/*
	g++ drill16.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ./Drill_window.cpp -o drill16.out `fltk-config --ldflags --use-images` -std=c++11 && ./drill16.out
*/

#include "./Drill_window.h"
#include "../../gui/Graph.h"


int main()
{
	using namespace Graph_lib;

	Drill_window win{Point{100,100}, 1280, 720, "Drill 16"};

	return gui_main();
}