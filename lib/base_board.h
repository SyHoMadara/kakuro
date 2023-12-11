#ifndef BASE_BOARD_H
#define BASE_BOARD_H

#include <ostream>
#include "base_block.h"
#include "string"
#include "deque"

class BaseBoard {
public:
    BaseBoard();

    int n;
    int m;
    std::deque<BaseBlock*> empty_blocks;
    BaseBlock **board;

    void init_board(int n, int m, const std::string &board_str);

    BaseBoard(int n, int m, const std::string &board_str = nullptr);

    BaseBoard(const BaseBoard &b);

    friend std::ostream &operator<<(std::ostream &os, const BaseBoard &board);

    [[nodiscard]] BaseBlock *getParentVertical(int i, int j) const;

    [[nodiscard]] int *getParentVerLocation(int i, int j) const;

    [[nodiscard]] BaseBlock * getParentHorizontal(int i, int j) const;

    [[nodiscard]] int* getParentHorLocation(int i, int j) const;

    int columnSum(int col, int row);

    int rowSum(int col, int row);

    [[nodiscard]] bool columnConsistency(int col, int row, bool sum_check, bool zero_skip) const;

    [[nodiscard]] bool rowConsistency(int col, int row, bool sum_check, bool zero_skip) const;

    bool checkRowFilled(int row, int col);
    bool checkColFilled(int row, int col);

    [[nodiscard]] bool consistency(int col, int row, bool sum_check) const;
    [[nodiscard]] bool consistency() const;

};


#endif