/*
    g++ drill12.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images` -std=c++11 && ./drill12
*/
#include <iostream>

int main()
{
	for (int i = 1000; i > 100; i -= 100) {
		std::cout << i;
	}
	return 0;
	
}
