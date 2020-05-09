#ifndef SPINBOX_H
#define SPINBOX_H

#include <Widget.h>


class SpinBox : public Widget
{
    public:
        SpinBox() = delete;
        SpinBox(Coord, int, int, int, int);
        virtual ~SpinBox();
        void draw();
        void handle(const genv::event&);
        std::string get_data();
        void set_data(int);
        bool fix = false;
        int num = 0;
        bool multiple = false;

    protected:
        int max_num;
        int min_num;


    private:
};

#endif // SPINBOX_H
