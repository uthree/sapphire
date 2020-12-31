# pragma once
# define NAMESPACE_UNIT_SIZE 145 // 名前空間のオブジェクト一つ分が確保するオブジェクトの数

struct NameSpace;
struct Object;

// 名前空間。自己参照構造体で、オブジェクトのポインタを可変長で保存するのが目的。
typedef struct
{
    struct NameSpace *next;
    int key[NAMESPACE_UNIT_SIZE]; // キー。
    struct Object *obj[NAMESPACE_UNIT_SIZE]; //　値。
} NameSpace;


// オブジェクトの種類
enum ObjectType {
    integer, // long int
    double_float, // double 
    string, // char[]
    namespace, // 名前空間
    class, // クラス￥
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

// 名前空間にオブジェクトを追加する。
void NS_add_object(NameSpace *naespace,int symbol_value,Object *object) {
    
}