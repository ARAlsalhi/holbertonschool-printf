# _printf Project

## 📌 Description
This project is a custom implementation of the C standard library function `printf`.

The goal is to recreate the behavior of `printf` while understanding:
- Variadic functions (`va_list`)
- Format string parsing
- Buffering
- Low-level output using `write`

---

## ⚙️ Prototype
```
int _printf(const char *format, ...);

---

## 📊 Project Breakdown

Task	    Type	            Description

0	        Mandatory	        Write a function that produces output according to a format
1	        Mandatory	        Handle specifiers: d, i
2	        Mandatory	        Create a man page
3	        Advanced	        Handle specifier: b (binary)
4	        Advanced	        Handle specifiers: u, o, x, X
5	        Advanced	        Implement buffer (1024 chars)
6	        Advanced	        Handle specifier: S
7	        Advanced	        Handle specifier: p
8	        Advanced	        Handle flags: +, space, #
9	        Advanced	        Handle length modifiers: l, h
10	        Advanced	        Handle field width
11	        Advanced	        Handle precision
12	        Advanced	        Handle flag: 0
13	        Advanced	        Handle flag: -
14	        Advanced	        Handle specifier: r (reverse)
15	        Advanced	        Handle specifier: R (rot13)
16	        Advanced	        Integrate all features together

---

## 🧠 How It Works
The _printf function reads the format string character by character.
When it encounters %, it parses:

%[flags][width][.precision][length]specifier


---

## 🔄 Execution Flow

START
  ↓
Read format string
  ↓
Is current char '%'?
  ├── No → print char
  └── Yes
        ↓
     Parse flags (+, space, #, 0, -)
        ↓
     Parse width (number or *)
        ↓
     Parse precision (.number or .*)
        ↓
     Parse length (h, l)
        ↓
     Parse specifier
        ↓
     Call corresponding function
        ↓
     Print formatted output
  ↓
Repeat until end
  ↓
Flush buffer
  ↓
END


---

## 🧩 Supported Specifiers

Specifier   | 	 Description
            | 
%c	        |    Character
%s	        |    String
%%	        |    Percent
%d, %i	    |    Signed integer
%u	        |    Unsigned integer
%o	        |    Octal
%x	        |    Hex (lowercase)
%X	        |    Hex (uppercase)
%p	        |    Pointer
%b	        |    Binary
%S	        |    String (non-printable → hex)
%r	        |    Reversed string
%R	        |    ROT13 string


---

## 🚩 Flags

Specifier   | 	Description
+	        |   Show sign
space	    |   Space before positive
#	        |   Alternate form
0	        |   Zero padding
-	        |   Left align

---

## 📏 Width

_printf("%5d", 42);

Output:
    42


---


## 🎯 Precision

_printf("%.4d", 42);

Output:
0042


---

## 🔠 Length Modifiers

Meaning         Modifier	
h	        |   short
l	        |   long


---


## ⚡ Buffering
- Uses a buffer of 1024 characters
- Reduces system calls to write
- Improves performance

---

## ⚠️ Edge Cases
NULL string → "(null)"
NULL pointer → "(nil)"
precision = 0 and value = 0 → prints nothing
- overrides 0
+ overrides space


---

## 🧪 Examples
_printf("%d", -42);       // -42
_printf("%+d", 42);       // +42
_printf("%05d", 42);      // 00042
_printf("%-5d", 42);      // 42   
_printf("%#x", 255);      // 0xff
_printf("%r", "Hello");   // olleH
_printf("%R", "Hello");   // Uryyb


---

## 📂 Project Structure
.
├── main.h
├── printf.c
├── functions.c
├── conversions.c
├── pointer.c
├── flags.c
├── width.c
├── precision.c
├── reverse.c
├── rot13.c
├── man_3_printf
└── README.md


---


## 🚀 Compilation and Use

1-Clone the repository:

git clone https://github.com/ARAlsalhi/holbertonschool-printf.git

2-Move into the directory:

cd holbertonschool-printf

3-Compile:

gcc -Wall -Werror -Wextra -pedantic -Wno-format -std=gnu89 *.c

4-Run:

./a.out

---

## 🧑‍💻 Authors
Abdulrhman Alsalhi
Lama Alzahrani


---c


