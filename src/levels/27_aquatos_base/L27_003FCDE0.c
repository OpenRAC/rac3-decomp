#include "common.h"

/* localdecomp:start func_L27_003FCDE0 */
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; u8 p38[0xC]; s16 count; u8 p46[0x15A]; u8 *mobys[2]; u8 *f1A8; } S_3FCDE0;
extern S_3FCDE0 D_L27_001E59C0;
extern u8 *D_L27_00238030[];
__asm__(".extern D_L27_001D6AE0, 4");
extern f32 D_L27_001D6AE0;
extern f32 D_L27_001D6AE4;
extern f32 D_L27_001D6AE8;
extern s32 D_001D545C;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(u8 *, s32);
extern void func_003A7AF8(void);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00424168(void);
extern void func_L01_00404808(void *, void *);
extern void func_L07_004249A0(s32, s32, s32);
extern void func_L27_003FCBA0(void *arg0, s32 arg1);

void func_L27_003FCDE0(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;

    func_L01_00423AB8();
    for (i = 0; i < D_L27_001E59C0.count; i++) {
        m = D_L27_001E59C0.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L27_00238030[j] != 0; j++) {
                if (D_L27_00238030[j][0x63] != 0) D_L27_00238030[j][0x63] = 1;
            }
            func_003A58C0(m, 0);
            func_L01_00404A10(func_003A7AF8, m);
        }
        if (m == 0) continue;
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_00451DB8(m, (f32 *)(*(u8 **)(m + 0x68) + 0xC), 0x80AAAAD2, 0x80396464, 0.07330383f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_00451DB8(m, &D_L27_001D6AE0, 0x80505080, 0x80404038, 0.038397245f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(m, &D_L27_001D6AE4, 0x8080AAAA, 0x80464646, 0.045378566f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(m, &D_L27_001D6AE8, 0x80AAAAFF, 0x80646496, 0.13264504f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, m);
        }
    }
    if (D_001D545C == 0x1B) {
        if (D_L27_001E59C0.f30 == 0) {
            func_L07_004249A0(0x2B2, 0, 2);
        } else if (D_L27_001E59C0.f30 == 2 && D_L27_001E59C0.f34 >= 0x68) {
            u8 *n = D_L27_001E59C0.f1A8;
            if (n != 0) {
                func_L27_003FCBA0(n, 0);
                func_L27_003FCBA0(n, 1);
            }
        }
    }
}
/* localdecomp:end func_L27_003FCDE0 */
