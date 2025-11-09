#ifndef HEADER_H
#define HEADER_H
#include <iostream>

class Stack
{
private:
	int32_t top;
	const int32_t size;
	int32_t* arr;
public:
	Stack(const int32_t& = 100);
	Stack(const Stack&);
	Stack(Stack&&);
	Stack& operator = (Stack&&);
	Stack& operator = (const Stack&);
	void push(int32_t);
	void pop();
	int32_t peak();
	bool IsEmpty();
	bool IsFull();
	~Stack();
};



#endif HEADER_H

//задача на скобки {(})[})
//задачка на вагоны 