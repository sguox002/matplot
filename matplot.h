#pragma once
#include "../outlinefont.h"
#include "axes.h"
#include "figure.h"
#include "layer.h"
#include "line.h"
#include "patch.h"
#include "surface.h"
#include "text.h"


class MatPlot
{///
 private:
	COutlineFont *pFont;
    int is_debug1;
    int is_debug2;
    
	bool use_bitmapfont;
    vector<vector<float> > cmap;//TODO move to class Figure
    
    int mode;//0:initialization 1:configuration
    int init_level;// initialization level of objects
    int hObj;// handle number of current object

    int time_layer_clicked,time_layer_clicked_last;

    // Events //
    int window_w,window_h;
    float xButtonDown,yButtonDown;// last clicked mouse position
    float ctaButtonDown,phiButtonDown;
    int xPassive,yPassive;

    // pointer to current objects //
    Figure *cf;
    Layer *cfr;
    Axes *ca;
    Line *cl;
    Surface *cs;
    Patch *cp;
    Text *ct;    

    // objects containers //
    vector< Figure > vFigure;
    vector< Layer > vLayer;
    vector< Axes > vAxes; 
    vector< Line > vLine;
    vector< Surface > vSurface;
    vector< Patch > vPatch;
    vector< Text > vText;

    // objects counter //
    int iFigure;
    int iLayer;
    int iAxes;
    int iLine;
    int iSurface;
    int iPatch;
    int iText;

    // Selected object //
    int iAxesSelected;

 private:
    // coordinate transform  //
    // figure coordination
    float ctx2(double x);
    float cty2(double y);
    // axes coordination
    float ctx(double x);
    float cty(double y);
    float ct3x(double x);
    float ct3y(double y);
    float ct3z(double z);
    
    int figure();

    // display //
    void display_figure();    
    void display_layer();
    void display_layer2();
    
    void display_axes();
    void display_axes_2d();
    void display_axes_3d();
    void display_axes_colorbar();
    
    void display_line();
    
    void display_surface();
    void display_surface_2d();
    void display_surface_3d();
    void display_pcolor();
    void display_contour();

    void display_patch();
    void display_patch_2d();
    void display_patch_3d();


    void display_bar();

    void display_text();

    // mouse //
    void Layer_mouse(int button, int state, int x, int y );
    void Axes_mouse(int button, int state, int x, int y );
    void Axes_motion(int x, int y );


    void surface_config();
    void line_config();
    void patch_config();
    tcvec Index2TrueColor(dvec IC);

 public:
    //add by sguo
	void set_ptext(COutlineFont *p) {pFont=p;}
	void setup_figure();
	void update_figure();
	void show_figure();
	


    MatPlot();
    virtual ~MatPlot();

    void virtual DISPLAY(){};
	virtual void update_data() {};

    void inline debug1(){is_debug1=1;}
    void inline debug2(){is_debug2=1;}

    // GLUT Callback Functions ///
    void display();
    void reshape(int w, int h);
    void mouse(int button, int state, int x, int y );
    void motion(int x, int y );
    void passivemotion(int x,int y);
    void keyboard(unsigned char key, int x, int y);
    
    // Layer ///
    int layer();
    //int layer(string s);    
    int layer(string s,int Visible);
    int frame(string s,int Visible);// do not use

    // Axes ///
    
    int axes();
    int gca();
    int subplot(int m,int n,int p);
    
    int colorbar();

    void axis(double xMin,double xMax,double yMin,double yMax);
    void axis(double xMin,double xMax,double yMin,double yMax,double zMin,double zMax);

    void axis(string s);
    void axis(int s);
    
    void grid(string s);
    void grid(int s);

    void ticklabel(string s);
    void ticklabel(int s);

    void title(string s);
    void xlabel(string s);
    void ylabel(string s);
    void zlabel(string s);

    //void xlim(double min,double max);
    //void xlim(string s);

    //void legend(string s,int N);

    //int plotyy

    void mouse_capture(double *xmouse,double *ymouse);   
    
    // set, General Object Handling ///
    void set(string v);
    void set(float v);  
    void set(string p,float v);
    void set(string p,string v);
    void set(int h,string p,string v);
    void set(int h,string p,float v);      
    int gco();
    
    // Line ///
    
    int begin();//do not use
    void end();//do not use
    void vertex(double x,double y);
    void vertex(double x,double y,double z);

    int line();
    int line(const dvec& x,const dvec& y);
    int line(const dvec& x,const dvec& y,const dvec& z);
    //line(X,Y)
    //line(X,Y,Z)

    int plot(const dvec& y);
    int plot(const dvec& x,const dvec& y);    
    //int plot(dmat Y);
    //int plot(dvec x,dmat Y);
    //int plot(dmat X,dmat Y);
    int plot(const valarray<double>& x,const valarray<double>& y);
    
    int plot3(const dvec& x,const dvec& y,const dvec& z);
    //int plot3(dvec X,dvec Y,dvec Z);

    int semilogx(const dvec& x,const dvec& y);
    int semilogy(const dvec& x,const dvec& y);
    //int loglog(dvec y);
    int loglog(const dvec& x,const dvec& y);    
    
