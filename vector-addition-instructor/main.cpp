#include "stdafx.h"

using namespace std;

template <typename T>
void DisplayVector(const string& name, const vector<T>& vec)
{
    cout << "Vector " << name << " = {";
    for (size_t i{}; i < vec.size() - 1; i++)
        cout << vec.at(i) << ", ";
    cout << vec.back() << "}" << endl << endl;
}

template <typename T>
vector<T> AddVectors(const vector<T>& vec1, const vector<T>& vec2)
{
    vector<T> vec3(vec1.size());
    for (size_t i{}; i < vec1.size(); i++)
        vec3.at(i) = vec1.at(i) + vec2.at(i);
    return vec3;
}

int main()
{
    vector<int> a{ -2, 3, 6, 113, 49, 0, 123 };
    vector<int> b{ 18, 13, 990, 2, -55, -9, 14 };

    DisplayVector("a", a);
    DisplayVector("b", b);
    DisplayVector("c", AddVectors(a, b));

    return 0;
}

