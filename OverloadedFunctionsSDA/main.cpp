#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <windows.h>

using namespace std;

// Шаблон для заполнения матрицы случайными данными
template <typename T>
void fillMatrix(T** matrix, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            matrix[i][j] = static_cast<T>(rand() % 100); // Генерируем случайное значение
            j++;
        }
        i++;
    }
}

// Шаблон для вывода матрицы на экран
template <typename T>
void printMatrix(T** matrix, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            cout << matrix[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

// Шаблон для определения максимального и минимального элемента на главной диагонали
template <typename T>
void findMinMaxDiagonal(T** matrix, int size, T& min, T& max)
{
    min = numeric_limits<T>::max();
    max = numeric_limits<T>::min();

    int i = 0;
    while (i < size)
    {
        if (matrix[i][i] < min)
        {
            min = matrix[i][i];
        }
        if (matrix[i][i] > max)
        {
            max = matrix[i][i];
        }
        i++;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0))); // Инициализируем генератор случайных чисел

    const int size = 3; // Размер квадратной матрицы

    // Создание матрицы для int
    int** intMatrix = new int* [size];
    int i = 0;
    while (i < size)
    {
        intMatrix[i] = new int[size];
        i++;
    }

    // Заполнение матрицы случайными данными и вывод
    fillMatrix(intMatrix, size);
    cout << "Int Матрица:" << endl;
    printMatrix(intMatrix, size);

    // Определение максимального и минимального элемента на главной диагонали
    int intMin, intMax;
    findMinMaxDiagonal(intMatrix, size, intMin, intMax);
    cout << "Минимальная диагональ матрицы Int: " << intMin << ", Максимальная: " << intMax << endl;

    // Создание матрицы для double
    double** doubleMatrix = new double* [size];
    i = 0;
    while (i < size)
    {
        doubleMatrix[i] = new double[size];
        i++;
    }

    // Заполнение матрицы случайными данными и вывод
    fillMatrix(doubleMatrix, size);
    cout << "Double Матрица:" << endl;
    printMatrix(doubleMatrix, size);

    // Определение максимального и минимального элемента на главной диагонали
    double doubleMin, doubleMax;
    findMinMaxDiagonal(doubleMatrix, size, doubleMin, doubleMax);
    cout << "Минимальная диагональ Double матрицы: " << doubleMin << ", Максимальная: " << doubleMax << endl;

    // Создание матрицы для char
    char** charMatrix = new char* [size];
    i = 0;
    while (i < size)
    {
        charMatrix[i] = new char[size];
        i++;
    }

    // Заполнение матрицы случайными данными и вывод
    fillMatrix(charMatrix, size);
    cout << "Char Матрица:" << endl;
    printMatrix(charMatrix, size);

    // Определение максимального и минимального элемента на главной диагонали
    char charMin, charMax;
    findMinMaxDiagonal(charMatrix, size, charMin, charMax);
    cout << "Минимальная диагональ матрицы Char: " << charMin << ", Максимальная: " << charMax << endl;

    // Очистка памяти
    i = 0;
    while (i < size)
    {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
        delete[] charMatrix[i];
        i++;
    }
    delete[] intMatrix;
    delete[] doubleMatrix;
    delete[] charMatrix;

    return 0;
}