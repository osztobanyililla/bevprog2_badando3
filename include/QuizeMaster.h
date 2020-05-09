#ifndef QUIZEMASTER_H
#define QUIZEMASTER_H
#include "vector"
#include "Widget.h"
#include "Window.h"
#include "fstream"


class QuizeMaster
{
    public:
        QuizeMaster() = delete;
        QuizeMaster(std::string);
        virtual ~QuizeMaster();
        std::string name;
        Window game_window;
        bool start_game = false;
        void check_level();
        void check_rules(int);


    protected:

    private:
        std::vector<int> puzzle;
        std::vector<int> solution;
        void read_in_sudoku(std::string);
        void read_in_solution(std::string);
        void set_initial_values();
        bool check_row(int);
        bool check_column(int);
        bool check_box(int);
        void check_solution();
        bool without_help = false;

};

#endif // QUIZEMASTER_H
