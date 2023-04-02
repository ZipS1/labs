#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "t-container.h"
#include "shapes.h"

using namespace std;

const string LAB_TASK = "Общие требования : в начале программы вывести задание;\n\
в процессе работы выводить подсказки пользователю\n\
(что ему нужно ввести, чтобы продолжить выполнение программы).\n\
После работы программы вся динамически выделенная память должна быть освобождена.\n\
Класс коллекция должна иметь методы для изменения количества хранимых объектов :\n\
добавление в конец, вставка, усечение, удаление из середины.\n\
При обращении к элементам с несуществующим индексом или\n\
при некорректном изменении количества должно выбрасываться исключение.\n\
Взаимодействие с пользователем организовать в виде простого меню,\n\
обеспечивающего возможность переопределения исходных данных и завершение работы программы.\n\
15. Написать программу, в которой описана иерархия классов : геометрические фигуры\n\
(круг, параллелепипед, трапеция).Описать шаблонный класс для хранения массива\n\
указателей на объекты произвольного класса, в шаблонном классе перегрузить операцию «[]».\n\
Продемонстрировать работу операторов и использование шаблонного класса с различными классами.\n";

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
int runMenu(Container<T>& cont)
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