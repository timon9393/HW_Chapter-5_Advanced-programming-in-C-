#include <iostream>
#include <vector>

template <typename T>
void move_vectors(std::vector<T>& sourse, std::vector<T>& dest)
{
	dest = std::move(sourse);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << "Before moving:" << std::endl;
	std::cout << "Vector 'one': ";
	for (const auto& el : one)
		std::cout << el << " ";
	std::cout << "\nVector 'two': ";
	for (const auto& el : two)
		std::cout << el << " ";
	std::cout << "\n\n";

	move_vectors(one, two);
	std::cout << "After moving:" << std::endl;
	std::cout << "Vector 'one': ";
	for (const auto& el : one)
		std::cout << el << " ";
	std::cout << "\nVector 'two': ";
	for (const auto& el : two)
		std::cout << el << " ";
	std::cout << std::endl;
	
	return 0;
}