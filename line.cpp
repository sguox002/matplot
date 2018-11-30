#include "StdAfx.h"
#include "line.h"

void Line::reset()
{
    XData.clear();
    YData.clear();
    ZData.clear();
    YPData.clear();
    YMData.clear();
}
void Line::color(float r,float g,float b)
{
    //Color[0]=r;
    //Color[1]=g;
    //Color[2]=b;
}

Line::Line(int id_)
{	
	id=id_;

	Color="b";
	LineStyle="-";
	LineWidth=0.5;

	Marker="none";
	MarkerSize=6;
	MarkerEdgeColor="k";
	MarkerFaceColor="w";

	Errorbar=0;
	//PlotStyle=0;
}   