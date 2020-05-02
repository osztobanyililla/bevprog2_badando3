#include "graphics.hpp"
#include "QuizeMaster.h"

int main()
{
    QuizeMaster master("SUDOKU");
    master.event_loop();
    return 0;
}
