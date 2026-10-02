# A Makefile with variables and suffix rules
# ------------------------------------------
# variaveis
#----------
INCLUDES = myFunctions.h
SOURCES = myFunctions.c main.c
OBJFILES = myFunctions.o main.o
EXEC = ex15
# Suffix rules
#--------------
.SUFFIXES : .c .o
.c.o:
	gcc -g -Wall -Wextra -fanalyzer -c $<

${EXEC}: ${OBJFILES}
	gcc ${OBJFILES} -o ${EXEC}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}
# EOF #
#######
