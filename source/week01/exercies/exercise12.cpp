/*
    g++ exercise12.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o exercise12 `fltk-config --ldflags --use-images` -std=c++11 && ./exercise12
*/
#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    Simple_window win {Point{100,100}, xmax, ymax, "Exercise 12"};

    Rectangle r {Point{0,200}, 200, 100};

	r.set_color(Color::blue);

	Polygon rect;

	rect.add(Point{300,200});
	rect.add(Point{350,100});
	rect.add(Point{400,200});

	rect.set_color(Color::red);


	Rectangle r2 {Point{500,500}, 100, 30};
	Text t {Point{500,530}, "Howdy!"};

	Text l_letter {Point{750,200}, "L"};
	Text r_letter {Point{750,250}, "R"};

	l_letter.set_font(Font::times_bold);
	l_letter.set_font_size(35);

	r_letter.set_font(Font::times_bold);
	r_letter.set_font_size(35);

	win.attach(r);
	win.attach(r2);
	win.attach(rect);
	win.attach(t);
	win.attach(l_letter);
	win.attach(r_letter);
    win.wait_for_button();

}
