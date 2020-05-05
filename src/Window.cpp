#include "Window.h"
#include "vector"
#include "iostream"
#include "ComboBox.h"
#include "StaticTextBox.h"
#include "Button.h"
#include "QuizeMaster.h"
#include "SpinBox.h"
#include "cmath"

using namespace genv;

Window::Window(int sx, int sy, QuizeMaster* qm):
    sizex(sx), sizey(sy), master(qm)
    {
        std::vector<std::string> level_names {"Easy", "Medium", "Hard"};
        level_selection = new ComboBox(Coord(sx/2-100, sy/4), 200, 50,level_names, 3, this);
        start_btn = new Button(Coord(sx/2-50, sy/2), 100, 70, "START", this);
        start_labels.push_back(new StaticTextBox(Coord(10, sy/4-100), winx-10, 30, master->name));
        start_labels.push_back(new StaticTextBox(Coord(10, sy/4-70), winx-10, 30, "Select level and press Start button to start game!"));
        int count_i = 0;
        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 9; i++){
                int count_j = 0;
                if(i > 6){
                    count_i = 6;
                }
                else if(i > 3 && i != 6){
                    count_i = 3;
                }
                else{
                    count_i = 0;
                }
                if(j > 6){
                    count_j = 6;
                }
                else if(j > 3 && j != 6){
                    count_j = 3;
                }
                else{
                    count_j = 0;
                }
                if(i%3 == 0 && j%3 == 0){

                    game_widgets.push_back(new SpinBox(Coord(60+i*60+count_i*5, 60+j*60+count_j*5), 50, 50, 9, 0));
                }
                else if(i%3 == 0){
                    game_widgets.push_back(new SpinBox(Coord(60+i*60+count_i*5, 60+j*55+count_j*5), 50, 50, 9, 0));
                }
                else if(j%3 == 0){
                    game_widgets.push_back(new SpinBox(Coord(60+i*55+count_i*5, 60+j*60+count_j*5), 50, 50, 9, 0));
                }
                else{
                    game_widgets.push_back(new SpinBox(Coord(60+i*55+count_i*5, 60+j*55+count_j*5), 50, 50, 9, 0));
                }
            }
        }
        end_label = new StaticTextBox(Coord(100,200),winx-200,winy-400,"CONGRATULATIONS, PUZZLE SOLVED");
        gout.open(sizex, sizey);
    }
Window::~Window(){
    std::cout << "Window deleted" << std::endl;
}


void Window::clear_screen(){
    gout << move_to(0,0) << color(0,0,0) << box(winx-1,winy-1);
}

void Window::event_loop(){
    for(int i = 0; i < game_widgets.size(); i ++){
        std::cout << i  << ": " << game_widgets[i]->pos.x << " " << game_widgets[i]->pos.y << " " << game_widgets[i]->sizex << "" << game_widgets[i]->sizey << std::endl;
    }
    event ev;
    gin.timer(30);
    while(gin >> ev){
        if(!master->start_game){
            Widget* selected_widget = nullptr;
            if(ev.type == ev_mouse && ev.button == btn_left){
                if(start_btn->is_selected(ev.pos_x, ev.pos_y)){
                    level_selection->unfocus();
                    selected_widget = start_btn;
                    //std::cout << "button selected" << std::endl;
                    master->check_level();
                }
                if(level_selection->is_selected(ev.pos_x, ev.pos_y)){
                    start_btn->unfocus();
                    selected_widget = level_selection;
                    //std::cout << "combo selected" << std::endl;
                }
            }
            if(selected_widget){
                selected_widget->handle(ev);
            }
            if(ev.type == ev_timer){
                clear_screen();
                start_btn->draw();
                level_selection->draw();
                for(Widget* w : start_labels){
                    w->draw();
                }
                    }
            if(ev.type == ev_key && ev.keycode == key_escape){
                break;
            }
        }
        else{
            Widget* selected_widget = nullptr;
            int ind = 0;
            if(ev.type == ev_mouse && ev.button == btn_left){
                /*if(selected_widget != nullptr){
                    selected_widget->unfocus();
                    selected_widget = nullptr;
                }*/
                //for(auto it = game_widgets.rbegin(); it != game_widgets.rend(); ++it){
                for(int i = 0; i < game_widgets.size(); i++){
                    //SpinBox* w = *it;
                    SpinBox* w = game_widgets[i];
                    if(w->is_selected(ev.pos_x, ev.pos_y)){
                        ind = i;
                        //std::cout << "mouse: " << ev.pos_x << " " << ev.pos_y << std::endl;
                        selected_widget = w;
                        //std::cout << selected_widget->pos.x << " " << selected_widget->pos.y << " " << selected_widget->focus << std::endl;
                        break;
                    }
                }
            }
            if(selected_widget){
                selected_widget->handle(ev);
                selected_widget->unfocus();
                master->check_solution();
            }
            if(ev.type == ev_timer){
                clear_screen();
                for(SpinBox* w : game_widgets){
                    w->draw();
                }
            }
            if(ev.type == ev_key && ev.keycode == key_escape){
                break;
            }
            if(game_over){
                end_label->draw();
            }
        }
        gout << refresh;
    }
}
