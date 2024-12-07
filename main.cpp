#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

double A[10];
double B[10];
double C[10];

// zadanie 1b - funkcje pomocnicze
int silnia(int n) {
    if (n == 1 || n == 0)
        return 1;
    return n*silnia(n-1);
}

int fibonnacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonnacci(n-1) + fibonnacci(n-2);
}

// zadanie 1c - funkcje pomocnicze
void wprowadz_A() {
    for (int i = 0; i < 10; i++) {
        cout << " podaj " << i+1 <<"element: ";
        cin >> A[i];
    }
}

void losujB() {
    for (int i = 0; i < 10; i++)
        B[i] = rand() % 101 + rand() % 101 / 100.0; //losowanie liczb rzeczywistych z dokładnością 2 miejsc po przecinku
}

void oblicz_C() {
    for (int i = 0; i < 10; i++)
        C[i] = A[i] * B[i];
}

void wyswietl(int tab[10]) {
    for (int i = 0; i < 10; i++)
        cout << tab[i] << " ";
    cout << endl;
}

//zadanie 1d - potęgowanie rekurencyjne
int poteguj(int a, int n) {
    if (n == 0 || n == 1)
        return a;
    else
        return a * poteguj(a, n-1);
}

void wyswietl_macierz(int sz, int dl, int M[][]) {
    for (int i = 0; i < dl; i++) {
        for (int j = 0; j < sz; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void dodaj_macierz(int sz, int dl, int wyn[][], int A[][], int B[][]) {
    for (int i = 0; i < dl; i++) {
        for (int j = 0; j < sz; j++)
            wyn[i][j] = A[i][j] + B[i][j];
    }
}
void pomnoz_macierz(int sz, int dl, int wyn[][], int A[][], int B[][]) {
    for (int i = 0; i < dl; i++) {
        
    }
}

int main() {

    // for (int i = 0; i < 10; i++) {
    //     cout << "podaj " << i+1 <<"element: ";
    //     cin >> A[i];
    //     B[i] = (rand() % 101) + (rand()%101) / 100.0;
    // }
    // cout << "Tablica A: " << endl;
    // for (int i = 0; i < 10; i++)
    //     cout << A[i] << " ";
    //
    // cout << endl << "tablica B: " << endl;
    // for (int i = 0; i < 10; i++)
    //     cout << B[i] << " ";
    //
    // cout << endl << "tablica C: " << endl;
    //
    // for (int i = 0; i < 10; i++) {
    //     C[i] = A[i] * B[i];
    //     cout << C[i] << " ";
    // }

    int D[10][3];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0)
                D[i][j] = i+1;
            else if (j == 1)
                D[i][j] = silnia(i+1);
            else
                D[i][j] = fibonnacci(i+1);
        }
    }
    cout << endl;
    cout << "n" << "\t" << "    " << "SIL" << "\t" << " "  << "FIB" << endl;
    for (int i = 0; i < 10; i++) {
        cout << D[i][0] << "\t"; // pierwsza koluma
        cout << setw(7) << right << D[i][1] << "\t"; //druga kolumna
        cout << setw(4) << right << D[i][2] << "\t" << endl; //trzecia kolumna oraz przejście do nowej lini
    }

    //zad 1d
    int n, a;
    cout << "wprowadz a: ";
    cin >> a;
    cout << "wprowadz potege: ";
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << i << " potega liczby a: " << poteguj(a, i) << endl;

    //zadanie dodatkowe
    int szerokosc;
    int dlugosc;
    cout << "Podaj szerokosc macierzy: ";
    cin >> szerokosc;
    cout << "podaj dlugosc macierzy: ";
    cin >> dlugosc;

    int A[][] = new int[dlugosc][szerokosc];
    int B[][] = new int[dlugosc][szerokosc];
    int wyn[][] = new int[dlugosc][szerokosc];

    srand(time(NULL));
    for (int i = 0; i < dlugosc; i++) {
        for (int j = 0; j < szerokosc; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }



    return 0;
}

