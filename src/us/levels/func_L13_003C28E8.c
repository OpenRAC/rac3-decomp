#include "common.h"

/* NTSC-U counterpart of func_L13_003C4AB0 (src/levels/13_holostar_studios_ratchet/L13_003C4AB0.c) */
#include "vu0.h"

/* localdecomp:start func_L13_003C28E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C4AB0;
typedef struct {
    char _p0[0x24];
    f32 f24;
} C_3C4AB0;
typedef struct {
    char _p0[0x10];
    V4_3C4AB0 v10;
    char _p20[4];
    C_3C4AB0 *f24;
    char _p28[4];
    f32 f2C;
    char _p30[0xC0 - 0x30];
    V4_3C4AB0 vC0;
} M_3C4AB0;

extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90_003C28E8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
extern u8 D_L13_001D66B0_003C28E8[8];
__asm__(".extern D_L13_001DEB84, 4");
__asm__(".extern D_L13_001DEB80_003C28E8, 4");
extern f32 D_L13_001DEB84;
extern f32 D_L13_001DEB80_003C28E8;

void func_L13_003C28E8(M_3C4AB0 *m) {
    V4_3C4AB0 v;
    V4_3C4AB0 w;
    f32 inv;

    if (func_L01_00444358(m, -1, 0) == 0) {
        return;
    }
    func_0039FE80(0, 0, m);
    func_L01_0044ED60(m, 0x3F, D_L13_001D66B0_003C28E8, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    inv = 1.0f / m->f24->f24;
    *(vu0_q *)&v = 0;
    v.x = 4.4f;
    v.y = 2.9f;
    v.z = 35.0f;
    func_003886E8(&v, &v, inv);
    *(vu0_q *)&w = 0;
    w.z = -0.116666675f;
    func_L02_003E0520(m, &v, 0.1f, &w, 0x14, 0, 0, 0.15f, D_L13_001DEB84 * inv * m->f2C, 20.0f, 1.0f);
    func_003886E8(&v, &v, m->f2C);
    func_003888C8(&v, &v, &m->vC0);
    vec_add_ab(&v, &v, &m->v10);
    func_L01_0032FE90_003C28E8((u8 *)&v, 0, 0, 0, 0, 2, 5, 0, D_L13_001DEB80_003C28E8 * inv * m->f2C, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
    func_L01_0044EBF8(m, 1, 0.0f);
    func_003BD360(m);
}
/* localdecomp:end func_L13_003C28E8 */
