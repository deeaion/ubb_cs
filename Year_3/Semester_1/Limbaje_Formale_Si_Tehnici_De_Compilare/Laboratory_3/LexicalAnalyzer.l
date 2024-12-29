%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cJSON.h"

// Maximum sizes
#define MAX_FIP_SIZE 1000
#define MAX_ERROR_SIZE 1000
#define MAX_ATOM_CODES 256

// Data Structures
typedef struct {
    char atom[50];
    int code;
} AtomCode;

typedef struct {
    char atom[100];
    int codAtom;
    int pozitieTS;
} FIPEntry;

typedef struct {
    int lineNumber;
    char message[256];
} LexicalError;

typedef struct {
    char key[100];
    int codAtom;
    int position;
} TSData;

typedef struct {
    TSData *data;
    int size;
    int capacity;
    int nextPos;
} SymbolTable;

// Globals
FIPEntry fip[MAX_FIP_SIZE];
int fipIndex = 0;

LexicalError errors[MAX_ERROR_SIZE];
int errorCount = 0;

AtomCode atomCodeList[MAX_ATOM_CODES];
int atomCodeCount = 0;

SymbolTable ts;
int line_number = 1;

// Function Prototypes
void initTS();
int insertToTS(const char *key, int codAtom);
void saveTS(const char *filenameConst,const char *filenameID);
void freeTS();
int getAtomCode(const char *token);

void addToFIP(const char *atom, int codAtom, int pozitieTS);
void addLexicalError(int lineNumber, const char *message);
void saveFIP(const char *filename);
void saveErrors(const char *filename);
void printErrorsToTerminal();

int loadJsonConfiguration(const char *filename);

%}

%option noyywrap

DIGIT           [0-9]
LETTER          [a-zA-Z_]
ID              {LETTER}({LETTER}|{DIGIT})*(\.{LETTER}({LETTER}|{DIGIT})*)*
CONST           {DIGIT}+(\.{DIGIT}+)?  
STRING_LITERAL  \"([^\"\\\\]|\\\\.)*\" 
OPERATOR        "=="|"<="|">="|"!="|"<"|">"|"="|"\\+"|"-"|"\\*"|"/"|"%"
SEPARATOR       ";"|"\\{"|"\\}"|"\\("|"\\)"|","|"<<"|">>"|"."
PREPROCESSOR    "#include|#define|#"

%%

"#include"|"#define"|"#" {
    printf("Matched preprocessor: %s\n", yytext);
    int atomCode = getAtomCode(yytext);
    if (atomCode != -1) {
        addToFIP(yytext, atomCode, -1);
    } else {
        printf("Unrecognized preprocessor token: %s\n", yytext);
        addLexicalError(line_number, yytext);
    }
}
"<"[a-zA-Z0-9_\.]+">" {
    printf("Matched library: %s\n", yytext);
    int atomCode = getAtomCode("LIBRARY");
    if (atomCode != -1) {
        addToFIP(yytext, atomCode, -1);
    } else {
        addLexicalError(line_number, yytext);
    }
}

"int"|"float"|"char"|"struct"|"string"|"main"|"cin"|"cout"|"if"|"else"|"while"|"return"|"void"|"repeta"|"panacand" {
    printf("Matched reserved word: %s\n", yytext);
    int atomCode = getAtomCode(yytext);
    if (atomCode != -1) {
        addToFIP(yytext, atomCode, -1);
    }
}

{ID} {
    printf("Matched identifier: %s\n", yytext);
    int atomCode = getAtomCode("ID");
    int pos = insertToTS(yytext, atomCode);
    addToFIP(yytext, atomCode, pos);
}

{CONST} {
    printf("Matched constant: %s\n", yytext);
    int atomCode = getAtomCode("CONST");
    int pos = insertToTS(yytext, atomCode);
    addToFIP(yytext, atomCode, pos);
}

{STRING_LITERAL} {
    printf("Matched string literal: %s\n", yytext);
    int atomCode = getAtomCode("STRING");
    int pos = insertToTS(yytext, atomCode);
    addToFIP(yytext, atomCode, pos);
}

"=="|"<="|">="|"!="|"<"|">"|"="|"+"|"-"|"*"|"/"|"%"|"*" {
    printf("Matched operator: %s\n", yytext);
    int atomCode = getAtomCode(yytext);
    if (atomCode != -1) {
        addToFIP(yytext, atomCode, -1);
    } else {
        printf("Unrecognized operator token: %s\n", yytext);
        addLexicalError(line_number, yytext);
    }
}

[()]|[{}]|[.]|[;,]|<<|>> {
    printf("Matched separator: %s\n", yytext);
    int atomCode = getAtomCode(yytext);
    if (atomCode != -1) {
        addToFIP(yytext, atomCode, -1);
    } else {
        printf("Unrecognized separator token: %s\n", yytext);
        addLexicalError(line_number, yytext);
    }
}

