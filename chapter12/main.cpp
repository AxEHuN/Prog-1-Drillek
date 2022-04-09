
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib_facilities.h"
using namespace Graph_lib;
int main()
{
   

    Point tl(150,150);
    Simple_window win(tl,600,400,"My window");

    Axis xx(Axis::x,Point(20,330),300,10,"axis1");
    win.attach(xx);
    
    Axis yy(Axis::y,Point(20,330),280,30,"axis2");
    yy.set_color(Color::blue);
    yy.label.set_color(Color::dark_green);
    win.attach(yy);

    Function cosine(cos,0,100,Point(20,175),100,10,10);
    win.attach(cosine);

    cosine.set_color(Color::yellow);
    Graph_lib::Polygon poly;
    poly.add(Point(100,200));
    poly.add(Point(200,300));
    poly.add(Point(400,500));
    poly.add(Point(600,700));
    poly.add(Point(800,900));

    poly.set_color(Color::dark_blue);
    poly.set_style(Line_style::dot);
    win.attach(poly);

    Graph_lib::Rectangle rect(Point(200,200),110,30);
    win.attach(rect);

    Closed_polyline poly_rec;
    poly_rec.add(Point(50,25));
    poly_rec.add(Point(100,25));
    poly_rec.add(Point(50,50));
    poly_rec.add(Point(100,50));
    win.attach(poly_rec);
    poly_rec.add(Point(25,50));


    Text t(Point(150,150),"palacsinta");
    win.attach(t);

    t.set_font_size(50);

    Image ii(Point(100,50),"image.jpeg");
    win.attach(ii);


    Circle c(Point(100,200),50);
    Graph_lib::Ellipse e(Point(150,250),75,25);
    e.set_color(Color::dark_red);
    Mark m(Point(100,200),'X');

    win.wait_for_button();

}