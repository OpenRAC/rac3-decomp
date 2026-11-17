#include "common.h"

/* localdecomp:start func_L18_00436E90 */
typedef struct { u8 p0[0x34]; u16 h34; u8 p36[0x2D]; u8 b63; u8 p64[4]; u8 *p68; u8 p6C[0x3E]; s16 hAA; } M_436E90;
typedef struct { u8 p0[0x30]; s32 w30; s32 w34; u8 p38[0xC]; s16 h44; u8 p46[0x15A]; M_436E90 *mobys[1]; } S_436E90;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_436E90;
typedef int q_436E90 __attribute__((mode(TI)));
extern S_436E90 D_L18_001E6E00;
extern M_436E90 *D_L18_0023ACF0[];
extern u8 D_L18_001D6AE0[4];
__asm__(".extern D_L18_001D6AE0, 4");
extern u8 D_L18_001D6AE4[4];
extern u8 D_L18_001D6AE8[4];
extern s32 D_001D545C;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_003A7AF8(void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00424168(void *);
extern void func_L08_004070C0(s32, void *, s32, s32, s32, s32, s32, s32, f32, f32, s32);
void func_L18_00436E90(void) {
    s32 i;
    func_L01_00423AB8();
    for (i = 0; i < D_L18_001E6E00.h44; ) {
        s32 id = 0xD54;
        M_436E90 *m = D_L18_001E6E00.mobys[i];
        s32 n;
        if (m != 0 && m->hAA == 0xE29) m->h34 |= 0x800;
        n = i + 1;
        if (m->hAA == id) {
            m->b63 = 0;
            {
                s32 k;
                for (k = 0; D_L18_0023ACF0[k] != 0; k++) {
                    if (D_L18_0023ACF0[k]->b63 != 0) D_L18_0023ACF0[k]->b63 = 1;
                }
            }
            func_003A58C0(m, 0);
            func_L01_00404A10(func_003A7AF8, m);
        }
        if (m != 0) {
            s32 h = m->hAA;
            if (h == 0xFA0) {
                if (m->p68 != 0) func_L01_00451DB8(m, m->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.07330383f);
            } else if (h == 0x1DEE || h == 0x19BC) {
                func_L01_00451DB8(m, D_L18_001D6AE0, 0x80505080, 0x80404038, 0.038397245f);
            } else if (h == 0x1977) {
                func_L01_00451DB8(m, D_L18_001D6AE4, 0x8080AAAA, 0x80464646, 0.045378566f);
            } else if (h == 0x1766) {
                func_L01_00451DB8(m, D_L18_001D6AE8, 0x80AAAAFF, 0x80646496, 0.13264504f);
            } else if (h == 0x195B || h == 0x1B58 || h == 0x195C || h == 0x175A) {
                func_L01_00404808(func_L01_00424168, m);
            }
        }
        i = n;
    }
    if (D_001D545C == 0x12 && D_L18_001E6E00.w30 == 0 && (D_L18_001E6E00.w34 == 0x63 || D_L18_001E6E00.w34 == 0x8A)) {
        V4_436E90 v;
        *(q_436E90 *)&v = 0;
        v.z = 1.0f;
        func_L08_004070C0(1, &v, 0x19, 0x19, 0x96, 0x64, 0x50204080, 0x50204080, 1.0f, 1.0f, 0x50204080);
    }
}
/* localdecomp:end func_L18_00436E90 */
