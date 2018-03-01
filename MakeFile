CC=gcc
CFLAGS = o
FILES = expr.c parserRD.c parserTD.c parseTree.c calculator.c
OUTPUT = expr

make : $(FILES)
	$(CC) -$(CFLAGS) $(OUTPUT) $(FILES)

run :
	./$(OUTPUT)

clean :
	rm $(OUTPUT)

run-clean : $(FILES)
	$(CC) -$(CFLAGS) $(OUTPUT) $(FILES)
	./$(OUTPUT)
	rm $(OUTPUT)
