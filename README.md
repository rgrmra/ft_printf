# ft_printf

The recoded printf.

#### How does it work?

This function works with a list of characters and allocates memory for each character. When it finishes the proccess of the configuration of the flags, it prints the result in the standard output.

#### Prototype:

```c
int  ft_printf(const char *fmt, ...);
```

## How to use it?

Clone this repository:

```shell
git clone https://github.com/rgrmra/ft_printf.git get_next_line
```

Then compile the files as following:

#### Mandatory:

Formats just the percentage flags: %c, %s, %d, %i, %u, %p, %x, %X, %%.

```shell
make
```

#### Bonus:

Format the percentage flags and the flags: left (-), plus (+), zero (0), space ( ), precision (.) and hash (#).

```shell
make bonus
```

#### Compiling:

Compile the archive _libftprintf.a_ with your _main_.

```shell
cc -Wall -Wextra -Werror main.c libftprintf.a
```

> Obs.: Don't forget to include in your main the prototype of the _ft_printf_.
