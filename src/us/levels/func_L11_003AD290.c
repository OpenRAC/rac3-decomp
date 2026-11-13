#include "common.h"

/* NTSC-U counterpart of func_L11_003AF058 (src/levels/11_obani_moons/L11_003AE1B0.c) */
#include "vu0.h"
extern void func_L01_0044E010(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L11_003AD290(u8 *);

/* localdecomp:start func_L11_003AD290 */
extern u8 D_L11_001D66B0_003AD290;
extern u8 *D_L11_0021E6C8_003AD290[];
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_0037E2F0(void *, f32, f32);
extern void func_L01_0046FE70(void *, void *, s32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L11_003AD290(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 mtx;
    vu0_v4 dir;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 s;
    f32 sc;
    u8 *q;

    func_L01_0044E010(a0, &mtx, 1);
    func_00388758(&dir, &mtx, v);
    func_00388830(&a, &dir, *(f32 *)(v + 0x18));
    vec_add_ab(&a, &a, a0 + 0x10);
    func_00388830(&b, &dir, -*(f32 *)(v + 0x18));
    vec_add_ab(&b, &b, a0 + 0x10);
    p = a;
    func_0037E2F0(&r, 0.025f, 0.15f);
    vec_add_ba(&r, &r, &p);
    vec_sub_ab(&s, &p, &r);
    func_00388830(&s, &s, 0.012500001f);
    func_L01_0046FE70(&r, &s, 7, 1.0f);
    sc = (func_L01_00440918(0.0f, 0.15f) + 0.75f) * 210000.0f;
    if (func_0037E1D8(2) != 0) {
        q = func_L01_00466F98(&p, &D_L11_001D66B0_003AD290, 7, 6, 0x904020, (s32)func_L01_00440918(1.0f, -1.0f), sc * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[2] = D_L11_0021E6C8_003AD290[0][1];
        }
    }
    p.x += func_L01_00440918(0.0f, 0.04f);
    p.y += func_L01_00440918(0.0f, 0.04f);
    p.z += func_L01_00440918(0.0f, 0.04f);
    if (func_0037E1D8(2) != 0) {
        q = func_L01_00466F98(&p, &D_L11_001D66B0_003AD290, 7, 0x6F, 0x804020, (s32)func_L01_00440918(1.0f, -1.0f), sc * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8_003AD290[0][0];
        }
        q = func_L01_00466F98(&p, &D_L11_001D66B0_003AD290, 7, 0x6F, 0x802080, (s32)func_L01_00440918(1.0f, -1.0f), sc * 1.25f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8_003AD290[0][0];
        }
    }
    p = b;
    func_0037E2F0(&r, 0.025f, 0.15f);
    vec_add_ba(&r, &r, &p);
    vec_sub_ab(&s, &p, &r);
    func_00388830(&s, &s, 0.012500001f);
    func_L01_0046FE70(&r, &s, 7, 1.0f);
    sc = (func_L01_00440918(0.0f, 0.15f) + 0.75f) * 210000.0f;
    if (func_0037E1D8(2) != 0) {
        q = func_L01_00466F98(&p, &D_L11_001D66B0_003AD290, 7, 6, 0x904020, (s32)func_L01_00440918(1.0f, -1.0f), sc * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[2] = D_L11_0021E6C8_003AD290[0][1];
        }
    }
    p.x += func_L01_00440918(0.0f, 0.04f);
    p.y += func_L01_00440918(0.0f, 0.04f);
    p.z += func_L01_00440918(0.0f, 0.04f);
    if (func_0037E1D8(2) != 0) {
        q = func_L01_00466F98(&p, &D_L11_001D66B0_003AD290, 7, 0x6F, 0x804020, (s32)func_L01_00440918(1.0f, -1.0f), sc * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8_003AD290[0][0];
        }
        q = func_L01_00466F98(&p, &D_L11_001D66B0_003AD290, 7, 0x6F, 0x802080, (s32)func_L01_00440918(1.0f, -1.0f), sc * 1.25f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8_003AD290[0][0];
        }
    }
}
/* localdecomp:end func_L11_003AD290 */
