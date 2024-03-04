#include <iostream>
#include <vector>

template<typename T>
class functor
{
public:
	functor(std::vector<T>& arr) : array(arr), counter{ 0 }, sum{ 0 } {};

	void operator()()
	{
		std::cout << "Sum = " << get_sum() << std::endl;
		std::cout << "Count = " << get_count() << std::endl;
	}

	T get_sum()
	{
		for (const auto& el : array)
		{
			if (el % 3 == 0)
				sum += el;
		}
		return sum;
	}

	int get_count()
	{
		for (const auto& el : array)
		{
			if (el % 3 == 0)
				counter++;
		}
		return counter;
	}
	
private:
	int counter;
	T sum;
	std::vector<T> array;
};

int main()
{
	std::vector<int> arr{ 4, 1, 3, 6, 25, 54 };
	functor<int> test(arr);

	std::cout << "IN: ";
	for (const auto& el : arr)
		std::cout << el << " ";
	std::cout << std::endl;
	test();

	return 0;
}