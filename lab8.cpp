#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <windows.h>
using namespace std;

//Завдання 1 
void sortAscending(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void sortDescending(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void task1() {
    cout << "Завдання 1" << endl;
    const int m = 12;
    int arr[m];

    for (int i = 0; i < m; i++)
        arr[i] = rand() % 101 - 50;

    cout << "Початковий масив:      ";
    printArray(arr, m);

    int asc[m], desc[m];
    for (int i = 0; i < m; i++) {
        asc[i] = arr[i];
        desc[i] = arr[i];
    }

    sortAscending(asc, m);
    cout << "За зростанням:         ";
    printArray(asc, m);

    sortDescending(desc, m);
    cout << "За спаданням:          ";
    printArray(desc, m);
    cout << endl;
}

//Завдання 2 
void zeroNegativesBeforeMax(vector<int>& v) {
    int maxIndex = 0;
    for (size_t i = 1; i < v.size(); i++)
        if (v[i] > v[maxIndex])   
            maxIndex = i;

    for (int i = 0; i < maxIndex; i++)
        if (v[i] < 0)
            v[i] = 0;
}

void task2() {
    cout << "Завдання 2" << endl;
    int n;
    cout << "Введіть кількість елементів масиву (n > 0): ";
    cin >> n;
    if (n <= 0) {
        cout << "Масив має бути не порожнім!" << endl;
        return;
    }

    vector<int> v(n);
    cout << "Введіть " << n << " цілих чисел: ";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << "Початковий масив: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    zeroNegativesBeforeMax(v);

    cout << "Результат:        ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));
    task1();
    task2();
    return 0;
}