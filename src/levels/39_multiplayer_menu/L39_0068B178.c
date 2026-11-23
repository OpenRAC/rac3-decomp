#include "common.h"

/* declared by functions of L39_0068A8F8.c, which this file was cut from */
s32 func_L39_0068B3C0();

/* localdecomp:start func_L39_0068B178 */
typedef struct S_68B178_B {
    char _p0[0x4];
    s32 f4;
} S_68B178_B;
typedef struct S_68B178_A {
    char _p0[0x10C];
    s32 f10C;
    S_68B178_B *f110[1];
} S_68B178_A;

/* from rac4-decomp's func_L00_0071B768 */
s32 func_L39_0068B178(S_68B178_A *arg0) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < arg0->f10C; i++) {
        if (arg0->f110[i]->f4 >= 3) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L39_0068B178 */

/* localdecomp:start func_L39_0068B1E0 */
typedef struct { u8 pad0[4]; s32 f4; } E_0068B1E0;
typedef struct { u8 pad0[0x10C]; s32 count; E_0068B1E0 *items[1]; } L_0068B1E0;

s32 func_L39_0068B1E0(L_0068B1E0 *self, s32 start) {
    s32 found = -1;
    s32 i;
    s32 idx;
    s32 n;
    if (start == -1) start = *(s32 *)((u8 *)self + 0x290);
    for (i = 0; i < self->count; i++) {
        n = self->count;
        idx = (start + 1 + i) % n;
        if (self->items[idx]->f4 >= 3) { found = idx; break; }
    }
    return found;
}
/* localdecomp:end func_L39_0068B1E0 */

/* localdecomp:start func_L39_0068B260 */
typedef struct { s32 unk0; s32 unk4; } S_0068B260_E;
typedef struct { u8 pad[0x10C]; s32 unk10C; S_0068B260_E *unk110[(0x290 - 0x110) / 4]; s32 unk290; } S_0068B260;
s32 func_L39_0068B260(S_0068B260 *arg0, s32 arg1) {
    s32 r = -1;
    s32 i;
    if (arg1 == -1) {
        arg1 = arg0->unk290;
    }
    if (arg1 == -1) {
        arg1 = 0;
    }
    for (i = 0; i < arg0->unk10C; i++) {
        s32 idx = (arg1 - 1 - i + arg0->unk10C) % arg0->unk10C;
        if (arg0->unk110[idx]->unk4 >= 3) {
            r = idx;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L39_0068B260 */

/* localdecomp:start func_L39_0068B2F8 */
typedef struct E_0068B2F8 E_0068B2F8;
typedef struct { u8 pad0[0x1C]; void (*msg)(E_0068B2F8 *, s32, s32); } V_0068B2F8;
struct E_0068B2F8 { u8 pad0[4]; s32 f4; u8 pad8[0x58]; V_0068B2F8 *vt; };
typedef struct { u8 pad0[0x110]; E_0068B2F8 *items[1]; } L_0068B2F8;
extern void func_L01_0041BE20(s32);

s32 func_L39_0068B2F8(L_0068B2F8 *self, s32 sel, s32 arg) {
    s32 old = *(s32 *)((u8 *)self + 0x290);
    E_0068B2F8 *e;

    if (old >= 0) {
        e = self->items[old];
        if (e->f4 >= 3) {
            e->vt->msg(e, 3, 0);
        }
    }
    *(s32 *)((u8 *)self + 0x290) = sel;
    if (sel >= 0) {
        e = self->items[sel];
        if (e->f4 >= 3) {
            e->vt->msg(e, 4, arg);
        } else {
            *(s32 *)((u8 *)self + 0x290) = -1;
        }
    }
    func_L01_0041BE20(1);
    return old;
}
/* localdecomp:end func_L39_0068B2F8 */

/* localdecomp:start func_L39_0068B3C0 */
typedef struct {
    s32 pad0;
    s32 unk4;
} S1_68B3C0;
typedef struct {
    u8 pad0[0x110];
    S1_68B3C0 *unk110[(0x290 - 0x110) / 4];
    s32 unk290;
} S0_68B3C0;
s32 func_L39_0068B1E0();
s32 func_L39_0068B2F8();

/* from rac4-decomp's func_L00_0071B9B0 */
s32 func_L39_0068B3C0(S0_68B3C0 *arg0) {
    s32 temp_s1;
    s32 temp_v1;
    s32 var_v0;
    temp_s1 = arg0->unk290;
    if (temp_s1 == -1) {
        var_v0 = func_L39_0068B178((S_68B178_A *)arg0);
        goto block_4;
    }
    temp_v1 = arg0->unk110[temp_s1]->unk4;
    if (temp_v1 < 3) {
        var_v0 = func_L39_0068B1E0(arg0, -1);
block_4:
        func_L39_0068B2F8(arg0, var_v0, 0);
        return temp_s1;
    }
    if (temp_v1 < 4) func_L39_0068B2F8(arg0, temp_s1, 0);
    return temp_s1;
}
/* localdecomp:end func_L39_0068B3C0 */
