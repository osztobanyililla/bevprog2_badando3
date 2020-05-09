#ifndef BUTTON_H
#define BUTTON_H

#include <Widget.h>

class Window;

class Button : public Widget
{
    public:
        Button() = delete;
        Button(Coord, int, int, std::string, Window*);
        virtual ~Button();
        void draw();
        void handle(const genv::event&);
        bool pressed = false;

    protected:

    private:
        std::string label;
        Window* parent;
};

#endif // BUTTON_H
