#include "StdAfx.h"
#include "surface.h"

Surface::Surface(int id_)
{
	id=id_;

	ColorMap="Gray";
	//Shading="faceted";
	FaceColor="flat"; 
	EdgeColor="b";
	LineStyle="-";
	LineWidth=0.5;
	NContour=10;
	V.clear();
	
}

void Surface::get()
{
	cout <<"FaceColor: "<< FaceColor <<endl;
	cout <<"EdgeColor: "<< EdgeColor <<endl;
	cout <<"LineStyle: "<< LineStyle <<endl;
	cout <<"LineWidth: "<< LineWidth <<endl;
}