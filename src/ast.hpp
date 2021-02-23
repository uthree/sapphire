#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../src/ast_type.hpp"

class AST {
public:
    ASTType type;
    std::vector<AST*> children;
    bool flag_token;
    std::string content;

    AST(ASTType _type, std::vector<AST*> _children, bool _flag_token, std::string _content)
    {
        type = _type;
        children = _children;
        flag_token = _flag_token;
        content = _content;
    }
};