#include "common.h"

/* NTSC-U counterpart of func_L39_0054E010 (src/levels/shared/L39_0054D5F8.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern s32 func_00388398(void *);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern f32 func_00388A28(f32, f32);

/* localdecomp:start func_L39_0054D6F8 */
#include "vu0.h"
typedef int Q_0054E010 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0054E010;

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_0054E010;

typedef struct {
    u8 p0[0x10C]; f32 f10C; u8 p110[0x134 - 0x110]; f32 f134; u8 p138[0x13C - 0x138]; f32 f13C;
} Pad_0054E010;

typedef struct O_0054E010 {
    u8 p0[0x14];
    void **vt;
    u8 p18[0x170 - 0x18];
    Q_0054E010 q170;
    u8 p180[0x3B0 - 0x180];
    V_0054E010 v3B0;
    u8 p3C0[0x3E0 - 0x3C0];
    s32 w3E0;
    u8 p3E4[0x474 - 0x3E4];
    s32 w474;
    u8 p478[0x1078 - 0x478];
    s32 w1078;
    u8 p107C[0x122C - 0x107C];
    s32 w122C;
    u8 p1230[0x1250 - 0x1230];
    f32 f1250;
    u8 p1254[0x1280 - 0x1254];
    u16 h1280;
    u8 p1282[0x12C0 - 0x1282];
    f32 f12C0;
    u8 p12C4[0x1338 - 0x12C4];
    s32 w1338;
    s32 w133C;
    u8 p1340[0x19E4 - 0x1340];
    u8 b19E4;
    u8 p19E5;
    u8 b19E6;
    u8 p19E7[0x1A07 - 0x19E7];
    u8 b1A07;
    u8 b1A08;
    u8 p1A09[0x1A0D - 0x1A09];
    u8 b1A0D;
    u8 p1A0E[0x1A14 - 0x1A0E];
    u8 b1A14;
    u8 p1A15[0x1A40 - 0x1A15];
    u8 b1A40[0x2470 - 0x1A40];
    s32 w2470;
    u8 p2474[0x24C9 - 0x2474];
    u8 b24C9;
    u8 p24CA[0x24FE - 0x24CA];
    u8 b24FE;
    u8 p24FF;
    u8 b2500;
    u8 p2501[0x2534 - 0x2501];
    Pad_0054E010 *pad;
    u8 p2538[0x2544 - 0x2538];
    s32 w2544;
} O_0054E010;

typedef struct {
    s16 h0;
    u8 p2[2];
    f32 f4;
    f32 f8;
    f32 fC;
    s32 w10;
    s32 w14;
    u8 p18[0x20 - 0x18];
    s32 w20;
    s32 w24;
    u8 p28[0x2C - 0x28];
    s16 h2C;
    s16 h2E;
    s32 w30;
    u8 p34[0x3C - 0x34];
    O_0054E010 *o;
    V_0054E010 v40;
} M_0054E010;

typedef struct {
    u8 p0[0x10];
    V_0054E010 pos;
    u8 b20;
    u8 p21[0x31 - 0x21];
    u8 b31;
    u8 p32[2];
    u16 h34;
    u8 p36[0x42 - 0x36];
    u8 b42;
    u8 b43;
    u8 p44[0x60 - 0x44];
    u8 b60;
    u8 p61[0x68 - 0x61];
    M_0054E010 *m;
    u8 p6C[0xD0 - 0x6C];
    V_0054E010 vD0;
} Self_0054E010;

typedef struct {
    u8 p0[0x26];
    u8 b26;
    u8 p27[0x2C - 0x27];
    u32 w2C;
    f32 x30, y30, z30;
    f32 x3C, y3C, z3C;
    u8 p48[0x50 - 0x48];
} S_0054E010;

typedef struct {
    u8 p0[0xD0];
    u8 bD0;
    u8 pD1[0xDC - 0xD1];
    void *owner;
} Slot_0054E010;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    V_0054E010 v10;
} Info_0054E010;

