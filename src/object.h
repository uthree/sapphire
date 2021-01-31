# pragma once
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

// 名前空間。自己参照構造体で、オブジェクトのポインタを可変長で保存するのが目的。
typedef struct
{
    int size; // サイズ
    int* keys; // キー。 配列の先頭ポインタ。
    struct Object **objects; //　値。 ポインタの配列の先頭ポインタ。
    int end; // 末尾
} NameSpace;


// オブジェクトの種類
enum ObjectType {
    nil, // nil
    integer, // long int
    double_float, // double 
    string, // char[]
    namespace, // 名前空間
    class, // クラス
    other_obj, // その他のユーザ定義オブジェクト。
};

// オブジェクト
typedef struct {
    enum ObjectType type;
    union {
        long int integer;
        double double_float;
        struct NameSpace *namespace;
    } value;
} Object;


NameSpace initialize_namespace();
void set_object_to_namespace(NameSpace *ns,int id,Object *object);
Object *get_object_from_namespace(NameSpace *ns, int id);
