#include "Widget.h"
#include <iostream>

Widget::Widget(Coord p, int a, int b)
{
    pos.x = std::min(winx-a-10, p.x);
    pos.y = std::min(winy-b-10, p.y);
    if(pos.x != p.x || pos.y != p.y){
        std::cout << "Position should be corrected to correctly draw widget!\n";
    }
    sizex = a;
    sizey = b;
    if(int(3*sizex/4) > sizey){
        border_size = int(sizey / 10);
    }
    else{
        border_size = int(3*sizex/4 / 10);
    }
}


Widget::~Widget(){}

void Widget::unfocus(){
    focus = false;
}

bool Widget::is_selected(const int& mx, const int& my){
    if(mx > pos.x && mx < pos.x + sizex && my > pos.y && my < pos.y + sizey){
        focus = true;
    }
    return focus;
}

std::string Widget::get_data(){}
