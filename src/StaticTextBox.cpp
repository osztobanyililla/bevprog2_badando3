#include "StaticTextBox.h"

using namespace genv;

StaticTextBox::StaticTextBox(Coord p, int sx, int sy, std::string d):
    Widget(p,sx,sy), label(d){}

StaticTextBox::~StaticTextBox(){}

void StaticTextBox::draw(){
    MyColor text_color(255,255,255);
    int text_width = gout.twidth(label);
    gout << move_to(pos.x+sizex/2-text_width/2, pos.y+sizey/2+gout.cascent()) << color(text_color.r, text_color.g, text_color.b) << text(label);
}

void StaticTextBox::handle(const event& e){

}
