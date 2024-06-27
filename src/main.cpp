#include "Header.h"
using namespace std;

template<typename T>
vector<T>::vector(uint16_t size)
{
	this->size = size;
	this->capacity = size + 3;
	this->data = new T[this->capacity];
	for (uint16_t i = 0; i < this->capacity; ++i)
	{
		this->data[i] = T(0);
	}
};

template<typename T>
vector<T>::vector(const vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->last_item = other.last_item;
	this->data = new T[this->capacity];
	for (uint16_t i = 0; i < this->capacity; ++i)
	{
		this->data[i] = other.data[i];
	}
};

template<typename T>
void vector<T>::push_back(const T& item)
{
	if (this->last_item < (this->capacity - 1))
	{
		if (this->last_item < (this->size - 1))
		{
			this->data[this->last_item + 1] = item;
			++this->last_item;
		}
		else if (this->last_item == (this->size - 1))
		{
			++this->size;
			++this->last_item;
			this->data[this->last_item] = item;
		}
	}
	else
	{
		this->capacity += 4;
		++this->size;
		++this->last_item;

		T* temp = new T[this->capacity];
		for (uint16_t i = 0; i < (this->size - 1); ++i)
			temp[i] = this->data[i];
		temp[this->size - 1] = item;
		for (uint16_t i = this->size; i < this->capacity; ++i)
			temp[i] = 0;
		delete[] this->data;
		this->data = temp;
		temp = nullptr;
	}
}

template<typename T>
inline void vector<T>::print() const
{
	for (uint16_t j = 0; j < this->size; ++j)
		cout << data[j] << "  ";
	cout << endl;
}

template<typename T>
void vector<T>::GetSize() const
{
	cout << this->size << endl;
}

template<typename T>
void vector<T>::resize(uint16_t newSize, std::nothrow_t)
{
	if (this->size < newSize)
	{
		T* temp = new T[newSize + 3];
		for (uint16_t i = 0; i < this->size; ++i)
			temp[i] = this->data[i];
		for (uint16_t i = this->size; i < (newSize + 3); ++i)
			temp[i] = T(0);
		this->size = newSize;
		this->capacity = this->size + 3;
		delete[] this->data;
		this->data = temp;
		temp = nullptr;
	}
}

int main()
{
	vector<int> a(2);
	a.GetSize();
	a.push_back(8);
	a.push_back(27);
	a.print();
	a.resize(6, std::nothrow);
	a.GetSize();
	a.print();
	a.push_back(11);
	a.push_back(33);

	a.GetSize();
	a.print();

	return 0;
}