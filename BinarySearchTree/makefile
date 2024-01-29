src=main.c
TARGET=test
${TARGET}:${src}
	gcc ${src} -o ${TARGET} -lmyBST


libsrc=$(patsubst %.c,%.o, $(wildcard ./*.c))
LIBTARGET=libmyBST.so

${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}

%.o:%.c
	${CC} -c $^ -o $@
	
.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET} *.o

install:                  
	sudo cp ${LIBTARGET} /usr/lib
	sudo cp myBST.h /usr/include/