#include "StdAfx.h"
#include "figure.h"

void Figure::add_child(int i)
{
	Children.push_back(i);
}

Figure::Figure(int id_)
{
	id=id_;
	//Status=1;
	//Position[0]=100;
	//Position[1]=100;
	//Position[2]=800;
	//Position[3]=800;
	Visible=1;
};