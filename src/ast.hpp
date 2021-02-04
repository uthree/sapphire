#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../src/ast_type.hpp"

class AST {
public:
    AST(std::string content, ASTType type, std::vector<AST*> children, bool token); // コンストラクタ
    ~AST(); // デストラクタ
    AST(const AST& other); // コピーコンストラクタ。
    AST& operator=(const AST& other) //代入演算子
    {
        this->children = other.children;
        this->content = other.content;
        this->type = other.type;
        this->token = other.token;
        return *this;
    };
    bool token; // トークンであるか
    std::string content; // 内容
    std::vector<AST*> children; //子要素
    ASTType type; //構文またはトークンの種類。 
};

