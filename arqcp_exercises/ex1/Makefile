INCLUDES = program_functions.h
SOUCES = func1.c func2.c main.c
OBJFILES = func1.o func2.o main.o
EXEC = program

.SUFFIXES: .c .o
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
# #####
