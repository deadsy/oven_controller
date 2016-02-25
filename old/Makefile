
OUT = oven_controller

SRC = logger.c \
      hal.c \
      main.c \
      program.c \

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

CFLAGS = -Wall -Wextra -Wstrict-prototypes
CFLAGS += -Werror

LDFLAGS =

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	-rm $(OBJ)
	-rm $(OUT)
