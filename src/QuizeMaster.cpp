#include "QuizeMaster.h"
#include "iostream"
#include "ComboBox.h"
#include "StaticTextBox.h"
#include "Button.h"

using namespace genv;

QuizeMaster::QuizeMaster(std::string n):
    name(n), game_window(800,800,this){}

QuizeMaster::~QuizeMaster()
{
    std::cout << "QuizeMaster deleted" << std::endl;
}

void QuizeMaster::event_loop(){
    event ev;
    gin.timer(30);
    while(gin >> ev){
        if(game_window.start_window){
            Widget* selected_widget = nullptr;
            if(ev.type == ev_mouse && ev.button == btn_left){
                if(selected_widget){
                    selected_widget->unfocus();
                    selected_widget = nullptr;
                }
                for(auto it = game_window.start_widgets.rbegin(); it != game_window.start_widgets.rend(); ++it){
                    Widget* w = *it;
                    if(w->is_selected(ev.pos_x, ev.pos_y)){
                        selected_widget = w;
                        break;
                    }
                }
            }
            if(selected_widget){
                selected_widget->handle(ev);
            }
            if(ev.type == ev_timer){
                game_window.clear_screen();
                for(Widget* w : game_window.start_widgets){
                    w->draw();
                }
                std::cout << game_window.start_window << std::endl;
            }



        }
        else{
            std::cout << "start game" << std::endl;
        }
        gout << refresh;
    }
}

