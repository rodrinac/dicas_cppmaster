#include <iostream>
#include <regex>
using namespace std;

bool validator(const string &number) {
    // valido apenas se tiver:
    //                   / 1 número de 1 a 9
    //                  /     / 3 ou 4  de 0 a 9
    //                 /     /         / um traço
    //                /     /         //  4 números de 0 a 9
    static regex reg("[1-9][0-9]{3,4}-[0-9]{4}");

    return regex_match(number, reg);
}

int main()
{
    setlocale(LC_ALL, "");
    string number;

    do {
#ifdef WIN32
        system("cls");
#else
        if(! number.empty())
            cout << "Telefone incorreto!" << endl << endl;
#endif	
        cout << "Digite um no. de telefone: ";
        getline(cin, number);

    } while(! validator(number));

    cout << "\nO número " << number << " é válido!" << endl;

    cin.get();
}
