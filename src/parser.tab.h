/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PULS = 258,
     MINUS = 259,
     ASTERISK = 260,
     SLASH = 261,
     PERCENT = 262,
     EQUAL = 263,
     PERIOD = 264,
     COMMA = 265,
     COLON = 266,
     SEMICOLON = 267,
     LESSTHAN = 268,
     GREATERTHAN = 269,
     LEFT_PARENTHESIS = 270,
     RIGHT_PARENTHESIS = 271,
     LEFT_BLACKET = 272,
     RIGHT_BLACKET = 273,
     LEFT_CURLY_BLACKET = 274,
     RIGHT_CURLY_BLACKET = 275,
     EQUAL_EQUAL = 276,
     LESSTHAN_EQUAL = 277,
     GREATERTHAN_EQUAL = 278,
     NOT_EQUAL = 279,
     PULS_EQUAL = 280,
     MINUS_EQUAL = 281,
     ASTERISK_EQUAL = 282,
     SLASH_EQUAL = 283,
     NEWLINE = 284,
     KW_AND = 285,
     KW_OR = 286,
     KW_NOT = 287,
     KW_XOR = 288,
     KW_NAND = 289,
     LW_NOR = 290,
     KW_IMPORT = 291,
     KW_FROM = 292,
     KW_AS = 293,
     KW_CLASS = 294,
     KW_FUNCTION = 295,
     KW_CONSTRUCTOR = 296,
     KW_GETTER = 297,
     KW_SETTER = 298,
     KW_IF = 299,
     KW_ELSE = 300,
     KW_END = 301,
     KW_WHILE = 302,
     KW_UNTIL = 303,
     KW_BREAK = 304,
     KW_RETURN = 305,
     INTEGER_LITERAL = 306,
     FLOAT_LITERAL = 307,
     BOOL_LITERAL = 308,
     NIL_LITERAL = 309,
     STRING_LITERAL = 310,
     IDENTIFIER = 311
   };
#endif
/* Tokens.  */
#define PULS 258
#define MINUS 259
#define ASTERISK 260
#define SLASH 261
#define PERCENT 262
#define EQUAL 263
#define PERIOD 264
#define COMMA 265
#define COLON 266
#define SEMICOLON 267
#define LESSTHAN 268
#define GREATERTHAN 269
#define LEFT_PARENTHESIS 270
#define RIGHT_PARENTHESIS 271
#define LEFT_BLACKET 272
#define RIGHT_BLACKET 273
#define LEFT_CURLY_BLACKET 274
#define RIGHT_CURLY_BLACKET 275
#define EQUAL_EQUAL 276
#define LESSTHAN_EQUAL 277
#define GREATERTHAN_EQUAL 278
#define NOT_EQUAL 279
#define PULS_EQUAL 280
#define MINUS_EQUAL 281
#define ASTERISK_EQUAL 282
#define SLASH_EQUAL 283
#define NEWLINE 284
#define KW_AND 285
#define KW_OR 286
#define KW_NOT 287
#define KW_XOR 288
#define KW_NAND 289
#define LW_NOR 290
#define KW_IMPORT 291
#define KW_FROM 292
#define KW_AS 293
#define KW_CLASS 294
#define KW_FUNCTION 295
#define KW_CONSTRUCTOR 296
#define KW_GETTER 297
#define KW_SETTER 298
#define KW_IF 299
#define KW_ELSE 300
#define KW_END 301
#define KW_WHILE 302
#define KW_UNTIL 303
#define KW_BREAK 304
#define KW_RETURN 305
#define INTEGER_LITERAL 306
#define FLOAT_LITERAL 307
#define BOOL_LITERAL 308
#define NIL_LITERAL 309
#define STRING_LITERAL 310
#define IDENTIFIER 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "parser.y"
{
    AST_node ast;
}
/* Line 1529 of yacc.c.  */
#line 165 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

