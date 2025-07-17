# $@ = target of the rule (thing you're building)
# $^ = all prerequisites (dependencies)
# $< = first prerequisite

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude -MMD -MP

# Directories
SRC_DIR = src/tools
OBJ_DIR = obj/tools
BIN_DIR = bin
INC_DIR = include

# Tool source files (assumes src/tools/my_ls.c, etc.)
TOOLS = my_ls #my_cat my_cp my_grep

# Construct full paths
SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(TOOLS)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(TOOLS)))
BINS = $(addprefix $(BIN_DIR)/, $(TOOLS))
DEPS = $(OBJS:.o=.d)

# Default target: build all tools
all: setup $(BINS)

# Link each binary from its object file
$(BIN_DIR)/%: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile each source to object
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin/ and obj/ if not present
setup:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Remove build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Include auto-generated header dependencies
-include $(DEPS)
