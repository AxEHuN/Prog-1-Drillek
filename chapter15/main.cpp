/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"
 
double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return slope(x)+cos(x);}

int main()
{
	int xmax=600;
	int ymax=600;


	Simple_window win {Point{100,100}, xmax, ymax, "Aging Japan"};


	Axis x {Axis::x, Point{100, 300},400,20, "1==20px"};
	Axis y {Axis::y, Point{300, 500},400,20, "1==20px"};

	x.set_color(Color::blue);
	y.set_color(Color::blue);

	win.attach(x);
	win.attach(y);

	const double rgmin=-10;
	const double rgmax=11;

	const int numbpoints=400;
	const double xscale=20;
	const double yscale=20;

	const Point origo{300,300};

	Function f1{one,rgmin,rgmax,origo,numbpoints,xscale,yscale};
	Function f2{slope,rgmin,rgmax,origo,numbpoints,xscale,yscale};
	Function f3{[](double x){return x*x;},rgmin,rgmax,origo,numbpoints,xscale,yscale};//fügvény közvetlen deklarálás
	Function f4{cos,rgmin,rgmax,origo,numbpoints,xscale,yscale};
	Function f5{sloping_cos,rgmin,rgmax,origo,numbpoints,xscale,yscale};
	
	f5.set_color(Color::white);
	f4.set_color(Color::blue);


	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.wait_for_button();

	return 0;
}
