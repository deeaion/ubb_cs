
#include <omp.h>

using namespace std;

const int MAX = 20;
int a[MAX], b[MAX], m[MAX][MAX], c[MAX];

int produsScalar(int a[MAX], int b[MAX]) {
    int s = 0;

    for (int i = 0; i < MAX; i++) {
        s += a[i] * b[i];
    }

    return s;
}

int produsScalarParallel(int a[MAX], int b[MAX]) {
    /*
     * suma globala
     */
    int sum = 0;
    //copie fiecare thread
    //public and private

    int partial_sum = 0;

    //directive private pentru un anumit thread
//private(partial_sum) copie fara sa ii pastreze informatia initiala
//first_private(partial_sum) copie a variabilei fix cu ultima valoare inainte sa fie initializata
//less_private -> creaza copie si atunci cand iese din sectiunea paralela varibila globala din main are valoarea din ultimul thread din sectiunea paralela
//by default daca nu punem nicio directiva e schedule static

#pragma omp parallel firstprivate(partial_sum) num_threads(16)
    {
#pragma omp for
        for (int i = 0; i < MAX; i++) {
            partial_sum += a[i] * b[i];
        }
//sectiunea critica

#pragma omp critical
        {
            sum += partial_sum;
        }
    }

    return sum;
}

int produsScalarParallel2(int a[MAX], int b[MAX]) {
    int sum = 0;

    //reduction doi operatori +:sum (+ reducerea si unde sum)
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < MAX; i++) {
        sum += a[i] * b[i];
    }

    return sum;
}

void addVectors(int a[MAX], int b[MAX], int c[MAX]) {
    for (int i = 0; i < MAX; i++) {
        c[i] = a[i] + b[i];
    }
}

void multiplyVectors(int a[MAX], int b[MAX], int c[MAX]) {
    for (int i = 0; i < MAX; i++) {
        c[i] = a[i] * b[i];
    }
}

int main() {
    /*
     * OPEN MP -> framework de orchestrare, un framework
     * FRAMEWORK PE CARE IL PUTEM INJECTA INTR UN PROIECT DEJA EXISTENT
     * in java avem adnotari
     *
     */

    /*
     * la care linie de cod se creeaza threads? -> nu aici
     * doar seteaza (p=4), numarul de threaduri default pe care il vom folosi
     */
    omp_set_num_threads(4);

    cout << "Thread num1: " << omp_get_num_threads() << endl;
    /*
     * putem grupa instructiuniile in blocuri
     * sectiuea unde se creeaza thread uriile
     * creeaza threaduriile ca si ThreadPools
     * astfel threaduriile sunt intr un ThreadPool care are un Queue
     * astfel creeaza functii anonime care sunt ca un fel de task uri si le puen in Queue
     * le pune cumva ca si cum ar fi un lambda function
     */
#pragma omp parallel num_threads(16)
    {

        /*
         * am 16 threads
         * pe sectiuni paralele eu zic cat vreau
         */
        cout << "Thread num2: " << omp_get_num_threads() << endl;
/*
 * echivalent cu mutex
 * 76-79 avem critical
 * toate 16 threaduriile le executa
 * doar el
 */
#pragma omp critical
        {
            cout << "Hello from: " << omp_get_thread_num() << endl;
            cout << "Thread num3: " << omp_get_num_threads() << endl;
        }

        cout << "Thread num4: " << omp_get_num_threads() << endl;
/*
 * daca nu avem pragma omp for for ul ala s ar executa de toate 16 threads
 * astfel gestionam optimizarea de for
 * segmentul 0 se imparte in chunks de n/p
 * restu se duce la ultimul thread
 * schedule dynamic -> ca la lab 4 5
 * schedule dynamic -> apoi pe mecanismul de primul venit sunt procesate de un thread
 * folosim fix coada ca la producer-consumer
 * valoarea numerica -> chunks de dimensiunea respectiva
 *
 */
#pragma omp for schedule(static, 2) nowait
        for (int i = 0; i < MAX; i++) {
            a[i] = omp_get_thread_num();
            b[i] = i;
        }
        /*
         * aici in teorie este o bariera
         * asteapta toate thread uriile
         * nowait -> disable la bariera
         *
         */
/*
 * alt for . for in for
 * pragma omp for actioneaza by default doar pe primul for
 * poti sa faci collapse la for -> le liniarizam si paralelizam
 * aici o sa fie bariera dupa for
 * may este o pbariera si la parallel
 */
#pragma omp for schedule(static, 2) collapse(2)
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                m[i][j] = omp_get_thread_num();
            }
        }
    }

    for (int i = 0; i < MAX; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    /*
     * varianta secventiala
     */
    cout << produsScalar(a, b) << endl;
    /*
     * paralela
     */
    cout << produsScalarParallel(a, b) << endl;
    cout << produsScalarParallel2(a, b) << endl;
/*
 * aici ar fi
 */
/*
 * noua sectiune cu 8 threads
 *
 */

#pragma omp parallel num_threads(8)
    {
        /*
         * section -> sa paralelizam structuri de for
         * sections-> definim o sectiune paralela, folosim 8 thread uri deja declarate
         * avem toate sectiuniile care trebuiesc executate
         * omp section-> thread unul singur
         *
         */
#pragma omp sections
        {
#pragma omp section
            {
                addVectors(a, b, c);
#pragma omp critical
                {
                    cout << "Section add: " << omp_get_thread_num() << endl;
                }
            }
#pragma omp section
            {
                multiplyVectors(a, b, c);
#pragma omp critical
                {
                    cout << "Section multiply: " << omp_get_thread_num() << endl;
                }
            }
#pragma omp section
            {
                produsScalar(a, b);
#pragma omp critical
                {
                    cout << "Section produs: " << omp_get_thread_num() << endl;
                }
            }
        }
    }
/*
 * single->
 */
#pragma omp parallel num_threads(5)
    {
        /*
         * permite executia unei instructiuni doar dde un singur thread
         * la critical fiecare executa sectiunea critica
         * aici doar unul singur , unul din ele executa
         *
         */
#pragma omp single
    {
        cout << "Doar eu execut: " << omp_get_thread_num() << endl;

    }
    }
    return 0;
}