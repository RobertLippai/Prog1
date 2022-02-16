/*
    g++ drill12.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o drill12.out `fltk-config --ldflags --use-images` -std=c++11 && ./drill12.out
*/
#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x*-1; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Drill 12"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function sin_func ( [] (double x) { return sin(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	y.set_color(Color::cyan);
	y.label.set_color(Color::dark_red);

	Polygon poly;

	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::green); 
	poly.set_style(Line_style::dash); 
	poly.set_fill_color(Color::yellow);
	
	Rectangle r {Point{200,200}, 200, 100};

	r.set_fill_color(Color::red);
	r.set_style(Line_style(Line_style::dash, 5));

	Text t {Point{200,400}, "Drill 12!"};
	t.set_font(Font::times_bold);
	t.set_font_size(35);

	Image ii {Point{100,100}, "badge.jpg"};

	Circle c {Point{700,700}, 150};

	Ellipse e {Point{500,500}, 100, 50};
	e.set_fill_color(Color::blue);

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(sin_func);
	win.attach(x);
	win.attach(y);
	win.attach(poly);

    win.wait_for_button();

}
