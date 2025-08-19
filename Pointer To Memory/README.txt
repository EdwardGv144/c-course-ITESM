# Pointer Arithmetic Demo

This program demonstrates pointer arithmetic by iterating through memory addresses.

## How It Works
- Declares an integer `x = -1`.
- Creates a pointer `ptr` pointing to `x`.
- Prints `WINDOW_SIZE` successive addresses and the values found there.
- Each `ptr++` advances the pointer to the next integer in memory.

## Example Output

   Address of counter variable x = 000000411f9ffb20

   Address         Content
   000000411f9ffb20   [     -1]
   000000411f9ffb24   [      1]
   000000411f9ffb28   [530578216]
   000000411f9ffb2c   [     65]
   000000411f9ffb30   [-1329864632]
   000000411f9ffb34   [  32758]
   000000411f9ffb38   [-1329917751]
   000000411f9ffb3c   [  32758]
   000000411f9ffb40   [-1329864640]
   000000411f9ffb44   [  32758]
   000000411f9ffb48   [      1]
   000000411f9ffb4c   [      0]
   000000411f9ffb50   [      0]
   000000411f9ffb54   [      0]
   000000411f9ffb58   [      0]
   000000411f9ffb5c   [      0]
   000000411f9ffb60   [530578316]
   000000411f9ffb64   [     65]
   000000411f9ffb68   [      0]
   000000411f9ffb6c   [      0]

Press Enter to exit...

*(Actual addresses and contents vary by run and platform)*

## Build & Run
```bash
gcc pointer_to_memory.c -o ptr
./ptr
