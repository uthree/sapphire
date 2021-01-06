# include <stdio.h>
# include "identifier.c"

int main(int argc, char const *argv[])
{
    initialize_identifier_list();
    add_identifier("a");
    printf("%d\n", __identifier_list__.end);
    add_identifier("b");
    printf("%d\n", __identifier_list__.end);
    add_identifier("c");
    printf("%d\n", __identifier_list__.end);
    printf("SIZ %d\n", sizeof(__identifier_list__.values));
    add_identifier("d");
    printf("%d\n", __identifier_list__.end);
    printf("SIZ %d\n", sizeof(__identifier_list__.values));
    add_identifier("e");
    printf("%d\n", __identifier_list__.end);
    printf("SIZ %d\n", sizeof(__identifier_list__.values));
    return 0;
}
