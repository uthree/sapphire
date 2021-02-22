#pragma once
#include "ast.hpp"

struct AST {
    ASTType type; // ASTの種類
    char* content; // 内容。
    AST* children[8]; // 子要素。8個まで入る。
    bool token; // 終端記号であるか
};

