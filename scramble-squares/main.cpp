#include "stdafx.h"
#include "tile.h"
#include "board.h"

using namespace std;

int main()
{
    Board* board = new Board();
    board->Solve(0);
    delete board;
    return 0;
}
