# Dynamic Struct: Student Record (Matrícula Validation)

Allocates a `Record` struct dynamically and fills its fields from user input.  
Prompts are in Spanish; identifiers are in English.

## Rules
- **Matrícula** must match the fixed format: **`[A/M][0-9]{8}`**  
  - First character is `A` or `M` (case-insensitive; stored uppercase)  
  - Followed by **8 digits**  
  - Total length: **9** characters
- `Nombre`, `Direccion`, and `Carrera` are read as lines (max 39 chars + `\0`).

## Build & Run
```bash
gcc pointer_to_struct.c -o registro
./registro

Example:
Matricula -> A01204727
Nombre Completo-> Edward Gomez
Direccion -> 3 de Mayo 10, int 75
Carrera -> ISDR


CONTENIDO DEL REGISTRO
A01204727
Edward Gomez
3 de Mayo 10, int 75
ISDR