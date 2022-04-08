#include "GUI/GUI.h"

using namespace Graph_lib ;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);

	bool wait_for_button();
private:
	Open_polyline lines;
	//widgetek
	Button next_button;
	Button quit_button;
	Button menu_button;
	Button color_button;
	Button style_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	Menu color_menu;
	Menu style_menu;
	

	void change(Color c) { lines.set_color(c); }
	void changestyle(Line_style s) {lines.set_style(s);}


	void hide_color() { color_menu.hide(); color_menu.show(); }
	void hide_style() {style_menu.hide(); style_menu.show();}

	void color_pressed() { color_button.hide(); color_button.show(); }
	void style_pressed() { style_button.hide(); style_button.show();}

	void red_pressed(){change(Color::red);hide_color();}
	void blue_pressed(){change(Color::blue);hide_color();}
	void black_pressed(){change(Color::black);hide_color();}

	void dot_pressed(){change(Line_style::dot);hide_style();}
	void dash_pressed(){change(Line_style::dash);hide_style();}
	void solid_pressed(){change(Line_style::solid);hide_style();}

/*
	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);

*/
//	static void cb_menu(Address, Address);
	
	void next();
	void quit();
};