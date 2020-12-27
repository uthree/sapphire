#pragma once

// 構文の種類を識別するID
enum AST_type {
    token,
};

// 抽象構文木のノード。 自己参照構造体。
struct AST_node;
typedef struct
{
    enum AST_type type; // 構文の種類。
    struct AST_node *childlen[8]; //内包される”子”となるASTノード
    void *value; // トークンである場合にはその値が入る。
} AST_node;