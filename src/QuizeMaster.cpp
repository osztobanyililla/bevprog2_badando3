#include "QuizeMaster.h"
#include "iostream"
#include "cmath"
#include "fstream"
#include "sstream"
#include "ComboBox.h"
#include "StaticTextBox.h"
#include "Button.h"
#include "CheckBox.h"
#include "Widget.h"


using namespace genv;

QuizeMaster::QuizeMaster(std::string n):
    name(n), game_window(winx,winy,this){}

QuizeMaster::~QuizeMaster()
{
    std::cout << "QuizeMaster deleted" << std::endl;
}


void QuizeMaster::check_level(){
    std::cout << "Check level\n";
    if(game_window.level == "Easy"){
        start_game = true;
        read_in_sudoku("easy_sudoku.txt");
        read_in_solution("easy_solution.txt");
    }
    else if(game_window.level == "Medium"){
        start_game = true;
        read_in_sudoku("medium_sudoku.txt");
        read_in_solution("medium_solution.txt");
    }
    else if(game_window.level == "Hard"){
        start_game = true;
        read_in_sudoku("hard_sudoku.txt");
        read_in_solution("hard_solution.txt");
    }
    else{
        std::cout << "no level selected" << std::endl;
        start_game = false;
    }
    if(game_window.help_btn->checked){
        without_help = true;
    }
    else{
        without_help = false;
    }
}

void QuizeMaster::read_in_sudoku(std::string file_name){
    std::ifstream my_file(file_name);
    if(!my_file.good()){
        std::cout << "No such file" << std::endl;
    }
    else{
        std::string line;
        while(!my_file.eof()){
            std::getline(my_file, line);
            for(int i = 0; i < 9; i++){
                std::stringstream ss(line.std::string::substr(i,1));
                int a = 0;
                ss >> a;
                puzzle.push_back(a);
            }
        }
        set_initial_values();
    }
}

void QuizeMaster::read_in_solution(std::string file_name){
    std::ifstream my_file(file_name);
    if(!my_file.good()){
        std::cout << "No such file" << std::endl;
    }
    else{
        std::string line;
        while(!my_file.eof()){
            std::getline(my_file, line);
            for(int i = 0; i < 9; i++){
                std::stringstream ss(line.std::string::substr(i,1));
                int a = 0;
                ss >> a;
                solution.push_back(a);
            }
        }
    }
}

void QuizeMaster::set_initial_values(){
    for(int i = 0; i < puzzle.size(); i++){
        if(puzzle[i] != 0){
            game_window.game_widgets[i]->fix = true;
        }
        game_window.game_widgets[i]->set_data(puzzle[i]);
    }
}

void QuizeMaster::check_rules(int index){
    if(!without_help){
        if(check_box(index) || check_row(index) ||check_column(index)){
            game_window.game_widgets[index]->multiple = true;
        }
        else{
            game_window.game_widgets[index]->multiple = false;
        }
    }
    check_solution();
}

bool QuizeMaster::check_box(int index){
    int value = game_window.game_widgets[index]->num;
    bool multiple = false;
    bool criteria_1;
    bool criteria_2;
    for(int i = 0; i < game_window.game_widgets.size(); i++){
        criteria_1 = false;
        criteria_2 = false;
        if(index%9 < 3 && i%9 < 3){
            criteria_1 = true;
        }
        if(index%9 > 2 && index%9 < 6 && i%9 > 2 && i%9 < 6){
            criteria_1 = true;
        }
        if(index%9 > 5 && i%9 > 5){
            criteria_1 = true;
        }
        if(floor(index/9) < 3 && floor(i/9) < 3){
            criteria_2 = true;
        }
        if(floor(index/9) > 2 && floor(index/9) < 6 && floor(i/9) > 2 && floor(i/9) < 6){
            criteria_2 = true;
        }
        if(floor(index/9) > 5 && floor(i/9) > 5){
            criteria_2 = true;
        }
        if(i != index && criteria_1 && criteria_2 && value == game_window.game_widgets[i]->num && value != 0){
            //std::cout << "multiple " << value << " in box " << std::endl;
            multiple = true;
        }
    }
    return multiple;
}

bool QuizeMaster::check_row(int index){
    int value = game_window.game_widgets[index]->num;
    int ind_in_row = index%9;
    int row_ind = floor(index/9);
    bool multiple = false;
    for(int i = 0; i < game_window.game_widgets.size(); i++){
        if(i != index && floor(i/9) == row_ind){
            if(value != 0 && value == game_window.game_widgets[i]->num){
                multiple = true;
                //std::cout << "multiple " << value << " in " << row_ind+1 << ". row\n";
            }
        }
    }
    return multiple;
}

bool QuizeMaster::check_column(int index){
    int value = game_window.game_widgets[index]->num;
    bool multiple = false;
    for(int i = 0; i < game_window.game_widgets.size(); i++){
        if(i != index && i%9 == index%9){
            if(value != 0 && value == game_window.game_widgets[i]->num){
                multiple = true;
                //std::cout << "multiple " << value << " in " << (i%9)+1 << ". column\n";
            }
        }
    }
    return multiple;
}


void QuizeMaster::check_solution(){
    bool solved = true;
    for(int i = 0; i < solution.size(); i++){
        if(solution[i] != game_window.game_widgets[i]->num){
            solved = false;
            break;
        }
    }
    if(solved){
        //std::cout << "Puzzle solved\n";
        game_window.game_over = true;
    }
}
