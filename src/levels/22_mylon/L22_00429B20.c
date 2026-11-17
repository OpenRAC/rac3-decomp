#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_00429B20 */
typedef struct { u8 p0[0x30]; unsigned long f30; u8 p38[0xC]; s16 count; u8 p46[0x15A]; u8 *mobys[3]; } S_429B20;
extern S_429B20 D_L22_001E6E40;
extern u8 *D_L22_00239AB0[];
__asm__(".extern D_L22_001D6A90, 4");
extern f32 D_L22_001D6A90;
extern f32 D_L22_001D6A94;
extern f32 D_L22_001D6A98;
extern s32 D_001D545C;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(u8 *, s32);
extern void func_003A7AF8(void);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00424168(void);
extern void func_L01_00404808(void *, void *);
extern void func_L08_004070C0(s32, vu0_v4 *, s32, s32, s32, s32, u32, u32, u32, f32, f32);

void func_L22_00429B20(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;
    vu0_v4 v;

    func_L01_00423AB8();
    for (i = 0; i < D_L22_001E6E40.count; i++) {
        m = D_L22_001E6E40.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L22_00239AB0[j] != 0; j++) {
                if (D_L22_00239AB0[j][0x63] != 0) D_L22_00239AB0[j][0x63] = 1;
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
            func_L01_00451DB8(m, &D_L22_001D6A90, 0x80505080, 0x80404038, 0.038397245f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(m, &D_L22_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(m, &D_L22_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, m);
        }
    }
    if (D_001D545C == 0x16 && D_L22_001E6E40.f30 == 0x2900000000UL) {
        vu0_v4 *p = &v; /* retail keeps &v in a saved register */
        qzero(&v);
        v.z += 2.0f;
        func_L08_004070C0(2, p, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
        qzero(&v);
        v.z += 1.0f;
        func_L08_004070C0(3, p, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_L22_00429B20 */
