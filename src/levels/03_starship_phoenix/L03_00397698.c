#include "common.h"

/* localdecomp:start func_L03_00397698 */
typedef struct { int f0; char p4[0x14]; int f18; u8 c1c; u8 c1d; u8 c1e; u8 c1f; } S_00397698b;
typedef struct { char p[0x20]; u8 c20; char p21[0x75]; u16 h96; } S_00397698a;
typedef struct { char p[0x1A4]; int f1A4; } S_00397698c;
extern s32 D_001D4CF0; __asm__(".extern D_001D4CF0, 16");
extern s32 D_001D545C_sda_00397698; __asm__(".extern D_001D545C_sda_00397698, 4");
extern s32 D_001D6694_sda_00397698; __asm__(".extern D_001D6694_sda_00397698, 4");
extern s32 D_L03_001D6694; __asm__(".extern D_L03_001D6694, 16");
extern u8 D_001426E8[]; __asm__(".extern D_001426E8, 16");
extern s32 D_001DF4C0_sda; __asm__(".extern D_001DF4C0_sda, 4");
extern s32 D_00142660[]; __asm__(".extern D_00142660, 16");
extern char *D_L03_001DF99C; __asm__(".extern D_L03_001DF99C, 16");
extern s32 D_00142C10[]; __asm__(".extern D_00142C10, 16");
extern s32 D_L03_002D09B0[]; __asm__(".extern D_L03_002D09B0, 16");
extern S_00397698c *D_001D52FC_sda_00397698; __asm__(".extern D_001D52FC_sda_00397698, 4");
extern s32 D_001DE320_sda; __asm__(".extern D_001DE320_sda, 4");
extern s32 D_001DE330_sda; __asm__(".extern D_001DE330_sda, 4");
extern s32 D_001DE2F0_sda; __asm__(".extern D_001DE2F0_sda, 4");
extern u8 D_001DE308_sda; __asm__(".extern D_001DE308_sda, 4");
extern void func_L03_003979F0();
extern int func_L01_004BA800();
extern int func_L03_00397CF8(void *);
extern int func_L03_00397BF0(void *);
extern void func_L03_00397B38(void *);
extern void func_L01_00456230(void *, int);
extern int func_L01_004561B8(void *);
extern void func_L01_003EB438(int, void *, void *, int, int, int);
extern void func_L01_003EB5E0(int, int);
extern s32 func_L01_00452560(int, int, int, int, int, int, int);
extern void func_L01_004450F0(void *, int, int);
extern void func_003A0EC0(int, int, int, int, int);
extern void func_L03_0034B348(int);
extern void func_003A2CD8(void *);
void func_L03_00397698(S_00397698a *a) {
    S_00397698b *b = *(S_00397698b **)((char *)a + 0x68);
    int arg;
    int t;
    int x;
    if (a->c20 == 0) {
        func_L03_003979F0(a);
        x = D_001D6694_sda_00397698;
    } else {
        if ((u32)(D_001D4CF0 - 0x1F) < 5) D_001D4CF0 = D_001D545C_sda_00397698;
        x = D_L03_001D6694;
    }
    if (x == 2) return;
    if (func_L01_004BA800() != 0) return;
    switch (a->c20) {
    case 3:
        if (D_001426E8[0] == 0) return;
        if (D_001DF4C0_sda < 6) return;
        if (func_L01_004BA800() != 0) return;
        if (b->c1c != 0) {
            func_L03_00397CF8(a);
            b->c1c = 0;
        }
        t = b->f18;
        if (t != 0) {
            D_00142660[0] += t;
            b->f18 = 0;
        }
        if (func_L03_00397BF0(a) == 0) return;
        func_L03_00397B38(a);
        if (b->c1d & 1) {
            func_L01_00456230(D_L03_001DF99C + (b->f0 << 8), 1);
            if (D_00142C10[0] & 0x80000) {
                func_L01_004450F0(a, 6, -1);
                return;
            } else {
                func_L01_004450F0(a, 1, -1);
                return;
            }
        } else {
            func_L01_004450F0(a, 6, -1);
            return;
        }
    case 10:
        if (func_L01_004561B8(a) != 0) func_L01_003EB438(0, &D_001DE320_sda, &D_001DE330_sda, 4, 0, 0);
        a->h96++;
        if (D_001DE2F0_sda < a->h96) {
            func_L01_003EB5E0(0, 2);
            func_L01_004450F0(a, 3, -1);
        }
        return;
    case 6:
        if (b->c1e != 0) {
            func_L01_004450F0(a, 9, -1);
            return;
        } else {
            func_L01_004450F0(a, 5, -1);
            return;
        }
    case 5:
        func_L01_00452560(0, 1, 0xA22, 1, 0, 0, 0);
        if (D_L03_002D09B0[0] == 1 && (D_001D52FC_sda_00397698->f1A4 & 0x10)) func_L01_004450F0(a, 7, -1);
        if (func_L03_00397BF0(a) != 0) return;
        func_L01_004450F0(a, 3, -1);
        return;
    case 9:
        func_L01_00452560(0, 1, 0xA23, 1, 0, 0, 0);
        if (D_L03_002D09B0[0] == 1 && (D_001D52FC_sda_00397698->f1A4 & 0x10)) func_L01_004450F0(a, 4, -1);
    case 7:
        if (func_L03_00397BF0(a) != 0) return;
        func_L01_004450F0(a, 3, -1);
        return;
    case 4:
        func_003A0EC0(3, 1, 0xF, 0, 0);
        func_L01_004450F0(a, 3, -1);
        return;
    case 1:
        if ((D_00142C10[0] & 0x80000) == 0) return;
        func_L03_0034B348(D_001DE308_sda);
        func_003A2CD8(D_001D52FC_sda_00397698);
        func_L01_004450F0(a, 3, -1);
        return;
    case 8:
        if (func_L01_004BA800() != 0) return;
        func_L03_0034B348(b->c1f);
        func_L01_004450F0(a, 3, -1);
        return;
    case 2:
    default:
        return;
    }
}
/* localdecomp:end func_L03_00397698 */

