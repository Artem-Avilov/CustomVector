#include <iostream>
#include <new>
using namespace std;

template<typename T>
class vector
{
private:
	T* data = nullptr;
	uint8_t size = 0;
	uint8_t capacity = 0;
	int16_t last_item = -1;
public:
	vector() = default;
	vector(uint8_t size)
	{
		this->size = size;
		this->capacity = size + 3;
		this->data = new T[this->capacity];
		for (int i = 0; i < this->capacity; ++i)
		{
			this->data[i] = T(0);
		}
	}
	
	vector(const vector& other)
	{
		this->size = other.size;
		this->capacity = other.capacity;
		this->last_item = other.last_item;
		this->data = new T[this->capacity];
		for (uint8_t i = 0; i < this->capacity; ++i)
		{
			this->data[i] = other.data[i];
		}
	}

	vector& operator = (const vector& other)
	{
		this->size = other.size;
		this->capacity = other.capacity;
		this->last_item = other.last_item;
		if (this->data != nullptr)
		{
			delete[] this->data;
		}
		this->data = new T[other.capacity];
		for (uint8_t i = 0; i < other.capacity; ++i)
		{
			this->data[i] = other.data[i];
		}
		return *this;
	}

	vector operator + (const vector& other)
	{
		vector temp(this->size + other.size);
		temp.last_item = this->last_item + other.last_item +1;
		for (uint8_t i = 0; i <= temp.last_item; ++i)
		{
			if (i <= this->last_item)
				temp.data[i] = this->data[i];
			else 
				temp.data[i] = other.data[i - this->last_item - 1];
		}
		return temp;
	}

	void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
		void* ptr = malloc(size);
		return ptr;
	}
		
	void push_back(const T& item)
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
			for (uint8_t i = 0; i < (this->size - 1); ++i)
				temp[i] = this->data[i];
			temp[this->size - 1] = item;
			for (uint8_t i = this->size; i < this->capacity; ++i)
				temp[i] = 0;
			delete [] this->data;
			this->data = temp;
			temp = nullptr;
		}
	}
	
	inline void print() const
	{
		for (uint8_t j = 0; j < this->size; ++j)
			cout << data[j] << "  ";
		cout << endl;
	}
	
	void GetSize() const
	{
		cout << uint16_t(this->size) << endl;
	}

	void resize(uint8_t newSize, std::nothrow_t)
	{
		if (this->size < newSize)
		{
			T* temp = new T[newSize + 3];
			for (uint8_t i = 0; i < this->size; ++i)
				temp[i] = this->data[i];
			for (uint8_t i = this->size; i < (newSize + 3); ++i)
				temp[i] = T(0);
			this->size = newSize;
			this->capacity = this->size + 3;
			delete[] this->data;
			this->data = temp;
			temp = nullptr;
		}
	}

	~vector()
	{
		delete[] data;
	}
};

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