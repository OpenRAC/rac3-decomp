#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_0038CB78();
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CB78(void *, s32, s32);
extern s32 *func_003E5918(s32 *);
extern s32 func_003E58F8();
extern void func_003E6348();
extern void func_0038CB78(void *, int, int);
extern void func_003E6348(void **, s32, s32);
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
extern void func_003873C0();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_00384CC8(s32);

LINKER_REMNANT("asm/remnants", func_003E58A8);

/* localdecomp:start func_003E58C0 */
void func_003E58C0(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_003E58C0 */

/* localdecomp:start func_003E58F8 */
extern s32 func_003E6378();
 
s32 func_003E58F8(void **p) {
    return func_003E6378(p) != 0;
}
/* localdecomp:end func_003E58F8 */

/* localdecomp:start func_003E5918 */
s32 *func_003E5918(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003E5918 */

/* localdecomp:start func_003E5928 */
typedef struct { u8 p0[0x50]; s32 *arr[35]; u8 pad[0x41DC - 0xDC]; } O_3E03D8;
extern O_3E03D8 D_00306E00_003E5928[];
extern O_3E03D8 D_0031B74C[];
extern s32 func_003E7118();
void func_003E5928(void) {
    O_3E03D8 *s = D_00306E00_003E5928;
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
                            if (*q) func_003E7118(*q);
                            *q = 0;
                        } while (p->arr != q);
                    }
                }
            } while (p != D_00306E00_003E5928);
        }
    }
}
/* localdecomp:end func_003E5928 */

/* localdecomp:start func_003E59C8 */
extern u8 D_00306E00[];
extern s32 D_001DA878;
extern void *func_003E6670();
extern void func_116FD0();
extern void func_003E5928();
void *func_003E59C8(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_001DA878 == 0) {
        q = D_00306E00;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_003E6670(q + 0x1C4);
            func_003E6670(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_001DA878 = 1;
        func_116FD0(func_003E5928);
    }
    return D_00306E00 + idx * 0x41DC;
}
/* localdecomp:end func_003E59C8 */

