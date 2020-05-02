#include "Window.h"
#include "vector"
#include "iostream"
#include "ComboBox.h"
#include "StaticTextBox.h"
#include "Button.h"
#include "QuizeMaster.h"

using namespace genv;

Window::Window(int sx, int sy, QuizeMaster* qm):
    sizex(sx), sizey(sy), master(qm){
        Coord pos_levels(sx/2-100, sy/4);
        std::vector<std::string> level_names {"Easy", "Medium", "Hard"};
        ComboBox* levels = new ComboBox(pos_levels, 200, 50,level_names, 3);
        Coord pos_lab1(sx/2-100, sy/4-100);
        StaticTextBox* label1 = new StaticTextBox(pos_lab1, 200, 50, master->name);
        Coord pos_button(sx/2-50, sy/2);
        Button* btn = new Button(pos_button, 100, 70, "START", this);
        start_widgets.push_back(levels);
        start_widgets.push_back(label1);
        start_widgets.push_back(btn);
        gout.open(sizex, sizey);
    }
Window::~Window(){
    std::cout << "Window deleted" << std::endl;
}


void Window::clear_screen(){
    gout << move_to(0,0) << color(0,0,0) << box(winx-1,winy-1);
}


