# File Copy with XOR Transformation

This program copies the contents of a source file to a destination file while applying a bitwise XOR operation (`255 ^ byte`) to all bytes after the first 54 bytes (commonly used for BMP headers).

## How It Works
1. The user enters the source and destination file names.
2. The program copies the first 54 bytes unchanged.
3. The rest of the bytes are inverted using `255 ^ byte`.
4. The modified file is saved as the destination file.

## Usage
```bash
gcc main.c -o file_copy_xor
./file_copy_xor

Source file name? input.bmp
Destination file name? output.bmp

Example:
Source file name? lena.bmp
Destination file name? lena_out.bmp
