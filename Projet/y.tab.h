/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    VOID = 259,
    IDENTIFICATEUR = 260,
    CONSTANTE = 261,
    PLUS = 262,
    MOINS = 263,
    MUL = 264,
    DIV = 265,
    LSHIFT = 266,
    RSHIFT = 267,
    BAND = 268,
    BOR = 269,
    LT = 270,
    GT = 271,
    GEQ = 272,
    LEQ = 273,
    EQ = 274,
    NEQ = 275,
    NOT = 276,
    LAND = 277,
    LOR = 278,
    EXTERN = 279,
    RETURN = 280,
    BREAK = 281,
    ELSE = 282,
    FOR = 283,
    WHILE = 284,
    IF = 285,
    SWITCH = 286,
    CASE = 287,
    DEFAULT = 288,
    THEN = 289,
    moins = 290,
    REL = 291
  };
#endif
/* Tokens.  */
#define INT 258
#define VOID 259
#define IDENTIFICATEUR 260
#define CONSTANTE 261
#define PLUS 262
#define MOINS 263
#define MUL 264
#define DIV 265
#define LSHIFT 266
#define RSHIFT 267
#define BAND 268
#define BOR 269
#define LT 270
#define GT 271
#define GEQ 272
#define LEQ 273
#define EQ 274
#define NEQ 275
#define NOT 276
#define LAND 277
#define LOR 278
#define EXTERN 279
#define RETURN 280
#define BREAK 281
#define ELSE 282
#define FOR 283
#define WHILE 284
#define IF 285
#define SWITCH 286
#define CASE 287
#define DEFAULT 288
#define THEN 289
#define moins 290
#define REL 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "miniC.y"

	char* type;
	char* identificateur;
	int constante;
	bool boolean;
	char* binary_op;
	char* binary_rel;
	char* binary_comp;
	char* selection_nom;
	
	parm_t parm;
	liste_parms_t liste_parms;
	declarateur_t declarateur;
	liste_declarateurs_t liste_declarateurs;
	declaration_t declaration;
	liste_declarations_t liste_declarations;
	variable_t variable;
	liste_expressions_t liste_expressions;
	expression_t expression;
	condition_t condition;
	appel_t appel;
	affectation_t affectation;
	saut_t saut;
	bloc_t bloc;
	selection_t selection;
	instruction_t instruction;
	liste_instructions_t liste_instructions;
	iteration_t iteration;
	fonction_t fonction;
	liste_fonctions_t liste_fonctions;
	programme_t programme;

#line 162 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
