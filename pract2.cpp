#include <iostream>

#include "Mysring.h"

using std :: cin;
using std :: cout;
using std :: endl;
int main()
{
    setlocale(LC_ALL, "rus");
    mysring s1;
    mysring s2("я студент");
    mysring s3(s2);

    s1.print();
    s2.print();
    s3.print();

    s1 =s2;
    s1.print();
    cout << s1 << endl;
    cout << s1[5] << endl;

    return 0;
}