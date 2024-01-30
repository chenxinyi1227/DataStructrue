src=main.c
TARGET=test
OBJ=-lmyBSTree -lmyQueue -lmyLinkList
${TARGET}:${src}
	gcc ${src} -o ${TARGET} ${OBJ}

libsrc=myBSTree.c
LIBTARGET=libmyBSTree.so

${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}

.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET}

install:                  
	sudo cp ${LIBTARGET} /usr/lib
	sudo cp myBSTree.h /usr/include/