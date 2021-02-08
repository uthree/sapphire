#pragma once
#include "ast.hpp"


struct AST {
    ASTType type; // ASTの種類
    char* content; // 内容。
    struct AST* children; // 子要素。可変長配列。要素追加する際に随時メモリを確保する。
    bool token; // 終端記号であるか
};