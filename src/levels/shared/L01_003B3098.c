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
extern void func_L01_004450F0(s32, s32, s32);
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE634;
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;

/* localdecomp:start func_L01_003B3098 */
extern void func_L01_00456230(u8 *, s32);
extern s32 D_L01_001DFB40_003B3098;
__asm__(".extern D_L01_001DFB40_003B3098, 16");
extern s16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern u8 *D_L01_001E001C_003B3098;
__asm__(".extern D_L01_001E001C_003B3098, 16");
extern void func_L01_003B5FD8(u8 *);
extern void func_L01_003B4840(u8 *, u8 *);
extern void func_L01_00327038(u8 *);

void func_L01_003B3098(u8 *m) {
    u8 *vars = *(u8 **)(m + 0x68);
    s16 *q;

    D_L01_001DE630 = (s32)m;
    func_L01_00456230(m, 1);
    *(s32 *)(vars + 4) = D_L01_001DFB40_003B3098;
    if (*(s32 *)(vars + 0xC) != -1) {
        q = D_L01_0021DE20[*(s32 *)(vars + 0xC)];
        while ((*(s32 *)(vars + 0xC) & 0xFF) != 0xFF && *(s32 *)(vars + 0xC) <= D_L01_001E0058 && q != 0 &&
               (q[-1] >= 0 || q == D_L01_0021DE20[*(s32 *)(vars + 0xC)])) {
            u8 *r = D_L01_001E001C_003B3098 + ((*(u16 *)q & 0x7FFF) << 8);
            if (r == 0) break;
            func_L01_003B5FD8(r);
            q++;
        }
    }
    func_L01_003B4840(m, vars);
    func_L01_00327038(m);
    *(u16 *)(m + 0x34) &= ~2;
    *(s32 *)(vars + 0x2C) = 0;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(m, 2, -1);
}
/* localdecomp:end func_L01_003B3098 */

/* localdecomp:start func_L01_003B31B8 */
extern void func_L01_003B4D58(void *a, u8 *b);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_003B6108(u8 *obj);
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE634;
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;
extern s32 D_L01_001E0058;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_003B31B8;
__asm__(".extern D_L01_001E001C_003B31B8, 16");

void func_L01_003B31B8(void *a0, u8 *a1) {
    u8 *v = *(u8 **)((u8 *)a0 + 0x68);
    u8 *p;
    s16 *s;
    func_L01_003B4D58(a0, v);
    D_L01_001DE630 = 0;
    func_L01_00456230(a0, 0);
    if (a1 == 0 || *(s16 *)(a1 + 0xAA) == 0x19E4) {
        p = (u8 *)D_L01_001DE634;
        D_L01_001DE638 = 0;
        D_L01_001DE63C = 0;
        D_L01_001DE640 = 0;
        D_L01_001DE644 = 0;
        D_L01_001DE648 = 0;
        if (p != 0) {
            do {
                u8 *q = *(u8 **)(p + 0x68);
                p = *(u8 **)(q + 0x58);
                *(s32 *)(q + 0x58) = 0;
                *(s32 *)(q + 0x54) = 0;
            } while (p != 0);
            D_L01_001DE634 = 0;
        }
    } else {
        p = (u8 *)D_L01_001DE634;
        if (p != 0) {
            u8 *head = p;
            u8 *prev = 0;
            u8 *q;
            do {
                q = *(u8 **)(p + 0x68);
                if (--*(s32 *)(q + 0x54) == 0) {
                    p = *(u8 **)(q + 0x58);
                    if (prev != 0) {
                        q = *(u8 **)(prev + 0x68);
                        *(u8 **)(q + 0x58) = p;
                    } else {
                        *(u8 **)(q + 0x58) = 0;
                        head = p;
                    }
                } else {
                    prev = p;
                    p = *(u8 **)(q + 0x58);
                }
            } while (p != 0);
            D_L01_001DE634 = (s32)head;
        }
    }
    if (*(s32 *)(v + 0xC) != -1) {
        for (s = D_L01_0021DE20[*(s32 *)(v + 0xC)];
             (*(s32 *)(v + 0xC) & 0xFF) != 0xFF && *(s32 *)(v + 0xC) <= D_L01_001E0058 && s != 0 && (s[-1] >= 0 || s == D_L01_0021DE20[*(s32 *)(v + 0xC)]);
             s++) {
            p = D_L01_001E001C_003B31B8 + ((*(u16 *)s & 0x7FFF) << 8);
            if (p == 0) break;
            func_L01_003B6108(p);
        }
    }
    ((void (*)(void *, s32, s32))func_L01_004450F0)(a0, 1, -1);
}
/* localdecomp:end func_L01_003B31B8 */

INCLUDE_ASM("asm/levels", func_L01_003B3368);
