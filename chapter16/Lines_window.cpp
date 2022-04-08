#include "Lines_window.h"



Lines_window::Lines_window(Point xy, int w, int h, const string& title)
: Window {xy, w, h, title},

next_button{Point{x_max()-300,0},150,40, "Next", 
	[](Address, Address pw) {reference_to <Lines_window>(pw).next();}},
quit_button{Point{x_max()-150,0},150,40, "Quit", 
	[](Address, Address pw) {reference_to <Lines_window>(pw).quit();}},

next_x{Point{300,0}, 50,30, "next_x:"},
next_y{Point{450,0}, 50,30, "next_y:"},

xy_out{Point{100,0}, 130,30, "Current x,y:"},

color_menu{Point{x_max()-120,220}, 70,20,Menu::vertical, "Color"},
style_menu{Point{x_max()-120,320}, 70,20,Menu::vertical, "Style"},

menu_button{Point{x_max()-120,130}, 120,30,"color menu",
	[](Address, Address pw) {reference_to <Lines_window>(pw).color_pressed();}},
style_button{Point{x_max()-120,230}, 120,30,"style_menu",
	[](Address, Address pw) {reference_to <Lines_window>(pw).style_pressed();}}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);

	xy_out.put("No point");

	/*
	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	*/
//color
	color_menu.attach(new Button{Point{0,0},0,0,"red",
		[](Address,Address pw){
			reference_to<Lines_window>(pw).red_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",
		[](Address,Address pw){
			reference_to<Lines_window>(pw).blue_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"black",
		[](Address,Address pw){
			reference_to<Lines_window>(pw).black_pressed();}});

//style
	style_menu.attach(new Button{Point{0,0},0,0,"dot",
		[](Address,Address pw){
			reference_to<Lines_window>(pw).dot_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"dash",
		[](Address,Address pw){
			reference_to<Lines_window>(pw).dash_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"solid",
		[](Address,Address pw){
			reference_to<Lines_window>(pw).solid_pressed();}});

//attach
	attach(color_menu);
	attach(style_menu);

	style_menu.hide();
	color_menu.hide();

	attach(menu_button);
	attach(style_button);

	attach(lines);
}

void Lines_window::quit()
{
	hide();

}
void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point{x,y});

	ostringstream ss;
	ss << '(' << x << ',' << y <<')';
	xy_out.put(ss.str());

	redraw();

}

