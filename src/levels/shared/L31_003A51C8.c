#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A51C8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A51C8;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 D_L31_001E91A0[];

f32 func_L31_003A51C8(V_003A51C8 *pos, s32 a1, void *a2, f32 dz) {
    V_003A51C8 to;
    V_003A51C8 from;

    from = *pos;
    to = from;
    from.z += dz;
    to.z = 0.01f;
    if (func_003D3CB0(&from, &to, a1, a2, 0) != 0) {
        return D_L31_001E91A0[2];
    }
    return 0.0f;
}
/* localdecomp:end func_L31_003A51C8 */

/* localdecomp:start func_L31_003A5238 */
#include "vu0.h"

extern u8 *func_L01_00447490_003A5238(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0_003A5238(void *, void *);
extern void func_003C4A40(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_003A55A0_003A5238(u8 *a0, s32 a1);
extern void func_L31_003473F0_003A5238(void *, f32, f32);
extern u8 *D_001A71A0[];
extern f32 D_L31_001DE984_003A5238;
__asm__(".extern D_L31_001DE984_003A5238, 4");
extern f32 D_L31_001DE990_003A5238;
__asm__(".extern D_L31_001DE990_003A5238, 4");
extern f32 D_L31_001DE9DC_003A5238;
__asm__(".extern D_L31_001DE9DC_003A5238, 4");

void func_L31_003A5238(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit = func_L01_00447490_003A5238(self, 0x10000, 0);
    vu0_v4 push;

    func_0038CAD0(v + 0x174);
    func_L01_0044ABD0_003A5238(self, v + 0x40);
    if (hit != 0) {
        if (*(f32 *)(hit + 0x2C) > 0.0f && self[0x20] != 5 && self[0x20] != 0x42 && *(s32 *)(v + 0x174) == 0) {
            u8 *o = *(u8 **)(hit + 0x20);
            if (o != 0 && *(s16 *)(o + 0xAA) == 0x15C6) {
                *(f32 *)v = 0.0f;
            } else {
                *(f32 *)v -= *(f32 *)(hit + 0x2C);
            }
            *(s32 *)(v + 0x174) = 0xC;
            v[0x47] = 0xFF;
            func_003C4A40(self, v + 0x40);
            func_003A52A0(5, 0, self);
            func_003A52A0(6, 0, self);
            if (*(f32 *)v <= 0.0f) {
                func_0038CF68(&push, hit + 0x10, D_L31_001DE990_003A5238);
                vec_add_ab(v + 0x160, v + 0x160, &push);
                func_L31_003A55A0_003A5238(self, 5);
            } else {
                if (*(u8 **)(hit + 0x20) == D_001A71A0[0]) {
                    func_0038CF68(&push, hit + 0x10, D_L31_001DE984_003A5238);
                    vec_add_ab(v + 0x160, v + 0x160, &push);
                }
                func_L31_003A55A0_003A5238(self, 10);
            }
        }
        self[0xA8] = 0xFF;
    }
    if (self[0x20] != 0x42 && self[0x20] != 5) {
        func_L31_003473F0_003A5238(self + 0x10, D_L31_001DE9DC_003A5238, D_L31_001DE9DC_003A5238);
    }
}
/* localdecomp:end func_L31_003A5238 */
