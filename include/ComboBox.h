#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <Widget.h>
#include <vector>
#include <Window.h>

class Window;

class ComboBox : public Widget
{
    public:
        ComboBox() = delete;
        ComboBox(Coord, int, int, std::vector<std::string>, int, Window*);
        virtual ~ComboBox();
        void draw();
        void handle(const genv::event&);
        std::string get_data();
        bool is_selected(const int&, const int&);
        int selected_index = -1;
        bool is_open = false;

    protected:

    private:
        std::vector<std::string> items;
        int max_item;
        int first_not_shown_index = max_item;
        Window* parent;
};

#endif // COMBOBOX_H
