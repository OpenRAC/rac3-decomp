/* NTSC-U draft (Claude wave C4): C of func_L07_0035D738, the NTSC-U twin of func_L07_0035E618, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L07_0035D738", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (vec helpers + lui/ori float constants; the PAL file has neither); 137 normalized diff words of 314 (154 at the first draft, frame 0x140 vs retail 0x120): retail keeps priv ...
 */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x5C];
    u8 *p5C;
    u8 pad60[0x74];
    u8 *pD4;
} Tab_0035D738;

/* localdecomp:start func_L07_0035D738 */
__asm__(".extern D_001DD730_sda, 8");
__asm__(".extern D_001DD760_sda, 4");
__asm__(".extern D_001DD764_sda, 4");
__asm__(".extern D_001DD770_sda, 4");
extern u8 D_001DD730_sda[8];
extern f32 D_001DD760_sda;
extern f32 D_001DD764_sda;
extern f32 D_001DD770_sda;
extern f32 D_001DD774;
extern f32 D_001DD778;
extern f32 D_L07_001E0FB0;
extern f32 D_L07_001E0FB4;
extern f32 D_L07_001E0FB8;
extern vu0_v4 D_001A4EC0;
extern Tab_0035D738 D_L07_0021EC98;
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern u8 *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_0035D738(u8 *obj, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 m70[3];
    vu0_v4 vA0;
    u8 *priv;
    u8 *o;
    u8 *o2;
    u8 *o3;
    u8 *vp;
    vu0_v4 *pm70;
    vu0_v4 *pv60;
    vu0_v4 *pq60;
    vu0_v4 *pvA0;
    f32 len;
    f32 r;
    f32 r2;
    s32 n;
    s32 c;
    s32 k;
    s32 z;
    s32 col;
    s32 col2;
    s32 s3z;
    s32 s0b;
    s32 s0;

    *(vu0_q *)&v10 = *(vu0_q *)a1;
    priv = *(u8 **)(obj + 0x68);
    *(vu0_q *)&v20 = *(vu0_q *)a2;
    len = func_00388770(priv);
    *(vu0_q *)&v40 = *(vu0_q *)&v20;
    vec_sub_ab(&v50, &v10, &v20);
    n = (s32)(len / 0.1f);
    func_00388830(&v50, &v50, len / (f32)n);
    pm70 = m70;
    pv60 = &v60;
    pvA0 = &vA0;
    if (n > 0) {
        c = n;
        do {
            z = (s32)func_L01_00440918(1.0f, 3.0f);
            r = func_0037E250(0.1f, 0.2f);
            func_003886E8(&v30, &D_001A4EC0, -(r * 0.016666668f));
            s0 = func_0037E208(3, 6);
            if ((func_0013D3E0() & 2) != 0) {
                k = 0x40;
                col = 0xFF7F40;
            } else {
                k = 0x60;
                col = 0xFF4040;
            }
            o = func_L01_00466F98(&v40, &v30, s0, k, col, z, 126000.01f, 10000.0f, 1.0f, 0.0f, 0.0f);
            vec_add_ab(&v40, &v40, &v50);
            if (o != 0) {
                o[2] = *D_L07_0021EC98.p5C;
                o[3] = (k == 0x40) ? 0x48 : 0x44;
            }
            c--;
        } while (c != 0);
    }
    if (func_0037E1D8(2) != 0) {
        func_003886E8(pv60, priv, -0.033333335f);
        func_003BF6A8(pv60, 0.10000001f);
        v60.z = v60.z + 0.050000004f;
        col2 = (func_0037E1D8(2) != 0) ? 0x7F407FFF : 0x7F80DFFF;
        o2 = func_L01_00462190(obj + 0x10, pv60, col2, 0xFF0000, func_0037E208(10, 20), 0, -1, -1, 0, 157500.0f);
        if (o2 != 0) {
            *(f32 *)(o2 + 0x2C) = 0.0016666667f;
            o2[2] = *D_L07_0021EC98.pD4;
        }
    }
    D_L07_001E0FB0 = func_00389380(D_L07_001E0FB0, D_001DD770_sda * 0.017453292f * 0.016666668f);
    D_L07_001E0FB4 = func_00389380(D_L07_001E0FB4, D_001DD774 * 0.017453292f * 0.016666668f);
    D_L07_001E0FB8 = func_00389380(D_L07_001E0FB8, D_001DD778 * 0.017453292f * 0.016666668f);
    func_00388BD0(pm70, &D_L07_001E0FB0);
    pq60 = pv60;
    vp = D_001DD730_sda;
    c = 2;
    do {
        func_003888C8(pvA0, vp, pm70);
        if (*(s32 *)(priv + 0x14) >= 6) {
            func_00388830(pvA0, pvA0, D_001DD760_sda);
        } else {
            func_00388830(pvA0, pvA0, 0.0f);
        }
        vec_add_ab(&vA0, &vA0, obj + 0x10);
        vec_sub_ab(&v60, &vA0, obj + 0x10);
        func_00388830(pq60, pq60, D_001DD764_sda * 0.016666668f);
        s3z = (s32)func_L01_00440918(2.0f, 5.0f);
        r2 = func_0037E250(0.12f, 0.18f);
        o3 = func_L01_0046DCB8(pvA0, pq60, 0xF, 0x802020, s3z, 0x6F, 0, 6, 126000.01f, r2 * 210000.0f, 0.0f);
        if (o3 != 0) {
            o3[3] = (func_0037E1D8(4) != 0) ? 0x48 : 0x44;
        }
        c--;
        vp = vp + 0x10;
    } while (c >= 0);
}
/* localdecomp:end func_L07_0035D738 */
