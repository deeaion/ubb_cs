# Tema 1 - Analizator Lexical

## 1. Specificarea minilimbajului de programare (MLP)

### 1.1. Tipuri de date simple și tip de date definit de utilizator

1. **Integer** - tip de date pentru numere întregi (`int`)
2. **Float** - tip de date pentru numere reale (`float`)
3. **Char** - tip de date pentru caractere (`char`)
4. **Struct** - tip de date definit de utilizator care permite gruparea mai multor tipuri de date simple sau structuri de date (ex: `struct circle {float r;}; circle c;`)
5. **String** - tip de date pentru șiruri de caractere (`string`)

### 1.2. Instructiuni

1. **Instrucțiune de atribuire**:

   - Se realizează prin intermediul operatorului de atribuire "=" (ex: `a = 5;`)

2. **Instrucțiune de intrare/ieșire**:

   - Se realizează prin intermediul:
     - Funcției de citire: `cin >> nume_variabilă;` (ex: `cin >> a;`)
     - Funcției de afișare: `cout << nume_variabilă;` (ex: `cout << a;`)
     - Functia de returnare: `return nume_variabilă;` (ex: `return a;`) - se folosește pentru a returna o valoare dintr-o funcție

3. **Instrucțiune de selecție (condițională)**:

   - Se realizează prin intermediul:
     - `if (condiție) { // bloc de instrucțiuni }` (ex: `if (a > 5) { cout << a; }`)
     - `if (condiție) { // bloc de instrucțiuni } else { // bloc de instrucțiuni }` (ex: `if (a > 5) { cout << a; } else { cout << b; }`)

4. **Instrucțiune de ciclare**:
   - Se realizează prin intermediul: `while (condiție) { // bloc de instrucțiuni }` (ex: `while (a > 5) { cout << a; }`)
   - Se mai realizeaza si prin intermediul : ` do { // bloc de instrucțiuni } while (condiție);` (ex: `do { cout << a; } while (a > 5);`)

### Restricții:

- **Identificatori**:

  - Pot conține litere, cifre și underscore (`_`), dar nu pot începe cu o cifră.
  - Sunt case sensitive.
  - Nu pot fi cuvinte cheie.

- **Comentarii**:

  - Sunt permise comentariile pe o singură linie, începând cu `//`.
  - Sunt permise comentariile pe mai multe linii, între `/*` și `*/`.

- **Tipul de date Struct**:
  - Se definește prin intermediul cuvântului cheie `struct`.
  - Membrii structurii sunt accesați cu operatorul `.` (ex: `a.b`).
  - Atribuirea membrilor se face prin intermediul operatorului `=` (ex: `a.b = 5;`).
- **Pot returna decat in functii de tip int sau float**
- **Pot avea un singur return in functie**

---

### 1.3. Analiza lexicală

#### 1.3.1. Simboluri:

- **Operatori**:

  - Aritmetici: `+`, `-`, `*`, `/`, `%`
  - De comparație: `<`, `>`, `<=`, `>=`, `==`, `!=`
  - Logici: `&&`, `||`, `!`
  - De atribuire: `=`
  - De separare: `,`, `;`

- **Delimitatori**: `(`, `)`, `{`, `}`, `[`, `]`, `;`

- **Cuvinte cheie**:
  - `int`
  - `float`
  - `char`
  - `struct`
  - `string`
  - `if`
  - `while`
  - `cin >>`
  - `cout <<`
  - `else`
  - `return`
  - `do`

#### 1.3.2. Identificatori:

- **Definiție**:
  - `identifier = letter (letter | digit | _)*`
  - `letter = a | b | ... | z | A | B | ... | Z`
  - `digit = 0 | 1 | ... | 9`

#### 1.3.3. Tabel de codificare (TC):

