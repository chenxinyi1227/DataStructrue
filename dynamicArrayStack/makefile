src=main.c
TARGET=test
OBJ=-lmyStack -lmyArray
${TARGET}:${src}
	gcc ${src} -o ${TARGET} ${OBJ}


libsrc=myStack.c
LIBTARGET=libmyStack.so

${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}
	
.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET} *.o

install:                  
	sudo cp ${LIBTARGET} /usr/lib
	sudo cp myStack.h /usr/include/