#include "afxwin.h"
#include "plot1.h"
#include "hptime.h"

extern hptime mytimer;

void plot1::DISPLAY()
{
	ex6();
}

void plot1::ex1()
{
    vector<double> x(100),y(100);    
    for(int i=0;i<100;++i){
		x[i]=0.1*i;
		y[i]=sin(x[i]);
    }
    plot(x,y);
}

void plot1::ex2()
{
    vector<double> x0(100),y0(100);   
	
	mytimer.record_currtime();
    for(int i=0;i<100;++i)
	{
		x0[i]=0.1*i;
		y0[i]=sin(x0[i]);
    }
    subplot(1,2,1);
	//plot(x0,y0);
	plot(y0);
	mytimer.record_currtime();
    // Prepare test data
	subplot(1,2,2);
    int n=100;
    vector<double> x,y,z;
    x=linspace(-2,2,n);
    y=linspace(-2,2,n);
    vector< vector< double > > Z(n,vector<double>(n)),C(n,vector<double>(n));
    for( i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			Z[i][j]=sin(3*x[j])+sin(3*y[i])+0.5;	    
		}
    }
	mytimer.record_currtime();
    // To add contour plot
    //contour(Z);
	
    // To set current color map, use following commands
    //hsv();
    jet();
	mytimer.record_currtime();
    // To generate pseudo color plot:
    pcolor(Z);  //most time consuming part here
	mytimer.record_currtime();
    // To delete edge lines:
    set("EdgeColor","none");
    
    // To add color bar
    colorbar();
	mytimer.record_currtime();
	mytimer.dump("dtime.txt");
}

void plot1::ex3()
{
	
    // Create test data
    int n=100,m=10;
    vector<double> x(n),y(n);
    x=linspace(0,10,n);
    vector<vector<double> > Y(m,vector<double>(n));
    for(int j=0;j<m;++j){
		for(int i=0;i<n;++i){
			x[i]=0.1*i;
			Y[j][i]=sin(x[i])+0.4*j;
		}
    }
    // To set line width
    subplot(2,2,1);
    y=Y[0];plot(x,y);set(2);
    y=Y[1];plot(x,y);set(3);
    y=Y[2];plot(x,y);set(4);
	
    // To color lines
    subplot(2,2,2);
    y=Y[0];plot(x,y);set("r");//red
    y=Y[1];plot(x,y);set("g");//green
    y=Y[2];plot(x,y);set("b");//blue
    y=Y[3];plot(x,y);set("y");//yellow
    y=Y[4];plot(x,y);set("c");//cyan
    y=Y[5];plot(x,y);set("p");//purple
    
    // To set line style
    subplot(2,2,3);
    y=Y[0];plot(x,y);set("-");//solid line
    y=Y[1];plot(x,y);set(":");//dotted line
    y=Y[2];plot(x,y);set("- -");//dashed lne
    y=Y[3];plot(x,y);set("-.");//dash and dots
    y=Y[4];plot(x,y);set(":");  set(2);
    y=Y[5];plot(x,y);set("- -");set(2);
    y=Y[6];plot(x,y);set("-."); set(2);
    
    // To plot with markers
    subplot(2,2,4);
    y=Y[0];plot(x,y);set(".");
    y=Y[1];plot(x,y);set("+");
    y=Y[2];plot(x,y);set("x");
    y=Y[3];plot(x,y);set("d");
    y=Y[4];plot(x,y);set("^"); 
    y=Y[5];plot(x,y);set("v");
    y=Y[6];plot(x,y);set("o"); 
    y=Y[7];plot(x,y);set("*"); 
    y=Y[8];plot(x,y);set("s"); 
    
}

void plot1::ex4()
{
	
    // create test data 
    int n=100;
    float d=0.4;
    vector<double> x(n),y1(n),y2(n),y3(n),y4(n);    
    for(int i=0;i<n;++i){
		x[i]=0.1*i;
		y1[i]=sin(x[i])+d*0;
		y2[i]=sin(x[i])+d*1;
		y3[i]=sin(x[i])+d*2;
		y4[i]=sin(x[i])+d*3;
    }
    
    subplot(2,3,1);    
    plot(x,y1);
	
    // To add a title, labels 
    title("Auto");
    xlabel("x label ");
    ylabel("y label ");
	
    // To change plot range
    subplot(2,3,2);
    axis(-5,15,-2,0.5);
    plot(x,y1);
	
    // To add grids
    subplot(2,3,3);
    plot(x,y1);
    grid(1);
    //or grid("off");
	
    // To delete axes
    subplot(2,3,4);
    plot(x,y1);
    axis(0);
	
    // To delete ticklabel
    subplot(2,3,5);
    plot(x,y1);
    ticklabel(0);
	
    // To put tick outside
    subplot(2,3,6);set("TickDir","out");
    plot(x,y1);
    
}

void plot1::ex5()
{
    // Prepare test data
    int n=100;
    vector<double> x,y,z;
    x=linspace(-2,2,n);
    y=linspace(-2,2,n);
    vector< vector< double > > Z(n,vector<double>(n)),C(n,vector<double>(n));
    for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			Z[i][j]=sin(3*x[j])+sin(3*y[i])+0.5;	    
		}
    }
    // To add contour plot
    //contour(Z);
	
    // To set current color map, use following commands
    //hsv();
    jet();
	
    // To generate pseudo color plot:
    pcolor(Z);
	
    // To delete edge lines:
    set("EdgeColor","none");
    
    // To add color bar
    colorbar();
}

void plot1::ex6()
{
	
    // Prepare test data
    int n=50;
    vector<double> x,y,z;
    x=linspace(-2,2,n);
    y=linspace(-2,2,n);
    vector< vector< double > > Z(n,vector<double>(n)),C(n,vector<double>(n));
    for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			Z[i][j]=sin(3*x[j])+sin(3*y[i])+0.5;	    
		}
    }
	
    // To set current color map, use following commands
    //hsv();
    jet();
    
    // To generate 3D surface plot
    surface(x,y,Z);
    
    // Another test data
    n=300;
    x.resize(n);
    y.resize(n);
    z.resize(n);    
    double t;
    for( i=0;i<n;++i)
	{
		t=0.1*i;
		x[i]=sin(t);
		y[i]=cos(t);
		z[i]=0.1*t;
    }
	
    // To plot 3D line
    plot3(x,y,z);
    
    // To color this line
    set("r");set(3);
	
    // To add colorbar
    colorbar();
	
}