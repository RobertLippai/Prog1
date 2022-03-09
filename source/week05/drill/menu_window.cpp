#include "menu_window.h"

menu_window::menu_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    //we are creating the buttons here
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<menu_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<menu_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    
    color_menu_button{Point{x_max()-80, 50}, 80, 20, "color menu",
    	[](Address, Address pw) {reference_to<menu_window>(pw).toggle_color_menu();}},
    	
    color_menu{Point{x_max()-70, 40}, 70, 20, Menu::vertical, "color"},

    line_style_menu_button{Point{x_max()-80, 200}, 80, 20, "line style menu",
    	[](Address, Address pw) {reference_to<menu_window>(pw).toggle_line_style_menu();}},
    	
    line_style_menu{Point{x_max()-70, 200}, 70, 20, Menu::vertical, "lines"}
{
    //then we need to attach all of them
    attach(color_menu_button);
    attach(line_style_menu_button);
    
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    
    
    color_menu.attach(new Button{Point{0, 0}, 0,0, "Red", 
    [](Address, Address pw) {reference_to<menu_window>(pw).change_color(Color::red);} });  
      
    color_menu.attach(new Button{Point{0, 0}, 0,0, "Blue", 
    [](Address, Address pw) {reference_to<menu_window>(pw).change_color(Color::blue);} }); 
    
    color_menu.attach(new Button{Point{0, 0}, 0,0, "Black", 
    [](Address, Address pw) {reference_to<menu_window>(pw).change_color(Color::black);} }); 
    
    line_style_menu.attach(new Button{Point{0, 0}, 0,0, "Solid", 
    [](Address, Address pw) {reference_to<menu_window>(pw).change_line_style(Line_style::solid);} });  
      
    line_style_menu.attach(new Button{Point{0, 0}, 0,0, "Dash", 
    [](Address, Address pw) {reference_to<menu_window>(pw).change_line_style(Line_style::dash);} });  
      
     line_style_menu.attach(new Button{Point{0, 0}, 0,0, "Dot", 
    [](Address, Address pw) {reference_to<menu_window>(pw).change_line_style(Line_style::dot);} });  
    
    attach(color_menu);    
    attach(line_style_menu);

    color_menu.hide();    
    line_style_menu.hide();
    
}

void menu_window::change_color(Color c) { 
	lines.set_color(c); 
	toggle_color_menu();
}

void menu_window::toggle_color_menu(){
	if(isColorMenuShown){
		color_menu.hide();
		color_menu_button.show();
	} else {
		color_menu.show();
		color_menu_button.hide();
	}
	
	isColorMenuShown = !isColorMenuShown;
}

void menu_window::change_line_style(Line_style t){
	lines.set_style(t);
	toggle_line_style_menu();
}
void menu_window::toggle_line_style_menu(){
	if(isLineStyleMenuShown){
		line_style_menu.hide();
		line_style_menu_button.show();
	} else {
		line_style_menu.show();
		line_style_menu_button.hide();
	}
	
	isLineStyleMenuShown = !isLineStyleMenuShown;
}

void menu_window::quit()
{
    hide();
}

void menu_window::next()
{
    //read the text from the input field
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';

    //writes out
    xy_out.put(ss.str());

    redraw();
}
