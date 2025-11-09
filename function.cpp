#include "header.h"

Stack::Stack(const int32_t& _size) : size(_size), top(0) {
	if (size <= 1) {
		throw std::invalid_argument("incorrect size!\n");
	}
	arr = new int32_t[size];
}

Stack::Stack(const Stack& other) : size(other.size), top(other.top) {
	arr = new int32_t[size];
	for (size_t i = 0; i < top; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Stack::Stack(Stack&& other) : size(other.size), top(other.top) {
	const_cast<int&>(size) = 0;
	other.top = 0;
	arr = new int32_t[size];
	arr = other.arr;
	other.arr = nullptr;
}



void Stack::push(int32_t num) {
	if (IsFull) {
		throw std::exception("Staek is full!\n");
	}
	arr[top++] = num;
}

void Stack::pop() {
	if (IsEmpty()) {
		throw std::exception("Staek is empty!\n");
	}
	--top;
}

int32_t Stack::peak() {
	if (IsEmpty()) {
		throw std::exception("Staek is empty!\n");
	}
	return arr[top - 1];
}

bool Stack::IsEmpty() {
	return top == 0;
}

bool Stack::IsFull() {
	return top == size;
}

Stack::~Stack()
{
	if (arr != nullptr) {
		delete[] arr;
		arr = nullptr;
	}
}

Stack& Stack::operator=(const Stack& other)
{
	if (this == &other) {
		return *this;
	}
	if (size != other.size) {
		throw std::runtime_error("Stack sizes must match for assignment");
	}	
	top = other.top;
	std::copy(other.arr, other.arr + size, arr);

	return *this;
}

Stack& Stack::operator=(Stack&& other) {
	if (this == &other)
		return *this;

	delete[] arr;

	const_cast<int&>(size) = other.size; 
	top = other.top;
	arr = new int32_t[size];
	std::copy(other.arr, other.arr + size, arr);

	return *this;
}