#include "Window.h"
#include "../GUI/Graph.h"
#include "../GUI/GUI.h"

namespace Graph_lib{

	Window::Window(int w, int h, const string& title)
	:FL_Window(ww,hh,title.c_str()), w(ww), h(hh)
	{
		init();

	}
	Window::Window(Point xy,int w, int h, const string& title)
	:FL_Window(xy.x,xy.y,ww,hh,title.c_str()), w(ww), h(hh)
	{
		init();
		
	}
	void Window::init()
	{
		resizeable(this);
		show();

	}
	void Window::draw()
	{
		FL_Window::draw();
		for (unsigned int i=0;i<shapes.size();i++) shapes[i]->draw();
	}
	void Window::attach(Shape& s)
	{
		shapes.push_back(&s);
	}
	void Window::detach(Shape& s)
	{
		for (unsigned int = shapes.size();i>0;i--)
			if(shape[i-1]==&s)
				shapes.erase(shapes.begin()+(i-1));
	}
	void Window::attach(Widget& w)
	{
		begin();
			w.attach(*this);
		end();
	}

	void Window::detach(Widget& w)
	{
		w.hide();
	}
	int gui_main(){return Fl::run();}


} //end namespace