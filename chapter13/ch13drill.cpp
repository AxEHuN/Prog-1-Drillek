
/*
g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{

	using namespace Graph_lib;

	int xmax=800;
	int ymax=1000;

	Simple_window win {Point{100,100}, xmax, ymax, "windows"};



	int xs=800;
	int ys=800;
	int xg=100;
	int yg=100;

	Lines grid;

	for (int i=xg; i<xs;i+=xg){
		grid.add(Point{i,0}, Point{i,ys});
	}
	for (int j=yg;j<ys;j+=yg){
		grid.add(Point{0,j}, Point{xs, j});
	}

	win.attach(grid);
	grid.set_color(Color::red);

	//3.

	Vector_ref <Rectangle> mid;
	for (int i=0;i<xs;i+=xg){
		mid.push_back(new Rectangle{Point{i,i}, Point{i+xg, i+xg}});
		mid[mid.size()-1].set_color(Color::invisible);
		mid[mid.size()-1].set_fill_color(Color::yellow);
		win.attach(mid[mid.size()-1]);
	}

	//4.

	Image logo1{Point{0,300}, "logo.jpg"};
	Image logo2{Point{300,600}, "logo.jpg"};
	Image logo3{Point{500,100}, "logo.jpg"};

	win.attach(logo1);
	win.attach(logo2);
	win.attach(logo3);

	//5.

	Image imre{Point{0,0}, "imre.jpeg"};
	win.attach(imre);
	win.wait_for_button();


	// jo megoldas 5.
	int ymove=0;
	int xcord=0;
	int yindex=0;
	int db=0;
	while (db!=56){
			imre.move(100,0);
			win.wait_for_button();
			ymove=0;
			db++;
			xcord+=1;
			if (xcord==7){
				xcord=0;
				ymove+=100;
				imre.move(-700,ymove);
				win.wait_for_button();
			}
	}
}
