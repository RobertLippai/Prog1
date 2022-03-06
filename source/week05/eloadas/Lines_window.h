#include "../../gui/GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	//widgets
	Button next_button;
	Button quit_button;

	//textfield
	In_box next_x;
	In_box next_y;

	//
	Out_box xy_out;

	void next();
	void quit();

};