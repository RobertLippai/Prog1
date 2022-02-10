/*
    g++ task3.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o task3 `fltk-config --ldflags --use-images` -std=c++11 && ./task3
*/
#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

double one(double){
	return 1;
}

double square(double x){
	return x*x;
}

int main()
{
    using namespace Graph_lib;


    int xmax = 1280;
    int ymax = 720;

    int x_origo = xmax/2;
    int y_origo = ymax/2;

    int rmin = -11;
    int rmax = 11;

    int n_points = 400;

    //the windows's left side will be on tl's cordinate
    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    Point origo {x_origo, y_origo};

    int xlength = xmax-40;
    int ylength = ymax-40;

    int xscale = 30, yscale = 30;

    Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
    Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
    Function cos_func ([] (double x) {return cos(x); }
    					, rmin, rmax, origo, n_points, xscale, yscale);

    Axis x {Axis::x, Point{20, y_origo}, xlength, xlength/xscale, "x"};
    Axis y {Axis::y, Point{x_origo, ylength + 20}, ylength, ylength/yscale, "y"};

    Rectangle r {Point{200,200}, 100, 50};
    r.set_fill_color(Color::yellow);
    r.set_style(Line_style(Line_style::dash, 4));

    Text t {Point{200,400}, "Hello graphics!"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);

    Image ii {Point{100,100}, "badge.jpg"};

      Circle c {Point{400,400}, 50};

    win.attach(ii);
    win.attach(c);
    win.attach(t);
    win.attach(r);
    win.attach(s);
    win.attach(sq);
    win.attach(cos_func);
    win.attach(x);
    win.attach(y);

    win.wait_for_button();
}
