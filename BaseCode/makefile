MODULE_NAME = cmdproc

# Paths
UNITY_ROOT = ..
SRC_FOLDER = src
TEST_FOLDER = test

# Commands
CLEANUP = rm -f
MKDIR = mkdir -p

#Compiler
C_COMPILER = gcc
CFLAGS=-std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TARGET=test$(MODULE_NAME)
SRC_FILES=$(UNITY_ROOT)/src/unity.c $(SRC_FOLDER)/$(MODULE_NAME).c  $(TEST_FOLDER)/test$(MODULE_NAME).c
INC_DIRS=-I$(SRC_FOLDER) -I$(UNITY_ROOT)/src
SYMBOLS=

all: clean default

.PHONY: clean

default: $(SRC_FILES)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET)	
	- ./$(TARGET)
	
clean:
	$(CLEANUP) $(TARGET)
	