#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E6700();
extern void func_003E6700(void **, s32, s32);
/* --- end of declarations from other files --- */

/* declarations of 3E5C60.c's earlier functions */
extern s32 func_003E6730();
extern s32 func_003E74D0();
extern void func_003E6238();
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
extern s32 func_003E5F88(void **p);
extern void func_003E5FA8(S_3E06A0 **p);
extern void func_003E5FD8(s32 *arg0);
extern s32 func_003E6078(void **p);

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
