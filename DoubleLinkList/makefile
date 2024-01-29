src=main.c
TARGET=test
${TARGET}:${src}
	gcc ${src} -o ${TARGET} -lmyLinkList

libsrc=myLinkList.c
LIBTARGET=libmyLinkList.so
${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}

.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET}

install:                  
	sudo cp ${LIBTARGET} /usr/lib
	sudo cp myLinkList.h /usr/include/
