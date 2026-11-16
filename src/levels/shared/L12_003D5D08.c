#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L12_003D4B18.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);

INCLUDE_ASM("asm/levels", func_L12_003D5D08);

INCLUDE_ASM("asm/levels", func_L12_003D63D8);

INCLUDE_ASM("asm/levels", func_L12_003D6C70);

INCLUDE_ASM("asm/levels", func_L12_003D6FC0);
