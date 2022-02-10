/*
	g++ task1.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o task1 `fltk-config --ldflags --use-images` -std=c++11 && ./task1
*/
#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

int main()
{
    using namespace Graph_lib;


    int xmax = 1280;
    int ymax = 720;

    int x_origo = xmax/2;
    int y_origo = ymax/2;

    //the windows's left side will be on tl's cordinate
    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    Point origo {x_origo, y_origo};

    int xlength = xmax-40;
    int ylength = ymax-40;

    int xscale = 30, yscale = 30;

    Axis x {Axis::x, Point{20, y_origo}, xlength, xlength/xscale, "x"};
    Axis y {Axis::y, Point{x_origo, ylength + 20}, ylength, ylength/yscale, "y"};


    win.attach(x);
    win.attach(y);

    win.wait_for_button();
}
