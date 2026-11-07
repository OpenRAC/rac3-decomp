#include "common.h"

/* localdecomp:start func_L02_003BBA80 */
void func_L01_004AA7E8(s32, s32);
void func_L02_003BBA80(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L02_003BBA80 */

/* localdecomp:start func_L02_003BBAC0 */
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18; } T_3BBAC0;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0xF]; u8 f30; u8 pad31[0x37]; T_3BBAC0 *p; } S_3BBAC0;
extern u8 D_001A4C60[];
s32 func_00382380(void *, s32, s32);
void func_L01_0045F1E8(s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L02_003BBAC0(S_3BBAC0 *a) {
    T_3BBAC0 *p = a->p;
    switch (a->state) {
    case 0:
        a->f30 = 0xFF;
        func_L01_004450F0(a, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, p->f4, 0)) {
            func_L01_0045F1E8(p->f14, -1);
            func_L01_004450F0(a, 2, -1);
        } else if (func_00382380(D_001A4C60, p->f8, 0)) {
            func_L01_0045F1E8(p->f18, -1);
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 2:
        if (func_00382380(D_001A4C60, p->f0, 0) || func_00382380(D_001A4C60, p->fC, 0)) {
            func_L01_0045F1E8(p->f10, -1);
            func_L01_004450F0(a, 1, -1);
        } else if (func_00382380(D_001A4C60, p->f8, 0)) {
            func_L01_0045F1E8(p->f18, -1);
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        if (func_00382380(D_001A4C60, p->f0, 0) || func_00382380(D_001A4C60, p->fC, 0)) {
            func_L01_0045F1E8(p->f10, -1);
            func_L01_004450F0(a, 1, -1);
        }
        if (func_00382380(D_001A4C60, p->f4, 0)) {
            func_L01_0045F1E8(p->f14, -1);
            func_L01_004450F0(a, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L02_003BBAC0 */

INCLUDE_ASM("asm/levels", func_L02_003BBC98);
