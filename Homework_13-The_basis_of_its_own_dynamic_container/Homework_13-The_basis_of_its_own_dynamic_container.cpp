#include <iostream>

//робота з масивом
void create_vector(int*& vec, const unsigned size, const int valueByDefault = 0);
int* create_vector(const unsigned size, const int valueByDefault = 0);
void delete_vector(int* vec);

void push_back_in_vector(int*& vec, const unsigned size, const int newValue);
void copy_vector(int* const to, const int* const from, const unsigned size);
int& at_vector(int* const vec, const unsigned index);

//перегрузка
void swap_items(int& a, int& b);
void swap_items(int* const a, int* const b);
void swap_items(int* const vec, const unsigned aIndex, const unsigned bIndex);

void create_vector(int*& vec, const unsigned size, const int valueByDefault)
{
	if (vec)
	{
		delete[] vec;
	}
	vec = new int[size];
	for (int count = 0; count < size; ++count)
	{
		vec[count] = valueByDefault;
	}
}

int* create_vector(const unsigned size, const int valueByDefault)
{
	int* vec = new int[size];//створюємо динамічний масив
	for (int count = 0; count < size; ++count)
	{
		vec[count] = valueByDefault;
	}
	return vec;

}

void delete_vector(int* vec)
{
	if (vec)
	{
		delete[] vec;
		vec = nullptr; //не забуваємо занулити
	}

}

void copy_vector(int* const to, const int* const from, const unsigned size)
{
	for (int count = 0; count < size; ++count)
	{
		to[count] = from[count];
	}
}

void push_back_in_vector(int*& vec, const unsigned size, const int newValue)
{
	int* copy = create_vector(size + 1);
	copy_vector(copy, vec, size);
	copy[size] = newValue;
	delete_vector(vec);
	vec = copy;
}

int& at_vector(int* const vec, const unsigned index)
{
	return vec[index];
}

void swap_items(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_items(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_items(int* vec, const unsigned aIndex, const unsigned bIndex)
{
	int& a = at_vector(vec, aIndex);
	int& b = at_vector(vec, bIndex);
	swap_items(a, b);
}

int main()
{
	int* data;
	size_t size = 10;
//1
	int* dyVector = nullptr;
	create_vector(dyVector, 10, 2);
	create_vector(dyVector, 10);//попередня пам'ять звільняється викликом delete_vector  

	for (int count = 0; count < size; ++count)
	{
		std::cout << dyVector[count] << " ";
	}
	std::cout << std::endl;
	delete_vector(dyVector);

//2
	dyVector = create_vector(10, 2);
	int* dyVector1 = create_vector(10);

	for (int count = 0; count < size; ++count)
	{
		std::cout << dyVector[count] << " ";
	}
	std::cout << std::endl;
	delete_vector(dyVector);
	delete_vector(dyVector1);

//4
	dyVector = create_vector(10, 5);
	dyVector1 = create_vector(10);
	copy_vector(dyVector1, dyVector, 10);

	for (int count = 0; count < size; ++count)
	{
		std::cout << dyVector1[count] << " ";
	}
	std::cout << std::endl;
	delete_vector(dyVector);
	delete_vector(dyVector1);

//5
//	size = 10;
	dyVector = create_vector(size, 9);
	push_back_in_vector(dyVector, size, 5);

	for (int count = 0; count < size + 1; ++count)
	{
		std::cout << dyVector[count] << " ";
	}
	std::cout << std::endl;
	delete_vector(dyVector);

//6
//	size = 10;
	dyVector = create_vector(size, 6);
	int& item = at_vector(dyVector, 2);//обережно з індексами
	item = 10;//встановлюємо елемент з індексом 2 в значення 10

	for (int count = 0; count < size; ++count)
	{
		std::cout << dyVector[count] << " ";
	}
	std::cout << std::endl << std::endl;

//7
	swap_items(dyVector, 2, 7);
	for (int count = 0; count < size; ++count)
	{
		std::cout << dyVector[count] << " ";
	}
	std::cout << std::endl << std::endl;

	delete_vector(dyVector);

}
