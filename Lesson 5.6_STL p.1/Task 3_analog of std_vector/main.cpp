#include <iostream>
#include <vector>

template <class T>
class vector
{
public:
	vector(T capacity) : Size(0), Capacity(capacity)
	{
		arr = new T[Capacity]();
	}

	vector() : Size(0), Capacity(0)
	{
		arr = new T[0]();
	}

	T at(int index)
	{
		try {
			if (index >= Size || index < 0)
				throw std::out_of_range ("Wrong index for .at()");
			return arr[index];
			
		}
		catch (const std::out_of_range& oor)
		{
			std::cout << oor.what() << std::endl;
			std::abort();
		}		
	}

	void push_back(T value)
	{
		if (Size == Capacity)
		{
			if (Capacity == 0) { Capacity = 1; }
			else { Capacity *= 2; }			
			T* temp = new T[Capacity]();
			for (int i = 0; i < Size; i++)
				temp[i] = arr[i];
			delete[] arr;			
			arr = temp;
			arr[Size] = value;
			Size++;
		}
		else
		{
			arr[Size] = value;
			Size++;
		}
	}

	int size() { return Size; }
	int capacity() { return Capacity; }

	~vector() 
	{		
		delete[] arr;
	}

private:
	T* arr;
	int Size;
	int Capacity;
};

int main()
{
	vector<int> v(2);
	std::cout << "size() = " << v.size() << "\t" << "capacity() = " << v.capacity() << std::endl;
	v.push_back(26);
	std::cout << "size() = " << v.size() << "\t" << "capacity() = " << v.capacity() << std::endl;
	v.push_back(21);
	std::cout << "size() = " << v.size() << "\t" << "capacity() = " << v.capacity() << std::endl;
	v.push_back(3);
	std::cout << "size() = " << v.size() << "\t" << "capacity() = " << v.capacity() << std::endl;
	v.push_back(216);
	std::cout << "size() = " << v.size() << "\t" << "capacity() = " << v.capacity() << std::endl;
	v.push_back(9);
	std::cout << "size() = " << v.size() << "\t" << "capacity() = " << v.capacity() << std::endl;

	std::cout << ".at(3) = " << v.at(3) << "\t" << ".at(1) = " << v.at(1) << std::endl;
}