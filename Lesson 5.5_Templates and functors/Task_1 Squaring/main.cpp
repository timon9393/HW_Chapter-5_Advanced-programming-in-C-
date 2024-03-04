#include <iostream>
#include <vector>

template <class T>
T squaring(T value) { return value * value; }

template <>
std::vector<int> squaring(std::vector<int> a)
{
	for (auto& el : a)
		el *= el;
	return a;		
}

int main()
{
	int value = 4;
	std::cout << "[IN]: " << value << std::endl;
	std::cout << "[OUT]: " << squaring(value) << std::endl;

	std::vector<int> vec = { -1, 4, 8 };
	std::cout << "[IN]: ";
	for (const auto& el : vec)
	{
		std::cout << el << " ";
		if (&el != &vec.back())
			std::cout << ", ";
	}
		
	std::cout << std::endl;
	std::cout << "[OUT]: ";
	int count = 0;
	for (const auto& el : squaring(vec))
	{
		if (count != 0)
			std::cout << ", ";
		std::cout << el;
		count++;
	}		
}