#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <Widget.h>

class Window;

class CheckBox : public Widget
{
    public:
        CheckBox() = delete;
        CheckBox(Coord, int, int);
        virtual ~CheckBox();
        void draw();
        void handle(const genv::event&);
        bool checked = false;

    protected:

    private:
        Window* parent;
};

#endif // CHECKBOX_H
