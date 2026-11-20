/* near miss (level 10, Zeldrin Starport): 32 differences by check.py's row count, 20 aligned rows (69 / 53 at the start of round 14) with "-mvu0-use-vf0-vf2" added to the file's flags (check.py --no-context at level 10; the declarations of D_L10_001D6694, D_001D5471 and func_L10_0035AEA8 come from the file's earlier block in the real file and are repeated here for a context-free measurement) and a divs_nops row `func_L10_0035AF90 0 1` (retail has one nop before the second div.s). Needs -mvu0-use-vf0-vf2 on src/levels/10_zeldrin_starport/L10_0035AEA8.c (its file is @ps2as already) and include/vu0.h. Contains a `switch`. The draft declares D_L10_001D6694 as a scalar with `.extern D_L10_001D6694, 16` (the file's earlier block has the `[]` + `section(".sdata")` form: both must be changed together, and func_L10_0035AEA8 re-checked, when this lands). Round 12 (2026-11-18), what moved it from 275:
 - the nested call as the last argument of `func_00382760(v + 0x220, 6.0f, f, func_003824E0(0.0f, 30.0f) * 0.017453292f)` is gcc's evaluation order trap: the first argument `v + 0x220` is computed BEFORE the nested call and must survive it, which took a fourth saved register ($s0) and the whole 0x90 frame. A local `p = func_003824E0(0.0f, 30.0f) * 0.017453292f;` before the call makes retail's `addiu $a0,$s1,0x220` in the jal's delay slot (275 -> 176);
 - D_001D5471 read as `(&D_001D5470)[1]` from a scalar with `.extern D_001D5470, 16` (in-place `lui $v0; lbu $v0,lo($v0)` like retail, not $gp), D_L10_001DF29C as `D_L10_001DF298[1]` of a two-element pointer array with `.extern D_L10_001DF298, 16` and a local pointer `gp` (retail loads the pointer once into $a1 and reuses it, re-reading only the $s1 field); func_L01_0047F3B0 declared void (the next temporary lands in $v0 as in retail);
 - the divs_nops row (176 -> 73).
 Round 14 (b24-u2), 69 -> 32 differences (53 -> 20 aligned): (a) the turn block's float variables are their own locals (`yaw`, `pitch`) instead of reusing `f` and `p` of the first block: the two short pseudos then take $f20 together and the constants get $f21 (0.017453292f) and $f22 (6.0f) as in retail (53 -> 38); (b) D_L10_001D6694 a scalar (MEM_SCALAR_P) and the `m + 0x34` flag a struct member (`M34_35AF90.f34`, MEM_IN_STRUCT_P): gcc then knows they are disjoint and the `sh` lands in the `bne` delay slot after the second read like retail; (c) `ok = 1;` is a statement of its own right before `D_L10_001DF034.f4 = ok;` (retail has it twice, once in the first bne's slot, copied from the join); (d) the first `gp[field * 256]` access is written without a temporary: `((M34_35AF90 *)(gp + *(s32 *)(v + 0x24C) * 256))->f34 |= 1;` and the second with `* 256` too (the multiplication stays a MULT until the address is formed, so the addu has the index first like retail; `<< 8` makes the base first) (35 -> 21); (e) the three statements of the `turn = 1` block in the order turn, copy, store.
 Left (32 rows, 20 aligned): (1) the `turn = 1` block: retail orders `addiu $s2,$zero,1` (the beqz slot), `sw $zero,0x234`, `lui/addiu $v0` (D_001A4CC0), `lq`, `sq`; here the `lui` and `addiu` are scheduled first and the `sw` last (all six source orders give the same row count or worse); (2) `0.3f * r` with r = 1.44f is folded to 0.432f by cse here (0x3edd2f1c), retail multiplies at run time (lui 0x3fb8 into $f21, lui 0x3e99 into $f20, `mul.s $f20,$f20,$f21`, `mul.s $f21,$f23,$f21`, the two products reused for both calls); r before the `if`, a local for 0.3f and the literals in the call all fold the same, so the function here is one instruction shorter and the end is shifted by it. */
#include "common.h"

