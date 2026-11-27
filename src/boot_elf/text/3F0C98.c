#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F0FA0(u8 *arg0, s32, s32);
extern void func_003F0D80();
extern void func_003F0E00(void *, s32, s16, s16, s32);
extern void func_003F0D38(void *, s32);
extern void func_003F0E78(u8 *, s32, f32, f32);
extern void func_003F0DE8(void *, f32);
extern void func_003F0E28(void *, f32);
extern s32 func_003F0E40();
extern s32 func_003F0E58();
extern void func_003F1090(void *, s32);
extern void func_003F0EB8(u8 *, f32);
extern void func_003F0ED8(void *, s32);
extern void func_003F0F00(void *, s32);
extern void func_003F0F28(u8 *, s32, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003F0C98 */
/* the copy of func_003F08E0 */
s32 *func_003E6FC0(s32 *);                  /* extern */
void **func_003E7078(s32 *, s32);           /* extern */
void func_003F2738_003F0C98(void *);
extern u8 D_001D9670_003F0C98;
extern u8 D_001D97C8;
extern char D_001D9670[];
/* Retail reaches D_001D97C8 through lui/addiu, so it must not be small data:
   an unsized array is never small data (docs/wiki/Matching-Patterns.md). */
extern u8 D_001D97C8_003F0C98[];
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];

void func_003F0C98(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D97C8;
    if (D_001DA938->f4 != 0) {
        var_v0 = (s32 *)D_001DA938;
    } else {
        var_v0 = func_003E6FC0((s32 *)D_001DA938);
    }
    temp_v0 = func_003E7078(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D9670_003F0C98;
    if (arg1 & 1) {
        func_003F2738_003F0C98(arg0);
    }
}
/* localdecomp:end func_003F0C98 */

/* localdecomp:start func_003F0D38 */
void func_003F0D38(void *p, s32 value) {
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x34) = value;
}
/* localdecomp:end func_003F0D38 */

/* localdecomp:start func_003F0D48 */
void func_003F0D48(u8 *p) {
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
/* localdecomp:end func_003F0D48 */

/* localdecomp:start func_003F0D80 */
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003F0D48();
void func_003F0D80(S_3EB440 *p, s32 b) {
    Q_3EB440 *q = p->q;
    if (q->w10 != b && (q->h48 & 0x20)) {
        func_003F0D48((u8 *)p);
        p->b30 = 0;
        p->w34 = 0;
    }
    p->q->w10 = b;
}
/* localdecomp:end func_003F0D80 */

/* localdecomp:start func_003F0DE8 */
void func_003F0DE8(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0DE8 */

/* localdecomp:start func_003F0E00 */
void func_003F0E00(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
/* localdecomp:end func_003F0E00 */

/* localdecomp:start func_003F0E28 */
void func_003F0E28(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0E28 */

/* localdecomp:start func_003F0E40 */
s32 func_003F0E40(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003F0E40 */

/* localdecomp:start func_003F0E58 */
s32 func_003F0E58(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003F0E58 */

/* localdecomp:start func_003F0E78 */
void func_003F0E78(u8 *p, s32 a, f32 x, f32 y) {
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
/* localdecomp:end func_003F0E78 */

/* localdecomp:start func_003F0EB8 */
/* the same code as frontbin's func_003F0B00 */
void func_003F0EB8(u8 *p, f32 x) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = x * 0.8333333f;
}
/* localdecomp:end func_003F0EB8 */

/* localdecomp:start func_003F0ED8 */
void func_003F0ED8(void *arg0, s32 arg1) {
    *(s16 *)((u8 *)((*(void **)((u8 *)arg0 + 0x2C))) + 0x4C) = (s16) ((s32) ((arg1 * 5) + 2) / 6);
}
/* localdecomp:end func_003F0ED8 */

/* localdecomp:start func_003F0F00 */
void func_003F0F00(void *arg0, s32 arg1) {
    *(s16 *)((u8 *)((*(void **)((u8 *)arg0 + 0x2C))) + 0x54) = (s16) ((s32) ((arg1 * 5) + 2) / 6);
}
/* localdecomp:end func_003F0F00 */

/* localdecomp:start func_003F0F28 */
void func_003F0F28(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0F28 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F0F68);

/* localdecomp:start func_003F0F70 */
void func_003F0F70(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003F0F70 */

/* localdecomp:start func_003F0FA0 */
void func_003F0F28_003F0FA0(void *, s32, s32);

s32 func_003F0FA0(u8 *arg0, s32 arg1, s32 arg2) {
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
    func_003F0F28_003F0FA0(arg0, 1, a);
    func_003F0F28_003F0FA0(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_003F0FA0 */

/* localdecomp:start func_003F1030 */
extern void func_003EDF20(void *, f32, f32);
void func_003F1030(u8 *object, f32 *bounds) {
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
    func_003EDF20(object, x, y);
    *(volatile s32 *)(object + 0x34) = 0;
    *(volatile u8 *)(object + 0x30) = 0;
}
/* localdecomp:end func_003F1030 */

/* localdecomp:start func_003F1090 */
void func_003F1090(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F1090 */
