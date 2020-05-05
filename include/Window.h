#ifndef WINDOW_H
#define WINDOW_H
#include "Widget.h"
#include "vector"
#include "ComboBox.h"
#include "Button.h"
#include "StaticTextBox.h"
#include "SpinBox.h"

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
        ComboBox* level_selection;
        std::vector<Widget*> start_labels;
        std::vector<SpinBox*> game_widgets;
        QuizeMaster* master;
        StaticTextBox* end_label;
        std::string level;
        Button* start_btn;
        bool level_selected = false;
        bool game_over = false;
        void event_loop();

    protected:

    private:
        int sizex, sizey;

};

#endif // WINDOW_H