/* localdecomp:start func_L10_0035AF90 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35AF90;
typedef struct M34_35AF90 { u8 p0[0x31]; u8 f31; u8 p32[2]; u16 f34; } M34_35AF90;
typedef struct T_35AF90 { s16 f0; s16 f2; s32 f4; } T_35AF90;
extern s32 D_L10_001D6694;
__asm__(".extern D_L10_001D6694, 16");
extern u8 D_001D5471[] __attribute__((section(".sdata")));
extern void func_L10_0035AEA8(void *);
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");
extern T_35AF90 D_L10_001DF034;
__asm__(".extern D_L10_001DF034, 16");
extern u8 D_00142C38[];
extern u8 D_001A4CC0[];
extern u8 D_L10_001E86C0[];
extern u8 *D_L10_001DF298[2];
__asm__(".extern D_L10_001DF298, 16");
extern u8 *D_L10_001DF380[] __attribute__((section(".sdata")));
extern void func_003C2F58(void *, s32, void *);
extern void func_L10_0042A4D0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L04_0046FFA0(void *, s32, f32);
extern void func_L01_0047F3B0(void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(f32 *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L10_0035AF90(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_35AF90 a;
    V4_35AF90 tgt;
    V4_35AF90 c;
    V4_35AF90 d;
    s32 ok;
    s32 turn;
    u8 *e;
    u8 *gp;
    f32 r;
    f32 f;
    f32 g;
    f32 p;

    func_L10_0035AEA8((void *)m);
    func_003C2F58(m, 2, &a);
    switch (m[0x20]) {
    case 0:
        func_L10_0042A4D0(m);
        if (*(u32 *)D_00142C38 & 0x4000000) {
            func_L01_004450F0(m, 7, -1);
        } else {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L04_0046FFA0(m, 0xA, 2.5f) != 0) {
            func_L01_0047F3B0(m);
            if (func_00392B20(D_L10_001E86C0, 0x9A) != 0) {
                func_00392C78(D_L10_001E86C0);
                func_L01_004450F0(m, 2, -1);
            }
        }
        break;
    case 2:
        if (D_L10_001D6694 == 2) {
            m[0x31] = 0;
            ((M34_35AF90 *)m)->f34 |= 1;
            if (D_L10_001D6694 == 2) {
                gp = D_L10_001DF298[1];
                ((M34_35AF90 *)(gp + *(s32 *)(v + 0x24C) * 256))->f34 |= 1;
                (gp + *(s32 *)(v + 0x24C) * 256)[0x31] = 0;
            }
        }
        ok = 1;
        D_L10_001DF034.f4 = ok;
        if (func_L01_004BA800() == 0) {
            e = D_L10_001DF380[0] + (*(s32 *)(v + 0x248) << 7);
            func_L01_004F50C8(e + 0x30, e + 0x70, 0, 1);
            D_L10_001DF034.f4 = 0;
            m[0x31] = ok;
            ((M34_35AF90 *)m)->f34 &= 0xFFFE;
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7:
        func_003C2880(D_L10_001DF298[1] + (*(s32 *)(v + 0x24C) << 8));
        func_003C2880(m);
        return;
    }
    if (m[0x20] != 0 && m[0x20] != 6) {
        if (m[0x43] == 0 && func_0038CAD0(v + 0x23C) != 0) {
            *(s32 *)(v + 0x23C) = (func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f;
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
        } else if (m[0x43] == 1 && (m[0x60] & 2)) {
            func_003C3A10(m, 0, 0, 8);
        }
    }
    g = 0.019999999f;
    turn = 0;
    if (m[0x43] == 0 && m[0x20] != 6) {
        if (*(s32 *)(v + 0x234) != 0) {
            turn = 1;
            *(V4_35AF90 *)(v + 0x220) = *(V4_35AF90 *)D_001A4CC0;
            *(s32 *)(v + 0x234) = 0;
        }
        if (func_0038CAD0(v + 0x238) != 0) {
            *(s32 *)(v + 0x238) = (func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / 6.0f;
            f = func_0038DAB8(*(f32 *)(m + 0xF8), func_003824E0(-90.0f, 90.0f) * 0.017453292f);
            p = func_003824E0(0.0f, 30.0f) * 0.017453292f;
            func_00382760(v + 0x220, 6.0f, f, p);
            vec_add_ab(v + 0x220, v + 0x220, m + 0x10);
        }
        if (*(s32 *)(v + 0x234) != 0) {
            g = 0.039999999f;
            tgt = *(V4_35AF90 *)D_001A4CC0;
        } else {
            tgt = *(V4_35AF90 *)(v + 0x220);
        }
    }
    if (turn != 0) {
        f32 yaw, pitch;
        c = *(V4_35AF90 *)(m + 0x10);
        c.z += 2.0f;
        vec_sub_ab(&d, &tgt, &c);
        yaw = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(m + 0xF8));
        pitch = -func_0038D160(func_0038CED8((f32 *)&d), d.z);
        if (1.5707964f < yaw) {
            yaw = 1.5707964f;
        } else if (yaw < -1.5707964f) {
            yaw = -1.5707964f;
        }
        if (0.5235988f < pitch) {
            pitch = 0.5235988f;
        } else if (pitch < -0.5235988f) {
            pitch = -0.5235988f;
        }
        *(f32 *)(v + 0x184) = pitch;
        *(f32 *)(v + 0x188) = yaw * 0.6f;
        *(f32 *)(v + 0x208) = yaw * 0.4f;
    }
    if ((&D_001D5470)[1] != 0) {
        *(f32 *)(v + 0x190) = 2.75f;
    }
    r = 1.44f;
    func_L01_0044E850(m, v + 0x120, 1, g * r, 0.3f * r);
    func_L01_0044E850(m, v + 0x1A0, 0, g * r, 0.3f * r);
}
/* localdecomp:end func_L10_0035AF90 */
