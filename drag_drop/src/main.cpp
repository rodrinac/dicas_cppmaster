#include <fstream>
#include <iostream>
#ifdef WIN32
#   include <windows.h>
#   define ERRO(titulo, msg) MessageBoxA(NULL, msg, titulo, MB_ICONERROR)
#   define PRINT_F(titulo, dados) MessageBoxA(NULL, dados.c_str(), titulo.c_str(), MB_ICONINFORMATION)
#   define WAIT()
# else
#   define ERRO(titulo, msg) cout << msg << endl
#   define PRINT_F(titulo, dados) cout << "\n\t" << titulo.c_str() << ":\n\n" << dados.c_str() << endl;
#   define WAIT() cin.get()
#endif

using namespace std;

int main(int argc, char *argv[])
{
    // se não há argumentos, encerra o app
    if(argc < 2) {
        ERRO("Erro", "Precisa de Argumentos!");

        return -1;
    }

    // percorre pelos arguemntos passados
    // OBS.: o argv[0] tem o destino para o próprio app
    for(int i = 1; i < argc; i++) {
        ifstream file(argv[i]);

        if(file.is_open()) {
            string title = argv[i], data;

            getline(file, data, static_cast<char>(EOF));

            PRINT_F(title, data);
        }
    }

    WAIT();
    return 0;
}
