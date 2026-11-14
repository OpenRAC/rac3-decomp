#include "common.h"

/* NTSC-U counterpart of func_L02_003FCAE8 (src/levels/02_florana/L02_003FCAE8.c): 0.0733038 -> 0.0610865; 0.0383972 -> 0.0319977; 0.0453786 -> 0.0378155; 0.132645 -> 0.110538; 1197 -> 1437; 0.01 -> 0.00833333; 67 -> 80; 717 -> 860 */
#include "vu0.h"

/* localdecomp:start func_L02_003F9890 */
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; u8 p38[0xC]; s16 count; u8 p46[0x2A]; s32 f70; s32 f74; s32 f78; u8 p7C[0x124]; u8 *mobys[3]; u8 *f1AC; } S_3FCAE8;
extern S_3FCAE8 D_L02_001E56C0;
extern u8 *D_L02_00237D30[];
__asm__(".extern D_L02_001D6A90_003F9890, 4");
extern f32 D_L02_001D6A90_003F9890;
extern f32 D_L02_001D6A94_003F9890;
extern f32 D_L02_001D6A98_003F9890;
extern s32 D_001D545C;
extern u8 D_L02_001DE3E4;
extern u8 D_L02_001DE3E5;
extern u8 D_L02_001DE3E6;
extern void func_L01_00420D88(void);
extern void func_003A04A0(u8 *, s32);
extern void func_003A26D0(void);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00421438(void);
extern void func_L01_00402498(void *, void *);
extern void func_L02_003F8C58(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L02_003F9890(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;

    func_L01_00420D88();
    for (i = 0; i < D_L02_001E56C0.count; i++) {
        m = D_L02_001E56C0.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L02_00237D30[j] != 0; j++) {
                if (D_L02_00237D30[j][0x63] != 0) D_L02_00237D30[j][0x63] = 1;
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
            func_L01_0044EB38(m, &D_L02_001D6A90_003F9890, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(m, &D_L02_001D6A94_003F9890, 0x8080AAAA, 0x80464646, 0.0378154702f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(m, &D_L02_001D6A98_003F9890, 0x80AAAAFF, 0x80646496, 0.110537529f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, m);
        }
    }
    if (D_001D545C == 2) {
        S_3FCAE8 *g = &D_L02_001E56C0;
        if (g->f30 == 1) {
            if (g->f34 == 0x59D) {
                vu0_v4 v, off, dir[3];
                u8 *h = g->mobys[0];
                func_L02_003F8C58(h, dir);
                func_003886E8(&off, dir, 0.2f);
                vec_add_ab(&off, h + 0x10, &off);
                off.z += 1.1f;
                for (j = 0x18; j >= 0; j--) {
                    qzero(&v);
                    func_003BF6A8(&v, 0.00833333377f);
                    func_L01_00460318(&off, &v, 0xC0507080, 0x253040, 0x50, 0x1E, 0x32, 0);
                }
            }
            return;
        } else if (g->f30 == 2) {
            if (g->f34 != 0x35C) return;
        } else if (g->f30 == 3) {
            if (g->f34 != 1) return;
        } else {
            return;
        }
        D_L02_001DE3E4 = 0x9F;
        g->f70 = 0x9F;
        D_L02_001DE3E5 = 0xAA;
        g->f74 = 0xAA;
        D_L02_001DE3E6 = 0x77;
        g->f78 = 0x77;
    }
}
/* localdecomp:end func_L02_003F9890 */
