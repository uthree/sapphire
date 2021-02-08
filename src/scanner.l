%{
#pragma once
#include "parser.tab.h"
#include "../src/ast.cpp"
using namespace std;

extern "C" int yywrap(); 
int yywrap() {
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

[0-9]+ {
    AST ast;
    char* content;
    content = (char*)malloc(sizeof(yytext));
    content = yytext;
    ast = {
        integer_literal,
        content,
        nullptr,
        false
    }
    yylval.ast = ast;
    return INTEGER_LITERAL
}

%%