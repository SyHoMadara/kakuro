#include <iostream>
#include "ai_game.h"

AiGame::AiGame(const BaseBoard &board) : gameBoard(board) {

}

bool AiGame::solve(BaseBoard &state) {
    if (state.empty_blocks.empty()) return state.consistency();
    for (int i = 1; i < 10; i++) {
        BaseBoard newBoard = state;
        auto newBlock = newBoard.empty_blocks.front();
        newBoard.empty_blocks.pop_front();
        newBlock->value[0] = i;
        if (newBoard.checkColFilled(newBlock->row, newBlock->col) &&
            !newBoard.columnConsistency(newBlock->col, newBlock->row, true,
                                       false)){
            continue;
        }
        if (newBoard.checkRowFilled(newBlock->row, newBlock->col) &&
            !newBoard.rowConsistency(newBlock->col, newBlock->row, true,
                                       false)){
            continue;
        }
            if (!newBoard.rowConsistency(newBlock->col, newBlock->row, false, true)) {
                continue;
            }
        if (!newBoard.columnConsistency(newBlock->col, newBlock->row, false, true)) {
            continue;
        }
        if (solve(newBoard)) {
            state = newBoard;
            return true;
        }
    }
    return false;
}
