CC = gcc
CFLAGS = -Wall 
SRCDIR = src
INCDIR = include
BINDIR = bin

# List of source files
SRC := $(wildcard $(SRCDIR)/*.c)

# List of object files
OBJ := $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# List of header files
INC := -I$(INCDIR)

# Output executable name
TARGET = run

$(BINDIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: run
run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

.PHONY: clean
clean:
	rm -f $(BINDIR)/*.o $(BINDIR)/$(TARGET)
