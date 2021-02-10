/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    ASTERISK = 260,                /* ASTERISK  */
    SLASH = 261,                   /* SLASH  */
    PERCENT = 262,                 /* PERCENT  */
    EQUAL = 263,                   /* EQUAL  */
    PERIOD = 264,                  /* PERIOD  */
    COMMA = 265,                   /* COMMA  */
    COLON = 266,                   /* COLON  */
    SEMICOLON = 267,               /* SEMICOLON  */
    LESSTHAN = 268,                /* LESSTHAN  */
    GREATERTHAN = 269,             /* GREATERTHAN  */
    LEFT_PARENTHESIS = 270,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 271,       /* RIGHT_PARENTHESIS  */
    LEFT_BLACKET = 272,            /* LEFT_BLACKET  */
    RIGHT_BLACKET = 273,           /* RIGHT_BLACKET  */
    LEFT_CURLY_BLACKET = 274,      /* LEFT_CURLY_BLACKET  */
    RIGHT_CURLY_BLACKET = 275,     /* RIGHT_CURLY_BLACKET  */
    EQUAL_EQUAL = 276,             /* EQUAL_EQUAL  */
    LESSTHAN_EQUAL = 277,          /* LESSTHAN_EQUAL  */
    GREATERTHAN_EQUAL = 278,       /* GREATERTHAN_EQUAL  */
    NOT_EQUAL = 279,               /* NOT_EQUAL  */
    PULS_EQUAL = 280,              /* PULS_EQUAL  */
    MINUS_EQUAL = 281,             /* MINUS_EQUAL  */
    ASTERISK_EQUAL = 282,          /* ASTERISK_EQUAL  */
    SLASH_EQUAL = 283,             /* SLASH_EQUAL  */
    NEWLINE = 284,                 /* NEWLINE  */
    KW_AND = 285,                  /* KW_AND  */
    KW_OR = 286,                   /* KW_OR  */
    KW_NOT = 287,                  /* KW_NOT  */
    KW_XOR = 288,                  /* KW_XOR  */
    KW_NAND = 289,                 /* KW_NAND  */
    LW_NOR = 290,                  /* LW_NOR  */
    KW_IMPORT = 291,               /* KW_IMPORT  */
    KW_FROM = 292,                 /* KW_FROM  */
    KW_AS = 293,                   /* KW_AS  */
    KW_CLASS = 294,                /* KW_CLASS  */
    KW_FUNCTION = 295,             /* KW_FUNCTION  */
    KW_CONSTRUCTOR = 296,          /* KW_CONSTRUCTOR  */
    KW_GETTER = 297,               /* KW_GETTER  */
    KW_SETTER = 298,               /* KW_SETTER  */
    KW_IF = 299,                   /* KW_IF  */
    KW_ELSE = 300,                 /* KW_ELSE  */
    KW_END = 301,                  /* KW_END  */
    KW_WHILE = 302,                /* KW_WHILE  */
    KW_UNTIL = 303,                /* KW_UNTIL  */
    KW_BREAK = 304,                /* KW_BREAK  */
    KW_RETURN = 305,               /* KW_RETURN  */
    INTEGER_LITERAL = 306          /* INTEGER_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

    AST ast;

#line 119 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
