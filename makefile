CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TARGET_NAME = run
TARGET = $(BIN_DIR)/$(TARGET_NAME)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))


all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $@"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	@rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

