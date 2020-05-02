#ifndef WINDOW_H
#define WINDOW_H
#include "Widget.h"
#include "vector"

class QuizeMaster;

class Window
{
    public:
        Window() = delete;
        Window(int, int, QuizeMaster*);
        virtual ~Window();
        void clear_screen();
        std::vector<Widget*> start_widgets;
        bool start_window = true;

    protected:

    private:
        int sizex, sizey;
        QuizeMaster* master;
};

#endif // WINDOW_H
