/* near miss (level 3, Starship Phoenix): 1 difference: the trailing delay-slot instruction (addiu $sp,$sp,0x20) after jr $ra is cut by the catalogue size (0xC8), so the C is one instruction longer; everything else is byte-identical (the loop over the $gp slot array); same class as func_L01_00350040 */
#include "common.h"

/* localdecomp:start func_L03_0046FF38 */
typedef struct VT_0046FF38 { int pad[3]; void (*fn)(void *); } VT_0046FF38;
typedef struct O_0046FF38 { int pad; VT_0046FF38 *vt; } O_0046FF38;
extern void func_L01_00517918(int);
extern O_0046FF38 *func_003B42F8(int);
extern void func_003A2750(int);
extern void func_003BB468(int);
extern void func_0038E150(int);
extern void func_L01_0041A008(int);
extern int D_001D84C8_sda;
__asm__(".extern D_001D84C8_sda, 4");
extern int D_001D8430_sda;
__asm__(".extern D_001D8430_sda, 4");
extern int D_001D843C_sda;
__asm__(".extern D_001D843C_sda, 4");
extern int D_001D8434_sda;
__asm__(".extern D_001D8434_sda, 4");
extern unsigned char D_L03_001D672C;
__asm__(".extern D_L03_001D672C, 16");

void func_L03_0046FF38(void) {
    int i;
    int j;
    int *p;
    O_0046FF38 *o;
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    for (i = 0; i < 4; i++) {
        o = func_003B42F8(i);
        o->vt->fn(o);
    }
    func_003A2750(1);
    func_003BB468(D_001D8430_sda);
    p = &D_001D84C8_sda;
    for (j = 3; j >= 0; j--) {
        func_003BB468(p[3 - j]);
    }
    if (D_L03_001D672C == 0) {
        func_003BB468(D_001D843C_sda);
        func_003BB468(D_001D8434_sda);
    }
    func_0038E150(0);
    func_L01_0041A008(0);
}
/* localdecomp:end func_L03_0046FF38 */
