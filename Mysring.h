#pragma once
#include <iostream>

using std :: ostream;
using std :: istream;

#ifndef SRING_H_
#define SRING_H_
class mysring
{
private:
    char* str;
    size_t len;
public:
// Консткуктор класса 
mysring();
//конструктор с пораметромами
mysring(const char* s);
//конструктор копирования 
mysring(const mysring& s);
//деструктор
~mysring();
//вывод строки 
void print();
mysring& operator =(mysring& s);
friend ostream& operator << (ostream& os, const mysring& s);
//пере грузка оператора [] для опредиленя символа 
char& operator[](int i);

};
#endif