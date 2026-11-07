#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00397698);

INCLUDE_ASM("asm/levels", func_L03_003979F0);

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
