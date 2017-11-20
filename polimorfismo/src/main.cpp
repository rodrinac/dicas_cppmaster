#include <iostream>
using namespace std;

class Base {
public:
    // Se for declarado como: virtual void sayHello() = 0;
    // a classe será abstrata.
    virtual void sayHello() { cout << "Hello From Base" << endl; }
};

class Deriv1 : public Base {
public:
    void sayHello() override { cout << "Hello From Deriv1" << endl; }
};

class Deriv2 : public Base {
public:
    void sayHello() override { cout << "Hello From Deriv2" << endl; }
};

int main()
{
    Base *pBase0 = new Base();
    Base *pBase1 = new Deriv1();
    Base *pBase2 = new Deriv2();

    pBase0->sayHello();
    pBase1->sayHello();
    pBase2->sayHello();
}
