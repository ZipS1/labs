#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


const vector<string> MENU_ITEMS = { "��������...", "�������...", "�������...", "�����" };
const vector<string> UPDATE_ITEMS = { "�� �������", "� �����" };

enum {Add = 1, Select, Remove, Exit};
enum {AtIndex = 1, AtEnd};


void outputItems(const vector<string> items)
{
	for (size_t i = 1; i <= items.size(); i++)
		cout << i << " - " << items[i - 1] << endl;
}

int getUserChoiceOf(vector<string> items)
{
	int choice = -1;
	
	while (choice < 1 || choice > items.size())
	{
		outputItems(items);
		cout << "����� - ";
		cin >> choice;
		cout << endl;
	}
	
	return choice;
}

size_t getUserIndex(size_t size = SIZE_MAX)
{
	int index = -1;
	while (index < 0 || index >= size)
	{
		cout << "������� ������: ";
		cin >> index;
		cout << endl;
	}
	
	return index;
}

template <typename T>
void runAddMenu(Container<T>& cont)
{
	T inp;
	cout << "������� ����� �������: ";
	cin >> inp;
	T* item = new T(inp);
	cout << "��������..." << endl;
	int choice = getUserChoiceOf(UPDATE_ITEMS);
	switch (choice)
	{
	case AtIndex:
		cont.insert(item, getUserIndex());
		break;
	case AtEnd:
		cont.push(item);
		break;
	}
}

template <typename T>
void runSelectionMenu(Container<T>& cont)
{
	cout << "�������...\n";
	size_t index = getUserIndex(cont.size());
	cout << "�������: " << cont[index] << endl;
}

template <class T>
void runRemoveMenu(Container<T>& cont)
{
	cout << "�������..." << endl;
	int choice = getUserChoiceOf(UPDATE_ITEMS);
	switch (choice)
	{
	case AtIndex:
		cont.remove(getUserIndex());
		break;
	case AtEnd:
		cont.pop();
		break;
	}
}

template <class T>
int runMenu(stack<& cont)
{
	cout << "������� ������ ����������: " << cont.size() << endl;
	int choice = getUserChoiceOf(MENU_ITEMS);

	switch (choice)
	{
	case Add:
		runAddMenu(cont);
		break;
	case Select:
		runSelectionMenu(cont);
		break;
	case Remove:
		runRemoveMenu(cont);
		break;
	case Exit:
		break;
	}

	return choice;
}