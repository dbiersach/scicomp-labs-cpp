#include "stdafx.h"
#include "SimpleScreen.h"

using namespace std;

vector<int> board(9);

bool HasChain(int player, int posA, int posB, int posC)
{
    if ((board.at(posA) == player) &&
            (board.at(posB) == player) &&
            (board.at(posC) == player))
        return true;
    else
        return false;
}

bool HasWon(int player)
{
    // Check Rows
    if (HasChain(player, 0, 1, 2)) return true;

    // Check Columns
    if (HasChain(player, 0, 3, 6)) return true;

    return false;
}

string WhoWon()
{
    // Player 1 = O's, Player 2 = X's
    if (HasWon(1) && !HasWon(2)) return "O Wins!";
    if (!HasWon(1) && HasWon(2)) return "X Wins!";
    return "Tie!";
}

void DrawBoardGrid(SimpleScreen& ss)
{
    ss.DrawRectangle("black", 175, 25, 5, 450, 1, true);
    ss.DrawRectangle("black", 325, 25, 5, 450, 1, true);
    ss.DrawRectangle("black", 25, 175, 450, 5, 1, true);
    ss.DrawRectangle("black", 25, 325, 450, 5, 1, true);
}

void DrawPlayer(SimpleScreen& ss, int pos, int player)
{
    // Decode position number into row and column numbers
    int row = pos / 3;
    int col = pos % 3;

    // Calculate Cartesian center of current position
    int centerX = col * 150 + 100;
    int centerY = 400 - row * 150;

    if (player == 1)  // The "O" player
    {
        ss.DrawCircle(centerX, centerY, 45, "red", 15);
    }
    else if (player == 2)  // The "X" player
    {
        PointSet psBackSlash;
        psBackSlash.add(centerX - 39, centerY + 39);
        psBackSlash.add(centerX + 39, centerY - 39);
        ss.DrawLines(&psBackSlash, "blue", 15);

        PointSet psForwardSlash;
        psForwardSlash.add(centerX + 39, centerY + 39);
        psForwardSlash.add(centerX - 39, centerY - 39);
        ss.DrawLines(&psForwardSlash, "blue", 15);
    }
}

void DecodeBoard(int boardNum)
{
    for (int pos = 0; pos < 9; pos++)
        board.at(pos) = (int)(boardNum / pow(3,pos)) % 3;
}

void draw(SimpleScreen& ss)
{
    DrawBoardGrid(ss);
    for (int pos = 0; pos < 9; pos++)
        DrawPlayer(ss, pos, board.at(pos));
}

int main()
{
    SimpleScreen ss(draw);
    ss.SetWorldRect(0, 0, 500, 500);

    DecodeBoard(3845);

    cout << WhoWon() << endl;

    ss.HandleEvents();

    return 0;
}