/* localdecomp:start func_L03_003979F0 */
typedef struct { char p0[0x10]; int f10; char p14[4]; int f18; char p1c; } S_003979F0b;
typedef struct { char p[0x20]; u8 c20; } S_003979F0a;
extern void *D_001DE310_sda_003979F0; __asm__(".extern D_001DE310_sda_003979F0, 4");
extern s32 D_001D4CF0_sda; __asm__(".extern D_001D4CF0_sda, 4");
extern s32 D_001D4CF0; __asm__(".extern D_001D4CF0, 16");
extern u8 D_001426E0[];
extern u8 *D_L03_001DFA80; __asm__(".extern D_L03_001DFA80, 16");
extern void func_L03_00397B38(void *);
extern int func_L03_00397CF8(void *);
extern void func_L01_004F50C8(u8 *, u8 *, int, int);
extern void func_0039EC28(int, int);
extern void func_L01_004450F0(void *, int, int);
void func_L03_003979F0(S_003979F0a *a) {
    S_003979F0b *b = *(S_003979F0b **)((char *)a + 0x68);
    int i;
    int r;
    D_001DE310_sda_003979F0 = a;
    func_L03_00397B38(a);
    if ((u32)(D_001D4CF0 - 0x1F) < 5) {
        b->f18 = 0;
        for (i = 2; i >= 0; i--) {
            b->f18 <<= 8;
            b->f18 += D_001426E0[0x57 - (2 - i)];
        }
        D_001426E0[0x55] = 0;
        D_001426E0[0x56] = 0;
        D_001426E0[0x57] = 0;
        b->p1c = D_001D4CF0;
        r = func_L03_00397CF8(a) & 0xFF;
        b->p1c = 0;
        func_L01_004F50C8(D_L03_001DFA80 + (b->f10 << 7) + 0x30, D_L03_001DFA80 + (b->f10 << 7) + 0x70, 0, 1);
        if (a->c20 == 0) {
            if (r) {
                int old = D_001D4CF0_sda;
                D_001D4CF0_sda = 3;
                func_0039EC28(1, -1);
                D_001D4CF0 = old;
                func_L01_004450F0(a, 10, -1);
            } else {
                func_L01_004450F0(a, 3, -1);
            }
        }
    } else {
        func_L01_004450F0(a, 3, -1);
    }
}
/* localdecomp:end func_L03_003979F0 */

INCLUDE_ASM("asm/levels", func_L03_00397B38);

