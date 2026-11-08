#include "common.h"

/* localdecomp:start func_L39_00589538 */
extern int *D_L39_0024CAD0;
extern int *D_L39_0024B9F4;
extern int D_002402F0;
extern int D_002402F4;
extern int D_001FC450[];
extern int D_L39_0024B9FC;
extern int D_L39_0024BA00;
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024B9F4, 16");
__asm__(".extern D_002402F0, 16");
__asm__(".extern D_002402F4, 16");
__asm__(".extern D_L39_0024BA00, 16");
extern long D_001D6E20_sda;
extern long D_001D6E28_sda;
extern int D_001D6E30_sda;
extern long D_L39_0025DDC0[];
extern char D_L39_0024BCE0[] __attribute__((section(".sdata")));

extern void func_L39_00591B88(void);

void func_L39_00589538(int arg0) {
    int *p = D_L39_0024CAD0;
    int i;
    D_L39_0024B9F4 = p;
    p += 4;
    D_L39_0024CAD0 = p;
    D_002402F0 = D_002402F4;
    D_L39_0024B9FC = 0;
    {
        int k;
        for (k = 0; k < D_L39_0024BA00; k++) {
            D_L39_0025DDC0[k * 2] = 0;
        }
    }
    D_001D6E20_sda = 0;
    D_001D6E28_sda = 0;
    D_001D6E30_sda = 0;
    if (arg0 == 0) {
        for (i = 0; i < *(int *)(*(char **)(D_L39_0024BCE0 + 0x18) + 0x44); i++) {
            unsigned short *el = (unsigned short *)(i * 8 + *(int *)(D_L39_0024BCE0 + 0x24) + 4);
            if (*el >= (D_001FC450[1] >> 8)) {
                *el = 0;
            }
        }
        {
            int j;
            for (j = 0; j < *(int *)(*(char **)(D_L39_0024BCE0 + 0x18) + 0x24); j++) {
                *(short *)(*(char **)(D_L39_0024BCE0 + 0x28) + j * 8 + 4) = 0;
            }
        }
    }
    func_L39_00591B88();
}
/* localdecomp:end func_L39_00589538 */
