#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <functional>


#define FILENAME "name.txt"

using namespace std;

/*
Дана строка name и вектор V с четным количеством элементов. 
Найти все различные числа, которые входят во вторую половину 
исходного вектора и при этом отсутствуют в первой половине. 
Записать найденные числа в текстовый файл с именем name в убывающем порядке, 
выводя каждое число на новой строке. Использовать алгоритм set_difference 
для двух вспомогательных множеств и итератора ostream_iterator. 
Чтобы обеспечить вывод чисел в нужном порядке, 
при создании множеств и в алгоритме использовать функциональный объект greater.
*/

void inputVector(vector<int>& nums)
{
    size_t n = 1;
    cout << "Enter even amount of nums: ";
    while (n % 2 == 1)
        cin >> n;
    nums.resize(n);

    cout << "Enter nums: ";
    for (size_t i = 0; i < n; i++)
        cin >> nums[i];
}

void outputVector(vector<int>& vec)
{
    cout << "Output array: ";
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

int main()
{
    string name;
    vector<int> nums;

    inputVector(nums);
    set<int, greater<int>> a(nums.begin() + nums.size() / 2, nums.end());
    set<int, greater<int>> b(nums.begin(), nums.begin() + nums.size() / 2);
    
    ofstream of(FILENAME);
    ostream_iterator<int> os_it(of, "\n");

    set_difference(a.begin(), a.end(), b.begin(), b.end(), os_it, greater<int>{});
}