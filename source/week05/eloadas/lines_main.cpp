/*
	g++ lines_main.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Lines_window.cpp -o lines_main.out `fltk-config --ldflags --use-images` -std=c++11 && ./lines_main.out
*/

#include "../../gui/Lines_window.h"
#include "../../gui/Graph.h"


int main()
{
	using namespace Graph_lib;

	Lines_window win{Point{100,100}, 800, 400, "Vector_ref"};

	return gui_main();
}


