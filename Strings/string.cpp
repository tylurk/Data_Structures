// Program that will modify constructors and operators +, - , =... for our String class
// as well as output and [] in order for us to get locations within our string
// and cout the String.

#include "string.h"
#include <cstring>

using namespace std;

//Sets default string to hold no values in size or buffer;

String::String()
{
	size = 0;
	buffer = 0;

}

/* Copies explicit string to implicit string by setting the new size equal to the size of
the a string. In order to prevent a segmentation fault buffer needs to be given enough space
in order for us to be able to increment through and set the elements of a equal to the
elements of the new string. This will need to be deleted [] later*/

String::String(const String & a)
{
	size = a.size;
	buffer = new char[size];
	for (int i = 0; i < size; i++){
		buffer[i] = a.buffer[i];
		}
}


/* Does virtually the same thing as the previous copy, but in order to copy the
size of our a string we instead need to use strlen*/

String::String(const char * a)
{
	size = strlen(a);
	buffer = new char[size];
	for (int i = 0; i < size; i++){
		buffer[i] = a[i];
	}

}

// deletes buffer for cleaning up.
String::~String()
{
	delete [] buffer;
}

/* Here I modify the = operator. If the size of a is above 0 I will need to alocate enough room for
the new string therefor I will use *temp to point at enough space for the size of char a. I will
then attatch each char found in a to temp. I will clean the buffer. else if the size = 0 delete buffer
and set it to 0 to match string a. */

String & String::operator =(const String & a)
{
	if (a.size > 0){
		size = a.size;
		char *temp = new char[size];
		strcat(temp,a.buffer);
		if(buffer){
			delete [] buffer;
		}
		buffer = temp;
	}
	else
	{
		size = 0;
		if (buffer){
			delete [] buffer;
			buffer = 0;
		}
	}

}

/* Initially the operator will check 2 stings to see if they are of equal size.
 if they are not it is false by default. If they are I will use a for loop to
 compare each element if 1 element is not equal to its counter part the loop
 returns false */

bool operator ==(const String & a, const String & b)
{
	if (a.size == b.size){
		for (int i = 0; i < a.size; i++){
			if (a.buffer[i] != b.buffer[i]){
				return 0;
			}
		}
	}
	else
		return 0;
}

/* checks if string is less than or equal to string b. it will
need to iterate through each string and compare each location
of the same point to the opposing string. If the value is
equal to or less than than return true if not will return false */

bool operator <=(const String & a, const String & b)
{
	for(int i = 0; i < a.size and i < b.size; i++){
		if (a.buffer[i] == b.buffer[i])
			return 1;
		else if (a.buffer[i] <= b.buffer[i]){
			return 1;
		}
	}

}

/* adds 2 strings together by first storing the initial string in
a temp then adding the sizes of each string together to have enough
room to append each. finally uses a for loop to insert original string
into new string and another for loops to append the added string into
the new string. */

String & String::operator +=(const String & a)
{
	String temp(*this);
	size = a.size + temp.size;

	buffer = new char[temp.size];

	int i;

	for (i = 0; i < size; i++){
		buffer[i] = temp[i];
	}

	for (i = 0;  i < a.size; i++){
		buffer[i+temp.size] = a.buffer[i];
	}

	return *this;
}

// by using osteam I Will simply use the operator <<  to return the string
ostream & operator<<(ostream & out, const String & a)
{
return out;
}

// Here I will use the int i and follow the pointer to that location
char & String::operator[](int i)
{
	return buffer[i];
}

// Simply return the length of the string by returning the size
int String::length()
{
	return size;
}
