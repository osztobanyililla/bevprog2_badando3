#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <Widget.h>
#include <vector>


class ComboBox : public Widget
{
    public:
        ComboBox() = delete;
        ComboBox(Coord, int, int, std::vector<std::string>, int);
        virtual ~ComboBox();
        void draw();
        void handle(const genv::event&);
        std::string get_data();
        bool is_selected(const int&, const int&);

    protected:
        std::vector<std::string> items;
        int max_item;
        bool is_open = false;
        int selected_index = -1;
        int first_not_shown_index = max_item;

    private:
};

#endif // COMBOBOX_H
