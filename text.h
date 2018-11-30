#pragma once
using namespace std;

class Text
{///  
 public:
    int id;
    string String;
    float Position[3];
    int Parent;
    int type;//0:axis 1:figure
    explicit Text(int id_);
};
