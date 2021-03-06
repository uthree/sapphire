%{
    #pragma once
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "./ast.h"
    #define YYDEBUG 1
%}
%union {
    AST_node ast;
}

/*
//   _______ ____  _  ________ _   _  _____ 
//  |__   __/ __ \| |/ /  ____| \ | |/ ____|
//     | | | |  | | ' /| |__  |  \| | (___  
//     | | | |  | |  < |  __| | . ` |\___ \ 
//     | | | |__| | . \| |____| |\  |____) |
//     |_|  \____/|_|\_\______|_| \_|_____/                          
*/                                

%left PULS
%left MINUS
%left ASTERISK
%left SLASH
%left PERCENT
%token EQUAL
%left PERIOD
%token COMMA
%token COLON
%token SEMICOLON
%left LESSTHAN
%left GREATERTHAN
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token LEFT_BLACKET
%token RIGHT_BLACKET
%token LEFT_CURLY_BLACKET
%token RIGHT_CURLY_BLACKET

%left EQUAL_EQUAL
%left LESSTHAN_EQUAL
%left GREATERTHAN_EQUAL
%left NOT_EQUAL
%left PULS_EQUAL
%left MINUS_EQUAL
%left ASTERISK_EQUAL
%left SLASH_EQUAL

%token NEWLINE

%left KW_AND
%left KW_OR
%left KW_NOT
%left KW_XOR
%left KW_NAND
%left LW_NOR

%token KW_IMPORT
%token KW_FROM
%token KW_AS

%token KW_CLASS
%token KW_FUNCTION
%token KW_CONSTRUCTOR
%token KW_GETTER
%token KW_SETTER
%token KW_IF
%token KW_ELSE
%token KW_END
%token KW_WHILE
%token KW_UNTIL
%token KW_BREAK
%token KW_RETURN

%token <ast> INTEGER_LITERAL
%token <ast> FLOAT_LITERAL;
%token <ast> BOOL_LITERAL;
%token <ast> NIL_LITERAL;
%token <ast> STRING_LITERAL;
%token <ast> IDENTIFIER;

/*
//   _________     _______  ______  _____ 
//  |__   __\ \   / /  __ \|  ____|/ ____|
//     | |   \ \_/ /| |__) | |__  | (___  
//     | |    \   / |  ___/|  __|  \___ \ 
//     | |     | |  | |    | |____ ____) |
//     |_|     |_|  |_|    |______|_____/ 
*/


%type <ast> literal;
%type <ast> program;
%type <ast> expression;

%type <ast> setter;
%type <ast> getter;


/*
//   _____  _    _ _      ______  _____ 
//  |  __ \| |  | | |    |  ____|/ ____|
//  | |__) | |  | | |    | |__  | (___  
//  |  _  /| |  | | |    |  __|  \___ \ 
//  | | \ \| |__| | |____| |____ ____) |
//  |_|  \_\\____/|______|______|_____/ 
*/                                           
%%

program
    : expression NEWLINE{
        AST_ROOT = $1;
    };

expression
    : literal
    | getter
    | setter
    ;

setter
    : expression PERIOD IDENTIFIER EQUAL expression
    {
        printf("setter\n");
        AST_node *list = {
            &$1,
            $3,
            &$5
        };
        AST_node ast = {
            op_setter,
            list,
            NULL
        };
        $$ = ast;
    }

literal
    : INTEGER_LITERAL {
        printf("int");
        $$ = $1;   
    }
    | FLOAT_LITERAL {
        printf("float");
        $$ = $1;
    }
    | STRING_LITERAL {
        printf("string");
        $$ = $1;
    }
    ;

getter
    : IDENTIFIER {
        printf("single_getter\n");
        $$ = $1;
    }
    | expression PERIOD IDENTIFIER {
        printf("getter\n");
        AST_node *list = {
            &$1,
            $3
        };
        AST_node ast = {
            op_getter,
            list,
            NULL
        };
        $$ = ast;
    }
    ;




%%
#include "lex.yy.c"

int yyerror(char const *str) {
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}