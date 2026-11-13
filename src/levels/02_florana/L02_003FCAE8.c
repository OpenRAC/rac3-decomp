#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_003FCAE8 */
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; u8 p38[0xC]; s16 count; u8 p46[0x2A]; s32 f70; s32 f74; s32 f78; u8 p7C[0x124]; u8 *mobys[3]; u8 *f1AC; } S_3FCAE8;
extern S_3FCAE8 D_L02_001E5640;
extern u8 *D_L02_00237CB0[];
__asm__(".extern D_L02_001D6A90, 4");
extern f32 D_L02_001D6A90;
extern f32 D_L02_001D6A94;
extern f32 D_L02_001D6A98;
extern s32 D_001D545C;
extern u8 D_L02_001DE364;
extern u8 D_L02_001DE365;
extern u8 D_L02_001DE366;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(u8 *, s32);
extern void func_003A7AF8(void);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00424168(void);
extern void func_L01_00404808(void *, void *);
extern void func_L02_003FBE40(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L02_003FCAE8(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;

    func_L01_00423AB8();
    for (i = 0; i < D_L02_001E5640.count; i++) {
        m = D_L02_001E5640.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L02_00237CB0[j] != 0; j++) {
                if (D_L02_00237CB0[j][0x63] != 0) D_L02_00237CB0[j][0x63] = 1;
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
            func_L01_00451DB8(m, &D_L02_001D6A90, 0x80505080, 0x80404038, 0.038397245f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(m, &D_L02_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(m, &D_L02_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, m);
        }
    }
    if (D_001D545C == 2) {
        S_3FCAE8 *g = &D_L02_001E5640;
        if (g->f30 == 1) {
            if (g->f34 == 0x4AD) {
                vu0_v4 v, off, dir[3];
                u8 *h = g->mobys[0];
                func_L02_003FBE40(h, dir);
                func_0038CE20(&off, dir, 0.2f);
                vec_add_ab(&off, h + 0x10, &off);
                off.z += 1.1f;
                for (j = 0x18; j >= 0; j--) {
                    qzero(&v);
                    func_003C4C18(&v, 0.010000001f);
                    func_L01_004637C8(&off, &v, 0xC0507080, 0x253040, 0x43, 0x1E, 0x32, 0);
                }
            }
            return;
        } else if (g->f30 == 2) {
            if (g->f34 != 0x2CD) return;
        } else if (g->f30 == 3) {
            if (g->f34 != 1) return;
        } else {
            return;
        }
        D_L02_001DE364 = 0x9F;
        g->f70 = 0x9F;
        D_L02_001DE365 = 0xAA;
        g->f74 = 0xAA;
        D_L02_001DE366 = 0x77;
        g->f78 = 0x77;
    }
}
/* localdecomp:end func_L02_003FCAE8 */
