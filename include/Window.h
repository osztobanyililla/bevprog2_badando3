#ifndef WINDOW_H
#define WINDOW_H
#include "Widget.h"
#include "vector"
#include "ComboBox.h"
#include "Button.h"
#include "StaticTextBox.h"

class QuizeMaster;
class Button;
class ComboBox;

class Window
{
    public:
        Window() = delete;
        Window(int, int, QuizeMaster*);
        virtual ~Window();
        void clear_screen();
        std::vector<Widget*> start_labels;
        std::vector<Widget*> game_widgets;
        std::string level;
        QuizeMaster* master;
        ComboBox* level_selection;
        Button* start_btn;
        bool start_window = true;
        bool level_selected = false;
        void event_loop();

    protected:

    private:
        int sizex, sizey;

};

#endif // WINDOW_H