extern u8 D_L39_004998A0[];
extern f32 D_L39_0024B1B8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B1C8_0054D6F8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B1D8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B1E8_0054D6F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B1B8, 4");
__asm__(".extern D_L39_0024B1C8_0054D6F8, 4");
__asm__(".extern D_L39_0024B1D8, 4");
__asm__(".extern D_L39_0024B1E8_0054D6F8, 4");
extern f32 D_L39_0024B810_0054D6F8[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B820[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B830[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B840_0054D6F8[] __attribute__((section(".sdata")));
extern s32 D_001D7AA8_sda;
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern s32 D_L39_0024BE14[2];
extern f32 D_L39_0025D870[];
typedef struct { u8 pA4[0xA4]; u8 flags[0x100]; } Tab_0054E010;
extern Tab_0054E010 D_001A5990;
extern u8 D_L39_001FE1A0[];
extern u8 D_L39_00470700[];
extern Info_0054E010 D_L39_002668C0_0054D6F8[];

extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern void func_0037E568(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004AD960(s32);
extern void func_L01_00402768(void *, void *);
extern void func_L39_0054F190(u8 *);
extern s32 func_L39_0061E558(u8 *, s32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L39_00637548(void *);
extern u32 func_L39_005FD580(void *, void *, s32, f32);
extern f32 func_00388A28(f32, f32);
extern void func_L39_00619D58(u8 *, u8 **);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F0988(s32);
extern s32 func_L39_00670988(void *p, s32 a1, s32 a2, s32 a3);
extern void func_L39_0061F5C0(void *, s32);
extern s32 func_L01_003F0118(void *, void *);
extern u8 *func_L39_0061AA60(s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_003887C8(void *, void *);
extern s32 func_L39_0054FD10(u8 *, f32 *);
extern u8 *func_0037E0B8(void *);
extern void func_L01_0050D180(void *, void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern f32 func_00388730(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L39_0054EBC8(u8 *, u8 *, s32, s32, s32);
extern void func_L01_003F0338(s32, void *);
extern s32 func_L01_0040BB20(void *);
extern void func_L01_00421FE0(s32);
extern s32 func_L39_0059CE28(void *, s32, f32, f32);

/* the obfuscated byte at p, decoded (key table D_L39_004998A0) */
static __inline__ u32 decode_0054E010(u8 *p) {
    Buf_0054E010 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

/* player state (o->b19E4, decoded) == 0x1D */
static __inline__ s32 respawning_0054E010(O_0054E010 *o) {
    Buf_0054E010 buf;
    u8 *p = &o->b19E4;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;
    u32 r;

    if (*p == 0) {
        r = 0;
    } else {
        n = *p;
        k = ((u32)p - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)p;
        r = buf.w[1] ^ buf.w[0];
        buf.w[1] = r;
    }
    return (r ^ 0x1D) == 0;
}

/* the player is on this console */
static __inline__ s32 isLocal_0054E010(O_0054E010 *o) {
    return o->b1A14;
}

/* set the local player's camera field of view */
static __inline__ void camera_0054E010(O_0054E010 *o, f32 fov, f32 speed, f32 b) {
    if (o->b1A14 != 0) {
        func_0037E568(o->b24C9, 0, 3, fov, speed, b, 0.0f);
    }
}

static __inline__ void vset_0054E010(V_0054E010 *v, f32 *src) {
    v->x = src[0];
    v->y = src[1];
    v->z = src[2];
    v->w = 0.0f;
}

void func_L39_0054D6F8(u8 *arg0) {
    Self_0054E010 *self = (Self_0054E010 *)arg0;
    V_0054E010 pos0;
    M_0054E010 *m;
    O_0054E010 *o;
    u8 *ent;
    u8 *obj;
    O_0054E010 *hero;
    u8 *q;
    f32 dist;
    f32 f;
    f32 k;
    s32 snd;
    s32 busy;
    s32 idx;
    s32 flag;
    s32 res;
    O_0054E010 *veh;
    s32 fl;
    s32 flag2;

    m = self->m;
    o = m->o;
    if (self->b42 == self->b43 && (self->b60 & 2)) {
        func_L01_00441E00(arg0, 1, 0, 2, 0);
    }
    if (o != 0 && o->w474 == 3) {
        if (self->b20 == 0) {
            return;
        }
        idx = o->b24C9;
        if (isLocal_0054E010(o)) {
            D_L39_0024B820[idx] = D_L39_0024B1B8[idx];
            D_L39_0024B830[idx] = D_L39_0024B1C8_0054D6F8[idx];
            D_L39_0024B840_0054D6F8[idx] = D_L39_0024B1D8[idx];
            D_L39_0024B810_0054D6F8[idx] = D_L39_0024B1E8_0054D6F8[idx];
            func_0037E568(idx, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
            D_001D7AA8_sda = 0xE0;
            func_L01_004AD960(1);
        }
        if (m->w10 >= 0) {
            func_L01_00421FE0(m->w10);
        }
        m->w10 = -1;
        return;
    }
    pos0 = self->pos;
    if (o != 0 && respawning_0054E010(o) && self->b20 != 0) {
        if (isLocal_0054E010(o)) {
            self->b31 = 0;
            self->h34 |= 1;
            func_L01_00402768(func_L39_0054F190, arg0);
            if (*D_L39_002412A0 == 1) {
                D_L39_0024BE14[1] = 1;
            }
        }
        if (o->b1A08 == 0 && o->f1250 >= 1.0f) {
            m->h2C = 1;
            m->w30 = o->w122C;
        } else {
            m->h2C = 0;
            m->w30 = 0;
        }
        if (o->w2470 == 0 && m->h2C != 0) {
            m->h2E++;
            if (m->h2E >= 0x1F) {
                m->h2E = 0;
            }
            if (m->f4 <= 0.0f && func_L39_0061E558((u8 *)o, -1) != 0 && m->h2E >= 6 && isLocal_0054E010(o)) {
                func_L01_003F4D78(o->b24C9, self, 0x200000FF, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f,
                                  40.0f, 40.0f);
            }
        }
    } else if (o != 0) {
        if (func_L39_00637548(o) != 0) {
            u32 c = func_L39_005FD580(&o->w1338, &o->w133C, 0, 150.0f);

            if (isLocal_0054E010(o)) {
                func_L01_003F4D78(o->b24C9, self, c, 0, 0x20, -1, 4, 0.5f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f,
                                  40.0f);
            }
        }
        if (o != 0 && isLocal_0054E010(o)) {
            D_L39_0024BE14[1] = 0;
        }
    }
    switch (self->b20) {
    case 0:
        m->h0 = 0;
        m->f4 = 0.36666667f;
        self->b20 = 2;
        {
            f32 t = func_00388A28(1.0f, D_L39_0025D870[0]) * 2.0f;

            m->f8 = t;
            m->fC = t + (0.17453292f - t) * 0.25f;
        }
        func_L39_00619D58(arg0, (u8 **)&m->o);
        o = m->o;
        if (isLocal_0054E010(o)) {
            s32 n = o->b24C9;

            D_L39_0024B1B8[n] = D_L39_0024B820[n];
            D_L39_0024B1C8_0054D6F8[n] = D_L39_0024B830[n];
            D_L39_0024B1D8[n] = D_L39_0024B840_0054D6F8[n];
            D_L39_0024B1E8_0054D6F8[n] = D_L39_0024B810_0054D6F8[n];
        }
        m->w14 = 0;
        m->w10 = -1;
        m->w20 = -1;
        m->w24 = -1;
        m->h2C = 0;
        m->h2E = 0;
        m->w30 = 0;
        break;
    case 1: {
        V_0054E010 a;
        V_0054E010 b;

        flag = 0;
        if ((decode_0054E010(&o->b19E4) ^ 1) == 0) {
            ((void (*)(void *, s32, s32, s32, s32))o->vt[0x34 / 4])(o, 0x1D, 1, 0, 1);
        }
        busy = 0;
        if ((decode_0054E010(&o->b19E4) ^ 1) == 0 || respawning_0054E010(o) || o->b24FE != 0 ||
            o->b2500 != 0) {
            busy = 1;
        }
        if ((u8)busy) {
            if (m->h0 == 0 && isLocal_0054E010(o)) {
                D_001D7AA8_sda = 0;
            }
            m->h0 = 1;
        }
        if (o->w3E0 != 0) {
            o->w1078 = o->w3E0;
        }
        busy = 0;
        if ((decode_0054E010(&o->b19E4) ^ 1) == 0 || respawning_0054E010(o) || o->b24FE != 0 ||
            o->b2500 != 0) {
            busy = 1;
        }
        if ((u8)busy) {
            f32 x;

            if (D_001A5990.flags[o->w2544] != 0) {
                x = -o->pad->f10C;
            } else {
                x = o->pad->f134;
                if (x < o->pad->f13C) {
                    x = -o->pad->f13C;
                }
            }
            if (fabs_asm(x) >= 1.0f) {
                x += x;
            }
            if (x > 0.0f && m->fC > 0.17453292f) {
                s32 snd = m->w20;

                if (snd == -1 || ((Slot_0054E010 *)(D_L39_001FE1A0 + (snd << 7)))->owner != self ||
                    ((Slot_0054E010 *)(D_L39_001FE1A0 + (snd << 7)))->bD0 == 0) {
                    m->w20 = func_L39_005F0CE0(2, 4, self);
                }
                m->fC -= x * 0.02f;
            } else if (x < 0.0f && m->fC < m->f8) {
                s32 snd = m->w20;

                if (snd == -1 || ((Slot_0054E010 *)(D_L39_001FE1A0 + (snd << 7)))->owner != self ||
                    ((Slot_0054E010 *)(D_L39_001FE1A0 + (snd << 7)))->bD0 == 0) {
                    m->w20 = func_L39_005F0CE0(3, 4, self);
                }
                m->fC -= x * 0.02f;
            } else {
                snd = m->w20;
                if (snd != -1) {
                    u8 *slot = D_L39_001FE1A0 + (snd << 7);
                    if (*(Self_0054E010 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
                        func_L39_005F0988(snd);
                    }
                }
                m->w20 = -1;
            }
            if (m->fC > m->f8) {
                m->fC = m->f8;
            } else if (m->fC < 0.17453292f) {
                m->fC = 0.17453292f;
            }
            camera_0054E010(o, m->fC, 0.02f, 0.2f);
            if (isLocal_0054E010(o)) {
                func_L01_004AD960(0);
            }
            m->o->f12C0 = 200.0f;
            m->o->h1280 |= 0x20;
        } else {
            snd = m->w20;
            if (snd != -1) {
                u8 *slot = D_L39_001FE1A0 + (snd << 7);
                if (*(Self_0054E010 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
                    func_L39_005F0988(snd);
                }
            }
            m->w20 = -1;
            if (m->h0 != 0) {
                m->fC = m->f8 + (0.17453292f - m->f8) * 0.25f;
                camera_0054E010(o, m->f8, 0.005f, 0.2f);
                m->h0 = 0;
                if (isLocal_0054E010(o)) {
                    D_001D7AA8_sda = 0xE0;
                    func_L01_004AD960(1);
                }
            }
            m->o->f12C0 = 75.0f;
            m->o->h1280 &= ~0x20;
        }
        k = (m->fC - 0.17453292f) / (m->f8 - 0.17453292f);
        if (isLocal_0054E010(o)) {
            D_L39_0024B820[o->b24C9] = (D_L39_0024B1B8[o->b24C9] - 0.03f) * k + 0.03f;
            D_L39_0024B830[o->b24C9] = (D_L39_0024B1C8_0054D6F8[o->b24C9] - 0.4f) * k + 0.4f;
            D_L39_0024B810_0054D6F8[o->b24C9] = (D_L39_0024B1E8_0054D6F8[o->b24C9] - 0.010471975f) * k + 0.010471975f;
        }
        {
        V_0054E010 pos;
        S_0054E010 s;
        V_0054E010 v;

        res = func_L39_00670988(o->b1A40, 0, 1, (s32)&s);
        if (res == 8) {
            func_L39_0061F5C0(o, -1);
            m->w24 = func_L01_003F0118(D_L39_00470700, o->pad);
            ent = func_L39_0061AA60(s.w2C);
            if (ent != 0) {
                obj = ((u8 * (*)(u8 *))(*(void ***)(ent + 0x14))[0x10 / 4])(ent);
            } else {
                obj = 0;
            }
            hero = 0;
            if (ent != 0 && (ent[3] & 0xF) == 0) {
                hero = (O_0054E010 *)ent;
            }
            veh = 0;
            if (ent != 0 && (ent[3] & 0xF) == 3) {
                veh = (O_0054E010 *)ent;
            }
            if (!isLocal_0054E010(o)) {
                func_003BDA38(self, 0, &pos);
                dist = 0.0f;
                flag2 = 0;
                if (obj != 0) {
                    dist = func_003887C8(&pos, obj + 0x10);
                }
                if (s.b26 & 0x40) {
                    if (obj != 0) {
                        fl = 1;
                    } else {
                        fl = 0;
                    }
                } else {
                    fl = 1;
                }
                if (s.b26 & 0x80) {
                    if (func_L39_0054FD10(arg0, (f32 *)&pos) == 0) {
                        flag2 = 1;
                        vset_0054E010(&pos, &s.x30);
                    }
                }
                if (obj == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD || dist > 190.0f) {
                    if (o->b1A08 == 1) {
                        func_00388830(&m->v40, &self->vD0, -1.0f);
                    } else if (s.b26 & 0x40) {
                        if (obj != 0 && s.w2C != 0xFFFFFFFF) {
                            vset_0054E010(&v, &s.x3C);
                            vec_add_ab(&m->v40, obj + 0x10, &v);
                        } else {
                            vset_0054E010(&m->v40, &s.x3C);
                        }
                        vec_sub_ab(&m->v40, &m->v40, &pos);
                        func_00388830(&m->v40, &m->v40, 1.0f);
                    } else {
                        vset_0054E010(&m->v40, &s.x3C);
                    }
                } else {
                    if (s.b26 & 0x40) {
                        vset_0054E010(&v, &s.x3C);
                        vec_add_ab(&v, &v, obj + 0x10);
                    } else {
                        q = func_0037E0B8(obj);
                        if (q != 0) {
                            if (hero != 0) {
                                f = *(f32 *)(q + 0x10);
                                if ((decode_0054E010(&hero->b19E6) ^ 0xC) == 0) {
                                    f -= 0.1f;
                                } else {
                                    f += 0.5f;
                                }
                                func_L01_0050D180(hero, &v, obj + 0x10, f);
                            } else {
                                *(Q_0054E010 *)&v = *(Q_0054E010 *)(obj + 0x10);
                                v.z += *(f32 *)(q + 0x10);
                            }
                        }
                    }
                    {
                    V_0054E010 d;
                    V_0054E010 e;

                    if (flag2 == 0 && func_003CE740(&pos, &v, 2, 0, 0) != 0) {
                        vset_0054E010(&e, &s.x30);
                        vec_sub_ab(&d, &e, &pos);
                        func_L01_0050D180(o, &pos, &pos, func_L39_0062FE30((u8 *)o, (f32 *)&d));
                    }
                    if (hero != 0) {
                        *(Q_0054E010 *)&a = hero->q170;
                    } else if (veh != 0) {
                        *(Q_0054E010 *)&a = *(Q_0054E010 *)((u8 *)veh + 0x270);
                    } else {
                        qzero(&a);
                    }
                    flag = 1;
                    func_003886E8(&a, &a, (f32)(s32)(dist / 26.666668f + 0.9f));
                    vec_add_ba(&b, &v, &a);
                    vec_sub_ab(&d, &b, &pos);
                    func_00388830(&m->v40, &d, 1.0f);
                    if (func_00388730(&m->v40, &self->vD0) > 0.4f) {
                        func_00388830(&m->v40, &self->vD0, -1.0f);
                        flag = 0;
                        func_003BDA38(self, 0, &pos);
                    }
                    }
                }
            } else {
                vset_0054E010(&m->v40, &s.x3C);
                vset_0054E010(&pos, &s.x30);
                if (s.b26 & 0x40) {
                    fl = 1;
                } else {
                    fl = 0;
                }
            }
            func_003BE4F0(self, 2, 0, 0);
            snd = m->w20;
            if (snd != -1) {
                u8 *slot = D_L39_001FE1A0 + (snd << 7);
                if (*(Self_0054E010 **)(slot + 0xDC) == self && slot[0xD0] != 0) {
                    func_L39_005F0988(snd);
                }
            }
            m->w20 = -1;
            func_L39_005F0CE0(0, 0, self);
            func_L39_0054EBC8(arg0, (u8 *)&pos, (s32)obj, fl, flag ? (s32)&b : 0);
        } else if (res == 4) {
            func_L39_005F0CE0(1, 0, self);
        }
        if ((res != 8 || o->b1A07 == 0) && m->w24 >= 0) {
            func_L01_003F0338(m->w24, o->pad);
            m->w24 = -1;
        }
        }
        break;
    }
    case 2:
        o->b1A0D = 1;
        if (func_L01_0040BB20(&m->f4) != 0) {
            o->b1A0D = 0;
            self->b20 = 1;
        }
        break;
    }
    if (m->w14 == 0) {
        return;
    }
    if (func_00388398(&m->w14) != 0) {
        if (m->w10 >= 0) {
            func_L01_00421FE0(m->w10);
        }
        m->w10 = -1;
    } else {
        if (m->w10 == -1) {
            m->w10 = ((s32 (*)(void *, f32, f32, s32))func_L39_0059CE28)(&self->pos, 10.0f, 0.0f, 0xFF0000FF);
        }
        if (m->w10 >= 0) {
            V_0054E010 a;
            V_0054E010 b;

            if (o->b1A08 == 1) {
                func_003BDA38(self, 0, &a);
                func_00388830(&b, &self->vD0, -1.5f);
            } else {
                func_003BDA38(self, 0, &a);
                func_00388830(&b, &o->v3B0, 1.5f);
            }
            vec_add_ab(&D_L39_002668C0_0054D6F8[m->w10].v10, &a, &b);
            D_L39_002668C0_0054D6F8[m->w10].v10.w = 10.0f;
            {
                f32 t = (f32)m->w14 / 30.0f;

                D_L39_002668C0_0054D6F8[m->w10].f4 = t;
                D_L39_002668C0_0054D6F8[m->w10].f0 = t * 0.75f;
            }
            D_L39_002668C0_0054D6F8[m->w10].f8 = 0.0f;
        }
    }
}
/* localdecomp:end func_L39_0054D6F8 */
