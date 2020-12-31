
// 名前空間。自己参照構造体で、オブジェクトのポインタを可変長で保存するのが目的。
struct NameSpace;
typedef struct
{
    NameSpace next;
    
} NameSpace;
