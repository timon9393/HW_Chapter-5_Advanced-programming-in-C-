#include <iostream>
#include <vector>
#include <set>

int main()
{
	std::vector<int> vi = { 1, 1, 2, 5, 6, 1, 2, 4 };
	std::cout << "[IN]: ";
	for (const auto& el : vi)
		std::cout << el << " ";
	std::cout << std::endl;

	std::set<int> si;
	for (const auto& el : vi)
		si.insert(el);

	vi.clear();
	for (const auto& el : si)
		vi.push_back(el);

	std::cout << "[OUT]: ";
	for (const auto& el : vi)
		std::cout << el << " ";
	std::cout << std::endl;
}