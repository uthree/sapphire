# pragma once
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define NS_ALLOC_SIZE 8 // 名前空間構造体が一度に確保するメモリ

struct NameSpace;
struct Object;

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


// 名前空間を初期化
NameSpace initialize_namespace() {
    NameSpace ns;
    ns.size = NS_ALLOC_SIZE;
    // todo: Exit program if failed memory allocation.
    ns.keys = (int *)malloc(ns.size * sizeof(int));
    ns.objects = (Object **)malloc(ns.size * sizeof(Object*));
    ns.end = 0;
    return ns;
}

// 名前空間にオブジェクトを追加する。
void set_object_to_namespace(NameSpace *ns,int id,Object *object) {
    if (ns->end+1 >= ns->size) { // 現在確保されている領域を超過しそうなら、新たに追加でメモリを確保する。
        ns->size += NS_ALLOC_SIZE;
        ns->keys = (int *)realloc(ns->keys, (ns->size * sizeof(int)));
        ns->objects = (Object **)realloc(ns->objects, (ns->size * sizeof(Object*)));
    }
    // todo: idが重複する場合でも追加されるので事前にそれを判定する。
    ns->keys[ns->end] = id;
    ns->objects[ns->end] = object;
    ns->end ++;
}



// 名前空間から名前を検索し、そのオブジェクトのポインタを返す。
Object *get_object_from_namespace(NameSpace *ns, int id) {
    if (ns->size == 0) exit(EXIT_FAILURE); // object not found.
    for (int i = 0; i < ns->end; i++)
    {
        if(ns->keys[i] == id) {
            return ns->objects[i];
        }
    }
}

# undef NS_ALLOC_SIZE