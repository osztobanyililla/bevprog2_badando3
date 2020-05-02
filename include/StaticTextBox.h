#ifndef STATICTEXTBOX_H
#define STATICTEXTBOX_H

#include <Widget.h>


class StaticTextBox : public Widget
{
    public:
        StaticTextBox() = delete;
        StaticTextBox(Coord, int, int, std::string);
        virtual ~StaticTextBox();
        void draw();
        void handle(const genv::event& e);
    protected:

    private:
        std::string label;
};

#endif // STATICTEXTBOX_H
