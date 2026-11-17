#include "common.h"

typedef struct O_00431948 O_00431948;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(O_00431948 *, s32);
} VT_00431948;
struct O_00431948 {
    u8 pad0[0x14];
    VT_00431948 *vt;
};

extern u8 *D_001D5F30_sda;
extern u8 *D_L40_0024845C;
extern f32 D_L40_00247A04;
extern f32 D_L40_00247A08;
extern s32 D_L40_00247A10;
extern f32 D_L40_00247A14;
extern s32 D_L40_00247A18;
extern s32 D_L40_00247A1C;
extern u8 D_001FE020[];
extern void func_L01_0044ABD0(u8 *m, u8 *a1);
extern void func_003C2880(u8 *m);
extern s32 func_L40_003F6078(u8 *m);
extern u8 *func_L39_0066C828(u8 *m, s32 a1, s32 a2);
extern void func_L39_0061C1E0(u8 *m, s32 a1);
extern O_00431948 *func_L39_0061D7B0(u8 *m);
extern void func_L01_004450F0(u8 *m, s32 a1, s32 a2);
extern s32 func_L39_005F33E0(s32 a0, s32 a1, u8 *m);
extern void func_L40_00431EA0(u8 *m);
extern s32 func_L01_004561B8(u8 *m);
extern void func_L40_00431C00(u8 *m);
extern void func_L39_005F2FF8(u8 *m, s32 a1);
extern s32 func_L39_005B4398(s32 n);
extern void func_L40_004311A8(u8 *m, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15);

/* localdecomp:start func_L40_00431F78 */
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L40_00432178(void);
extern void func_L01_00404808(void *, void *);
extern void func_L40_00432170(u8 *m);
extern s32 func_L01_003303B8(u8 *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32);
__asm__(".extern D_L40_00247A2C, 4");
__asm__(".extern D_L40_00247A30, 4");
__asm__(".extern D_L40_00247A34, 4");
__asm__(".extern D_L40_00247A38, 4");
__asm__(".extern D_L40_00247A3C, 4");
__asm__(".extern D_L40_00247A40, 4");
__asm__(".extern D_L40_00247A44, 2");
__asm__(".extern D_L40_00247A4C, 2");
__asm__(".extern D_L40_00247A50, 2");
__asm__(".extern D_L40_00247A54, 2");
extern f32 D_L40_00247A2C;
extern f32 D_L40_00247A30;
extern s32 D_L40_00247A34;
extern s32 D_L40_00247A38;
extern s32 D_L40_00247A3C;
extern s32 D_L40_00247A40;
extern s16 D_L40_00247A44;
extern s16 D_L40_00247A4C;
extern s16 D_L40_00247A50;
extern s16 D_L40_00247A54;

void func_L40_00431F78(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    u8 k = m[0x20];

    switch (k) {
    case 0:
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        func_L01_00404808(func_L40_00432178, m);
        func_003C4138((f32 *)(v + 0x4C), 1.0f, *(f32 *)(v + 0x5C));
        if (*(f32 *)(v + 0x4C) >= 1.0f) {
            func_L01_004450F0(m, 2, -1);
            func_L01_003303B8(v + 0x20, D_L40_00247A30, 0, D_L40_00247A34, D_L40_00247A38, D_L40_00247A3C, D_L40_00247A40,
                              D_L40_00247A44, 2, 0.0f, 0.0f, 2.0f,
                              0, D_L40_00247A4C, D_L40_00247A50, D_L40_00247A54, k, 0, 0,
                              *(s32 *)(v + 0x44), 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        break;
    case 2:
        if (*(f32 *)(v + 0x58) < 1.0f) {
            func_L40_00432170(m);
            func_003C4138((f32 *)(v + 0x58), 1.0f, D_L40_00247A2C * 0.0200000014f);
        } else {
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L40_00431F78 */
