#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Рекурсивна функція для створення матриці
void Create(int** a, const int n, const int Low, const int High, int i = 0, int j = 0) {
    if (i == n) return;
    if (j == n) {
        Create(a, n, Low, High, i + 1, 0);
        return;
    }
    a[i][j] = Low + rand() % (High - Low + 1);
    Create(a, n, Low, High, i, j + 1);
}

// Рекурсивна функція для друку матриці
void Print(int** a, const int n, int i = 0, int j = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    if (j == n) {
        cout << endl;
        Print(a, n, i + 1, 0);
        return;
    }
    cout << setw(4) << a[i][j];
    Print(a, n, i, j + 1);
}

// Рекурсивна функція для пошуку мінімального парного елементу
bool SearchMinEven(int** a, const int n, int& minEven, int i = 0, int j = 0, bool found = false) {
    if (i == n) return found;
    if (j == n) return SearchMinEven(a, n, minEven, i + 1, 0, found);

    if (j % 2 == 0 && (!found || a[i][j] < minEven)) {
        if (a[i][j] % 2 == 0) {
            minEven = a[i][j];
            found = true;
        }
    }
    return SearchMinEven(a, n, minEven, i, j + 1, found);
}

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int n;

    cout << "n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, n);

    int minEven;
    if (SearchMinEven(a, n, minEven))
        cout << "min even = " << minEven << endl;
    else
        cout << "there are no even elements" << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
