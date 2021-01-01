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

IdentifierList __identifiers__ = { // 識別子のリスト
    NULL,
    {},
    {}
};

int __end_of_idefinder_list__ = 0; // 識別子リストの末尾のインデックス。 
IdentifierList *__identfier_list_ptr__; //識別子リストの自己参照の最後のポインタ。 
int __last_identfier_number__ = 0; // 最後の識別子の番号

void initialize_identifier_list() { // 識別子リストを初期化する。
    __identfier_list_ptr__ = &__identifiers__;
}

void add_identfier(char *name) // 識別子を追加する。
{
    __end_of_idefinder_list__++;
    __last_identfier_number__++;
    if (__end_of_idefinder_list__ >= IDENTFIER_LIST_UNIT_SIZE) {
        //新規ユニットを登録する。

        IdentifierList next_list = { // 新しいリスト。
            NULL,
            {},
            {}
        };
        __identfier_list_ptr__->next = &next_list; //次のリストを示すポインタを代入
        __identfier_list_ptr__ = &next_list;
        __end_of_idefinder_list__ = 0; // 初期値に戻す
    }
    // 名前を追加
    __identfier_list_ptr__->names[__end_of_idefinder_list__] = name;
    __identfier_list_ptr__->values[__end_of_idefinder_list__] = __last_identfier_number__;
}

// 識別子情報用に確保したメモリを解放
void remove_identfier();