/* near miss (level 3, Starship Phoenix): 1 difference: retail has `dsrl $v0,$v0,1` after the `lw` of D_00142C40 (a 64-bit shift of a sign-extended word) before the andi, the C gives `sra` or `srl`; signed/unsigned long casts, a long array (ld), a bitfield struct and 1UL operands tried; store order inside the tail blocks is f31, f34, f98 (blocks 1 and 3) and f98, f34, f31 (block 2) */
#include "common.h"

/* localdecomp:start func_L03_003AFD48 */
typedef struct { u8 pad[0x31]; u8 f31; u8 pad32[2]; u16 f34; u8 pad36[0x98 - 0x36]; int f98; } S_003AFD48;
extern u8 D_001426E0[];
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");
extern unsigned int D_00142C40[];
extern u8 D_00142CC2[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
void func_L03_003B0ED8(int, int);
void func_L03_003AFD48(void *arg0) {
    S_003AFD48 *p = (S_003AFD48 *)arg0;
    u8 *t = D_001426E0;
    u8 *q = *(u8 **)((u8 *)arg0 + 0x68);
    S_003AFD48 *e;
    D_001DE858_sda = 0x3F;
    if (t[0x20] != 0) {
        func_L03_003B0ED8(0, 0);
        p->f31 = 0;
        p->f34 |= 1;
        p->f98 = 0;
    }
    if (t[0x3D] != 0 && t[0x85] == 0) {
        func_L03_003B0ED8(4, 0);
    }
    if (((unsigned long)(long)(int)D_00142C40[0] >> 1) & 1) {
        e = (S_003AFD48 *)(D_L03_001DF99C + *(int *)(q + 0x16C) * 256);
        func_L03_003B0ED8(3, 0);
        e->f98 = 0;
        e->f34 |= 3;
        e->f31 = 0;
    }
    if (D_00142CC2[0] != 0) {
        e = (S_003AFD48 *)(D_L03_001DF99C + *(int *)(q + 0x168) * 256);
        func_L03_003B0ED8(2, 0);
        e->f31 = 0;
        e->f34 |= 1;
        e->f98 = 0;
    }
}
/* localdecomp:end func_L03_003AFD48 */
