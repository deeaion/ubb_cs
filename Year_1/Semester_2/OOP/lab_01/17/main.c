#include <stdio.h>
#include <math.h>

/*
 *
17. Determina primele 10 numere naturale strict mai mari ca 2, care au

    proprietatea ca toate numerele naturale strict mai mici decat ele

    si care sunt prime cu ele sunt numere prime.
1.Genereaza numere prime mai mici decat un numar natural dat.

 */
void menu(int *opt);

/*
 * Prints out the menu and saves what option the user entered.
 *
 * returns: -
 *          but the function is made to change the value of opt using a reference function
 *
 */

void generate_numbers(int n);

/*
 * Will generate all the prime numbers lower than the given n number.
 * returns:-
 *
 */

int determinare_numere(int numere[10]);

/*
 * Function will determin the first 10 ( if they exist) 'n' numbers that respect the following conditions:
 *                  -they are greater than 2. n>2
 *                  -all the numbers 'y' < 'n' with cmmdc(n,y)=1 are prime numbers prim(y)=1 !
 * returns: nr- integer, the number of 'n' 's that respect the conditions
 */
void tiparire(int numere[10], int nr_el);

/*
 *Prints out the array 'numere' that has 'nr_el' elements!
 * returns: -
 */

int cmmdc_euclid(int a, int b);

/*
 * Cel mai mare divizor comun dintre a si b.
 * a,b- numere naturale
 * returns: 1- daca numerele sunt prime intre ele
 *          n- unde n este cel mai mare divizor comun si n!=1
 */
int prim(int n);

/*
 * verifies if n is a prime number
 * returns : 1- if True : n is a prime number
 *           0- if False: n is not a prime number
 */
int main() {
    int opt = 0, numere[10], nr_el, n = 0;

    while (1) {
        opt = 0;
        menu(&opt);
        if (opt == 1) {
            nr_el = determinare_numere(numere);
            if (nr_el != 10) { printf("\nWarning: There are only %d numbers that satisfy the condition!\n", nr_el); }
            printf("Numbers were generated\n");
        }
        if (opt == 2)
            tiparire(numere, nr_el);
        if (opt == 3)
            generate_numbers(n);
        if (opt == 4)
            return 0;

    }
}

void menu(int *opt) {
    printf("Menu:\nEnter one of the following number that each correspond to a command:\n");
    printf(" 1. Generate the first ten numbers that satisfy the condition.\n 2.Print the generated numbers.\n 3.Generate the prime numbers lower than a given number that you enter.\n 4.Exit\n");


    while ((*opt) < 1 || (*opt) > 4) {
        printf("Your option is: ");
        scanf_s("%d", opt);
    }
    printf("You chose option: %d\n", *opt);
}


int determinare_numere(int numere[10]) {
    int nr_el = 0;
    int i, j, n, ok;
    i = 0;
    n = 3;
    while (nr_el < 10) {
        ok = 1;
        for (j = n - 1; j >= 2 && ok == 1; j--) {
            if (cmmdc_euclid(j, n) == 1) //inseamna ca sunt prime intre ele
            {
                if (prim(j) == 0)
                    ok = 0;

            }

        }
        if (ok == 1) {
            nr_el++;
            numere[i] = n;
            i++;
        }

        n++;
        //voi testa decat pana la 1 000 000 pentru ca exista posibilitatea sa nu fie 10 numere si programul sa intre intr-un loop
        if (n == 1000000) {
            return nr_el;
        }
    }
    return nr_el;
}

int cmmdc_euclid(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int prim(int n) {
    int d;
    if (n <=1) {
        return 0;
    }
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    d = 3;
    while (d <= sqrt(n)) {
        if (n % d == 0)
            return 0;
        d += 2;
    }
    return 1;
}

void tiparire(int numere[10], int nr_el) {
    int i;
    for (i = 0; i < nr_el - 1; i++) {
        printf("%d, ", numere[i]);

    }
    printf("%d\n", numere[nr_el - 1]);
}


void generate_numbers(int n) {
    printf("Please introduce the number (the number has to be positive):\n");
    int i;
    n = -1;
    while (n < 0) {
        scanf_s("%d", &n);
    }
    for (i = 2; i < n - 1; i++) {
        if (prim(i) == 1) {
            printf("%d, ", i);
        }
    }

    printf("\n");

}