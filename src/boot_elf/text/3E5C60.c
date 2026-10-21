#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038CF58(void *, s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void func_0038CF58();
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *func_003E5CD0(s32 *);
extern s32 func_003E5CB0();
extern void func_003E6700();
extern void func_0038CF58(void *, int, int);
extern void func_003E6700(void **, s32, s32);
/* --- end of declarations from other files --- */

typedef int u128_3E0190 __attribute__((mode(TI)));
typedef struct { u128_3E0190 q0; f32 f10; f32 f14; f32 f18; f32 f1C; } P_3E0190;
typedef struct { u8 pad[0x38]; s32 f38; u8 pad2[0x28]; u8 *f64; } G_3E0190;
typedef struct { u8 pad[0xB0]; f32 fB0; } H_3E0190;
typedef struct { f32 v[4]; } V4_3E0190;
typedef struct { V4_3E0190 v0; u8 pad[0x370]; f32 f380[4]; f32 f390[4]; f32 f3A0[4]; } M_3E0190;
extern G_3E0190 D_00225700;
extern H_3E0190 D_00225900;
extern M_3E0190 D_00222480;
extern u8 D_002224A0[];
extern f32 D_001D5BC8;
extern f32 D_001D5BCC;
extern void func_003877A0();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
extern void func_0038D348(void *, void *, f32);
extern void func_003850A8(s32);

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5C60);

/* localdecomp:start func_003E5C78 */
void func_003E5C78(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_003E5C78 */

/* localdecomp:start func_003E5CB0 */
extern s32 func_003E6730();
 
s32 func_003E5CB0(void **p) {
    return func_003E6730(p) != 0;
}
/* localdecomp:end func_003E5CB0 */

/* localdecomp:start func_003E5CD0 */
s32 *func_003E5CD0(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003E5CD0 */

/* localdecomp:start func_003E5CE0 */
typedef struct { u8 p0[0x50]; s32 *arr[35]; u8 pad[0x41DC - 0xDC]; } O_3E03D8;
extern O_3E03D8 D_00306E00_003E5CE0[];
extern O_3E03D8 D_0031B74C[];
extern s32 func_003E74D0();
void func_003E5CE0(void) {
    O_3E03D8 *s = D_00306E00_003E5CE0;
    O_3E03D8 *p;
    s32 **q;
    if (s != 0) {
        p = D_0031B74C;
        if (p != s) {
            do {
                p--;
                if (p->arr != 0) {
                    q = p->arr + 35;
                    if (p->arr != q) {
                        do {
                            q--;
                            if (*q) func_003E74D0(*q);
                            *q = 0;
                        } while (p->arr != q);
                    }
                }
            } while (p != D_00306E00_003E5CE0);
        }
    }
}
/* localdecomp:end func_003E5CE0 */

/* localdecomp:start func_003E5D80 */
extern u8 D_00306E00[];
extern s32 D_001DA878;
extern void *func_003E6A28();
extern void func_116FD0();
extern void func_003E5CE0();
void *func_003E5D80(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_001DA878 == 0) {
        q = D_00306E00;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_003E6A28(q + 0x1C4);
            func_003E6A28(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_001DA878 = 1;
        func_116FD0(func_003E5CE0);
    }
    return D_00306E00 + idx * 0x41DC;
}
/* localdecomp:end func_003E5D80 */

/* localdecomp:start func_003E5E58 */
typedef struct { u8 b[16]; } B16_003E0550;
typedef struct { B16_003E0550 hdr; s32 a[16]; s32 b[16]; u8 p90[0x4C]; s32 c[16]; s32 d[16]; s32 e[16]; u8 f[16]; u8 g[16]; s32 f1BC; u32 f1C0; u8 p1C4[0x41D4 - 0x1C4]; s32 f41D4; s32 f41D8; } O_003E0550;
extern void func_003E6238();
s32 func_003E5E58(O_003E0550 **o, u32 mode) {
    B16_003E0550 tmp;
    s32 i;
    if (mode < 5) {
        *o = func_003E5D80(mode);
        (*o)->hdr = tmp;
        for (i = 0; i < 16; i++) (*o)->a[i] = 0;
        for (i = 0; i < 16; i++) *(s32 *)((u8 *)(*o) + i * 4 + 0x50) = 0;
        for (i = 0; i < 16; i++) {
            (*o)->c[i] = 0;
            (*o)->d[i] = 0;
            (*o)->e[i] = 0;
            (*o)->f[i] = 0;
            (*o)->g[i] = 0;
        }
        (*o)->f1BC = 0;
        (*o)->f1C0 = 0;
        (*o)->f41D4 = 0;
        (*o)->f1C0 = mode;
        (*o)->f41D8 = 0;
        func_003E6238(o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5E58 */

/* localdecomp:start func_003E5F88 */
s32 func_003E5F88(void **p) {
    return *(s32 *)((u8 *)*p + 0x1C0);
}
/* localdecomp:end func_003E5F88 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5F98);

/* localdecomp:start func_003E5FA8 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_003E5FA8(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_003E5FA8 */

/* localdecomp:start func_003E5FD8 */
extern void func_003E7398(void *);

void func_003E5FD8(s32 *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    void *temp_v0;

    var_s2 = 0;
    do {
        temp_s0 = var_s2 * 4;
        temp_v1 = (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC));
        if (temp_v1 != 0) {
            func_003E7398(temp_v1);
        }
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x11C)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x15C)) = 0;
        (*(s8 *)((u8 *)((*arg0 + var_s2)) + 0x1AC)) = 0;
        temp_v0 = *arg0 + var_s2;
        var_s2 += 1;
        (*(s8 *)((u8 *)(temp_v0) + 0x19C)) = 0;
    } while (var_s2 < 0x10);
}
/* localdecomp:end func_003E5FD8 */

/* localdecomp:start func_003E6078 */
s32 func_003E6078(void **p) {
    return *(s32 *)((u8 *)*p + 0x1BC);
}
/* localdecomp:end func_003E6078 */

/* localdecomp:start func_003E6088 */
typedef struct { u8 pad[0xDC]; s32 arr[1]; } S_3E0780;
 
s32 func_003E6088(S_3E0780 **p, s32 i) {
    return (*p)->arr[i];
}
/* localdecomp:end func_003E6088 */

extern s32 D_001D96D0[];
extern s32 func_003E74D0();
extern void func_003E74C0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E60A0);

