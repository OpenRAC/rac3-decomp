/* near miss (level 3, Starship Phoenix): 6 differences: all ten cases of the jump-table switch are written in retail block order (3, 10, 6, 5, 9 falling into 7, 4, 1, 8, then 2/default); only the register choice in the two D_L03_002D09B0[0] == 1 checks (cases 5 and 9) differs: retail has the lui in $v1, the loaded value in $v0 and the constant 1 in $a0, the C the lui in $v0 and the value in $v1; a scalar, a local, a reordered comparison and an early read of the sda pointer tried; the four shared tails are separate calls with return (gotos flipped $s0/$s1) */
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
extern void func_L03_003979F0(void *);
extern int func_L01_004BA800();
extern int func_L03_00397CF8(void *);
extern int func_L03_00397BF0(void *);
extern void func_L03_00397B38(void *);
extern void func_L01_00456230(void *, int);
extern int func_L01_004561B8(void *);
extern void func_L01_003EB438(int, void *, void *, int, int, int);
extern void func_L01_003EB5E0(int, int);
extern void func_L01_00452560(int, int, int, int, int, int, int);
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
