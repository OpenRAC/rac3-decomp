#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
extern void func_003F09C8();
extern void func_003F0A48(void *, s32, s16, s16, s32);
extern void func_003F0980(void *, s32);
extern void func_003F0AC0(u8 *, s32, f32, f32);
extern void func_003F0A30(void *, f32);
extern void func_003F0A70(void *, f32);
extern s32 func_003F0A88();
extern s32 func_003F0AA0();
extern void func_003F0CD8(void *, s32);
extern void *malloc(s32, s32) __asm__("func_003F2388");
typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s16 f18, f1A;
    s32 f1C;
    u8 f20;
    s16 f22;
    f32 f24, f28;
    s32 f2C, f30;
    u32 f34, f38;
    s32 f3C, f40, f44;
    u8 p48[2];
    u8 f4A;
    u8 p4B[0x56 - 0x4B];
    s16 f56;
    u8 p58;
    u8 f59, f5A;
} O_3EB180;
typedef struct { u8 p0[8]; void *f8; u8 pC[0x2C - 0xC]; O_3EB180 *f2C; u8 f30; s32 f34; } T_3EB180;
extern void *__nw(s32, s32) __asm__("func_003F2388");
extern void func_003F0B00(u8 *, f32);
extern void func_003F0B20(T_3EB180 *, s32);
extern void func_003F0B48(u8 *, s32);
extern void func_003F0B70(u8 *, s32, s32);
/* --- end of declarations from other files --- */

/* declarations of 3ED988.c's earlier functions */
extern void func_003EDB68(void *, f32, f32);
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDAF8();
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDAF8(void *, s32);
extern char D_001D9670[];
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 *func_003E6C08();
void **func_003E6CC0(s32 *, s32);
extern s32 func_003EDAF8(void *p, s32 mask);
extern void func_003EDB40(void *p, s32 *a, s32 *b);
extern void func_003EDB68(void *p, f32 x, f32 y);
extern s32 func_003EDBA8(s32 p, s32 k);
extern s32 func_003EDBD8(O_3E8670 *a, s32 b);
extern void func_003EDC30(S_3E86C8 *a, s32 b);
extern void func_003EDC80(void *arg0, s32 arg1);
extern void func_003EDCF0(void *a, f32 *b);
extern void func_003EDD40(f32 a, f32 b, f32 c, f32 d);

/* Near miss of func_003F08E0 with its file's own flags: tools/check.py reports 5 diff
   (the version it replaces: 38).
   What differs: Only the materialization of &D_001DA938 differs: retail `lui $v1,
   %hi(D_001DA938)` (high half in a scratch, computed at the top) + `addiu $a0, $v1,
   %lo(D_001DA938)` (low half added into $a0) — the split-address form; ours `lui $a0,
   %hi(D_001DA938)` + `addiu $a0, $a0, %lo(D_001DA938)` — the whole address in one register,
   which is what `-mno-split-addresses` (this file's flag) makes gcc emit; every other
   instruction now matches.
*/

/* US draft of func_003F08E0 (rac3-uya-decomp func_003EB358, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003F08E0 */
s32 *func_003E6C08(s32 *);                  /* extern */
void **func_003E6CC0(s32 *, s32);           /* extern */
void func_003F2380_003F08E0(void *);
extern u8 D_001D9670_003F08E0;
extern u8 D_001D97C8;
extern char D_001D9670[];
/* Retail reaches D_001D97C8 through lui/addiu, so it must not be small data:
   an unsized array is never small data (docs/wiki/Matching-Patterns.md). */
extern u8 D_001D97C8_003F08E0[];
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];

void func_003F08E0(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D97C8;
    if (D_001DA938->f4 != 0) {
        var_v0 = (s32 *)D_001DA938;
    } else {
        var_v0 = func_003E6C08((s32 *)D_001DA938);
    }
    temp_v0 = func_003E6CC0(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D9670_003F08E0;
    if (arg1 & 1) {
        func_003F2380_003F08E0(arg0);
    }
}
/* localdecomp:end func_003F08E0 */

/* localdecomp:start func_003F0980 */
void func_003F0980(void *p, s32 value) {
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x34) = value;
}
/* localdecomp:end func_003F0980 */

/* localdecomp:start func_003F0990 */
void func_003F0990(u8 *p) {
    u8 *q;
    s32 v;
    (*(u8 **)(p + 0x2C))[0x59] = 0;
    q = *(u8 **)(p + 0x2C);
    v = 0;
    if (*(u16 *)(q + 0x48) & 8) v = *(u16 *)(q + 0x4C);
    *(s16 *)(q + 0x56) = v;
    (*(u8 **)(p + 0x2C))[0x5A] = 0;
    *(s32 *)(*(u8 **)(p + 0x2C) + 0x40) = 0;
}
/* localdecomp:end func_003F0990 */

