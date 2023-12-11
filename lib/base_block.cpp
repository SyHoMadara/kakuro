#include <regex>
#include <iomanip>
#include "base_block.h"

BaseBlock::BaseBlock(int a, int b) {
    this->value = new int[]{a, b};
    this->blockType = BlockType::READ_ABLE;
    size = 2;
}

BaseBlock::BaseBlock(int a) {
    this->value = new int[]{a};
    this->blockType = BlockType::WRITE_ABLE;
    size = 1;
}

void BaseBlock::initStr(const std::string& s) {
    blockType = BlockType::WRITE_ABLE;
    for (char i: s) {
        if (i == '/') {
            blockType = BlockType::READ_ABLE;
            break;
        }
    }
    if (blockType == BlockType::READ_ABLE) {
        value = new int[2];
        std::regex exp("([-\\d]+)");
        std::smatch res;
        std::string::const_iterator searchStart(s.cbegin());
        int i = 0;
        while (regex_search(searchStart, s.cend(), res, exp)) {
            value[i] = stoi(res[0]);
            searchStart = res.suffix().first;
            i++;
        }
        size = 2;
        return ;
    }
    value = new int[1];
    value[0] = stoi(s);
    size = 1;
}

BaseBlock::BaseBlock() {
}

std::ostream &operator<<(std::ostream &os, const BaseBlock &block) {
    std::string output;
    if (block.blockType == BlockType::WRITE_ABLE) {
        if (block.value[0] <= 0) output += "*";
        else output += std::to_string(block.value[0]);
    } else {
        if (block.value[0] <= 0) output += "";
        else output += std::to_string(block.value[0]);
        output += "/";
        if (block.value[1] <= 0) output += "";
        else output += std::to_string(block.value[1]);
    }
    os << std::setw(8) << output;
    return os;
}

BaseBlock::BaseBlock(BaseBlock const &b) {
    value = new int[b.size];
    std::copy(b.value, b.value+b.size, value);
    size = b.size;
    blockType = b.blockType;
    col = b.col;
    row = b.row;
}

bool BaseBlock::operator<(const BaseBlock &rhs) const {
    if(rhs.blockType == BlockType::READ_ABLE) return false;
    return this->value[0] <rhs.value[0];
}

bool BaseBlock::operator>(const BaseBlock &rhs) const {
    if(rhs.blockType == BlockType::READ_ABLE) return false;
    return rhs.value[0] < this->value[0];
}

bool BaseBlock::operator<=(const BaseBlock &rhs) const {
    return !(rhs < *this);
}

bool BaseBlock::operator>=(const BaseBlock &rhs) const {
    return !(*this < rhs);
}

bool BaseBlock::operator==(const BaseBlock &rhs) const {
    return (*this >= rhs && *this <= rhs);
}

BaseBlock BaseBlock::operator+(const BaseBlock &b) const {
    BaseBlock res(0);
    res.value[0] = value[0] + b.value[0];
    return res;
}

BaseBlock::BaseBlock(const std::string &s) {
    initStr(s);
}






