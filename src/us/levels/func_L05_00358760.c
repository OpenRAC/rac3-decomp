#include "common.h"

/* NTSC-U counterpart of func_L05_00359878 (src/levels/shared/L05_00355DD8.c): func_003BE4F0 gets 3 instead of 2 */
/* localdecomp:start func_L05_00358760 */
typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x30 - 0x21];
    unsigned long q30;
    u8 p38[0x43 - 0x38];
    u8 b43;
    u8 p44[0x62 - 0x44];
    u8 b62;
    u8 p63[0x68 - 0x63];
    void *p68;
    u8 p6C[0x94 - 0x6C];
    u8 b94;
    u8 b95;
    u8 p96[2];
    s32 w98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
} M_358760;

typedef struct {
    u8 p0[0x30];
    f32 f30;
    u8 p34[0x3E - 0x34];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 b60;
    u8 p61[0x160 - 0x61];
    u8 x160[0x370 - 0x160];
    s32 w370;
    f32 f374;
    s32 w378;
    f32 f37C;
    u8 p380[0x3D8 - 0x380];
    s16 h3D8;
    s16 h3DA;
    u8 p3DC[0x3EC - 0x3DC];
    M_358760 *x3EC;
    u8 p3F0[0x3FC - 0x3F0];
    s32 w3FC;
} C_358760;

extern s32 D_001D545C;
extern s32 func_L05_00354AF8(u8 *a0);
extern s32 func_L05_00358B60(u8 *);
extern void func_L05_00359430(u8 *, s32);
extern void func_L05_00359848(u8 *);
extern void func_L05_00354FE0(u8 *);
extern void func_003BD360(u8 *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003C1A60(void *, s32 *, s32 *, s32 *);
extern void func_L01_00438908(void *, s32, s32, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L05_00358760(u8 *a0) {
    M_358760 *m = (M_358760 *)a0;
    C_358760 *c = (C_358760 *)m->p68;
    s32 v[3];
    s32 r;
    s32 s5;
    u8 save;
    f32 f;

    if (m->b20 == 0 && func_L05_00358B60(a0) != 0) {
        return 1;
    }
    if (D_001D545C == 0xE) {
        m->b62 = 0;
        if (c->x3EC != 0) {
            c->x3EC->b62 = 0;
        }
    }
    if (c->b60 != 0 || c->b5E != 0 || c->b3E == 2) {
        func_L05_00359430(a0, 0);
        func_003BD360(a0);
        return 1;
    }
    s5 = func_L05_00354AF8(a0);
    f = c->f30;
    save = m->b94;
    r = func_L01_0044FCD0(m, c->x160, 0, 0, c->h3DA);
    if (f != c->f30) {
        func_L05_00359848(a0);
    }
    if (r != 0) {
        if (r != 1) {
            if (m->b94 == 2 || m->b94 == 0x10 || m->b94 == 0x11 || m->b94 == 0x12) {
                m->b94 = save;
            }
            if (m->b94 == 0xE) {
                m->b94 = 0xF;
            } else if (m->b94 == 0xC) {
                m->b94 = 0xB;
            }
            if (m->b43 < 0x12) {
                func_003BE4F0(c->x3EC, m->b43, 0, 3);
            }
            if (s5 != 0 || c->w3FC != 0) {
                func_003BE4F0(m, 0x13, 0, 0);
            }
        }
    }
    m->bA8 = 0xFF;
    if (c->x3EC != 0) {
        func_003C1A60(m, &v[0], &v[1], &v[2]);
        func_L01_00438908(c->x3EC, v[0], v[1], v[2]);
    }
    func_L01_0044F5E8(m, &c->f30, 0);
    if (c->b5F != 0) {
        func_L05_00354FE0(a0);
        if ((m->q30 & 0x104100000000UL) != 0x4100000000UL || m->w98 != 0) {
            if (c->f30 > 0.0f) {
                func_L01_004538E0(m, 5);
            }
        }
        if (m->b95 == 0) {
            func_L01_004539A8(m, c->w370, c->f374, 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
            return 0;
        } else {
            func_L01_004539A8(m, c->w378, c->f37C, 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
        return 0;
    }
    if ((m->q30 & 0x104100000000UL) != 0x4100000000UL || m->w98 != 0) {
        if (c->f30 > 0.0f) {
            func_L01_004538E0(m, 3);
        }
    }
    if (c->h3D8 != 0) {
        func_L01_004539A8(m, -1, 255.0f, 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
    } else if (m->b95 == 0) {
        func_L01_004539A8(m, c->w370, c->f374, 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
    } else {
        func_L01_004539A8(m, c->w378, c->f37C, 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L05_00358760 */
