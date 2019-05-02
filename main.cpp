#include <iostream>
using namespace std;

#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H

template<typename T = int>
class Stack
{
public:
	Stack();
	bool empty();
	T peek();
	T push(T value);
	T pop();
	int getSize();
private:
	T *elements;
	int size;
	int capacity;
	void ensureCapacity();
};
template<typename T>
Stack<T>::Stack() : size(0), capacity(16)

{
	elements = new T[capacity];
}
template<typename T>
bool Stack<T>::empty()
{
	return (size == 0);
}
template<typename T>
T Stack<T>::peek()

{
	return elements[size - 1];
}
template<typename T>
T Stack<T>::push(T value)
{
	ensureCapacity();
	return elements[size++] = value;
}
template<typename T>
void Stack<T>::ensureCapacity()
{
	if (size >= capacity)
	{
		T *old = elements;
		capacity = 2 * size;
		elements = new T[size * 2];
		for (int i = 0; i < size; i++)
			elements[i] = old[i];
		delete old;
	}
}
template<typename T>
T Stack<T>::pop()
{
	return elements[--size];
}

template<typename T>
int Stack<T>::getSize()
{
	return size;
}
#endif

void Calculation(Stack<char> &stack)
{
	char operation[3];
	int behide, foreword,int_status;
	char middle,char_status;
	for (int i = 0; i < 3; i++)
	{
		operation[i]=stack.peek();
		stack.pop();
	}
	behide = operation[0]-'0';
	middle = operation[1];
	foreword = operation[2]-'0';

	if (middle == '+')
		int_status = foreword + behide;
	if(middle == '-')
		int_status = foreword - behide;
	if (middle == '*')
		int_status = (foreword * behide);
	if (middle == '/')
		int_status = (foreword / behide);
	char_status = int_status + '0';
	stack.push(char_status);
}
void print(Stack<char> &stack)
{
	for (int i = 1; i <= 4; i++)
	{
		Calculation(stack);
		cout << stack.peek() << endl;
	}
}
int main()
{
	Stack<char> stack;
	char nineWord;
	for (int i = 0; i < 9; i++)
	{
		cin >> nineWord;
		stack.push(nineWord);
	}
	print(stack);
	system("pause");
}