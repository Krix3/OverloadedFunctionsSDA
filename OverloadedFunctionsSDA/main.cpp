#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <windows.h>

using namespace std;

// ������ ��� ���������� ������� ���������� �������
template <typename T>
void fillMatrix(T** matrix, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            matrix[i][j] = static_cast<T>(rand() % 100); // ���������� ��������� ��������
            j++;
        }
        i++;
    }
}

// ������ ��� ������ ������� �� �����
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

// ������ ��� ����������� ������������� � ������������ �������� �� ������� ���������
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
    srand(static_cast<unsigned>(time(0))); // �������������� ��������� ��������� �����

    const int size = 3; // ������ ���������� �������

    // �������� ������� ��� int
    int** intMatrix = new int* [size];
    int i = 0;
    while (i < size)
    {
        intMatrix[i] = new int[size];
        i++;
    }

    // ���������� ������� ���������� ������� � �����
    fillMatrix(intMatrix, size);
    cout << "Int �������:" << endl;
    printMatrix(intMatrix, size);

    // ����������� ������������� � ������������ �������� �� ������� ���������
    int intMin, intMax;
    findMinMaxDiagonal(intMatrix, size, intMin, intMax);
    cout << "����������� ��������� ������� Int: " << intMin << ", ������������: " << intMax << endl;

    // �������� ������� ��� double
    double** doubleMatrix = new double* [size];
    i = 0;
    while (i < size)
    {
        doubleMatrix[i] = new double[size];
        i++;
    }

    // ���������� ������� ���������� ������� � �����
    fillMatrix(doubleMatrix, size);
    cout << "Double �������:" << endl;
    printMatrix(doubleMatrix, size);

    // ����������� ������������� � ������������ �������� �� ������� ���������
    double doubleMin, doubleMax;
    findMinMaxDiagonal(doubleMatrix, size, doubleMin, doubleMax);
    cout << "����������� ��������� Double �������: " << doubleMin << ", ������������: " << doubleMax << endl;

    // �������� ������� ��� char
    char** charMatrix = new char* [size];
    i = 0;
    while (i < size)
    {
        charMatrix[i] = new char[size];
        i++;
    }

    // ���������� ������� ���������� ������� � �����
    fillMatrix(charMatrix, size);
    cout << "Char �������:" << endl;
    printMatrix(charMatrix, size);

    // ����������� ������������� � ������������ �������� �� ������� ���������
    char charMin, charMax;
    findMinMaxDiagonal(charMatrix, size, charMin, charMax);
    cout << "����������� ��������� ������� Char: " << charMin << ", ������������: " << charMax << endl;

    // ������� ������
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