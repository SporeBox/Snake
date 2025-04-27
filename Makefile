CC = gcc
CFLAGS = -Wall -Wextra
INCLUDES = -I/usr/include/SDL2/
LIBS = -lSDL2 -lSDL2_image

# Proiecte
SNAKE_SRCS = snake.c
SNAKE_OBJS = $(SNAKE_SRCS:.c=.o)
SNAKE_BIN = snake

START_SRCS = start.c
START_OBJS = $(START_SRCS:.c=.o)
START_BIN = start

OVER_SRCS = gameOver.c
OVER_OBJS = $(OVER_SRCS:.c=.o)
OVER_BIN = over

WIN_SRCS = youWin.c
WIN_OBJS = $(WIN_SRCS:.c=.o)
WIN_BIN = win

# Ținta principală
all: $(SNAKE_BIN) $(START_BIN) $(OVER_BIN) $(WIN_BIN)

# Reguli de compilare
$(SNAKE_BIN): $(SNAKE_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(START_BIN): $(START_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(OVER_BIN): $(OVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(WIN_BIN): $(WIN_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

# Regulă generică pentru .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Curățare
clean:
	$(RM) *.o *~ $(SNAKE_BIN) $(START_BIN) $(OVER_BIN) $(WIN_BIN)
