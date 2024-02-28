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

	smart_array(const smart_array& right)
	{
		size = right.size;
		count = right.count;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = right.arr[i];
		}
	}

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

	smart_array& operator = (const smart_array& right)
	{
		if (this != &right)
		{
			size = right.size;
			count = right.count;
			delete[] arr;
			arr = new int[size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = right.arr[i];
			}
		}
		return *this;
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

	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;

	return 0;
}