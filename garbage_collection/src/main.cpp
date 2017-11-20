#include <iostream>
#include <memory> // unique_ptr<T>, shared_ptr<T>
/**
	direfente de unique_ptr<>, shared_ptr<> permine vários
	objetos apontando para a mesma memória alocada.
	A memória só é liberada quando o último objetos
	shared_ptr<> é destruído.
	Saiba mais no livro "The C++ Standard Library",
    disponível neste @link: http://adf.ly/1b0AWv
**/

using namespace std;

//	classe de exemplo
class Foo
{
public:
    Foo()       { cout << "Foo::Foo()\n";  }
    ~Foo()      { cout << "Foo::~Foo()\n"; }
    void bar()  { cout << "Foo::bar()\n";  }
};

// cria um alias, semelhante a usar typedef
using fooPointer = unique_ptr<Foo>;

void showGarbage()
{
	// associa p a um "novo" Foo
    fooPointer p { new Foo() };

	// get() obtem um ponteiro 
    p.get()->bar();
} // a memória antes alocada é liberada aqui

int main(int argc, char **argv)
{
   {
       fooPointer p2 { new Foo() };
	   
       //  operador -> sobrecarregado	   
       p2->bar();
   }

    cout << "\n===================\n";

   showGarbage();

   cin.get();
}
