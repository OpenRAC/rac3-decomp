#include "common.h"

/* NTSC-U counterpart of func_L22_00429B20 (src/levels/22_mylon/L22_00429B20.c) */
#include "vu0.h"

/* localdecomp:start func_L22_00426C00 */
typedef struct { u8 p0[0x30]; unsigned long f30; u8 p38[0xC]; s16 count; u8 p46[0x15A]; u8 *mobys[3]; } S_429B20;
extern S_429B20 D_L22_001E6E40_00426C00;
extern u8 *D_L22_00239AB0_00426C00[];
__asm__(".extern D_L22_001D6A90_00426C00, 4");
extern f32 D_L22_001D6A90_00426C00;
extern f32 D_L22_001D6A94_00426C00;
extern f32 D_L22_001D6A98_00426C00;
extern s32 D_001D545C;
extern void func_L01_00420D88(void);
extern void func_003A04A0(u8 *, s32);
extern void func_003A26D0(void);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00421438(void);
extern void func_L01_00402498(void *, void *);
extern void func_L08_00403E80(s32, vu0_v4 *, s32, s32, s32, s32, u32, u32, u32, f32, f32);

void func_L22_00426C00(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;
    vu0_v4 v;

    func_L01_00420D88();
    for (i = 0; i < D_L22_001E6E40_00426C00.count; i++) {
        m = D_L22_001E6E40_00426C00.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L22_00239AB0_00426C00[j] != 0; j++) {
                if (D_L22_00239AB0_00426C00[j][0x63] != 0) D_L22_00239AB0_00426C00[j][0x63] = 1;
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_003A26D0, m);
        }
        if (m == 0) continue;
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_0044EB38(m, (f32 *)(*(u8 **)(m + 0x68) + 0xC), 0x80AAAAD2, 0x80396464, 0.061086528f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(m, &D_L22_001D6A90_00426C00, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(m, &D_L22_001D6A94_00426C00, 0x8080AAAA, 0x80464646, 0.03781547f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(m, &D_L22_001D6A98_00426C00, 0x80AAAAFF, 0x80646496, 0.11053753f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, m);
        }
    }
    if (D_001D545C == 0x16 && D_L22_001E6E40_00426C00.f30 == 0x3200000000UL) {
        vu0_v4 *p = &v; /* retail keeps &v in a saved register */
        qzero(&v);
        v.z += 2.0f;
        func_L08_00403E80(2, p, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
        qzero(&v);
        v.z += 1.0f;
        func_L08_00403E80(3, p, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_L22_00426C00 */
