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

INCLUDE_ASM("asm/levels", func_L03_0032C3A8);

/* localdecomp:start func_L03_0032C870 */
extern s32 D_001DD118_sda;
__asm__(".extern D_001DD118_sda, 4");
s32 *func_L03_0032C870(void *unused, s32 a1, s32 *out) {
    if (a1 == 0) {
        *out = 16;
        return &D_001DD118_sda;
    }
    return 0;
}
/* localdecomp:end func_L03_0032C870 */

/* localdecomp:start func_L03_0032C890 */
extern u8 D_001DD10A_sda;
__asm__(".extern D_001DD10A_sda, 1");
extern void *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern u32 D_001A7F70[];
__asm__(".extern D_001A7F70, 16");
extern u32 D_001D545C;
__asm__(".extern D_001D545C, 16");
void func_L01_0041A5B0(s32 a, s32 b);
void func_L03_0032CF78(void *a, s32 b);

void func_L03_0032C890(s32 a, u8 b) {
    D_001DD10A_sda = b;
    if (a == 0x7F) {
        if ((D_001A7F70[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xB79, 0x1C);
        }
    }
    func_L03_0032CF78(D_001DD104_sda, a);
}
/* localdecomp:end func_L03_0032C890 */

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
typedef struct S_0032CF78 { char pad[0xD0]; int idx; } S_0032CF78;
extern char *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
void func_L01_004F50C8(void *dst, void *src, int n, int m);
s32 func_L03_0032F670(s32 arg0);
void func_L03_0032CFE8(void *a, s32 b);
void func_L03_0032CF78(void *a, s32 b) {
    char *p = D_L03_001DFA80 + ((S_0032CF78 *)*(void **)((char *)a + 0x68))->idx * 128;
    func_L01_004F50C8(p + 0x30, p + 0x70, 0x74, 1);
    func_L03_0032CFE8(a, func_L03_0032F670(b));
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

INCLUDE_ASM("asm/levels", func_L03_0032D8C0);
