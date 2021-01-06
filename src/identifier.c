# include "identifier.h"

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>

# pragma once

# define IDENTIFIER_ALLOC_SIZE 4

// 識別子にそれぞれ固有の番号(int)を割り当てることによって、処理を高速化する。

// リストは、本プログラムにおいて一つしか存在しないので、型名をつける必要はない。
struct {
    int size;
    int end;
    char** names;
    int* values;
} __identifier_list__;

// リスト初期化
void initialize_identifier_list() {
    __identifier_list__.size = IDENTIFIER_ALLOC_SIZE;
    __identifier_list__.end = 0;
    __identifier_list__.names = (char**)malloc(__identifier_list__.size * sizeof(char*));
    __identifier_list__.values = (int*)malloc(__identifier_list__.size * sizeof(int));
}

// 新しい識別子を追加する
void add_identifier(char* name) {
    if (check_identifier_exist(name)) return; // すでに存在する場合は追加しない。
    if (__identifier_list__.end+1 >= __identifier_list__.size) { //リストが一杯になったら新規メモリを確保する。
        printf("reallocate");
        __identifier_list__.size += IDENTIFIER_ALLOC_SIZE;
        __identifier_list__.names = (char**)realloc(__identifier_list__.names, __identifier_list__.size * sizeof(char*));
        __identifier_list__.values = (int*)realloc(__identifier_list__.values, __identifier_list__.size * sizeof(int));
    }
    __identifier_list__.names[__identifier_list__.end] = name;
    __identifier_list__.values[__identifier_list__.end] = __identifier_list__.end;
    __identifier_list__.end ++;
}

// 識別子が存在するかどうかチェックする。
bool check_identifier_exist(char* name) {
    if (__identifier_list__.end == 0) return false;
    for (int i = 0; i < __identifier_list__.end; i++)
    {
        if(strcmp(__identifier_list__.names[i], name) == 0) {
            return true;
        }
    }
    return false;   
    
}

// 識別子の番号を取得する。
int get_identifier_number(char* name) {
    for (int i = 0; i <= __identifier_list__.end; i++)
    {
        if(strcmp(__identifier_list__.names[i], name) == 0) {
            return __identifier_list__.values[i];
        }
    }
    return -1; 
}

#undef IDENTIFIER_ALLOC_SIZE