#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;
typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;
typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;
typedef void (*Fn_003B52B0)(u8 *, s32);

extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);
extern s32 func_L01_003B3548(u8 *);

/* declared by functions of L01_003B2F80.c, which this file was cut from */
extern s32 func_0038CAD0(u8 *);
extern void func_L01_004450F0(s32, s32, s32);

/* localdecomp:start func_L01_003B4FB0 */
typedef struct {
    u8 *w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
} St_3B4FB0;
typedef struct { u8 p0[0x18]; void (*f18)(void); } V_3B4FB0;
extern u8 *D_L01_001E001C;
extern s32 D_L01_001DE748[2];
__asm__(".extern D_L01_001DE748, 8");
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern s32 D_001D545C_003B4FB0;
__asm__(".extern D_001D545C_003B4FB0, 16");
extern s16 D_001A4DBC[];
extern f32 D_001A7404[];
extern f32 D_L01_001DF950[2];
extern void func_L01_003B5498(u8 *);
extern void func_L01_003B5500(s32, s32, s32);
extern void func_L01_003B28D0(void *);
extern void func_L01_003B42C8(s32, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_003291D0(u8 *);
extern void func_003E54E0(s32);
extern s32 func_L01_00328FE8(void *);
extern s32 func_L01_00329038(void *);
extern void func_L01_00419188(s32);
extern void func_L01_00326E50(void *);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_004EDE10(void);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_005003D0(s32, s32);
extern V_3B4FB0 *func_L01_0043B548(s32, s32);
extern s32 func_L01_004BA800(void);

void func_L01_003B4FB0(u8 *o) {
    St_3B4FB0 *s1;
    u8 *s0;
    u8 *t;
    s32 v;
    s32 k;
    u32 x;
    s32 b;
    V_3B4FB0 *r;

    s1 = *(St_3B4FB0 **)(o + 0x68);
    if (o[0x20] == 0) {
        ((void (*)(u8 *, void *))func_L01_003B5498)(o, s1);
    }
    switch (o[0x20]) {
    case 1:
        *(u16 *)(o + 0x34) |= 2;
        break;
    case 2:
        if (func_L01_004561B8(o) != 0) {
            if (s1->w10 != 0) {
                s1->w14 = 2;
            } else {
                s1->w14 = 0xC8;
            }
            if (s1->wC != 0) {
                if (s1->w18 != -1) {
                    t = D_L01_001E001C + (s1->w18 << 8);
                    t[0x30] = 0xFF;
                    *(u16 *)(t + 0x34) &= 0xFFFD;
                }
                s0 = *(u8 **)(s1->w0 + 0x68);
                if (*(s32 *)(s0 + 0x54) != 0) {
                    v = func_L01_003291D0(s1->w0);
                    s1->w1C = v;
                    D_00142660[0] += v;
                    func_003E54E0(0x96);
                } else {
                    s1->w1C = 0;
                }
                if (s0[0x52] != 0 && (func_L01_00328FE8(s1->w0) == 0 || func_L01_00329038(s1->w0) == 0)) {
                    k = D_L01_001DE748[s0[0x52]];
                    s1->w20 = k;
                    func_L01_00419188(k);
                } else {
                    s1->w20 = 0;
                }
                if (s1->w18 != -1) {
                    x = (*(s32 *)s0 & 0x7FF) + ((D_001D545C_003B4FB0 & 0x1F) << 11);
                    D_001426E0[0xE6] = x;
                    D_001426E0[0xE5] = x >> 8;
                }
                b = D_001426E0[0xBD];
                func_L01_00326E50(s1->w0);
                if (b == 0 && D_001426E0[0xBD] != 0) {
                    s1->w24 = 1;
                    func_003A5348(1, 0, 0);
                } else {
                    s1->w24 = 0;
                }
                D_001A4DBC[0] = 0xFA;
            }
        }
        if (s1->wC != 0 && s1->w10 == 0) {
            D_001A7404[0] = 300.0f;
        }
        if (func_0038CAD0((u8 *)&s1->w14) != 0) {
            if (s1->wC == 0) {
                func_L01_004EDE10();
            }
            if (s1->w18 != -1 && s1->wC != 0) {
                func_L01_00456230(D_L01_001E001C + (s1->w18 << 8), 1);
                if (D_001D545C_003B4FB0 == 0x1A) {
                    func_L01_005003D0(0x74, 1);
                }
                ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 3, -1);
            } else if (s1->w10 != 0) {
                if (s1->wC != 0 && s1->w4 != 0) {
                    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 5, -1);
                } else {
                    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 7, -1);
                }
            } else {
                ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 4, -1);
            }
        } else if (s1->w10 == 0) {
            if (s1->wC != 0) {
                func_L01_003B42C8(0xA82, s1->w1C, s1->w20, s1->w24);
            } else {
                func_L01_003B42C8(0xA83, 0, 0, 0);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(o) != 0) {
            r = func_L01_0043B548(0x19E1, 0x6C);
            r->f18();
        }
        if (func_L01_004BA800() == 0) {
            D_001426E0[0xE5] = 0;
            D_001426E0[0xE6] = 0;
            if (s1->wC != 0 && s1->w4 != 0) {
                ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 5, -1);
            } else {
                ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 7, -1);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(o) != 0) {
            s1->w14 = 0x21;
        }
        if (s1->wC != 0) {
            func_L01_003B42C8(0xA82, s1->w1C, s1->w20, s1->w24);
        } else {
            func_L01_003B42C8(0xA83, 0, 0, 0);
        }
        if (func_0038CAD0((u8 *)&s1->w14) != 0) {
            D_L01_001DF950[0] = 2.0f;
            if (s1->wC != 0 && s1->w4 != 0) {
                ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 5, -1);
            } else {
                ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 7, -1);
            }
        } else {
            D_L01_001DF950[0] = (1.0f - (f32)s1->w14 / 33.0f) * 1.1f;
        }
        break;
    case 5:
        ((void (*)(u8 *, void *, s32))func_L01_003B5500)(o, s1, s1->w8);
        ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 6, -1);
        break;
    case 6:
        if (func_L01_004561B8(o) != 0) {
            s1->w14 = 0x11;
        }
        if (func_0038CAD0((u8 *)&s1->w14) != 0) {
            D_L01_001DF950[0] = 0.0f;
            ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 7, -1);
        } else {
            D_L01_001DF950[0] = ((f32)s1->w14 / 17.0f) * 1.1f;
        }
        break;
    case 7:
        func_L01_003B28D0(s1->w0);
        ((void (*)(u8 *, s32, s32))func_L01_004450F0)(o, 1, -1);
        break;
    }
}
/* localdecomp:end func_L01_003B4FB0 */
