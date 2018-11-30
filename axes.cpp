#include "StdAfx.h"
#include "axes.h"

Axes::Axes(int id_)
{
	id=id_;
	Selected=0;
	Position[0]=0.13;
	Position[1]=0.11;
	Position[2]=0.775;
	Position[3]=0.815;
    
	Viewport3d[0]=0.0;
	Viewport3d[1]=0.0;
	Viewport3d[2]=1.0;
	Viewport3d[3]=1.0;
	
	Mouse=1;
	View=0;
	Visible=1;
	Box=1;
	Children.clear();
	
	cta0=30; 
	phi0=30;
	cta=cta0; 
	phi=cta0;
	
	CameraPosition[0]=1; CameraPosition[1]=1; CameraPosition[2]=1;
	CameraTarget[0]=0.;  CameraTarget[1]=0; CameraTarget[2]=0;
	CameraUpVector[0]=0; CameraUpVector[1]=0; CameraUpVector[2]=1;
	
	LineWidth=1;
	
	GridLineStyle=":";
	XGrid=0;
	YGrid=0;
	ZGrid=0;
	
	XLim[0]=0;    XLim[1]=10;
	YLim[0]=0;    YLim[1]=10;
	ZLim[0]=0;    ZLim[1]=10;
	
	XLimMode=0; YLimMode=0; ZLimMode=0;
	XAxisLocation="bottom";//top | bottom
	YAxisLocation="left";// left | right
	XScale=0;// {0:linear} | 1:log
	YScale=0;
	ZScale=0;
    
	TickLabel=1;
	TickDir="in";
	
	xmin= 1e99;    xmax=-1e99;
	ymin= 1e99;    ymax=-1e99;
	zmin= 1e99;    zmax=-1e99;
	XMouse=YMouse=0.0;
	CLim[0]=0;CLim[1]=0;

	num_child=0;
	//MakeTick();
	//Parent=i_figure;
 }

void Axes::reset()
{
    num_child=0;
    xmin=1e99; xmax=-1e99;
    ymin=1e99; ymax=-1e99;
    zmin=1e99; zmax=-1e99;	
}

void Axes::config()
{
    float extent=0,extent_linear=0.03;
    if((XLimMode==0)&&(xmax>xmin))  //auto
	{
		if(XScale==0) //linear
		{
			extent=extent_linear;
		}
		if(XScale==1) //log
		{
			extent=0;
		}
		XLim[0]=xmin-extent*(xmax-xmin); 
		XLim[1]=xmax+extent*(xmax-xmin);
    }
    if((YLimMode==0)&&(ymax>ymin))
	{
		if(YScale==0){extent=extent_linear;}
		if(YScale==1){extent=0;}
		YLim[0]=ymin-extent*(ymax-ymin); 
		YLim[1]=ymax+extent*(ymax-ymin);
    }
    if((ZLimMode==0)&&(zmax>zmin))
	{
		ZLim[0]=zmin-extent*(zmax-zmin); 
		ZLim[1]=zmax+extent*(zmax-zmin);
    }	
    //printf("Z: %d,%f,%f\n",ZLimMode,ZLim[0],ZLim[1]);
    //if(num_child){Visible=1;}else{Visible=0;}
    
    XTick=make_tick(XLim[0],XLim[1]);
    YTick=make_tick(YLim[0],YLim[1]);
    ZTick=make_tick(ZLim[0],ZLim[1]);
}

int Axes::ID()
{
	return id;
}

int Axes::selected()
{
	return Selected;
}

void Axes::selected(int i)
{
	Selected=i;
}

void Axes::add_child(int i)
{
	Children.push_back(i);
}

dvec Axes::make_tick(double min,double max)
{
	int i,j;
	double dg;
	double x,y;
	int z;
	x=fabs(max-min);
	z=(int)log10(x);
	y=x/pow((double)10,(double)z);
	dg=1*pow((double)10,(double)z);
	if(y<5){dg=0.5*pow((double)10,(double)z);}
	if(y<2){dg=0.2*pow((double)10,(double)z);}
	
	double min0;
	min0=min-fmod(min,dg);j=0;
	
	dvec tick;
	tick.clear();
	if(max>min){ i=-2; while(max>=min0+dg*i){ if(min<=min0+dg*i){ tick.push_back(min0+dg*i); j++; } i+=1;} }
	if(max<min){ i=-2; while(max<=min0-dg*i){ if(min>=min0-dg*i){ tick.push_back(min0-dg*i); j++; } i+=1;} }
	return tick;
}