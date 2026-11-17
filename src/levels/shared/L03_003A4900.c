#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003A4900);

/* localdecomp:start func_L03_003A4FC8 */
typedef struct Vars_3A4FC8 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3A4FC8;
typedef struct Rec_3A4FC8 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    vu0_q pos;
    u8 pad40[0x40];
} Rec_3A4FC8;
extern u8 *D_L03_001DFA80;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
extern void func_0038CC88(void *, void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_003C2880(void *);
extern void func_L01_003F5E88(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003A4FC8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3A4FC8 *vars = *(Vars_3A4FC8 **)(obj + 0x68);
    f32 a;
    f32 b;
    u8 *dir;
    Rec_3A4FC8 *tbl;

    vars->f4 = 1.0f;
    vars->w14 = -1;
    vars->w8 = 0;
    vars->w10 = 0;
    if (vars->w18 < 10) {
        vars->w18 = (s32)((f32)vars->w18 * 50.0f);
    } else {
        vars->w18 = (vars->w18 * 5 + 2) / 6;
    }
    dir = obj + 0xC0;
    tbl = (Rec_3A4FC8 *)D_L03_001DFA80;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x145;
    *(vu0_q *)(obj + 0x10) = tbl[vars->w0].pos;
    func_0038CC88(dir, &((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0], 0x30);
    a = func_0038CEA8(((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0].e10);
    b = func_0038CEA8(((Rec_3A4FC8 *)D_L03_001DFA80)[vars->w0].e20);
    if (b < a) {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * a;
        func_0038CE20(obj + 0xD0, obj + 0xD0, b / a);
    } else {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * b;
        func_0038CE20(obj + 0xD0, obj + 0xD0, a / b);
    }
    func_003C7C38(obj);
    if (D_001BBC40[obj[0xB0] + (D_001D545C << 4)] & 0x80) {
        func_003C2880(obj);
        return;
    }
    func_L01_003F5E88(obj);
    if (vars->wC != 0) {
        vars->f4 = 0.0f;
        func_L01_004450F0(obj, 1, 1);
    } else {
        vars->f4 = 1.0f;
        func_L01_004450F0(obj, 2, 1);
    }
}
/* localdecomp:end func_L03_003A4FC8 */

/* localdecomp:start func_L03_003A51E0 */
extern s32 func_00382498(s32, s32);
extern void func_0038D570(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L03_002BA370[][4];
extern u8 *D_L03_001DFA80;

void func_L03_003A51E0(vu0_v4 *out, s32 idx) {
    vu0_v4 s[2];
    vu0_v4 m[4];
    vu0_v4 e;
    vu0_v4 r;
    vu0_v4 t;
    s32 n;
    s32 k;

    n = func_00382498(0, 5);
    k = func_00382498(0, 3);
    switch (k) {
    case 0:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][1];
        break;
    case 1:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][2];
        break;
    case 2:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][2];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    case 3:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][1];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    }
    func_0038D570(m, D_L03_001DFA80 + idx * 0x80);
    *(vu0_q *)&m[3] = *(vu0_q *)(D_L03_001DFA80 + idx * 0x80 + 0x30);
    m[3].w = 1.0f;
    vec_sub_ba(&r, &s[1], &s[0]);
    e = r;
    func_0038CE20(&e, &e, func_003824E0(0.0f, 1.0f));
    vec_add_ab(&t, &s[0], &e);
    r = t;
    *out = r;
    func_0038D028(out, out, m);
}
/* localdecomp:end func_L03_003A51E0 */

INCLUDE_ASM("asm/levels", func_L03_003A5388);
