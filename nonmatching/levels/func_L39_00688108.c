/* NTSC-U draft (Claude wave K): C of func_L39_006855C8, the NTSC-U twin of func_L39_00688108, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 87 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L39_006855C8", whose code is not the PAL one).
 * Worker's note: 87 diff (instruction count/frame 0x80 and all opcodes right): fully decoded 0x38-byte struct copy into a 0x40 local (state word +0x30), D_001DC1E4_sda/D_001E1FD0_sda gp aliases + D_L39_0024D860 lui form, do-while polling loop (func_L39_0067C0B0 < 0x7531 and ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00688108 (src/levels/39_multiplayer_menu/L39_006873F0.c) */
/* localdecomp:start func_L39_006855C8 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct { s32 w[14]; } S38_006855C8;
typedef struct { s32 w[12]; s32 state; s32 pad[3]; } S40_006855C8;
extern u8 *D_L39_0024D860;
extern u8 *D_001DC1E4_sda;
extern u8 *D_001E1FD0_sda;
extern void func_L39_006D1928(s32);
extern void func_L01_003A2FD8(s32);
extern s32 func_L39_006D9F70(s32, s32);
extern void func_L39_006D62D8(void *);
extern void func_001986B8(void);
extern void func_001375B0(void *, void *, s32);
extern void func_L39_0067C078(void);
extern void func_00195500(void);
extern void func_L39_00686F20(void *, void *);
extern s32 func_L39_0067C0B0(void);
extern void func_00199190(void);
extern void func_001986A0(void);

void func_L39_006855C8(u8 *a0, S38_006855C8 *a1, void *a2) {
    S40_006855C8 loc;
    S40_006855C8 *lp = &loc;
    u8 *s1;
    u8 *s4;
    u8 old;
    u8 *p;

    *(S38_006855C8 *)lp = *a1;
    p = D_001DC1E4_sda;
    old = p[0x280];
    s4 = D_L39_0024D860;
    p[0x280] = 1;
    s1 = *(u8 **)(p + 0x64);
    func_L39_006D1928(*(s32 *)(D_L39_0024D860 + 0x3C));
    if (s1[0x2B9] != 0) {
        func_L01_003A2FD8(*(s32 *)(s4 + 0x30));
    }
    if (s1[0x2B8] != 0) {
        func_L39_006D9F70(*(s32 *)(s4 + 0x50), 0);
    }
    func_L39_006D62D8(D_001E1FD0_sda);
    func_001986B8();
    func_001375B0(lp, a2, 0x40);
    if (lp->state != 5) {
        func_L39_0067C078();
    }
    s1 = a0 + 0x110;
    do {
        func_00195500();
        func_001375B0(lp, a2, 0x40);
        func_L39_00686F20(*(void **)(s1 + *(s32 *)(a0 + 0x270) * 4), a2);
        if (func_L39_0067C0B0() >= 0x7531) {
            break;
        }
    } while (lp->state != 5);
    *(s32 *)(D_001DC1E4_sda + 0x284) = 0x18;
    func_00199190();
    *(s32 *)(a0 + 0x27C) = 0;
    func_001986A0();
    D_001DC1E4_sda[0x280] = old;
}
/* localdecomp:end func_L39_006855C8 */
