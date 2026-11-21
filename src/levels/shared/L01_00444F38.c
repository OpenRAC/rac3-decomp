#include "common.h"

/* localdecomp:start func_L01_00444F38 */
typedef struct { u8 pad0[0x11]; u8 count; } A_444F38;
typedef struct { u8 pad0[0x48]; A_444F38 *anims[1]; } C_444F38;
typedef struct {
    u8 pad0[0x24];
    C_444F38 *cls;
    u8 pad28[0x40 - 0x28];
    u8 anim_cur;
    u8 key;
    u8 anim_prev;
    u8 sequence;
    f32 blend_t;
    f32 blend_scale;
    f32 blend_rate;
    s32 w50;
    s32 w54;
    u8 pad58[0x60 - 0x58];
    u8 b60;
    u8 pad61[0x6C - 0x61];
    u8 anim_count;
    u8 pad6D[0x7E - 0x6D];
    u8 b7E;
    u8 pad7F[0x80 - 0x7F];
    f32 pose[4];
    u8 pad90[0xA9 - 0x90];
    u8 bA9;
} M_444F38;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_444F38;

extern Vec4_444F38 D_L01_001FCB40[];
extern void func_003C3938(M_444F38 *);
extern void func_003C6EA0(M_444F38 *, s32, u16);
extern s32 func_003C2D30(M_444F38 *);
extern void func_003C8B18(M_444F38 *, s32);
extern void func_003C29B0(M_444F38 *);

/* moby_anim_blend_flags: moby_anim_blend with a flags argument (1: bit 8 of the pose slot, 2: bit 9,
 * 4: force a new pose slot, 8: skip func_003C6EA0, 0x10: set b7E bit 4). */
void func_L01_00444F38(M_444F38 *moby, s32 sequence, s32 key, s32 ticks, s32 flags) {
    s32 r;
    s32 slot;

    if (ticks <= 0) {
        func_003C3938(moby);
        return;
    }
    if ((u32)(key - 1) < 10 && (flags & 8) == 0) {
        func_003C6EA0(moby, sequence, (u16)(key - 1));
    }
    if (moby->blend_t > 0.025f || moby->w50 != 0 || moby->w54 != 0 || (flags & 4) != 0) {
        r = func_003C2D30(moby);
        if (r >= 0) {
            slot = r;
            if (flags & 1) {
                slot = r | 0x100;
            }
            if (flags & 2) {
                slot |= 0x200;
            }
            func_003C8B18(moby, slot);
            D_L01_001FCB40[r] = *(Vec4_444F38 *)moby->pose;
            if (moby->anim_prev != 0xFF) {
                moby->bA9 = moby->anim_prev;
            }
            moby->anim_prev = 0xFF;
            moby->anim_cur = r;
        }
    }
    moby->key = key;
    moby->sequence = sequence;
    func_003C29B0(moby);
    moby->b60 &= ~2;
    moby->blend_scale = 1.0f;
    moby->blend_t = 0.0f;
    moby->blend_rate = 1.0f / (f32)ticks;
    moby->anim_count = ((A_444F38 *)moby->cls->anims[sequence])->count;
    if (flags & 0x10) {
        moby->b7E |= 4;
    } else {
        moby->b7E &= ~4;
    }
}
/* localdecomp:end func_L01_00444F38 */

/* localdecomp:start func_L01_004450F0 */
/* from rac2-decomp's func_002A7750, renamed */
void func_L01_004450F0(u8 *a0,s32 a1,s32 a2) {
 u8 old=a0[0x20];a0[0x20]=(u8)a1;a0[0x94]=old;*(short *)(a0+0x96)=0;
 a0[0xbe]&=~1;
 if(a2!=-1){a0[0x95]=(u8)a2;a0[0xbe]&=~2;}
}
/* localdecomp:end func_L01_004450F0 */

/* localdecomp:start func_L01_00445130 */
void func_L01_00445130(u8 *obj, s32 state, s32 arg) {
    if (obj[0x20] != state) {
        obj[0x94] = obj[0x20];
        obj[0x20] = state;
        *(s16 *)(obj + 0x96) = 0;
        obj[0xBE] &= 0xFE;
        if (arg != -1) {
            obj[0x95] = arg;
            obj[0xBE] &= 0xFD;
        }
    }
}
/* localdecomp:end func_L01_00445130 */

/* localdecomp:start func_L01_00445170 */
void func_L01_00445170(u8 *a, u8 v) {
    a[149] = v;
    a[190] &= ~2;
}
/* localdecomp:end func_L01_00445170 */

/* localdecomp:start func_L01_00445188 */
void func_L01_00445188(u8 *a, u8 v) {
    a[188] = v;
    a[190] &= ~0x20;
}
/* localdecomp:end func_L01_00445188 */

/* localdecomp:start func_L01_004451A0 */
float func_L01_004451A0(float x) {
    return x * x;
}
/* localdecomp:end func_L01_004451A0 */

/* localdecomp:start func_L01_004451A8 */
f32 func_L01_004451A8(f32 t) {
    t = 1.0f - t;
    return 1.0f - t * t;
}
/* localdecomp:end func_L01_004451A8 */

LINKER_REMNANT("asm/levels", func_L01_004451C8);

/* localdecomp:start func_L01_004451D0 */
f32 func_L01_004451D0(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 t2 = t * t;
    f32 a = (p3 - p2) - (p0 - p1);
    f32 b = (p0 - p1) - a;
    return a * (t2 * t) + b * t2 + (p2 - p0) * t + p1;
}
/* localdecomp:end func_L01_004451D0 */

/* localdecomp:start func_L01_00445208 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_445208;

/* vec_cubic: a point on a cubic curve of vectors, start at t 0 and end at t 1 (bow and far
 * shape it between); the Spitting Hydra lays its arcs' points on it. Per axis as 0x4451D0,
 * with the three coefficients in locals that every axis reuses. */
void func_L01_00445208(f32 t, Vec_445208 *out, Vec_445208 *start, Vec_445208 *end, Vec_445208 *bow, Vec_445208 *far) {
    f32 t2;
    f32 t3;
    f32 a;
    f32 b;
    f32 c;

    if (t == 0.0f) {
        *out = *start;
        return;
    }
    if (t == 1.0f) {
        *out = *end;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    a = (far->x - end->x) - (bow->x - start->x);
    b = (bow->x - start->x) - a;
    c = end->x - bow->x;
    out->x = a * t3 + b * t2 + c * t + start->x;
    a = (far->y - end->y) - (bow->y - start->y);
    b = (bow->y - start->y) - a;
    c = end->y - bow->y;
    out->y = a * t3 + b * t2 + c * t + start->y;
    a = (far->z - end->z) - (bow->z - start->z);
    b = (bow->z - start->z) - a;
    c = end->z - bow->z;
    out->z = a * t3 + b * t2 + c * t + start->z;
    out->w = 0.0f;
}
/* localdecomp:end func_L01_00445208 */
