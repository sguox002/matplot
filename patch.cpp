#include "StdAfx.h"
#include "patch.h"

Patch::Patch(int id_)
{	
	id=id_;
	type=0;
	LineWidth=1;
	FaceColor="r"; 
	EdgeColor="k";
	LineStyle="-";
}