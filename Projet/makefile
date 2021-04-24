all: main

debug: print all
	@sed -i 's/true/false/'g types.h

print:
	@sed -i 's/false/true/'g types.h

main: flex yacc compil parse clear

flex: ANSI-C.l
	@flex ANSI-C.l

yacc: miniC.y
	@yacc -d miniC.y

compil: lex.yy.c y.tab.c
	@gcc lex.yy.c y.tab.c -o try -lfl
	
parse: try
	@mkdir -p Résultats ./Résultats/Png;
	@$(foreach f, $(wildcard ./Tests/*.c), \
		echo "Fichier: " $f; \
		./try $(addsuffix $(addsuffix .dot,$(notdir $(basename $f))),Résultats/) < $f;)
	@$(foreach f, $(wildcard ./Résultats/*.dot), \
		dot -Tpng $f > ./Résultats/Png/$(notdir $(basename $f)).png;)
		
clear: y.tab.h y.tab.c lex.yy.c try
	@rm y.tab.h y.tab.c lex.yy.c try
	@echo Compilation reussie.
