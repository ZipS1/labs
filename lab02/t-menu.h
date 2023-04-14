#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


const vector<string> MENU_ITEMS = { "Добавить...", "Выбрать...", "Удалить...", "Выход" };
const vector<string> UPDATE_ITEMS = { "по индексу", "в конец" };

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
		cout << "Выбор - ";
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
		cout << "Введите индекс: ";
		cin >> index;
		cout << endl;
	}
	
	return index;
}

template <typename T>
void runAddMenu(Container<T>& cont)
{
	T inp;
	cout << "Введите новый элемент: ";
	cin >> inp;
	T* item = new T(inp);
	cout << "Добавить..." << endl;
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
	cout << "Выбрать...\n";
	size_t index = getUserIndex(cont.size());
	cout << "Элемент: " << cont[index] << endl;
}

template <class T>
void runRemoveMenu(Container<T>& cont)
{
	cout << "Удалить..." << endl;
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
	cout << "Текущий размер контейнера: " << cont.size() << endl;
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