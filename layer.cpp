#include "StdAfx.h"
#include "layer.h"

Layer::Layer(int id_)
{ 
    id=id_;	
	Visible=1;
    Children.clear();	
}
/// Patch

void Layer::add_child(int i)
{
	Children.push_back(i);
}