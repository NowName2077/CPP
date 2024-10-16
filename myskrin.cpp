#include "Mysring.h"
#include <cstring>
#include <iostream>

using std :: ostream;
using std :: istream;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: strlen;

mysring::mysring() : len(0)
{
    str = new char[1];
    str [0] = '\0';
}
//конструктор с пораметромами
mysring::mysring(const char* s)
{
    len = strlen(s);
    str = new char[len+1];
    for (size_t i = 0; i <= len; i++)
    {
        str[i] = s[i];
    }
}
mysring::mysring(const mysring& s)
{
    len = s.len;
    str = new char[len+1];
    for (size_t i = 0; i <= len; i++)
    {
        str[i] = s.str[i];
    }
}
//деструктор
mysring::~mysring()
{
    delete[]str;
    len =0 ;
    str = new char[1];
    str[0] = '\0';
    cout <<"трока удалена \n";
}

void mysring:: print()
{
    cout <<str << endl;
}

mysring& mysring:: operator = (mysring& s)
{
    delete[]str;
    len = s.len;
    str = new char[len+1];
    for (size_t i = 0; i <= len; i++)
    {
        str[i] = s.str[i];
    }
    return *this;
}

ostream& operator << (ostream& os, const mysring& s)
{
    os<< s.str << ",длина строки = "<< s.len;
    return os;
}

char& mysring :: operator[](int i)
{
    return str[i];
}