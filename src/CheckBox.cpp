#include "CheckBox.h"

using namespace genv;

CheckBox::CheckBox(Coord p, int sx, int sy):
    Widget(p, sx, sy){}

CheckBox::~CheckBox(){}

void CheckBox::draw(){
    MyColor border_color(176,200,249);
    MyColor body_color(255,255,255);
    gout << move_to(pos.x, pos.y) << color(border_color.r, border_color.g, border_color.b) << box(sizex, sizey);
    gout << move_to(pos.x+border_size, pos.y+border_size) << color(body_color.r, body_color.g, body_color.b) << box(sizex-2*border_size, sizey-2*border_size);
    if(checked){
        gout << color(0,0,0) << move_to(pos.x+sizex/4, pos.y+sizey/2) << line_to(pos.x+sizex/2, pos.y+3*sizey/4) << line_to(pos.x+3*sizex/4, pos.y+sizey/4);
    }
}

void CheckBox::handle(const event& e){
    if(e.type == ev_mouse && e.button == btn_left){
        if(e.pos_x > pos.x+border_size && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+border_size && e.pos_y < pos.y+sizey-border_size){
            checked = !checked;
        }
    }
}
