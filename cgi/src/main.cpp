#include <iostream>
#include <algorithm>
using namespace std;

/*
 *	Ajuda a converter o número hexadecimal devolta em caractere
 */
inline char decodeHex(char hex)
{
    if(hex >= 'A')
        return (hex & 0xdf) - 'A' + 0xA;
    else
        return hex - '0';
}

int main(int argc, char *argv[])
{
    //	Recebe os dados do formulário
    string data = getenv("QUERY_STRING");

	//	Necessário para o navegador saber que tipo de arquivo será mostrado no browser
    cout << "Content-Type: text/html\n\n" <<endl;
    cout << "<h1>Dados recebidos</h1>" <<endl;

    cout << "<p>";

    replace(data.begin(), data.end(), '+', ' ');

    for(unsigned i = 0; i < data.size(); i++)
    {
        if(data[i] == '%') //	Converte os números hexadecimais em caractere
            cout.put(decodeHex(data[++i]) * 16 + decodeHex(data[++i]));
        else if(data[i] == '&')
            cout <<"<br>";
        else if(data[i] == '=')
            cout <<" = ";
        else
            cout.put(data[i]);
    }
    cout << "</p>";


    return 0;
}
