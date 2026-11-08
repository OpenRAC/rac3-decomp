/* near miss (level 3, Starship Phoenix): 97 differences with the default assembler (needs @ps2as for the 1.2f / 0.017f constants, which L03_003A20E0.c does not have): the prologue, the jump-table dispatch and the register allocation match and every case is written, but retail cross-jumps the four func_L01_004450F0(a,n,-1) calls into one shared tail (case 1 is laid out as `b tail` with li $a1,5 in the delay slot) and the C does not; a goto to a shared tail swaps the saved registers (131-134 diff) */
#include "common.h"

/* localdecomp:start func_L03_003A20E0 */
typedef struct S_003A20E0 { u8 pad0[0x20]; u8 state; u8 pad1[0x47]; f32 *p68; u8 pad2[0x3C]; u8 b_A8; u8 pad3[0x4B]; f32 f_F4; } S_003A20E0;
typedef struct T_003A20E0 { u8 pad[0x20]; struct U_003A20E0 *q; } T_003A20E0;
typedef struct U_003A20E0 { u8 pad[0xAA]; s16 id; } U_003A20E0;
extern f32 D_001DE3E0_sda; /* gp 0x1B30 */
extern f32 D_001DE3DC_sda; /* gp 0x1B2C */
extern u8 D_001A4C60_003A20E0[];
__asm__(".extern D_001DE3E0_sda, 4");
__asm__(".extern D_001DE3DC_sda, 4");
__asm__(".extern D_001A4C60_003A20E0, 16");
void func_L03_003A2328(S_003A20E0 *);
s32 func_L03_003A2360_003A20E0();
T_003A20E0 *func_L01_00447490();
void func_L01_0041A5B0();
void func_L01_004450F0();
f32 func_003C3BE8(f32, f32, f32);
s32 func_00382380();

void func_L03_003A20E0(S_003A20E0 *a) {
    f32 *p;
    f32 v;
    T_003A20E0 *r;
    func_L03_003A2328(a);
    p = a->p68;
    switch (a->state) {
    case 1:
        if (func_L03_003A2360_003A20E0(a)) {
            func_L01_004450F0(a, 5, -1);
        }
        r = func_L01_00447490(a, 0x30000, 0);
        if (r == 0) return;
        a->b_A8 = 0xFF;
        if (r->q != 0) {
            if (r->q->id == 0x47) {
                func_L01_0041A5B0(0xA18, 5);
            }
        }
        return;
    case 2:
        v = p[1] + D_001DE3E0_sda * 1.2f;
        p[1] = v;
        if (v >= 1.0f) {
            p[1] = 1.0f;
            func_L01_004450F0(a, 3, -1);
        }
        a->f_F4 = func_003C3BE8(0.0f, D_001DE3DC_sda * 0.017f, p[1]);
        if (func_00382380(D_001A4C60_003A20E0, *(s32 *)p, 0) == 0) {
            func_L01_004450F0(a, 4, -1);
        }
        return;
    case 3:
        if (func_00382380(D_001A4C60_003A20E0, *(s32 *)p, 0) == 0) {
            func_L01_004450F0(a, 4, -1);
        }
        return;
    case 4:
        v = p[1] - D_001DE3E0_sda * 1.2f;
        p[1] = v;
        if (v <= 0.0f) {
            p[1] = 0.0f;
            func_L01_004450F0(a, 5, -1);
        }
        a->f_F4 = func_003C3BE8(0.0f, D_001DE3DC_sda * 0.017f, p[1]);
        if (func_00382380(D_001A4C60_003A20E0, *(s32 *)p, 0) != 0) {
            func_L01_004450F0(a, 2, -1);
        }
        return;
    case 5:
        if (func_00382380(D_001A4C60_003A20E0, *(s32 *)p, 0) != 0) {
            func_L01_004450F0(a, 2, -1);
        }
        return;
    }
}
/* localdecomp:end func_L03_003A20E0 */
