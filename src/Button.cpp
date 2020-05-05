#include "Button.h"
#include "iostream"
#include "QuizeMaster.h"

using namespace genv;

Button::Button(Coord p, int sx, int sy, std::string l, Window* w):
    Widget(p, sx, sy), label(l), parent(w){}

Button::~Button(){}

void Button::draw(){
    MyColor border_color(176,200,249);
    MyColor body_color(255,255,255);
    MyColor text_color(0,0,0);
    int text_width = gout.twidth(label);
    gout << move_to(pos.x, pos.y) << color(border_color.r, border_color.g, border_color.b) << box(sizex, sizey);
    gout << move_to(pos.x+border_size, pos.y+border_size) << color(body_color.r, body_color.g, body_color.b) << box(sizex-2*border_size, sizey-2*border_size);
    gout << move_to(pos.x+sizex/2-text_width/2, pos.y+sizey/2+gout.cascent()/2-gout.cdescent()/2) << color(text_color.r, text_color.g, text_color.b) << text(label);
}

void Button::handle(const event& e){
    if(e.type == ev_mouse && e.button == btn_left){
        if(e.pos_x > pos.x+border_size && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+border_size && e.pos_y < pos.y+sizey-border_size){
            std::cout << "Button pressed" << std::endl;
            pressed = true;
        }
    }
}
