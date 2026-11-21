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

/* declared by functions of L01_003B2688.c, which this file was cut from */
extern void func_L01_004450F0(s32, s32, s32);

/* localdecomp:start func_L01_003B2AA0 */
typedef struct {
    u8 pad0[0x14];
    void (*f14)(s32);
    u8 pad18[4];
    s32 (*f1C)(void);
    u8 pad20[4];
    void (*f24)(s32, s32);
    void (*f28)(s32);
    void (*f2C)(void *, f32);
} V_003B2AA0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[4];
    s32 w18;
    u8 pad1C[0x2C - 0x1C];
    f32 f2C;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 pad3C[4];
    s32 w40;
    u8 pad44[4];
    s32 w48;
    u8 pad4C[4];
    u8 b50;
    u8 pad51[0x5C - 0x51];
    s32 w5C;
    s32 w60;
} A_003B2AA0;
typedef struct {
    u8 pad0[0x25C4];
    s32 state;
} H_003B2AA0;
extern H_003B2AA0 D_001A4BE0;
extern s32 D_L01_001DFB40 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DFB40, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
__asm__(".extern D_001BBC40, 16");
extern u8 D_001426E0[];
extern u8 *D_L01_001E001C_003B2AA0;
__asm__(".extern D_L01_001E001C_003B2AA0, 16");
extern void *func_L01_0043B548(s32, s32);
extern void func_00392DF0(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_003B29A8(u8 *);
extern s32 func_L01_00511A98(void);
extern void func_L01_00504E38(s32);
extern void func_L01_003B3098(u8 *);
extern void func_L01_0045F1E8(s32, s32);

void func_L01_003B2AA0(void *arg0, void *arg1) {
    u8 *a0 = arg0;
    A_003B2AA0 *a1 = arg1;
    V_003B2AA0 *v = func_L01_0043B548(0x19E1, 0x6C);
    s32 flag;

    a1->w60 = D_L01_001DFB40;
    if (a1->w5C != -1 && !(D_001BBC40[a1->w5C + D_001D545C * 16] & 0x80)) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (a1->w30 != 0) {
        if (a1->b50 != 0) {
            if (a1->b50 != 0xFF) {
                if (a1->w40 != 0) {
                    u32 t = (a1->w40 & 0x7FF) | ((a1->b50 & 0x1F) << 11);
                    D_001426E0[0x72] = t;
                    D_001426E0[0x71] = t >> 8;
                }
                func_00392DF0(a1->b50, 1);
            } else {
                func_00392DF0(-1, 1);
            }
            return;
        }
        v->f24(a1->w34, flag);
        func_L01_004450F0((s32)a0, 0xB, -1);
        if (a1->w10 == -1 || flag) {
            if (D_001A4BE0.state != 0xB0) {
                v->f28(flag);
                if (flag || a1->f2C != 0.0f) {
                    v->f2C(&D_001A4BE0, -100.0f);
                } else if (a1->f2C == 0.0f) {
                    func_L01_005003D0(0, 1);
                }
            }
        }
    } else {
        if (v->f1C()) {
            v->f24(-2, flag);
            if (a1->w10 == -1 || flag) {
                if (D_001A4BE0.state != 0xB0) {
                    v->f28(flag);
                    v->f2C(0, -100.0f);
                }
            }
        }
        if (flag) {
            func_L01_004450F0((s32)a0, 5, -1);
        } else {
            func_L01_004450F0((s32)a0, 7, -1);
        }
    }
    if (a1->w10 != -1 && !flag) {
        v->f14(a1->w38);
        func_L01_003B29A8(a0);
        if (a1->w30 != 0) {
            if (v->f1C()) {
                if (a1->f2C != 0.0f) {
                    v->f2C(&D_001A4BE0, -100.0f);
                }
            }
        }
    } else {
        if (D_001A4BE0.state != 0xB0) {
            if (!func_L01_00511A98()) {
                func_L01_00504E38(0);
            }
        }
    }
    if (a1->w30 == 0) {
        func_L01_003B3098(D_L01_001E001C_003B2AA0 + (a1->w18 << 8));
    }
    if (a1->w48 != -1) {
        func_L01_0045F1E8(a1->w48, -1);
    }
}
/* localdecomp:end func_L01_003B2AA0 */
