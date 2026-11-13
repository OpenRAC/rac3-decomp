#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005E31D8);

INCLUDE_ASM("asm/levels", func_L39_005E3618);

/* localdecomp:start func_L39_005E3A10 */
extern u8 D_L39_002B5E70[];
extern s32 func_11D534(s32, s32, s32);
void func_L39_005E3A10(s32 i) {
    func_11D534((s32)D_L39_002B5E70 + (i << 9), 0, 0x200);
}
/* localdecomp:end func_L39_005E3A10 */

/* localdecomp:start func_L39_005E3A40 */
extern u8 D_L39_002B5E70[];
void *func_L39_005E3A40(s32 i) {
    return D_L39_002B5E70 + (i << 9);
}
/* localdecomp:end func_L39_005E3A40 */

/* localdecomp:start func_L39_005E3A58 */
extern s32 func_L01_00517688(void);
extern void func_L39_005D6A78(s32, s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern s32 func_L01_004910C0(s32);
extern void func_L01_00353C80(s32);
void func_L39_005E3A58(void) {
    s32 p = func_L01_00517688();
    func_L39_005D6A78(p, 10);
    func_L39_0061C0E0(p, 0);
    func_L39_005D6468(p, 0);
    func_L01_00353C80(func_L01_004910C0(p));
}
/* localdecomp:end func_L39_005E3A58 */

/* localdecomp:start func_L39_005E3AB8 */
extern s32 func_L01_00517688(void);
extern s32 func_L01_0049F168(s32 a0);
extern void func_L01_00517748(s32 a0);
extern s32 func_L01_004910C0(s32 a0);
extern void func_L01_00353C80(s32 a0);
void func_L39_005E3AB8(void) {
    func_L01_00517748(func_L01_0049F168(func_L01_00517688()));
    func_L01_00353C80(func_L01_004910C0(func_L01_00517688()));
}
/* localdecomp:end func_L39_005E3AB8 */

/* localdecomp:start func_L39_005E3B00 */
extern s32 func_L01_00517688(void);
typedef struct { u8 pad[0x4500]; } D_002FB100_t;
extern D_002FB100_t *func_L39_0061BF38(s32 i);
extern void func_L01_003F2278(s32, void *);
extern void func_L39_005C3EA0(void *);
extern void func_L01_003F1F60(void *);
extern void func_L39_005D6A78(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern s32 func_L01_004910C0(s32);
extern void func_L01_00353C80(s32);
extern void func_L39_0059A578(s32, s32);
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 D_L39_00241440;
__asm__(".extern D_L39_00241440, 16");
extern s32 D_001D7204_sda;
typedef struct { u8 pad0[0x78]; s32 w78; u8 pad7C[0x174 - 0x7C]; s32 w174; } S_005E3B00;
extern S_005E3B00 D_001A5CD0;
typedef struct { u8 pad[0x2534]; u8 *q; } P_005E3B00;

void func_L39_005E3B00(void) {
    s32 i;
    P_005E3B00 *p;
    for (i = 0; i < *D_L39_00241120; ) {
        p = (P_005E3B00 *)func_L39_0061BF38(i++);
        func_L01_003F2278(0, p->q);
        p->q[0x188] = 0;
        p->q[0x189] = 0;
        func_L39_005C3EA0(p->q);
        func_L01_003F1F60(p->q);
    }
    func_L39_005D6A78(func_L01_00517688(), 10);
    func_L39_005D6468(func_L01_00517688(), 0);
    func_L01_00353C80(func_L01_004910C0(func_L01_00517688()));
    if (D_001A5CD0.w174 != 0) {
        D_L39_00241440 = 5;
    } else if (D_001A5CD0.w78 == -1) {
        D_L39_00241440 = 9;
    } else {
        D_L39_00241440 = 6;
    }
    D_001D7204_sda = 0;
    func_L39_0059A578(0x27, 1);
}
/* localdecomp:end func_L39_005E3B00 */
