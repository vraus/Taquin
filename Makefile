CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

EXECUTABLE = main

all: clean $(EXECUTABLE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)

.PHONY: clean all
