// This is the header file for String.cpp which will esentially construct
// our default constructors as well as be the starting point for several
// of our functions which will be modified in string.cpp


#include <iostream>

using namespace std;

class String {
        int size;
        char *buffer;
public:
        String();
        String(const char *a);
        String(const String &);
        ~String();


	// other methods

        friend bool operator==(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
        char & operator [](int i);
        int length();
        String& operator =(const String &);
        String& operator +=(const String &);


};

#endif
