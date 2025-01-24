# Compiler
CC = gcc

# Executable names
TARGETS = add_function fork_programm kill_programm pipe_programm write_pids

# Source files
SRCS = add_function.c fork_programm.c kill_programm.c pipe_programm.c write_pids.c

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Default target to build all executables
all: $(TARGETS)

# Build each executable from its corresponding source file
add_function: add_function.c
	$(CC) $(CFLAGS) -o add_function add_function.c

fork_programm: fork_programm.c
	$(CC) $(CFLAGS) -o fork_programm fork_programm.c

kill_programm: kill_programm.c
	$(CC) $(CFLAGS) -o kill_programm kill_programm.c

pipe_programm: pipe_programm.c
	$(CC) $(CFLAGS) -o pipe_programm pipe_programm.c

write_pids: write_pids.c
	$(CC) $(CFLAGS) -o write_pids write_pids.c

# Clean up generated files
clean:
	rm -f $(TARGETS) a.out
