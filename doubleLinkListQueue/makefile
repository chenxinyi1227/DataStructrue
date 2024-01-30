src=main.c
TARGET=test
${TARGET}:${src}
	gcc ${src} -o ${TARGET} -lmyQueue -lmyLinkList


libsrc=myQueue.c
LIBTARGET=libmyQueue.so

${LIBTARGET}:${libsrc}
	gcc -shared -fPIC ${libsrc} -o ${LIBTARGET}
	
.PHONY:all clean install

all:${TARGET} ${LIBTARGET}

clean:
	rm -f ${TARGET} ${LIBTARGET} *.o

install:                  
	sudo cp ${LIBTARGET} /usr/lib
	sudo cp myQueue.h /usr/include/

# OBJS=$(patsubst %.c, %.o, $(wildcard ./*.c))
# TARGET=libmyQueue.so

# $(TARGET):$(OBJS)
# 	$(CC) -shared -fPIC $^ -o $@
# #	发布
# 	cp $(TARGET) /usr/lib/
# 	cp myQueue.h /usr/include/
# %.o:%.c
# 	$(CC) -c $^ -o $@

# clean:
# 	$(RM) $(OBJS) $(TARGET)
# 	$(RM) /usr/lib/$(TARGET)