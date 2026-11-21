#include "common.h"

/* NTSC-U counterpart of func_L13_004053F0 (src/levels/13_holostar_studios_ratchet/L13_004053F0.c): 0.0733038 -> 0.0610865; 0.0383972 -> 0.0319977; 0.0453786 -> 0.0378155; 0.132645 -> 0.110538 */
/* localdecomp:start func_L13_00402320 */
typedef struct { u8 pad0[0x30]; s32 f30; u8 pad34[0x44 - 0x34]; s16 count; u8 pad46[0x1A0 - 0x46]; u8 *mobys[1]; } L_4053F0;
extern L_4053F0 D_L13_001E6500;
extern u8 *D_L13_00238B70[];
extern s32 D_001D545C;
__asm__(".extern D_L13_001D6A90_00402320, 4");
extern f32 D_L13_001D6A90_00402320;
extern f32 D_L13_001D6A94_00402320;
extern f32 D_L13_001D6A98_00402320;
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_00421438(void *);
extern void func_L03_0040E698(s32 arg0, s32 arg1);

void func_L13_00402320(void)
{
    s32 i;
    u8 *m;
    s16 id;
    s32 j;

    func_L01_00420D88();
    for (i = 0; i < D_L13_001E6500.count; i++) {
        m = D_L13_001E6500.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) {
            *(u16 *)(m + 0x34) |= 0x800;
        }
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L13_00238B70[j] != 0; j++) {
                if (D_L13_00238B70[j][0x63] != 0) {
                    D_L13_00238B70[j][0x63] = 1;
                }
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_003A26D0, m);
        }
        if (m != 0) {
            id = *(s16 *)(m + 0xAA);
            if (id == 0xFA0) {
                if (*(u8 **)(m + 0x68) != 0) {
                    func_L01_0044EB38(m, *(u8 **)(m + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
                }
            } else if (id == 0x1DEE || id == 0x19BC) {
                func_L01_0044EB38(m, &D_L13_001D6A90_00402320, 0x80505080, 0x80404038, 0.031997703f);
            } else if (id == 0x1977) {
                func_L01_0044EB38(m, &D_L13_001D6A94_00402320, 0x8080AAAA, 0x80464646, 0.0378154702f);
            } else if (id == 0x1766) {
                func_L01_0044EB38(m, &D_L13_001D6A98_00402320, 0x80AAAAFF, 0x80646496, 0.110537529f);
            } else if (id == 0x195B || id == 0x1B58 || id == 0x195C || id == 0x175A) {
                func_L01_00402498(func_L01_00421438, m);
            }
        }
    }
    if (D_001D545C == 0xD && D_L13_001E6500.f30 == 1) {
        func_L03_0040E698(0x712, 0x788);
    }
}
/* localdecomp:end func_L13_00402320 */
