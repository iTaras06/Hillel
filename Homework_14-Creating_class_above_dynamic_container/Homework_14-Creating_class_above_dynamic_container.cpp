#include <iostream>

class MyVector
{
private:
	unsigned m_size = 0;
	int* data = nullptr;

public:
	MyVector(const unsigned size = 0, const int valueByDefault = 0)
	{
		m_size = size;
		data = new int[m_size];

		for (int count = 0; count < m_size; ++count)
		{
			data[count] = valueByDefault;
		}
	}

	~MyVector()
	{
		if (data)
		{
			delete[] data;
			data = nullptr; //не забуваємо занулити
		}
	}

	void push_back(const unsigned size, const int newValue)
	{
		m_size = size;
		data = new int[m_size];

		for (int count = 0; count < m_size; ++count)
		{
			data[count] = newValue;
		}
	}

	MyVector(const MyVector&) = delete;
	MyVector operator=(const MyVector&) = delete;

	int& operator[](const unsigned index)
	{
		return data[index];
	}

	void print()
	{
		for (int count = 0; count < m_size; ++count)
		{
			std::cout << data[count] << " ";
		}
		std::cout << "\n\n";
	}
};

int main()
{
	MyVector t(10, 7);
	t.print();

	MyVector m(20, 90);
	m.print();

	m.push_back(5, 15);
	m.print();

	t[3] = 3;
	t.print();

	m[2] = 2;
	m.print();
}
