#pragma once
#include <iostream>
#include <new>


template<typename T>
class vector
{
private:
	T* data = nullptr;
	uint16_t size = 0;
	uint16_t capacity = 0;
	int16_t last_item = -1;
public:
	vector() = default;
	vector(uint16_t size);

	vector(const vector& other);
	
	vector& operator = (const vector& other)
	{
		{
			this->size = other.size;
			this->capacity = other.capacity;
			this->last_item = other.last_item;
			if (this->data != nullptr)
			{
				delete[] this->data;
			}
			this->data = new T[other.capacity];
			for (uint16_t i = 0; i < other.capacity; ++i)
			{
				this->data[i] = other.data[i];
			}
			return *this;
		}
	}

	vector operator + (const vector& other)
	{
		vector temp(this->size + other.size);
		temp.last_item = this->last_item + other.last_item + 1;
		for (uint16_t i = 0; i <= temp.last_item; ++i)
		{
			if (i <= this->last_item)
				temp.data[i] = this->data[i];
			else
				temp.data[i] = other.data[i - this->last_item - 1];
		}
		return temp;
	}

	void push_back(const T& item);


	inline void print() const;

	void GetSize() const;

	void resize(uint16_t newSize, std::nothrow_t);

	~vector()
	{
		delete[] data;
	}
};