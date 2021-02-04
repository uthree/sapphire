#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../src/ast_type.hpp"

class AST {
public:
    AST(); // コンストラクタ
    ~AST(); // デストラクタ
    AST(AST& other); // コピーコンストラクタ。
    bool token; // トークンであるか
    std::string content; // 内容
    std::vector<AST*> childlen; //子要素
};