%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum sizes
#define MAX_FIP_SIZE 1000
#define MAX_ERROR_SIZE 1000

// Forward declarations for TS functions
int insertToTS(const char *key, int codAtom);
void saveTS(const char *filename);
void printTS();
void freeTS();

// FIP Entry
typedef struct {
    char atom[100];
    int codAtom;
    int pozitieTS;
} FIPEntry;

// Lexical Error Entry
typedef struct {
    int lineNumber;
    char message[256];
} LexicalError;

// Global FIP and error arrays
FIPEntry fip[MAX_FIP_SIZE];
int fipIndex = 0;

LexicalError errors[MAX_ERROR_SIZE];
int errorCount = 0;

// Reserved words and atom codes
typedef struct {
    const char *word;
    int code;
} ReservedWord;

ReservedWord reservedWords[] = {
    {"int", 5}, {"float", 6}, {"char", 7}, {"struct", 8}, {"string", 9},
    {"cin", 33}, {"cout", 34}, {"if", 35}, {"else", 36}, {"while", 37},
    {"return", 41}, {"void", 42}, {"main", 43}, {"null", 44}, {"#include", 45},
    {NULL, -1}  // End marker
};

// Function prototypes for FIP and errors
int findReservedWord(const char *word);
void addToFIP(const char *atom, int codAtom, int pozitieTS);
void addLexicalError(int lineNumber, const char *message);
void saveFIP(const char *filename);
void saveErrors(const char *filename);
void printErrorsToTerminal();

// Line counter
int line_number = 1;

%}

%option noyywrap

%%

[a-zA-Z_][a-zA-Z0-9_]* {
    int reservedCode = findReservedWord(yytext);
    if (reservedCode != -1) {
        addToFIP(yytext, reservedCode, -1);
    } else {
        int pos = insertToTS(yytext, 0);  // ID
        addToFIP(yytext, 0, pos);
    }
}

[0-9]+          { int pos = insertToTS(yytext, 1); addToFIP(yytext, 1, pos); }
[0-9]+\.[0-9]+  { int pos = insertToTS(yytext, 1); addToFIP(yytext, 1, pos); }

\"[^\"]*\"      { int pos = insertToTS(yytext, 1); addToFIP(yytext, 1, pos); }

"=="|"<="|">="|"!="|"<"|">" { addToFIP(yytext, 20, -1); }
"+"|"-"|"*"|"/"             { addToFIP(yytext, 21, -1); }

";" { addToFIP(";", 27, -1); }
"," { addToFIP(",", 4, -1); }
"{" { addToFIP("{", 10, -1); }
"}" { addToFIP("}", 11, -1); }
"(" { addToFIP("(", 2, -1); }
")" { addToFIP(")", 3, -1); }

[ \t]+         { /* Ignore spaces and tabs */ }
\n             { line_number++; }

.              { addLexicalError(line_number, yytext); }

%%

// Reserved Word Finder
int findReservedWord(const char *word) {
    for (int i = 0; reservedWords[i].word != NULL; i++) {
        if (strcmp(reservedWords[i].word, word) == 0) {
            return reservedWords[i].code;
        }
    }
    return -1;  // Not found
}

// Add to FIP
void addToFIP(const char *atom, int codAtom, int pozitieTS) {
    if (fipIndex >= MAX_FIP_SIZE) {
        fprintf(stderr, "Error: FIP overflow\n");
        exit(1);
    }
    strcpy(fip[fipIndex].atom, atom);
    fip[fipIndex].codAtom = codAtom;
    fip[fipIndex].pozitieTS = pozitieTS;
    fipIndex++;
}

// Add Lexical Error
void addLexicalError(int lineNumber, const char *message) {
    if (errorCount >= MAX_ERROR_SIZE) {
        fprintf(stderr, "Error: Too many lexical errors\n");
        exit(1);
    }
    errors[errorCount].lineNumber = lineNumber;
    snprintf(errors[errorCount].message, sizeof(errors[errorCount].message), "Invalid token: %s", message);
    errorCount++;
}

// Save FIP to File
void saveFIP(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening FIP file");
        return;
    }
    fprintf(file, "Atom,CodAtom,PozitieTS\n");
    for (int i = 0; i < fipIndex; i++) {
        fprintf(file, "%s,%d,%d\n", fip[i].atom, fip[i].codAtom, fip[i].pozitieTS);
    }
    fclose(file);
}

// Save Errors to File
void saveErrors(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening error file");
        return;
    }
    fprintf(file, "Linie,Mesaj\n");
    for (int i = 0; i < errorCount; i++) {
        fprintf(file, "%d,%s\n", errors[i].lineNumber, errors[i].message);
    }
    fclose(file);
}

// Print Errors to Terminal
void printErrorsToTerminal() {
    for (int i = 0; i < errorCount; i++) {
        printf("Error at line %d: %s\n", errors[i].lineNumber, errors[i].message);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening source file");
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    saveTS("TS.csv");
    saveFIP("FIP.csv");
    saveErrors("lexical_errors.csv");
    printErrorsToTerminal();
    freeTS();

    return 0;
}
