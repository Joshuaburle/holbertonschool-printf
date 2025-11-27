_printf

Simple reimplementation of a subset of the C library function printf(3).

This project provides a minimal `_printf` function that supports a small set
of conversion specifiers and is implemented using a dispatch table and a
custom `_putchar` helper. The documentation below describes how to build
and use the program, what is implemented, and how to view the bundled man
page.

## Build

Compile with GCC (the project uses C89/GNU extensions by default):

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o _printf
```

## Requirements

- POSIX-compatible system (Linux/macOS)
- GCC (or compatible C compiler)
 

## Supported conversion specifiers

This implementation supports the following conversion specifiers:

- `%c` — print a single character
- `%s` — print a NUL-terminated string (prints `(null)` when a NULL pointer is given)
- `%d`, `%i` — print a signed decimal integer (handles `INT_MIN`)
- `%%` — print a literal percent sign

Unknown specifiers are printed as a percent sign followed by the unknown
character (for example, `"%q"` prints `%q`). If the format string is
NULL, `_printf` returns `-1`. A trailing single `%` at the end of the
format string is considered an error and causes `-1` to be returned.

## Behaviour and return value

On success `_printf` returns the number of characters written to standard
output. On error (for example, when `format` is `NULL`, or the format
string ends with an unmatched `%`) the function returns `-1`.

String printing: when a `NULL` pointer is passed for `%s`, this
implementation writes the literal `(null)` (6 characters).

Integer printing: signed integers are printed correctly. `INT_MIN` is
handled specially to avoid overflow when negating.

## Examples

Example 1 — character:

```c
_printf("I'm the letter: %c\n", 'A');
/* Output: I'm the letter: A */
```

Example 2 — string:

```c
_printf("I'm a %s!\n", "string");
/* Output: I'm a string! */
```

Example 3 — percent sign:

```c
_printf("Progress: 100%%\n");
/* Output: Progress: 100% */
```

Example 4 — integer:

```c
_printf("Number: %d\n", 123);
/* Output: Number: 123 */
```

Example 5 — NULL string handling:

```c
_printf("Null: %s\n", NULL);
/* Output: Null: (null) */
```

Example 6 — unknown specifier:

```c
_printf("Unknown: %q\n");
/* Output: Unknown: %q */
```

## Project structure

```
_printf.c
_putchar.c
main.h
print_types.c
man_3_printf
test.c
image/
```

## Man page

A man page is included at `man_3_printf` (troff format). You can view it
locally without installing it system-wide in several ways:

- Directly with `man` if your `man` accepts local files:

```sh
man ./man_3_printf
```

- Use `groff` to format and display it:

```sh
groff -Tutf8 -man man_3_printf | less
```

- Install locally to a `man` tree (example creates `./man/man3`):

```sh
mkdir -p ./man/man3
gzip -c man_3_printf > ./man/man3/_printf.3.gz
man -M ./man _printf
```

## Testing & Valgrind

Compile and run simple examples to exercise the implementation. To check
for memory leaks using Valgrind run:

```sh
valgrind --leak-check=full --show-leak-kinds=all ./_printf "Hello %s" "world"
```

Note: `_printf` is a small educational implementation; memory allocation
is minimal but it's good practice to run Valgrind on your examples.

## Man page (screenshots)

Screenshots of the bundled manual page are included below (ascending order):

![Man page — part 1](<image/man page (1-3).png>)

![Man page — part 2](<image/man page (2-3).png>)

![Man page — part 3](<image/man page (3-3).png>)

## Flowchart

High-level flowcharts describing the `_printf` parsing and dispatch flow
are included below (ascending order):

![Flowchart — part 1](<image/flowchart (1-2).png>)

![Flowchart — part 2](<image/flowchart (2-2).png>)

## Implementation notes

- A dispatch table (`printer array`) maps format characters to handler
	functions declared in `main.h`.
- `_putchar` is a tiny wrapper around `write(1, &c, 1)` to perform
	unbuffered output from handlers.
- Variadic arguments are handled with `stdarg.h` macros.

## Authors

- Joan FAROUX
- Joshua BURLE