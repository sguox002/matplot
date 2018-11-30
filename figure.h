#pragma once
using namespace std;

//template class __declspec(dllimport) std::vector<int>;

class Figure
{///
 public:
    int id;
    //int Status;// 0:minimized, 1:default position, 2:maximized 
    int Position[4];//left top width height
    int Visible;
 public:
    vector<int> Children;
    void add_child(int i);
    explicit Figure(int id_);
};

