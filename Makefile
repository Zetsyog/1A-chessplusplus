CC=g++
CFLAGS=-std=c++11 -Wall -g #-DDEBUG

TARGET=echecs
BINDIR=bin
SRCDIR=src
INCLUDEDIR=include
OBJDIR=build

SOURCES  := $(wildcard $(SRCDIR)/**/*.cc) $(wildcard $(SRCDIR)/*.cc)
INCLUDES := $(wildcard $(INCLUDE_PATH)/**/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TRAGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJ)  -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cc
	mkdir -p $(dir $@)
	$(CC) -g -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)

clean:
	rm $(BINDIR)/$(TARGET)
	rm -rf $(OBJDIR)/*
