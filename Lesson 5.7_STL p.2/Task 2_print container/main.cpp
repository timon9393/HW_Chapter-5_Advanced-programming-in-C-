#include <iostream>
#include <set>
#include <list>
#include <vector>

template <class T>
void print_container(const T& cont)
{
	for (auto it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::cout << "Print container std::set:\t"; 
	print_container(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::cout << "Print container std::list:\t";
	print_container(test_list); 

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	std::cout << "Print container std::vector:\t";
	print_container(test_vector); 
}