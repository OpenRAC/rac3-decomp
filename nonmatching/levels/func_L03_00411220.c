/* near miss (level 3, Starship Phoenix): 200 differences, mostly a cascade from one divergence in the case 0 compare chain: after each `t < (X*5+2)/6` test the compiler hoists the next block's lui into the delay slot and its lw into the fall-through while retail leaves a nop and starts every block with its own lui; lw (the first test matches); an if/else chain, sequential if/break and a ternary chain (211) tried, with and without hints on the six scalars; retail has a=$t3, b=$t2, c=$t1, d=$t0, e=$t7 and the 0x1E6800 high half in $t4; not tried: the six loads through one struct array with a variable index */
#include "common.h"

/* localdecomp:start func_L03_00411220 */
extern int D_001D545C;
__asm__(".extern D_001D545C, 16");
extern int D_L03_001E6800[];
__asm__(".extern D_L03_001E6800, 16");
extern int D_L03_002E5CA0[];
__asm__(".extern D_L03_002E5CA0, 16");
extern int D_L03_002E5CF0[], D_L03_002E5D50[], D_L03_002E5DC0[], D_L03_002E5E30[], D_L03_002E5E90[], D_L03_002E5EF0[], D_L03_002E5F50[];
extern int D_L03_001D6B94, D_L03_001D6BAC, D_L03_001D6BC4, D_L03_001D6BDC, D_L03_001D6BF4, D_L03_001D6C0C;
__asm__(".extern D_L03_001D6B94, 16");
__asm__(".extern D_L03_001D6BAC, 16");
__asm__(".extern D_L03_001D6BC4, 16");
__asm__(".extern D_L03_001D6BDC, 16");
__asm__(".extern D_L03_001D6BF4, 16");
__asm__(".extern D_L03_001D6C0C, 16");
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
extern int D_001D6C78_sda[4]; __asm__(".extern D_001D6C78_sda, 4");
extern int D_001D6C68_sda[4]; __asm__(".extern D_001D6C68_sda, 4");
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
            if (t < (D_L03_001D6B94 * 5 + 2) / 6) { b = &D_001D6B90_sda; }
            else if (t < (D_L03_001D6BAC * 5 + 2) / 6) { b = &D_001D6BA8_sda; }
            else if (t < (D_L03_001D6BC4 * 5 + 2) / 6) { b = &D_001D6BC0_sda; }
            else if (t < (D_L03_001D6BDC * 5 + 2) / 6) { b = &D_001D6BD8_sda; }
            else if (t < (D_L03_001D6BF4 * 5 + 2) / 6) { b = &D_001D6BF0_sda; }
            else { b = &D_001D6C20_sda; if (t < (D_L03_001D6C0C * 5 + 2) / 6) b = &D_001D6C08_sda; }
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
                    do {
                        if (!(t < (D_001D6C68_sda[i] * 5 + 2) / 6)) {
                            if (!((D_001D6C78_sda[i] * 5 + 2) / 6 < t)) flag = 1;
                        }
                        i++;
                    } while (i < 4 && flag == 0);
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
