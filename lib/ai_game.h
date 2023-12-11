//
// Created by hosein on 12/9/23.
//

#ifndef KAKURO_AI_GAME_H
#define KAKURO_AI_GAME_H
#include "base_board.h"

class AiGame {
public:
    BaseBoard gameBoard;
    explicit AiGame(const BaseBoard& board);
    bool solve(BaseBoard& state);
};


#endif //KAKURO_AI_GAME_H
