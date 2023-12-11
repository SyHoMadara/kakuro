#include <bits/stdc++.h>
#include "lib/base_board.h"
#include "lib/base_block.h"
#include "lib/ai_game.h"

using namespace std;
#define iosync ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
//    iosync;
    vector<string> s(4);
    vector<BaseBoard> b(4);
    s[0] = "0/0 0/0 0/0 17/0 28/0 0/0 0/0\n"
               "0/0 0/0 27/16 0 0 17/0 17/0\n"
               "0/0 11/27 0 0 0 0 0\n"
               "0/3 0 0 14/19 0 0 0\n"
               "0/34 0 0 0 0 0 17/0\n"
               "0/0 0/30 0 0 0 0 0\n"
               "0/0 0/3 0 0 0/16 0 0";
    b[0] = BaseBoard (7, 7, s[0]);
    s[1] = "0/0 11/0 6/0\n"
               "0/14 0 0\n"
               "0/3 0 0";
    b[1] = BaseBoard (3, 3, s[1]);
    s[2] = "0/0 0/0 0/0 18/0 4/0 0/0 26/0 13/0\n"
               "0/0 0/0 0/5 0 0 13/10 0 0\n"
               "0/0 0/0 25/33 0 0 0 0 0\n"
               "0/0 9/9 0 0 0/6 0 0 15/0\n"
               "0/6 0 0 0/0 0/0 0/8 0 0\n"
               "0/13 0 0 8/0 0/0 10/16 0 0\n"
               "0/0 9/13 0 0 7/7 0 0 0/0\n"
               "0/20 0 0 0 0 0 0/0 0/0\n"
               "0/3 0 0 0/8 0 0 0/0 0/0";
    b[2] = BaseBoard (9, 8, s[2]);
    s[3] = "0/0 1/0 2/0 3/0 4/0 5/0 0/0 6/0\n"
               "0/15 0 0 0 0 0 0/6 0";
    b[3] = BaseBoard (2, 8, s[3]);

    int i = 1;
    {
        cout << "Board " << i+1 << "\n";
        cout << b[i];
        cout << "-------------------------------------------------\n";
        AiGame game(b[i]);
        if (game.solve(game.gameBoard)){
            cout << "Solvable" << "\n";
            cout << game.gameBoard << "\n\n\n";
        } else {
            cout << "Unsolvable\n\n\n";
        }
    }

}
