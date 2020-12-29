%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "./ast.h"

    int yywrap() {
        printf("WRAP");
        return 1;
    }
%}
%%

"+"                 return PULS;
"-"                 return MINUS;
"*"                 return ASTERISK;
"/"                 return SLASH;
"%"                 return PERCENT;
"="                 return EQUAL;
"."                 return PERIOD;
","                 return COMMA;
":"                 return COLON;
";"                 return SEMICOLON;
"<"                 return LESSTHAN;
">"                 return GREATERTHAN;
"("                 return LEFT_PARENTHESIS;
")"                 return RIGHT_PARENTHESIS;
"["                 return LEFT_BLACKET;
"]"                 return RIGHT_BLACKET;
"{"                 return LEFT_CURLY_BLACKET;
"}"                 return RIGHT_CURLY_BLACKET;

"=="                return EQUAL_EQUAL;
"<="                return LESSTHAN_EQUAL;
">="                return GREATERTHAN_EQUAL;
"!="                return NOT_EQUAL;
"+="                return PULS_EQUAL;
"-="                return MINUS_EQUAL;
"*="                return ASTERISK_EQUAL;
"/="                return SLASH_EQUAL;

"\n"                return NEWLINE;

"and"               return KW_AND;
"or"                return KW_OR;
"not"               return KW_NOT;
"xor"               return KW_XOR;
"nand"              return KW_NAND;
"nor"               return LW_NOR;

"import"            return KW_IMPORT;
"from"              return KW_FROM;
"as"                return KW_AS;

"class"             return KW_CLASS;
"function"          return KW_FUNCTION;
"constructor"       return KW_CONSTRUCTOR;
"getter"            return KW_GETTER;
"setter"            return KW_SETTER;
"if"                return KW_IF;
"else"              return KW_ELSE;
"end"               return KW_END;
"while"             return KW_WHILE;
"until"             return KW_UNTIL;
"break"             return KW_BREAK;
"return"            return KW_RETURN;

[1-9][0-9]*         {
    // Integer
    long int *tmp;
    sscanf(yytext, "%ld", &tmp);
    AST_node ast = {
        token_integer,
        NULL,
        tmp
    };
    yylval.ast = ast;
    
    return INTEGER_LITERAL;
};

[0-9]\.[0-9]*         {
    // Float
    double *tmp;
    sscanf(yytext, "%lf", &tmp);
    AST_node ast = {
        token_float,
        NULL,
        tmp
    };
    yylval.ast = ast;
    
    return FLOAT_LITERAL;
};

(true|false)        return BOOL_LITERAL;
"nil"               return NIL_LITERAL;

\"(.*)\"            {
    // 文字列(char[] ポインタ)
    char *str;
    str = (char *)malloc(sizeof(yytext));
    str = yytext;
    if(str == NULL) {
        printf("FAILED ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }

    AST_node ast = {
        token_string,
        NULL,
        str
    };
    
    yylval.ast = ast;
    return STRING_LITERAL;
};

[A-Za-z][A-Za-z0-9]* {
    // 変数名などの識別子(char[] ポインタ)
    char *str;
    str = (char *)malloc(sizeof(yytext));
    str = yytext;
    printf(str);
    if(str == NULL) {
        printf("FAILED ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }

    AST_node ast = {
        token_identfier,
        NULL,
        str
    };
    yylval.ast = ast;
    return IDENTIFIER;
};

%%