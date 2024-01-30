src=main.c
TARGET=test
OBJ=-lmyAVLTree -lmyQueue -lmyLinkList
${TARGET}:${src}
	gcc ${src} -o ${TARGET} ${OBJ}


libsrc=myAVLTree.c
LIBTARGET=libmyAVLTree.so

${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}

.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET}
install:                  
	sudo cp ${LIBTARGET} /usr/lib/
	sudo cp myAVLTree.h /usr/include/