/* localdecomp:start func_L03_00397BF0 */
typedef struct { s32 f00; u8 pad04[0x20]; s32 f24; } S_00397BF0a;
typedef struct { u8 pad00[0x80]; u8 f80[0x25E4 - 0x80]; u8 b25E4; u8 pad25E5[0x288C - 0x25E5]; s16 h288C; } S_00397BF0b;
typedef struct { u8 pad00[0x14]; s32 f14; } S_00397BF0c;
extern S_00397BF0a D_L03_002E52F0;
extern u16 D_00143954[];
extern S_00397BF0b D_001A4BE0;
extern s32 func_00382380(void *, s32, s32);
s32 func_L03_00397BF0(void *a) {
    S_00397BF0c *c = *(S_00397BF0c **)((u8 *)a + 0x68);
    s32 r = 0;
    if ((D_L03_002E52F0.f00 != 0 || D_L03_002E52F0.f24 != -1) && D_00143954[0] != 0) {
    } else if (D_001A4BE0.b25E4 == 0 && D_001A4BE0.h288C == 0) {
        r = func_00382380(D_001A4BE0.f80, c->f14, 0) != 0;
    }
    return r;
}
/* localdecomp:end func_L03_00397BF0 */

/* localdecomp:start func_L03_00397C78 */
typedef struct { char pad[0x30]; unsigned char c30; char pad2[0x33]; void (*f64)(void *); } S_00397C78;
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_L01_00456230(void *, int);
extern void func_L01_005003D0(int, int);
extern void func_L01_004450F0(void *, int, int);
void func_L03_00397C78(S_00397C78 *a, int b) {
    S_00397C78 *p = (S_00397C78 *)(D_L03_001DF99C + (b << 8));
    func_L01_00456230(p, 1);
    p->c30 = 0xFF;
    p->f64(p);
    a->c30 = 0x40;
    func_L01_005003D0(0, 1);
    func_L01_004450F0(a, 3, -1);
}
/* localdecomp:end func_L03_00397C78 */

/* localdecomp:start func_L03_00397CF8 */
typedef struct { char p0[4]; int f4; int f8; int fC; char p10[0xC]; u8 c1c; } S_00397CF8b;
typedef struct { char p[0x30]; u8 c30; char p31[0x37]; S_00397CF8b *p68; } S_00397CF8a;
extern u8 D_001426EB[]; __asm__(".extern D_001426EB, 16");
extern u8 D_00142734[]; __asm__(".extern D_00142734, 16");
extern s32 D_00142C24[]; __asm__(".extern D_00142C24, 16");
extern s32 D_00142C20[]; __asm__(".extern D_00142C20, 16");
extern s32 D_00142BC4[]; __asm__(".extern D_00142BC4, 16");
extern char D_L03_001E8FC0[]; __asm__(".extern D_L03_001E8FC0, 16");
extern int func_00392B20(void *, int);
extern void func_00392C78(void *);
int func_L03_00397CF8(void *a0) {
    S_00397CF8a *a = a0;
    S_00397CF8b *b = a->p68;
    int arg;
    char *p;
    unsigned long t;
    switch (b->c1c) {
    case 0x1F:
        if (D_001426EB[0] == 0) return 1;
        t = D_00142C24[0];
        if (((t >> 5) & 1) == 1) return 1;
        arg = b->f4;
        goto tailA;
    case 0x20:
        if ((D_00142734[0] & 4) == 0) return 1;
        t = D_00142C20[0];
        if (((t >> 1) & 1) == 1) return 1;
        arg = b->f8;
        goto tailA;
    case 0x21:
        if ((D_00142734[0] & 8) == 0) return 1;
        t = D_00142BC4[0];
        if (((t >> 4) & 1) == 0) {
            p = D_L03_001E8FC0;
            arg = 0x24;
            goto tailB;
        }
        return 1;
    case 0x22:
        if ((D_00142734[0] & 0x10) == 0) return 1;
        t = D_00142BC4[0];
        if (((t >> 6) & 1) == 0) {
            p = D_L03_001E8FC0;
            arg = 0x26;
        tailB:
            if (func_00392B20(p, arg)) func_00392C78(p);
        }
        return 1;
    case 0x23:
        if ((D_00142734[0] & 0x20) == 0) return 1;
        t = D_00142C24[0];
        if (((t >> 4) & 1) == 1) return 1;
        arg = b->fC;
    tailA:
        func_L03_00397C78(a, arg);
        a->c30 = 0xFF;
        return 0;
    default:
        return 1;
    }
}
/* localdecomp:end func_L03_00397CF8 */

/* localdecomp:start func_L03_00397E78 */
typedef struct { char pad[0x68]; char *p68; } S_00397E78;
extern S_00397E78 *D_001DE310_sda;
__asm__(".extern D_001DE310_sda, 4");
void func_L03_00397E78(int a) {
    char *p = D_001DE310_sda->p68;
    if (p != 0) {
        p[0x1C] = a;
    }
}
/* localdecomp:end func_L03_00397E78 */