/* localdecomp:start func_003E5AA0 */
typedef struct { u8 b[16]; } B16_003E0550;
typedef struct { B16_003E0550 hdr; s32 a[16]; s32 b[16]; u8 p90[0x4C]; s32 c[16]; s32 d[16]; s32 e[16]; u8 f[16]; u8 g[16]; s32 f1BC; u32 f1C0; u8 p1C4[0x41D4 - 0x1C4]; s32 f41D4; s32 f41D8; } O_003E0550;
extern void func_003E5E80();
s32 func_003E5AA0(O_003E0550 **o, u32 mode) {
    B16_003E0550 tmp;
    s32 i;
    if (mode < 5) {
        *o = func_003E59C8(mode);
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
        func_003E5E80(o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5AA0 */

/* localdecomp:start func_003E5BD0 */
s32 func_003E5BD0(void **p) {
    return *(s32 *)((u8 *)*p + 0x1C0);
}
/* localdecomp:end func_003E5BD0 */

LINKER_REMNANT("asm/remnants", func_003E5BE0);

/* localdecomp:start func_003E5BF0 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_003E5BF0(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_003E5BF0 */

/* localdecomp:start func_003E5C20 */
extern void func_003E6FE0(void *);

void func_003E5C20(s32 *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    void *temp_v0;

    var_s2 = 0;
    do {
        temp_s0 = var_s2 * 4;
        temp_v1 = (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC));
        if (temp_v1 != 0) {
            func_003E6FE0(temp_v1);
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
/* localdecomp:end func_003E5C20 */

/* localdecomp:start func_003E5CC0 */
s32 func_003E5CC0(void **p) {
    return *(s32 *)((u8 *)*p + 0x1BC);
}
/* localdecomp:end func_003E5CC0 */

/* localdecomp:start func_003E5CD0 */
typedef struct { u8 pad[0xDC]; s32 arr[1]; } S_3E0780;
 
s32 func_003E5CD0(S_3E0780 **p, s32 i) {
    return (*p)->arr[i];
}
/* localdecomp:end func_003E5CD0 */

extern s32 D_001D96D0[];
extern s32 func_003E7118();
extern void func_003E7108();
INCLUDE_ASM("asm/nonmatchings/text", func_003E5CE8);

/* localdecomp:start func_003E5DC0 */
extern s32 func_003E7118();
extern s32 func_003E5BD0();
extern s32 func_003E6518(s32);
extern s32 func_003E6EA0();
s32 func_003E5DC0(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_003E7118(*q);
        *q = 0;
        for (i = 3; i >= 0; i--) {
            func_003E6EA0(func_003E6518(func_003E5BD0(p)));
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5DC0 */

/* localdecomp:start func_003E5E50 */
void func_003E5E50(s32 **p) {
    s32 i;
    for (i = 0; i < 35; i++) (*p)[i + 20] = 0;
}
/* localdecomp:end func_003E5E50 */

/* localdecomp:start func_003E5E80 */
typedef struct { u8 b[16]; } B16_003E0930;
extern B16_003E0930 D_001D9640;
extern void func_003E6638();
extern void func_003E5C20();
extern void func_003E5E50();
extern void func_003E5BF0();
void func_003E5E80(u8 **o) {
    B16_003E0930 tmp;
    func_003E6638(*o + 0x1C4);
    func_003E6638(*o + 0x21CC);
    func_003E5C20(o);
    func_003E5E50(o);
    func_003E5BF0(o);
    tmp = D_001D9640;
    *(B16_003E0930 *)*o = tmp;
    *(s32 *)(*o + 0x1BC) = -1;
}
/* localdecomp:end func_003E5E80 */

/* localdecomp:start func_003E5F28 */
/* func_003E5F28: MATCH (agent, 2026-10-17). Flags: the file's own (no override).
 * Second loop: the entry is read twice through two differently built addresses, the test through
 * y = x + 0x50; *(y + o) and the argument through *(x + o + 0x50). cse1 keeps them apart; combine turns both into
 * (plus sll o), and the post-reload cse makes the later one retail's `move $v1, $a2` copy (the argument's add was
 * hoisted above the test by sched1). Same mechanism as func_003E60C8's match.
 * USES INLINE ASM: a register fence `__asm__("" : "+r"(x));` on x = j << 2 (the empty-asm barrier form listed under
 * "Forms still under review" in Matching-Patterns). Without it loop.c strength-reduces y (20-23 diffs); every
 * fence-free form tried (barrier/do-while tails, j * 4, 0x50 + x) stays at 20+ or gives func_003E60C8's
 * single-add shape instead. Flag it for review when inserting. */
typedef struct { u8 pad0[0x50]; s32 *E[35]; s32 A[16]; s32 B[16]; u8 pad1[0x50]; u8 C[16]; s32 x1BC; } O_003E09D8;
extern s32 func_003E6FE8();
extern void func_003E7040();
extern void func_003E7018();
extern void func_003E6FF0();
extern void func_003E7068();
extern s32 func_003EDBD8();
void func_003E5F28(O_003E09D8 **pp) {
    s32 i;
    s32 j;
    for (i = 0; i < 16; i++) {
        (*pp)->x1BC = i;
        if ((*pp)->A[i] != 0 && func_003E6FE8((*pp)->A[i]) == 0) {
            func_003E7040((*pp)->A[i]);
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
                func_003E7018((*pp)->A[i]);
                func_003E6FF0((*pp)->A[i], 1);
                (*pp)->B[i] = 0;
            } else {
                goto M;
            }
        }
L:
        if ((*pp)->A[i] != 0) {
M:
            if (func_003E6FE8((*pp)->A[i]) == 1) {
                func_003E7068((*pp)->A[i]);
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
            func_003EDBD8(*(s32 **)(x + (s32)o + 0x50), o);
        }
    }
}
/* localdecomp:end func_003E5F28 */

/* localdecomp:start func_003E60C8 */
/* func_003E60C8: MATCH (agent, 2026-10-17). Flags: the file's own (no override).
 * Loop 2: the entry is loaded twice in the source (test through x + bb + 0x50, call argument through a separate
 * y = x + 0x50; *(y + bb)), so cse1 keeps two loads; combine then makes both addresses (plus sll bb) and the
 * post-reload cse deletes the second add and turns the second load into retail's `move $a0, $v1` in the jal slot.
 * x = j << 2 as its own statement gives the sll retail's $a0. The empty volatile asm (already in the earlier draft)
 * is still needed: without it loop.c strength-reduces y (20 diffs). It is the documented empty-asm barrier form
 * ("Forms still under review" in Matching-Patterns), so flag it for review when inserting. */
typedef struct { u8 p0[0x50]; s32 a[0x23]; s32 b[16]; u8 p1[0x1BC - 0xDC - 0x40]; s32 f1BC; u8 p2[0x41D8 - 0x1C0]; s32 f41D8; } O_3E0B78;
extern s32 func_003E6FE8();
extern void func_003E7090();
extern void func_003E70B8();
extern void func_003EDC80();
void func_003E60C8(O_3E0B78 **self) {
    s32 i, j, k;
    s32 n, x, off, bb;
    for (i = 0; i < 16; i++) {
        off = i << 2;
        (*self)->f1BC = i;
        if (*(s32 *)((u8 *)*self + off + 0xDC) != 0) {
            if (func_003E6FE8(*(s32 *)((u8 *)*self + off + 0xDC)) == 1) {
                func_003E7090(*(s32 *)((u8 *)*self + off + 0xDC));
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
                func_003EDC80(*(s32 *)(y + bb), bb);
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
            if (func_003E6FE8(*(s32 *)((u8 *)*self + off + 0xDC)) == 1) {
                func_003E70B8(*(s32 *)((u8 *)*self + off + 0xDC));
            }
        }
    }
    (*self)->f1BC = -1;
}
/* localdecomp:end func_003E60C8 */

/* localdecomp:start func_003E6210 */
typedef struct { u8 pad[0xDC]; s32 A[16]; s32 B[16]; } O_003E0CC0;
extern s32 func_003E6FE8();
s32 func_003E6210(O_003E0CC0 **pp, s32 b) {
    s32 r = -1;
    s32 i;
    if (func_003E6FE8(b) == 0) {
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
/* localdecomp:end func_003E6210 */

/* localdecomp:start func_003E62C8 */
typedef struct { u8 pad[0x11C]; s32 slots[36]; u8 used[1]; } T_3E0D78;
typedef struct { T_3E0D78 *t; } S_3E0D78;
s32 func_003E62C8(S_3E0D78 *s, s32 v) {
    s32 i = func_003E5CC0(s);
    T_3E0D78 *t;
    if (i < 0) return 0;
    t = s->t;
    if (t->slots[i] != 0) return 0;
    if (t->used[i] != 0) return 0;
    t->slots[i] = v;
    return 1;
}
/* localdecomp:end func_003E62C8 */

LINKER_REMNANT("asm/remnants", func_003E6340);

/* localdecomp:start func_003E6348 */
extern s32 func_003E6720();
 
void func_003E6348(void **p, s32 a, s32 b) {
    func_003E6720((u8 *)*p + 0x1C4, b, a);
}
/* localdecomp:end func_003E6348 */

/* localdecomp:start func_003E6378 */
extern void *func_003E66A0();
 
s32 func_003E6378(void **p) {
    return func_003E66A0((u8 *)*p + 0x1C4);
}
/* localdecomp:end func_003E6378 */

/* localdecomp:start func_003E6398 */
typedef struct {
    u8 pad0[0xDC];
    s32 a[16];
    s32 b[16];
    u8 pad1[0x50];
    u8 c[16];
} S_3E0E48;
s32 func_003E6398(void *a0, s32 a1) {
    S_3E0E48 *s = *(S_3E0E48 **)a0;
    s32 r = 0;
    if (s->a[a1] != 0 && s->c[a1] == 0) {
        s->b[a1] = 0;
        (*(S_3E0E48 **)a0)->c[a1] = 1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E6398 */

typedef struct { u32 key; void *val; } HE_3E0E90;
typedef struct { s32 f0; s32 n; HE_3E0E90 e[0x400]; } HT_3E0E90;
typedef struct { s32 f0; s32 f4; struct { s32 pad[2]; void (*fn)(void *, s32); } *vt; } O_3E0E90;
typedef struct { struct { s32 pad[3]; void (*fn)(void *, void *); } *vt; } M_3E0E90;
typedef struct { s32 f0; s32 x4; } G_3E0E90;
extern s32 D_001DAA08[2];
extern G_3E0E90 D_001DA938[];
extern void *func_003E67F8();
extern void *func_003E6C08();
extern s32 func_003E6CC0();
INCLUDE_ASM("asm/nonmatchings/text", func_003E63E0);

/* localdecomp:start func_003E6518 */
extern s32 D_001D9650_003E6518;
extern s32 D_001DA880_003E6518;
extern s32 D_001DA894_003E6518;
extern s32 D_001DA898_003E6518;
extern s32 D_001DA8AC_003E6518;
extern s32 D_001DA8B0_003E6518;
extern s32 D_001DA8C4_003E6518;
extern s32 D_001DA8C8_003E6518;
extern s32 D_001DA8DC_003E6518;
extern s32 D_001DA8E0_003E6518;
extern s32 D_001DA8F4_003E6518;

extern s32 *func_003E6E80();
extern s32 func_003E63E0();
s32 func_003E6518(s32 a) {
    if (D_001DA894_003E6518 == 0) {
        func_003E6E80(&D_001DA880_003E6518, 0, 0x3FF, 0, func_003E63E0);
        D_001DA894_003E6518 = 1;
    }
    if (D_001DA8AC_003E6518 == 0) {
        func_003E6E80(&D_001DA898_003E6518, 0, 0x3FF, 1, func_003E63E0);
        D_001DA8AC_003E6518 = 1;
    }
    if (D_001DA8C4_003E6518 == 0) {
        func_003E6E80(&D_001DA8B0_003E6518, 0, 0x3FF, 2, func_003E63E0);
        D_001DA8C4_003E6518 = 1;
    }
    if (D_001DA8DC_003E6518 == 0) {
        func_003E6E80(&D_001DA8C8_003E6518, 0, 0x3FF, 3, func_003E63E0);
        D_001DA8DC_003E6518 = 1;
    }
    if (D_001DA8F4_003E6518 == 0) {
        func_003E6E80(&D_001DA8E0_003E6518, 0, 0x3FF, 3, func_003E63E0);
        D_001DA8F4_003E6518 = 1;
    }
    return ((s32 *)&D_001D9650_003E6518)[a];
}
/* localdecomp:end func_003E6518 */

/* localdecomp:start func_003E6638 */
void func_003E6638(u8 *p) {
    func_0038CB78((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003E6638 */

/* localdecomp:start func_003E6670 */
extern s32 *func_003F2390(s32 *);
void *func_003E6670(void *p) {
    func_003F2390((s32 *)p);
    func_003E6638(p);
    return p;
}
/* localdecomp:end func_003E6670 */
