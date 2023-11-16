#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "io.h"

#define READ_ERROR "unexpected end of file\n"
#define WRITE_ERROR "unable to write file\n"

void read_uint8(FILE *fin, uint8_t *px){
    int result = fgetc(fin);
    if (result == EOF){
        fprintf(stderr, READ_ERROR);
        exit(EXIT_FAILURE);
    }
    *px = (uint8_t) result;
}

void read_uint16(FILE *fin, uint16_t *px){
    int result = fgetc(fin);
    if (result == EOF){
        fprintf(stderr, READ_ERROR);
        exit(EXIT_FAILURE);
    }
    *px = (uint16_t) result;
}

void read_uint32(FILE *fin, uint32_t *px){
    int result = fgetc(fin);
    if (result == EOF){
        fprintf(stderr, READ_ERROR);
        exit(EXIT_FAILURE);
    }
    *px = (uint32_t) result;
}

void write_uint8(FILE *fout, uint8_t x){
    int result = fputc(x, fout);
    if(result == EOF){
        fprintf(stderr, WRITE_ERROR);
        exit(EXIT_FAILURE);
    }
}

void write_uint16(FILE *fout, uint16_t x){
    int result = fputc(x, fout);
    if(result == EOF){
        fprintf(stderr, WRITE_ERROR);
        exit(EXIT_FAILURE);
    }
}

void write_uint32(FILE *fout, uint32_t x){
    int result = fputc(x, fout);
    if(result == EOF){
        fprintf(stderr, WRITE_ERROR);
        exit(EXIT_FAILURE);
    }
}
