#ifndef WINDOW_H
#define WINDOW_H
#include "Widget.h"
#include "vector"
#include "StaticTextBox.h"
#include "SpinBox.h"

class QuizeMaster;
class Button;
class ComboBox;
class CheckBox;

class Window
{
    public:
        Window() = delete;
        Window(int, int, QuizeMaster*);
        virtual ~Window();
        void clear_screen();
        QuizeMaster* master;
        ComboBox* level_selection;
        Button* start_btn;
        std::vector<Widget*> start_labels;
        CheckBox* help_btn;
        std::vector<SpinBox*> game_widgets;
        StaticTextBox* end_label;
        std::string level;
        bool level_selected = false;
        bool game_over = false;
        void event_loop();

    protected:

    private:
        int sizex, sizey;

};

#endif // WINDOW_H
