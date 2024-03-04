#include <iostream>
#include <vector>

template<typename T>
class functor
{
public:

	void operator()(int num)
	{
		if (num % 3 == 0) {
			sum += num;
			counter++;
		}
	}

	T get_sum() { return sum; }

	int get_count() { return counter; }
	
	
private:
	int counter = 0;
	T sum = 0;
};

int main()
{
	std::vector<int> arr{ 4, 1, 3, 6, 25, 54 };
	functor<int> test;

	std::cout << "IN: ";
	for (const auto& el : arr)
	{
		std::cout << el << " ";
		test(el);
	}		
	std::cout << std::endl;

	std::cout << "[OUT]: get_sum() = " << test.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << test.get_count() << std::endl;

	return 0;
}