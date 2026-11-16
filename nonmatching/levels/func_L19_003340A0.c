/* NTSC-U draft (Claude wave C3): C of func_L19_003336C8, the NTSC-U twin of func_L19_003340A0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L19_003336C8", whose code is not the PAL one).
 * Worker's note: 91 words differ (jump table not checked): 9-state switch on a0[0x95] (table D_L19_002C15D0: cases 1,7 share a body, 8 second, then 2,3,4,5,6, 0/default last) picks w = $gp float * 0.017453292f * 0.016666668f and two ints (D_001DCC28/30/38/40/50/58/60_sda + ...
 */
#include "common.h"

/* localdecomp:start func_L19_003336C8 */
extern s32 D_001DCC28_sda;
__asm__(".extern D_001DCC28_sda, 4");
extern s32 D_001DCC30_sda;
__asm__(".extern D_001DCC30_sda, 4");
extern s32 D_001DCC38_sda;
__asm__(".extern D_001DCC38_sda, 4");
extern s32 D_001DCC40_sda;
__asm__(".extern D_001DCC40_sda, 4");
extern s32 D_001DCC50_sda;
__asm__(".extern D_001DCC50_sda, 4");
extern s32 D_001DCC58_sda;
__asm__(".extern D_001DCC58_sda, 4");
extern s32 D_001DCC60_sda;
__asm__(".extern D_001DCC60_sda, 4");
extern f32 D_001DCC68_sda;
__asm__(".extern D_001DCC68_sda, 4");
extern f32 D_001DCC6C_sda;
__asm__(".extern D_001DCC6C_sda, 4");
extern f32 D_001DCC70_sda;
__asm__(".extern D_001DCC70_sda, 4");
extern f32 D_001DCC74_sda;
__asm__(".extern D_001DCC74_sda, 4");
extern s32 D_001DF758_sda;
__asm__(".extern D_001DF758_sda, 4");
extern s32 D_L19_001DCC2C[];
extern s32 D_L19_001DCC34[];
extern s32 D_L19_001DCC3C[];
extern s32 D_L19_001DCC44[];
extern s32 D_L19_001DCC54[];
extern s32 D_L19_001DCC5C[];
extern s32 D_L19_001DCC64[];
extern s32 D_L19_001DF240[];
extern u8 *D_L19_001DF71C[];
extern u16 *D_L19_0021C260[];
extern u8 D_L19_003339D0[];
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00402498(void *, void *);

void func_L19_003336C8(u8 *a0) {
    u8 *p;
    s32 v[2];
    f32 w;
    u16 *l;
    u8 *ent;

    if (a0[0x31] == 0) {
        return;
    }
    p = *(u8 **)(a0 + 0x68);
    switch (a0[0x95]) {
    case 1:
    case 7:
        w = D_001DCC70_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC30_sda;
        v[1] = D_L19_001DCC34[0];
        break;
    case 8:
        w = D_001DCC74_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC38_sda;
        v[1] = D_L19_001DCC3C[0];
        break;
    case 2:
        w = D_001DCC6C_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC38_sda;
        v[1] = D_L19_001DCC3C[0];
        break;
    case 3:
        w = D_001DCC6C_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC50_sda;
        v[1] = D_L19_001DCC54[0];
        break;
    case 4:
        w = D_001DCC6C_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC60_sda;
        v[1] = D_L19_001DCC64[0];
        break;
    case 5:
        w = D_001DCC6C_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC58_sda;
        v[1] = D_L19_001DCC5C[0];
        break;
    case 6:
        w = D_001DCC6C_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC40_sda;
        v[1] = D_L19_001DCC44[0];
        break;
    case 0:
    default:
        w = D_001DCC68_sda * 0.017453292f * 0.016666668f;
        v[0] = D_001DCC28_sda;
        v[1] = D_L19_001DCC2C[0];
        break;
    }
    *(f32 *)(p + 0x35C) = func_00389380(*(f32 *)(p + 0x35C), w);
    *(s32 *)(a0 + 0x78) = func_003894A0(v[0], v[1], func_00388978(*(f32 *)(p + 0x35C)) * 0.5f + 0.5f);
    if (*(s32 *)(p + 0x368) == D_L19_001DF240[0]) {
        return;
    }
    l = D_L19_0021C260[a0[0x21]];
    while (a0[0x21] != 0xFF && D_001DF758_sda >= a0[0x21] && l != 0 && (((s16 *)l)[-1] >= 0 || l == D_L19_0021C260[a0[0x21]])) {
        ent = D_L19_001DF71C[0] + ((*l & 0x7FFF) << 8);
        l++;
        if (ent == 0) {
            break;
        }
        *(s32 *)(*(u8 **)(ent + 0x68) + 0x368) = D_L19_001DF240[0];
    }
    func_L01_00402498(D_L19_003339D0, a0);
}
/* localdecomp:end func_L19_003336C8 */
