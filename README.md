# Variadic Functions and Logging Macros in C

This project demonstrates the use of **variadic functions**, **custom logging macros**, and a **custom printf-like function** in C. The implementation covers several advanced C concepts including variadic arguments, macro expansion with `__VA_ARGS__`, and low-level `write()` operations.

---

## 📁 Project Structure

- `main.c` – Implements and tests basic variadic functions such as `cong`, `maxx`, `gttb`.
- `bt1.c` – Demonstrates log level-based printing using macros.
- `duong_printf.c` / `duong_printf.h` – A custom implementation of `printf` with support for `%d`, `%s`, `%c`.
- `variadic_macro.c` – Tests macros like `LOG()` and `LOG1()` with file name and line number printing.
- `run.exe` – Precompiled binary.

---

## 🔧 Key Features

### Variadic Functions
- `cong(int count, ...)`: Sums integers.
- `maxx(int count, ...)`: Returns maximum value.
- `gttb(int count, ...)`: Computes average value.

### Custom Logging Macro (from `bt1.c`)
```c
#define LOG_ERROR(...)   LOG_INTERNAL_MODULE(LOG_LEVEL_ERROR, __VA_ARGS__)
```
Each log level checks against `NRF_LOG_DEFAULT_LEVEL` before printing.

### Custom Print Function (from `duong_printf.c`)
- Implements a simplified `printf()` using `write()` system call.
- Supports `%d`, `%s`, `%c`, and `%%`.

### Macro Logging with File and Line Info
```c
#define LOG1(Format, ...)   printf("%s (%d) " Format, __FILE__, __LINE__, ##__VA_ARGS__)
```
Prints log message with file name and line number.

---

## ▶️ Compilation Example

```bash
gcc main.c duong_printf.c -o run
gcc bt1.c -o run_bt1
gcc variadic_macro.c -o run_macro
```

---

## 📝 Example Output

```
Hello word
Hello word
3
a
1.999000
42.500000
variadic_macro.c (22) Ten Toi La Duong
```

---

## 📌 Notes

- You should use `duong_printf.h` when calling `printd()` from other files.
- `printd()` is useful in embedded systems where `printf` may not be available.
- This project is a good reference for learning variadic functions and custom logging in C.

---

## 📤 Author

Built for learning and practicing C advanced techniques including variadic macros and low-level logging.
