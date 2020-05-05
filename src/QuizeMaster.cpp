#include "QuizeMaster.h"
#include "iostream"
#include "ComboBox.h"
#include "StaticTextBox.h"
#include "Button.h"
#include "fstream"
#include "sstream"
#include "Widget.h"
#include "cmath"

using namespace genv;

QuizeMaster::QuizeMaster(std::string n):
    name(n), game_window(winx,winy,this){}

QuizeMaster::~QuizeMaster()
{
    std::cout << "QuizeMaster deleted" << std::endl;
}


void QuizeMaster::check_level(){
    if(game_window.level == "Easy"){
        std::cout << "Easy level selected" << std::endl;
        start_game = true;
        read_in_sudoku("easy_sudoku.txt");
        read_in_solution("easy_solution.txt");
    }
    else if(game_window.level == "Medium"){
        std::cout << "Medium level selected" << std::endl;
        start_game = true;
        read_in_sudoku("medium_sudoku.txt");
        read_in_solution("medium_solution.txt");
    }
    else if(game_window.level == "Hard"){
        std::cout << "Hard level selected" << std::endl;
        start_game = true;
        read_in_sudoku("hard_sudoku.txt");
        read_in_solution("hard_solution.txt");
    }
    else{
        std::cout << "no level selected" << std::endl;
        start_game = false;
    }
}

void QuizeMaster::read_in_sudoku(std::string file_name){
    std::ifstream my_file(file_name);
    if(!my_file.good()){
        std::cout << "No such file" << std::endl;
    }
    else{
        std::cout << "the puzzel:\n";
        std::string line;
        while(!my_file.eof()){
            std::getline(my_file, line);
            for(int i = 0; i < 9; i++){
                std::stringstream ss(line.std::string::substr(i,1));
                int a = 0;
                ss >> a;
                puzzle.push_back(a);
                std::cout << a;
            }
            std::cout << std::endl;
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
        std::cout << "the solution:\n";
        std::string line;
        while(!my_file.eof()){
            std::getline(my_file, line);
            for(int i = 0; i < 9; i++){
                std::stringstream ss(line.std::string::substr(i,1));
                int a = 0;
                ss >> a;
                solution.push_back(a);
                std::cout << a;
            }
            std::cout << std::endl;
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



void QuizeMaster::check_solution(){
    bool solved = true;
    for(int i = 0; i < solution.size(); i++){
        if(solution[i] != game_window.game_widgets[i]->num){
            solved = false;
            break;
        }
    }
    if(solved){
        std::cout << "Puzzle solved\n";
        game_window.game_over = true;
    }
}
