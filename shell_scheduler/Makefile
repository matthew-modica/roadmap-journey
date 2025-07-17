# $@ = target of the rule (thing you're building)
# $^ = All prequisites of the rule
# $< = First prerequisite of the rule
# subst = $(subst find, replacement, source_text)
# patsubst = $(patsubst pattern, replacement, source_text)
# $(expression) = return the value of variable or expression
# $(OBJS:.o=.d) = replace .o with .d from each string in OBJS

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude -MMD -MP

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Binary name
TARGET = $(BIN_DIR)/main

# Source and object file paths
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# subst: Replace SRC_DIR/ (src/) with empty string from each .c path, i.e. strip src/ from each .c path | ex. src/tools/shell.c becomes tools/shell.c
# patsubst: Replace all files something.c with obj/something.o from the src files stripped of src/ | ex. tools/shell.c becomes obj/tools/shell.o
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRCS)))

# Generate dependency files (.d)
DEPS = $(OBJS:.o=.d)

# Default build target
all: setup $(TARGET)

# Link object files into the final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c → .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build folders if they don't exist
setup:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

-include $(DEPS)
