#include "common.h"

/* NTSC-U counterpart of func_L24_0034A2C8 (src/levels/24_insomniac_museum/L24_0034A2C8.c) */
/* localdecomp:start func_L24_003494A8 */
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    f32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    s32 x28;
    f32 x2C;
    f32 x30;
    f32 x34;
    s32 x38;
    u8 *x3C;
    s32 x40;
    s32 x44;
    s32 x48;
    s16 x4C;
    s16 x4E;
    s32 x50;
    f32 x54;
} S_0034A2C8;

extern s32 D_001D545C;
extern u8 *D_001D52FC;
extern u8 D_001A4C60[];
extern void *D_001A4F3C[];
__asm__(".extern D_L24_001DF51C_003494A8, 4");
extern u8 *D_L24_001DF51C_003494A8;
extern u8 *D_L24_0021EFD8_003494A8[];
extern char D_L24_001DD210[];
extern char D_L24_001DD218_003494A8[];
extern char D_L24_001DD228_003494A8[];
extern char D_L24_001DD238[];
extern char D_L24_001DD248[];
extern char D_L24_001DD258[];
extern char D_L24_001DD260_003494A8[];
extern char D_L24_001DD268[];
extern char D_L24_001DD270_003494A8[];
extern char D_L24_001DD280_003494A8[];
extern char D_L24_001DD290[];
extern char D_L24_001DD2A0[];
extern char D_L24_001DD2B0[];
extern char D_L24_001DD2C0[];
extern char D_L24_001DD2C8[];
extern char D_L24_001DD2D8[];
extern char D_L24_001DD2E8[];
extern char D_L24_001DD2F8[];
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F3E0(s32, s32);
extern s32 func_L01_00452EC8(void *);
extern u8 *func_L03_00348048(void *);
extern void func_L03_003480D8(void *, void *, void *, s32, s32, s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L24_003494A8(u8 *obj) {
    S_0034A2C8 *s = *(S_0034A2C8 **)(obj + 0x68);
    u8 *p;

    switch (obj[0x20]) {
    case 0:
        if (s->x4E < 0) {
            s->x4E = 0;
        }
        if (s->x4C > s->x4E) {
            s->x4C = s->x4E;
        } else if (s->x4C < 0) {
            s->x4C = 0;
        }
        s->xC = func_0037E208(s->x4C, s->x4E);
        obj[0x30] = 0x40;
        *(s16 *)(obj + 0x32) = 0x40;
        s->x54 = *(f32 *)(obj + 0x18);
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if ((s->x50 != -1 && D_001A4F3C[0] != 0 && D_001A4F3C[0] == D_L24_001DF51C_003494A8 + (s->x50 << 8))
            || (s->x48 != -1 && func_0037E0F0(D_001A4C60, s->x48, 0) != 0)) {
            func_L01_0044F2E8(0, 1, 0x1235, 1, 0, 0, 0);
            if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                func_L01_0044F3E0(0, 1);
                func_L01_00441FB8(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj)) {
            s->x3C = func_L03_00348048(obj);
            if (D_001D545C == 0x18) {
                func_L03_003480D8(s->x3C, obj + 0x18, D_L24_001DD210, 1, s->x54, s->x54 + 5.0f);
                func_L03_003480D8(s->x3C, &s->x0, D_L24_001DD218_003494A8, 1, -1, 1);
                func_L03_003480D8(s->x3C, &s->x4, D_L24_001DD228_003494A8, 1, -1, 1);
                func_L03_003480D8(s->x3C, &s->x8, D_L24_001DD238, 1, -1, 1);
                func_L03_003480D8(s->x3C, &s->x10, D_L24_001DD248, 0, 0, 30);
                func_L03_003480D8(s->x3C, &s->x14, D_L24_001DD258, 0, 0, 255);
                func_L03_003480D8(s->x3C, &s->x18, D_L24_001DD260_003494A8, 0, 0, 255);
                func_L03_003480D8(s->x3C, &s->x1C, D_L24_001DD268, 0, 0, 255);
                func_L03_003480D8(s->x3C, &s->x20, D_L24_001DD270_003494A8, 0, -100, 100);
                func_L03_003480D8(s->x3C, &s->x24, D_L24_001DD280_003494A8, 0, 0, 127);
                func_L03_003480D8(s->x3C, &s->x28, D_L24_001DD290, 0, 0, 127);
                func_L03_003480D8(s->x3C, &s->x2C, D_L24_001DD2A0, 1, 0, 1000);
                func_L03_003480D8(s->x3C, &s->x30, D_L24_001DD2B0, 1, 0, 1000);
                func_L03_003480D8(s->x3C, &s->x34, D_L24_001DD2C0, 1, -1, 1);
                func_L03_003480D8(s->x3C, &s->x40, D_L24_001DD2C8, 0, 0, 103);
                func_L03_003480D8(s->x3C, &s->x44, D_L24_001DD2D8, 0, 0, 20);
                func_L03_003480D8(s->x3C, &s->x4C, D_L24_001DD2E8, 3, 2, 60);
                func_L03_003480D8(s->x3C, &s->x4E, D_L24_001DD2F8, 3, 2, 60);
            } else {
                func_L03_003480D8(s->x3C, &s->x0, D_L24_001DD218_003494A8, 1, -1000, 1000);
                func_L03_003480D8(s->x3C, &s->x4, D_L24_001DD228_003494A8, 1, -1000, 1000);
                func_L03_003480D8(s->x3C, &s->x8, D_L24_001DD238, 1, -1000, 1000);
                func_L03_003480D8(s->x3C, &s->x10, D_L24_001DD248, 0, 0, 50);
                func_L03_003480D8(s->x3C, &s->x14, D_L24_001DD258, 0, 0, 255);
                func_L03_003480D8(s->x3C, &s->x18, D_L24_001DD260_003494A8, 0, 0, 255);
                func_L03_003480D8(s->x3C, &s->x1C, D_L24_001DD268, 0, 0, 255);
                func_L03_003480D8(s->x3C, &s->x20, D_L24_001DD270_003494A8, 0, -1000, 1000);
                func_L03_003480D8(s->x3C, &s->x24, D_L24_001DD280_003494A8, 0, 0, 127);
                func_L03_003480D8(s->x3C, &s->x28, D_L24_001DD290, 0, 0, 127);
                func_L03_003480D8(s->x3C, &s->x2C, D_L24_001DD2A0, 1, 0, 1000);
                func_L03_003480D8(s->x3C, &s->x30, D_L24_001DD2B0, 1, 0, 1000);
                func_L03_003480D8(s->x3C, &s->x34, D_L24_001DD2C0, 1, -1000, 1000);
                func_L03_003480D8(s->x3C, &s->x40, D_L24_001DD2C8, 0, 0, 103);
                func_L03_003480D8(s->x3C, &s->x44, D_L24_001DD2D8, 0, 0, 20);
                func_L03_003480D8(s->x3C, &s->x4C, D_L24_001DD2E8, 3, 0, 1000);
                func_L03_003480D8(s->x3C, &s->x4E, D_L24_001DD2F8, 3, 0, 1000);
            }
        }
        if (s->x3C == 0 || *(s16 *)(s->x3C + 0xAA) != 0x118A || s->x3C[0x20] == 0xFE || s->x3C[0x20] == 0xFD) {
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    }

    if (s->xC-- == 0.0f) {
        if (s->x4C > s->x4E) {
            s->x4C = s->x4E;
        } else if (s->x4C < 0) {
            s->x4C = 0;
        }
        s->xC = func_0037E208(s->x4C, s->x4E);
        p = func_L01_0046C468(obj + 0x10, s, s->x10,
                              (s->x1C << 16) | (s->x18 << 8) | s->x14,
                              s->x20, s->x24, s->x28,
                              s->x2C * 210000.0f, s->x30 * 210000.0f, s->x34, s->x38);
        if (p != 0) {
            p[9] = 0xFF;
            p[2] = D_L24_0021EFD8_003494A8[s->x40][s->x44];
        }
    }
}
/* localdecomp:end func_L24_003494A8 */
