#include "common.h"

/* NTSC-U counterpart of func_L39_005E3B00 (src/levels/shared/L39_005E31D8.c) */
extern s32 func_L01_00513698(void);
extern void func_L39_005D4508(s32, s32);
extern void func_L39_005D3EF8(s32, s32);
extern s32 func_L01_0048D818(s32);
extern void func_L01_00353138(s32);
extern s32 func_L01_00513698(void);
extern s32 func_L01_0048D818(s32 a0);
extern void func_L01_00353138(s32 a0);

/* localdecomp:start func_L39_005E1590 */
extern s32 func_L01_00513698(void);
typedef struct { u8 pad[0x4500]; } D_002FB100_t;
extern D_002FB100_t *func_L39_006197C0(s32 i);
extern void func_L01_003F0338(s32, void *);
extern void func_L39_005C1C50(void *);
extern void func_L01_003F0020(void *);
extern void func_L39_005D4508(s32, s32);
extern void func_L39_005D3EF8(s32, s32);
extern s32 func_L01_0048D818(s32);
extern void func_L01_00353138(s32);
extern void func_L39_005992A8(s32, s32);
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern s32 D_L39_002415C0;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_001D7204_sda_005E1590;
typedef struct { u8 pad0[0x78]; s32 w78; u8 pad7C[0x174 - 0x7C]; s32 w174; } S_005E3B00;
extern S_005E3B00 D_001A5E50;
typedef struct { u8 pad[0x2534]; u8 *q; } P_005E3B00;

void func_L39_005E1590(void) {
    s32 i;
    P_005E3B00 *p;
    for (i = 0; i < *D_L39_002412A0; ) {
        p = (P_005E3B00 *)func_L39_006197C0(i++);
        func_L01_003F0338(0, p->q);
        p->q[0x188] = 0;
        p->q[0x189] = 0;
        func_L39_005C1C50(p->q);
        func_L01_003F0020(p->q);
    }
    func_L39_005D4508(func_L01_00513698(), 10);
    func_L39_005D3EF8(func_L01_00513698(), 0);
    func_L01_00353138(func_L01_0048D818(func_L01_00513698()));
    if (D_001A5E50.w174 != 0) {
        D_L39_002415C0 = 5;
    } else if (D_001A5E50.w78 == -1) {
        D_L39_002415C0 = 9;
    } else {
        D_L39_002415C0 = 6;
    }
    D_001D7204_sda_005E1590 = 0;
    func_L39_005992A8(0x27, 1);
}
/* localdecomp:end func_L39_005E1590 */
