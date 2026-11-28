/* func_L01_003A9978 (Claude wave 14 retry r85, 2026-11-28). First draft kept here. */
/* func_L01_003A9978: near miss (wave 14 retry r85), 1 diff with the file's flags at level 01 (p10/check.py first
 * placement). Changed against the r51 draft (49 diff, every row the $s3/$s4 swap of obj and its vars pointer p):
 * global-alloc ranked obj (23 refs over 331 insns) just above p (22 refs over 318, -dl dump), so one more
 * reference to p flips them; here the after-switch z is read from the vars record,
 * pos.z = ((vu0_v4 *)(p + 0x10))->z - w * 0.5f, which gives retail's allocation everywhere.
 * Still differs: that one load, lwc1 $f1, 0x18($s3) where retail reads the stack copy, lwc1 $f1, 8($sp).
 * A decomp-permuter run matched only with a dead if (p) e = ...; else e = ...; (the same extra p reference,
 * removed by cross-jumping after reload), which is not plausible source. */
#include "common.h"

/* localdecomp:start func_L01_003A9978 */
#include "vu0.h"
typedef struct { u8 pad[0x1A]; u16 h1A; u8 tail[0x14]; } Hit_003A9978;
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_003A9978;
typedef struct { u8 pad00[0x18]; u8 *moby; u8 pad1C[4]; vu0_v4 pos; u8 pad30[0x10]; vu0_v4 normal; } Coll_003A9978;
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA00[];

static __inline__ s32 trace_003A9978(void *a, void *b, s32 mask, void *par, void *hit)
{
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    s32 r;
    u8 *t;

    func_L01_004CB320();
    r = func_003D3CB0(a, b, mask, par, hit);
    if (r != 0) {
        t = *(u8 **)(D_L01_001EAA00 + 0x18);
        if (t != 0 && *(s16 *)(t + 0xAA) == 0x186D && t[0x20] != 2 && t[0x20] != 5) {
            t[0x20] = 4;
        }
    }
    func_L01_004CB358();
    return r;
}

