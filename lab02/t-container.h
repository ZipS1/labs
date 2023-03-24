#pragma once
#include <stdexcept>

template <class T>
class Container
{
	struct Node
	{
		T* dataPtr;
		Node* next;
	};
public:
	bool push(T* ptr);
	bool insert(T* ptr, const size_t index);
	T* pop();
	T* remove(size_t index);
	size_t size();
	T get(size_t const& index);
	T operator[](size_t index);
	~Container();

private:
	Node* head = nullptr;
	size_t counter = 0;
};

template<class T>
bool Container<T>::push(T* ptr)
{
	Node* newNode = new Node;
	newNode->dataPtr = ptr;
	newNode->next = nullptr;

	if (counter == 0)
		head = newNode;
	else
	{
		Node* currentNode = head;
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		currentNode->next = newNode;
	}

	counter++;
	return true;
}

template<class T>
bool Container<T>::insert(T* ptr, const size_t index)
{
	if (index > counter)
		throw new std::out_of_range("Cannot write to this index");

	Node* newNode = new Node;
	newNode->dataPtr = ptr;
	newNode->next = nullptr;

	if (counter == 0)
		head = newNode;
	else
		if (index == 0)
		{
			Node* previousHead = head;
			head = newNode;
			head->next = previousHead;
		}
		else
		{
			size_t curIndex = 0;
			Node* currentNode = head;
			while (curIndex != index - 1)
			{
				currentNode = currentNode->next;
				curIndex++;
			}

			Node* previousNext = currentNode->next;
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}

	counter++;
	return true;
}

template<class T>
T* Container<T>::pop()
{
	if (counter == 0)
		throw std::logic_error("Trying to pop from empty list");

	size_t curIndex = 0;
	Node* currentNode = head;
	while (curIndex != counter - 2)
	{
		currentNode = currentNode->next;
		curIndex++;
	}

	Node* lastNode = currentNode->next;
	currentNode->next = nullptr;
	counter--;
	return lastNode->dataPtr;
}

template<class T>
T* Container<T>::remove(size_t index)
{
	if (index >= counter)
		throw new std::out_of_range("No such index in list");

	size_t curIndex = 0;
	Node* currentNode = head;
	while (curIndex != index - 1)
	{
		currentNode = currentNode->next;
		curIndex++;
	}

	Node* removingNode = currentNode->next;
	currentNode->next = removingNode->next;
	counter--;
	return removingNode->dataPtr;
}

template<class T>
inline size_t Container<T>::size()
{
	return counter;
}

template<class T>
T Container<T>::get(size_t const& index)
{
	if (index >= counter)
		throw new std::out_of_range("No such index in container");


	size_t curIndex = 0;
	Node* curNode = head;
	while (curIndex != index)
	{
		curNode = curNode->next;
		curIndex++;
	}

	return *curNode->dataPtr;
}

template<class T>
T Container<T>::operator[](size_t index)
{
	return get(index);
}

template<class T>
Container<T>::~Container()
{
	if (counter == 0)
		return;

	Node* currentNode = head;
	while (currentNode->next != nullptr)
	{
		Node* next = currentNode->next;
		if (currentNode->dataPtr != nullptr)
			delete currentNode->dataPtr;
		delete currentNode;
		currentNode = next;
	}
	if (currentNode->dataPtr != nullptr)
		delete currentNode->dataPtr;
	delete currentNode;
}