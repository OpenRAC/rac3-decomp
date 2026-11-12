/* func_L14_003547F8: near miss, 4 diff: file already has the VU0 + @ps2as set; everything else matches (func_L01_003303B8 and func_003A52A0 declared returning s32, as in func_L14_003542F0). Left: in the i >= 3 block retail loads off ($vf1) and ctr[i] ($vf2) and adds before copying nrm[i] through $vf1; with the copy written first (this draft) the registers are right but the copy is scheduled first, with the add first ($vf1/$vf2 swap) 6 diff; _ab/_ba forms and a struct copy tried
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
typedef int u128_t_3547F8 __attribute__((mode(TI)));
typedef struct {
    s32 n0;
    s32 n;
    f32 depth;
    s32 fC;
    vu0_v4 pts[60];
    vu0_v4 nrm[60];
    vu0_v4 ctr[60];
} S_3547F8;
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern s32 D_L14_001DF240;
extern S_3547F8 D_L14_00284820;
extern S_3547F8 D_L14_002856A0;
extern void func_L14_003F7C70(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_00450DE8(void *, f32, f32, f32, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L14_00354B90(S_L14_00354B90 *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
void func_L14_003547F8(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    vu0_v4 off;
    vu0_v4 tmp;
    s32 i;
    if (D_L14_001DF240 == 0) {
        func_L14_003F7C70(&D_L14_002856A0, (s32)0x90000000, 20, 1, 0.4f, 0.9f, 1.5f);
    }
    if (a0[0x31] != 0) {
        for (i = 1; i < D_L14_00284820.n; i++) {
            func_L01_00450DE8(a0, 0.0f, -4.0f, 5.7f, &off);
            vec_add_ba(&b, &D_L14_00284820.pts[i - 1], &off);
            vec_add_ab(&a, &D_L14_00284820.pts[i], &off);
            if (i >= 3) {
                vec_copy(&tmp, &D_L14_00284820.nrm[i]);
                vec_add_ba(&b, &D_L14_00284820.ctr[i], &off);
                vec_add_ab(&a, &b, &tmp);
            }
        }
        func_L01_00404A10(func_L14_00354B90, a0);
    }
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x7F, &D_L14_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        *(u128_t_3547F8 *)&b = 0;
        b.y = -4.0f;
        b.z = 5.4f;
        func_0038CE20(&b, &b, 4.099873f);
        *(u128_t_3547F8 *)&a = 0;
        a.z = -0.14000002f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x14, 0, 0.18f, 1.5f, 20.0f, 1.0f, 0);
        func_0038CE20(&b, &b, *(f32 *)(a0 + 0x2C));
        func_0038D000(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, 0.70000005f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
