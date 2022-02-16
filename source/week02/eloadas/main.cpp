/*
	g++ main.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o main.out `fltk-config --ldflags --use-images` -std=c++11 && ./main.out
*/

#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

int main()
{
	int max_width = 600;
	int max_height = 400;
	
	Simple_window win {Point{100,100}, max_width, max_height, "main File"};

	Line l (Point{200,200}, Point{300,300});
	Lines lines = {
		Point{100,100}, Point{200,100},
		Point{150,50}, Point{150,150}
	};

	lines.add (Point{400,340}, Point {450, 250});

	lines.set_color(Color::red);
	
	win.attach(lines);

	win.wait_for_button();
}