/*
	g++ template.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o template.out `fltk-config --ldflags --use-images` -std=c++11 && ./template.out
*/

#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

int main()
{
	int max_width = 600;
	int max_height = 400;
	
	Simple_window win {Point{100,100}, max_width, max_height, "Template File"};

	win.wait_for_button();
}