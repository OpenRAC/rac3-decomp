#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;

INCLUDE_ASM("asm/levels", func_L03_0032C3A8);

INCLUDE_ASM("asm/levels", func_L03_0032C870);

INCLUDE_ASM("asm/levels", func_L03_0032C890);

/* localdecomp:start func_L03_0032C8F8 */
extern u8 D_L03_001DD10A;

s32 func_L03_0032C8F8(void) {
    if (D_L03_001DD10A != 0) {
        D_L03_001DD10A = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L03_0032C8F8 */

INCLUDE_ASM("asm/levels", func_L03_0032C918);

INCLUDE_ASM("asm/levels", func_L03_0032CBD8);

INCLUDE_ASM("asm/levels", func_L03_0032CE38);

INCLUDE_ASM("asm/levels", func_L03_0032CED0);

/* localdecomp:start func_L03_0032CF78 */
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern void func_L01_004F50C8(void *a, void *b, s32 c, s32 d);
extern s32 func_L03_0032F670(void *a);
extern void func_L03_0032CFE8(void *a, s32 b);

void func_L03_0032CF78(Obj_32CF78 *a0, void *a1) {
    u8 *base = D_L03_001DFA80 + (a0->p68->idx << 7);
    func_L01_004F50C8(base + 0x30, base + 0x70, 0x74, 1);
    func_L03_0032CFE8(a0, func_L03_0032F670(a1));
}
/* localdecomp:end func_L03_0032CF78 */

INCLUDE_ASM("asm/levels", func_L03_0032CFE8);

/* localdecomp:start func_L03_0032D228 */
extern u8 D_001426E0[];
extern s32 D_00142848[];
extern u8 D_001A74A9[];
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_003F1760(void);

void func_L03_0032D228(u8 *a0) {
    S_Foo_0032D228 *s = *(S_Foo_0032D228 **)(a0 + 0x68);
    u8 *b;
    s32 v;
    u32 w;

    if (s->f4 != 0) {
        func_L01_004AAC98(8, 0, (s32) a0, 0x1936);
    } else {
        s->f108 = 0;
        func_L01_004AAC98(9, 0, (s32) a0, 0x1936);
    }
    b = D_001426E0;
    v = b[0xE3];
    w = v;
    if (v != 0) {
        s32 *d = D_00142848;
        v = 0;
        b[0xE3] = 0;
        do {
            *d = w - 1;
        } while (0);
    }
    D_001A74A9[0] = 0;
    func_L01_003F1760();
    s->f2 = 0xC8;
    func_L01_004450F0((s32) a0, 9, -1);
}
/* localdecomp:end func_L03_0032D228 */

/* localdecomp:start func_L03_0032D2D8 */
extern s32 func_L03_0032D348(void *p, s32 i);

s32 func_L03_0032D2D8(void *p) {
    s32 i = 0;
    s32 r = 0;
    s32 one = 1;

    do {
        s32 v = func_L03_0032D348(p, i);
        i++;
        if (v != 0) {
            r = one;
        }
    } while (i < 3);
    return r;
}
/* localdecomp:end func_L03_0032D2D8 */

INCLUDE_ASM("asm/levels", func_L03_0032D348);

/* localdecomp:start func_L03_0032D598 */
void *func_L03_0032F6A8();

s32 func_L03_0032D598(void *arg0, u8 *arg1) {
    S_0032D598 *tbl;
    s32 idx;

    arg1 = func_L03_0032F6A8(arg1);
    if (arg1[0x1C] == 1 || arg1[0x1C] == 3) {
        return 1;
    }
    if (arg0 != 0) {
        if (*(s16 *)((u8 *)arg0 + 0xAA) == 0x1936) {
            tbl = *(S_0032D598 **)((u8 *)arg0 + 0x68);
            idx = arg1[0x1D];
            if (tbl->cnt[idx] > 0) {
                goto body;
            }
        }
    }
    return 0;
body:
    arg1[0x1C] = 1;
    {
        s32 j = arg1[0x1D];
        tbl->cnt[j] = tbl->cnt[j] - 1;
    }
    return 1;
}
/* localdecomp:end func_L03_0032D598 */

INCLUDE_ASM("asm/levels", func_L03_0032D640);

INCLUDE_ASM("asm/levels", func_L03_0032D6B8);

/* localdecomp:start func_L03_0032D8C0 */
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;

s32 func_L03_0032D8C0(u8 *a0) {
    s32 best;
    u16 *p;
    u8 *e;
    u8 *r;

    r = func_L03_0032F6A8(a0);
    if ((u8)(r[0x1C] - 2) < 2) return -1;
    if (*(s16 *)(r + 0x1A) != -1) return *(s16 *)(r + 0x1A);
    best = -1;
    p = D_L03_0021C620[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L03_001DF9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L03_0021C620[a0[0x21]])) {
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            r = func_L03_0032F6A8(e);
            if (r[0x1C] == 1) {
                s16 v = *(s16 *)(r + 0x1A);
                if (best < v) best = v;
            }
        }
        p++;
    }
    return best + 1;
}
/* localdecomp:end func_L03_0032D8C0 */
