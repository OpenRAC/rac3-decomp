#include "common.h"

/* NTSC-U counterpart of func_L01_003AD010 (src/levels/shared/L01_003AC8C0.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern f32 func_00389380(f32, f32);

/* localdecomp:start func_L01_003AB888 */
typedef struct {
    s32 w0;
    s32 w4;
    u8 p8[0x10];
} E_3AD010_003AD010;
typedef struct {
    u8 p0[8];
    s32 n;
    E_3AD010_003AD010 *e;
    u8 p10[0xC];
    f32 f1C;
    f32 f20;
    s32 w24;
    f32 f28;
    f32 f2C;
} C_3AD010_003AD010;
typedef struct {
    u8 p0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 p21[0x95 - 0x21];
    u8 b95;
    u8 p96[0xC0 - 0x96];
    vu0_v4 mC0[3];
    u8 pF0[8];
    f32 fF8;
} O_3AD010_003AD010;
typedef struct {
    u8 p0[0x44];
    s16 h44;
    u8 p46[0x64 - 0x46];
    void *w64;
    C_3AD010_003AD010 *cfg;
    u8 p6C[4];
    vu0_v4 v70;
    u8 p80[0x20];
    u8 ent[0xC60 - 0xA0];
    s32 wC60;
    u8 pC64[0xCE0 - 0xC64];
    s32 wCE0;
    u8 pCE4[8];
    s32 wCEC;
    u8 pCF0[0xD90 - 0xCF0];
    vu0_v4 mD90[3];
} M_3AD010_003AD010;

extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_00388398(void *);
extern void func_L01_0044B5C8_003AB888(void *, void *, s32, f32, f32);
extern void func_L01_00442038_003AB888(void *, s32);
extern f32 func_003887A0(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0040C920_003AB888(void *, void *);
extern void func_003BDA38(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_00388BD0(u8 *a0, u8 *a1);
extern void func_00388EB8(void *, void *, void *);
extern void func_003BF360(void *, void *);
extern void func_L01_003AB820_003AB888(s32 arg0, s32 arg1, void *arg2, void *arg3);

void func_L01_003AB888(O_3AD010_003AD010 *o, M_3AD010_003AD010 *m) {
    vu0_v4 dir;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 rot;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 m70[3];
    vu0_v4 mA0[3];
    vu0_v4 mD0[3];
    vu0_v4 v100;
    C_3AD010_003AD010 *cfg;
    E_3AD010_003AD010 *e;
    u8 *ent;
    s32 i;
    f32 a;
    f32 s;
    f32 len;
    f32 t;

    cfg = m->cfg;
    if (cfg->n == 0) {
        return;
    }
    a = func_00389380(o->fF8, cfg->f1C);
    dir.x = func_00388960(a);
    dir.y = func_00388978(a);
    *(s32 *)&dir.z = 0;
    func_003888C8(&v10, m->mD90, o->mC0);
    vec_add_ba(&v10, &v10, &o->v10);
    vec_sub_ab(&v40, &m->v70, &v10);
    v50 = v40;
    *(s32 *)&v50.z = 0;
    func_00388830(&v50, &v50, 1.0f);
    if (o->b20 < 2 || m->wCE0 == 0
        || (m->wCEC <= 0 && (o->b95 == 3 || m->h44 != 1 || v50.x * dir.x + v50.y * dir.y < cfg->f20))) {
        func_00388398(&m->wC60);
        if (m->wC60 < cfg->w24) {
            m->wC60 = cfg->w24;
        }
        e = cfg->e;
        for (i = 0; i < cfg->n; i++) {
            ent = &m->ent[e->w4 * 128];
            qzero(ent + 0x60);
            func_L01_0044B5C8_003AB888(m->w64, ent, e->w0, 0.0299999993f, 0.300000012f);
            e++;
        }
        return;
    }
    if (o->b95 == 3) {
        func_00388398(&m->wC60);
        if (m->wC60 < cfg->w24) {
            m->wC60 = cfg->w24;
        }
    } else if (func_00388398(&m->wC60) != 0 && o->b95 != 2) {
        func_L01_00442038_003AB888(o, 2);
    }
    len = func_003887A0(&v40);
    if (len < cfg->f28 * 0.5f + cfg->f2C) {
        s = cfg->f2C - len;
    } else {
        s = cfg->f28 * -0.5f;
    }
    if (m->wCEC > 0) {
        t = (f32)m->wCEC / (f32)m->wCE0;
        t = s + cfg->f28 * (1.0f - t);
    } else {
        t = s;
    }
    func_003886E8(&v100, &v50, t);
    vec_add_ab(&v60, &v100, &m->v70);
    func_L01_0040C920_003AB888(mD0, o->mC0);
    qzero(&rot);
    e = cfg->e;
    for (i = 0; i < cfg->n; i++) {
        ent = &m->ent[e->w4 * 128];
        func_003BDA38(m->w64, e->w0, &v10);
        vec_sub_ab(&v20, &v60, &v10);
        rot.y = -func_00388A28(func_003887A0(&v20), v20.z);
        rot.z = func_00388A28(v20.x, v20.y);
        func_00388BD0(m70, &rot);
        func_00388EB8(mA0, mD0, m70);
        func_003BF360(mA0, ent + 0x60);
        func_L01_003AB820_003AB888((s32)o, (s32)m, e, ent + 0x60);
        func_L01_0044B5C8_003AB888(m->w64, ent, e->w0, 0.0299999993f, 0.300000012f);
        e++;
    }
}
/* localdecomp:end func_L01_003AB888 */
