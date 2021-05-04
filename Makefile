CXX := g++

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := build

EXE := $(BIN_DIR)/cc3k
SRC := $(wildcard $(SRC_DIR)/*.cc)
OBJ := $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

CPPFLAGS := -std=c++14 -Wextra -Wpedantic -Wall -MMD -g -Werror=vla -Iinclude
CFLAGS   := -Wall

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
