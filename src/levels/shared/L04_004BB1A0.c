#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_004BB1A0);

/* localdecomp:start func_L04_004BB268 */
extern void func_L04_004BB1A0(s32, s32);

void func_L04_004BB268(void) {
    func_L04_004BB1A0(0, 0);
}
/* localdecomp:end func_L04_004BB268 */

INCLUDE_ASM("asm/levels", func_L04_004BB288);

/* localdecomp:start func_L04_004BB2E0 */
typedef int u128_4B75B0 __attribute__((mode(TI)));
typedef struct { u8 a; u8 pad[3]; u16 id; u8 pad2[58]; u128_4B75B0 v0; u128_4B75B0 v1; } Ent_004B75B0;
extern Ent_004B75B0 D_L04_00239370[];
s32 func_L04_004BB2E0(u32 a0, u128_4B75B0 *a1, u128_4B75B0 *a2) {
    u32 idx = a0 >> 16;
    Ent_004B75B0 *e = 0;
    if (idx < 12) {
        Ent_004B75B0 *p = &D_L04_00239370[idx];
        if (p->a != 0 && p->id == (a0 & 0xFFFF)) e = p;
    }
    if (e) {
        e->v0 = *a1;
        e->v1 = *a2;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_004BB2E0 */

/* localdecomp:start func_L04_004BB348 */
extern Ent_004B75B0 D_L04_00239370[];
s32 func_L04_004BB348(u32 id, s32 a1, s32 a2, s32 a3) {
    u8 *e = 0;
    u32 idx = id >> 16;
    if (idx < 12) {
        u8 *p = ((u8 *)&D_L04_00239370) + idx * 96;
        if (p[0] != 0 && *(u16 *)(p + 4) == (id & 0xFFFF)) {
            e = p;
        }
    }
    if (e != 0) {
        *(s32 *)(e + 16) = a1;
        *(s32 *)(e + 20) = a2;
        *(s32 *)(e + 24) = a3;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_004BB348 */

/* localdecomp:start func_L04_004BB3A8 */
extern Ent_004B75B0 D_L04_00239370[];
typedef struct { u8 b0; s8 s[3]; u16 h4; u8 p6[0xE]; s32 f14; u8 p18[0x48]; } S_4B7678;
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);

s32 func_L04_004BB3A8(u32 handle) {
    u32 idx = handle >> 16;
    S_4B7678 *s = 0;
    s32 k;
    u8 *t;

    if (idx < 12) {
        S_4B7678 *e = &((S_4B7678 *)&D_L04_00239370)[idx];
        if (e->b0 != 0) {
            if (e->h4 == (handle & 0xFFFF)) {
                s = e;
            }
        }
    }
    if (s == 0) {
        return 0;
    }
    s->b0 = 0;
    k = s->s[0];
    if (k != -1) {
        t = D_001A30B0 + k * 128;
        if (*(s32 *)(t + 0xDC) == s->f14 && t[0xD0] != 0) {
            func_003A4F28(k);
        }
    }
    s->s[0] = -1;
    k = s->s[1];
    if (k != -1) {
        t = D_001A30B0 + k * 128;
        if (*(s32 *)(t + 0xDC) == s->f14 && t[0xD0] != 0) {
            func_003A4F28(k);
        }
    }
    s->s[1] = -1;
    k = s->s[2];
    if (k != -1) {
        t = D_001A30B0 + k * 128;
        if (*(s32 *)(t + 0xDC) == s->f14 && t[0xD0] != 0) {
            func_003A4F28(k);
        }
    }
    s->s[2] = -1;
    return 1;
}
/* localdecomp:end func_L04_004BB3A8 */
