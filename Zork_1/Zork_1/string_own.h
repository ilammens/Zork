#ifndef _STRING_OWN_
#define _STRING_OWN_
#include <string.h>

class String
{
public:
	char* buffer = nullptr;

	String(const char* str) //constructor
	{
		buffer = new char[20];

		int s = strlen(str);

		strcpy_s(buffer, s + 1, str);
	}

	~String() //destructor
	{
		delete[] buffer;
	}

	String(const String& str) //copy constructor
	{
		int s = (strlen(str.buffer));

		buffer = new char[s + 1];

		strcpy_s(buffer, s + 1, str.buffer);
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

	bool operator ==(const String& str) const //constructs an extra copy 
	{
		if (strcmp(buffer, str.buffer) == 0)
		{
			return true;
		}
	}


};

#endif
