/*
 * func_L39_00605EF8 -- k4 Sonnet first pass, 2472 B (618 instructions), shared at 15 places (39:00605EF8 ... 53:004DE7F8).
 * Result: NEAR, far. `tools/check.py scratch/f.c func_L39_00605EF8` (file flags `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`):
 * 597 diff of 618 positional, about 36% of retail's instructions in common by LCS (623 of mine). Shape and every call are right,
 * register allocation, spill slots and some CSE'd addresses are not.
 * What the function is: per-player (arg1) HUD refresh of the multiplayer object (arg0, same family as func_L39_006068A0 just below in
 * this file): sets the colour/alpha words (func_L39_006010E0 returns the word pointer; every write is `(*r & 0xFFFFFF) | hi`), switches
 * the 8 slot widgets on/off from the 0x1C-byte records `**D_L39_0024BD48[pl]` (w0 at +0, id at +0x18), reads two protected values
 * (DecB 0x81/D_L39_0049C340 at p+id+0x1A62 in loop 1, Dec2 0xD1/D_L39_00483A00 at p+id+0x1A52 and p+0x1A41 in loop 2: helpers as in
 * docs/game/protected-values.md and src/levels/shared/L39_005DADF8.c), then fades slots by `hi >> 24`, clamps two alphas with the
 * min of a third, and counts down obj+0xB38 to switch the widgets off (func_003AD590 x6 then func_L01_004CF3A0 x6).
 * Differences, in order of importance for the next attempt:
 *  1. Frame: retail 0xD0 (mine 0xD0 too after splitting the two locals sets), but retail keeps `p` in $s6, the loop-1 counter in $s2 and
 *     the next counter value in $fp (`addiu $fp,$s2,1` before the body; `move $s2,$fp` at the end), the player-record array pointer
 *     `&D_L39_0024BD48[pl]` in a stack slot 0x28 (sp28) and `pl*4` in 0x70, and the three `&c0/&c1/&c2` addresses in 0x54/0x58/0x60
 *     (stored before the first branch AND again after it). Mine puts p in $fp and reloads D_L39_0024BD48[pl] each time. Tried a
 *     `R ***rp = &D_L39_0024BD48[pl]` local for loop 1 and a second one for the body (h2 variant): no gain. The `i+1` in $fp suggests the
 *     original loop was `for (i = 0; i < 8; i = n)`-like with a named next value, or the loop var is used by an inline.
 *  2. `mult` operands: retail loads the stride constants into registers (`addiu $a1,$zero,0x1C ; mult $s1,$s2,$a1`; `addiu $a2,0x30`), as mine
 *     does for most, but the register choice follows from (1).
 *  3. Loop 2 (`prev = i-1 < 0 ? 7 : i-1` as slt/movz) and the tail (min of two alphas via sltu/movn) are in the right shape.
 *  4. The discarded Dec2 of p+0x1A41 (retail keeps the whole decode loop and the divu; value unused) is reproduced by calling the inline
 *     without using the result; not yet compared in detail.
 * Prototypes (confidence high; names via config/levels/functions.tsv column 7): func_003AAF00(void*,s32)=00601128, func_003AB988(void*,s32,s32)=00601C60,
 * func_003AB530(void*,s32,s32)=006017A0, func_003ABBE0/BE8(void*,s32)=00601EB8/EC0, func_003AD590(void*,s32)=00603FE8,
 * func_L01_004CF3A0(void*)=00603F40, func_L01_004CF498(void*,s32)=00604038, func_L01_004D25D0=00607488 (2 real args; its a2 is leftover),
 * func_L39_00648AE0(u8*,s32). E_00605EF8 is the 0x80-byte D_L39_0049C890 record (b8 flag, h1E, b21 index).
 * Next steps: iterate on (1) first (name the player-record pointer and the loop-next value, try `R **rec = *rp` hoisted), then diff by block.
 * Profile: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as. Check: ~/RACSwarm/k4-check.sh with this file as the snippet body.
 */
#include "common.h"

