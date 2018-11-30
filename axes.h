#pragma once
#include "matplot_global.h"
using namespace std;


class Axes
{///
 private:
    
 protected:
    
 public:
    int id;

    float cta,phi;  // controled by mouse
    float cta0,phi0;// default value or specified by command line
    // Mouse 
    double XMouse,YMouse;
    int Mouse;

    double xmin,xmax,ymin,ymax,zmin,zmax;
    int num_child;

    
    int View;// 0:2D, 1:3D

    vector<vector<float> > ColorMap;// for colorbar

    // Matlab variables //
    // styles
    int Box;//0:Off, 1:On
    string GridLineStyle;
    float LineWidth;
    string TickDir;// {in} | out
    //string TickDirMode;
    //TickLength
    int Visible;//0:Off, 1:On
    int XGrid,YGrid,ZGrid;// {0:Off}, 1:On

    // General Information 
    int Parent;
    vector<int> Children;
    int Selected;
    float Position[4];//left bottom width height
    float Viewport3d[4];//left bottom width height

    //Scale
    string XAxisLocation;
    string YAxisLocation;

    //string XDir,YDir,ZDir;

    double XLim[2],YLim[2],ZLim[2];//plot range
    int XLimMode,YLimMode,ZLimMode;//0:Auto 1:Manual

    int XScale,YScale,ZScale;// linear | log

    dvec XTick,YTick,ZTick;
    string XTickMode,YTickMode,ZTickMode;
    int TickLabel;// 0:Off, {1:On}
    //View
    float CameraPosition[3];
    float CameraTarget[3];
    float CameraUpVector[3];

    // Label
    string Title;
    string XLabel,YLabel,ZLabel;

    double CLim[2];
 public:
    void reset();
    void config();
    int ID();
    int selected();
    void selected(int i);
    void add_child(int i);    
    dvec make_tick(double min,double max);

    explicit Axes(int id_);
};