/* near miss (level 13: 169 diff with @ps2as, needs @ps2as) */
#include "common.h"

/* localdecomp:start func_L13_004053F0 */
typedef struct {
    char _p0[0x34];
    u16 u34;
    char _p36[0x63 - 0x36];
    u8 f63;
    char _p64[0x68 - 0x64];
    u8 *f68;
    char _p6C[0xAA - 0x6C];
    s16 hAA;
} M_4053F0;
typedef struct {
    char _p0[0x30];
    s32 f30;
    char _p34[0x44 - 0x34];
    s16 s44;
    char _p46[0x1A0 - 0x46];
    M_4053F0 *list[1];
} G_4053F0;

extern G_4053F0 D_L13_001E6480;
extern M_4053F0 *D_L13_00238AF0[];
extern u8 D_L13_001D6A90[];
extern u8 D_L13_001D6A94[];
extern u8 D_L13_001D6A98[];
extern s32 D_001D545C;
extern void func_L01_00423AB8(void);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(void *, void *, u32, u32, f32);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void);
extern void func_L01_00424168(void);
extern void func_L03_00411778(s32, s32);

void func_L13_004053F0(void) {
    s32 i;
    s32 n;
    M_4053F0 *m;
    M_4053F0 **p;

    func_L01_00423AB8();
    for (i = 0; i < D_L13_001E6480.s44; i = n) {
        m = D_L13_001E6480.list[i];
        n = i + 1;
        if (m != 0 && m->hAA == 0xE29) {
            m->u34 |= 0x800;
        }
        if (m->hAA == 0xD54) {
            m->f63 = 0;
            for (p = D_L13_00238AF0; *p != 0; p++) {
                if ((*p)->f63 == 0) {
                    (*p)->f63 = 1;
                }
            }
            func_003A58C0(m, 0);
            func_L01_00404A10(func_003A7AF8, m);
        }
        if (m != 0) {
            switch (m->hAA) {
            case 0xFA0:
                if (m->f68 != 0) {
                    func_L01_00451DB8(m, m->f68 + 0xC, 0x80AAAAD2, 0x80396464, 0.07330383f);
                }
                break;
            case 0x1DEE:
            case 0x19BC:
                func_L01_00451DB8(m, D_L13_001D6A90, 0x80505080, 0x80404038, 0.038397245f);
                break;
            case 0x1977:
                func_L01_00451DB8(m, D_L13_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
                break;
            case 0x1766:
                func_L01_00451DB8(m, D_L13_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
                break;
            case 0x195B:
            case 0x1B58:
            case 0x195C:
            case 0x175A:
                func_L01_00404808(func_L01_00424168, m);
                break;
            }
        }
    }
    if (D_001D545C == 0xD && D_L13_001E6480.f30 == 1) {
        func_L03_00411778(0x712, 0x788);
    }
}
/* localdecomp:end func_L13_004053F0 */
