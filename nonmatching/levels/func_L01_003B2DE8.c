/* NTSC-U draft (Codex wave 3): C of func_L01_003B1618, the NTSC-U twin of func_L01_003B2DE8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 90 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003B1618", whose code is not the PAL one).
 * Worker's note: 90 diff; best func_L01_003B1618.check01.log; permitted no-split flags produce gp accesses while retail has lui/lw; inherited array/struct alternatives did not solve; verified once per climbed-flags rule; no unlisted flags tried
 */
#include "common.h"
/* localdecomp:start func_L01_003B1618 */
extern int D_001D545C;
extern unsigned char D_00142738,D_001439F4;
extern unsigned int D_001D4C38,D_001A7DD0,D_001A8414,D_001A842C;
extern int D_001C5290[][16];
extern int func_L01_0050FF18(void),func_L01_00326EE8(void);
extern void func_L01_00417F60(int,int);
void func_L01_003B1618(void *unused,int *event) {
    if (D_001D545C==4) {
        if (*event==100 && !D_00142738 && !D_001439F4 && D_001D4C38-D_001A7DD0>216000u && !func_L01_0050FF18() && !(D_001A8414 & (1 << D_001D545C))) {
            func_L01_00417F60(0xcd6,0x7f);
        }
    } else if (D_001D545C==12) {
        int n=func_L01_00326EE8();
        if (D_001C5290[D_001D545C][n]==3 && !D_001439F4 && D_001D4C38-D_001A7DD0>72000u && !func_L01_0050FF18() && !(D_001A842C & (1 << D_001D545C))) {
            func_L01_00417F60(0xcd8,0x81);
        }
    }
}
/* localdecomp:end func_L01_003B1618 */
