#include "common.h"

/* localdecomp:start func_L01_00494DC8 */
extern u8 D_001426E0[];
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_00143A07[];
extern void *func_L01_0043B548(s32, s32);
extern void func_L01_0047EC88(void);
extern void func_L01_0048A080(u8 *);
extern s32 func_L01_0048A028(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00494DC8(u8 *);
extern void func_L01_0047DAD0(s32);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_00498610(s32);
extern s32 func_L01_00498698(s32);
extern void func_L01_004990A8(s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L01_00494DC8(u8 *a0) {
    u8 *o = func_L01_0043B548(0x19E1, 0x6C);
    s32 t;
    func_L01_0047EC88();
    if (D_001426E0[0x71] == 0xFF && D_001426E0[0x72] == 0xFF) {
        D_001426E0[0x71] = 0;
        D_001426E0[0x72] = 0;
        func_L01_0048A080(a0);
        func_L01_00517748(func_L01_0048A028());
        func_L01_00516090_00494DC8(a0);
    }
    if ((*(s32 *)(D_001D52FC + 0x1C4) & 0x10) && (D_001D545C == 0xC || D_001D545C == 0x12)) {
        func_L01_0048A080(a0);
        func_L01_00517748(func_L01_0048A028());
        func_L01_00516090_00494DC8(a0);
        return;
    }
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x80) {
        func_L01_0047DAD0(2);
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_00494DC8(a0);
        return;
    }
    t = func_L01_00498698(func_L01_00498610(0));
    func_L01_004990A8(func_L01_00498610(0), *(s32 *)(D_001D52FC + 0x1C4));
    if (func_L01_00498698(func_L01_00498610(0)) != t) {
        (*(void (**)(void))(o + 0x64))();
    }
    if (D_00143A07[0] >= 2) {
        func_L01_00517538(0x1A0010, 0.65f, 0.9f);
    }
    if ((*(s32 (**)(void))(o + 0x54))() != 0) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_00494DC8(a0);
    }
}
/* localdecomp:end func_L01_00494DC8 */
