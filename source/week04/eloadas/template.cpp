/*
	g++ template.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o template.out `fltk-config --ldflags --use-images` -std=c++11 && ./template.out
*/

#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

double one(double x){ return 1; }

double slope(double x){ return x/2; }

double square(double x){ return x*x; }
int main()
{
	int max_width = 600;
	int max_height = 400;

	int x_orig = max_width / 2;
	int y_orig = max_height / 2;

	int rmin = -11; //range
	int rmax = 11;

	int n_points = 400;

	
	Simple_window win {Point{100,100}, max_width, max_height, "Template File"};

	Point origo {x_orig, y_orig};

	int xlength = max_width - 40;
	int ylength = max_height - 40;

	int xscale = 30, yscale = 30;

	Function s(one, rmin, rmax, origo, n_points, xscale, yscale);

	Function sl(slope, rmin, rmax, origo, n_points, xscale, yscale);

	Function sq(square, rmin, rmax, origo, n_points, xscale, yscale);

	Function sl_cos([] (double x) { return cos(x) + slope(x); }, rmin, rmax, origo, n_points, xscale, yscale);


	/*

	Marks

	*/

	Marks mpl("prog1");
	//Marks mpl("prog1");
	//Marked_polyline mpl("prog1");
	mpl.add(Point{100,100});
	mpl.add(Point{200,150});
	mpl.add(Point{300,100});
	mpl.add(Point{100,200});
	mpl.add(Point{300,500});


	Mark m(Point{300,300}, 'x');

	win.attach(s);
	win.attach(sl);
	win.attach(sq);
	win.attach(sl_cos);
	win.attach(mpl);
	win.attach(m);

	win.wait_for_button();
}


