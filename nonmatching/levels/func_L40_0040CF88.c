/* func_L40_0040CF88: near miss, 37 diff at level 40. 904 bytes, 14 levels (40-53),
   src/levels/shared/L40_0040A4D0.c (flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Written from asm (2026-11-11). The Ranger's damage (from
   func_L40_0040C6F0): the hit on the legs or the torso unless it is friendly fire (a 0x1849 of
   its team, or a guber whose vtable +0x1C says same team), the damage taken off TargetVars'
   health, death at 0 health, the death counter (pVar+0x2CC) that destroys the guber after 200.

   Two places differ, the rest is retail's:
   - the damage scale block (hit +0x2C *= mb +0xA8 when the attacker is of the Ranger's class):
     retail fills the bc1t slot with the fall-through's load of hit +0x2C and tests the attacker
     with beql; ours fills it with the target's li 8 (4-6 words, the branch offsets after it);
   - the end: retail evaluates (k * 5 + 2) / 6 < abs(frame - mb +0x44) into $v0 and overwrites it
     with the return 0 (a test whose branch went away after life analysis); ours keeps a bnez
     between two returns of 0, with other registers (about 25 words).
   Tried: the call's 1 / 0x10000 argument as a conditional expression or if/else (the movn
   form, 191 diff) and as the call written in each arm (cross-jumped to retail's shape: 38), the
   class compare's operands swapped (37), hit +0x2C read into a local first (37), the end test
   joined with && (37), as identical if/else arms (33, but the comparison is then deleted) and as
   a conditional expression returning 0 either way (59). Context: the file's prelude (vu0.h's
   abs_asm) and earlier blocks (D_L40_0024112C[] is func_L40_0040B9C0's). */
#include "common.h"
#include "vu0.h"

extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(u8 *m, s32 state, s32 a2);
/* localdecomp:start func_L40_0040CF88 */
__asm__(".extern D_L40_0024845C, 4");
extern u8 *D_L40_0024845C; /* the moby array */
extern void func_L01_0044ABD0(u8 *m);
extern void func_L39_0066C470(s32 uid);
extern u8 *func_L01_00447490(u8 *m, s32 kind, s32 a2);
extern u8 *func_L39_0061D7B0(u8 *m);
extern void func_0038CB00(void *p);
extern void func_003C4A40(u8 *m, void *mb);
extern f32 func_L01_004474E8(u8 *m, u8 *hit);
extern s32 func_L40_0053F018(u8 *m);
extern void func_L01_00455E18(u8 *m, u8 *x, u8 *tv);

typedef struct {
    u8 pad[0x1C];
    s32 (*same_team)(u8 *g, s32 team);
} GuberVt_40CF88;

/* The Ranger's damage: take the hit on the legs or the torso unless it is friendly fire,
   apply it to the health, die at 0 health or after 200 frames of it. */
s32 func_L40_0040CF88(u8 *m, u8 *mb, s32 uid, s32 a3, s32 torso_hits) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *tv;
    u8 *x;
    u8 *hit;
    u8 *src;
    u8 *g;
    f32 dmg;
    s32 k;

    *(u8 **)(v + 0x2A0) = 0;
    tv = *(u8 **)(v + 0x0);
    x = *(u8 **)(v + 0x20);
    func_L01_0044ABD0(m);
    if (*(f32 *)(v + 0x30) <= 0.0f) {
        *(s32 *)(v + 0x2CC) += 1;
    }
    if (*(s32 *)(v + 0x2CC) > 200) {
        func_L39_0066C470(uid);
    }
    if (torso_hits) {
        hit = func_L01_00447490(m, 1, 0);
    } else {
        hit = func_L01_00447490(m, 0x10000, 0);
    }
    if (hit == 0) {
        if (torso_hits) {
            hit = func_L01_00447490(*(u8 **)(v + 0x270), 1, 0);
        } else {
            hit = func_L01_00447490(*(u8 **)(v + 0x270), 0x10000, 0);
        }
        if (hit == 0) {
            goto done;
        }
        *(u8 *)(*(u8 **)(v + 0x270) + 0xA8) = 0xFF;
    }
    if (*(u8 **)(hit + 0x20) != 0 && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1849 && *(u8 **)(*(u8 **)(hit + 0x20) + 0x68) != 0) {
        if (*(s32 *)(*(u8 **)(*(u8 **)(hit + 0x20) + 0x68) + 0x2C) == *(s32 *)(v + 0x2F0)) {
            hit = 0;
        }
    }
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        src = *(u8 **)(hit + 0x20);
        while (*(u8 **)(src + 0xB8) != 0) {
            src = *(u8 **)(src + 0xB8);
        }
        g = func_L39_0061D7B0(src);
        if (g != 0 && (*(GuberVt_40CF88 **)(g + 0x14))->same_team(g, *(s32 *)(v + 0x2F0))) {
            hit = 0;
            *(u8 *)(m + 0xA8) = 0xFF;
        }
        if (hit != 0) {
            *(u8 **)(v + 0x2A0) = src;
        }
    }
done:
    func_0038CB00(v + 0x36);
    if (hit != 0) {
        if (*(s16 *)(v + 0x36) != 0) {
            hit = 0;
            *(u8 *)(m + 0xA8) = 0xFF;
        }
        if (hit != 0) {
            *(u8 *)(v + 0x167) = 0xC8;
            func_003C4A40(m, v + 0x160);
            if (*(f32 *)(mb + 0xA8) != 0.0f && *(u8 **)(hit + 0x20) != 0 && *(s16 *)(m + 0xAA) == *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA)) {
                *(f32 *)(hit + 0x2C) = *(f32 *)(hit + 0x2C) * *(f32 *)(mb + 0xA8);
            }
            *(s16 *)(v + 0x36) = 8;
            if (*(u8 **)(hit + 0x20) != 0 && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x108F) {
                *(s16 *)(v + 0x36) = 0x32;
            }
        }
    }
    dmg = func_L01_004474E8(m, hit);
    *(u8 *)(m + 0xA8) = 0xFF;
    *(f32 *)tv -= dmg;
    if (*(f32 *)(v + 0x30) <= 0.0f && func_L40_0053F018(m) != 0) {
        func_L01_004450F0(m, *(u8 *)(mb + 0x10), *(u8 *)(mb + 0x48));
    }
    if (x != 0) {
        func_L01_00455E18(m, x, tv);
    }
    if (dmg == 0.0f) {
        return 0;
    }
    *(s16 *)(mb + 0x70) = -1;
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        *(s16 *)(mb + 0x70) = (*(u8 **)(hit + 0x20) - D_L40_0024845C) >> 8;
    }
    k = *(s16 *)(tv + 4) * *(f32 *)(mb + 0x58) <= 0.0f ? 90 : 300;
    if (*(u8 *)(mb + 0x77) == 0) {
        if ((k * 5 + 2) / 6 < abs_asm(D_L40_0024112C[0] - *(s32 *)(mb + 0x44))) {
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L40_0040CF88 */
