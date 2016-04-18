#ifndef _STRING_OWN_
#define _STRING_OWN_
#include <string.h>

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

	~String() //destructor
	{
		delete[] buffer;
	}

	String(const String& str) //copy constructor
	{
		int len = (strlen(str.buffer)) + 1;

		max = len;

		buffer = new char[len];

		strcpy_s(buffer, len, str.buffer);
	}

	unsigned int lenght() const
	{
		int len = strlen(buffer);
		return len;
	}

	/* const char* c_str() const //avoids deletion of buffer outside the code, allows only to read it
	{
		return buffer;
	} */

	bool empty() const
	{
		if (strlen(buffer) == 0)
		{
			return true;
		}
	}

	bool operator ==(const String& str) const
	{
		return strcmp(buffer, str.buffer) == 0;
	}

};

#endif
