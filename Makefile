CC = gcc

CFLAGS = -Wall

LIB =

INCLUDE = -Iinclude/

SRC_DIR = ./src
OBJ_DIR = ./obj

TARGET = main

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: main

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MD

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)
