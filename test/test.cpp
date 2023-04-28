#include <iostream>
#include <list>
#include <deque>

using namespace std;

/*
* (Требуется написать две программы - в первой в качестве массива будет list, во второй – deque)
Даны натуральное число и и целочисленный массив из п чисел.
Подсчитать количество серий из простых чисел и выдать эти серии.
*/

void outputList(list<int> arr)
{
    for (auto num : arr)
        cout << num << " ";
    cout << endl;
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;

    if (num == 2)
        return true;

    for (unsigned int i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}
void outputSeries(list<int> array)
{
    int count = 0;
    bool isInSeries = false;
    list<int> series;

    for (int num : array)
    {
        if (isPrime(num))
        {
            series.push_back(num);
            if (isInSeries == false)
                isInSeries = true;
        }
        else
            if (isInSeries == true)
            {
                count++;
                isInSeries = false;
                outputSeries(series);
                series.clear();
            }
    }

    cout << "количество серий: " << count << endl;
}

void inspectList()
{
    cout << "--- List ---" << endl;
    list<int> list;
    size_t n;
    cout << "Введите число N: ";
    cin >> n;

    cout << "Введите N чисел: ";
    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        list.push_back(num);
    }

    outputSeries(list);
}

void outputDeque(deque<int> arr)
{
    for (auto num : arr)
        cout << num << " ";
    cout << endl;
}

void outputSeries(deque<int> arr)
{
    int count = 0;
    bool isInSeries = false;
    list<int> series;

    for (int num : arr)
    {
        if (isPrime(num))
        {
            series.push_back(num);
            if (isInSeries == false)
                isInSeries = true;
        }
        else
            if (isInSeries == true)
            {
                count++;
                isInSeries = false;
                outputSeries(series);
                series.clear();
            }
    }

    cout << "количество серий: " << count << endl;
}

void inspectDeque()
{
    cout << "--- Deque ---" << endl;
    deque<int> deq;
    size_t n;
    cout << "Enter number N: ";
    cin >> n;

    cout << "Enter N numbers: ";
    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        deq.push_back(num);
    }

    outputSeries(deq);
}

int main()
{
    inspectList();
    cout << endl;
    inspectDeque();
}