#pragma once
#include "matplot_global.h"

using namespace std;

class Surface
{///
 public:
    int type;
    int id;
    string ColorMap;

    //dvec XData,YData;
    dmat XData,YData,ZData,CDataIndex;
    dvec V,UserData;
    tcmat CData;
    
    string FaceColor;//ColorSpec    | none | {flat} 
    string EdgeColor;//ColorSpec{k} | none | flat
    
    string LineStyle;// {-} | - - | : | -. | none
    float  LineWidth;
    string Marker;// {none}
    float  MarkerSize;
    string MarkerEdgeColor;
    string MarkerFaceColor;

    int Parent;

    int NContour;
 public:
    explicit Surface(int id_);
    void get();
};