void func_L01_003A9978(u8 *obj)
{
    extern s32 func_L01_00367080(void *, void *, void *, void *);
    extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
    extern void func_L01_00367430(void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_L01_00366FC8(void);
    extern f32 func_0038CED8(void *);
    extern void func_003C4138(f32 *, f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_00404A10(void (*)(u8 *), u8 *);
    extern void func_L01_003AA120(u8 *);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 scratch;
    Hit_003A9978 hit;
    u8 *p;
    u8 *o;
    u8 *hero;
    s32 limit;
    s32 flags;
    s32 got;
    s32 i;
    s32 r;
    s32 c1, c2;
    f32 w;
    f32 alpha;
    u8 *eff;
    Coll_003A9978 *e;

    *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    limit = 30;
    p = *(u8 **)(obj + 0x68);
    if (*(f32 *)(p + 0x30) < 2.0f) {
        limit = 20;
    }
    if (limit < *(u16 *)(obj + 0x96)) {
        f32 down = *(f32 *)(p + 0x1C);
        down -= 0.015f;
        *(f32 *)(p + 0x1C) = down;
        if (down <= 0.0f) {
            func_L01_004450F0((S_3A9AC0m *)obj, 1, -1);
        }
    } else {
        w = *(f32 *)(p + 0x1C);
        w += 0.015f;
        *(f32 *)(p + 0x1C) = w;
        if (0.4f < w) {
            *(f32 *)(p + 0x1C) = 0.4f;
        }
    }
    alpha = *(f32 *)(p + 0x1C);
    switch (obj[0x20]) {
    case 0:
        vec_add_ab(&pos, p + 0x10, p);
        if (func_L01_00367080(p + 0x20, &pos, &dir, &scratch) != 0) {
            pos = dir;
            func_L01_00367260(obj, 0, 1, p + 0x20, &dir, 0x2F2020FF);
            o = (u8 *)func_00382348(*(u8 **)(obj + 0xB8));
            func_L01_00367430(obj, (f32)o[0x16]);
        } else {
            func_L01_00367260(obj, 0, 0, D_L01_001D66B0, D_L01_001D66B0, 0x2F2020FF);
        }
        flags = 1;
        o = (u8 *)func_00382348(*(u8 **)(obj + 0xB8));
        if (o != 0 && o[0x2F] != 0) {
            flags = 0x10000;
        }
        func_L01_00446760(&hit, obj, flags, p, *(f32 *)(p + 0x30));
        hit.h1A = *(u16 *)(obj + 0xAA);
        if (func_L01_00366FC8() != 0) {
            *(s32 *)(((Hero_003A9978 *)D_001A4BE0)->moby + 0x98) = 0;
        }
        got = trace_003A9978(p + 0x20, p + 0x10, 0x10, *(u8 **)(obj + 0xB8), &hit);
        hero = ((Hero_003A9978 *)D_001A4BE0)->moby;
        *(s32 *)(hero + 0x98) = *(s32 *)(*(u8 **)(hero + 0x24) + 0x10);
        if (got != 0 && ((Coll_003A9978 *)D_L01_001EAA00)->moby != 0) {
            got = trace_003A9978(p + 0x20, p + 0x10, 0x12, *(u8 **)(obj + 0xB8), 0);
        }
        if (*(u8 **)(obj + 0xB8) != 0) {
            o = (u8 *)func_00382348(*(u8 **)(obj + 0xB8));
            if (o != 0 && o[0x2F] == 0) {
                func_L01_00446760(&hit, obj, 0x10000, p, *(f32 *)(p + 0x30) * 0.25f);
                hit.h1A = *(u16 *)(obj + 0xAA);
                trace_003A9978(p + 0x20, p + 0x10, 0x10, *(u8 **)(obj + 0xB8), &hit);
            }
        }
        if (got != 0) {
            e = (Coll_003A9978 *)D_L01_001EAA00;
            if (func_0038D160(e->normal.z, func_0038CED8(&e->normal)) < 0.43633232f) {
                func_003C4138(&pos.z, e->pos.z, 0.5f);
            } else {
                pos = e->pos;
            }
        }
        *(vu0_v4 *)(p + 0x10) = pos;
        *(f32 *)(p + 0x1C) = alpha;
        break;
    case 1:
        func_L01_00367260(obj, 0, 0, D_L01_001D66B0, D_L01_001D66B0, 0x2F2020FF);
        func_003C2880((Obj_003A5118 *)obj);
        return;
    }
    pos = *(vu0_v4 *)(p + 0x10);
    pos.z = ((vu0_v4 *)(p + 0x10))->z - *(f32 *)(p + 0x1C) * 0.5f;
    for (i = 1; i >= 0; i--) {
        c1 = 0x202080;
        c2 = 0x2040DD;
        if (*(f32 *)(p + 0xC) != 0.0f && D_001D545C == 1) {
            c1 = 0x208020;
            c2 = 0x20DD40;
        }
        func_00382580(&dir, 0.20000002f, 0.26000002f);
        if (dir.z < 0.0f) {
            dir.z = -dir.z;
        }
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        eff = func_L01_004713C8(&pos, &dir, 8, c1, r, 0x7F, 0x7F, 6, func_003824E0(0.6f, 1.0f) * 210000.0f, 2100.0f, 0.00584f);
        if (eff != 0) {
            eff[2] = *D_L01_00221098[0xD4 / 4];
        }
        r = (s32)func_L01_00443A18(2.0f, 5.0f);
        eff = func_L01_004713C8(&pos, &dir, 8, c2, r, 0x30, 0x30, 0, func_003824E0(0.6f, 1.0f) * 210000.0f * 3.0f, 4200.0f, 0.00584f);
        if (eff != 0) {
            eff[2] = *D_L01_00221098[0xD4 / 4];
        }
    }
    func_L01_00404A10(func_L01_003AA120, obj);
}
/* localdecomp:end func_L01_003A9978 */
