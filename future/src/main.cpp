#include <iostream> // string, cout, endl, abort 
#include <fstream>  // ifstream
#include <future>   // async, future<>
#include <sstream>  // ostringstream
#ifdef WIN32
#   include <windows.h> // Win32 GUI e etc.
#endif

using namespace std;

void showOutput(const string &title, const string &text, int ico = 0)
{
#ifdef WIN32
    MessageBoxA(nullptr, text.c_str(), title.c_str(), ico);
    if (ico == MB_ICONERROR)
#   else
    cout << title << ":\n" << text <<endl;
    if (ico == 0)
#endif
    exit(-1);
}

string getFile1(string fileName)
{
    ifstream file(fileName);
    ostringstream os;

    if(! file.is_open())
        throw runtime_error("Erro ao abrir " + fileName);

    os << file.rdbuf();

    return os.str();
}

string getFile2(string fileName)
{
    ifstream file(fileName);
    ostringstream os;

    if(! file.is_open())
        throw runtime_error("Erro ao abrir " + fileName);

    os << file.rdbuf();

    return os.str();
}

int main(int argc, char *argv[])
{
    // future deve ser especialido para o tipo de retorno
    // do objeto chamável(lambda, função, functor, método);
    future<string> f1 = async(launch::async, getFile1, "C:\\file1.txt");
    future<string> f2 = async(launch::async, getFile2, "C:\\file2.txt");

    try {
        // get() retorna o resultado, se não estiver pronto,
        string a = f1.get(); // o thread atual tem que esperar
        string b = f2.get(); // se future<void>, vc pode usar future<>::wait()

        showOutput("Recebido de f1", a, 1);
        showOutput("Recebido de f2", b, 1);
    } // exceptios também podem ser transmitidas por future<>::get()
    catch(exception &e) {
        showOutput("Ocorreu um erro", e.what(), 0);
    }
}
