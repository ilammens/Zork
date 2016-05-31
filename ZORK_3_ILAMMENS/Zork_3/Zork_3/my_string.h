#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <string.h>
#include "Vector.h"

class String
{
public:
	char* buffer = nullptr;
	unsigned int max = 200;

	String(){};

	String(const char* str) //constructor
	{
		int len = (strlen(str)) + 1;

		max = len;

		buffer = new char[len];

		strcpy_s(buffer, len, str);
	}

	String(const String& str) //copy constructor
	{
		int len = (strlen(str.buffer)) + 1;

		max = len;

		buffer = new char[len];

		strcpy_s(buffer, len, str.buffer);
	}

	~String() //destructor
	{
		delete[] buffer;
	}

	unsigned int capacity() const
	{
		return max;
	}

	void clear()
	{
		buffer[0] = '\0';
	}

	unsigned int lenght() const
	{
		int len = strlen(buffer);
		return len;
	}

	const char* c_str() const //avoids deletion of buffer outside the code, allows only to read it
	{
		return buffer;
	}

	bool empty() const
	{
		if (strlen(buffer) == 0)
		{
			return true;
		}
	}

	bool operator ==(const char* str) const
	{
		return strcmp(buffer, str) == 0;
	}

	void operator =(const String& str)
	{
		int len = (strlen(str.buffer) + 1);

		if (max < len)
		{
			delete[]buffer;
			max = len;
			buffer = new char[max];
		}
		strcpy_s(buffer, max, str.buffer);
	}

	void tokenize(Vector<String> &tokens)
	{
		char* context = nullptr;
		tokens.push_back(String(strtok_s(buffer, " ", &context)));

		while (*context != '\0')
		{
			tokens.push_back(String(strtok_s(NULL, " ", &context)));
		}
	}


}
#endif //my_string