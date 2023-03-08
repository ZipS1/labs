#include <iostream>
#include <iomanip>
#include <typeinfo>

#define OUTPUT_WIDTH 5
#define UNABLE_TO_FIND_AVERAGE -1

using namespace std;

template <typename T>
T** allocate2dArray(int sizeY, int sizeX)
{
    T** arr = new T* [sizeY];
    for (int i = 0; i < sizeY; ++i) {
        arr[i] = new T[sizeX];
    }
    return arr;
}

template <typename T>
void remove2dArray(T** arr, int sizeY)
{
    for (int i = 0; i < sizeY; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

template <typename T>
T** inputMatrix(int& sizeY, int& sizeX)
{
    bool isValidInput = false;
    while (isValidInput == false)
    {
        cout << "Enter " << typeid(T).name() << " matrix size(Y X): ";
        cin >> sizeY >> sizeX;

        if (!(sizeY > 0 && sizeX > 0))
            cout << "Invalid input!" << endl;
        else
            isValidInput = true;
    }

    T** matrix = allocate2dArray<T>(sizeY, sizeX);
    cout << "Input elements of type " << typeid(T).name() << ":" << endl;
    for (int i = 0; i < sizeY; i++)
        for (int j = 0; j < sizeX; j++)
        {
            cout << "[" << i << "][" << j << "]" << "--> ";
            T num;
            cin >> num;
            matrix[i][j] = num;
        }
    cout << endl;

    return matrix;
}

template <typename T>
void outputMatrix(T** matrix, int sizeY, int sizeX)
{
    cout << "Matrix:" << endl;
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            cout << setw(OUTPUT_WIDTH) << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

template <typename T>
double calculateAverageAbove(T** matrix, int sizeY, int sizeX)
{
    int counter = 0;
    double sum = 0;

    for (int i = 0; i < sizeY; i++)
    {
        for (int j = sizeX - i - 2; j >= 0; j--)
        {
            if (matrix[i][j] != 0)
            {
                sum += matrix[i][j];
                counter++;
            }
        }
    }

    return counter ? sum/counter : UNABLE_TO_FIND_AVERAGE;
}

template <typename T>
void processMatrix()
{
    int sizeX, sizeY;
    T** matrix = inputMatrix<T>(sizeY, sizeX);
    outputMatrix<T>(matrix, sizeY, sizeX);

    double average = calculateAverageAbove<T>(matrix, sizeY, sizeX);
    if (average == UNABLE_TO_FIND_AVERAGE)
        cout << "Unable to find average from this matrix" << endl;
    else
        cout << "Average: " << average << endl << endl;

    remove2dArray<T>(matrix, sizeY);
}


int main(int argc, char* argv[])
{
    processMatrix<int>();
    processMatrix<double>();
    processMatrix<int>();
    return 0;
}
