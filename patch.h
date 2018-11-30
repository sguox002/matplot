#pragma once
#include "matplot_global.h"

using namespace std;

class Patch
{///
 public:
    int id;
    int type;
    vector< vector<int> > Faces;
    dmat Vertices;
    dmat FaceVertexCData;
    dmat XData,YData,ZData;

    //dvec ICVec;
    //dmat ICMat;    
    //tcmat CData;
    tcvec CData;

    string EdgeColor,FaceColor;//{ColorSpec}|none|flat|interp 

    string LineStyle; // {-} | - - | : | -. | none
    float  LineWidth;

    explicit Patch(int id_);
};