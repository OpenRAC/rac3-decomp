#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006025F0);

/* localdecomp:start func_L39_00602930 */
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
    s16 f18;
    s16 f1A;
} S_00602930;

extern s32 D_L39_00240300[2];
extern char D_L39_002453E8[];
extern char D_L39_002453F8[];
extern char D_L39_00245408[];
extern char D_L39_00245440[];
extern char D_L39_00245478[];
extern char D_L39_00245480[];
extern char D_L39_00245490[];
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_00391130();
extern void func_L01_00412C28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern void func_L39_00593468(void *, f32, f32, s32, char *, s32, unsigned long);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L39_00602D90(u8 *, s32, u32, f32, f32, f32, f32);

void func_L39_00602930(void *a0, S_00602930 *s, s32 a2, char *a3, s32 mode, s32 center, s32 a6,
                       s32 a7, char *a8, char *a9, u8 a10) {
    char buf[0x200];
    s32 old = s->f12;
    s32 l, r, t, b;
    s32 w, h;
    s32 x, y;

    s->f12 |= 3;
    if (a8 != 0) {
        if (a9 != 0) {
            if (a10 != 0) {
                if (a7 != 0) {
                    func_00120048(buf, D_L39_002453E8, a3, 1, a8, 1, a9);
                } else {
                    func_00120048(buf, D_L39_002453F8, a3, 1, 1, a8, 1, a9);
                }
            } else {
                if (a7 != 0) {
                    func_00120048(buf, D_L39_00245408, a3, 1, a8, a9);
                } else {
                    func_00120048(buf, D_L39_00245440, a3, 1, 1, a8, a9);
                }
            }
        } else {
            if (a7 != 0) {
                func_00120048(buf, D_L39_00245478, a3, 1, a8);
            } else {
                func_00120048(buf, D_L39_00245480, a3, 1, 1, a8);
            }
        }
    } else {
        func_00120048(buf, D_L39_00245490, a3);
    }
    s->f12 |= 4;
    switch (mode) {
    case 0:
        func_00391130(s, a2, buf, a6);
        break;
    case 1:
        func_L39_00593468(s, 1.0f, 1.0f, a2, buf, a6, 0x80000000UL);
        break;
    case 2:
        ((void (*)(void *, s32, char *, s32))func_L01_00412C28)(s, a2, buf, a6);
        break;
    }
    if (center) {
        s->f0 = (D_L39_00240300[1] - s->fE) >> 1;
        s->f2 = s->f0 + s->fE;
        s->fA = s->f0 + (s->fE >> 1);
    }
    switch (mode) {
    case 0:
        func_00391130(s, a2, buf, a6);
        break;
    case 1:
        func_L39_00593468(s, 1.0f, 1.0f, a2, buf, a6, 0x80000000UL);
        break;
    case 2:
        ((void (*)(void *, s32, char *, s32))func_L01_00412C28)(s, a2, buf, a6);
        break;
    }
    h = (s->fC >> 1) + 10;
    w = (s->fE >> 1) + 5;
    s->f12 &= ~4;
    y = s->f8;
    x = s->fA;
    l = x - w;
    r = x + w;
    t = y - h;
    b = y + h;
    func_0038C3B0(l, r, t, b, 0x60, 0x600E5092);
    func_L39_00602D90(a0, 0x60, 0x332299DE, l, r, t, b);
    s->f12 |= 0x20;
    s->f18 = 2;
    s->f1A = 2;
    switch (mode) {
    case 0:
        func_00391130(s, a2, buf, a6);
        break;
    case 1:
        func_L39_00593468(s, 1.0f, 1.0f, a2, buf, a6, 0x80000000UL);
        break;
    case 2:
        ((void (*)(void *, s32, char *, s32))func_L01_00412C28)(s, a2, buf, a6);
        break;
    }
    s->f12 = old;
}
/* localdecomp:end func_L39_00602930 */
