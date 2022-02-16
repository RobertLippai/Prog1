/*
	g++ drill13.cpp ../../gui/Graph.cpp ../../gui/Window.cpp ../../gui/GUI.cpp ../../gui/Simple_window.cpp -o drill13.out `fltk-config --ldflags --use-images` -std=c++11 && ./drill13.out
*/

#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

int main()
{
	using namespace Graph_lib;

	int xmax = 800;
	int ymax = 1000;

	int x_grid = 100;
	int y_grid = 100;
	

	//Task 1
	Simple_window win {Point{100,100}, xmax, ymax, "Drill 13"};


	Lines grid;
	
	//Task 2
	for (int x = x_grid; x < xmax; x += x_grid){
		grid.add(Point{x, 0},Point{x, ymax});
	}
	
	for (int y = y_grid; y < ymax; y += y_grid){
		grid.add(Point{0,y},Point{xmax,y});
	}

	//Task 3
	Vector_ref<Rectangle> rectangles;

	for (int i = 0; i < xmax; i += x_grid) {
		rectangles.push_back(new Rectangle{Point{i,i}, x_grid, y_grid});

		int size = rectangles.size();

		rectangles[size - 1].set_color(Color(Color::red));
		rectangles[size - 1].set_fill_color(Color::red);

		win.attach(rectangles[size - 1]);
	}

	//Task 4
	Vector_ref<Image> images;
	
	for (int i = 0; i < 4; i++) {
		int cordX = 200 * (i+1);
		if (i == 0){
			cordX = 200;
		}
		images.push_back(new Image {Point{cordX, 200*i}, "linux.gif"});
		win.attach(images[images.size() - 1]);
	}
	
	//Attaching grid later, so the red squares and the images are not overlapping it.
	win.attach(grid);

	//Task 5
	Image pacman {Point{0,0}, "pacman.jpeg"};
	win.attach(pacman);


	for (int i = 2; i < (ymax / y_grid); ++i)
	{
		for (int i = 0; i < (xmax / x_grid); ++i)
		{
			win.wait_for_button();
			pacman.move(x_grid, 0);
		}
		pacman.move(xmax*-1, y_grid);
	}

}