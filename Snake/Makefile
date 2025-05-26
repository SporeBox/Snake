CC = gcc
CFLAGS = -Wall -Wextra
INCLUDES = -I/usr/include/SDL2/
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

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

MP_SRCS = multiPlayer.c
MP_OBJS = $(MP_SRCS:.c=.o)
MP_BIN = snakeMp

P1W_SRCS = p1w.c
P1W_OBJS = $(P1W_SRCS:.c=.o)
P1W_BIN = p1w

P2W_SRCS = p2w.c
P2W_OBJS = $(P2W_SRCS:.c=.o)
P2W_BIN = p2w

TIE_SRCS = tie.c
TIE_OBJS = $(TIE_SRCS:.c=.o)
TIE_BIN = tie

all: $(SNAKE_BIN) $(START_BIN) $(OVER_BIN) $(WIN_BIN) $(MP_BIN) $(P1W_BIN) $(P2W_BIN) $(TIE_BIN)

$(SNAKE_BIN): $(SNAKE_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(START_BIN): $(START_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)


$(OVER_BIN): $(OVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(WIN_BIN): $(WIN_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(MP_BIN): $(MP_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(P1W_BIN): $(P1W_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(P2W_BIN): $(P2W_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

$(TIE_BIN): $(TIE_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(SNAKE_BIN) $(START_BIN) $(OVER_BIN) $(WIN_BIN) $(MP_BIN) $(P1W_BIN) $(P2W_BIN) $(TIE_BIN)