typedef struct { s32 w0; u8 pad4[0x14]; s32 id; u8 pad1C[0]; } R_00605EF8;
typedef struct { u8 pad[0x2544]; s32 idx; } P_00605EF8;
typedef struct { u8 pad0[8]; u8 b8; u8 pad9[0x15]; s16 h1E; u8 pad20[1]; s8 b21; u8 pad22[0x5E]; } E_00605EF8;
typedef union { u8 b[8]; u32 w[2]; u16 h[4]; } Buf_00605EF8;
typedef struct { u8 pad[0xA4]; u8 bA4; } G_00605EF8;
extern u8 *func_L39_0061BF38(s32);
extern R_00605EF8 **D_L39_0024BD48[] __attribute__((section(".sdata")));
extern E_00605EF8 D_L39_0049C890[];
extern G_00605EF8 D_001A5810[];
extern u8 D_L39_0049C340[];
extern u8 D_L39_00483A00[];
extern u8 *D_L39_00242A50;
__asm__(".extern D_L39_00242A50, 16");
extern s32 *func_L39_006010E0(void *);
extern void func_L39_00602258(s32, s32, u32 *, u32 *, u32 *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_003AAF00(void *, s32);
extern void func_003AB988(void *, s32, s32);
extern void func_003AB530(void *, s32, s32);
extern void func_003ABBE0(void *, s32);
extern void func_003ABBE8(void *, s32);
extern void func_L01_004CF3A0(void *);
extern void func_003AD590(void *, s32);
extern void func_L01_004CF498(void *, s32);
extern u8 *func_L01_004D25D0(u8 *, s32);

static inline u16 DecB_00605EF8(u8 *q) {
    Buf_00605EF8 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_0049C340[m + ((k + i) & 7) * 129];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static inline u16 Dec2_00605EF8(u8 *q) {
    Buf_00605EF8 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

void func_L39_00605EF8(u8 *obj, s32 pl) {
    u8 *p;
    s32 i;
    s32 sel;
    s32 prev;
    u32 c0, c1, c2;
    u32 col;
    u32 hi;
    u32 alpha;
    u32 s0, s1, s2;
    u8 *e;
    u8 *a;
    s32 *r;
    s32 t;

    p = func_L39_0061BF38(pl);
    if (D_L39_0024BD48[pl] != 0 && p != 0) {
        a = obj + 0x5C8;
        if (D_001A5810[((P_00605EF8 *)p)->idx].bA4 == 0) {
            func_003AAF00(a, 1);
            func_003AAF00(obj + 0x5F8, 0);
        } else {
            func_003AAF00(a, 0);
            func_003AAF00(obj + 0x5F8, 1);
        }
        for (i = 0; i < 8; i++) {
            if ((*D_L39_0024BD48[pl])[i].w0 == 0) {
                func_003AAF00(obj + i * 0x30 + 0x664, 0);
            } else {
                e = obj + i * 0x30 + 0x664;
                func_003AAF00(e, 1);
                func_003AB988(e, (*D_L39_0024BD48[pl])[i].w0, 0);
            }
            func_003AAF00(func_L01_004D25D0(D_L39_00242A50 + 0x1FCA8, pl) + i * 0x3C, 0);
            if ((*D_L39_0024BD48[pl])[i].id > 0) {
                u32 d0 = 0, d1 = 0, d2 = 0;
                func_L39_00602258(pl, (*D_L39_0024BD48[pl])[i].id, &d0, &d1, &d2);
                r = func_L39_006010E0(obj + i * 0x30 + 0x664);
                *r = (*r & 0xFF000000) | (d2 & 0xFFFFFF);
                e = func_L01_004D25D0(D_L39_00242A50 + 0x1FCA8, pl) + i * 0x3C;
                func_003AAF00(e, 1);
                func_003AB530(e, d0, d1);
                func_003ABBE0(e, 100);
                func_003ABBE8(e, 100);
                if (D_L39_0049C890[(*D_L39_0024BD48[pl])[i].id].b8 != 0) {
                    func_003ABBE0(e, 5);
                    {
                        u8 *q = p + (*D_L39_0024BD48[pl])[i].id + 0x1A62;
                        s16 v;
                        if (*q != 0) {
                            v = DecB_00605EF8(q);
                        } else {
                            v = 0;
                        }
                        func_003ABBE8(e, v >= 4 ? 3 : v);
                    }
                }
            }
        }
    }
    s0 = *(s32 *)(p + 0x478);
    if (func_L39_00648AE0(p, s0) != 0) {
        e = (u8 *)&D_L39_0049C890[D_L39_0049C890[s0].b21];
    } else {
        e = (u8 *)&D_L39_0049C890[s0];
    }
    sel = (((E_00605EF8 *)e)->h1E == 0) ? 0 : s0;
    if (obj[0xB40] != 0) {
        sel = *(s32 *)(obj + 0xB44);
    }
    c0 = 0;
    c1 = 0;
    c2 = 0;
    func_L39_00602258(pl, sel, &c0, &c1, &c2);
    *func_L39_006010E0(obj + 0x110) = c2;
    func_L01_004CF498(obj + 0x7E8, 1);
    func_L01_004CF498(obj + 0x870, 1);
    func_L01_004CF498(obj + 0x8F8, 1);
    func_L01_004CF498(obj + 0x980, 1);
    func_L01_004CF498(obj + 0xA08, 1);
    s1 = *(u8 *)((u8 *)func_L39_006010E0(obj + 0x664) + 3) << 24;
    for (i = 6; i >= 0; i--) {
        r = func_L39_006010E0(obj + 0x694 + (6 - i) * 0x30);
        *r = (*r & 0xFFFFFF) | s1;
    }
    r = func_L39_006010E0(obj + 0x5C8);
    *r = (*r & 0xFFFFFF) | s1;
    col = 0x331465B7;
    r = func_L39_006010E0(obj + 0x5F8);
    *r = (*r & 0xFFFFFF) | s1;
    func_L01_004CF498(obj + 0xA90, 1);
    hi = *func_L39_006010E0(obj + 0x2BC) & 0xFF000000;
    for (i = 0; i < 8; i++) {
        prev = i - 1;
        if (prev <= -1) {
            prev = 7;
        }
        alpha = hi >> 24;
        if (D_L39_0024BD48[pl] != 0) {
            if ((*D_L39_0024BD48[pl])[i].w0 != 0) {
                u8 *pp = func_L39_0061BF38(pl);
                s32 id = (*D_L39_0024BD48[pl])[i].id;
                s32 f = 0;
                if (id > 0) {
                    f = D_L39_0049C890[id].b8 != 0;
                }
                if (f != 0) {
                    u8 *q = pp + id + 0x1A52;
                    u16 v;
                    if (*q != 0) {
                        v = Dec2_00605EF8(q);
                    } else {
                        v = 0;
                    }
                    if (v == 0 && D_L39_0049C890[(*D_L39_0024BD48[pl])[i].id].h1E != 0) {
                        *func_L39_006010E0(obj + prev * 0x3C + 0x2BC) = 0x70202080;
                    } else {
                        *func_L39_006010E0(obj + prev * 0x3C + 0x2BC) = col;
                    }
                    if (pp[0x1A41] != 0) {
                        Dec2_00605EF8(pp + 0x1A41);
                    }
                } else {
                    *func_L39_006010E0(obj + prev * 0x3C + 0x2BC) = col;
                }
            }
        }
        r = func_L39_006010E0(obj + prev * 0x3C + 0x2BC);
        *r = (*r & 0xFFFFFF) | (alpha << 24);
    }
    r = func_L39_006010E0(obj + 0x244);
    *r = (*r & 0xFFFFFF) | (alpha << 24);
    s0 = *func_L39_006010E0(obj + 0x280) & 0xFF000000;
    r = func_L39_006010E0(obj + 0x628);
    *r = (*r & 0xFFFFFF) | s0;
    s1 = *func_L39_006010E0(obj + 0xD0) & 0xFF000000;
    s2 = *func_L39_006010E0(obj + 0x110) & 0xFF000000;
    s0 = *func_L39_006010E0(obj) & 0xFF000000;
    if (s0 < s1) {
        s1 = s0;
    }
    r = func_L39_006010E0(obj + 0xD0);
    *r = (*r & 0xFFFFFF) | s1;
    if (s0 < s2) {
        s2 = s0;
    }
    r = func_L39_006010E0(obj + 0x110);
    *r = (*r & 0xFFFFFF) | s2;
    t = *(s32 *)(obj + 0xB38);
    if (t != 0) {
        t--;
        *(s32 *)(obj + 0xB38) = t;
        if (t == 0 && *(s32 *)(obj + 0xB3C) != 1) {
            *(s32 *)(obj + 0xB3C) = 1;
            func_003AAF00(obj + 0x628, 0);
            func_003AD590(obj + 0x7E8, -1);
            func_003AD590(obj + 0x870, -1);
            func_003AD590(obj + 0x8F8, -1);
            func_003AD590(obj + 0x980, -1);
            func_003AD590(obj + 0xA08, -1);
            func_003AD590(obj + 0xA90, -1);
            func_L01_004CF3A0(obj + 0x7E8);
            func_L01_004CF3A0(obj + 0x870);
            func_L01_004CF3A0(obj + 0x8F8);
            func_L01_004CF3A0(obj + 0x980);
            func_L01_004CF3A0(obj + 0xA08);
            func_L01_004CF3A0(obj + 0xA90);
        }
    }
}
