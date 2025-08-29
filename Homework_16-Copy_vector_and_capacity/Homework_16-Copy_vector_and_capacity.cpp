#include <iostream>

class MyVector
{
private:
	unsigned m_size = 0;
	int* data = nullptr;
	unsigned capacity = 0;

public:
	MyVector(const unsigned size = 0, const int valueByDefault = 0)
	{
		m_size = size;
		capacity = 2 * m_size;

		if (m_size == 0)
			return;


		data = new int[capacity];

		for (unsigned count = 0; count < capacity; ++count)
		{
			data[count] = 0;
		}


		for (unsigned count = 0; count < m_size; ++count)
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

	void push_back(const int newValue)
	{
		if (capacity > m_size)
		{
			data[m_size] = newValue;
			++m_size;
			return;
		}

		capacity = m_size * 2;
		int* copy = new int[capacity];
		for (unsigned count = 0; count < m_size; ++count)
		{
			copy[count] = data[count];
		}
		copy[m_size] = newValue;
		++m_size;
		delete[]data;
		data = copy;
	}

	MyVector(const MyVector& other):MyVector()
	{
		if (!other.capacity)
		{
			return;
		}
		data = new int[other.capacity];
		capacity = other.capacity;
		m_size = other.m_size;
		for (unsigned count = 0; count < m_size; ++count)
		{
			data[count] = other.data[count];
		}
	}

	MyVector& operator=(const MyVector& other)
	{
		if (this == &other)
		{
			return *this;
		}
		
		if (data)
		{
			delete[]data;
			data = nullptr;
		}
		capacity = other.capacity;
		m_size = other.m_size;
		if (other.capacity == 0)
		{
			return *this;
		}
		data = new int[other.capacity];
		for (unsigned count = 0; count < capacity; ++count)
		{
			data[count] = other.data[count];
		}
		return *this;
	}

	MyVector(MyVector&&) = delete;
	MyVector& operator=(MyVector&&) = delete;

	int& operator[](const unsigned index)
	{
		return data[index];
	}

	void print()
	{
		for (unsigned count = 0; count < capacity; ++count)
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

	MyVector m(10, 9);
	m.print();

	m.push_back(5);
	m.print();

	m.push_back(8);
	m.print();

	t[3] = 3;
	t.print();

	m[2] = 2;
	m.print();

	t = m;
	t.print();
}
