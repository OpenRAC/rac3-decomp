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


/* localdecomp:start func_L03_0032CED0 */
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern s32 D_L03_001DF514;
__asm__(".extern D_L03_001DF514, 16");
extern void func_L01_004F50C8(void *a, void *b, s32 c, s32 d);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
void func_L01_004450F0(s32, s32, s32);

void func_L03_0032CED0(void *arg0) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *base = D_L03_001DFA80 + (*(s32 *)(s + 0xD0) << 7);
    func_L01_004F50C8(base + 0x30, base + 0x70, 0x74, 1);
    base = D_L03_001DFA80 + (*(s32 *)(s + 0xD8) << 7);
    func_L01_003EB438(0, base + 0x30, base + 0x70, 1, 0, 0);
    D_L03_001DF514 = 0;
    *(s32 *)(s + 0x100) = 0;
    *(s32 *)(s + 0x108) = 0;
    func_L01_004450F0((s32)arg0, 2, -1);
}
/* localdecomp:end func_L03_0032CED0 */

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

/* localdecomp:start func_L03_0032CFE8 */
typedef struct S_0032CFE8 {
    char pad0[0x68];
    void *p68;
} S_0032CFE8;
typedef struct S_0032CFE8_p {
    char pad[0xCC]; s32 fCC; char padD0[4]; s32 fD4; char padD8[0x14];
    s32 fEC; u8 fF0; u8 fF1; u16 fF2; u8 fF4; char padF5[3]; s32 fF8;
    char padFC[0x10]; u16 f10C;
} S_0032CFE8_p;
typedef struct E_0032CFE8 { char pad[0x14]; s32 f14; s32 f18; char pad2[0xC]; } E_0032CFE8;
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");
extern u8 D_00142CAB[];
extern char *D_L03_001DFA80_0032CFE8;
extern char *D_L03_001DF99C_0032CFE8;
__asm__(".extern D_L03_001DF99C_0032CFE8, 16");
__asm__(".extern D_L03_001DFA80_0032CFE8, 16");
extern E_0032CFE8 D_L03_002AE4D0_0032CFE8[];
extern u8 D_00142CA0[];
extern u8 D_001427F0[];
extern u8 D_001427C3[];
extern u8 D_001427B6[];
extern u8 D_00142D40[];
extern s32 D_00142668[];
extern u8 D_001A4BE0[];
__asm__(".extern D_001A4BE0, 16");
void func_L01_00419188(s32);
void func_L03_003A1C60();
void func_L01_004A3610();
void func_L01_004F50C8();
void func_L01_004450F0();
void func_L01_004C94B0();
void func_0039EF28();
void func_L01_005003D0();
void func_L01_003EB5E0();
void func_L01_00459AF8();
void func_L03_0032CFE8(void *arg0, s32 b) {
    S_0032CFE8 *a = arg0;
    char buf[0x20];
    S_0032CFE8_p *s;
    u16 *h;
    h = (u16 *)D_001CCFD0;
    s = a->p68;
    if ((u16)(h[0x76/2] - 6) >= 2) h[0x76/2] = 5;
    if ((u16)(h[0x9E/2] - 6) >= 2) h[0x9E/2] = 5;
    if (b == 0) {
        if (D_00142CAB[0] == 0) {
            func_L01_00419188(11);
            func_L01_00419188(20);
        }
        func_L03_003A1C60(D_L03_001DF99C_0032CFE8 + (s->fCC << 8), buf, buf + 16);
        func_L01_004A3610(buf, buf + 16);
        {
            char *t = D_L03_001DFA80_0032CFE8 + (s->fD4 << 7);
            func_L01_004F50C8(t + 0x30, t + 0x70, 0, 1);
        }
        func_L01_004450F0(a, 1, -1);
    } else {
        s32 small;
        u8 *q;
        E_0032CFE8 *e = &D_L03_002AE4D0_0032CFE8[b];
        s->fF1 = b;
        s->fEC = -1;
        if (e->f14 != -1) s->fEC = (e->f14 * 5 + 2) / 6;
        small = b < 9;
        if (e->f18 != -1) {
            u8 *flags = D_00142CA0;
            if (flags[0x16] != 0) {
                u8 c = D_001427F0[0x58];
                *(s32 *)(D_001427F0 + 0x58) = 0;
                D_001427C3[0] = c + 1;
                func_L01_004C94B0();
            }
            if (!small && flags[e->f18] == 0) {
                flags[e->f18] = 1;
                D_00142D40[e->f18] = 1;
                func_0039EF28();
                D_001427B6[0] = e->f18;
            }
        }
        {
            q = D_001A4BE0;
            *(s32 *)(q + 0x2850) = D_00142668[0];
        }
        func_L01_005003D0(0, 1);
        func_L01_003EB5E0(0, 2);
        s->fF0 = 0; s->fF4 = 0; s->fF8 = 0; s->f10C = 0;
        if (small) func_L01_004A3610(q + 0x80, q + 0x90);
        func_L01_00459AF8();
        s->fF2 = 0x11;
        func_L01_004450F0(a, 4, -1);
    }
}
/* localdecomp:end func_L03_0032CFE8 */

/* localdecomp:start func_L03_0032D228 */
extern u8 D_001426E0[];
extern s32 D_00142848[];
extern u8 D_001A74A9[];
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_004126C8(void);

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
    func_L01_004126C8();
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
