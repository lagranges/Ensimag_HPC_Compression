#include "tree.hpp"

Tree::Tree(char c){
    this->childLeft = null;
    this->childRight = null;
    this->val = c;
}

Tree::Tree(Tree left, Tree right){
    this->childLeft = left;
    this->childRight = right;
}
