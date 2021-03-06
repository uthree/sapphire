
# include <stdio.h>

# include "ast.h"
AST_node AST_ROOT;

# include "parser.tab.c"
# include "object.c"
# include "identifier.c"

int main(int argc, char const *argv[]) {
    extern int yyparse(void);
    extern FILE *yyin;

    yyin = fopen(argv[1], "r");

    if (yyparse()) {
        fprintf(stderr, "\nerror \n");
        fclose(yyin);
        exit(1);
    }
    fclose(yyin);
    printf("\n\nPROGRAM END\n");
}
