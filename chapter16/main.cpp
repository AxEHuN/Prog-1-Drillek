// g++ main.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Lines_window.h"
#include "GUI/Graph.h"
#include <iostream>

int main()
{

	using namespace Graph_lib;
	try{
	Lines_window win{Point{100,100}, 1280,720,"Vector_ref"};
	

	return gui_main();
 }
 catch(exception& e){
 	cerr << "Error: " << e.what() << endl;
 	return 1;
 }
 catch(...){
 	cerr << "Unkown exception" << endl;
 	return 2;
 }
}
