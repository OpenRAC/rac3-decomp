/* NTSC-U draft (2026-11-14, Codex worker): C of func_L03_003B4310, the NTSC-U twin of func_L03_003B5EF8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L03_003B5C78.c's current line.
 * Worker's note: 133 diff; best log w69/func_L03_003B4310.check02.log; assigned assembler emits lit4 for 1/60 and 2.1f while retail uses inline lui/ori/mtc1; no allowed alternate flags; VU scheduling/store order also differ; retained .near.c
 */
/* Near: 133 diff with assigned flags. The default assembler emits .lit4 loads for
 * 1/60 and 2.1f; retail uses inline lui/ori/mtc1. No permitted alternate flags.
 * VU0 sequence scheduling and scalar store order also differ. See check02.log. */
#include "common.h"

/* localdecomp:start func_L03_003B4310 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3B4310;
typedef int Q_3B4310 __attribute__((mode(TI)));
typedef struct { u8 pad[0x18]; u8 *hit; } Collision_3B4310;
extern Collision_3B4310 D_L03_001E9280[];
extern f32 D_001DEA48_sda;
extern f32 D_001DEA4C_sda;
extern f32 D_001DEA40_sda;
extern f32 D_001DEA3C_sda;
extern s32 D_001DEA38_sda;
extern u8 D_L03_001E1E48[];
extern void func_L03_003B4788(void);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L03_0034A658(void *, s32, s32, s32, void (*)(void), f32);

u8 *func_L03_003B4310(u8 *self, s32 joint, s32 kind, f32 speed) {
    V_3B4310 start, end, delta, point;
    u8 collision[0x30];
    u8 *owner = *(u8 **)(self + 0x68);
    u8 *object;
    u8 *state;
    func_003BDA38(*(void **)owner, joint, &start);
    func_003BDA38(*(void **)owner, joint + 0x20, &end);
    /* The assigned flags do not allocate VU0 registers; memory operands describe this sequence. */
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(start), "m"(end));
    func_00388830(&delta, &delta, D_001DEA48_sda);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(point) : "m"(start), "m"(delta));
    func_L01_00443610(collision, self, 0, 0.0f);
    *(u16 *)(collision + 0x1A) = *(u16 *)(self + 0xAA);
    if (func_003CE740(&start, &point, 0, self, collision)) {
        if (D_L03_001E9280->hit && *(s16 *)(D_L03_001E9280->hit + 0xAA) == 0x1C06)
            return 0;
        if (kind == 0 || kind == 3 || kind == 6) {
            u8 *hit = D_L03_001E9280->hit;
            if (hit && *(s16 *)(hit + 0xAA) == 0x1C04) {
                s32 hit_kind = *(s32 *)(*(u8 **)(hit + 0x68) + 0x24);
                if (hit_kind == 0 || hit_kind == 3 || hit_kind == 6) return 0;
            }
        }
    }
    object = func_003BCFB0(0x1C04, 0x80);
    if (object) {
        *(u8 *)(object + 0x30) = 0xFF;
        *(u8 *)(object + 0x31) = 1;
        *(u16 *)(object + 0x32) = 0x40;
        *(f32 *)(object + 0x2C) *= D_001DEA4C_sda;
        *(void **)(object + 0xB8) = self;
        state = *(u8 **)(object + 0x68);
        if (kind == 0 || kind == 3 || kind == 6) {
            *(u8 *)(object + 0x31) = 0;
            *(u16 *)(object + 0x34) |= 1;
        } else {
            *(u8 *)(object + 0x31) = 1;
            *(u16 *)(object + 0x34) &= 0xFFFE;
        }
        *(s32 *)(object + 0x98) = *(s32 *)(*(u8 **)(object + 0x24) + 0x10);
        *(s32 *)(state + 0x24) = kind;
        *(f32 *)(state + 0x20) = speed * 0.01666666753590107f;
        *(s32 *)(state + 0x30) = joint;
        *(f32 *)(state + 0x38) = D_001DEA40_sda;
        *(f32 *)(state + 0x3C) = D_001DEA3C_sda;
        *(s32 *)(state + 0x28) = 0;
        *(s32 *)(state + 0x34) = 0;
        *(Q_3B4310 *)(state + 0x10) = *(Q_3B4310 *)&start;
        *(Q_3B4310 *)state = *(Q_3B4310 *)&end;
        *(void **)(state + 0x2C) = *(void **)owner;
        *(Q_3B4310 *)(object + 0x10) = *(Q_3B4310 *)&start;
    }
    if (D_001DEA38_sda == 0) {
        D_001DEA38_sda = 1;
        func_L03_0034A658(D_L03_001E1E48, 0x1E, 0x14, 2, func_L03_003B4788, 2.1f);
    }
    return object;
}
/* localdecomp:end func_L03_003B4310 */
