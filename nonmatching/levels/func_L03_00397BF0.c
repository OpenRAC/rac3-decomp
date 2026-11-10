/* near miss (level 3, Starship Phoenix): 2 differences: retail loads the u16 at D_00143954 into $v1 (lhu $v1), the C into $v0, and the following bnez uses that register; everything else matches (single return tail via goto, .extern hint 16); unsigned int, unsized array, local copy and > 0 give the same 2 diffs */
#include "common.h"

/* localdecomp:start func_L03_00397BF0 */
typedef struct { int f0; char pad[0x20]; int f24; } S_00397BF0;
typedef struct { char pad[0x14]; int f14; } T_00397BF0;
typedef struct { char pad[0x68]; T_00397BF0 *p; } A_00397BF0;
typedef struct { char pad[0x80]; char pad2[0x2564]; unsigned char f25E4; char pad3[0x2A6]; short f288C; } G_00397BF0;
extern S_00397BF0 D_L03_002E52F0;
extern G_00397BF0 D_001A4BE0;
extern unsigned short D_00143954;
__asm__(".extern D_00143954, 16");
extern int func_00382380(void *, int, int);

int func_L03_00397BF0(A_00397BF0 *a) {
    int r = 0;
    T_00397BF0 *p = a->p;
    if (D_L03_002E52F0.f0 != 0 || D_L03_002E52F0.f24 != -1) {
        if (D_00143954 != 0) goto E;
    }
    if (D_001A4BE0.f25E4 != 0) goto E;
    if (D_001A4BE0.f288C == 0)
        r = func_00382380((char *)&D_001A4BE0 + 0x80, p->f14, 0) != 0;
E:
    return r;
}
/* localdecomp:end func_L03_00397BF0 */
