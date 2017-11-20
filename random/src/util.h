#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <deque>
#include <ctime>
#include <random>
#include <vector>

namespace Util {
    using namespace std;

    template<class ValueType>
    void print(const vector<ValueType> &v, string what = "inteiros")
    {
        cout << "Mostrando " << what <<endl;

        for(const ValueType &i : v)
            cout << '[' << i << "] ";

        cout.put('\n').put('\n');
    }

    void print(const deque<bool> &d) { print(vector<bool>(d.begin(), d.end()), "bools"); }

    //! Distribuições formatam o valor obtido de uma engine
    // para inteiros <int_type = int>(min, max)
    uniform_int_distribution<> intDis(1000, 9999);
    uniform_int_distribution<char> charDis('A', 'Z');
    // para reais <float_type = double>(min, max)
    uniform_real_distribution<float> floatDis(1000.0f, 9999.0f);
    // para booleanos ([proporção de vir true])
    bernoulli_distribution boolDis(0.4);
}

#endif // UTIL_H
