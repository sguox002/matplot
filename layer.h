#pragma once
using namespace std;

//template class __declspec(dllimport) std::vector<int>;

class Layer
{///
 public:
    int id;
    int Visible;
    string layername;
    vector<int> Children;
 public:
    explicit Layer(int id_);
    void add_child(int i);
};