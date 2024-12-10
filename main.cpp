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
    return n*silnia(n-1); //zastosowanie rekurencji
}

int fibonnacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonnacci(n-1) + fibonnacci(n-2); //zastosowanie rekurencji
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
        C[i] = A[i] * B[i]; //przypisywanie iloczynu odpowiednich elementow tablic A i B do tablicy C
}

void wyswietl(int tab[10]) {
    for (int i = 0; i < 10; i++)
        cout << tab[i] << " ";
    cout << endl;
}

//zadanie 1d - potęgowanie rekurencyjne
long poteguj(int a, int n) {
    if (n == 0 || n == 1)
        return a;
    else
        return a * poteguj(a, n-1);
}

//zadanie dodatkowe - funkcje pomocznicze

//funkcja do stworzenia dynamicznie pojedynczej macierzy
int** inicjalizuj_macierz(int wiersze, int kolumny) {
    int** macierz = new int*[wiersze];
    for (int i = 0; i < kolumny; i++) {
        macierz[i] = new int[kolumny];
    }
    return macierz; // zwracamy wskaznik na 1szy element tablicy dwuwymiarowej
}

//wyswietlanie wynikowej macierzy
void wyswietl_macierz(int wiersze, int kolumny, int** M) {
    for (int i = 0; i < kolumny; i++) {
        for (int j = 0; j < wiersze; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

//dodawanie macierzy
int** dodaj_macierz(int** A, int** B, int wiersze, int kolumny) {
    int** wyn = inicjalizuj_macierz(wiersze, kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            wyn[i][j] = A[i][j] + B[i][j];
        }
    }
    return wyn;
}

//odejmowanie macierzy
int** odejmij_macierz(int** A, int** B, int wiersze, int kolumny) {
    int** wyn = inicjalizuj_macierz(wiersze, kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            wyn[i][j] = A[i][j] - B[i][j];
        }
    }
    return wyn;
}

//mnozenie macierzy (funkcja dziala jedynie dla macierzy o tych samych wymiarach)
int** pomnoz_macierz(int** A, int** B, int wierszeA, int kolumnyA, int kolumnyB) {
    int** wyn = inicjalizuj_macierz(wierszeA, kolumnyB);
    for (int wiersz = 0; wiersz < wierszeA; wiersz++) {
        for (int kolumna = 0; kolumna < kolumnyB; kolumna++) {
            wyn[wiersz][kolumna] = 0;
            for (int i = 0; i < kolumnyA; i++) {
                wyn[wiersz][kolumna] += A[wiersz][i] * B[i][kolumna];
            }
        }
    }
    return wyn;
}

//transponowanie macierzy
int** transponuj_macierz(int** A, int wiersze, int kolumny) {
    int** wyn = inicjalizuj_macierz(wiersze, kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++)
            wyn[j][i] = A[i][j];
    }
    return wyn;
}
int main() {
    //zad 1a - wprowadzenie elementow do tablic A,B,C oraz wyswietlenie ich wartosci
     for (int i = 0; i < 10; i++) {
         cout << "podaj " << i+1 <<"element: ";
         cin >> A[i];
         B[i] = (rand() % 101) + (rand()%101) / 100.0;
     }
     cout << "Tablica A: " << endl;
     for (int i = 0; i < 10; i++)
         cout << A[i] << " ";

     cout << endl << "tablica B: " << endl;
     for (int i = 0; i < 10; i++)
         cout << B[i] << " ";

     cout << endl << "tablica C: " << endl;

     for (int i = 0; i < 10; i++) {
         C[i] = A[i] * B[i];
         cout << C[i] << " ";
     }

    //zad 1b - wprowadzenie wartosci do tablic
    long D[10][3];
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

    //zad 1b - wyswietlanie tablicy
    cout << endl;
    cout << "n" << "\t" << "    " << "SIL" << "\t" << " "  << "FIB" << endl;
    for (int i = 0; i < 10; i++) {
        cout << D[i][0] << "\t"; // pierwsza koluma
        cout << setw(7) << right << D[i][1] << "\t"; //druga kolumna
        cout << setw(4) << right << D[i][2] << "\t" << endl; //trzecia kolumna oraz przejście do nowej lini
    }

    //zad 1d
    int n;
    long a;
    cout << "wprowadz a: ";
    cin >> a;
    cout << "wprowadz potege: ";
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << i << " potega liczby a: " << poteguj(a, i) << endl;

    //zadanie dodatkowe
    int kolumny, kolumny_2;
    int wiersze, wiersze_2;
    cout << "Podaj ilosc kolumn macierzy A: ";
    cin >> kolumny;
    cout << "podaj ilosc wierszy macierzy A: ";
    cin >> wiersze;
    cout << "Podaj ilosc kolumn macierzy B: ";
    cin >> kolumny_2;
    cout << "Podaj ilosc wierszy macierzy B: ";
    cin >> wiersze_2;

    //dynamiczna alokacja macierzy
    int** A  = inicjalizuj_macierz(wiersze, kolumny);
    int** B = inicjalizuj_macierz(wiersze_2, kolumny_2);

    //wypelnianie macierzy wartosciami (wybralem losowe)
    srand(time(NULL));
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++)
            A[i][j] = rand();
    }

    for (int i = 0; i < wiersze_2; i++) {
        for (int j = 0; j < kolumny; j++)
            B[i][j] = rand();
    }

    int **C = nullptr; // ustawienie poczatkowo pustego wskaznika na tablice dwuwymiarowa (macierz wynikowa)

    if (kolumny == kolumny_2 && wiersze == wiersze_2) {
        C = dodaj_macierz(A, B , wiersze, kolumny);
        cout << "wynik dodawania: " << endl;
        wyswietl_macierz(wiersze,kolumny,C);
        cout << endl;
    }

    if (wiersze == wiersze_2 && kolumny == kolumny_2) {
        C = odejmij_macierz(A, B, wiersze, kolumny);
        cout << "wynik odejmowania: " << endl;
        wyswietl_macierz(wiersze,kolumny,C);
    }

    if (kolumny == wiersze_2) {
        C = pomnoz_macierz(A, B, wiersze, kolumny, wiersze_2);
        cout << "wynik mnozenia: " << endl;
        wyswietl_macierz(wiersze, kolumny, C);
    }

    cout << "Macierz A transponowana: " << endl;
    wyswietl_macierz(wiersze,kolumny,A);
    cout << "Macierz B transponowana: " << endl;
    wyswietl_macierz(wiersze,kolumny,transponuj_macierz(A,wiersze,kolumny));

    //zwalnianie pamieci
    for (int i = 0; i< wiersze; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i< wiersze_2; i++)
        delete[] B[i];
    delete[] B;


    return 0;
}
