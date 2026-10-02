# A Makefile with variables and suffix rules
# ------------------------------------------
# variaveis
#----------
INCLUDES = size_string.h
SOURCES = size_string.c main.c
OBJFILES = size_string.o main.o
EXEC = ex10
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
