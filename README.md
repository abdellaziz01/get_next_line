*This project has been created as part of the 42 curriculum by abdait-o*
# get_next_line
## Description

**Get Next Line** is a 42 project where I had to create a function that reads a file one line at a time.

Through this project, I learned more about reading files in C, working with file descriptors, and managing memory using `malloc` and `free`. I also learned how to use a static variable to keep data between function calls.

The `get_next_line()` function reads from a file descriptor and returns one line each time it is called. If there is a newline (`\n`), it is included in the returned line. Any remaining data is saved and used during the next call.

For the bonus part, I added support for reading from multiple file descriptors at the same time, while keeping the data of each one separate.

## Instructions
### Installation

To use this function in another project, first clone the repository:

```bash
git clone <repository-url>
```

Then, include the `get_next_line.h` or `get_next_line_bonus.h` header file in your source file:

```c
#include "get_next_line.h"
#include "get_next_line_bonus.h"
```

### Compilation

To compile the project, run the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

For the bonus part, compile the bonus files instead:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

You can change the `BUFFER_SIZE` value to test the function with different buffer sizes.

### Execution

After compiling, run the program:

```bash
./a.out
```

Make sure to provide a valid file descriptor to `get_next_line()`. The function returns one line at a time, and you can call it again to read the next line until it returns `NULL`.

## Resources

### References
this project, I used different resources to understand how file reading and memory management work in C:
- **42 Get Next Line Subject:** To understand the project requirements and the expected behavior of the function.
- **Linux Manual Pages:** To learn more about `read()`, `malloc()`, and `free()`.
- **YouTube Tutorials:**: https://www.youtube.com/@nesoacademy
- Discussions and explanations with peers.
### AI Usage

When I encounter a problem in C or need to understand a new concept, I first ask my peers for help and try to develop a general understanding of the problem myself. After that, I may look for information online or use AI tools to get some guidance and explore possible solutions.

I do not rely entirely on AI, as understanding the code and solving problems independently are important parts of my learning process. After completing my code, and once I have already sought help from my peers, I may also use AI to review it, identify potential errors, and check whether anything could be improved. My main goal is to learn, understand my mistakes, and improve my programming skills rather than simply rely on AI-generated solutions.

## Algorithm

The algorithm works as follows:

1. **Reading:** The function reads data from the file descriptor using `read()` with the specified `BUFFER_SIZE`.
2. **Storing data:** The newly read data is joined with the data already stored in the static variable using `ft_strjoin()`.
3. **Searching for a newline:** After each read, the function checks whether a newline character (`\n`) exists in the stored data.
4. **Returning a line:** When a newline is found, the function extracts the line and returns it.
5. **Keeping remaining data:** Any data after the newline is saved in the static variable for the next function call.
6. **End of file:** If the end of the file is reached, the function returns the remaining data if there is any. Otherwise, it returns `NULL`.

### Why I chose this algorithm

I chose this approach because it allows me to read files line by line without loading the entire file into memory.

Using a static variable makes it possible to preserve unread data between function calls, while `BUFFER_SIZE` controls how much data is read at a time.

For the bonus part, I used an array of static pointers indexed by the file descriptor. This allows the function to manage multiple files at the same time, keeping the remaining data of each file separate.