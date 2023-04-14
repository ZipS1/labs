#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "ticket.h"

using namespace std;


const vector<string> MENU_ITEMS = { "Добавить...", "Удалить...", "Вывести по номеру рейса и дате вылета...", "Вывести все..." };

enum { Add = 1, Remove, SelectSpec, SelectAll, Exit };

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

void runAddMenu(stack<Ticket>& cont)
{
	Ticket newTicket;

	cout << "Введите пункт назначения: ";
	string destination;
	cin >> destination;
	newTicket.destination = destination;

	cout << "Введите номер рейса: ";
	string flightNumber;
	cin >> flightNumber;
	newTicket.flightNumber = flightNumber;

	cout << "Введите ФИО пассажира: ";
	string name;
	cin >> name;
	newTicket.passengerName = name;

	cout << "Введите дату: ";
	string date;
	cin >> date;
	newTicket.date = date;

	cont.push(newTicket);
}

void outputTicket(Ticket ticket)
{
	cout << "Пункт назначения: ";
	cout << ticket.destination << endl;

	cout << "Номер рейса: ";
	cout << ticket.flightNumber << endl;

	cout << "ФИО пассажира: ";
	cout << ticket.passengerName << endl;

	cout << "Дата рейса: ";
	cout << ticket.date << endl;
	
	cout << endl;
}

void RunSelectionMenu(stack<Ticket> cont)
{
	cout << "Введите номер рейса: ";
	string flightNumber;
	cin >> flightNumber;

	cout << "Введите дату: ";
	string date;
	cin >> date;

	for (size_t i = 0; i < cont.size(); i++)
	{
		Ticket ticket = cont.top();
		cont.pop();
		if (ticket.flightNumber == flightNumber && ticket.date == date)
			outputTicket(ticket);
	}
}

void selectAll(stack<Ticket> cont)
{
	for (size_t i = 0; i < cont.size(); i++)
	{
		Ticket ticket = cont.top();
		cont.pop();
		outputTicket(ticket);
	}
}

int runMenu(stack<Ticket> &cont)
{
	int choice = getUserChoiceOf(MENU_ITEMS);

	switch (choice)
	{
	case Add:
		runAddMenu(cont);
		break;
	case Remove:
		cont.pop();
		break;
	case SelectSpec:
		RunSelectionMenu(cont);
		break;
	case SelectAll:
		selectAll(cont);
		break;
	case Exit:
		break;
	}

	return choice;
}