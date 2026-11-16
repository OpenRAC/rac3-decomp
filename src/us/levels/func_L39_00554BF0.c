#include "common.h"

/* NTSC-U counterpart of func_L39_00555548 (src/levels/shared/L39_00554E60.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00554E60;
typedef struct { u8 pad0[0x10]; s32 f10; } C_00554E60;
typedef struct {
    u8 pad0[0x10];
    V_00554E60 pos;      
    u8 pad20[0x4];
    C_00554E60 *f24;     
    u8 pad28[0x70];
    s32 f98;             
    u8 pad9c[0xE];
    s16 hAA;             
} M_00554E60;
typedef struct {
    s32 flags;
    u8 pad4[0x2D4];
    u32 *f2D8;           
    u8 pad2dc[0x34];
    f32 f310;            
} E_00554E60;
typedef struct {
    u8 pad0[0x24CC];
    u32 f24CC;
    s32 f24D0;
} H_00554E60;
extern E_00554E60 *func_L39_0061B038(void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_003F9498(void *, f32, s32, void *);

/* localdecomp:start func_L39_00554BF0 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00555548;

struct O_00555548;
typedef struct { u8 pad0[0x7C]; f32 f7C; s32 s80; s32 s84; u8 pad88[8]; s32 s90; u8 pad94[8]; s32 s9C; s32 sA0; f32 fA4; s32 sA8; } A_00555548;
typedef struct { u8 pad0[0x240]; struct O_00555548 *p240; u8 pad244[0x254 - 0x244]; s32 i254; u8 pad258[0x27B - 0x258]; u8 b27B; } S2530_00555548;
typedef struct { u8 pad0[0x1A4]; s32 i1A4; u8 pad1A8[0x1D4 - 0x1A8]; s32 i1D4; } S2534_00555548;
typedef struct {
    u8 pad0[0x20];
    u8 m20[0x80];
    V4_00555548 vA0;
    V4_00555548 vB0;
    u8 padC0[0x60];
    V4_00555548 v120;
    u8 pad130[0x1A0A - 0x130];
    u8 b1A0A;
    u8 pad1A0B[9];
    u8 b1A14;
    u8 pad1A15[0x2458 - 0x1A15];
    s32 i2458;
    u8 pad245C[0x24CC - 0x245C];
    u32 i24CC;
    s32 i24D0;
    u8 pad24D4[0x2530 - 0x24D4];
    S2530_00555548 *p2530;
    S2534_00555548 *p2534;
    u8 pad2538[0x2548 - 0x2538];
    s32 i2548;
    u8 pad254C[0x4D30 - 0x254C];
    V4_00555548 v4D30;
    u8 pad4D40[0x4D68 - 0x4D40];
    f32 f4D68;
} W_00555548;
typedef struct O_00555548 {
    u8 pad0[0x10];
    V4_00555548 pos;
    u8 state;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[0x43 - 0x32];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[7];
    A_00555548 *a68;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x96 - 0x70];
    u16 h96;
    u8 pad98[0xA8 - 0x98];
    u8 bA8;
    u8 padA9[0xF0 - 0xA9];
    V4_00555548 vF0;
} O_00555548;
typedef struct { u8 pad0[0xAA]; s16 hAA; } X_00555548;
typedef struct S17_00555548 { u32 i0; u8 pad4[0x10]; struct { u8 pad[0x1C]; s32 (*f1C)(struct S17_00555548 *, s32); } *vt14; } S17_00555548;
typedef struct { u8 pad0[0x20]; X_00555548 *p20; } S18_00555548;
typedef struct { u8 pad0[0x2D8]; s32 *p2D8; u8 pad2DC[0x310 - 0x2DC]; f32 f310; } E_00555548;

__asm__(".extern D_L39_0024B3A4, 4");
__asm__(".extern D_L39_0024B3A8, 4");
__asm__(".extern D_L39_0024B3AC, 4");
__asm__(".extern D_L39_0024B384, 4");
__asm__(".extern D_L39_0024B388, 4");
__asm__(".extern D_L39_0024B39C, 4");
__asm__(".extern D_L39_0024B3A0, 4");
__asm__(".extern D_L39_0024B37C, 4");
__asm__(".extern D_L39_0024B380, 4");
__asm__(".extern D_L39_0024B394_00554BF0, 4");
__asm__(".extern D_L39_0024B398, 4");
__asm__(".extern D_L39_0024B378, 4");
__asm__(".extern D_L39_0024B38C_00554BF0, 4");
__asm__(".extern D_L39_0024B390_00554BF0, 4");
__asm__(".extern D_L39_0024CF20, 32");
extern W_00555548 *D_L39_0024CF20[1];
extern u8 D_L39_0024DF80[];
extern X_00555548 *D_L39_0025F858[];
extern f32 D_L39_0024B3A4;
extern f32 D_L39_0024B3A8;
extern f32 D_L39_0024B3AC;
extern f32 D_L39_0024B384;
extern f32 D_L39_0024B388;
extern f32 D_L39_0024B39C;
extern f32 D_L39_0024B3A0;
extern f32 D_L39_0024B37C;
extern f32 D_L39_0024B380;
extern f32 D_L39_0024B394_00554BF0;
extern f32 D_L39_0024B398;
extern s32 D_L39_0024B378;
extern s32 D_L39_0024B38C_00554BF0;
extern s32 D_L39_0024B390_00554BF0;

extern void func_L39_00555C28(void *, s32, s32);
extern s32 func_L39_00554508(M_00554E60 *, V_00554E60 *, H_00554E60 *, f32, f32, f32, f32);
extern S18_00555548 *func_L01_00444358(void *, s32, s32);
extern S17_00555548 *func_L39_0061A728(void *);
extern void func_L01_00444070(void *, f32);
extern s32 func_00388398(void *);
extern void func_L39_0061E358(void *, s32, s32, s32);
extern void func_00388BF0(void *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L39_005C2098(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_L39_00635C68(void *);
extern void func_L39_00630530(void *, s32, f32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_00630DD8(void *, f32, f32);
extern void func_L39_00630E28(void *, f32);
extern s32 func_L01_00452EC8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00389468(f32, f32);
extern void func_L01_00445558(void *, s32, f32, f32);
extern void func_L39_0062DD00(void *);
extern void func_L39_00638860(void *);

void func_L39_00554BF0(O_00555548 *o) {
    A_00555548 *a = o->a68;
    W_00555548 *w = D_L39_0024CF20[a->s9C];
    V4_00555548 v0;
    V4_00555548 v1;
    f32 d;
    s32 r;
    u8 t2;

    if (a->s84 > 0 || w == 0 || w->i2458 == 0) {
        func_L39_00555C28(o, a->s84 == 2, a->s84 == 3);
        return;
    }
    if (w->b1A14 != 0) {
        S18_00555548 *s18 = func_L01_00444358(o, 0x0B030001, 0);
        if (s18 != 0) {
            S17_00555548 *s17 = (s18->p20 != 0) ? func_L39_0061A728(s18->p20) : 0;
            if (s17 == 0 || s17->vt14->f1C(s17, w->i2548) == 0 || (s18->p20 != 0 && s18->p20->hAA == 0x18AB)) {
                w->i24CC = (s17 != 0) ? s17->i0 : 0xFFFFFFFF;
                w->i24D0 = -1;
                func_L39_0061E358(w, 0, 1, 0);
                return;
            }
        }
    }
    o->bA8 = 0xFF;
    func_L01_00444070(o, 0.5f);
    func_00388398(&a->s80);
    if (a->s80 == 0) {
        if (w != 0 && w->b1A14 != 0) {
            func_L39_0061E358(w, 1, 1, 0);
            return;
        }
    }
    t2 = w->b1A14;
    if (t2 != 0) {
        V4_00555548 *p = &o->pos;
        *(u128_t *)&w->vA0 = *(u128_t *)p;
        *(u128_t *)&w->vB0 = *(u128_t *)&o->vF0;
        w->b1A0A = 2;
        func_00388BF0(w->m20, &w->vB0);
        if (o->b31 != 0) {
            d = func_L01_0040C018(D_L39_0024DF80, p);
            if (d < 144.0f) {
                func_L01_00444188(o);
                o->b6F = 0xB;
            }
        }
    } else {
        if (o->b31 != 0) {
            d = func_L01_0040C018(D_L39_0024DF80, &o->pos);
            if (d < 144.0f) {
                func_L01_00444188(o);
                o->b6F = 0xB;
            }
        }
    }
    switch (o->state) {
    case 0:
        d = o->pos.z - func_003BE7F0(&o->pos, 0, o, 0.5f);
        if (D_L39_0024B384 < d) {
            a->f7C = 0.0f;
            func_L01_00441FB8(o, 4, -1);
            if (d > 0.5f) {
                if (o->b43 != 6) {
                    func_003BE4F0(o, 6, 0, 10);
                }
            }
        } else {
            func_L01_00441FB8(o, 1, -1);
        }
        break;
    case 1:
        o->f48 = 1.0f;
        if (w->p2534->i1D4 == 0) {
            func_L01_00441FB8(o, 2, -1);
            a->s90 = func_L39_005B24C8(400, 600);
            if (o->b43 != 3) {
                func_003BE4F0(o, 3, 0, 4);
            }
            o->f48 = D_L39_0024B39C;
        } else {
            r = func_L39_005C2098(0x40, 0);
            if (w->p2534->i1A4 & r) {
                func_L01_00441FB8(o, 3, -1);
                a->fA4 = o->pos.z + D_L39_0024B388;
                a->f7C = D_L39_0024B37C * 0.01666666753590107f;
                a->sA0 = D_L39_0024B38C_00554BF0;
                if (o->b43 != 6) {
                    func_003BE4F0(o, 6, 0, 10);
                }
                o->f48 = D_L39_0024B3A0;
            } else if (w->p2534->i1A4 & 0xA0) {
                func_L01_00441FB8(o, 5, -1);
                a->s90 = func_L39_005B24C8(180, 360);
                if (o->b43 != 5) {
                    func_003BE4F0(o, 5, 0, 6);
                }
            } else if (o->b60 & 2) {
                f32 f20 = 0.0f;
                f32 f21 = func_L39_005B2510(f20, 150.0f);
                if (f20 <= f21 && f21 < 50.0f) {
                    if (o->b43 != 0) {
                        func_003BE4F0(o, 0, 0, 10);
                    }
                }
                if (50.0f <= f21 && f21 < 100.0f) {
                    if (o->b43 != 1) {
                        func_003BE4F0(o, 1, 0, 10);
                    }
                }
                if (150.0f <= f21 && f21 < 150.0f) {
                    if (o->b43 != 2) {
                        func_003BE4F0(o, 2, 0, 10);
                    }
                }
            }
        }
        *(u128_t *)&v0 = *(u128_t *)&o->pos;
        v0.z += 0.5f;
        if (func_L01_003F9498(&v0, D_L39_0024B3A8, 4, o) != 0) {
            X_00555548 *x = D_L39_0025F858[0];
            if (x != 0) {
                s16 id = x->hAA;
                if (id == 0x107C || id == 0x107E) {
                    E_00555548 *e = (E_00555548 *)func_L39_0061B038(x);
                    if (fabs_asm(e->f310) > 0.05000000447034836f) {
                        s32 *p = e->p2D8;
                        w->i24CC = (p != 0) ? *p : -1;
                        w->i24D0 = -1;
                        func_L39_0061E358(w, 0, 1, 0);
                    }
                }
            }
        }
        break;
    case 5:
        func_L39_00635C68(w);
        if (o->b60 & 2) {
            func_L01_00441FB8(o, 1, -1);
            if (o->b43 != 0) {
                func_003BE4F0(o, 0, 0, 4);
            }
        }
        break;
    case 3:
        func_00388398(&a->sA0);
        if (a->sA0 <= 0) {
            if (w->p2534->i1A4 & 0x40) {
                a->sA0 = D_L39_0024B38C_00554BF0;
                o->f48 = D_L39_0024B3A0;
                a->f7C += D_L39_0024B37C * 0.01666666753590107f;
            }
        }
        if (D_L39_0024B390_00554BF0 < o->h96) {
            a->f7C -= D_L39_0024B380 * 0.00027777778450399637f;
        }
        if (a->f7C < -0.11666667461395264f) {
            a->f7C = -0.11666667461395264f;
        }
        if (D_L39_0024B378 < o->h96) {
            func_L01_00441FB8(o, 4, -1);
            if (o->b43 != 6) {
                func_003BE4F0(o, 6, 0, 10);
            }
        }
        func_L39_00630530(w, 0, D_L39_0024B394_00554BF0 * 0.01666666753590107f);
        func_L39_00630AC0(w, 0, 0.05000000074505806f, 0.25f, 0.1163552924990654f);
        o->vF0.z = w->vB0.z;
        func_L39_00630DD8(w, D_L39_0024B398 * 0.010277777910232544f, D_L39_0024B398 * 0.008333333767950535f);
        func_L39_00630E28(w, 99999.0f);
        vec_add_ba(&v0, &o->pos, &w->v120);
        v0.z += a->f7C;
        if (a->fA4 < v0.z) {
            v0.z = a->fA4;
            if (0.0f < a->f7C) {
                a->f7C = 0.0f;
            }
        }
        r = func_L39_00554508((M_00554E60 *)o, (V_00554E60 *)&v0, (H_00554E60 *)w, D_L39_0024B3A8, D_L39_0024B3AC, D_L39_0024B3A4, a->fA4);
        if (r < 3) {
            if (r == 2) {
                if (o->h96 >= 11) {
                    func_L01_00441FB8(o, 1, -1);
                    if (o->b43 != 0) {
                        func_003BE4F0(o, 0, 0, 10);
                    }
                }
            }
        } else {
            func_L39_0061E358(w, 0, 1, r == 4);
            return;
        }
        break;
    case 2:
        if (func_L01_00452EC8(o) != 0) {
            a->sA8 = func_L39_005B24C8(40, 200);
        }
        a->sA8 = a->sA8 - 1;
        if (o->b60 & 2) {
            if (a->sA8 <= 0) {
                if (o->b43 == 4) {
                    func_003BE4F0(o, 3, 0, 5);
                } else {
                    func_003BE4F0(o, 4, 0, 5);
                }
                a->sA8 = func_L39_005B24C8(40, 200);
            }
        }
        o->f48 = D_L39_0024B39C;
        if (w->p2534->i1D4 != 0) {
            func_L01_00441FB8(o, 1, -1);
            a->s90 = func_L39_005B24C8(400, 600);
        }
        a->f7C = -0.03333333507180214f;
        r = func_L39_005C2098(0x40, 0);
        if (w->p2534->i1A4 & r) {
            func_L01_00441FB8(o, 3, -1);
            a->fA4 = o->pos.z + D_L39_0024B388;
            a->f7C = D_L39_0024B37C * 0.01666666753590107f;
            a->sA0 = D_L39_0024B38C_00554BF0;
            if (o->b43 != 6) {
                func_003BE4F0(o, 6, 0, 10);
            }
            o->f48 = D_L39_0024B3A0;
        } else if (w->p2534->i1A4 & 0xA0) {
            func_L01_00441FB8(o, 5, -1);
            if (o->b43 != 5) {
                func_003BE4F0(o, 5, 0, 6);
            }
        }
        func_L39_00630530(w, 0, D_L39_0024B394_00554BF0 * 0.01666666753590107f);
        func_L39_00630AC0(w, 0, 0.05000000074505806f, 0.25f, 0.1163552924990654f);
        o->vF0.z = w->vB0.z;
        func_L39_00630DD8(w, D_L39_0024B398 * 0.010277777910232544f, D_L39_0024B398 * 0.008333333767950535f);
        func_L39_00630E28(w, 99999.0f);
        vec_add_ba(&v0, &o->pos, &w->v120);
        v0.z += a->f7C;
        *(u128_t *)&v1 = *(u128_t *)&o->pos;
        r = func_L39_00554508((M_00554E60 *)o, (V_00554E60 *)&v0, (H_00554E60 *)w, D_L39_0024B3A8, D_L39_0024B3AC, D_L39_0024B3A4, -1.0f);
        if (r >= 3) {
            func_L39_0061E358(w, 0, 1, r == 4);
            return;
        }
        if (a->f7C < 0.0f) {
            if (r == 0 || r == 1) {
                d = o->pos.z - func_003BE7F0(&o->pos, 0, o, 0.5f);
                if (D_L39_0024B384 < d) {
                    a->f7C = 0.0f;
                    func_L01_00441FB8(o, 4, -1);
                    if (d > 0.5f) {
                        if (o->b43 != 6) {
                            func_003BE4F0(o, 6, 0, 10);
                        }
                    }
                }
            }
        }
        break;
    case 4:
        a->f7C -= 0.0027222223579883575f;
        if (a->f7C < 1.0f) {
            if (o->b43 != 6) {
                func_003BE4F0(o, 6, 0, 10);
            }
        }
        func_L39_00630530(w, 0, D_L39_0024B394_00554BF0 * 0.01666666753590107f);
        func_L39_00630AC0(w, 0, 0.05000000074505806f, 0.25f, 0.1163552924990654f);
        o->vF0.z = w->vB0.z;
        func_L39_00630DD8(w, D_L39_0024B398 * 0.010277777910232544f, D_L39_0024B398 * 0.008333333767950535f);
        func_L39_00630E28(w, 99999.0f);
        vec_add_ba(&v0, &o->pos, &w->v120);
        v0.z += a->f7C;
        r = func_L39_00554508((M_00554E60 *)o, (V_00554E60 *)&v0, (H_00554E60 *)w, D_L39_0024B3A8, D_L39_0024B3AC, D_L39_0024B3A4, -1.0f);
        if (r >= 3) {
            func_L39_0061E358(w, 0, 1, r == 4);
            return;
        }
        if (r == 2) {
            a->f7C = 0.0f;
            func_L01_00441FB8(o, 0, -1);
        }
        break;
    }
    if (o->state == 1) {
        d = o->pos.z - func_003BE7F0(&o->pos, 0, o, 0.5f);
        if (D_L39_0024B384 < d) {
            a->f7C = 0.0f;
            func_L01_00441FB8(o, 4, -1);
            if (d > 0.5f) {
                if (o->b43 != 6) {
                    func_003BE4F0(o, 6, 0, 10);
                }
            }
        }
    }
    if (w->b1A14 == 0) {
        vec_sub_ba(&v1, &w->v4D30, &o->pos);
        func_003886E8(&v1, &v1, 0.125f);
        vec_add_ab(&o->pos, &o->pos, &v1);
        d = func_00389468(o->vF0.z, w->f4D68);
        {
            f32 k = 15.0f;
            if (d > 0.7853982f) {
                k = 120.0f;
            }
            func_L01_00445558(&o->vF0.z, 0, w->f4D68, k * 0.017453292f * 0.01666666753590107f);
        }
    }
    o->h96 = o->h96 + 1;
    if (w != 0) {
        *(u128_t *)&w->vA0 = *(u128_t *)&o->pos;
        *(u128_t *)&w->vB0 = *(u128_t *)&o->vF0;
        func_L39_0062DD00(w);
        func_L39_00638860(w);
        w->p2530->p240 = o;
        w->p2530->i254 = 0;
        w->p2530->b27B = 1;
    }
}
/* localdecomp:end func_L39_00554BF0 */