/* localdecomp:start func_003E6178 */
extern s32 func_003E74D0();
extern s32 func_003E5F88();
extern s32 func_003E68D0(s32);
extern s32 func_003E7258();
s32 func_003E6178(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_003E74D0(*q);
        *q = 0;
        for (i = 3; i >= 0; i--) {
            func_003E7258(func_003E68D0(func_003E5F88(p)));
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6178 */

/* localdecomp:start func_003E6208 */
void func_003E6208(s32 **p) {
    s32 i;
    for (i = 0; i < 35; i++) (*p)[i + 20] = 0;
}
/* localdecomp:end func_003E6208 */

/* localdecomp:start func_003E6238 */
typedef struct { u8 b[16]; } B16_003E0930;
extern B16_003E0930 D_001D9640;
extern void func_003E69F0();
extern void func_003E5FD8();
extern void func_003E6208();
extern void func_003E5FA8();
void func_003E6238(u8 **o) {
    B16_003E0930 tmp;
    func_003E69F0(*o + 0x1C4);
    func_003E69F0(*o + 0x21CC);
    func_003E5FD8(o);
    func_003E6208(o);
    func_003E5FA8(o);
    tmp = D_001D9640;
    *(B16_003E0930 *)*o = tmp;
    *(s32 *)(*o + 0x1BC) = -1;
}
/* localdecomp:end func_003E6238 */

/* localdecomp:start func_003E62E0 */
/* func_003E62E0: MATCH (agent, 2026-10-17). Flags: the file's own (no override).
 * Second loop: the entry is read twice through two differently built addresses, the test through
 * y = x + 0x50; *(y + o) and the argument through *(x + o + 0x50). cse1 keeps them apart; combine turns both into
 * (plus sll o), and the post-reload cse makes the later one retail's `move $v1, $a2` copy (the argument's add was
 * hoisted above the test by sched1). Same mechanism as func_003E6480's match.
 * USES INLINE ASM: a register fence `__asm__("" : "+r"(x));` on x = j << 2 (the empty-asm barrier form listed under
 * "Forms still under review" in Matching-Patterns). Without it loop.c strength-reduces y (20-23 diffs); every
 * fence-free form tried (barrier/do-while tails, j * 4, 0x50 + x) stays at 20+ or gives func_003E6480's
 * single-add shape instead. Flag it for review when inserting. */
typedef struct { u8 pad0[0x50]; s32 *E[35]; s32 A[16]; s32 B[16]; u8 pad1[0x50]; u8 C[16]; s32 x1BC; } O_003E09D8;
extern s32 func_003E73A0();
extern void func_003E73F8();
extern void func_003E73D0();
extern void func_003E73A8();
extern void func_003E7420();
extern s32 func_003EDF90();
void func_003E62E0(O_003E09D8 **pp) {
    s32 i;
    s32 j;
    for (i = 0; i < 16; i++) {
        (*pp)->x1BC = i;
        if ((*pp)->A[i] != 0 && func_003E73A0((*pp)->A[i]) == 0) {
            func_003E73F8((*pp)->A[i]);
            (*pp)->A[i] = 0;
        }
        if ((*pp)->B[i] != 0 || (*pp)->C[i] != 0) {
            if ((*pp)->A[i] == 0) {
                if ((*pp)->C[i] != 0) {
                    (*pp)->B[i] = 0;
                    (*pp)->C[i] = 0;
                    goto L;
                }
                (*pp)->A[i] = (*pp)->B[i];
                func_003E73D0((*pp)->A[i]);
                func_003E73A8((*pp)->A[i], 1);
                (*pp)->B[i] = 0;
            } else {
                goto M;
            }
        }
L:
        if ((*pp)->A[i] != 0) {
M:
            if (func_003E73A0((*pp)->A[i]) == 1) {
                func_003E7420((*pp)->A[i]);
            }
        }
    }
    (*pp)->x1BC = -1;
    for (j = 0; j < 35; j++) {
        O_003E09D8 *o = *pp;
        s32 x, y;
        x = j << 2;
        __asm__("" : "+r"(x));
        y = x + 0x50;
        if (*(s32 **)(y + (s32)o) != 0) {
            func_003EDF90(*(s32 **)(x + (s32)o + 0x50), o);
        }
    }
}
/* localdecomp:end func_003E62E0 */

/* localdecomp:start func_003E6480 */
/* func_003E6480: MATCH (agent, 2026-10-17). Flags: the file's own (no override).
 * Loop 2: the entry is loaded twice in the source (test through x + bb + 0x50, call argument through a separate
 * y = x + 0x50; *(y + bb)), so cse1 keeps two loads; combine then makes both addresses (plus sll bb) and the
 * post-reload cse deletes the second add and turns the second load into retail's `move $a0, $v1` in the jal slot.
 * x = j << 2 as its own statement gives the sll retail's $a0. The empty volatile asm (already in the earlier draft)
 * is still needed: without it loop.c strength-reduces y (20 diffs). It is the documented empty-asm barrier form
 * ("Forms still under review" in Matching-Patterns), so flag it for review when inserting. */
typedef struct { u8 p0[0x50]; s32 a[0x23]; s32 b[16]; u8 p1[0x1BC - 0xDC - 0x40]; s32 f1BC; u8 p2[0x41D8 - 0x1C0]; s32 f41D8; } O_3E0B78;
extern s32 func_003E73A0();
extern void func_003E7448();
extern void func_003E7470();
extern void func_003EE038();
void func_003E6480(O_3E0B78 **self) {
    s32 i, j, k;
    s32 n, x, off, bb;
    for (i = 0; i < 16; i++) {
        off = i << 2;
        (*self)->f1BC = i;
        if (*(s32 *)((u8 *)*self + off + 0xDC) != 0) {
            if (func_003E73A0(*(s32 *)((u8 *)*self + off + 0xDC)) == 1) {
                func_003E7448(*(s32 *)((u8 *)*self + off + 0xDC));
            }
        }
    }
    n = (*self)->f41D8;
    if (n <= 0) {
        (*self)->f1BC = -1;
        for (j = 0; j < 0x23; j++) {
            bb = (s32)*self;
            x = j << 2;
            if (*(s32 *)(x + bb + 0x50) != 0) {
                s32 y = x + 0x50;
                func_003EE038(*(s32 *)(y + bb), bb);
                __asm__ __volatile__("");
                do { } while (0);
            }
        }
    } else {
        (*self)->f41D8 = n - 1;
    }
    for (k = 0; k < 16; k++) {
        off = k << 2;
        (*self)->f1BC = k;
        if (*(s32 *)((u8 *)*self + off + 0xDC) != 0) {
            if (func_003E73A0(*(s32 *)((u8 *)*self + off + 0xDC)) == 1) {
                func_003E7470(*(s32 *)((u8 *)*self + off + 0xDC));
            }
        }
    }
    (*self)->f1BC = -1;
}
/* localdecomp:end func_003E6480 */

/* localdecomp:start func_003E65C8 */
typedef struct { u8 pad[0xDC]; s32 A[16]; s32 B[16]; } O_003E0CC0;
extern s32 func_003E73A0();
s32 func_003E65C8(O_003E0CC0 **pp, s32 b) {
    s32 r = -1;
    s32 i;
    if (func_003E73A0(b) == 0) {
        for (i = 0; i < 16; i++) {
            if ((*pp)->A[i] == 0 && (*pp)->B[i] == 0) {
                (*pp)->B[i] = b;
                r = i;
                break;
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E65C8 */

/* localdecomp:start func_003E6680 */
typedef struct { u8 pad[0x11C]; s32 slots[36]; u8 used[1]; } T_3E0D78;
typedef struct { T_3E0D78 *t; } S_3E0D78;
s32 func_003E6680(S_3E0D78 *s, s32 v) {
    s32 i = func_003E6078(s);
    T_3E0D78 *t;
    if (i < 0) return 0;
    t = s->t;
    if (t->slots[i] != 0) return 0;
    if (t->used[i] != 0) return 0;
    t->slots[i] = v;
    return 1;
}
/* localdecomp:end func_003E6680 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E66F8);

/* localdecomp:start func_003E6700 */
extern s32 func_003E6AD8();
 
void func_003E6700(void **p, s32 a, s32 b) {
    func_003E6AD8((u8 *)*p + 0x1C4, b, a);
}
/* localdecomp:end func_003E6700 */

/* localdecomp:start func_003E6730 */
extern void *func_003E6A58();
 
s32 func_003E6730(void **p) {
    return func_003E6A58((u8 *)*p + 0x1C4);
}
/* localdecomp:end func_003E6730 */

/* localdecomp:start func_003E6750 */
typedef struct {
    u8 pad0[0xDC];
    s32 a[16];
    s32 b[16];
    u8 pad1[0x50];
    u8 c[16];
} S_3E0E48;
s32 func_003E6750(void *a0, s32 a1) {
    S_3E0E48 *s = *(S_3E0E48 **)a0;
    s32 r = 0;
    if (s->a[a1] != 0 && s->c[a1] == 0) {
        s->b[a1] = 0;
        (*(S_3E0E48 **)a0)->c[a1] = 1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E6750 */

typedef struct { u32 key; void *val; } HE_3E0E90;
typedef struct { s32 f0; s32 n; HE_3E0E90 e[0x400]; } HT_3E0E90;
typedef struct { s32 f0; s32 f4; struct { s32 pad[2]; void (*fn)(void *, s32); } *vt; } O_3E0E90;
typedef struct { struct { s32 pad[3]; void (*fn)(void *, void *); } *vt; } M_3E0E90;
typedef struct { s32 f0; s32 x4; } G_3E0E90;
extern s32 D_001DAA08[2];
extern G_3E0E90 D_001DA938[];
extern void *func_003E6BB0();
extern void *func_003E6FC0();
extern s32 func_003E7078();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E6798);

/* localdecomp:start func_003E68D0 */
extern s32 D_001D9650_003E68D0;
extern s32 D_001DA880_003E68D0;
extern s32 D_001DA894_003E68D0;
extern s32 D_001DA898_003E68D0;
extern s32 D_001DA8AC_003E68D0;
extern s32 D_001DA8B0_003E68D0;
extern s32 D_001DA8C4_003E68D0;
extern s32 D_001DA8C8_003E68D0;
extern s32 D_001DA8DC_003E68D0;
extern s32 D_001DA8E0_003E68D0;
extern s32 D_001DA8F4_003E68D0;

extern s32 *func_003E7238();
extern s32 func_003E6798();
s32 func_003E68D0(s32 a) {
    if (D_001DA894_003E68D0 == 0) {
        func_003E7238(&D_001DA880_003E68D0, 0, 0x3FF, 0, func_003E6798);
        D_001DA894_003E68D0 = 1;
    }
    if (D_001DA8AC_003E68D0 == 0) {
        func_003E7238(&D_001DA898_003E68D0, 0, 0x3FF, 1, func_003E6798);
        D_001DA8AC_003E68D0 = 1;
    }
    if (D_001DA8C4_003E68D0 == 0) {
        func_003E7238(&D_001DA8B0_003E68D0, 0, 0x3FF, 2, func_003E6798);
        D_001DA8C4_003E68D0 = 1;
    }
    if (D_001DA8DC_003E68D0 == 0) {
        func_003E7238(&D_001DA8C8_003E68D0, 0, 0x3FF, 3, func_003E6798);
        D_001DA8DC_003E68D0 = 1;
    }
    if (D_001DA8F4_003E68D0 == 0) {
        func_003E7238(&D_001DA8E0_003E68D0, 0, 0x3FF, 3, func_003E6798);
        D_001DA8F4_003E68D0 = 1;
    }
    return ((s32 *)&D_001D9650_003E68D0)[a];
}
/* localdecomp:end func_003E68D0 */

/* localdecomp:start func_003E69F0 */
void func_003E69F0(u8 *p) {
    func_0038CF58((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003E69F0 */

/* localdecomp:start func_003E6A28 */
extern s32 *func_003F2748(s32 *);
void *func_003E6A28(void *p) {
    func_003F2748((s32 *)p);
    func_003E69F0(p);
    return p;
}
/* localdecomp:end func_003E6A28 */
