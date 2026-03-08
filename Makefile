CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -g
SRC_DIR := src
INC_DIR := include
TEST_DIR := tests
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin

SRC_FILES := $(SRC_DIR)/mystring.c
OBJ_FILES := $(BUILD_DIR)/mystring.o
TEST_FILES := $(wildcard $(TEST_DIR)/test_*.c)
TEST_NAMES := $(basename $(notdir $(TEST_FILES)))
TEST_BIN := $(addprefix $(BIN_DIR)/,$(TEST_NAMES))

.PHONY: all tests run-tests run-test clean help

all: tests

$(BUILD_DIR):
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

$(BIN_DIR):
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJ_FILES) | $(BIN_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $< $(OBJ_FILES) -o $@

tests: $(TEST_BIN)

run-tests: tests
	@powershell -NoProfile -Command "Get-ChildItem 'build\bin' -Filter 'test_*.exe' | ForEach-Object { Write-Host ''; Write-Host ('Running: ' + $$_.Name); Write-Host '----------------------------------------'; & $$_.FullName }"

run-test: $(OBJ_FILES) | $(BIN_DIR)
	@if "$(TEST)"=="" (echo Usage: make run-test TEST=test_name) else ($(CC) $(CFLAGS) -I$(INC_DIR) $(TEST_DIR)/$(TEST).c $(OBJ_FILES) -o $(BIN_DIR)/$(TEST) & $(BIN_DIR)/$(TEST))

clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"

help:
	@echo.
	@echo C String Library
	@echo.
	@echo make run-tests       Run all tests
	@echo make run-test        Run specific test (TEST=name)
	@echo make tests           Build all tests
	@echo make clean           Remove build files
	@echo.


