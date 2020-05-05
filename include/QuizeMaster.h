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
        void check_row(int);
        void check_column(int);
        void check_box(int);
        void check_solution();

    protected:

    private:
        std::vector<int> puzzle;
        std::vector<int> solution;
        void read_in_sudoku(std::string);
        void read_in_solution(std::string);
        void set_initial_values();

};

#endif // QUIZEMASTER_H
