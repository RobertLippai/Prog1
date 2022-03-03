/*
	g++ drill15.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o drill15.out `fltk-config --ldflags --use-images` -std=c++11 && ./drill15.out
*/

#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"


double one(double x){ return 1; }

///Task 4
double slope(double x) { return x/2; }

double square(double x){ return x*x; }

double sloping_cos(double x){ return slope(x) + cos(x); }

int main()
{
	using namespace Graph_lib;

	int max_width = 600;
	int max_height = 600;

	Simple_window win {Point{100,100}, max_width, max_height, "Function graphs"};

	int x_orig = max_width / 2;
	int y_orig = max_height / 2;

	Point origo {x_orig, y_orig};

	int axis_length = 400;
	int notches = 20;


	Axis x_axis (Axis::Orientation::x, Point{100, y_orig}, axis_length, axis_length / notches, "1 == 20 pixels");
	Axis y_axis (Axis::Orientation::y, Point{x_orig, 500}, axis_length, axis_length / notches, "1 == 20 pixels");

	x_axis.set_color(Color::red);
	y_axis.set_color(Color::red);

	//Task 2-3
	int range_min = -10;
	int range_max = 11;

	int number_of_points = 400;


	int xscale = 20, yscale = 20;


	//Task 1
	Function fcn_one(one, range_min, range_max, origo, number_of_points, xscale, yscale);
	
	//Task 5
	Function fcn_slope(slope, range_min, range_max, origo, number_of_points, xscale, yscale);
	
	int position = range_min;

    Text slope_label(Point(abs(origo.x + (xscale * position)), origo.y - ((slope(position) + 1) * yscale)),"x/2");

	win.attach(slope_label);

	//Task 6
	Function fcn_square(square, range_min, range_max, origo, number_of_points, xscale, yscale);
    
	win.attach(fcn_square);

	//Task 7-8
	Function fcn_cos(cos, range_min, range_max, origo, number_of_points, xscale, yscale);

	fcn_cos.set_color(Color::blue);

	win.attach(fcn_cos);

	//Task 9
	Function fcn_slope_and_cos(sloping_cos, range_min, range_max, origo, number_of_points, xscale, yscale);


	win.attach(fcn_slope_and_cos);
	win.attach(x_axis);
	win.attach(y_axis);
	win.attach(fcn_one);
	win.attach(fcn_slope);

	win.wait_for_button();
}