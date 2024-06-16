#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
#define true ((bool)1)
#define false ((bool)0)

#define string(source) create_string(source)

unsigned int strlen_n(const char* str);
bool strcmp_n(const char* a, const char* b);
char* strrev_n(const char* str);

typedef struct _string
{
    char* c_str;
    unsigned int length;
} string;

void initialize_string(string* this, const char* source)
{
    if (this->length > 0)free(this->c_str);
    this->length = strlen_n(source);
    this->c_str = (char*)malloc(this->length);
    memcpy(this->c_str, source, this->length);
}

string create_string(const char* source)
{
    string str;
    initialize_string(&str, source);
    return str;
}

// Returns the length of the given string.
unsigned int strlen_n(const char* str)
{
    unsigned int counter;
    for (counter = 0; str[counter] != 0; counter++);
    return counter;
}

// Returns true if the two string arguments are equal.
bool strcmp_n(const char* a, const char* b)
{
    int i;
    for (i = 0; i <= strlen_n(a); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

// Reverses the given string.
char* strrev_n(const char* str)
{
    char* rev = (char*)malloc(strlen_n(str));
    int i, y;
    for (i = 0, y = strlen_n(str) - 1; i < strlen_n(str); i++, y--)
    {
        rev[y] = str[i];
    }
    rev[strlen_n(str)] = 0;
    return rev;
}

// Returns the if the given string is a palindrome.
bool is_palindrome(const char* str)
{
    return strcmp_n(str, strrev_n(str));
}

int main()
{
    // Prints the string length.
    printf("%u\n", is_palindrome("madam"));
    // Exits the program.
    return 0;
}
