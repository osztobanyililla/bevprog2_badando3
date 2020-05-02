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
        void event_loop();
        std::string name;

    protected:

    private:
        Window game_window;
};

#endif // QUIZEMASTER_H
