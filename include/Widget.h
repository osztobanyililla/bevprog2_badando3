#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"
#define winx 640
#define winy 640


struct Coord{

    int x;
    int y;
    Coord() {
        x = -1;
        y = -1;
    }
    Coord(int x_, int y_){
        x = x_;
        y = y_;
    }
};

struct MyColor{
    int r;
    int g;
    int b;
    MyColor(int d, int e, int f){
        r = d;
        g = e;
        b = f;
    }
};

class Widget
{
    public:
        Widget() = delete;
        Widget(Coord, int, int);
        virtual ~Widget();
        virtual void draw() = 0;
        virtual void handle(const genv::event&) = 0;
        virtual void unfocus();
        virtual bool is_selected(const int&, const int&);
        virtual std::string get_data();
        Coord pos;
        int sizex, sizey;
        bool focus = false;

    protected:
        //Coord pos;
        //int sizex, sizey;
        //bool focus = false;
        int border_size;
        int text_height = genv::gout.cascent();

    private:
};

#endif // WIDGET_H
