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

#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
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
    FOR = 258,
    WHILE = 259,
    INT = 260,
    VOID = 261,
    IDENTIFICATEUR = 262,
    CONSTANTE = 263,
    PLUS = 264,
    MOINS = 265,
    MUL = 266,
    DIV = 267,
    LSHIFT = 268,
    RSHIFT = 269,
    BAND = 270,
    BOR = 271,
    LT = 272,
    GT = 273,
    GEQ = 274,
    LEQ = 275,
    EQ = 276,
    NEQ = 277,
    NOT = 278,
    LAND = 279,
    LOR = 280,
    EXTERN = 281,
    RETURN = 282,
    BREAK = 283,
    ELSE = 284,
    CASE = 285,
    DEFAULT = 286,
    IF = 287,
    SWITCH = 288,
    END_OF_FILE = 289,
    THEN = 290,
    OP = 291,
    REL = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "miniC.y"

	char* type;
	char* identificateur;
	int constante;
	bool boolean;
	char* binary_op;
	char* binary_rel;
	char* binary_comp;
	char* switch_case;
	char* selection_type;
	
	struct parm_t parm;
	struct liste_parms_t liste_parms;
	struct declarateur_t declarateur;
	struct liste_declarateurs_t liste_declarateurs;
	struct declaration_t declaration;
	struct liste_declarations_t liste_declarations;
	struct variable_t variable;
	struct liste_expressions_t liste_expressions;
	struct expression_t expression;
	struct condition_t* condition;
	struct appel_t* appel;
	struct affectation_t* affectation;
	struct saut_t* saut;
	struct bloc_t* bloc;
	struct selection_t* selection;
	struct instruction_t instruction;
	struct liste_instructions_t liste_instructions;
	struct iteration_t* iteration;
	struct fonction_t fonction;
	struct liste_fonctions_t liste_fonctions;
	struct programme_t programme;

#line 129 "miniC.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */
