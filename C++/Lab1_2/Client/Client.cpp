#include "../Server/ComplexNum.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    ComplexNum n1(1, 2), n2(3, 4);
    ComplexNum result;

    //Вывод с сохранением результата
    cout << "Вывод с сохранением результата" << endl;

    result = add(n1,n2);
    result.print();
    result = sub(n1,n2);
    result.print();

    //Разовый вывод без сохранения результата
    cout << "\nРазовый вывод без сохранения результата" << endl;

    add(n1, n2).print();
    sub(n1, n2).print();
}