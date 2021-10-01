# Input and Output

## Formatted Output

The basic syntax for formatted output is similar to `printf` in C:

`%[width][.precision][specifier]`

where `width` is the column width, `.precision` is the number of digits after the radix for floating point numbers \(see examples\), and the specifiers are

* integers: `d` for decimal, `o` for octal, `x` or `X`fo hexadecimal
* floating point numbers: `e` for scientific notation, `f` for decimal number
* characters: `c` or `C`

Examples:

```java
System.out.printf("%X",0xffffcdab) // prints out FFFFCDAB
System.out.printf("%.2f",145.9999) // prints out 146.00
System.out.printf("%.4f",145.9999) // prints out 145.9999
System.out.printf("%.4e",145.9999) // prints out 1.4600e+02
System.out.printf("%3d%3d%3d",1,1,1) // prints out "  1  1  1";
```

