#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "io.h"

#define MAX_COLORS 256
#define EMPTY_ERROR "pbmp is NULL\n"

uint8_t type1;
uint8_t type2;
uint32_t noUse1;
uint32_t noUse2;
uint16_t noUse1;
uint16_t noUse2;

typedef struct color{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Color;

typedef struct bmp{
    uint32_t height;
    uint32_t width;
    Color palette[MAX_COLORS];
    uint8_t **a;
} BMP;

uint32_t round_up(uint32_t x, uint32_t n){
    while((x % n) != 0){
        x++;
    }
    return x;
}

BMP *bmp_create(FILE *fin){
    BMP *pbmp = calloc(1, sizeof(BMP));
    if (pbmp == NULL){
        fprintf(stderr, EMPTY_ERROR);
        exit(EXIT_FAILURE);
    }

    read_uint8(fin, type1);   
    read_uint8(fin, type2);

    read_uint32(fin, noUse1);
    read_uint16(fin, noUse1);
    read_uint16(fin, noUse2);
    read_uint32(fin, noUse2);
}
