#include "common.h"

/* NTSC-U counterpart of func_L39_00662748 (src/levels/shared/L39_00662678.c) */
typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
extern N_65FDA0 *D_L39_00246374;
extern void func_L39_00660140(u8 *a0);
extern N_65FDA0 *D_L39_00246374;

/* localdecomp:start func_L39_0065FE70 */
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D85C, 16");
extern s32 D_L39_0024D85C;
extern void func_L39_006600D8(u8 *a0);

void func_L39_0065FE70(void) {
    N_65FDA0 *p = D_L39_00246374;
    N_65FDA0 *prev = 0;
    N_65FDA0 *rem = 0;
    while (p) {
        u8 *g = D_001A5E50;
        if (p->b55 == 0 && p->w4 + (s32)(p->w0 >> 13) <= *(s32 *)(g + 0x128)) {
            N_65FDA0 *n = p->next;
            if (prev == 0) {
                D_L39_00246374 = n;
            } else {
                prev->next = n;
            }
            p->next = rem;
            rem = p;
            p = n;
        } else {
            prev = p;
            p = p->next;
        }
    }
    while (rem) {
        p = rem;
        if (*(s32 *)((u8 *)rem + 0x50) == -1 || *(s32 *)((u8 *)rem + 0x50) == D_L39_0024D85C) {
            func_L39_006600D8((u8 *)rem);
        }
        rem = rem->next;
        func_L39_00660140((u8 *)p);
    }
}
/* localdecomp:end func_L39_0065FE70 */
