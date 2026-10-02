# A Makefile with variables and suffix rules
# ------------------------------------------
# variaveis
#----------
INCLUDES = average.h
SOURCES = average.c main.c
OBJFILES = average.o main.o
EXEC = ex09
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
