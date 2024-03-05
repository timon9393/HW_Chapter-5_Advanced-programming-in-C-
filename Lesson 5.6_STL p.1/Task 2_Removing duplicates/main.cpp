#include <iostream>
#include <set>

int main()
{
	std::set<int, std::greater<int>> arr;
	int size, current;
	std::cout << "[IN]:" << std::endl;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> current;
		arr.insert(current);
	}

	std::cout << "[OUT]:" << std::endl;
	for (const auto& el : arr)
		std::cout << el << std::endl;

}