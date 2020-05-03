#include "graphics.hpp"
#include "QuizeMaster.h"

int main()
{
    QuizeMaster master("SUDOKU");
    master.game_window.event_loop();
    return 0;
}
