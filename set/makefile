src=main.c
TARGET=test
OBJ=-lmySet -lmyAVLTree -lmyQueue -lmyLinkList
${TARGET}:${src}
	gcc ${src} -o ${TARGET} ${OBJ}


libsrc=mySet.c
LIBTARGET=libmySet.so

${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}

.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET}
install:                  
	sudo cp ${LIBTARGET} /usr/lib/
	sudo cp mySet.h /usr/include/