#include <iostream>
#include <vector>

template<typename T>
class table
{
public:
	table(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {};

	std::vector<T>& operator[] (int index)
	{
		return data[index];
	}

	std::vector<T>& operator[] (int index) const
	{
		return data[index];
	}

	int Size() const
	{
		return rows * cols;
	}

private:
	int rows;
	int cols;
	std::vector<std::vector<T>> data;
};

int main()
{
	table<int> tab(2, 3);
	tab[0][0] = 4;
	std::cout << "tab[0][0] = " << tab[0][0] << std::endl;
	std::cout << "tab.Size() = " << tab.Size() << std::endl;

	return 0;
}