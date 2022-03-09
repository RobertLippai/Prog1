#include "../../gui/GUI.h"


using namespace Graph_lib;

struct menu_window : Graph_lib::Window {
	menu_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;
	
	Menu color_menu;
	Button color_menu_button;
	
	
	Menu line_style_menu;
	Button line_style_menu_button;


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
	
	bool isColorMenuShown = false;
		
	bool isLineStyleMenuShown = false;

	void change_color(Color c);
	void toggle_color_menu();
	
	void change_line_style(Line_style t);
	void toggle_line_style_menu();
	
	void next();
	void quit();

};
