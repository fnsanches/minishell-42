CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = minishell
OBJS = minishell.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lreadline

clean:
	rm -f $(TARGET) $(OBJS)