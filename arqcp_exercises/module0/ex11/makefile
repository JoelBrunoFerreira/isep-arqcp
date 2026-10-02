# A Makefile with variables and suffix rules
# ------------------------------------------
# variaveis
#----------
INCLUDES = convert.h
SOURCES = convert.c main.c
OBJFILES = convert.o main.o
EXEC = ex11
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
