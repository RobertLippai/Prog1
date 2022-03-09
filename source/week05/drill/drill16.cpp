/*
	g++ drill16.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ./menu_window.cpp -o drill16.out `fltk-config --ldflags --use-images` -std=c++11 && ./drill16.out
*/

#include "./menu_window.h"
#include "../../gui/Graph.h"


int main()
{
	using namespace Graph_lib;

	menu_window win{Point{100,100}, 1024, 768, "Drill 16"};

	return gui_main();
}

// 2 menü
// egyikben vonal színe
// másikkban vonal stílusát lehessen állítani

// a lines window osztályát kilehet bövíteni

//GUI.h-ban widgetek


/*
1. Make a completely new project with linker settings for FLTK (as de-
scribed in Appendix D).
2. Using the facilities of Graph_lib , type in the line-drawing program from
§16.5 and get it to run.
3. Modify the program to use a pop-up menu as described in §16.7 and get
it to run.
4. Modify the program to have a second menu for choosing line styles and
get it to run.
*/
