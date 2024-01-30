src=*.c
TARGET=test
${TARGET}:${src}
	gcc ${src} -o ${TARGET} -lmyArray

libsrc=myArray.c
LIBTARGET=libmyArray.so
${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}

.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET}

install:                  
	sudo cp ${LIBTARGET} /usr/lib
	sudo cp myArray.h /usr/include/
