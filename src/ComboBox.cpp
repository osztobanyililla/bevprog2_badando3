#include "ComboBox.h"
#include <iostream>
using namespace genv;

MyColor border_color(176,200,249);
MyColor body_color(255,255,255);
MyColor text_color(0,0,0);
MyColor select_color(0,0,0);
MyColor button_color(207,212,213);
MyColor slider_color(194,194,194);

ComboBox::ComboBox(Coord p, int a, int b, std::vector<std::string> v, int m):
    Widget(p, a, b), items(v), max_item(m)
{
    if(pos.y+sizey+max_item*(2*gout.cdescent()+text_height) > winy){
        pos.y = winy - 10 - sizey - max_item*(2*gout.cdescent()+text_height);
        std::cout << "Position should be corrected to correctly draw widget!\n";
    }
}

ComboBox::~ComboBox(){}

void ComboBox::draw(){
    int item_box_x = int(3*sizex/4);
    gout << move_to(pos.x, pos.y) << color(border_color.r, border_color.g, border_color.b) << box(sizex, sizey);
    int button_body_y = sizey-2*border_size;
    int button_body_x = sizex - item_box_x - border_size;
    int line_size = button_body_x/3;
    int single_item_y = text_height+2*gout.cdescent();
    int open_button_y = button_body_y/2;
    int open_line = line_size/2;
    if(!focus){
        is_open = false;
    }
    if(!is_open){
        if(selected_index == -1){
            gout << move_to(pos.x+border_size, pos.y+border_size) << color(body_color.r, body_color.g, body_color.b) << box(item_box_x-2*border_size, sizey-2*border_size);
            gout << move_to(pos.x+item_box_x, pos.y+border_size) << box(button_body_x, button_body_y);
            gout << color(text_color.r, text_color.g, text_color.b) << move_to(pos.x+item_box_x+button_body_x/2-line_size, pos.y+border_size+(button_body_y-line_size)/2) << line(line_size, line_size) <<line(line_size, -1*line_size);
        }
        else{
            gout << move_to(pos.x+border_size, pos.y+border_size) << color(body_color.r, body_color.g, body_color.b) << box(item_box_x-2*border_size, sizey-2*border_size);
            gout << move_to(pos.x+item_box_x, pos.y+border_size) << box(button_body_x, button_body_y);
            gout << color(text_color.r, text_color.g, text_color.b) << move_to(pos.x+item_box_x+button_body_x/2-line_size, pos.y+border_size+(button_body_y-line_size)/2) << line(line_size, line_size) <<line(line_size, -1*line_size);
            int text_width = gout.twidth(items[selected_index]);
            gout << move_to(pos.x+(item_box_x-text_width)/2, pos.y+(sizey+text_height-gout.cdescent())/2) << text(items[selected_index]);
        }
    }
    else{
        gout << move_to(pos.x, pos.y) << color(border_color.r, border_color.g, border_color.b) << box(sizex, sizey+max_item*single_item_y+border_size);
        gout << move_to(pos.x+border_size, pos.y+border_size) << color(body_color.r, body_color.g, body_color.b) << box(item_box_x-2*border_size, sizey-2*border_size);
        gout << move_to(pos.x+border_size, pos.y+sizey) << box(sizex-button_body_x-3*border_size, max_item*single_item_y);
        gout << move_to(pos.x+item_box_x, pos.y+border_size) << box(button_body_x, button_body_y);
        int slider_y = std::min(max_item,(int)items.size())*((single_item_y*max_item-2*open_button_y)/(int)items.size());
        int slider_chunk;
        if((int)items.size() == max_item){
            slider_chunk = 0;
            gout << color(text_color.r, text_color.g, text_color.b) << move_to(pos.x+item_box_x+button_body_x/2-line_size, pos.y+border_size+(button_body_y-line_size)/2) << line(line_size, line_size) <<line(line_size, -1*line_size);
        }
        else{
            slider_chunk = (max_item*single_item_y-2*open_button_y-slider_y)/((int)items.size()-max_item);
            gout << move_to(pos.x+item_box_x, pos.y+button_body_y+2*border_size) << box(button_body_x, max_item*single_item_y);
            gout << color(button_color.r, button_color.g, button_color.b) << move_to(pos.x+item_box_x, pos.y+button_body_y+2*border_size) << box(button_body_x, open_button_y);
            gout << move_to(pos.x+item_box_x, pos.y+sizey+max_item*single_item_y-open_button_y) << box(button_body_x, open_button_y);
            gout << move_to(pos.x+item_box_x, pos.y+sizey+open_button_y+(first_not_shown_index-max_item)*slider_chunk) << color(slider_color.r, slider_color.g, slider_color.b) << box(button_body_x, slider_y+1);
            gout << color(text_color.r, text_color.g, text_color.b) << move_to(pos.x+item_box_x+button_body_x/2-line_size, pos.y+border_size+(button_body_y-line_size)/2) << line(line_size, line_size) <<line(line_size, -1*line_size);
            gout << move_to(pos.x+item_box_x+button_body_x/2-open_line, pos.y+2*border_size+button_body_y+(open_button_y+open_line)/2) << line(open_line, -1*open_line) << line(open_line, open_line);
            gout << move_to(pos.x+item_box_x+button_body_x/2-open_line, pos.y+sizey+max_item*single_item_y -(open_button_y+open_line)/2) << line(open_line,open_line) << line(open_line, -1*open_line);

        }
        if(selected_index != -1){
            int text_width = gout.twidth(items[selected_index]);
            gout << move_to(pos.x+(item_box_x-text_width)/2, pos.y+(sizey+text_height-gout.cdescent())/2) << text(items[selected_index]);
        }
        int i_ = 0;
        for(int i = first_not_shown_index-max_item; i < std::min(first_not_shown_index, (int)items.size()); i++){
            int item_length = gout.twidth(items[i]);
            gout << move_to(pos.x+(item_box_x-item_length)/2, pos.y+sizey+i_*single_item_y+(single_item_y+text_height-gout.cdescent())/2) << text(items[i]);
            i_++;
        }
    }
}

