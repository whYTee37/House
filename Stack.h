#include<iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H
enum Error_code {
	success, underflow, overflow
};

template<typename Stack_entry>
class Stack {
public:
	Stack(int size) :count(0), stacksize(size), entry(new Stack_entry[size]) {}
	~Stack() { delete[] entry; }
	bool empty() const
	{
		return (count == 0);
	}
	Error_code pop()
	{
		Error_code outcome = success;
		if (empty())
			outcome = underflow;
		else
			count--;
		return outcome;
	}
	Error_code push(const Stack_entry & item)
	{
		Error_code outcome = success;
		if (count >= stacksize)
			outcome = overflow;
		else
			entry[count++] = item;
		return outcome;
	}
	Error_code top(Stack_entry & item) const
	{
		Error_code outcome = success;
		if (empty())
			outcome = underflow;
		else
			item = entry[count - 1];
		return outcome;
	}


private:
	int count;
	int stacksize;
	Stack_entry* entry;
};
#endif
