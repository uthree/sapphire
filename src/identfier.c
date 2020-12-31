# pragma once
# include <stdio.h>
// 識別子にそれぞれ番号を振って、照合する際の処理を文字列ではなく整数の一致の判定にすることによって高速化する。
# define IDENTFIER_LIST_UNIT_SIZE 256 // 一度に確保するサイズ。自己参照構造体の一つ分。

struct IdentifierList;

typedef struct
{
    struct IdentifierList *next;
    char *names[IDENTFIER_LIST_UNIT_SIZE]; //key
    int values[IDENTFIER_LIST_UNIT_SIZE]; //value
} IdentifierList;

IdentifierList identifiers; // 識別子のリスト

int __end_of_idefinder_list__ = 0; // 識別子リストの末尾のインデックス。 
struct IdentifierList *__identfier_list_ptr__; //識別子リストの自己参照の最後のポインタ。 
void add_identfier(char *name) // 識別子を追加する。
{
    __end_of_idefinder_list__++;
    if (__end_of_idefinder_list__ >= IDENTFIER_LIST_UNIT_SIZE) {
        //新規ユニットを登録する。
        __end_of_idefinder_list__ = 0;
    }
}