| Atom     | ID  |
| -------- | --- |
| ID       | 0   |
| CONST    | 1   |
| (        | 2   |
| )        | 3   |
| ,        | 4   |
| int      | 5   |
| float    | 6   |
| char     | 7   |
| main     | 8   |
| struct   | 8   |
| string   | 9   |
| {        | 10  |
| }        | 11  |
| =        | 12  |
| +        | 13  |
| -        | 14  |
| \*       | 15  |
| /        | 16  |
| %        | 17  |
| <        | 18  |
| >        | 19  |
| <=       | 20  |
| >=       | 21  |
| ==       | 22  |
| !=       | 23  |
| &&       | 24  |
| \|\|     | 25  |
| !        | 26  |
| ;        | 27  |
| cin      | 33  |
| cout     | 34  |
| if       | 35  |
| else     | 36  |
| while    | 37  |
| <<       | 38  |
| >>       | 39  |
| .        | 40  |
| return   | 41  |
| void     | 42  |
| null     | 43  |
| #include | 44  |
| do       | 45  |

# 1.4 Forma BNF a MLP-ului

```
<program> ::= <header>? <function>
<header> ::= <library_inclusions> <declaration_list>
<library_inclusions>::= "#include" <library> <library_inclusions> | eps;
<declaration_list> ::= <declaration> <declaration_list> | eps
<library> ::= "<iostream>" | "<math.h>"
<function> ::= <function_header> <body>
<function_header> ::= <type> <EID> ( <parameter_list>? )
<type> ::= int | float | string | char | struct | void
<parameter_list> ::= <declaration> , <parameter_list> | <declaration>
<declaration> ::= <type> ID ; | "struct" ID { <declaration>* } ;
<body> ::= { <compound_instruction>  }
<compound_instruction> ::= <instruction> <compound_instruction> | <instruction>
<instruction> ::= <declaration> ; | <assignment> ; | <input_instruction> ; | <output_instruction> ;
 | <while_loop> | <if_statement> |<optional_return>; | <do_while_loop>;
<assignment> ::= <EID> = <arithmetic_expression> ;
<input_instruction> ::= cin >> <EID> ;
<output_instruction> ::= cout << <arithmetic_expression> ; | cout<< endl;
<while_loop> ::= while ( <condition> ) <body>
<do_while_loop> ::= do <body> while ( <condition> ) ;
<if_statement> ::= if ( <condition> ) <body> ( else <body> )?
<condition> ::= <arithmetic_expression> <relational_operator> <arithmetic_expression> | <arithmetic_expression>
<arithmetic_expression> ::= <arithmetic_expression> <arithmetic_operator> <arithmetic_expression> | <EID> | CONST
<arithmetic_operator> ::= + | - | * | / | %
<relational_operator> ::= != | == | < | > | <= | >=
<EID> ::= ID| ID "." ID
<optional_return> = "" | return <arithmetic_expression> ;


```

```

<const_int> ::= <zero> | (+ | -)?  <valid_number>
<valid_number> ::= <non-zero> <digit>*
<zero> ::= "0"
<non-zero> ::= "1" | ... | "9"
<const_float> ::= <const_int> "." <digit> *
<const_string> ::= "\"" { character } "\"" ;
<digit>::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
<letter>::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" ;
<character>::= <letter> | <digit> | " " | "!" | "#" ;
ID ::= <letter> (<letter> | <digit> | "_")*
CONST ::= <const_int> | <const_float> | <const_string>
```

### EBNF:

