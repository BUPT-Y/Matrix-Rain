# Matrix Rain (Console Version)

A "Matrix"-style digital rain simulation for the Windows console. Random characters fall from the top of the screen, creating a dynamic rain effect.

## Features

- Randomly generated characters (digits, letters, common symbols)
- Automatically adapts to console window resizing during runtime
- Manages a large number of raindrops using a circular queue
- Hides cursor and renders without flickering
- Configurable maximum drops and character length range

## File Structure

| File          | Description                                      |
|---------------|--------------------------------------------------|
| `main.cpp`    | Main program entry: drop generation and refresh loop |
| `Config.h`    | Configuration header: defines max drops, length limits |
| `drop.cpp`    | Implementation of the `drop` class (raindrop behavior) |
| `drop.h`      | Declaration of the `drop` class                  |
| `winapi.cpp`  | Windows API wrapper functions (screen size, cursor position, etc.) |
| `winapi.h`    | Declarations for Windows API helper functions    |

## Compilation and Execution

### Requirements
- Windows operating system (uses `<Windows.h>`)
- C++11 compatible compiler (e.g., MinGW-g++, MSVC)

Press `Ctrl + C` to terminate the program.

## Configuration

Edit the macros in `Config.h` to adjust the program's behavior:

```cpp
#define MAX_LENGTH 10   // Maximum length of a single raindrop (in characters)
#define MIN_LENGTH 6    // Minimum length of a single raindrop
#define MAX_DROPS 300   // Maximum number of simultaneous drops
```

Recompile after making changes.

## Notes

- This program is Windows-only due to its dependency on the Windows API.
- Ensure your console font supports ASCII characters (usually the default).
- If screen refresh appears flickery, adjust the `Sleep(40)` delay in `main.cpp` (milliseconds).
-!!!It is suggested to open it in a small window, otherwise it wil be very laggy
