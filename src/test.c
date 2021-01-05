# include <stdio.h>
# include "identifier.c"

int main(int argc, char const *argv[])
{
    initialize_identifier_list();
    add_identifier("a");
    return 0;
}
