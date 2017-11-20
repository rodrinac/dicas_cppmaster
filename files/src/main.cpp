#include <iostream> // cout , cin, string
#include <fstream>  // fstream [in & out], ifstream [in], ofstream [out]
#include <iomanip>  // setfill(), setw()
using namespace std;

int main(int argc, char *argv[])
{
    const char *file = "C:\\Users\\Jose\\Desktop\\file.dat";
    ofstream out(file); // abre arquivo para escrita
    ifstream in(file);  // abre arquivo para leitura

    if(out.is_open()) { // checa se o arquivo está aberto

        out << setfill('0'); // seta caractére de preenchimento de campo para setw()

        for(unsigned i = 1; i <= 100; ++i) {
              // envia dados para o arquivo
             //    // cada número ocupara 3 campos ("001 002")
            //    //  se não ocupar, preenche com o caractére '0' [setfill('0')]
            out << setw(3) << i;

                               // put() envia um caractére por vez
            (i % 10 == 0)? out.put('\n') : out.put(' ');
        }

        out.close(); //fecha o arquivo
    }

    if(in.is_open()) {
        cout << "Lido do arquivo " << file << ":\n\n";

        /*
         *  rdbuf() retorna o buffer associado.
         *  Se é enviado para uma stream, lê todos os
         *  caractéres.
         */
        cout << in.rdbuf();
    }

    return cin.get(); // espera o usuário aperta uma tecla
}
