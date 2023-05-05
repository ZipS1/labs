#include <iostream>
#include <list>
#include <deque>

using namespace std;

void outputList(list<int> arr)
{
    for (auto num : arr)
        cout << num << " ";
    cout << endl;
}

void outputSeries(list<int> array, int m)
{
    int count = 0;
    bool isInSeries = false;
    list<int> series;

    for (int num : array)
    {
        if (num == m)
        {
            series.push_back(num);
            if (isInSeries == false)
            {
                isInSeries = true; 
            }
            else
            {
                count++;
                outputList(series);
                series.clear();
                isInSeries = false;
            }
        }
        else if (isInSeries)
            series.push_back(num);
    }

    cout << "Series amount: " << count << endl;
}

void inspectList()
{
    cout << "--- List ---" << endl;
    list<int> list;
    size_t n;
    cout << "Enter number N: ";
    cin >> n;

    cout << "Enter N numbers: ";
    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        list.push_back(num);
    }

    int m;
    cout << "Enter number M: ";
    cin >> m;
    cout << endl;

    outputSeries(list, m);
}

void outputDeque(deque<int> arr)
{
    for (auto num : arr)
        cout << num << " ";
    cout << endl;
}

void outputSeries(deque<int> arr, int m)
{
    int count = 0;
    bool isInSeries = false;
    list<int> series;

    for (int num : arr)
    {
        if (num == m)
        {
            series.push_back(num);
            if (isInSeries == false)
            {
                isInSeries = true;
            }
            else
            {
                count++;
                outputList(series);
                series.clear();
                isInSeries = false;
            }
        }
        else if (isInSeries)
            series.push_back(num);
    }

    cout << "Series amount: " << count << endl;
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

    int m;
    cout << "Enter number M: ";
    cin >> m;
    cout << endl;

    outputSeries(deq, m);
}

int main()
{
    inspectList();
    cout << endl;
    inspectDeque();
}


