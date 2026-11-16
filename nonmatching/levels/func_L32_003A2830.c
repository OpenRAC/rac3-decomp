/* func_L32_003A2830: 26 diff with the file's flags. Everything matches except: the stored constant 3 (u8 c3 = 3 before the loop splits it from the compare constants, but its register comes out s6 not s3, shifting s3-s6), a move a0,v0 vs lbu reload of v[0x1F9] ahead of the switch, and the move a2 / mov.s f12 order around func_003C3D30. Tried ternary vs if/else, c3 at function top (106 diff), in-loop (122). */
#include "vu0.h"
extern f32 D_L32_001DE7F8;
extern u16 D_L32_001DE7F4;
extern s32 D_L32_001DE7F0;
extern f32 D_L32_001DE7FC;
extern f32 D_L32_001DE800;
extern f32 D_L32_001DE804;
extern f32 D_L32_001DE808;
extern u8 D_L32_001DE80C;
__asm__(".extern D_L32_001DE7F8, 4");
__asm__(".extern D_L32_001DE7F4, 2");
__asm__(".extern D_L32_001DE7F0, 4");
__asm__(".extern D_L32_001DE7FC, 4");
__asm__(".extern D_L32_001DE800, 4");
__asm__(".extern D_L32_001DE804, 4");
__asm__(".extern D_L32_001DE808, 4");
__asm__(".extern D_L32_001DE80C, 1");
extern s32 func_0038CB00(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L32_003B8498(void *, f32, f32, f32, s32, u8, s32, s32, f32, s32, s32);

void func_L32_003A2830(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 i, n;
    u8 c3;
    f32 f20, r;
    vu0_v4 pos;
    if (func_0038CB00(v + 0x1FA)) {
        if (v[0x1F9]) {
            *(f32 *)(v + 0x1E8) = *(f32 *)(v + 0x1E8) + D_L32_001DE7F8;
            *(u16 *)(v + 0x1FA) = D_L32_001DE7F4;
            switch (v[0x1F9]) {
            case 2:
                i = 2;
                n = 3;
                break;
            case 1:
                i = 2;
                n = 4;
                break;
            case 3:
                i = 3;
                n = 4;
                break;
            }
            v[0x1F8] = v[0x1F8] + 1;
            f20 = *(f32 *)(v + 0x1E8) * 0.89999998f;
            c3 = 3;
            for (; i < n; i++) {
                pos = *(vu0_v4 *)(v + 0x1C0);
                if (i == 2) {
                    pos.x = pos.x - f20;
                } else if (i == 3) {
                    pos.x = pos.x + f20;
                }
                r = func_003C3D30(&pos, 0, 0, 0.5f);
                pos.z = r;
                if (fabs_asm(r - *(f32 *)(v + 0x1C8)) > 0.5f) {
                    if (v[0x1F9] >= 2) {
                        v[0x1F9] = 0;
                    }
                    if (v[0x1F9] == 1) {
                        if (i == 2) {
                            v[0x1F9] = c3;
                        } else {
                            v[0x1F9] = 2;
                        }
                    }
                } else {
                    func_L32_003B8498(&pos, D_L32_001DE7FC, D_L32_001DE800, D_L32_001DE804, 0x4C, D_L32_001DE80C, 0, 0x5A, D_L32_001DE808, 0x3C, 0);
                }
            }
        }
    }
    if (v[0x1F9] == 0 || v[0x1F8] >= D_L32_001DE7F0) {
        *(s32 *)(v + 0x78) = 0;
    }
}
