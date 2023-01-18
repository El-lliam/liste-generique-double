# project name (generate executable with this name)
TARGET = run


CC = gcc


# change these to proper directories where each file should be
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCLDIR = include


# compiling flags here
CFLAGS = -std=c99 -Wall -I$(INCLDIR)

# linking flags here
LFLAGS = -Wall -I$(INCLDIR) -lm

SOURCES  = $(wildcard $(SRCDIR)/*.c)
INCLUDES = $(wildcard $(INCLDIR)/*.h)

OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))


.PHONY: run clean delete

run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

clean: $(OBJECTS)
	rm -rf $(OBJDIR)/$(OBJECTS)

delete: $(BINDIR)/$(TARGET)
	rm -rf $(BINDIR)/$(TARGET)


$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) -o $@
    

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
