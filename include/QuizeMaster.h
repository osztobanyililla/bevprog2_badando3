#ifndef QUIZEMASTER_H
#define QUIZEMASTER_H
#include "vector"
#include "Widget.h"
#include "Window.h"


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

    protected:

    private:

};

#endif // QUIZEMASTER_H
