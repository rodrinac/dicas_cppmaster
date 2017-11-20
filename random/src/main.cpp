#include "util.h"
using namespace std;

int main(int argc, char *argv[])
{
    // interface gerado de randômicos
    // iniciada com um seed [horário atual]
    default_random_engine eng(time(nullptr));

    vector<int>     ints(5);
    vector<char>   chars(5);
    vector<float> floats(5);
    deque<bool>    bools(5);

    // preenche os vetores com valores randômicos
    // operador ()(<engine>) sobrecarregado
    for(auto &i : ints)   i = Util::intDis(eng);
    for(auto &i : chars)  i = Util::charDis(eng);
    for(auto &i : floats) i = Util::floatDis(eng);
    for(auto &i : bools)  i = Util::boolDis(eng);

    cout.setf(ios_base::fixed | ios_base::boolalpha);
    cout.precision(2);

    // printa na tela
    Util::print(ints);
    Util::print(chars, "chars");
    Util::print(floats, "floats");
    Util::print(bools);

    cin.get();
}
