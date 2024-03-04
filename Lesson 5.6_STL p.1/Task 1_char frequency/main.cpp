#include <iostream>
#include <map>

int main()
{
	std::string str = "Hello world!!";
	std::cout << "[IN]: " << str << std::endl;
	std::map<char, int> m;
	std::multimap<int, char, std::greater<int>> mm;
	for (const auto& em : str)
	{
		int count = 0;
		for (const auto& el : str)
		{
			if (el == em)
				count++;
		}
		m.insert(std::pair<char, int>(em, count)); 
	}

	for (const auto& el : m)
	{
		mm.insert(std::pair<int, char>(el.second, el.first));
	}

	std::cout << "[OUT]:" << std::endl;
	for (const auto& el : mm)
	{
		std::cout << el.second << ": " << el.first << std::endl;
	}
}