/* localdecomp:start func_003F09C8 */
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003F0990();
void func_003F09C8(S_3EB440 *p, s32 b) {
    Q_3EB440 *q = p->q;
    if (q->w10 != b && (q->h48 & 0x20)) {
        func_003F0990((u8 *)p);
        p->b30 = 0;
        p->w34 = 0;
    }
    p->q->w10 = b;
}
/* localdecomp:end func_003F09C8 */

/* localdecomp:start func_003F0A30 */
void func_003F0A30(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0A30 */

/* localdecomp:start func_003F0A48 */
void func_003F0A48(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
/* localdecomp:end func_003F0A48 */

/* localdecomp:start func_003F0A70 */
void func_003F0A70(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0A70 */

/* localdecomp:start func_003F0A88 */
s32 func_003F0A88(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003F0A88 */

/* localdecomp:start func_003F0AA0 */
s32 func_003F0AA0(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003F0AA0 */

/* localdecomp:start func_003F0AC0 */
void func_003F0AC0(u8 *p, s32 a, f32 x, f32 y) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x3C) = x;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x40) = y;
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x56) = 0;
    {
        u8 *q = *(u8 **)(p + 0x2C);
        if (a != 0) q[0x59] = 0;
        else q[0x59] = 1;
    }
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0AC0 */

/* localdecomp:start func_003F0B00 */
void func_003F0B00(u8 *p, f32 x) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = x * 0.8333333f;
}
/* localdecomp:end func_003F0B00 */

/* localdecomp:start func_003F0B20 */
void func_003F0B20(T_3EB180 *p, s32 a) {
    *(u16 *)((u8 *)p->f2C + 0x4C) = (a * 5 + 2) / 6;
}
/* localdecomp:end func_003F0B20 */

/* localdecomp:start func_003F0B48 */
/* func_003F0B48 */

void func_003F0B48(u8 *p, s32 a) {
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x54) = (a * 5 + 2) / 6;
}
/* localdecomp:end func_003F0B48 */

/* localdecomp:start func_003F0B70 */
void func_003F0B70(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0B70 */

LINKER_REMNANT("asm/remnants", func_003F0BB0);

/* localdecomp:start func_003F0BB8 */
void func_003F0BB8(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003F0BB8 */

/* localdecomp:start func_003F0BE8 */
void func_003F0B70_003F0BE8(void *, s32, s32);

s32 func_003F0BE8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 a = 0;
    s32 ok = 1;
    s32 b = 0;

    if (arg1 != 0) {
        if (arg1 == 1) {
            a = 1;
        } else {
            ok = 0;
        }
    }
    if (arg2 == 0) {
        b = 1;
    } else if (arg2 != 1) {
        ok = 0;
    }
    func_003F0B70_003F0BE8(arg0, 1, a);
    func_003F0B70_003F0BE8(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_003F0BE8 */

/* localdecomp:start func_003F0C78 */
extern void func_003EDB68(void *, f32, f32);
void func_003F0C78(u8 *object, f32 *bounds) {
    register f32 x __asm__("$f12") = bounds[0];
    register f32 half __asm__("$f2") = 0.5f;
    register f32 temp __asm__("$f1") = bounds[2];
    register f32 y __asm__("$f13") = bounds[1];
    register f32 other __asm__("$f0") = bounds[3];
    temp -= x;
    other -= y;
    temp *= half;
    x += temp;
    temp = other * half;
    y += temp;
    func_003EDB68(object, x, y);
    *(volatile s32 *)(object + 0x34) = 0;
    *(volatile u8 *)(object + 0x30) = 0;
}
/* localdecomp:end func_003F0C78 */

/* localdecomp:start func_003F0CD8 */
void func_003F0CD8(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0CD8 */

typedef struct {
    u8 p00[0x10];
    s32 f10;
    s32 f14;
    s16 h18;
    s16 h1A;
    u8 p1C[0xC];
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 f34;
    u32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u16 h48;
    u16 p4A;
    u16 h4C;
    u16 p4E;
    f32 f50;
    u16 h54;
    u16 h56;
    u8 b58;
    u8 b59;
    u8 b5A;
} P_3EB728;
typedef struct {
    u8 p00[0x20];
    void (*f20)(void *, s32, f32 *, s32);
} VT_3EB728;
typedef struct {
    u8 p00[8];
    VT_3EB728 *vt;
    u8 p0C[0x14];
    f32 f20;
    f32 f24;
    u32 f28;
    P_3EB728 *p;
    u8 b30;
    u8 p31[3];
    f32 f34;
} O_3EB728;
typedef struct {
    s16 y0, y1, x0, x1, tx, ty, w, h, f30, flags, f34, f36, f38, f3A;
} Desc_3EB728;
extern f32 D_001D9690;
extern f32 D_001D9694;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 D_001D55C4;
extern s32 D_003357E0[];
extern void func_0038E150(s32);
extern void func_003EDCF0(void *, f32 *);
extern void func_00391210();
extern void func_003911F0();
extern void func_00390CC8(void);
extern void func_00390CA8(void);
extern void func_003E7160(void);
extern long func_00389598(s32);
