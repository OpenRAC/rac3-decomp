#include "common.h"

/*
 * PAL reconstruction; stock check.py: 182 positional differences / 1188 retail bytes.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Two compiles: 186 -> 182. Shared decode buffer restores the 0x50 frame,
 * but its inline pointer changes decoder registers and removes loop padding.
 * Entry mode/selector allocation, boolean tail layout, global-base loads and
 * the final indexed table reload still differ. All 14 placements need review.
 * No source marker replaced. Full PAL/US build verification remains pending.
 */
typedef int Quad_430928 __attribute__((mode(TI)));
extern u8 *D_L40_00241640;
extern u8 *D_L40_00249330[] __attribute__((section(".sdata")));
extern u8 D_L40_003BFE20[];
extern u8 *D_L40_00248500;
extern u8 *D_L40_0024845C;
extern s32 *D_L40_00357470;
__asm__(".extern D_L40_00357470, 16");
extern f32 D_001DC2C0_sda;
__asm__(".extern D_001DC2C0_sda, 4");
extern void func_003C2880(void *);
extern u8 *func_L39_0066C828(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L40_00430170(void *);
extern void func_L40_00430198(void *);
extern s32 func_L40_004300D8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_004305B0(void *);
extern void func_L40_00430100(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00436660(s32, s32, s32);

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_430928;

/* Adapted from decode_00536EB0 in src/levels/shared/L39_00536EB0.c. */
static __inline__ u32 decode_430928(u8 *p, Buf_430928 *buf) {
    s32 n, k, m, i;
    u8 *d;
    if (*p == 0) return 0;
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf->b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    buf->w[0] ^= (u32)p;
    buf->w[1] ^= buf->w[0];
    return buf->w[1];
}

void func_L40_00430928(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *hero;
    u8 *r;
    u8 **p;
    f32 rot[4] __attribute__((aligned(16)));
    s32 i, team;
    u8 flag;
    f32 distance;
    if (*(s32 *)(D_L40_00241640 + 0x180) != 1) {
        func_003C2880(obj);
        return;
    }
    switch (obj[0x20]) {
    case 0:
        r = func_L39_0066C828(obj, -1, 1);
        *(s16 *)(s + 0x16) = 0;
        team = *(s16 *)(obj + 0xAA) == 0x1C2F ? 1 : 0;
        *(s16 *)(s + 0x14) = team;
        *(s32 *)(r + 0x28) = team;
        obj[0x30] = 0xFF;
        *(Quad_430928 *)s = *(Quad_430928 *)(obj + 0x10);
        *(Quad_430928 *)(s + 0x20) = *(Quad_430928 *)(obj + 0xF0);
        *(s32 *)(s + 0x10) = -1;
        *(u16 *)(obj + 0x34) |= 0x100;
        *(Quad_430928 *)rot = *(Quad_430928 *)(s + 0x20);
        rot[1] += -1.5707964f;
        func_0038D308(obj + 0xC0, rot);
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        p = D_L40_00249330;
        for (i = 7; i >= 0; i--, p++) {
            if (*p != 0 && *(u8 **)(*p + 0x251C) == obj) {
                *(u8 **)(*p + 0x251C) = 0;
            }
        }
        break;
    case 2:
        hero = D_L40_00249330[*(s32 *)(s + 0x10)];
        if (hero == 0) {
            if (!func_L40_00430170(obj)) func_L40_00430198(obj);
            break;
        }
        if (hero[0x1A14] == 0) break;
        if (!func_L40_00430170(obj)) {
            if ((decode_430928(hero + 0x19E6, (Buf_430928 *)rot) ^ 0x14) == 0 ||
                (decode_430928(hero + 0x19E4, (Buf_430928 *)rot) ^ 0x7A) == 0 ||
                (flag = (*(u8 **)(hero + 0x2530) != 0 &&
                         (*(u8 **)(hero + 0x2530))[0x27B] != 0 &&
                         (decode_430928(hero + 0x19E4, (Buf_430928 *)rot) ^ 0x31) == 0)) ||
                *(u8 **)(hero + 0x251C) == 0 ||
                (*(u8 **)(hero + 0x2528) != 0 && *(u8 **)(*(u8 **)(hero + 0x2528) + 0x2D8) == hero)) {
                func_L40_00430198(obj);
            }
        }
        if (func_L40_004300D8(obj)) break;
        distance = D_001DC2C0_sda * D_001DC2C0_sda;
        if (func_L01_0040E548(obj + 0x10, D_L40_00248500 + (*(s32 *)(s + 0x18) << 7) + 0x30) < distance) {
            if (*(s16 *)(s + 0x14) == 0) team = D_L40_00357470[1];
            else team = D_L40_00357470[0];
            r = D_L40_0024845C + (team << 8);
            if (*(s8 *)(D_L40_00241640 + 0x196) == 1 || func_L40_004305B0(r)) {
                func_L40_00430100(obj, 1, s[0x10]);
            } else {
                hero = D_L40_00249330[*(s32 *)(s + 0x10)];
                if (hero != 0 && hero[0x1A14] != 0) {
                    i = func_00381FF0(0x1709);
                    func_L01_00436660(i, -1, hero[0x24C9]);
                }
            }
        }
        break;
    }
}