    //int polar(dvec theta,dvec rho);

    void vertex(double x,double y,double ep,double em);
    int errorbar(const dvec& x,const dvec& y,const dvec& e);
    int errorbar(const dvec& x,const dvec& y,const dvec& ep,const dvec& em);

    //int quiver(U,V);
    //int quiver(X,Y,U,V);
    
    //int scatter(X,Y,S,C)
    //int scatter(X,Y,S)
    //int scatter(X,Y)

    // Surface, Contour ///
    dmat peaks(int n);
    //dmat peaks(int m,int n);
    //dmat peaks(int m,int n,string type);

    int surface();
    int surface(const dmat& Z);
    int surface(const dmat& Z,const dmat& C);
    int surface(const dmat& Z,const tcmat& C); //!!   
    int surface(const dvec& x,const dvec& y,const dmat& Z);
    int surface(const dvec& x,const dvec& y,const dmat& Z,const dmat& C);
    int surface(const dvec& x,const dvec& y,const dmat& Z,const tcmat& C);//!!
    int surface(const dmat& X,const dmat& Y,const dmat& Z);
    int surface(const dmat& X,const dmat& Y,const dmat& Z,const dmat& C);
    int surface(const dmat& X,const dmat& Y,const dmat& Z,const tcmat& C);//!!
    
    int pcolor(const dmat& C);
    int pcolor(const tcmat& C);
    int pcolor(const dvec& x,const dvec& y,const dmat& C);
    int pcolor(const dvec& x,const dvec& y,const tcmat& C);
    int pcolor(const dmat& X,const dmat& Y,const dmat& C);
    int pcolor(const dmat& X,const dmat& Y,const tcmat& C);

    int contour(const dmat& Z);
    int contour(const dmat& Z,int n);
    int contour(const dmat& Z,const dvec& v);
    int contour(const dvec& x, const dvec& y, const dmat& Z);
    int contour(const dvec& x, const dvec& y, const dmat& Z,int n);
    int contour(const dvec& x, const dvec& y, const dmat& Z,const dvec& v);
    //int contour(dmat X, dmat Y, dmat Z);
    //int contour(dmat X, dmat Y, dmat Z,int n);
    //int contour(dmat X, dmat Y, dmat Z,dvec v);

    //int mesh(dmat Z);
    //int mesh(dmat Z,dmat C);
    //int mesh(dmat Z,tcmat C);    
    int mesh(const dvec& x, const dvec& y, const dmat& Z);
    //int mesh(dvec x, dvec y, dmat Z,dmat C);
    //int mesh(dvec x, dvec y, dmat Z,tcmat C);    
    //int mesh(dmat X,dmat Y,dmat Z);
    //int mesh(dmat X,dmat Y,dmat Z,dmat C);
    //int mesh(dmat X,dmat Y,dmat Z,tcmat C);
    // meshc()
    // meshz()

    int surf(const dvec& x, const dvec& y, const dmat& Z);

    // Patch ///

    int patch();
    int patch(const dmat& X,const dmat& Y);
    int patch(const dmat& X,const dmat& Y,const dvec& C);
    int patch(const dmat& X,const dmat& Y,const tcvec& C);    
    int patch(const dmat& X,const dmat& Y,const dmat& Z);//!!
    int patch(const dmat& X,const dmat& Y,const dmat& Z,const dvec& C);//!!    
    int patch(const dmat& X,const dmat& Y,const dmat& Z,const tcvec& C);//!!
    //int patch(dmat X,dmat Y,tcmat C);
    //int patch(dmat X,dmat Y,dmat Z,tcmat C);

    int bar(const dvec& y);
    int bar(const dvec& y,float width);
    int bar(const dvec& x,const dvec& y);
    int bar(const dvec& x,const dvec& y,float width);

    //int bar(Y)
    //int bar(Y,float width);
    //int bar(Y,string style);
    //int bar(Y,float width,string style);

    //int bar(x,Y)
    //int bar(x,Y,float width);
    //int bar(x,Y,string style);
    //int bar(x,Y,float width,string style);
      
    //int hist(y);
    //int hist(y,x);
    //int hist(y,nbins);

    //int pie(dvec x);
    //int pie(dvec x, vector<int> Explode);

    // Text ///
    //TODO: more fonts    
    int text();
    int text(double x,double y,string s);
    void set_font(char font_[],int size);
    void ptext(float x,float y,string s);
    void ptext3(float x,float y,float z,string s);
    void ptext3c(float x,float y,float z,string s);

    // Colors ///
    void color(float r,float g,float b);
    vector<float> colormap(string c,float t);
    void colormap(string c);
    void colormap(vector<vector<float> > c);

    void gray();
    void jet();
    void hsv();
    void hot();
    void cool();
    void spring();
    void summer();
    void autumn();
    void winter();

    const vector<float>& map2color(double x,double xmin,double xmax);
    
    void Shading(string c);
    void shading(string c);
    vector<float> ColorSpec2RGB(string c);
    string rgb2colorspec(vector<float> rgb);
	Axes& get_axes(int h);
    // print ///
    void print();

};

