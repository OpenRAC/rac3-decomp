#include "common.h"

/* NTSC-U counterpart of func_L03_0039E748 (src/levels/03_starship_phoenix/L03_0039E470.c) */
typedef struct {
    u8 pad0[0x39];
    u8 b39;
    u8 pad3A[0x6];
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x25];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 pad83[0x3];
    u8 b86;
    u8 pad87[0x5];
    f32 f8C;
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    f32 fAC;
    u8 padB0[0x8];
    u8 bB8;
    u8 padB9[0x2F];
    u8 bE8;
    u8 bE9;
    u8 padEA[0x1];
    u8 bEB;
    u8 padEC[0x64];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15C;
    f32 f160;
    u8 pad164[0x18];
    f32 f17C;
    f32 f180;
    f32 f184;
    s32 w188;
    u8 pad18C[0xB0];
    s32 w23C;
    u8 pad240[0x14];
    void * p254;
    void * p258;
    u8 pad25C[0x11];
    u8 b26D;
    u8 pad26E[0x92];
    s32 w300;
} P_0039E748;
extern void func_L03_0039CF70(void *);

/* localdecomp:start func_L03_0039CF70 */
extern void func_L03_0039D410();
extern void func_L03_0039D3B8(void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
void func_L03_0039CF70(void *a) {
    P_0039E748 *p;
    if (*(u8 *)((u8 *)a + 0x20) == 0) {
        p = *(P_0039E748 **)((u8 *)a + 0x68);
        p->bB8 = 0xFF;
        p->b39 = 0;
        p->w23C = 0;
        p->b26D = 0;
        p->b80 = 4;
        p->b81 = 3;
        p->b82 = 3;
        p->bE8 = 5;
        p->bE9 = 5;
        p->fAC = 0.150000006f;
        p->bEB = 0xFF;
        p->b86 = 0xFF;
        p->f8C = 0.25f;
        p->f90 = 0.01666666753590107f;
        p->f94 = 0.0069444444961845875f;
        p->f98 = 0.009722222574055195f;
        p->f9C = 0.0005555555690079927f;
        p->b58 = 0x14;
        p->b5A = 0xE;
        p->f40 = 1.0f;
        p->f160 = 1.57079637f;
        p->f180 = 0.244346097f;
        p->f17C = 0.16333334147930145f;
        p->fA0 = 0.5f;
        p->fA4 = 0.5f;
        p->f150 = 0.5f;
        p->f154 = 0.5f;
        p->f158 = 0.5f;
        p->f15C = 0.5f;
        p->f184 = 0.5f;
        p->p254 = func_L03_0039D410;
        p->p258 = func_L03_0039D3B8;
        func_L01_00458A70(a, 0.0008333333535119891f, 0.05000000447034836f, 0.0008726646774448454f, 0.05235988274216652f);
        p->w188 |= 0x10;
        func_L03_0039D3B8(a);
        p->w300 = 0;
    }
}
/* localdecomp:end func_L03_0039CF70 */
