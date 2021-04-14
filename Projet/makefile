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
	@mkdir -p Résultats;
	@for file in ./Tests/*.c; do \
		echo "Fichier: " $${file}; \
		./try < $${file}; \
	done
		
clear: y.tab.h y.tab.c lex.yy.c try
	@rm y.tab.h y.tab.c lex.yy.c try
	$(info --------------------------------------> Compilation reussie.)



