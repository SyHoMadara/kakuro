#include <sstream>
#include <iostream>
#include "base_board.h"
#include "set"

void BaseBoard::init_board(int n, int m, const std::string &board_str) {
    empty_blocks = std::deque<BaseBlock *>();
    this->n = n;
    this->m = m;
    board = new BaseBlock *[n];
    std::stringstream stream(board_str);
    std::string s;
    for (int i = 0; i < n; i++) {
        board[i] = new BaseBlock[m];
        for (int j = 0; j < m; j++) {
            stream >> s;
            board[i][j] = BaseBlock(s);
            board[i][j].col = j;
            board[i][j].row = i;
            if (board[i][j].blockType && board[i][j].value[0] == 0) {
                empty_blocks.push_back(&board[i][j]);
            }

        }
    }

}

BaseBoard::BaseBoard(int n, int m, const std::string &board_str) {
    init_board(n, m, board_str);
}

BaseBlock *BaseBoard::getParentHorizontal(int i, int j) const {
    for (int jj = j; jj > -1; jj--) {
        if (this->board[i][jj].blockType == BlockType::READ_ABLE) {
            return &board[i][jj];
        }
    }
    return nullptr;
}

BaseBlock *BaseBoard::getParentVertical(int i, int j) const {
    for (int ii = i; ii > -1; ii--) {
        if (this->board[ii][j].blockType == BlockType::READ_ABLE) {
            return &board[ii][j];
        }
    }
    return nullptr;
}


int *BaseBoard::getParentHorLocation(int i, int j) const {
    for (int jj = j; jj > -1; jj--) {
        if (!board[i][jj].blockType) {
            auto a = new int[2]{i, jj};
            return a;
        }
    }
    return nullptr;
}

int *BaseBoard::getParentVerLocation(int i, int j) const {
    for (int ii = i; ii > -1; ii--) {
        if (!board[ii][j].blockType) {
            auto a = new int[2]{ii, j};
            return a;
        }
    }
    return nullptr;
}


std::ostream &operator<<(std::ostream &os, const BaseBoard &board) {
    for (int i = 0; i < board.n; i++) {
        for (int j = 0; j < board.m; j++) {
            os << board.board[i][j] << "|";
        }
        os << "\n";
    }
    return os;
}

BaseBoard::BaseBoard(const BaseBoard &b) {
    m = b.m;
    n = b.n;
    board = new BaseBlock *[n];
    empty_blocks = std::deque<BaseBlock *>();
    for (int i = 0; i < n; i++) {
        board[i] = new BaseBlock[m];
        for (int j = 0; j < m; j++) {
            auto a = new BaseBlock(b.board[i][j]);
            board[i][j] = *a;
            if (board[i][j].blockType && board[i][j].value[0] == 0) {
                empty_blocks.push_back(&board[i][j]);
            }
        }
    }


}

int BaseBoard::rowSum(int col, int row) {
    BaseBlock sum(0);
    for (int j = col; board[row][j].blockType != BlockType::READ_ABLE; j--) {
        sum = sum + board[row][j];
    }
    return sum.value[0];
}

int BaseBoard::columnSum(int col, int row) {
    BaseBlock sum(0);
    for (int i = row; board[i][col].blockType != BlockType::READ_ABLE; i--) {
        sum = sum + board[i][col];
    }
    return sum.value[0];
}

bool BaseBoard::columnConsistency(int col, int row, bool sum_check, bool zero_skip) const {
    std::set<int> numbers;
    BaseBlock sum(0);
    auto parent = getParentVerLocation(row, col);
    if (parent == nullptr) return false;
    for (int i = parent[0] + 1; i < n && board[i][col].blockType != BlockType::READ_ABLE; i++) {
        sum = sum + board[i][col];
        if ((!zero_skip || board[i][col].value[0] != 0) and numbers.find(board[i][col].value[0]) != numbers.end()) {
            delete parent;
            return false;
        }
        if (sum.value[0] > board[parent[0]][parent[1]].value[0]) {
            delete parent;
            return false;
        }
        numbers.insert(board[i][col].value[0]);
    }
    bool cond = (sum.value[0] == board[parent[0]][parent[1]].value[0]);
    delete parent;
    return !sum_check || cond;
}

bool BaseBoard::rowConsistency(int col, int row, bool sum_check, bool zero_skip) const {
    std::set<int> numbers;
    BaseBlock sum(0);
    auto parent = getParentHorLocation(row, col);
    if (parent == nullptr) return false;
    for (int j = parent[1] + 1; j < m && board[row][j].blockType != BlockType::READ_ABLE; j++) {
        sum = sum + board[row][j];
        if ((!zero_skip || board[row][j].value[0] != 0) && numbers.find(board[row][j].value[0]) != numbers.end()) {
            delete parent;
            return false;
        }
        if (sum.value[0] > board[parent[0]][parent[1]].value[1]) {
            delete parent;
            return false;
        }
        numbers.insert(board[row][j].value[0]);
    }
    bool cond = (sum.value[0] == board[parent[0]][parent[1]].value[1]);
    delete parent;
    return !sum_check || cond;
}

bool BaseBoard::consistency(int col, int row, bool sum_check) const {
    return rowConsistency(col, row, sum_check, false) && columnConsistency(col, row, sum_check, false);
}

bool BaseBoard::consistency() const {
    bool res = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j].blockType) continue;
            if (board[i][j].value[0] != 0) {
                res = columnConsistency(j, i, true, false);
            }
            if (board[i][j].value[1] != 0) {
                res = res && rowConsistency(j, i, true, false);
            }
            if (!res) return res;
        }
    }
    return res;
}

bool BaseBoard::checkRowFilled(int row, int col) {
    auto parent = getParentHorLocation(row, col);
    bool filled = true;
    if (parent == nullptr) return false;
    for(int j=parent[1]+1;j<m && board[row][j].blockType; j++){
        if(board[row][j].value[0] == 0) {
            filled = false;
            break;
        }
    }
    delete parent;
    return filled;

}

bool BaseBoard::checkColFilled(int row, int col) {
    auto parent = getParentVerLocation(row, col);
    bool filled = true;
    if (parent == nullptr) return false;
    for(int i=parent[0]+1;i<n && board[i][col].blockType; i++){
        if(board[i][col].value[0] == 0) {
            filled = false;
            break;
        }
    }
    delete parent;
    return filled;
}

BaseBoard::BaseBoard() {

}

