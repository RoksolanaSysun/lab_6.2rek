#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* p, int n, int MIN, int MAX, int i = 0)
{
    if (i < n)
    {
        p[i] = MIN + rand() % (MAX - MIN + 1);
        create(p, n, MIN, MAX, i + 1);
    }
}

void Print(int* p, const int n, int i = 0)
{
    cout << setw(4) << p[i];
    if (i < n - 1)
        Print(p, n, i + 1);
    else
        cout << endl;
}


int MaxElement(int* a, const int size, int i = 1, int max = 0) {
    if (i < size) {
        if (a[i] > a[max]) {
            max = i;
        }
        return MaxElement(a, size, i + 1, max); // Рекурсивно шукаємо далі
    }
    return a[max];
}

int MinElement(int* a, const int size, int i = 1, int min = 0) {
    if (i < size) {
        if (a[i] < a[min]) {
            min = i;
        }
        return MinElement(a, size, i + 1, min); // Рекурсивно шукаємо далі
    }
    return a[min];
}


double AverageMinMax(int* a, const int size) {
    int max = MaxElement(a, size);
    int min = MinElement(a, size);
    return (max + min) / 2.0;
}

int main()
{
    srand((unsigned)time(NULL));


    const int n = 10;
    int p[n];
    int MIN = -10;
    int MAX = 14;

    create(p, n, MIN, MAX);

    cout << "Array:" << endl;
    Print(p, n);

    double avg = AverageMinMax(p, n);

    cout << "Average of max and min elements: " << avg << endl;

    return 0;
}