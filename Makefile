TARGET=test

SRC=test.o

CC=gcc

${TARGET}:${SRC}
	@${CC} $^ -o $@

clean:
	@rm ${SRC} ${TARGET}
