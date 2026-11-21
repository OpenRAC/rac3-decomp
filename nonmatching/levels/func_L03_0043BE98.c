/* Near miss: PAL port of the NTSC-U draft of func_L03_00438870. PAL differs from NTSC-U in two
 * places: the random timer is converted to 50 Hz ((r * 5 + 2) / 6 in floats) and both turn rates
 * are scaled by 1.44f before the two func_L01_0044E850 calls. With the file's current flags
 * (-O2 -G8 -fopt-stack -mno-check-zero-division) it is 200 diff rows: the default assembler puts
 * 0.01f and 1.44f in .lit4 and loads them through $gp where retail builds them inline with
 * lui/ori/mtc1, which needs @ps2as (the file holds only this function). Checked with --as ps2as it
 * is 161 rows, all shifts from two causes: (1) one retail nop before the div.s, which needs a row
 * `func_L03_0043BE98 1` in config/levels/divs_nops.txt; (2) the prologue: retail saves $s0 before
 * $s1 and copies $a1 to $s0 before $a0 to $s1, and moves `move $s4,$a3` / the D_L03_001D66B0
 * lui-addiu pair one slot (8 rows). Tried for (2): loading the rates in either order, the a4 store
 * first, void * parameters with typed locals. Same result at level 27. Fixed on the way: the
 * xori/andi bit tests ((x ^ 1) & 1), the 0x1D5471 byte as (&D_001D5470)[1] (no $gp lbu in the
 * delay slot), the pitch products as two temporaries, and the 1.44f products inline in the calls.
 */
#include "common.h"
#include "vu0.h"
#include "structs/hero.h"

extern u8 D_L03_001D66B0[];
extern struct Hero D_001A4BE0;
extern u8 D_001D5470;
extern s32 func_L03_003FB6C8(void *, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L03_0043BE98(u8 *m, u8 *s, s32 a2, s32 a3, s32 a4) {
    vu0_v4 delta, target, pos;
    f32 yaw, pitch;
    f32 rate1 = *(f32 *)(s + 0x120);
    f32 rate2 = *(f32 *)(s + 0x124);
    *(s32 *)(s + 0x12C) = a4;
    if (!func_L03_003FB6C8(D_L03_001D66B0, s, 16)) {
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(delta) : "m"(*(vu0_v4 *)s), "m"(*(vu0_v4 *)(m + 0x10)) : "vf1", "vf2");
        yaw = func_0038DB00(func_0038D160(delta.x, delta.y), *(f32 *)(m + 0xF8));
        pitch = -func_0038D160(func_0038CED8(&delta), delta.z);
    } else {
        if (((*(u8 *)(s + 0x14C) ^ 1) & 1) &&
            func_0038CF38(m + 0x10, &D_001A4BE0.pos) < *(f32 *)(s + 0x144) &&
            func_0038DBA0(*(f32 *)(m + 0xF8), func_0038D160(D_001A4BE0.pickup_point.x - *(f32 *)(m + 0x10), D_001A4BE0.pickup_point.y - *(f32 *)(m + 0x14))) < *(f32 *)(s + 0x140)) {
            if (func_0038CEA8(&D_001A4BE0.vel) > 0.01f)
                *(s32 *)(s + 0x15C) = *(s32 *)(s + 0x148);
            else
                func_0038CAD0(s + 0x15C);
        } else if (*(s32 *)(s + 0x15C)) {
            *(s32 *)(s + 0x15C) = 0;
            target = *(vu0_v4 *)&D_001A4BE0.pickup_point;
        }
        if (func_0038CAD0(s + 0x158)) {
            *(s32 *)(s + 0x158) = (s32)((func_003824E0((f32)*(s32 *)(s + 0x150), (f32)*(s32 *)(s + 0x154)) * 5.0f + 2.0f) / 6.0f);
            *(f32 *)(s + 0x164) = func_003824E0(*(f32 *)(s + 0x118), *(f32 *)(s + 0x11C));
            *(f32 *)(s + 0x160) = func_003824E0(*(f32 *)(s + 0x110), *(f32 *)(s + 0x114));
        }
        if (*(s32 *)(s + 0x15C) && ((*(u8 *)(s + 0x14C) ^ 1) & 1)) {
            target = *(vu0_v4 *)&D_001A4BE0.pickup_point;
            pos = *(vu0_v4 *)(m + 0x10);
            target.z += D_001A4BE0.pickup_point.z - D_001A4BE0.pos.z;
            pos.z += *(f32 *)(s + 0x128);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(delta) : "m"(target), "m"(pos) : "vf1", "vf2");
            yaw = func_0038DB00(func_0038D160(delta.x, delta.y), *(f32 *)(m + 0xF8));
            pitch = -func_0038D160(func_0038CED8(&delta), delta.z);
            *(f32 *)(s + 0x164) = yaw;
            *(f32 *)(s + 0x160) = pitch;
            rate1 *= 3.0f;
            rate2 *= 3.0f;
        } else {
            yaw = *(f32 *)(s + 0x164);
            pitch = *(f32 *)(s + 0x160);
            if ((*(s32 *)(s + 0x14C) & 2) == 0) yaw = pitch = 0.0f;
        }
    }
    if (yaw > *(f32 *)(s + 0x11C)) yaw = *(f32 *)(s + 0x11C);
    else if (yaw < *(f32 *)(s + 0x118)) yaw = *(f32 *)(s + 0x118);
    if (pitch > -*(f32 *)(s + 0x110)) pitch = -*(f32 *)(s + 0x110);
    else if (pitch < -*(f32 *)(s + 0x114)) pitch = -*(f32 *)(s + 0x114);
    if (*(s32 *)(s + 0x12C)) {
        f32 x1 = yaw * *(f32 *)(s + 0x138);
        f32 x2;
        if (*(u16 *)(m + 0x34) & 0x8000) x1 = -x1;
        *(f32 *)(s + 0x78) = x1;
        x2 = yaw * *(f32 *)(s + 0x13C);
        if (*(u16 *)(m + 0x34) & 0x8000) x2 = -x2;
        *(f32 *)(s + 0xF8) = x2;
        x1 = pitch * *(f32 *)(s + 0x13C);
        x2 = pitch * *(f32 *)(s + 0x138);
        *(f32 *)(s + 0xF4) = x1;
        *(f32 *)(s + 0x74) = x2;
    }
    if ((&D_001D5470)[1]) *(f32 *)(s + 0x80) = 2.75f;
    func_L01_0044E850(m, s + 0x10, a2, rate1 * 1.44f, rate2 * 1.44f);
    func_L01_0044E850(m, s + 0x90, a3, rate1 * 1.44f, rate2 * 1.44f);
    qzero(s);
}
