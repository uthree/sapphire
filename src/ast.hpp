#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../src/ast_type.hpp"

class AST {
public:
    AST(std::string content, ASTType type, std::vector<AST*> children, bool token); // コンストラクタ
    ~AST(); // デストラクタ
    //AST(const AST& other); // コピーコンストラクタ。
    bool token; // トークンであるか
    std::string content; // 内容
    std::vector<AST*> children; //子要素
    ASTType type; //構文またはトークンの種類。 
};