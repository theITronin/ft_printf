*This project has been created as part of the 42 curriculum by dbustama*
 
# ft_printf
 
## Description
 
ft_printf is a 42 project whose goal is to re-implement the libc function `printf()`. The result is a static library, `libftprintf.a`, that exposes the function `ft_printf`. Along the way, the project teaches how **variadic functions** work in C (`va_list`, `va_start`, `va_arg`, `va_copy`, `va_end`).
 
```c
int ft_printf(char const *format, ...);
```
 
### Behavior summary
 
- Writes the formatted output to the standard output and returns the number of characters, like the original `printf()`.
- The buffer management of the original `printf()` is **not** implemented.
- Allowed external functions: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
- The use of `libft` is allowed. The library must be created with `ar` (`libtool` is forbidden).
### Supported conversions
 
| Conversion | Description                                              |
|------------|----------------------------------------------------------|
| `%c`       | Prints a single character.                               |
| `%s`       | Prints a string (`(null)` if the pointer is `NULL`).     |
| `%p`       | Prints a `void *` pointer in hexadecimal (`0x` prefix).  |
| `%d`       | Prints a signed decimal number (base 10).                |
| `%i`       | Prints a signed integer (base 10).                       |
| `%u`       | Prints an unsigned decimal number (base 10).             |
| `%x`       | Prints a hexadecimal number (base 16) in lowercase.      |
| `%X`       | Prints a hexadecimal number (base 16) in uppercase.      |
| `%%`       | Prints a percent sign.                                   |
 
### Files
 
| Part      | Files                                                                    |
|-----------|--------------------------------------------------------------------------|
| Mandatory | `Makefile`, `ft_printf.h`, `ft_printf.c` and the helper `*.c` files      |
| Library   | `libftprintf.a` (generated in the root of the repository)                |
 
## Instructions
 
### Compilation
 
The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`. The `Makefile` provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`, and does not relink.
 
```bash
make        # builds libftprintf.a in the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # fclean + all
```
 
### Usage
 
Include the header in your code and link the library:
 
```c
#include "ft_printf.h"
 
int main(void)
{
	int	len;
 
	len = ft_printf("Hello %s! %d + %i = %u\n", "42", 1, 2, 3);
	ft_printf("Hex: %x %X | Ptr: %p | Percent: %%\n", 255, 255, &len);
	ft_printf("Printed %d characters\n", len);
	return (0);
}
```
 
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```
 
`main.c` is just a personal test program; it is not part of the delivered work.
 
### Recommended tests
 
- Compare the output **and the return value** of `ft_printf` against the original `printf` for every conversion.
- Edge values: `INT_MIN`, `INT_MAX`, `0`, `UINT_MAX`, `LONG_MIN`, `LONG_MAX`.
- `NULL` string (`%s`) and `NULL` pointer (`%p`).
- Empty format string, format string ending with a single `%`, consecutive conversions (`%d%s%c`).
- Memory leaks (e.g. with `valgrind`).
## Algorithm: explanation and justification
 
### Explanation
 
`ft_printf` walks through the format string one character at a time while keeping a `va_list` with the variadic arguments:
 
1. **Initialization.** `va_start` initializes the argument list and a counter of printed characters is set to `0`.
2. **Parsing.** For each character of the format string:
   - If it is not `%`, it is written directly with `write` and the counter is incremented.
   - If it is `%`, the next character is read and sent to a **dispatcher** that selects the right conversion function (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`). The next argument is fetched with `va_arg` using the type that corresponds to the conversion.
3. **Conversions.** Each conversion function writes its output and returns the number of characters written.
   - Numbers are printed **recursively**: the number is divided by the base until it fits in one digit, and digits are written on the way back. This avoids any dynamic allocation or temporary buffer.
   - `%d` / `%i` handle the sign and the special case of `INT_MIN` by working with a wider type (`long`).
   - `%u`, `%x` and `%X` use `unsigned int` and a base string (`"0123456789abcdef"` or `"0123456789ABCDEF"`).
   - `%p` casts the pointer to `unsigned long` and prints it in hexadecimal with the `0x` prefix (`(nil)` for a `NULL` pointer, as the original does on Linux).
   - `%s` prints `(null)` when the string is `NULL`.
4. **End.** `va_end` releases the argument list and the total number of printed characters is returned.
### Justification
 
- **Dispatcher over a chain of `if`s.** Selecting the conversion in a single function keeps `ft_printf` short and readable, and adding a new conversion (or a bonus flag) only requires adding one case and one helper. This matches the subject's advice of having well structured and extensible code.
- **Writing directly with `write`.** The subject forbids implementing the buffer management of `printf`, so each piece of output is written as soon as it is produced. It is simple and the order of the output is always correct, at the cost of more system calls.
- **Recursion instead of `malloc`.** Printing numbers recursively needs no heap memory, so there are no leaks and no allocation failures to handle.
- **One helper per conversion, returning the printed length.** Every helper returns the number of characters written, so the total length is just the sum of the returns, and an error can be propagated immediately.
- **Wider types where needed.** Using `long` for signed numbers and `unsigned long` for pointers avoids overflow in `INT_MIN` and ensures that 64-bit addresses are printed correctly.
- **Trade-off.** Calling `write` once per character is slower than building a buffer, but it is the behavior asked by the subject and keeps the implementation robust and easy to verify.
## Resources
 
### References
 
- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- `man 3 va_start`, `man 3 va_arg`, `man 3 va_copy`, `man 3 va_end`
- C99 Language Specification (variadic functions)
- 42 Norm guidelines
- Discussions with other 42 students (peer learning) and peer evaluations
### Use of AI
 
In compliance with the 42 curriculum guidelines regarding artificial intelligence usage:
 
- **Approach:** AI was used to draft the structure and wording of this `README.md` and as a conceptual reference tool for clarifying the standard behavior of `printf` (edge cases such as `%p` with `NULL` or `INT_MIN`).
- **Implementation:** No direct code solutions or automatic code generators were used to write the library functions. Fundamental reasoning and peer discussions were prioritized to build the project.
