/* near miss (level 3, Starship Phoenix): 139 differences with --as ps2as (L03_00411220.c is this function alone, so it can take @ps2as when it matches; about 150 with the default assembler). The case 0 compare chain is now retail's instruction for instruction (registers aside): its six thresholds are fields of the 0x18-byte entries at 0x1D6B90, read as one array D_L03_001D6B90[] in small data (symbol+offset loads never go into delay slots, so every block starts with its own lui, as in retail), and the last test is a flat else-if pair (retail's movn). What is left: register allocation of a/b/c/d/e and t (retail a=$t3, b=$t2, c=$t1, d=$t0, e=$t7, t=$a3, the C one register off), and case 2's four-entry inner loop, where retail branches with bnel/beql around flag = 1 and the C if-converts it to movz (nested ifs, &&, for/while, u8/s8 flag all give movz); the inner arrays are reached from $gp through section(".sdata"). The $gp names keep the draft's _sda spelling; a match needs them renamed to D_L03_ (level data). */
#include "common.h"

/* localdecomp:start func_L03_00411220 */
extern int D_001D545C;
__asm__(".extern D_001D545C, 16");
extern int D_L03_001E6800[];
__asm__(".extern D_L03_001E6800, 16");
extern int D_L03_002E5CA0[];
__asm__(".extern D_L03_002E5CA0, 16");
extern int D_L03_002E5CF0[], D_L03_002E5D50[], D_L03_002E5DC0[], D_L03_002E5E30[], D_L03_002E5E90[], D_L03_002E5EF0[], D_L03_002E5F50[];
extern s32 D_L03_001D6B90[] __attribute__((section(".sdata")));
extern float D_001D6B64_sda; __asm__(".extern D_001D6B64_sda, 4");
extern char D_001D6AD0_sda; __asm__(".extern D_001D6AD0_sda, 4");
extern unsigned char D_001D6AC5_sda; __asm__(".extern D_001D6AC5_sda, 1");
extern int D_001D6B90_sda; __asm__(".extern D_001D6B90_sda, 4");
extern int D_001D6BA8_sda; __asm__(".extern D_001D6BA8_sda, 4");
extern int D_001D6BC0_sda; __asm__(".extern D_001D6BC0_sda, 4");
extern int D_001D6BD8_sda; __asm__(".extern D_001D6BD8_sda, 4");
extern int D_001D6BF0_sda; __asm__(".extern D_001D6BF0_sda, 4");
extern int D_001D6C20_sda; __asm__(".extern D_001D6C20_sda, 4");
extern int D_001D6C08_sda; __asm__(".extern D_001D6C08_sda, 4");
extern int D_001D6C38_sda; __asm__(".extern D_001D6C38_sda, 4");
extern int D_001D6C50_sda; __asm__(".extern D_001D6C50_sda, 4");
extern int D_001D6C78_sda[4] __attribute__((section(".sdata"))); __asm__(".extern D_001D6C78_sda, 4");
extern int D_001D6C68_sda[4] __attribute__((section(".sdata"))); __asm__(".extern D_001D6C68_sda, 4");
extern void func_L01_00423068();
extern void func_L03_004109D8();

void func_L03_00411220(void) {
    int *a, *d;
    void *b, *c;
    int e, t, i, flag, v;
    e = 0; d = 0; c = 0; b = 0; a = 0;
    D_L03_002E5CA0[12] = 1;
    D_001D6B64_sda = 1.0f;
    *(char **)&D_L03_002E5CA0[8] = &D_001D6AD0_sda;
    D_001D6AC5_sda = 0;
    if (D_001D545C == 3) {
        switch (D_L03_001E6800[12]) {
        case 0:
            t = D_L03_001E6800[13];
            a = D_L03_002E5CF0;
            if (t < (D_L03_001D6B90[1] * 5 + 2) / 6) { b = &D_001D6B90_sda; }
            else if (t < (D_L03_001D6B90[7] * 5 + 2) / 6) { b = &D_001D6BA8_sda; }
            else if (t < (D_L03_001D6B90[13] * 5 + 2) / 6) { b = &D_001D6BC0_sda; }
            else if (t < (D_L03_001D6B90[19] * 5 + 2) / 6) { b = &D_001D6BD8_sda; }
            else if (t < (D_L03_001D6B90[25] * 5 + 2) / 6) { b = &D_001D6BF0_sda; }
            else if (t < (D_L03_001D6B90[31] * 5 + 2) / 6) { b = &D_001D6C08_sda; }
            else { b = &D_001D6C20_sda; }
            break;
        case 2:
            t = D_L03_001E6800[13];
            if (t < (D_001D6C38_sda * 5 + 2) / 6) {
                D_L03_002E5CA0[12] = 0;
                e = 1;
                c = 0;
                if (D_001D6AC5_sda == 0) {
                    flag = 0;
                    i = 0;
                    while (flag == 0 && i < 4) {
                        if (!(t < (D_001D6C68_sda[i] * 5 + 2) / 6) && !((D_001D6C78_sda[i] * 5 + 2) / 6 < t)) flag = 1;
                        i++;
                    }
                    D_001D6AC5_sda = flag;
                }
                c = &D_001D6C50_sda;
            } else {
                b = &D_001D6C38_sda;
            }
            v = D_L03_002E5D50[21];
            if ((v * 5 + 2) / 6 < D_L03_001E6800[13]) d = D_L03_002E5DC0;
            else d = D_L03_002E5D50;
            break;
        case 12:
            v = D_L03_002E5E30[14];
            if (!(D_L03_001E6800[13] < (v * 5 + 2) / 6)) a = D_L03_002E5E30;
            break;
        case 13:
            a = D_L03_002E5E90;
            if (!(D_L03_001E6800[13] < (D_L03_002E5E90[15] * 5 + 2) / 6)) a = D_L03_002E5EF0;
            break;
        case 17:
            a = D_L03_002E5F50;
            break;
        }
    }
    if (a != 0) func_L01_00423068(a, b, c, e, 0, 1, 0);
    else if (d != 0) func_L03_004109D8(d, b, c, e);
}
/* localdecomp:end func_L03_00411220 */
