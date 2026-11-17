#include "common.h"

typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_001CCFD0_003AFF18;

typedef struct { u8 pad[0x13C]; s32 f13C; s32 f140; u8 pad144[0x30C-0x144]; s32 f30C; } P_003AF450;
typedef struct { u8 pad0[0x20]; u8 f20; u8 pad21[0x10]; u8 f31; u8 pad32[2]; u16 f34; u8 pad36[0x43-0x36]; u8 f43; u8 pad44[0x60-0x44]; u8 f60; u8 pad61[7];  P_003AF450 *f68; } S_003AF450;

/* localdecomp:start func_L03_003AF410 */
s32 func_L03_003AF410(void *arg0) {
    s32 temp_a0;

    temp_a0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x13C);
    switch (temp_a0) {                              /* irregular */
    case 4:
        return 4;
    case 6:
        return 3;
    default:
        return -1;
    }
}
/* localdecomp:end func_L03_003AF410 */

/* localdecomp:start func_L03_003AF450 */
extern u8 D_00142700_003AF450[]; extern u8 D_00142CBE_003AF450[];
__asm__(".extern D_00142700_003AF450, 16");
__asm__(".extern D_00142CBE_003AF450, 16");
s32 func_L01_004BA800();
void func_003C3A10();
void func_L01_004450F0();
void func_003C2880();
void func_L03_003AFD48();
s32 func_L01_004561B8();
s32 func_00382498();
s32 func_0038CAD0();
void func_L03_003B0290();
void func_L03_003AF848();
void func_L03_003AF7F0();
s32 func_L03_003AF410();
void func_L03_003AF450(S_003AF450 *a) {
    P_003AF450 *p = a->f68;
    if (func_L01_004BA800(a)) {
        a->f31 = 0;
        a->f34 |= 1;
        return;
    }
    if (D_00142700_003AF450[0] == 0) {
        a->f31 = 1;
        a->f34 &= 0xFFFE;
    }
    switch (a->f20) {
    case 0:
        if (D_00142CBE_003AF450[0] != 0) {
            if (a->f43 != 0) func_003C3A10(a, 0, 0, 8);
            func_L01_004450F0(a, 1, -1);
        } else {
            func_003C2880(a);
            return;
        }
        func_L03_003AFD48(a);
        break;
    case 1:
        if (func_L01_004561B8(a)) {
            p->f140 = 0;
            if (a->f43 != 0) func_003C3A10(a, 0, 0, 8);
            p->f30C = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
        }
        if (func_0038CAD0(&p->f30C)) {
            p->f30C = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
            if (a->f43 != 1) func_003C3A10(a, 1, 0, 0x11);
        }
        if (((u8 *)a)[0x60] & 2) {
            if (a->f43 != 0) func_003C3A10(a, 0, 0, 0x11);
        }
        break;
    case 3:
        if (func_L01_004561B8(a)) {
            p->f140 = 0;
            if (a->f43 != 2) func_003C3A10(a, 2, 0, 8);
        } else if (((u8 *)a)[0x60] & 2) {
            p->f140 = 1;
            func_L01_004450F0(a, p->f13C, -1);
            if (a->f43 != func_L03_003AF410(a)) func_003C3A10(a, func_L03_003AF410(a), 0, 8);
        }
        break;
    case 6:
        if (func_L01_004561B8(a)) {
            if (a->f43 != 3) func_003C3A10(a, 3, 0, 8);
        }
        break;
    case 4:
        if (func_L01_004561B8(a)) {
            if (a->f43 != 4) func_003C3A10(a, 4, 0, 8);
        }
        if (a->f60 & 2) {
            if (a->f43 != 7) func_003C3A10(a, 7, 0, 8);
        }
        break;
    case 5:
        if (func_L01_004561B8(a)) {
            if (a->f43 != 5) func_003C3A10(a, 5, 0, 8);
        }
        if (a->f60 & 2) {
            if (a->f43 != 7) func_003C3A10(a, 7, 0, 8);
        }
        break;
    case 7:
        if (func_L01_004561B8(a)) {
            if (a->f43 != 7) func_003C3A10(a, 7, 0, 8);
        }
        break;
    case 8:
        if (func_L01_004561B8(a)) {
            if (a->f43 != 8) func_003C3A10(a, 8, 0, 8);
            p->f140 = 0;
        } else if (((u8 *)a)[0x60] & 2) {
            if (a->f43 != 0) func_003C3A10(a, 0, 0, 8);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    }
    func_L03_003B0290(a);
    func_L03_003AF848(a);
    func_L03_003AF7F0(a);
}
/* localdecomp:end func_L03_003AF450 */
