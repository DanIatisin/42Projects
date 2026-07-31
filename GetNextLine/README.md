*This project has been created as part of the 42 curriculum by diatisin.*
# Get Next Line

Project from the 42 Network common core, whose goal is to write a function that reads and returns, one at a time, the lines of a file or file descriptor, regardless of the file's content (plain text, binary file, standard input, etc.).

## Description

`get_next_line` is a function that, on each call, returns the next line read from a file descriptor, including the trailing newline character (`\n`) if present. It is designed to be called repeatedly on the same fd, keeping state between calls through the use of **static variables**.

This allows a file to be read line by line without having to load it entirely into memory.

## Project Goals

- Understand the use of **static** variables in C
- Efficiently manage **buffered** reading (the `read` system call)
- Correctly handle **dynamic memory allocation** (avoiding leaks)
- Work with different types of file descriptors (files, stdin, pipes...)

## How It Works

The function reads the file in chunks of size `BUFFER_SIZE` (defined at compile time via the `-D` flag) and accumulates the content read in a static buffer, until it finds a newline character or reaches the end of the file (EOF).

**Prototype:**

```c
char *get_next_line(int fd);
```

**Behavior:**

| Case | Return value |
|------|-------------------|
| Successful read | The line read (including `\n` if present) |
| End of file (no more lines) | `NULL` |
| Error (negative fd, `read` error, etc.) | `NULL` |

## Project Files

```
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
└── get_next_line_bonus.h
```

## Compilation

The function has no `main`, so it must be compiled together with the file that calls it, specifying the buffer size with the `-D` flag:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

For the bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## Bonus Part

The bonus version extends the base function with the following features:

1. **Handling multiple file descriptors at the same time**
   It is possible to read from several fds in parallel (for example alternating calls on `fd1` and `fd2`) without the reads interfering with each other; each fd keeps its own independent read state.

2. **A single static variable**
   Unlike the mandatory version (which may use several static variables), the bonus requires the use of **a single static variable**, typically an array or a linked list indexed by fd, which stores the "leftover" not yet returned for each file descriptor.

3. **Shared helper functions**
   The utility functions (`ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_strdup`, etc.) are the same as in the mandatory part, reused in the bonus as well.

**Example with multiple fds:**

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);
char *line1_bis = get_next_line(fd1); // correctly continues reading from fd1
```

## Recommended Test Cases

- Empty file
- File with a single line and no trailing `\n`
- File with very long lines (larger than `BUFFER_SIZE`)
- Binary file
- Reading from `stdin` (fd 0)
- `BUFFER_SIZE` with extreme values (1, 9999999)
- Negative or invalid `fd`
- Multiple, alternating reads on several fds (bonus)
- Checking for memory leaks with `valgrind`

## AI usage
The ai was used to explain in detail the subject also to do some debbuging and tests.