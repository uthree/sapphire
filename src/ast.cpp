#pragma once
#include "ast.hpp"

// コンストラクタ
AST::AST(std::string content, ASTType type, std::vector<AST*> children, bool token) {
    this->content = content;
    this->children = children;
    this->type = type;
    this->token = token;
}

// コピーコンストラクタ
AST::AST(const AST& other) {
    this->content = other.content;
    this->children = other.children;
    this->token = other.token;
    this->type = other.type;
}
