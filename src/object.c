# pragma once
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define NS_ALLOC_SIZE ((size_t)8) // 名前空間構造体が一度に確保するメモリ

struct NameSpace;
struct Object;

// 名前空間。自己参照構造体で、オブジェクトのポインタを可変長で保存するのが目的。
typedef struct
{
    size_t size; // サイズ
    int *key; // キー。 配列を指すポインタ。
    struct Object *object; //　値。　配列を指すポインタ。
    int end; // 末尾
} NameSpace;


// オブジェクトの種類
enum ObjectType {
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

// 名前空間を初期化
NameSpace initialize_namespace() {
    NameSpace ns;
    ns.size = NS_ALLOC_SIZE;
    // todo: Exit program if failed memory allocation.
    ns.key = (int *)malloc(ns.size * sizeof(int));
    ns.object = (Object *)malloc(ns.size * sizeof(Object));
    ns.end = 0;
    return ns;
}

// 名前空間にオブジェクトを追加する。
void add_object_to_namespace(NameSpace *ns,int id,Object *object) {
    ns->end ++;
    if (ns->end >= ns->size) { // 現在確保されている領域を超過しそうなら、新たに追加でメモリを確保する。
        ns->size += NS_ALLOC_SIZE;
        ns->key = (int *)realloc(ns->size, (ns->size * sizeof(int)));
        ns->object = (Object *)realloc(ns->size, (ns->size * sizeof(Object)));
    }
    // todo: 続き
}

// 名前空間から名前を検索し、そのオブジェクトのポインタを返す。　存在しないならNULLを返す。
Object get_object_from_namespace(NameSpace *ns, int id) {

}

# undef NS_ALLOC_SIZE