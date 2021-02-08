#pragma once
#include "ast.hpp"


struct AST {
    ASTType type; // ASTの種類
    char* content; // 内容。
    struct AST* children[8]; // 子要素。8個まで入る。
    bool token; // 終端記号であるか
};

void show_ast(AST* ast);
void show_ast(AST* ast) {
    if (ast->token) {
        printf("t");
        printf("%s", (ast->content));
    }
    else {
        printf("(");
        printf("%d", ast->type);
        printf(" ");
        if (ast->content != nullptr)
            printf("%s", ast->content);;
        for (int i = 0; i < 8; i++)
        {
            if (ast->children[i] != nullptr) {
                printf("%d", i);
                show_ast((ast->children[i]));
                printf(" ");
            } else {
                printf("e");
            }
        };
        printf(")");
    }
    return;
}