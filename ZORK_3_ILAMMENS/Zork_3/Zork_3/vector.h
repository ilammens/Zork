#ifndef __VECTOR__
#define __VECTOR__

#include <assert.h>

template <class TYPE>
class Vector
{
public: //properties
	TYPE* buffer;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;

public: //methods
	Vector()
	{
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& data) //copy constructor
	{
		buffer = new TYPE[data.num_elements];
		num_elements = data.num_elements;
		capacity = data.capacity;

		for (int i = 0; i < num_elements; ++i)
		{
			buffer[i] = data.buffer[i];
		}
	}

	Vector(unsigned int elements)
	{
		capacity = elements;
		vector = new TYPE[capacity];
	}

	~Vector()
	{
		delete[] buffer;
	}

	void push_back(const TYPE &data)
	{
		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];
			for (int i = 0; i < num_elements; i++)
			{
				*(temp + i) = *(buffer + i);
			}
			delete[] buffer;
			buffer = temp;
		}

		*(buffer + (num_elements++)) = data;
	}

	void push_front(const TYPE& data)
	{
		if (num_elements == capacity)
		{
			capacity *= 2;
			TYPE *temp = nullptr;
			buffer = new TYPE[capacity];

			for (TYPE i = 0; i < capacity; i++)
			{
				*(buffer + (i + 1)) = *(temp + (i + 1));
			}

			delete[] buffer;
			temp = buffer;
		}

		for (TYPE i = 0; i < capacity; i++)
		{
			*(buffer + i) = *(buffer + (i + 1));
		}

		*(buffer) = data;
		num_elements++;
	}

	TYPE operator[](unsigned int index) const
	{
		assert(index < num_elements);
		return buffer[index];
	}

	bool empty()const
	{
		if (num_elements == 0)
			return true;
		else
			return false;
	}

	void clean()
	{
		num_elements = 0;
	}

	unsigned int size()
	{
		return num_elements;
	}

	unsigned int get_capacity()
	{
		return capacity;
	}

	bool pop_back(TYPE& value)
	{
		if (num_elements > 0){
			num_elements--;
			value = vector[num_elements];
			return true;
		}
		return false;
	}

	void shrink_to_fit()
	{
		capacity = num_elements;
		vector = new TYPE[capacity];
	}
};

#endif