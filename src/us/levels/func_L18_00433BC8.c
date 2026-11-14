#include "common.h"

/* NTSC-U counterpart of func_L18_00436E90 (src/levels/18_aridia/L18_00436E90.c): 0.0733038 -> 0.0610865; 0.0383972 -> 0.0319977; 0.0453786 -> 0.0378155; 0.132645 -> 0.110538; 99 -> 120; 138 -> 166 */
/* localdecomp:start func_L18_00433BC8 */
typedef struct { u8 p0[0x34]; u16 h34; u8 p36[0x2D]; u8 b63; u8 p64[4]; u8 *p68; u8 p6C[0x3E]; s16 hAA; } M_436E90;
typedef struct { u8 p0[0x30]; s32 w30; s32 w34; u8 p38[0xC]; s16 h44; u8 p46[0x15A]; M_436E90 *mobys[1]; } S_436E90;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_436E90;
typedef int q_436E90 __attribute__((mode(TI)));
extern S_436E90 D_L18_001E6E80;
extern M_436E90 *D_L18_0023AD70[];
extern u8 D_L18_001D6AE0_00433BC8[4];
__asm__(".extern D_L18_001D6AE0_00433BC8, 4");
extern u8 D_L18_001D6AE4_00433BC8[4];
extern u8 D_L18_001D6AE8_00433BC8[4];
extern s32 D_001D545C;
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_003A26D0(void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_00421438(void *);
extern void func_L08_00403E80(s32, void *, s32, s32, s32, s32, s32, s32, f32, f32, s32);
void func_L18_00433BC8(void) {
    s32 i;
    func_L01_00420D88();
    for (i = 0; i < D_L18_001E6E80.h44; ) {
        s32 id = 0xD54;
        M_436E90 *m = D_L18_001E6E80.mobys[i];
        s32 n;
        if (m != 0 && m->hAA == 0xE29) m->h34 |= 0x800;
        n = i + 1;
        if (m->hAA == id) {
            m->b63 = 0;
            {
                s32 k;
                for (k = 0; D_L18_0023AD70[k] != 0; k++) {
                    if (D_L18_0023AD70[k]->b63 != 0) D_L18_0023AD70[k]->b63 = 1;
                }
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_003A26D0, m);
        }
        if (m != 0) {
            s32 h = m->hAA;
            if (h == 0xFA0) {
                if (m->p68 != 0) func_L01_0044EB38(m, m->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
            } else if (h == 0x1DEE || h == 0x19BC) {
                func_L01_0044EB38(m, D_L18_001D6AE0_00433BC8, 0x80505080, 0x80404038, 0.031997703f);
            } else if (h == 0x1977) {
                func_L01_0044EB38(m, D_L18_001D6AE4_00433BC8, 0x8080AAAA, 0x80464646, 0.0378154702f);
            } else if (h == 0x1766) {
                func_L01_0044EB38(m, D_L18_001D6AE8_00433BC8, 0x80AAAAFF, 0x80646496, 0.110537529f);
            } else if (h == 0x195B || h == 0x1B58 || h == 0x195C || h == 0x175A) {
                func_L01_00402498(func_L01_00421438, m);
            }
        }
        i = n;
    }
    if (D_001D545C == 0x12 && D_L18_001E6E80.w30 == 0 && (D_L18_001E6E80.w34 == 0x78 || D_L18_001E6E80.w34 == 0xA6)) {
        V4_436E90 v;
        *(q_436E90 *)&v = 0;
        v.z = 1.0f;
        func_L08_00403E80(1, &v, 0x19, 0x19, 0x96, 0x64, 0x50204080, 0x50204080, 1.0f, 1.0f, 0x50204080);
    }
}
/* localdecomp:end func_L18_00433BC8 */
