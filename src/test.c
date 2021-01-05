# include <stdio.h>
# include "identifier.c"

int main(int argc, char const *argv[])
{
    initialize_identifier_list();
    add_identifier("a");
    add_identifier("b");
    add_identifier("c1");
    add_identifier("d2");
    printf("%d", __identifier_list__.end);
    return 0;
}