\n {
    line_number++;
}

[ \t\r]+ {
    // Ignore spaces, tabs, and carriage returns
}

. {
    printf("Invalid token at line %d: %s\n", line_number, yytext);
    addLexicalError(line_number, yytext);
}

%%



// Symbol Table Functions
void initTS() {
    ts.data = (TSData *)malloc(10 * sizeof(TSData));
    ts.size = 0;
    ts.capacity = 10;
    ts.nextPos = 1;
}

int insertToTS(const char *key, int codAtom) {
    for (int i = 0; i < ts.size; i++) {
        if (strcmp(ts.data[i].key, key) == 0) return ts.data[i].position;
    }

    if (ts.size == ts.capacity) {
        ts.capacity *= 2;
        ts.data = (TSData *)realloc(ts.data, ts.capacity * sizeof(TSData));
    }

    strcpy(ts.data[ts.size].key, key);
    ts.data[ts.size].codAtom = codAtom;
    ts.data[ts.size].position = ts.nextPos++;
    return ts.data[ts.size++].position;
}

void saveTS(const char *filenameConst, const char *filenameID) {
    FILE *fileConst = fopen(filenameConst, "w");
    FILE *fileID = fopen(filenameID, "w");
    fprintf(fileConst, "Position,Key,CodAtom\n");
    fprintf(fileID, "Position,Key,CodAtom\n");
    for (int i = 0; i < ts.size; i++) {
        if (ts.data[i].codAtom == getAtomCode("CONST")) {
            fprintf(fileConst, "%d,%s,%d\n", ts.data[i].position, ts.data[i].key, ts.data[i].codAtom);
        } else if (ts.data[i].codAtom == getAtomCode("ID")) {
            fprintf(fileID, "%d,%s,%d\n", ts.data[i].position, ts.data[i].key, ts.data[i].codAtom);
        }
    }
    fclose(fileConst);
    fclose(fileID);
}

void freeTS() {
    free(ts.data);
}

void addToFIP(const char *atom, int codAtom, int pozitieTS) {
    strcpy(fip[fipIndex].atom, atom);
    fip[fipIndex].codAtom = codAtom;
    fip[fipIndex].pozitieTS = pozitieTS;
    fipIndex++;
}

int getAtomCode(const char *token) {
    for (int i = 0; i < atomCodeCount; i++) {
        if (strcmp(atomCodeList[i].atom, token) == 0) {
            return atomCodeList[i].code;
        }
    }
    return -1;  // Return -1 if not found
}

void addLexicalError(int lineNumber, const char *message) {
    errors[errorCount].lineNumber = lineNumber;
    snprintf(errors[errorCount++].message, 256, "Invalid token: %s", message);
}

void saveFIP(const char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "Atom,CodAtom,PozitieTS\n");
    for (int i = 0; i < fipIndex; i++) {
        fprintf(file, "%s,%d,%d\n", fip[i].atom, fip[i].codAtom, fip[i].pozitieTS);
    }
    fclose(file);
}

void saveErrors(const char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line,Message\n");
    for (int i = 0; i < errorCount; i++) {
        fprintf(file, "%d,%s\n", errors[i].lineNumber, errors[i].message);
    }
    fclose(file);
}

void printErrorsToTerminal() {
    for (int i = 0; i < errorCount; i++) {
        printf("Error at line %d: %s\n", errors[i].lineNumber, errors[i].message);
    }
}

int loadJsonConfiguration(const char *filename) {
    FILE *file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *jsonString = malloc(fileSize + 1);
    fread(jsonString, 1, fileSize, file);
    fclose(file);

    cJSON *json = cJSON_Parse(jsonString);
    cJSON *atomCodesJson = cJSON_GetObjectItem(json, "atomCodes");

    cJSON *entry;
    cJSON_ArrayForEach(entry, atomCodesJson) {
        strcpy(atomCodeList[atomCodeCount].atom, entry->string);
        atomCodeList[atomCodeCount].code = entry->valueint;
        atomCodeCount++;
    }

    cJSON_Delete(json);
    free(jsonString);
    return 1;
}

// Main Function
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <config_file>\n", argv[0]);
        return 1;
    }

    initTS();
    if (!loadJsonConfiguration(argv[2])) return 1;

    FILE *file = fopen(argv[1], "r");
    yyin = file;
    yylex();
    fclose(file);

    saveTS("TS_CONST.csv","TS_ID.csv");
    saveFIP("FIP.csv");
    saveErrors("errors.csv");
    printErrorsToTerminal();
    freeTS();
    return 0;
}
