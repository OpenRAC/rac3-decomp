/* near miss (round 19 worker J5D): 2 words differ (370 of 370 words, `--mode S --flags=-mvu0-use-vf0-vf2`, and the divs_nops row `func_L01_0030EAE8 2 0` that
 * belongs to the match: add it with the C). Ammo pickup update (ammo_pickup_update): state 0 scans the 0x9C entries of D_001425C0 for the pickup's class (h3A of the
 * 0xF0-byte record), state 1 runs the collect test (func_L01_0030F0B0), counts the gain in D_001427F0 and shows it (func_L01_00451FB8), state 2 flies the pickup to the
 * hero (func_003C4138 approaches on p + 0x70, the length and the scale at self + 0x2C, a rotation by pi / 30 per frame); the tail steps the fade byte b23.
 * What the match needs outside the C: (1) the file's line has -mno-split-addresses, retail is built in S mode (`--all-modes`: S 101 aligned rows at the first compile,
 * N 119): the whole line L01_0030E630.c would change to `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2` (its other blocks are INCLUDE_ASM,
 * func_L01_003104B8 is the only C block: re-verify it), and the file needs `#include "vu0.h"`; (2) retail has `sq $zero,0($s3); sqc2 $vf0,16($s3)` (the vector reset to
 * 0,0,0,1): `qzero` plus a one-instruction VU0 asm block `sqc2 vf0` (a VU0 sequence, no helper in vu0.h stores vf0; a reviewer may want a helper with evidence).
 * What fixed most (101 -> 2): a typed 0xF0-byte record struct and `re = T + cat` pointer (the offset 0x3a stays out of the symbol), the float temp for (2 * f48)^2 written
 * before the call, `tgt = 8.0f; if (0.0f < a.z) tgt = 0.0f;`, ONE func_L01_00451FB8 call after selecting the id, `u32 bb = self[0x23]` per arm with the store inside each
 * arm (`self[0x23] = bb < 0x25 ? 0x24 : bb - 4;`: retail's sltiu / v1 / reload of the byte), `dd = D_FB40 - D_1728` computed between qzero and the 0x70 store, unused
 * `s32 spare[8]` for the frame (0x110), vec_add_ab with the operands swapped (retail's first-loaded operand sp+0x10 in vf1).
 * Left (2 words, one site): the first vec_add of state 2 (`self->pos += b10`): retail has `vadd.xyz vf2,vf2,vf1` and `sqc2 vf2` (result in the second-loaded register),
 * every helper form (ab / ba, operands swapped) gives `vadd vf1,vf1,vf2` / `sqc2 vf1`: the VU role problem of the helpers (K1 / K2a), the second add at the same
 * place (`+= hero + 0xD0`) matches in the ba form. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0030EAE8 */
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1728;
extern u8 D_001425C0[];
typedef struct {
    u8 pad0[0x34];
    s16 h34;
    s16 h36;
    s16 h38;
    s16 h3A;
    u8 pad3C[0xF0 - 0x3C];
} Rec_0030EAE8;
extern Rec_0030EAE8 D_L01_002C5600[];
extern s32 D_001427F0[];
extern s32 D_001A71A0[];
extern u8 D_001A4C60[];
extern s32 func_L01_004BA800(void);
extern void func_L01_003F7EE8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern s32 func_L01_0030F0B0(void *, s32);
extern void func_L01_00511958(s32, s32);
extern void func_L01_00451FB8(s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_0040E5D8(void *, s32);
extern void func_003C2880(void *);
extern void func_003C4138(void *, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C4CE8(f32, void *, void *);

void func_L01_0030EAE8(u8 *self)
{
    u8 *p;
    vu0_v4 a;
    vu0_v4 b10;
    vu0_v4 c20;
    vu0_v4 d30;
    vu0_v4 e40;
    vu0_v4 f50;
    vu0_v4 g60;
    vu0_v4 h70;
    vu0_v4 i80;
    f32 s;
    f32 dist;
    s32 i;
    s32 idx;
    s32 old;
    s32 diff;
    s32 hit;
    s32 nb;
    u8 *hero;
    u8 *hv;
    s32 *up;
    s32 ia;
    s32 dd;
    u32 bb;
    Rec_0030EAE8 *re;
    f32 sq;
    f32 tgt;
    f32 len;
    s32 spare[8];

    p = *(u8 **)(self + 0x68);
    if (D_L01_001D6694 == 2) {
        self[0x31] = 0;
        *(u16 *)(self + 0x34) |= 1;
    } else if (func_L01_004BA800() == 0) {
        self[0x31] = 1;
        *(u16 *)(self + 0x34) &= 0xFFFE;
    }
    switch (self[0x20]) {
    case 0:
        self[0x20] = 1;
        for (i = 0; i < 0x9C; i++) {
            re = D_L01_002C5600 + D_001425C0[i];
            if (re->h3A == *(s16 *)(self + 0xAA)) {
                *(s32 *)(p + 0x68) = i;
            }
        }
        break;
    case 1:
        hit = 0;
        if (p[0x79] >= 8 && (D_L01_001DFB40 & 0xF) != (((s32)self >> 8) & 0xF)) {
            hit = 0;
        } else {
            if (p[0x5C] == 3 && (D_L01_001DFB40 & 0xF) == (((s32)self >> 8) & 0xF)) {
                qzero(p);
                __asm__("sqc2 vf0, %0" : "=m"(*(vu0_v4 *)(p + 0x10)));
                p[0x5C] = 0;
            }
            a = *(vu0_v4 *)p;
            func_L01_003F7EE8(self);
            sq = *(f32 *)(p + 0x48);
            sq = sq + sq;
            dist = func_L01_0040E548(&a, p);
            sq = sq * sq;
            if (sq < dist) {
                hit = 1;
            }
            if (func_L01_0040E4C0(p) < 4.00000044e-06f) {
                if (func_L01_0040E4C0(p + 0x10) < 9.00000032e-06f) {
                    p[0x79] = p[0x79] + 1;
                } else {
                    p[0x79] = 0;
                }
            } else {
                p[0x79] = 0;
            }
        }
        if (func_L01_0030F0B0(self, hit) != 0) {
            idx = *(s32 *)(p + 0x68);
            up = &D_001427F0[idx];
            old = *up;
            func_L01_00511958(idx, *(s32 *)(p + 0x60));
            if (old < *up) {
                diff = *up - old;
                if (diff == 1) {
                    re = D_L01_002C5600 + D_001425C0[idx];
                    ia = re->h36;
                } else {
                    re = D_L01_002C5600 + D_001425C0[idx];
                    ia = re->h34;
                }
                func_L01_00451FB8(ia, diff, -1, 0);
            }
            func_L01_004450F0(self, 2, -1);
            qzero(p);
            dd = D_L01_001DFB40 - D_L01_001E1728;
            *(f32 *)(p + 0x70) = 0.16000001f;
            if (abs_asm(dd) >= 9) {
                func_003A52A0(0, 0, self);
                D_L01_001E1728 = D_L01_001DFB40;
            }
        }
        break;
    case 2:
        hero = D_001A4C60;
        vec_sub_ab(&a, self + 0x10, hero);
        func_0038D000(&a, &a, hero - 0x40);
        tgt = 8.0f;
        if (0.0f < a.z) {
            tgt = 0.0f;
        }
        func_003C4138(p + 0x70, tgt, 0.00960000046f);
        func_0038CF68(&b10, hero - 0x60, *(f32 *)(p + 0x70));
        vec_add_ab(self + 0x10, &b10, self + 0x10);
        vec_add_ba(self + 0x10, self + 0x10, hero + 0xD0);
        len = func_0038CEA8(p);
        func_003C4138(&len, 1.28000009f, 0.00960000046f);
        vec_sub_ab(&c20, hero + 0x60, self + 0x10);
        dist = func_0038CEA8(&c20) / len;
        if (dist < 25.0f) {
            func_003C4138(self + 0x2C, 0.0f, *(f32 *)(*(u8 **)(self + 0x24) + 0x24) / 25.0f);
        }
        if (*(f32 *)(self + 0x2C) == 0.0f || dist <= 1.0f) {
            func_003C2880(self);
            return;
        }
        func_0038CF68(p, &c20, len);
        vec_add_ab(self + 0x10, self + 0x10, p);
        func_0038CE90(&d30, hero - 0x60, p);
        func_003C4CE8(0.104719758f, &d30, &d30);
        h70 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
        h70.z = 0.3f;
        func_0038D000(&e40, &h70, self + 0xC0);
        func_0038D810(&d30, &i80);
        func_0038D5F0(self + 0xC0, &i80, self + 0xC0);
        func_0038D000(&f50, &h70, self + 0xC0);
        vec_sub_ba(&g60, &f50, &e40);
        vec_sub_ba(self + 0x10, self + 0x10, &g60);
        break;
    default:
        break;
    }
    if (self[0x20] == 1 && func_L01_0040E5D8(self, D_001A71A0[0]) != 0) {
        bb = self[0x23];
        self[0x23] = bb < 0x25 ? 0x24 : bb - 4;
    } else {
        bb = self[0x23];
        self[0x23] = bb < 0x7C ? bb + 4 : 0x80;
    }
    if ((s8)self[0x23] >= 0) {
        *(u16 *)(self + 0x34) |= 0x2000;
    } else {
        *(u16 *)(self + 0x34) &= 0xDFFF;
    }
}
/* localdecomp:end func_L01_0030EAE8 */
