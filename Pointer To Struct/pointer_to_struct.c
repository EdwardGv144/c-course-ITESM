/*
 * ITESM-CQ
 * Objective : Understand dynamic structures and basic input handling
 * Authors   : Oscar Hernandez (original), Edward Gomez (revised)
 * Date      : March 14, 2018 (revised 2025)
 *
 * Program: Allocates a record dynamically and fills its fields from user input.
 * Notes  : "Matricula" format: [A/M][0-9]{8}, length 9 (first char A or M).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 40

typedef char String[MAX_STR];

typedef struct {
    String Mat;       // [A/M][8 digits]
    String Nombre;
    String Direccion;
    String Carrera;
} Record, *PtrRecord;

int main(void) {
    PtrRecord reg = (PtrRecord)malloc(sizeof(Record));
    if (!reg) {
        fprintf(stderr, "Error: sin memoria.\n");
        return 1;
    }

    // --- Matricula (loop until valid) ---
    char buf[MAX_STR];
    for (;;) {
        printf("Matricula -> ");
        if (!fgets(buf, sizeof buf, stdin)) { free(reg); return 1; }

        // trim newline
        size_t n = strcspn(buf, "\n");
        buf[n] = '\0';

        size_t len = strlen(buf);
        // Fixed format: [A/M][0-9]{8}
        if (len != 9) {
            fprintf(stderr, "Matricula invalida: longitud exacta de 9 caracteres.\n");
            continue;
        }

        // first char A or M (not case sensitive)
        char c0 = buf[0];
        if (c0 != 'A' && c0 != 'M' && c0 != 'a' && c0 != 'm') {
            fprintf(stderr, "Matricula invalida: el primer caracter debe ser A o M.\n");
            continue;
        }

        // remaining 8 must be digits
        int ok = 1;
        for (size_t i = 1; i < len; ++i) {
            if (!isdigit((unsigned char)buf[i])) { ok = 0; break; }
        }
        if (!ok) {
            fprintf(stderr, "Matricula invalida: formato [A/M][8 digitos].\n");
            continue;
        }

        // Uppercase and save
        buf[0] = (char)toupper((unsigned char)buf[0]);
        strcpy(reg->Mat, buf);
        break;
    }


    // --- Nombre ---
    printf("Nombre Completo-> ");
    if (!fgets(reg->Nombre, sizeof reg->Nombre, stdin)) { free(reg); return 1; }
    reg->Nombre[strcspn(reg->Nombre, "\n")] = '\0';

    // --- Direccion ---
    printf("Direccion -> ");
    if (!fgets(reg->Direccion, sizeof reg->Direccion, stdin)) { free(reg); return 1; }
    reg->Direccion[strcspn(reg->Direccion, "\n")] = '\0';

    // --- Carrera ---
    printf("Carrera -> ");
    if (!fgets(reg->Carrera, sizeof reg->Carrera, stdin)) { free(reg); return 1; }
    reg->Carrera[strcspn(reg->Carrera, "\n")] = '\0';

    // --- Print ---
    printf("\n\nCONTENIDO DEL REGISTRO\n");
    puts(reg->Mat);
    puts(reg->Nombre[0]    ? reg->Nombre    : "(sin nombre)");
    puts(reg->Direccion[0] ? reg->Direccion : "(sin direccion)");
    puts(reg->Carrera[0]   ? reg->Carrera   : "(sin carrera)");

    free(reg);
    return 0;
}
