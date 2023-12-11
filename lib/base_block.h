//
// Created by hosein on 12/9/23.
//

#ifndef KAKURO_BASE_BLOCK_H
#define KAKURO_BASE_BLOCK_H

#include <ostream>
#include "block_type.h"
#include "string"

class BaseBlock {
public:
    int *value;
    int col = -1;
    int row = -1;

    int size;

    BlockType blockType;

    BaseBlock(int a, int b);

    explicit BaseBlock(int a);

    BaseBlock();

    BaseBlock(BaseBlock const &b);

    BaseBlock(const std::string& s);

    friend std::ostream &operator<<(std::ostream &os, const BaseBlock &block);

    void initStr(const std::string& s);

    bool operator<(const BaseBlock &rhs) const;

    bool operator>(const BaseBlock &rhs) const;

    bool operator<=(const BaseBlock &rhs) const;

    bool operator>=(const BaseBlock &rhs) const;

    bool operator==(const BaseBlock &rhs) const;

    BaseBlock operator+(const BaseBlock& b) const;
};


#endif //KAKURO_BASE_BLOCK_H
