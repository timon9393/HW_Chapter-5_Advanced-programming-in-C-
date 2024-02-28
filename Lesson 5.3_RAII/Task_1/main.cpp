#include <iostream>
#include <Windows.h>

class smart_array
{
public:
	smart_array(int size)
	{
		arr = new int[size];
		this->size = size;
	}
	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;


	void add_element(int a_element)
	{
		if (count < size)
		{
			arr[count] = a_element;
			++count;
		}
		else
		{
			throw std::domain_error("Превышен лимит по количеству элементов в массиве!");
		}
	}

	int get_element(int g_element)
	{
		if (g_element < count && g_element >= 0)
			return arr[g_element];
		else
			throw std::domain_error("Запрашиваемый элемент не существует");		
	}

	~smart_array()
	{
		delete[] arr;
	}

private:
	int* arr;
	int size;
	int count = 0;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}