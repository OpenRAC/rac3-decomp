#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006C20B0);

/* localdecomp:start func_L39_006C2C40 */
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_00241640;
typedef struct {
    char pad0[0xE0];
    s16 hE0[8];
    s16 hF0[1];
} S_241640_006C2C40;
extern S_241640_006C2C40 *D_001D5F30_sda;
extern s32 D_003D28BC __attribute__((section(".data")));

typedef struct {
    char pad0[0x128];
    s32 w128;
    char pad12C[4];
    s32 w130;
    char pad134[0x34];
    u8 b168;
} S_1A5CD0_006C2C40;
extern S_1A5CD0_006C2C40 D_001A5CD0 __attribute__((section(".data")));

typedef struct V_006C2C40 V_006C2C40;
typedef struct {
    void (*fn[32])(V_006C2C40 *, ...);
} VT_006C2C40;
struct V_006C2C40 {
    char pad[0x60];
    VT_006C2C40 *vt;
};

extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_00381FF0(s32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, s32);
s32 func_L01_005170B8(s32, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);
extern s32 func_L39_006C4788(void *, s32);
extern s32 func_L39_006C46F0(void *, s32);


void func_L39_006C2C40(u8 *obj) {
    u8 buf[64];
    s32 idx;
    s32 r;
    s32 flag;

    if (D_L39_00241640 != 0 && *(s16 *)(D_L39_00241640 + 0xF0) >= 7) {
        s32 n;
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[7](o, 0, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[7](o, 2, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[19](o, 0x40, 0);
        n = (*(s32 *)(D_L39_00241640 + 0x174) - D_001A5CD0.w128) / 1000 + 1;
        func_00120048(buf, (u8 *)func_00381FF0(0x1876), n);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[7](o, 1, 0);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[16](o, 1);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[19](o, 0x40, 1);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[9](o, buf);
    } else if (D_001A5CD0.b168 != 0) {
        V_006C2C40 *o;
        if (obj[0x2A8] != 0) {
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[8](o, 3, 0);
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[19](o, 0x40, 1);
        } else {
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[8](o, 2, 0);
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[19](o, 0x40, 0);
        }
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[7](o, 0, 0);
    } else {
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[7](o, 3, 0);
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[19](o, 0x40, 1);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[7](o, 0, 0);
    }

    if (D_001A5CD0.w130 < *(s32 *)(obj + 0x2F8)) {
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[8](o, 3, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[19](o, 0x40, 1);
    } else {
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[8](o, 2, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[19](o, 0x40, 0);
    }

    idx = *(s32 *)(obj + 0x290) - 0xF;
    if ((u32)idx < 0x28) {
        S_241640_006C2C40 *g;
        if (D_001A5CD0.b168 != 0 && (g = D_001D5F30_sda) != 0 && g->hE0[idx] == -1) {
            func_L39_00689D28(obj, func_00381FF0(0x1669));
        } else {
            func_L39_00689D28(obj, func_00381FF0(0x1254));
        }
    } else {
        func_L39_00689D28(obj, func_00381FF0(0x124));
    }

    flag = 0;
    r = func_L39_006C4788(obj, 0);
    if (r >= 0) {
        S_241640_006C2C40 *g;
        s32 t;
        r = func_L39_006C46F0(obj, r);
        g = (S_241640_006C2C40 *)D_L39_00241640;
        t = 0;
        if (g != 0 && r >= 0) {
            t = g->hF0[r] == 6;
        }
        flag = t;
    }

    func_L39_00689E58(obj, flag ? func_00381FF0(0x16D9) : func_00381FF0(0x1102), 0x706EC8FF, 1.0f, 1.0f);

    if (*(s32 *)(obj + 0x2BC) > 0xC8 && !flag) {
        f32 f = func_0038D0B0((f32)((*(s32 *)(obj + 0x2BC) - 0xC8) % 45) / 45.0f * 6.2831855f - 3.1415927f);
        s32 c = func_0038DBD8(f * 0.5f + 0.5f, 0x706EC8FF, -1);
        func_L01_005170B8(D_003D28BC, c);
    } else if (*(s32 *)(obj + 0x2BC) == 0) {
        func_L01_005170B8(D_003D28BC, 0x706EC8FF);
    }
}
/* localdecomp:end func_L39_006C2C40 */

INCLUDE_ASM("asm/levels", func_L39_006C30A0);

INCLUDE_ASM("asm/levels", func_L39_006C3670);

INCLUDE_ASM("asm/levels", func_L39_006C3778);

INCLUDE_ASM("asm/levels", func_L39_006C38E0);

INCLUDE_ASM("asm/levels", func_L39_006C3AA8);
