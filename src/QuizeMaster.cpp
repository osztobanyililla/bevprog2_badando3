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


void QuizeMaster::check_level(){
    if(game_window.level == "Easy"){
        std::cout << "Easy level selected" << std::endl;
        start_game = true;
    }
    else if(game_window.level == "Medium"){
        std::cout << "Medium level selected" << std::endl;
        start_game = true;
    }
    else if(game_window.level == "Hard"){
        std::cout << "Hard level selected" << std::endl;
        start_game = true;
    }
    else{
        std::cout << "no level selected" << std::endl;
        start_game = false;
    }
}


