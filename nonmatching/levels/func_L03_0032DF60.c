/* near miss (level 3, Starship Phoenix): 11 differences: the shape and every other register match (the for loop over three entries with the func_L03_0032EB30 style walk); retail reads the loop-entry copy of the D_001DF9D8 limit with lui/lw and the back-edge copy through $gp (0x3128), the C uses $gp in both, shifting four instructions around the entry test; splitting the entry guard gives 71-92 diffs */
#include "common.h"

/* localdecomp:start func_L03_0032DF60 */
extern int D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8;
__asm__(".extern D_001DF9D8, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
extern int func_L01_0044C078(void *, int);
void func_L03_0032DF10(void *arg0);

typedef struct S_0032DF60 {
    char pad0[0xA8];
    int idx[3];
    char padB4[0x10];
    int arg;
} S_0032DF60;

void func_L03_0032DF60(void *a) {
    int i;
    S_0032DF60 *p = *(S_0032DF60 **)((char *)a + 0x68);
    for (i = 0; i < 3; i++) {
        short *cur = (short *)D_L03_0021C620[p->idx[i]];
        while ((p->idx[i] & 0xFF) != 0xFF && D_001DF9D8_sda >= p->idx[i] && cur != 0 &&
               (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[p->idx[i]])) {
            char *buf = D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8);
            if (buf == 0) break;
            cur += 1;
            if (*(u8 *)(buf + 0x20) != 1) {
                if (func_L01_0044C078(buf + 0x10, p->arg) == 0)
                    func_L03_0032DF10(buf);
            }
        }
    }
}
/* localdecomp:end func_L03_0032DF60 */
