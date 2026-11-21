/* functional: medium. Written from the PAL asm only. Initialises an enemy/mob spawner object (state byte 0x30, counters and slot tables), optionally spawns its linked mob and arms it, then derives a facing basis (three vectors copied into the object at 0xC0..0xE0) from a world-table entry, and when a "ready" flag is set and the per-world tables allow it, picks the next-slot vectors and replaces the cached sub-object. Differs from retail: xyz vector sub/add are plain C helpers (file flags lack -mvu0-use-vf0-vf2); they keep the first operand's w. Unsure: what the two byte tables (D_001BBC40/D_001BBB18) mean; they are indexed as retail does (world*16+byte, world*8+slot). */
#include "common.h"
#include "vu0.h"

static void vadd(vu0_v4 *d, const vu0_v4 *a, const vu0_v4 *b) {
    vu0_v4 r;
    r.x = a->x + b->x; r.y = a->y + b->y; r.z = a->z + b->z; r.w = a->w;
    *d = r;
}
static void vsub(vu0_v4 *d, const vu0_v4 *a, const vu0_v4 *b) {
    vu0_v4 r;
    r.x = a->x - b->x; r.y = a->y - b->y; r.z = a->z - b->z; r.w = a->w;
    *d = r;
}

extern s32 D_001D545C;
extern u8 *D_L04_001DFE80;
extern u8 D_001BBC40[][16];
extern u8 D_001BBB18[][8];
extern u8 *func_L04_003BB468(u8 *);
extern u8 *func_L04_003BB5A0(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L04_003796C8(u8 *);
extern u8 *func_L04_00379410(void *);

void func_L04_0035A158(void *op, void *mp) {
    u8 *o = op;
    u8 *m = mp;
    vu0_v4 t0, t1, t2;
    u8 *mob;
    s32 a, r, i;
    u8 *ent;

    o[0x30] = 0x20;
    *(s16 *)(o + 0x32) = 0x20;
    *(s32 *)(m + 0x00) = 0;
    *(s32 *)(m + 0x04) = 0;
    *(s32 *)(m + 0x08) = 0;
    *(s32 *)(m + 0x30) = 0;
    a = *(s32 *)(m + 0x14);
    if (a < 2) {
        if (a < 0) *(s32 *)(m + 0x14) = 0;
    } else {
        *(s32 *)(m + 0x14) = 1;
    }
    a = *(s32 *)(m + 0x0C);
    if (a == -1 && *(s32 *)(m + 0x10) == a) {
        r = 1;
    } else {
        r = *(s32 *)(m + 0x14);
    }
    *(s32 *)(m + 0x18) = r;
    *(s32 *)(m + 0x2C) = 0;
    for (i = 0; i < 4; i++) {
        *(s32 *)(m + 0x70 + i * 0x30) = 0;
        *(s32 *)(m + 0x74 + i * 0x30) = 0;
        *(s32 *)(m + 0x110 + i * 0x10) = 0;
        *(s32 *)(m + 0x114 + i * 0x10) = 0;
        *(s32 *)(m + 0x118 + i * 0x10) = 0;
        *(s32 *)(m + 0x11C + i * 0x10) = 0;
    }
    *(s32 *)(m + 0x44) = -1;
    *(s32 *)(m + 0x40) = -1;
    a = *(s32 *)(m + 0x20);
    mob = 0;
    if (a != -1) {
        if (a == 0) {
            mob = func_L04_003BB468(o);
        } else {
            mob = func_L04_003BB5A0(o);
        }
    }
    o[0x30] = 0xFE;
    if (D_001D545C == 11) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
    }
    if (*(s32 *)(m + 0x48) != 0 && mob != 0) {
        u16 fl = *(u16 *)(mob + 0x34);
        *(s32 *)(mob + 0x98) = 0;
        fl |= 0x41;
        fl &= 0xEFFF;
        *(u16 *)(mob + 0x34) = fl;
        func_L01_004AA7E8(mob, 1);
    }
    a = *(s32 *)(m + 0x4C);
    if (a != -1) {
        ent = D_L04_001DFE80 + (a << 7);
        *(u16 *)(o + 0x34) |= 0x100;
        vsub(&t0, (vu0_v4 *)(ent + 0x30), (vu0_v4 *)(o + 0x10));
        func_0038CF68(&t0, &t0, 1.0f);
        func_003C5180(o + 0x10, &t1, 1);
        func_0038CF68(&t1, &t1, 1.0f);
        func_0038CE90(&t2, &t0, &t1);
        func_0038CF68(&t2, &t2, 1.0f);
        *(vu0_v4 *)(o + 0xC0) = t0;
        *(vu0_v4 *)(o + 0xD0) = t2;
        *(vu0_v4 *)(o + 0xE0) = t1;
    }
    if (*(s32 *)(m + 0x1C) != 0) {
        u8 c = o[0xB0];
        s32 take = 0;
        if (c != 0xFF && (D_001BBC40[D_001D545C][c] & 0x80)) {
            take = 1;
        } else {
            a = *(s32 *)(m + 0x34);
            if (a == -1) goto done;
            if (D_001BBB18[D_001D545C][a] == 0) goto done;
            take = 1;
        }
        r = *(s32 *)(m + 0x14) ^ 1;
        *(s32 *)(m + 0x2C) = 0;
        *(s32 *)(m + 0x18) = r;
        if (*(s32 *)(m + 0x1C) != 0) {
            *(s32 *)(m + 0x10) = -1;
            *(s32 *)(m + 0x0C) = -1;
        }
        a = *(s32 *)(m + 0x38);
        if (a != -1) {
            f32 scale;
            ent = D_L04_001DFE80 + (a << 7);
            t0 = *(vu0_v4 *)(ent + 0x30);
            scale = 40.0f;
            if (D_001D545C == 11) scale = 80.0f;
            func_0038CE20(&t1, ent, scale);
            vadd(&t1, &t1, &t0);
            vsub(&t2, &t1, &t0);
            func_0038CF68(&t2, &t2, 1.0f);
            if (*(s32 *)(m + 0x04) != 0) {
                func_L04_003796C8(*(u8 **)(m + 0x04));
            }
            *(u8 **)(m + 0x04) = func_L04_00379410(&t0);
            *(s32 *)(m + 0x110) = 4;
            *(vu0_v4 *)(m + 0x150) = t2;
        }
    }
done:
    func_L01_004450F0(o, 1, -1);
}
