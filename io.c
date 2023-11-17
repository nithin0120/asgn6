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

void read_uint16(FILE *fin, uint16_t *px) {
    uint8_t byte1, byte2;
    read_uint8(fin, &byte1); 
    read_uint8(fin, &byte2); 

    *px = ((uint16_t)byte2 << 8) | byte1; // 
}

void read_uint32(FILE *fin, uint32_t *px) {
    uint16_t word1, word2;
    read_uint16(fin, &word1); 
    read_uint16(fin, &word2); 

    *px = ((uint32_t)word2 << 16) | word1;
}

void write_uint8(FILE *fout, uint8_t x){
    int result = fputc(x, fout);
    if(result == EOF){
        fprintf(stderr, WRITE_ERROR);
        exit(EXIT_FAILURE);
    }
}

void write_uint16(FILE *fout, uint16_t x) {
    write_uint8(fout, (uint8_t)x);       
    write_uint8(fout, (uint8_t)(x >> 8)); 
}

void write_uint32(FILE *fout, uint32_t x) {
    write_uint16(fout, (uint16_t)x);           
    write_uint16(fout, (uint16_t)(x >> 16));   
}