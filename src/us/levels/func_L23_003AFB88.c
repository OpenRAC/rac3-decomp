#include "common.h"
#include "vu0.h"
#include "structs/hero.h"

/* NTSC-U counterpart of func_L23_003B1490 with regional timing. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0200;
typedef struct { u8 pad0[0x30]; V4_3B0200 pos; u8 pad40[0x40]; } Node_3B0200;

extern struct Hero D_001A4BE0;
extern Node_3B0200 *D_L23_001DF2C0; __asm__(".extern D_L23_001DF2C0, 16");
extern u8 D_L23_001E1AC0[];
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_L01_0040C040(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L01_00443790(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_L01_00436500(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_00457728(void *, void *);
extern Node_3B0200 *D_L23_001DF2C0;
__asm__(".extern D_L23_001DF2C0, 16");
extern s32 D_L23_001DECC0;

/* localdecomp:start func_L23_003AFB88 */
typedef struct {
    u8 pad0[0x30]; f32 f30; u8 pad34[0xA4 - 0x34]; f32 fA4;
    u8 padA8[0x110 - 0xA8]; f32 f110; f32 f114; f32 f118; u8 pad11C[0x13C - 0x11C]; f32 f13C;
    u8 pad140[0x170 - 0x140]; V4 v170; u8 pad180[4]; s16 h184;
    u8 pad186[0x300 - 0x186];
    s32 x300; s32 x304; f32 x308; s32 x30C; s32 x310; u8 pad314[8]; s32 x31C; s32 x320; f32 x324;
    f32 x328; f32 f32C; s32 x330; s32 x334; f32 f338; s32 x33C; u8 pad340[4]; f32 x344; s32 x348; f32 x34C;
    u8 pad350[0x10]; V4 v360; V4 v370; f32 f380; f32 f384; u8 pad388[4]; s32 x38C; u8 pad390[8]; s32 x398; f32 f39C;
} Vars_3AFB88;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0x42 - 0x21]; u8 b42; u8 b43;
    u8 pad44[4]; f32 f48; u8 pad4C[0x60 - 0x4C]; u8 b60; u8 pad61[7]; Vars_3AFB88 *vars; u8 pad6C[0x94 - 0x6C];
    u8 b94; u8 b95; u16 h96; u8 pad98[0xBC - 0x98]; u8 bBC; u8 padBD[0xF8 - 0xBD]; f32 fF8;
} Moby_3AFB88;
extern f32 D_L23_001DE384; __asm__(".extern D_L23_001DE384, 4");
extern f32 D_L23_001DE394; __asm__(".extern D_L23_001DE394, 4");
extern f32 D_L23_001DE398; __asm__(".extern D_L23_001DE398, 4");
extern s32 D_L23_001DE314; __asm__(".extern D_L23_001DE314, 4");
extern s32 D_L23_001DE39C; __asm__(".extern D_L23_001DE39C, 4");
extern s32 D_L23_001DE3A0; __asm__(".extern D_L23_001DE3A0, 4");
extern s32 D_L23_001DE3A4; __asm__(".extern D_L23_001DE3A4, 4");
extern s32 D_L23_001DE3A8; __asm__(".extern D_L23_001DE3A8, 4");
extern f32 D_L23_001DE3E0; __asm__(".extern D_L23_001DE3E0, 4");
extern f32 D_L23_001DE368; __asm__(".extern D_L23_001DE368, 4");
extern f32 D_L23_001DE37C; __asm__(".extern D_L23_001DE37C, 4");
extern f32 D_L23_001DE380; __asm__(".extern D_L23_001DE380, 4");
extern f32 D_L23_001DE388; __asm__(".extern D_L23_001DE388, 4");
extern s32 D_L23_001DE38C; __asm__(".extern D_L23_001DE38C, 4");
extern f32 D_L23_001DE390; __asm__(".extern D_L23_001DE390, 4");
extern f32 D_L23_001DE3AC; __asm__(".extern D_L23_001DE3AC, 4");
extern s32 D_L23_001DE3B0_003AFB88; __asm__(".extern D_L23_001DE3B0_003AFB88, 4");
extern f32 D_L23_001DE3B4; __asm__(".extern D_L23_001DE3B4, 4");
extern f32 D_L23_001DE3B8; __asm__(".extern D_L23_001DE3B8, 4");
extern f32 D_L23_001DE3BC; __asm__(".extern D_L23_001DE3BC, 4");
extern f32 D_L23_001DE3C0; __asm__(".extern D_L23_001DE3C0, 4");
extern s32 D_L23_001DE3C4; __asm__(".extern D_L23_001DE3C4, 4");
extern f32 D_L23_001DE3C8; __asm__(".extern D_L23_001DE3C8, 4");
extern s32 D_L23_001DE3CC; __asm__(".extern D_L23_001DE3CC, 4");
extern s32 D_L23_001DE3D0; __asm__(".extern D_L23_001DE3D0, 4");
extern f32 D_L23_001DE3D4; __asm__(".extern D_L23_001DE3D4, 4");
extern f32 D_L23_001DE3D8; __asm__(".extern D_L23_001DE3D8, 4");
extern s32 D_L23_001DE3DC; __asm__(".extern D_L23_001DE3DC, 4");
extern u8 *D_001A73E8[];
extern f32 func_003887A0(void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_0037E2F0(void *, f32, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern void *func_L23_00453320(V4 *, V4 *, f32, s32, s32, s32);
extern void *func_L23_003B9CE8(s32 arg0, u128_t *pos, u128_t *arg2, f32 scale, s32 arg3, f32 arg5);
extern void func_L01_003A81A0(u8 *obj);
extern void func_L23_003B2000(void *arg0);
extern void func_L23_003B1BF0(u8 *self);
extern void func_L23_003B22B0(void *m, V4 *target, f32 speed, s32 mode);
extern void func_L23_003B2800(V4 *out, u8 *self, s32 idx, V4 from, f32 r1, f32 r2);
extern f32 func_00388800(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_003BEB48(f32, f32, f32);
extern f32 func_L01_00440918(f32, f32);

void func_L23_003AFB88(Moby_3AFB88 *m) {
    Vars_3AFB88 *v;
    V4 w[6];

    v = m->vars;
    func_L23_003B1BF0((u8 *)m);
    switch (m->b95) {
    case 1:
        break;
    case 2:
        if (v->x300 != 3) {
            func_L01_00441FB8(m, 3, -1);
        }
        break;
    case 3:
        if (v->x30C == 3) {
            if (v->x300 == 3) {
                f32 d;
                V4 *p = &v->v170;
                *p = *(V4 *)&D_001A4BE0.pos;
                func_003BDA38(m, (v->x304 & 1) ^ 1, &w[0]);
                d = func_00388800(&w[0], p);
                v->x344 = -func_00388A28(d, v->v170.z - w[0].z);
            } else {
                f32 t = func_00388800(&D_001A4BE0.pos, &m->pos) / D_L23_001DE384;
                t *= v->x398 ? D_L23_001DE398 : D_L23_001DE394;
                func_003886E8(&w[0], &D_001A4BE0.vel, t);
                vec_add_ba(&v->v170, &w[0], &D_001A4BE0.pickup_point);
            }
        }
        break;
    }
    switch (m->b20) {
    case 1: {
        f32 a;
        u8 b;
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 0) {
                func_003BE4F0(m, 0, 0, 10);
            }
            v->x31C = 0;
            v->x308 = m->fF8;
            v->v360 = m->pos;
            v->x300 = 0;
        } else if (v->x31C == 10) {
            if (m->b43 != 1) {
                func_003BE4F0(m, 1, 0, 10);
            }
            v->x300 = 0;
        } else if ((b = m->b43) == 1 && func_L01_0044AF40(m, 100.0f) != 0) {
            v->v360.x = func_00388960(func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y)) * 10.0f;
            v->v360.y = func_00388978(func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y)) * 10.0f;
            v->v360.z = 0.0f;
            vec_add_ab(&v->v360, &v->v360, &m->pos);
            v->x308 = func_00388A28(D_001A4BE0.pos.x - v->v360.x, D_001A4BE0.pos.y - v->v360.y);
            v->x300 = b;
            if (m->b43 != 13) {
                func_003BE4F0(m, 13, 0, 20);
            }
        } else if (v->x31C == 0x12C) {
            v->v360 = m->pos;
            v->x308 = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
            v->x300 = 0;
            if (m->b43 != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
        } else if (m->b43 == 2 && func_L01_0044AF40(m, 78.0f) != 0) {
            v->x300 = 0;
            if (m->b43 != 0) {
                func_003BE4F0(m, 0, 0, 10);
            }
        }
        func_L23_003B22B0(m, &v->v360, v->x308, v->x300);
        break;
    }
    case 2: {
        f32 d1, d2, a, b, c, s;
        Node_3B0200 *n;
        if (func_L01_00452EC8(m) != 0 && m->b43 != 4) {
            func_003BE4F0(m, 4, 0, 6);
        }
        d1 = func_L01_0040C040(&v->v360, &D_001A4BE0.pos);
        d2 = func_L01_0040C040(&m->pos, &D_001A4BE0.pos);
        if (d1 < 6400.0f) {
            vec_sub_ab(&w[0], &D_001A4BE0.pos, &D_L23_001DF2C0[v->x320].pos);
            a = func_00388A28(w[0].x, w[0].y);
            vec_sub_ab(&w[1], &m->pos, &D_L23_001DF2C0[v->x320].pos);
            b = func_00388A28(w[1].x, w[1].y);
            if (func_00389468(b, a) < 0.0f) {
                c = func_003893C8(a, 2.0943952f);
            } else {
                c = func_00389380(a, 2.0943952f);
            }
            v->v360.x = func_00388960(c) * (100.0f - func_00388770(&w[0]));
            v->v360.y = func_00388978(c) * (100.0f - func_00388770(&w[0]));
            v->v360.z = 0.0f;
            vec_add_ba(&v->v360, &v->v360, &D_L23_001DF2C0[v->x320].pos);
        }
        if (d2 < 900.0f) {
            if (m->b43 != 6) {
                func_003BE4F0(m, 6, 0, 30);
            }
            v->x308 = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        } else if (v->f13C > v->fA4) {
            if (m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 30);
            }
            v->x308 = func_00388A28(v->v360.x - m->pos.x, v->v360.y - m->pos.y);
        } else {
            if (m->b43 != 4) {
                func_003BE4F0(m, 4, 0, 10);
            }
            v->x308 = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        }
        func_L23_003B22B0(m, &v->v360, v->x308, 3);
        break;
    }
    case 3:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 3) {
                func_003BE4F0(m, 3, 0, 10);
            }
            v->x300 = 0;
            v->x328 = 0.0f;
            v->x304 = 0;
            v->x30C = 0;
            v->x34C = 0;
            v->x334 = 0;
        }
        if (func_L01_0044AF40(m, 8.0f) != 0) {
            v->x300 = 3;
            v->x324 = D_L23_001DE3E0;
        }
        if (m->b42 == m->b43 && (m->b60 & 2)) {
            if (m->b43 != 4) {
                func_003BE4F0(m, 4, 0, 6);
            }
            if (m->b94 == 6) {
                func_L01_00441FB8(m, 6, -1);
            } else if (m->b94 == 5) {
                func_L01_00441FB8(m, 5, -1);
            } else {
                switch (m->b95) {
                case 1: func_L01_00441FB8(m, 1, -1); break;
                case 2: func_L01_00441FB8(m, 2, -1); break;
                case 3: func_L01_00441FB8(m, 7, -1); break;
                default: func_L01_00441FB8(m, 1, 1); break;
                }
            }
        }
        func_L23_003B22B0(m, &m->pos, m->fF8, v->x300);
        break;
    case 4: {
        f32 a;
        if (m->h96 >= 0xB5 || func_L01_00452EC8(m) != 0) {
            w[0] = m->pos;
            func_L23_003B2800(&v->v360, (u8 *)m, v->x310, w[0], 30.0f, 50.0f);
            m->h96 = 0;
            v->x34C = 0;
            v->x334 = 0;
        }
        a = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        v->x308 = a;
        if (m->b43 != 26) {
            if (func_L01_0040C040(&m->pos, &v->v360) < v->fA4 * v->fA4) {
                if (m->b43 != 26) {
                    func_003BE4F0(m, 26, 0, 6);
                }
            } else {
                v->x300 = 3;
                if (1.5707964f < fabs_asm(func_00389468(func_00388A28(v->v360.x - m->pos.x, v->v360.y - m->pos.y), v->x308))) {
                    if (m->b43 != 6) {
                        func_003BE4F0(m, 6, 0, 10);
                    }
                } else if (m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 10);
                }
            }
            func_L23_003B22B0(m, &v->v360, v->x308, 3);
        } else if (m->b42 == m->b43) {
            f32 f = func_L01_00436500(m);
            if (f <= 5.0f) {
                v->x328 = func_003BEB48(0.0f, v->f39C, 1.0f - (f / 5.0f) * (f / 5.0f));
                w[0] = m->pos;
                w[0].z = v->v370.z + v->x328;
                vec_sub_ba(&w[0], &w[0], &m->pos);
                func_L01_00457728(m, &w[0]);
            } else {
                func_L23_003B22B0(m, &m->pos, m->fF8, 0);
            }
            if (func_L01_0044AF40(m, 5.0f) != 0) {
                u8 *q = D_L23_001E1AC0;
                *(f32 *)(q + 0x20) = 0.3f;
                *(s32 *)(q + 0x28) = 0x28;
                *(s32 *)(q + 0x2C) = 0;
            }
            if (m->b60 & 2) {
                if (m->b43 != 0) {
                    func_003BE4F0(m, 0, 0, 6);
                }
                switch (m->b95) {
                case 1: func_L01_00441FB8(m, 1, -1); break;
                case 2: func_L01_00441FB8(m, 2, -1); break;
                case 3: func_L01_00441FB8(m, 7, -1); break;
                default: func_L01_00441FB8(m, 1, 1); break;
                }
            }
        } else {
            func_L23_003B22B0(m, &v->v360, a, 3);
        }
        break;
    }
    case 5:
        v->v360 = *(V4 *)&D_001A4BE0.pos;
        v->x308 = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        if (v->x300 == 3) {
            if (1.5707964f < fabs_asm(func_00389468(func_00388A28(v->v360.x - m->pos.x, v->v360.y - m->pos.y), v->x308))) {
                if (m->b43 != 6) {
                    func_003BE4F0(m, 6, 0, 10);
                }
            } else if (m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 10);
            }
        } else if (v->h184 == 0 && m->h96 >= 0x3D) {
            func_L01_00441FB8(m, 3, -1);
        } else {
            v->x300 = 2;
            if (m->b43 != 20) {
                func_003BE4F0(m, 20, 0, 10);
            }
        }
        func_L23_003B22B0(m, &v->v360, v->x308, v->x300);
        if (func_L01_0040C040(&m->pos, &D_001A4BE0.pos) <= v->f32C * v->f32C) {
            func_L01_00441FB8(m, 7, -1);
        }
        break;
    case 6:
        if (v->x300 != 3) {
            func_L01_00441FB8(m, 3, -1);
            break;
        }
        if (func_L01_00452EC8(m) != 0) {
            f32 r, c;
            if (m->b43 != 6) {
                func_003BE4F0(m, 6, 0, 10);
            }
            v->v360.x = func_00388960(func_00389380(func_L01_00440918(0.0f, 1.0471976f), func_00388A28(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y))) * v->f32C;
            v->v360.y = func_00388978(func_00389380(func_L01_00440918(0.0f, 1.0471976f), func_00388A28(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y))) * v->f32C;
            v->v360.z = 0.0f;
            vec_add_ab(&v->v360, &v->v360, &D_001A4BE0.pos);
            v->x308 = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        }
        func_L23_003B22B0(m, &v->v360, v->x308, 3);
        if (func_L01_0040C040(&m->pos, &v->v360) <= v->fA4 * v->fA4 || m->h96 >= 0x12D) {
            func_L01_00441FB8(m, 7, -1);
        }
        break;
    case 7: {
        f32 d;
        if (v->x304 == 0 && func_L01_00452EC8(m) != 0) {
            if (v->x300 == 3) {
                if (v->x334 != 0) {
                    if (m->b43 != 8) func_003BE4F0(m, 8, 0, 6);
                } else {
                    if (m->b43 != 4) func_003BE4F0(m, 4, 0, 6);
                }
            } else if (v->x334 != 0) {
                if (m->b43 != 15) func_003BE4F0(m, 15, 0, 6);
            } else {
                if (m->b43 != 0) func_003BE4F0(m, 0, 0, 6);
            }
        }
        func_L23_003B22B0(m, &m->pos, func_00388A28(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
        d = func_L01_0040C040(&m->pos, &D_001A4BE0.pos);
        if (v->x30C == 3 && d < 196.0f) {
            v->x304 = 0;
        }
        if (100.0f < d) {
            v->x38C = 0;
        }
        if (v->x30C == 1 && v->x38C >= 3) {
            v->x304 = 0;
            v->f32C = 30.0f;
            func_L01_00441FB8(m, 6, -1);
            break;
        }
        if (v->x304 <= 0) {
            if (D_L23_001DE314 < 0) {
                if (v->x300 == 3) {
                    if (v->x30C == 0) {
                        v->x304 = v->x398 ? D_L23_001DE3A8 : D_L23_001DE3A4;
                        v->x30C = 3;
                    } else {
                        func_L01_00441FB8(m, 4, -1);
                        v->x30C = 0;
                    }
                    break;
                } else if (d < 100.0f && v->x30C != 1) {
                    v->x304 = v->x398 ? func_0037E208(2, 4) : 2;
                    v->x30C = 1;
                } else if (196.0f <= d && v->x30C != 3) {
                    v->x304 = v->x398 ? D_L23_001DE3A0 : D_L23_001DE39C;
                    v->x30C = 3;
                } else if (v->x330 > 0) {
                    v->x304 = 2;
                    v->x30C = 1;
                } else if (v->x398 != 0) {
                    v->x304 = 1;
                    v->x30C = 2;
                } else {
                    v->x304 = 2;
                    v->x30C = 1;
            }
            } else {
                v->x30C = D_L23_001DE314;
            }
        }
        if (v->x30C == 3) {
            if (d < 196.0f) {
                v->f32C = 30.0f;
                if (v->x334 != 0) {
                    func_L01_00441FB8(m, 9, -1);
                } else {
                    func_L01_00441FB8(m, 6, -1);
                }
            } else if (2500.0f < d) {
                v->f32C = 30.0f;
                if (v->x334 != 0) {
                    func_L01_00441FB8(m, 9, -1);
                } else {
                    func_L01_00441FB8(m, 5, -1);
                }
            } else if (v->x334 == 0) {
                func_L01_00441FB8(m, 8, -1);
            } else {
                func_L01_00441FB8(m, 10, -1);
            }
        } else if (v->x30C == 2) {
            if (v->x334 != 0) {
                func_L01_00441FB8(m, 9, -1);
            } else if (d < 100.0f) {
                v->f32C = 16.0f;
                func_L01_00441FB8(m, 6, -1);
            } else if (324.0f < d) {
                v->f32C = 16.0f;
                func_L01_00441FB8(m, 5, -1);
            } else if (v->x300 == 3) {
                func_L01_00441FB8(m, 4, -1);
            } else {
                func_L01_00441FB8(m, 12, -1);
            }
        } else if (v->x30C == 1) {
            if (v->x334 != 0) {
                func_L01_00441FB8(m, 9, -1);
            } else if (100.0f < d) {
                v->f32C = 9.0f;
                func_L01_00441FB8(m, 5, -1);
            } else if (v->x300 == 3) {
                func_L01_00441FB8(m, 4, -1);
            } else {
                func_L01_00441FB8(m, 11, -1);
            }
        }
        break;
    }
    case 8:
        if (func_L01_00452EC8(m) != 0) {
            if (v->x300 == 3) {
                if (m->b43 != 7) func_003BE4F0(m, 7, 0, 6);
            } else {
                if (m->b43 != 14) func_003BE4F0(m, 14, 0, 6);
            }
        }
        if (m->b42 == m->b43 && (m->b60 & 2)) {
            if (v->x300 == 3) {
                if (m->b43 != 8) func_003BE4F0(m, 8, 0, 6);
            } else {
                if (m->b43 != 15) func_003BE4F0(m, 15, 0, 6);
            }
            v->x334 = 1;
            func_L01_00441FB8(m, 7, -1);
        }
        func_L23_003B22B0(m, &m->pos, func_00388A28(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
        break;
    case 9:
        if (func_L01_00452EC8(m) != 0) {
            if (v->x300 == 3) {
                if (m->b43 != 11) func_003BE4F0(m, 11, 0, 6);
            } else {
                if (m->b43 != 18) func_003BE4F0(m, 18, 0, 6);
            }
        }
        if (m->b42 == m->b43 && (m->b60 & 2)) {
            if (v->x300 == 3) {
                if (m->b43 != 4) func_003BE4F0(m, 4, 0, 6);
            } else {
                if (m->b43 != 0) func_003BE4F0(m, 0, 0, 6);
            }
            v->x334 = 0;
            func_L01_00441FB8(m, 7, -1);
        }
        func_L23_003B22B0(m, &m->pos, func_00388A28(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
        break;
    case 10:
        if (func_L01_00452EC8(m) != 0) {
            if (v->x300 == 3) {
                if (v->x304 & 1) {
                    if (m->b43 != 10) func_003BE4F0(m, 10, 0, 6);
                } else {
                    if (m->b43 != 9) func_003BE4F0(m, 9, 0, 6);
                }
            } else if (v->x304 & 1) {
                if (m->b43 != 17) func_003BE4F0(m, 17, 0, 6);
            } else {
                if (m->b43 != 16) func_003BE4F0(m, 16, 0, 6);
            }
            m->f48 = v->x398 ? 2.0f : 1.5f;
        }
        {
            f32 f = func_L01_00436500(m);
            if (f < 47.0f || 52.0f < f) {
                func_L23_003B22B0(m, &m->pos, func_00388A28(v->v170.x - m->pos.x, v->v170.y - m->pos.y), v->x300 == 3 ? 3 : 0);
            } else {
                func_L23_003B22B0(m, &m->pos, m->fF8, v->x300 == 3 ? 3 : 0);
            }
        }
        if (func_L01_0044AF40(m, 47.0f) != 0) {
            func_003BD9A0(m, (v->x304 & 1) ^ 1, &w[2]);
            w[0] = w[5];
            if (v->x300 == 3) {
                f32 l;
                vec_sub_ba(&w[1], &v->v170, &w[0]);
                l = func_003887A0(&w[1]);
                w[1].x = func_00388960(m->fF8) * l;
                w[1].y = func_00388978(m->fF8) * l;
                func_00388830(&w[1], &w[1], D_L23_001DE384);
            } else {
                w[1].x = func_00388960(m->fF8) * D_L23_001DE384;
                w[1].y = func_00388978(m->fF8) * D_L23_001DE384;
                w[1].z = 0.0f;
            }
            func_L23_003B9CE8((s32)m, (u128_t *)&w[0], (u128_t *)&w[1], D_L23_001DE388, D_L23_001DE38C, D_L23_001DE390);
            v->x34C = 0.0f;
        }
        if (func_L01_0044AF40(m, 64.0f) != 0) {
            v->x304 = v->x304 - 1;
            func_L01_00441FB8(m, 7, -1);
        }
        break;
    case 11: {
        f32 f;
        u8 *hero;
        if (func_L01_00452EC8(m) != 0) {
            if (v->x304 & 1) {
                if (m->b43 != 21) func_003BE4F0(m, 21, 0, 6);
            } else {
                if (m->b43 != 22) func_003BE4F0(m, 22, 0, 6);
            }
            m->f48 = v->x398 ? 2.0f : 1.5f;
        }
        f = func_L01_00436500(m);
        if (23.0f <= f && f <= 26.0f) {
            if (v->x304 & 1) {
                func_L01_00443790((u8 *)m, 4, D_L23_001DE3AC, D_L23_001DE3B0_003AFB88, D_L23_001DE3B4, 1.0f, 0, 1, 0);
            } else {
                func_L01_00443790((u8 *)m, 3, D_L23_001DE3AC, D_L23_001DE3B0_003AFB88, D_L23_001DE3B4, 1.0f, 0, 1, 0);
            }
        }
        hero = (u8 *)&D_001A4BE0;
        if (*(Moby_3AFB88 **)(hero + 0x2808) == m) {
            v->x38C++;
            *(s32 *)(hero + 0x2808) = 0;
            if (v->x38C >= 3) {
                v->x304 = 1;
            }
        }
        if (23.0f <= f && f <= 25.0f) {
            v->f110 = func_00388960(m->fF8) * (D_L23_001DE3B8 * (f - 23.0f) * 0.5f);
            v->f114 = func_00388978(m->fF8) * (D_L23_001DE3B8 * (f - 23.0f) * 0.5f);
            v->f118 = 0.0f;
        }
        if (func_L01_0044AF40(m, 43.0f) != 0) {
            m->f48 = 1.0f;
            v->x304 = v->x304 - 1;
            func_L01_00441FB8(m, 7, -1);
            v->x34C = 0.0f;
        }
        if (v->x398 != 0) {
            func_L23_003B22B0(m, &m->pos, func_00388A28(v->v170.x - m->pos.x, v->v170.y - m->pos.y), 0);
        } else {
            func_L23_003B22B0(m, &m->pos, m->fF8, 0);
        }
        break;
    }
    case 12: {
        s32 i, j;
        u8 *hero;
        if (func_L01_00452EC8(m) != 0) {
            m->bBC = 1;
            if (m->b43 != 23) func_003BE4F0(m, 23, 0, 6);
            D_001A73E8[0] = 0;
            v->x348 = 0;
        }
        if (m->b42 == m->b43 && (m->b60 & 2) && m->bBC == 1) {
            v->x330 = D_L23_001DE3D0;
            m->bBC = 2;
            if (m->b43 != 24) func_003BE4F0(m, 24, 0, 0);
        }
        if (m->bBC == 2) {
            f32 k = 15.0f;
            func_003BD9A0(m, 2, &w[0]);
            hero = (u8 *)&D_001A4BE0;
            for (i = 0; i < 4; i++) {
                f32 t = (f32)(D_L23_001DE3D0 - v->x330) / 60.0f;
                f32 r = (f32)((D_L23_001DECC0 + i * 4) % 16);
                f32 s, g;
                s = (1.0f < t ? r : t * r) / k;
                func_003886E8(&w[4], &w[0], D_L23_001DE3BC - D_L23_001DE3C0);
                w[4].z = 0.0f;
                vec_add_ab(&w[4], &w[4], &w[3]);
                w[5] = w[3];
                func_003BEB58(&w[4], &w[5], &w[4], s);
                g = func_003BEB48(1.0f, D_L23_001DE3C0, s);
                if (v->x348 == 0 &&
                    func_L01_00443648((u8 *)m, (u8 *)&w[4], D_L23_001DE3C4, 5, 1, 0, g, D_L23_001DE3C8, 0.0f) != 0 &&
                    *(Moby_3AFB88 **)(hero + 0x2808) == m) {
                    v->x348 = 1;
                    v->x330 -= 60;
                }
            }
            for (j = 0; j < D_L23_001DE3DC; j++) {
                f32 t, a, rad;
                w[4] = w[3];
                t = (f32)(D_L23_001DE3D0 - v->x330) / 20.0f;
                a = func_0037E250(0.0f, 1.0f < t ? 1.0f : t);
                rad = D_L23_001DE3D8;
                func_0037E2F0(&w[5], 0.0f, rad);
                w[5].x += w[0].x;
                w[5].y += w[0].y;
                func_00388830(&w[5], &w[5], D_L23_001DE3D4);
                func_L23_00453320(&w[4], &w[5], (a * 0.5f + 0.5f) * 4.0f, (s32)(a * 50.0f), func_0037E208(20, 30), func_0037E208(20, 30));
            }
            if (v->x330 <= 0) {
                m->bBC = 3;
                if (m->b43 != 25) func_003BE4F0(m, 25, 0, 6);
            }
        }
        if (m->b42 == m->b43 && (m->b60 & 2) && m->bBC == 3) {
            if (m->b43 != 0) func_003BE4F0(m, 0, 0, 6);
            v->x304 = v->x304 - 1;
            v->x330 = D_L23_001DE3CC;
            func_L01_00441FB8(m, 7, -1);
            v->x34C = 0.0f;
        }
        func_L23_003B22B0(m, &m->pos, m->fF8, 0);
        break;
    }
    case 13: {
        f32 f, c;
        if (func_L01_00452EC8(m) != 0) {
            if (v->x300 == 3) {
                if (m->b43 != 12) func_003BE4F0(m, 12, 0, 4);
            } else {
                if (m->b43 != 19) func_003BE4F0(m, 19, 0, 4);
                m->f48 = 2.0f;
            }
            v->x34C += v->f338 - v->f30;
            v->f338 = v->f30;
            v->x30C = -1;
            v->x304 = 0;
            if (m->b94 == 12) {
                v->x330 = D_L23_001DE3CC;
            }
        }
        c = v->f380 < D_L23_001DE37C ? v->f380 : D_L23_001DE37C;
        v->f380 -= c;
        w[0].x = func_00388960(v->f384) * c;
        w[0].y = func_00388978(v->f384) * c;
        w[0].z = 0.0f;
        func_L01_00457728(m, &w[0]);
        w[1].x = func_00388960(v->f384) * D_L23_001DE368;
        w[1].y = func_00388978(v->f384) * D_L23_001DE368;
        w[1].z = 0.0f;
        vec_add_ba(&w[1], &w[1], &m->pos);
        w[1].z += D_L23_001DE368;
        func_L01_00443648((u8 *)m, (u8 *)&w[1], D_L23_001DE3B0_003AFB88, 0, 1, 0, D_L23_001DE368, 100.0f, 1.0f);
        v->x33C = D_L23_001DECC0 + 2;
        if ((m->b43 == 19 && func_L01_0044AF40(m, 18.0f) != 0) || (m->b60 & 2)) {
            m->f48 = 1.0f;
            switch (m->b95) {
            case 1: func_L01_00441FB8(m, 1, -1); break;
            case 2: func_L01_00441FB8(m, 2, -1); break;
            case 3:
                if (v->x300 == 3) {
                    func_L01_00441FB8(m, 7, -1);
                } else if (v->x34C >= D_L23_001DE380) {
                    v->f32C = 30.0f;
                    func_L01_00441FB8(m, 6, -1);
                } else {
                    func_L01_00441FB8(m, m->b94, -1);
                }
                break;
            }
        }
        func_L23_003B22B0(m, &m->pos, m->fF8, v->x300 == 3 ? 3 : 0);
        break;
    }
    case 14:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 27) func_003BE4F0(m, 27, 0, 10);
        } else if (func_L01_0044AF40(m, 84.0f) != 0) {
            m->f48 = 0.0f;
            func_L01_003A81A0((u8 *)m);
        }
        break;
    }
    func_L23_003B2000(m);
}
/* localdecomp:end func_L23_003AFB88 */
