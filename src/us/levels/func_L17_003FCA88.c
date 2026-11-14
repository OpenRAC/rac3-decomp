#include "common.h"

/* NTSC-U counterpart of func_L17_003FF6B8 (src/levels/17_crash_site/L17_003FF6B8.c): 0.0733038 -> 0.0610865; 0.0383972 -> 0.0319977; 0.0453786 -> 0.0378155; 0.132645 -> 0.110538; 1084 -> 1301 */
/* localdecomp:start func_L17_003FCA88 */
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; u8 p38[0xC]; s16 count; u8 p46[0x15A]; u8 *mobys[3]; u8 *f1AC; } S_3FF6B8;
extern S_3FF6B8 D_L17_001E5CC0_003FCA88;
extern u8 *D_L17_00238330_003FCA88[];
__asm__(".extern D_L17_001D6A90_003FCA88, 4");
extern f32 D_L17_001D6A90_003FCA88;
extern f32 D_L17_001D6A94_003FCA88;
extern f32 D_L17_001D6A98_003FCA88;
extern s32 D_001D545C;
extern void func_L01_00420D88(void);
extern void func_003A04A0(u8 *, s32);
extern void func_003A26D0(void);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00421438(void);
extern void func_L01_00402498(void *, void *);
extern void func_L03_0040EE18(u8 *, s32);

void func_L17_003FCA88(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;

    func_L01_00420D88();
    for (i = 0; i < D_L17_001E5CC0_003FCA88.count; i++) {
        m = D_L17_001E5CC0_003FCA88.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L17_00238330_003FCA88[j] != 0; j++) {
                if (D_L17_00238330_003FCA88[j][0x63] != 0) D_L17_00238330_003FCA88[j][0x63] = 1;
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
            func_L01_0044EB38(m, &D_L17_001D6A90_003FCA88, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(m, &D_L17_001D6A94_003FCA88, 0x8080AAAA, 0x80464646, 0.0378154702f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(m, &D_L17_001D6A98_003FCA88, 0x80AAAAFF, 0x80646496, 0.110537529f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, m);
        }
    }
    if (D_001D545C == 0x11 && D_L17_001E5CC0_003FCA88.f30 == 2 && D_L17_001E5CC0_003FCA88.f34 < 0x515) {
        m = D_L17_001E5CC0_003FCA88.f1AC;
        if (m != 0) {
            func_L03_0040EE18(m, 0);
            func_L03_0040EE18(m, 1);
        }
    }
}
/* localdecomp:end func_L17_003FCA88 */
