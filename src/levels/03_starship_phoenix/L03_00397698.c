#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00397698);

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

INCLUDE_ASM("asm/levels", func_L03_00397BF0);

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

INCLUDE_ASM("asm/levels", func_L03_00397CF8);

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
