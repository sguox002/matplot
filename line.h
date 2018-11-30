#pragma once
#include "matplot_global.h"
using namespace std;

class Line
{///
 public:
    int id;
    int Errorbar;
    // Matlab oriented variables //
    dvec XData,YData,ZData;
    dvec YPData,YMData;
    //dmat XData,YData,ZData;
    //dmat EData,UData,LData;
    //dmat VData,WData;

    string Color;
    string LineStyle;// {-} | - - | : | -. | none
    float  LineWidth;
    string Marker;// {none}
    float  MarkerSize;
    string MarkerEdgeColor;
    string MarkerFaceColor;

    int Clipping;
    //string EraseMode;
    int SelectionHighlight;
    int Visible;

    // General Information 
    int Parent;
    int Selected;
 public:
    void reset();
    void color(float r,float g,float b);
    explicit Line(int id_);
};