void ComboBox::handle(const event& e){
    int item_box_x = int(3*sizex/4);
    int open_button_y = (sizey-2*border_size)/2;
    int single_item_y = text_height+2*gout.cdescent();
    if(e.type == ev_mouse && e.button == btn_left){
        if(e.pos_x > pos.x+item_box_x && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+border_size && e.pos_y < pos.y+sizey-border_size){
            if(is_open){
                is_open = false;
            }
            else{
                is_open = true;
            }
        }
        if(is_open){
            if(e.pos_x > pos.x+item_box_x && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+sizey && e.pos_y < pos.y+sizey+open_button_y){
                if(first_not_shown_index > max_item){
                    first_not_shown_index -= 1;
                }
                else{
                    std::cout << "can not go up" << std::endl;
                }
            }
            if(e.pos_x > pos.x+item_box_x && e.pos_x < pos.x+sizex-border_size && e.pos_y > pos.y+sizey+max_item*single_item_y-open_button_y && e.pos_y < pos.y+sizey+max_item*single_item_y){
                if(first_not_shown_index < items.size()){
                    first_not_shown_index += 1;
                }
                else{
                    std::cout << "can not go down" << std::endl;
                }
            }
            for(int i = 0; i < items.size(); i++){
                if(e.pos_x > pos.x+border_size && e.pos_x < pos.x+item_box_x-border_size && e.pos_y > pos.y+sizey+i*single_item_y && e.pos_y < pos.y+sizey+(i+1)*single_item_y){
                    selected_index = i + (first_not_shown_index-max_item);
                    is_open = false;
                }
            }
        }
    }
}

bool ComboBox::is_selected(const int& mx, const int& my){
    int single_item_y = text_height+2*gout.cdescent();
    if(!is_open){
        if(mx > pos.x && mx < pos.x + sizex && my > pos.y && my < pos.y + sizey){
            focus = true;
        }
    }
    else{
        if(mx > pos.x && mx < pos.x + sizex && my > pos.y && my < pos.y + sizey + max_item*single_item_y + border_size){
            focus = true;
        }
    }
    return focus;
}

std::string ComboBox::get_data(){
    if(selected_index != -1){
        return items[selected_index];
    }
    else{
        return "-";
    }
}
