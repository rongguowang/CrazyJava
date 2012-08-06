CC = gcc
CFLAGS = -g
OFLAGS = -o
IFLAGS = -I
LFLAGS = -L

SRCDIR = ./
BINDIR = ../bin/
LIBS = -lglut

.c:
	$(CC)  $(CFLAGS) $@.c $(LIBS) $(OFLAGS) $(BINDIR)$@
tags:
	rm -rf $(SRCDIR)TAGS
	find . -name *.c -print |xargs etags -o $(SRCDIR)TAGS
clean:
	rm -rf *~
	rm -rf  $(SRCDIR)*~ $(SRCDIR)*.o
	rm -rf $(TARDIR)$(TARGET)

.PHONY:tags exec clean all
