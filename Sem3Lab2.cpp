// Sem3Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

class noncopyable
{
private:
	noncopyable() = default;
	~noncopyable() = default;
	noncopyable(noncopyable const &) = delete;
	noncopyable& operator=(noncopyable const &) = delete;
	noncopyable(noncopyable&&) = default;
	noncopyable& operator=(noncopyable&&) = default;
};

class nonmovable
{
	nonmovable() = default;
	~nonmovable() = default;
	nonmovable(nonmovable const &) = default;
	nonmovable& operator=(nonmovable const &) = default;
	nonmovable(nonmovable&&) = delete;
	nonmovable& operator=(nonmovable&&) = delete;
};

template <typename T>
class Stack
{

private:
	std::vector<T> stack_vector;

public:
	Stack() = default;
	~Stack() = default;
	Stack(Stack const &) = delete;
	Stack& operator=(Stack const &) = delete;
	Stack(Stack&&) = default;
	Stack& operator=(Stack&&) = default;
	void push(T input)
	{
		stack_vector.push_back(input);
	}
	void pop()
	{
		stack_vector.pop_back();
	}
	void push_emplace(T input)
	{
		stack_vector.push_back(T(std::move(input)));
	}
	const T& head()
	{
		return stack_vector.back();
	}
	void pop_destroy()
	{
		stack_vector.back().~T();
	}
};


int main()
{
	Stack<int> my_stack;
	my_stack.push(1);
	std::cout << my_stack.head() << std::endl;
	my_stack.pop();
	my_stack.push_emplace(5);
	std::cout << my_stack.head() << std::endl;
	my_stack.pop_destroy();
	my_stack.push_emplace(3);
	std::cout << my_stack.head() << std::endl;
	system("pause");
	return 0;
}

