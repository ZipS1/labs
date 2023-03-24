#include <iostream>
#include <vector>

using namespace std;

void output(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << endl;
}

bool insertByValue(vector<int>& vec, int value)
{
	bool isFound = false;
	for (size_t index = 0; index != vec.size(); index++)
	{
		if (vec[index] == value)
		{
			isFound = true;
			auto it = vec.begin() + index;
			vec.insert(it, value);
			index++;
		}
	}
	return isFound;
}

void inspectVector()
{
	cout << "Enter elements amount: ";
	size_t n;
	cin >> n;

	vector<int> vec;
	int el;
	cout << "Enter elements: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		cin >> el;
		vec.push_back(el);
	}

	cout << "Enter dublicate value: ";
	int value;
	cin >> value;

	bool isFound = insertByValue(vec, value);
	if (isFound)
		output(vec);
	else
		cout << "Value not found";
}

int main()
{
	inspectVector();
	inspectVector();
}
