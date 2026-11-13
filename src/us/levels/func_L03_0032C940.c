#include "common.h"

/* NTSC-U counterpart of func_L03_0032CFE8 (src/levels/03_starship_phoenix/L03_0032CED0.c) */
extern void func_L01_004F12C0(void *a, void *b, s32 c, s32 d);
extern void func_L03_0032C940(void *a, s32 b);

/* localdecomp:start func_L03_0032C940 */
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
extern char *D_L03_001DFB00_0032C940;
extern char *D_L03_001DFA1C_0032C940;
__asm__(".extern D_L03_001DFA1C_0032C940, 16");
__asm__(".extern D_L03_001DFB00_0032C940, 16");
extern E_0032CFE8 D_L03_002AE550_0032C940[];
extern u8 D_00142CA0[];
extern u8 D_001427F0[];
extern u8 D_001427C3[];
extern u8 D_001427B6[];
extern u8 D_00142D40[];
extern s32 D_00142668[];
extern u8 D_001A4BE0[];
__asm__(".extern D_001A4BE0, 16");
void func_L01_00416B38(s32);
void func_L03_003A0478();
void func_L01_0049FDB0();
void func_L01_004F12C0();
void func_L01_00441FB8();
void func_L01_004C5900();
void func_00399F90();
void func_L01_004FC518();
void func_L01_003E9730();
void func_L01_00456808();
void func_L03_0032C940(void *arg0, s32 b) {
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
            func_L01_00416B38(11);
            func_L01_00416B38(20);
        }
        func_L03_003A0478(D_L03_001DFA1C_0032C940 + (s->fCC << 8), buf, buf + 16);
        func_L01_0049FDB0(buf, buf + 16);
        {
            char *t = D_L03_001DFB00_0032C940 + (s->fD4 << 7);
            func_L01_004F12C0(t + 0x30, t + 0x70, 0, 1);
        }
        func_L01_00441FB8(a, 1, -1);
    } else {
        s32 small;
        u8 *q;
        E_0032CFE8 *e = &D_L03_002AE550_0032C940[b];
        s->fF1 = b;
        s->fEC = -1;
        if (e->f14 != -1) s->fEC = e->f14;
        small = b < 9;
        if (e->f18 != -1) {
            u8 *flags = D_00142CA0;
            if (flags[0x16] != 0) {
                u8 c = D_001427F0[0x58];
                *(s32 *)(D_001427F0 + 0x58) = 0;
                D_001427C3[0] = c + 1;
                func_L01_004C5900();
            }
            if (!small && flags[e->f18] == 0) {
                flags[e->f18] = 1;
                D_00142D40[e->f18] = 1;
                func_00399F90();
                D_001427B6[0] = e->f18;
            }
        }
        {
            q = D_001A4BE0;
            *(s32 *)(q + 0x2850) = D_00142668[0];
        }
        func_L01_004FC518(0, 1);
        func_L01_003E9730(0, 2);
        s->fF0 = 0; s->fF4 = 0; s->fF8 = 0; s->f10C = 0;
        if (small) func_L01_0049FDB0(q + 0x80, q + 0x90);
        func_L01_00456808();
        s->fF2 = 0x14;
        func_L01_00441FB8(a, 4, -1);
    }
}
/* localdecomp:end func_L03_0032C940 */
