#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* localdecomp:start func_L39_00622990 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L39_004997E0[];
extern void func_L01_003F3768(s32);
extern void func_L01_003F3740(s32);
extern s32 func_L39_0062CD88(void *);
extern void func_L39_00621308(void *);
extern void func_0038D328(void *, void *);
extern void func_0038D2A0(void *);
extern void func_0038D5B0(void *, void *);
extern void func_L39_00623FB8(void *);
extern void func_L39_006244E0(u8 *);
extern void func_L39_00624658(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_0063B5E0(void *, s32);
extern void func_L39_00628038(void *, s32);

typedef union Buf_00622990 {
    u8 b[8];
    u32 w[2];
} Buf_00622990;

typedef struct {
    u8 pad0[0x2C];
    void (*f2C)(void *);
    u8 pad30[4];
    void (*f34)(void *, s32, s32, s32, s32);
} Vt_00622990;

typedef struct {
    u8 pad0[0x1FC0];
    f32 ring[32];
    u8 pad2040[0x300];
    s32 idx;
    s32 cnt;
} R_00622990;

typedef struct {
    u8 pad0[0x14];
    Vt_00622990 *vt;
} G_00622990;

void func_L39_00622990(u8 *g) {
    u128_t bufa[1];
    Buf_00622990 dbuf;
    u8 *a;
    u8 *b;

    if (g[0x1A14] != 0) {
        func_L01_003F3768(g[0x24C9]);
    }
    *(u128_t *)(g + 0x100) = *(u128_t *)(g + 0xA0);
    g[0x1A06] = func_L39_0062CD88(g);
    *(s32 *)(g + 0x200) = 0;
    ((G_00622990 *)g)->vt->f2C(g);
    if (g[0x1A14] != 0) {
        bufa[0] = *(u128_t *)(g + 0xE0);
    }
    ((R_00622990 *)g)->ring[((R_00622990 *)g)->idx] = *(f32 *)(g + 0xB8);
    *(s32 *)(g + 0x2340) = (*(s32 *)(g + 0x2340) + 1) % 32;
    *(s32 *)(g + 0x2344) += 1;
    if (*(s32 *)(g + 0x2344) > 32) {
        *(s32 *)(g + 0x2344) = 32;
    }
    func_L39_00621308(g);
    a = g + 0x20;
    b = g + 0x60;
    func_0038D328(a, g + 0xB0);
    func_0038D2A0(b);
    func_0038D5B0(b, a);
    func_L39_00623FB8(g);
    func_L39_006244E0(g);
    func_L39_00624658(g);
    if (g[0x1A14] != 0) {
        if (g[0x216] != 0 && (({
            u8 *q = g + 0x19E4;
            u32 a;
            u32 r;
            if (*q == 0) {
                r = 0;
            } else {
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = dbuf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = dbuf.w[0] ^ (u32)q;
                dbuf.w[0] = a;
                dbuf.w[1] ^= a;
                r = dbuf.w[1];
            }
            r;
        }) ^ 0x31) != 0 && (({
            u8 *q = g + 0x19E6;
            u32 a;
            u32 r;
            if (*q == 0) {
                r = 0;
            } else {
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = dbuf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = dbuf.w[0] ^ (u32)q;
                dbuf.w[0] = a;
                dbuf.w[1] ^= a;
                r = dbuf.w[1];
            }
            r;
        }) ^ 0x14) != 0 &&
            func_003D3CB0(bufa, g + 0xE0, 2, *(void **)(g + 0x2524), 0) != 0) {
            func_L39_0063B5E0(g, 0xF);
            ((G_00622990 *)g)->vt->f34(g, 0x76, 0, 0, 0);
            func_L39_00628038(g, 1);
        }
        func_L01_003F3740(g[0x24C9]);
    }
}
/* localdecomp:end func_L39_00622990 */

INCLUDE_ASM("asm/levels", func_L39_00622C28);
