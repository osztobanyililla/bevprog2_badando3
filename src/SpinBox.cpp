#include "SpinBox.h"
#include <iostream>
using namespace genv;

SpinBox::SpinBox(Coord p, int a, int b, int m, int n):
    Widget(p, a, b), max_num(m), min_num(n){}

SpinBox::~SpinBox(){}

void SpinBox::draw(){
    MyColor border_color(176, 200, 249);
    MyColor body_color(255, 255, 255);
    int num_box_x = int(3*sizex/4);
    gout << move_to(pos.x, pos.y) << color(border_color.r, border_color.g, border_color.b) << box(sizex, sizey);
    gout << move_to(pos.x + border_size, pos.y + border_size) << color(body_color.r, body_color.g, body_color.b) << box(num_box_x - 2*border_size, sizey - 2*border_size);
    int button_body_y = (sizey-3*border_size)/2;
    int button_body_x = sizex - num_box_x - border_size;
    gout << move_to(pos.x+num_box_x, pos.y+border_size) << box(button_body_x, button_body_y);
    gout << move_to(pos.x+num_box_x, pos.y+2*border_size+button_body_y) << box(button_body_x, button_body_y);
    int text_size = gout.twidth(std::to_string(num));
    if(multiple){
        MyColor text_color(255,0,0);
        gout << move_to(pos.x + (num_box_x-text_size)/2, pos.y + (sizey+text_height)/2) << color(text_color.r, text_color.g, text_color.b) << text(std::to_string(num));
        gout << color(0,0,0);
    }
    else{
        MyColor text_color(0,0,0);
        gout << move_to(pos.x + (num_box_x-text_size)/2, pos.y + (sizey+text_height)/2) << color(text_color.r, text_color.g, text_color.b) << text(std::to_string(num));
    }
    int line_size = button_body_x/4;
    gout << move_to(pos.x+num_box_x+button_body_x/2-line_size, pos.y+border_size+(button_body_y+line_size)/2) << line(line_size, -1*line_size) <<line(line_size, line_size);
    gout << move_to(pos.x+num_box_x+button_body_x/2-line_size, pos.y+2*border_size+button_body_y+(button_body_y-line_size)/2) << line(line_size, line_size) <<line(line_size, -1*line_size);
}

void SpinBox::handle(const event& e){
    int num_box_x = int(3*sizex/4);
    if(!fix){
        if(e.type == ev_mouse && e.button == btn_left){
            if(e.pos_x > pos.x+num_box_x && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+border_size && e.pos_y < pos.y+sizey/2-border_size/2){
                if(num < max_num){
                    num += 1;
                }
                else{
                    std::cout << "Maximum value reached" << std::endl;
                }
            }
            if(e.pos_x > pos.x+num_box_x && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+sizey/2+border_size/2 && e.pos_y < pos.y+sizey-border_size){
                if(num > min_num){
                    num -= 1;
                }
                else{
                    std::cout << "Minimum value reached" << std::endl;
                }
            }
        }
        if(e.type == ev_key && e.keycode == key_up){
                if(num < max_num){
                    num += 1;
                }
                else{
                    std::cout << "Maximum value reached" << std::endl;
                }
        }
        if(e.type == ev_key && e.keycode == key_down){
            if(num > min_num){
                num -= 1;
            }
                else{
                    std::cout << "Minimum value reached" << std::endl;
                }
        }
        if(e.type == ev_key && e.keycode == key_pgup){
            if(num+10 <= max_num){
                num += 10;
            }
            else{
                std::cout << "Maximum value reached" << std::endl;
            }
        }
        if(e.type == ev_key && e.keycode == key_pgdn){
            if(num-10 >= min_num){
                num -= 10;
            }
            else{
                std::cout << "Minimum value reached" << std::endl;
            }
        }
    }
    else{
        std::cout << "Value can not be changed" << std::endl;
    }
}

std::string SpinBox::get_data(){
    return std::to_string(num);
}

void SpinBox::set_data(int a){
    num = a;
}