```
program= header, function ;
header= library_inclusions, declaration_list ;
library_inclusions= "#include", library, library_inclusions | "" ;
declaration_list= declaration, declaration_list | "" ;
library= "<iostream>" | "<math.h>" ;
function= function_header, body ;
function_header = type, identifier, "(", [ parameter_list ], ")" ;
type= "int" | "float" | "string" | "char" | "struct" | "void" ;
parameter_list= declaration, { ",", declaration } ;
declaration= type, identifier ;
body= "{", { compound_instruction }, "}" ;
compound_instruction = instruction, { instruction } ;
instruction= declaration, ";"
              | assignment, ";"
              | input_instruction, ";"
              | output_instruction, ";"
              | while_loop
              | if_statement ; | optional_return ;
assignment= id, "=", arithmetic_expression , ";" ;
input_instruction= "cin", ">>", eid, ";" ;
output_instruction= "cout", "<<", arithmetic_expression ";" ; | "cout", "<<", "endl", ";" ;
while_loop = "while", "(", condition, ")", body ;
do_while_loop = "do", body, "while", "(", condition, ")" ;
if_statement= "if", "(", condition, ")", body, [ "else", body ] ;
condition= arithmetic_expression, relational_operator, arithmetic_expression
              | arithmetic_expression ;
arithmetic_expression = arithmetic_expression, arithmetic_operator, arithmetic_expression | eid | const ;
arithmetic_operator = "+" | "-" | "*" | "/" | "%" ;
relational_operator = "!=" | "==" | "<" | ">" | "<=" | ">=" ;
eid= id | id, ".", id;
optional_return = "" | "return", arithmetic_expression ;





id= letter, { letter | digit | "_" } ;
cons = const_int | const_float | const_string ;
const_int= [ "+" | "-" ] zero| ["+","-"]  valid_number;
valid_number= non-zero,{digit} ;
zero = "0";
non-zero = "1" | ... | "9";
const_float= <const_int>, ".", { digit } ;
const_string= "\"", { character }, "\"" ;
character= letter | digit | " " | "!" | "#" ;
digit = "0" | "1" | ... | "9" ;
letter= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" ;
```

## 2. Texte sursă a 3 mini-programe scrise în MLP

### 2.1. Program care calculează perimetrul și aria cercului de o rază dată

```cpp
#include <iostream>

int main() {
    struct circle {
        float r;
    } c ;
    float pi;
    pi = 3.14;
    cin >> c.r;
    cout << 2 * pi * c.r;
    cout<< endl;
    cout << pi * c.r * c.r;
    cout << endl;

    return 0;
}
```

### 2.2. Program care determină CMMDC a două numere naturale

```cpp
#include <iostream>
int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    cout << a;
    cout << endl;

    return 0;
}
```

### 2.3. Program care calculează suma a `n` numere citite de la tastatură

```cpp
#include <iostream>
int main() {
    int n;
    cin >> n;
    int sum;
    sum = 0;
    int x;
    while (n>0) {
        cin >> x;
        sum = sum +  x;
        n=n-1;
    }
    cout<< sum;
    cout << endl;

    return 0;
}
```

---

## 3. Texte sursă a 2 programe care conțin erori conform MLP-ului definit

### 3.1. Program cu erori în limbajul original și MLP

```cpp
#include <iostream>

int main() {
    int a // Eroare: lipseste punct și virgula
    int int; // Eroare: cuvânt cheie folosit ca identificator

    cout << "Introduceti un numar intreg: ";
    cin >> a;

    cout << "Suma este: ";
    cout << (a + int); // Eroare: identificatorul "int" nu este valid

    return 0;
}
```

### 3.2. Program cu erori conform MLP, dar care nu sunt erori în limbajul original C++

```cpp
#include <iostream>

int main() {
    int a, b; // Eroare în MLP - fiecare declarație trebuie să fie pe o linie separată
    int valori[10]; // Eroare în MLP - nu se permite declararea de vectori

    cout << "Introduceti 2 numere intregi: ";
    cin >> valori[0] >> valori[1]; // Eroare în MLP - operatorul de citire pentru mai multe variabile

    cout << "Suma este: " << valori[0] + valori[1]; // Eroare în MLP - numele variabilei nu este acceptat + nu pot afisa mai multe

    return 0;
}
```

## 4. Implementarea analizatorului lexical

- date intrare: fisier text cu un program scris in MLP
- date iesire: fisier text cu tabelele :
  - FIP - forma interna a programului surs
  - TS - tabela de simboluri

Programul semnaleaza erori lexicale care apar.
Restrictii suplimentare:

1. TS:
   a. unica pt identificatori si constante
   b. separat pentru identificatori si constante
2. Organizare TS:
   a. Tabel ordonat lexicografic
   b. Tabel arbore binar de cautare (ordine lexicografica)
   c. Tabel de dispersie (hash)
   Se mai cere:

- implementarea structuriilor de date cerute pentru TS;
- salvare FIP and TS in fisiere text;Pozitia in TS (din fisierul corespunzator FIP) va fi numarul liniei din fisierul TS in care este stocata informatia referitoare la acel atom lexical.
