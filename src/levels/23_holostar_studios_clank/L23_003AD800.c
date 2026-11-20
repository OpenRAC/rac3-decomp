#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x228]; f32 f228; u8 pad22C[0x244 - 0x22C]; s32 i244;
    u8 pad248[0x2BC - 0x248]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8]; V4 a3C0[8]; V4 a440[8];
} P_3AFAF0;
typedef struct { u8 pad0[0x68]; P_3AFAF0 *p; } S_3AFAF0;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 x20;
    u8 pad21[0xB];
    f32 scale;
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 x34;
    u8 pad36[0x32];
    u8 *vars;
} Moby_3B12C8;
typedef struct {
    u8 pad0[0x220]; s32 w220; u8 pad224[0x22C - 0x224]; void *p22C;
    u8 pad230[0x2BC - 0x230]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8];
} P_3AFC40;
typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0x68 - 0x21]; P_3AFC40 *p; u8 pad6C[0xAA - 0x6C]; u16 hAA; } S_3AFC40;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; u16 h1A; u8 pad1C[0x14]; } B_3AFC40;
typedef struct { u8 pad0[0x18]; void *p18; u8 pad1C[4]; u8 a20[1]; } H_3AFC40;
typedef struct {
    u8 pad0[0x10];
    V4 pos;
    u8 x20;
    u8 pad21[0x95 - 0x21];
    u8 x95;
    u8 pad96[0xA8 - 0x96];
    u8 xA8;
} Moby_3AF6E8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0200;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B0200;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B0200 paths[1]; } Paths_3B0200;
typedef struct { u8 pad0[0x30]; V4_3B0200 pos; u8 pad40[0x40]; } Node_3B0200;
typedef struct { u8 pad0[0x180]; struct Moby *target; } Vars_3B34F8;
typedef struct { s32 x0; void *x4; s32 x8; s32 xC; V4 pos; } Vars_3B0A20;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; s16 h1A; u8 pad1C[4]; s32 x20; u8 pad24[0xC]; } Hit_3B0A20;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x48]; Vars_3B0A20 *vars; u8 pad6C[0x2A]; u16 x96; u8 pad98[0x12]; s16 xAA;
} M_3B0A20;
typedef struct {
    u8 pad0[0x220]; s32 w220; u8 pad224[0x238 - 0x224]; f32 f238;
    u8 pad23C[0x2BC - 0x23C]; s32 i2BC;
    V4 a2C0[8]; V4 a340[8]; V4 a3C0[8]; V4 a440[8];
} P_3B0480;
typedef struct { u8 pad0[0x68]; P_3B0480 *p; } S_3B0480;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x39 - 0x36];
    u8 x39;
    u8 pad3A[0x40 - 0x3A];
    f32 x40;
    u8 pad44[0x58 - 0x44];
    u8 x58;
    u8 pad59;
    u8 x5A;
    u8 pad5B[0x70 - 0x5B];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0xA8 - 0x84];
    s32 xA8;
    u8 padAC[0x2A4 - 0xAC];
    f32 x2A4;
    u8 pad2A8[0x2B8 - 0x2A8];
    f32 x2B8;
    u8 pad2BC[0x2DC - 0x2BC];
    s32 x2DC;
    s32 x2E0;
    s32 x2E4;
    u8 pad2E8[0x300 - 0x2E8];
    s32 x300;
    s32 x304;
    f32 x308;
    s32 x30C;
    u8 pad310[4];
    s32 x314;
    s32 x318;
    s32 x31C;
    u8 pad320[4];
    s32 x324;
    s32 x328;
    s32 x32C;
    s32 x330;
    s32 x334;
    f32 x338;
    s32 x33C;
    s32 x340;
    s32 x344;
    s32 x348;
    s32 x34C;
    V4 x350;
    V4 x360;
    V4 x370;
    s32 x380;
    s32 x384;
    s32 x388;
    s32 x38C;
    s32 x390;
    u8 pad394[4];
    s32 x398;
} Vars_3B3998;

/* localdecomp:start func_L23_003AD800 */
#include "vu0.h"
#include "structs/hero.h"
typedef struct { u8 pad0[0x10]; u8 b10; } Sub_AD;
typedef struct {
    u8 pad0[0x10]; s32 i10; u8 pad14[0x30]; u16 h44; u8 pad46[2];
    Sub_AD *p48; Sub_AD *p4C; u8 pad50[0x10]; Sub_AD *p60; Sub_AD *p64;
} Cls_AD;
typedef struct {
    u8 pad0[0x30]; f32 f30; s16 h34; u8 pad36[0xA4 - 0x36]; f32 fA4;
    u8 padA8[0xF4 - 0xA8]; s32 iF4;
    u8 padF8[0x170 - 0xF8]; f32 f170; f32 f174; u8 pad178[0x184 - 0x178]; s16 h184;
    u8 pad186[0x210 - 0x186]; s32 i210; s32 i214; s32 i218; s32 i21C; s32 i220; f32 f224;
    s32 i228; s32 i22C; f32 f230; f32 f234; u8 pad238[4]; s32 i23C; s32 i240; s32 i244;
    u8 pad248[4]; f32 f24C; V4 v250; V4 v260; V4 v270; u8 pad280[0x10]; V4 v290;
    u8 pad2A0[0x10]; s32 i2B0; f32 f2B4; f32 f2B8; s32 i2BC;
} Vars_AD;
typedef struct {
    u8 pad0[0x10]; V4 pos;
    u8 b20; u8 b21; u8 pad22[2]; Cls_AD *cls; u8 pad28[8];
    union { unsigned long q; u8 b[8]; u16 h[4]; } f30;
    u8 pad38[8];
    u8 b40[2]; u8 b42; u8 b43; u8 pad44[4]; f32 f48; u8 pad4C[0x60 - 0x4C];
    u8 b60; u8 pad61[7]; Vars_AD *vars; u8 pad6C[0x94 - 0x6C];
    u8 b94; u8 b95; s16 h96; s32 i98; u8 pad9C[0xF0 - 0x9C]; V4 vF0;
} Moby_AD;

extern f32 D_L23_001DE1F0[6] __attribute__((section(".sdata"))); __asm__(".extern D_L23_001DE1F0, 4");
extern f32 D_L23_001DE208[6] __attribute__((section(".sdata"))); __asm__(".extern D_L23_001DE208, 4");
extern f32 D_L23_001DE220; __asm__(".extern D_L23_001DE220, 4");
extern f32 D_L23_001DE224; __asm__(".extern D_L23_001DE224, 4");
extern f32 D_L23_001DE228; __asm__(".extern D_L23_001DE228, 4");
extern f32 D_L23_001DE22C; __asm__(".extern D_L23_001DE22C, 4");
extern f32 D_L23_001DE234; __asm__(".extern D_L23_001DE234, 4");
extern f32 D_L23_001DE238; __asm__(".extern D_L23_001DE238, 4");
extern f32 D_L23_001DE23C; __asm__(".extern D_L23_001DE23C, 4");
extern f32 D_L23_001DE240; __asm__(".extern D_L23_001DE240, 4");
extern f32 D_L23_001DE248; __asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE254; __asm__(".extern D_L23_001DE254, 4");
extern f32 D_L23_001DE258; __asm__(".extern D_L23_001DE258, 4");
extern f32 D_L23_001DE25C; __asm__(".extern D_L23_001DE25C, 4");
extern f32 D_L23_001DE264; __asm__(".extern D_L23_001DE264, 4");
extern f32 D_L23_001DE268; __asm__(".extern D_L23_001DE268, 4");
extern f32 D_L23_001DE26C; __asm__(".extern D_L23_001DE26C, 4");
extern f32 D_L23_001DE270; __asm__(".extern D_L23_001DE270, 4");
extern s32 D_L23_001DE278; __asm__(".extern D_L23_001DE278, 4");
extern Moby_AD *D_L23_001DE2D0;
extern s32 D_001A7430[];
extern s32 D_001A71A0[];

extern struct Hero D_001A4BE0;
extern Paths_3B0200 *D_L23_001DED4C; __asm__(".extern D_L23_001DED4C, 16");
extern Node_3B0200 *D_L23_001DF240; __asm__(".extern D_L23_001DF240, 16");
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;
extern u8 D_L23_001E1A40[];
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_0044C108(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_004468C8(f32, f32, f32, void *, s32, s32, s32, s32, s32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00463378(void *, void *, void *, u32, u32, s32, s32, s32, s32);
extern int func_00382380(void *, int, int);
extern void func_L23_0034DF80(f32, void *, void *, void *, void *, s32, s32);
extern void func_L23_003AF6E8();
extern void func_L23_003AFE10(u8 *);
extern void func_L23_003AFC40();
extern void func_L23_003AFAF0();
extern void func_L23_003B08E0(void *);
extern s32 func_L23_003B0110(u8 *, V4 *, f32, s32);


void func_L23_003AD800(Moby_AD *m)
{
    Vars_AD *v;
    Cls_AD *c;
    V4 t;
    V4 u;
    f32 d;
    f32 dist;
    f32 ratio;
    f32 r;
    f32 dsq;
    f32 dist5;
    f32 ang5;
    f32 dist6;
    f32 dist10;
    f32 ang10;
    f32 dir2;
    f32 spd2;
    f32 step19;
    s32 i;
    s32 j;
    s32 ok;
    s32 id;
    u16 *p;
    u8 *e;
    Path_3B0200 *path;
    Node_3B0200 *n;

    if (func_L01_0044C108(&m->pos) == 0) {
        return;
    }
    v = m->vars;
    if (m->b20 == 1) {
        return;
    }
    func_L23_003AF6E8(m);
    switch (m->b95) {
    case 2:
        if (func_L01_004561E0(m) != 0) {
            if (v->i244 != 0) {
                func_L01_004450F0(m, 10, -1);
            }
        }
        if (v->h184 == 1) {
            func_L01_004450F0(m, 5, 3);
        }
        break;
    case 3:
        if (func_L01_004561E0(m) != 0) {
            if (v->i244 != 0) {
                func_L01_004450F0(m, 10, -1);
            }
        }
        if (v->h184 == 1) {
            func_L01_004450F0(m, 11, 4);
        }
        break;
    case 4:
        if (func_L01_004561E0(m) != 0) {
            v->i240 = 0;
            v->i21C = 0;
        }
        if (v->h184 == 1) {
            t.x = func_0038D098(func_0038D160(m->pos.x - v->f170, m->pos.y - v->f174)) * D_L23_001DE228;
            t.y = func_0038D0B0(func_0038D160(m->pos.x - v->f170, m->pos.y - v->f174)) * D_L23_001DE228;
            t.z = 0.0f;
            vec_add_ab(&v->v250, &v->f170, &t);
            v->f24C = func_0038D160(v->f170 - m->pos.x, v->f174 - m->pos.y);
        } else if (v->h184 == 0) {
            if (func_L01_004561E0(m) == 0) {
                if (D_001A7430[0] <= 0) {
                    func_L01_004450F0(m, 0x13, 2);
                } else {
                    func_L01_004450F0(m, 5, 3);
                }
            }
        }
        if (D_L23_001DE2D0 != 0) {
            if (D_L23_001DE2D0->vars->f30 <= 0.0f) {
                func_L23_003AFE10((u8 *)m);
                func_003C2880(m);
                return;
            }
        }
        break;
    case 0:
        m->i98 = 0;
        m->f30.h[2] = (m->f30.h[2] | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        break;
    }
    switch (m->b20) {
    case 1:
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 0) {
                func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
            }
            v->i214 = func_00382498(0xFA, 0x1F4);
        }
        if (v->i214 > 0) {
        } else if (m->b43 != 1) {
            func_003C3A10(m, 1, 0, 8);
        }
        if (m->b42 == m->b43 && m->b42 == 1 && (m->b60 & 2) != 0) {
            func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
            v->i214 = func_00382498(0xFA, 0x1F4);
        }
        break;
    case 2:
        if ((m->f30.q & 0x104100000000UL) == 0x4100000000UL && m->i98 == 0 &&
            func_L01_0040E570(&m->pos, &D_001A4BE0.pos) < 100.0f) {
            break;
        }
        if (func_L01_004561B8(m) != 0) {
            m->h96 = 0;
            m->f30.h[2] &= 0xFFBE;
            c = m->cls;
            m->f30.h[2] |= c->h44 & 0x1000;
            m->i98 = c->i10;
            if (m->b43 != 0x20) {
                func_003C3A10(m, 0x20, 0, 0);
            }
        }
        if ((m->b60 & 2) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 4, 2);
        }
        if (m->f30.b[1] != 0) {
            for (i = 0; i < 5; i++) {
                dir2 = func_00382538();
                spd2 = func_003824E0(0.0f, 0.120000005f);
                t.x = spd2 * func_0038D098(dir2);
                t.y = spd2 * func_0038D0B0(dir2);
                t.z = func_003824E0(0.120000005f, 0.32000002f) - spd2;
                t.w = 1.5f;
                func_0038CE20(&u, &t, 0.3f);
                u.w = 2.0f;
                func_L01_00463378(&m->pos, &t, &u, 0x80808080, 0x60808080, 12, 25, 12, -1);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            if (v->i2B0 == 0) {
                func_003C2880(m);
                return;
            }
            v->i2B0 = v->i2B0 - 1;
        }
        func_0038CAD0(&v->i210);
        if (v->i210 != 0) {
            break;
        }
        t = v->v290;
        path = &D_L23_001DED4C->paths[v->i23C];
        for (j = 0; j < path->count; j++) {
            id = path->ids[j];
            n = &D_L23_001DF240[id];
            if (j == D_L23_001DE278) {
                continue;
            }
            dsq = func_L01_0040E570(&n->pos, &D_001A4BE0.pos);
            if (dsq < D_L23_001DE26C * D_L23_001DE26C) {
                continue;
            }
            if (D_L23_001DE270 * D_L23_001DE270 < dsq) {
                continue;
            }
            if (fabs_asm(func_0038DB00(D_001A4BE0.rot.z, func_0038D160(n->pos.x - D_001A4BE0.pos.x, n->pos.y - D_001A4BE0.pos.y))) > 1.5707964f) {
                continue;
            }
            ok = 1;
            p = D_L23_0021C0E0[m->b21];
            while (m->b21 != 0xFF && m->b21 <= D_L23_001DF198 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[m->b21])) {
                e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                if ((Moby_AD *)e != m) {
                    if (func_00382380(e + 0x10, id, 0) != 0) {
                        ok = 0;
                        break;
                    }
                }
                p++;
            }
            if (ok != 0) {
                t = *(V4 *)&n->pos;
                t.z = func_003C3D30(&t, 0, 0, 0.5f);
                break;
            }
        }
        qzero(&m->vF0);
        m->pos = t;
        v->v250 = t;
        v->f30 = (f32)v->h34;
        v->f24C = func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        v->i218 = 0;
        v->i244 = 0;
        v->i21C = 0;
        v->i240 = 0;
        v->i228 = 0;
        v->i2BC = 0;
        func_L01_004450F0(m, 2, 1);
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 1) {
                func_003C3A10(m, 1, func_00382468(m->cls->p4C->b10), 8);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            if (v->i218 == 0) {
                dist5 = func_L01_0040E570(&m->pos, &v->v250);
                ang5 = func_0038D160(m->pos.x - *(f32 *)&D_L23_001E1A40[0], m->pos.y - *(f32 *)&D_L23_001E1A40[4]);
                ang5 = fabs_asm(func_0038DBA0(*(f32 *)&D_L23_001E1A40[0x18], ang5));
                if (v->i220 != 0) {
                    if (dist5 > 200.0f) {
                        v->i218 = func_00382468(2) ? 5 : 4;
                    } else if (ang5 > 0.5235988f) {
                        v->i218 = 1;
                    } else {
                        v->i218 = func_00382468(2) ? (v->i244 ? 5 : 2) : 4;
                    }
                } else if (dist5 > 100.0f) {
                    v->i218 = 4;
                } else {
                    v->i218 = 3;
                }
                v->f224 = dist5;
            }
            func_L01_0045BD78(m, D_L23_001DE208[v->i218], D_L23_001DE1F0[v->i218], 0.0050265486f, 0.12566371f);
            switch (v->i218) {
            case 1:
                if (m->b43 != 8) {
                    func_003C3A10(m, 8, 0, 5);
                }
                break;
            case 2:
                if (m->b43 != 0x1D) {
                    func_003C3A10(m, 0x1D, 0, 5);
                }
                break;
            case 3:
            case 4:
                func_L01_004450F0(m, 7, -1);
                break;
            case 5:
                if (m->b43 != 0xB) {
                    func_003C3A10(m, 0xB, 0, 5);
                }
                break;
            }
        } else if (m->b42 == m->b43 && (m->b60 & 2) != 0) {
            func_L01_004450F0(m, 7, -1);
        }
        func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218);
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            if (m->b94 != 6) {
                func_L01_004450F0(m, 6, -1);
                break;
            }
            switch (v->i218) {
            case 1:
                if (m->b43 != 9) {
                    func_003C3A10(m, 9, 0, 0);
                }
                break;
            case 2:
                if (m->b43 != 0x1E) {
                    func_003C3A10(m, 0x1E, 0, 0);
                }
                break;
            case 3:
                if (m->b43 != 6) {
                    func_003C3A10(m, 6, func_00382468(m->cls->p60->b10), 5);
                }
                break;
            case 4:
                if (m->b43 != 7) {
                    func_003C3A10(m, 7, func_00382468(m->cls->p64->b10), 5);
                }
                break;
            case 5:
                if (m->b43 != 0xC) {
                    func_003C3A10(m, 0xC, 0, 0);
                }
                break;
            }
        }
        if (func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218) == 0) {
            func_L01_004450F0(m, 0xF, 4);
        }
        dist6 = func_L01_0040E570(&m->pos, &v->v250);
        if (v->iF4 == D_001A71A0[0] || dist6 < v->fA4 * v->fA4) {
            func_L01_004450F0(m, 8, -1);
        } else if (dist6 - v->f224 > 16.0f) {
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        if ((v->i218 == 2 || v->i218 == 5) && (m->b60 & 2) == 0) {
            break;
        }
        if (func_L01_004561B8(m) != 0) {
            switch (v->i218) {
            case 1:
                if (m->b43 != 0xA) {
                    func_003C3A10(m, 0xA, 0, 5);
                }
                break;
            case 2:
                if (m->b43 != 0x1F) {
                    func_003C3A10(m, 0x1F, 0, 0);
                }
                break;
            case 5:
                if (m->b43 != 0xD) {
                    func_003C3A10(m, 0xD, 0, 0);
                }
                break;
            case 3:
            case 4:
                break;
            }
            v->i218 = 0;
        } else if (m->b42 == m->b43) {
            if ((m->b60 & 2) != 0) {
                switch (m->b95) {
                case 2:
                    func_L01_004450F0(m, 4, -1);
                    break;
                case 3:
                    func_L01_004450F0(m, 5, -1);
                    break;
                case 4:
                    func_L01_004450F0(m, 0xB, -1);
                    break;
                default:
                    func_L01_004450F0(m, 4, 2);
                    break;
                }
            }
        }
        func_L23_003B0110((u8 *)m, &m->pos, v->f24C, v->i218);
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 0xE) {
                func_003C3A10(m, 0xE, 0, 8);
            }
            v->i240 = 0;
        }
        func_L23_003B0110((u8 *)m, &m->pos, v->f24C, v->i218);
        if (m->b42 != m->b43) {
            break;
        }
        if (func_L01_0044E1B8(m, 12.0f) != 0) {
            v->i244 = 1;
        }
        if (m->b42 == m->b43 && (m->b60 & 2) != 0) {
            switch (m->b95) {
            case 2:
                func_L01_004450F0(m, 4, -1);
                break;
            case 3:
                func_L01_004450F0(m, 5, -1);
                break;
            case 4:
                func_L01_004450F0(m, 0xB, -1);
                break;
            default:
                func_L01_004450F0(m, 4, 2);
                break;
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 0x12) {
                func_003C3A10(m, 0x12, 0, 8);
            }
            v->i240 = 0;
        }
        if (m->b42 != m->b43) {
            break;
        }
        if (func_L01_0044E1B8(m, 27.0f) != 0) {
            v->i244 = 0;
        }
        if (m->b42 == m->b43 && (m->b60 & 2) != 0) {
            switch (m->b95) {
            case 2:
                func_L01_004450F0(m, 4, -1);
                break;
            case 3:
                func_L01_004450F0(m, 5, -1);
                break;
            case 4:
                func_L01_004450F0(m, 0xB, -1);
                break;
            default:
                func_L01_004450F0(m, 4, 2);
                break;
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            v->i240 = v->i21C;
            v->i22C = 0;
            dist10 = func_L01_0040E570(&m->pos, &v->v250);
            ang10 = func_0038DBA0(D_001A4BE0.rot.z, func_0038D160(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y));
            if (dist10 > 40.0f && v->i244 == 0 && func_00382468(3) != 0) {
                func_L01_004450F0(m, 0x10, -1);
            } else if (D_L23_001DE22C * D_L23_001DE22C < dist10) {
                if (v->i244 != 0 || func_00382468(2) != 0) {
                    func_L01_004450F0(m, 6, -1);
                } else {
                    func_L01_004450F0(m, 9, -1);
                }
            } else if (v->i244 != 0) {
                if (v->i220 != 0 && ang10 < 0.5235988f && func_00382468(2) != 0 && v->i240 != 2) {
                    func_L01_004450F0(m, 0x11, -1);
                } else if (v->i240 == 0 && func_00382468(2) != 0) {
                    func_L01_004450F0(m, 0x12, -1);
                } else if (func_00382468(3) != 0) {
                    func_L01_004450F0(m, 0xE, -1);
                } else if (v->i240 != 6) {
                    func_L01_004450F0(m, 0xF, -1);
                } else {
                    func_L01_004450F0(m, 0xA, -1);
                }
            } else {
                if (v->i220 != 0 && ang10 < 0.5235988f && func_00382468(2) != 0 && v->i240 != 2) {
                    func_L01_004450F0(m, 0x11, -1);
                } else if (v->i240 == 0 && func_00382468(2) != 0) {
                    func_L01_004450F0(m, 0x12, -1);
                } else if (func_00382468(3) != 0) {
                    func_L01_004450F0(m, 0xC, -1);
                } else if (v->i240 != 4) {
                    func_L01_004450F0(m, 0xD, -1);
                } else {
                    func_L01_004450F0(m, 9, -1);
                }
            }
        }
        func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218);
        break;
    case 12:
        if (func_L01_004561B8(m) != 0) {
            v->i21C = 3;
            if (m->b43 != 0x13) {
                func_003C3A10(m, 0x13, 0, 5);
            }
        }
        func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218);
        if (func_L01_004395E0(m) < 20.0f && m->b42 == m->b43) {
            func_L01_004468C8(D_L23_001DE234,
                              D_L23_001DE238 + (v->i220 != 0 ? D_L23_001DE240 : 0.0f), 1.0f, m, 4, 3, 0, 1, 0);
        }
        if (func_L01_0044E1B8(m, 21.0f) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            v->i21C = 4;
            if (m->b43 != 0x1C) {
                func_003C3A10(m, 0x1C, 0, 5);
            }
        }
        func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218);
        if (func_L01_004395E0(m) > 12.0f && m->b42 == m->b43) {
            func_L01_004468C8(D_L23_001DE234,
                              D_L23_001DE238 + (v->i220 != 0 ? D_L23_001DE240 : 0.0f), 1.0f, m, 9, 7, 0, 1, 0);
            func_L01_004468C8(D_L23_001DE234,
                              D_L23_001DE238 + (v->i220 != 0 ? D_L23_001DE240 : 0.0f), 1.0f, m, 10, 7, 0, 1, 0);
            func_L01_004468C8(D_L23_001DE234,
                              D_L23_001DE238 + (v->i220 != 0 ? D_L23_001DE240 : 0.0f), 1.0f, m, 8, 7, 0, 1, 0);
        }
        if (func_L01_0044E1B8(m, 30.0f) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 14:
        if (func_L01_004561B8(m) != 0) {
            v->i21C = 5;
            if (m->b43 != 0xF) {
                func_003C3A10(m, 0xF, 0, 5);
            }
        }
        func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218);
        if (m->b42 == m->b43) {
            func_L23_003AFC40(m);
        }
        if (func_L01_0044E1B8(m, 20.0f) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 15:
        if (func_L01_004561B8(m) != 0) {
            v->f230 = 0.0f;
            v->i21C = 5;
            v->f234 = 0.0f;
            if (m->b43 != 0x1B) {
                func_003C3A10(m, 0x1B, 0, 5);
            }
        }
        func_L23_003B0110((u8 *)m, &v->v250, v->f24C, v->i218);
        if (m->b42 != m->b43) {
            break;
        }
        d = func_L01_004395E0(m);
        if (d > 16.0f) {
            func_L23_003AFC40(m);
        }
        if (func_L01_0044E1B8(m, 16.0f) != 0) {
            v->f230 = 0.0f;
        }
        if (func_L01_0044E1B8(m, 33.0f) != 0) {
            func_L01_004450F0(m, 0xB, -1);
        }
        if (d > 8.0f && d < 16.0f) {
            func_003C41A0(&v->f234, &v->f230, 5.0f, 1.5625f, 0.25f, 1.0625f);
        }
        if (d > 16.0f && d < 24.0f) {
            func_003C41A0(&v->f234, &v->f230, 0.0f, 0.052083332f, 0.3125f, 0.9375f);
        }
        if (d > 8.0f && d < 24.0f) {
            t = m->pos;
            t.z = func_003C3D30(&t, 0, 0, 0.5f) + v->f234;
            vec_sub_ab(&u, &t, &m->pos);
            func_L01_0045AA30(m, &u);
        }
        break;
    case 16:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 0x14) {
                func_003C3A10(m, 0x14, 0, 5);
            }
        }
        func_L23_003B0110((u8 *)m, &m->pos, func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y), 0);
        if (func_L01_0044E1B8(m, 15.5f) != 0 && m->b42 == m->b43) {
            func_003C2F58(m, 4, &u);
            vec_sub_ab(&t, &v->v250, &u);
            func_0038CF68(&t, &t, 0.50000006f);
            func_L23_0034DF80(D_L23_001DE23C, m, &t, &u, &m->vF0, 1, 0);
        }
        if (func_L01_0044E1B8(m, 21.0f) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 18:
        if (func_L01_004561B8(m) != 0) {
            v->i21C = 1;
            if (v->i244 != 0) {
                if (m->b43 != 0x10) {
                    func_003C3A10(m, 0x10, 0, 5);
                }
            } else if (m->b43 != 0x15) {
                func_003C3A10(m, 0x15, 0, 5);
            }
        }
        func_L23_003B0110((u8 *)m, &m->pos, m->vF0.z, 0);
        if ((m->b60 & 2) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 19:
        if (func_L01_004561B8(m) != 0) {
            if (m->b43 != 2) {
                func_003C3A10(m, 2, 0, 8);
            }
        }
        if ((m->b60 & 2) != 0 && m->b42 == m->b43) {
            func_L01_004450F0(m, 4, 2);
        }
        func_L23_003B0110((u8 *)m, &m->pos, func_0038D160(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y), 0);
        break;
    case 17:
        if (func_L01_004561B8(m) != 0) {
            switch (func_00382468(4)) {
            case 0:
            case 1:
                if (m->b43 != 4) {
                    func_003C3A10(m, 4, 0, 5);
                }
                v->v260.x = func_0038D098(func_0038DAB8(1.5707964f, m->vF0.z)) * D_L23_001DE264;
                v->v260.y = func_0038D0B0(func_0038DAB8(1.5707964f, m->vF0.z)) * D_L23_001DE264;
                v->v260.z = 0.0f;
                vec_add_ab(&v->v260, &v->v260, &m->pos);
                v->v260.z = func_003C3D30(&v->v260, 0, 0, 0.5f);
                break;
            case 2:
            case 3:
                if (m->b43 != 3) {
                    func_003C3A10(m, 3, 0, 5);
                }
                v->v260.x = func_0038D098(func_0038DB00(1.5707964f, m->vF0.z)) * D_L23_001DE264;
                v->v260.y = func_0038D0B0(func_0038DB00(1.5707964f, m->vF0.z)) * D_L23_001DE264;
                v->v260.z = 0.0f;
                vec_add_ab(&v->v260, &v->v260, &m->pos);
                v->v260.z = func_003C3D30(&v->v260, 0, 0, 0.5f);
                break;
            case 4:
                if (m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 5);
                }
                v->v260.x = func_0038D098(func_0038DAB8(3.1415927f, m->vF0.z)) * D_L23_001DE264;
                v->v260.y = func_0038D0B0(func_0038DAB8(3.1415927f, m->vF0.z)) * D_L23_001DE264;
                v->v260.z = 0.0f;
                vec_add_ab(&v->v260, &v->v260, &m->pos);
                v->v260.z = func_003C3D30(&v->v260, 0, 0, 0.5f);
                break;
            }
            if (__builtin_fabsf(v->v260.z - m->pos.z) > 2.0f) {
                func_L01_004450F0(m, 0xB, -1);
                break;
            }
            v->f230 = 0.0f;
            v->i21C = 2;
            v->f234 = 0.0f;
            v->v270 = m->pos;
        }
        if (m->b42 != m->b43) {
            break;
        }
        dist = func_L01_004395E0(m);
        ratio = (dist - D_L23_001DE254) / (D_L23_001DE25C - D_L23_001DE254);
        if (ratio > 1.0f) {
            ratio = 1.0f;
        } else if (ratio < 0.0f) {
            ratio = 0.0f;
        }
        if (D_L23_001DE254 < dist && dist <= D_L23_001DE258) {
            v->f234 = D_L23_001DE268 * sqrt_asm((dist - D_L23_001DE254) / (D_L23_001DE258 - D_L23_001DE254));
        } else if (D_L23_001DE258 < dist && dist <= D_L23_001DE25C) {
            r = (dist - D_L23_001DE258) / (D_L23_001DE25C - D_L23_001DE258);
            v->f234 = D_L23_001DE268 * (1.0f - r * r);
        }
        if (v->f234 > 0.0f) {
            vec_sub_ab(&t, &v->v260, &v->v270);
            func_0038CE20(&t, &t, ratio);
            vec_add_ba(&t, &t, &v->v270);
            t.z = v->v260.z + v->f234;
            vec_sub_ab(&u, &t, &m->pos);
            func_L01_0045AA30(m, &u);
        } else {
            func_L23_003B0110((u8 *)m, &v->v250, v->f24C, 0);
        }
        if (func_L01_0044E1B8(m, 34.0f) != 0) {
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 20:
        if (func_L01_004561B8(m) != 0) {
            if (v->f30 <= 0.0f) {
                func_L23_003AFE10((u8 *)m);
                func_L01_004450F0(m, 3, 0);
                return;
            }
            if (v->f2B8 >= D_L23_001DE220) {
                if (m->b43 != 0x18) {
                    func_003C3A10(m, 0x18, 0, 3);
                }
            } else if (m->b43 != 0x18) {
                func_003C3A10(m, 0x18, 0, 3);
            }
            if (v->i220 != 0) {
                m->f48 = 1.5f;
            }
        }
        if (v->f2B8 < D_L23_001DE224) {
            step19 = v->f2B8;
        } else {
            step19 = D_L23_001DE224;
        }
        v->f2B8 = v->f2B8 - step19;
        t.x = func_0038D098(v->f2B4) * step19;
        t.y = func_0038D0B0(v->f2B4) * step19;
        t.z = 0.0f;
        func_L01_0045AA30(m, &t);
        u.x = func_0038D098(v->f2B4) * D_L23_001DE248;
        u.y = func_0038D0B0(v->f2B4) * D_L23_001DE248;
        u.z = 0.0f;
        vec_add_ba(&u, &u, &m->pos);
        u.z += D_L23_001DE248;
        func_L01_00446780((u8 *)m, (u8 *)&u, 3, 0, 1, 0, D_L23_001DE248, 20.0f, 1.0f);
        if (m->b42 == m->b43) {
            if ((m->b60 & 2) != 0) {
                func_L01_004450F0(m, 5, 3);
            }
        }
        func_L23_003B0110((u8 *)m, &m->pos, func_0038DB48(v->f2B4 + 3.1415927f), 0);
        break;
    }
    func_L23_003AFAF0(m);
    func_L23_003B08E0(m);
}
/* localdecomp:end func_L23_003AD800 */

/* localdecomp:start func_L23_003AF6E8 */
#include "vu0.h"
extern f32 D_L23_001DE248;
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE220;
__asm__(".extern D_L23_001DE220, 4");
extern V4 D_L23_001E87A0;
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern void func_L23_003AF9B8(u8 *self);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00404A10(void *, s32);


void func_L23_003AF6E8(Moby_3AF6E8 *m)
{
    u8 *v = *(u8 **)((u8 *)m + 0x68);
    u8 *t;
    V4 d;
    V4 p;
    V4 q;
    f32 len;

    if (m->x20 == 0) {
        func_L23_003AF9B8((u8 *)m);
    }
    func_L01_00451DF8((u8 *)m, v + 0x190, 11, 1, 2.5f);
    t = func_L01_00447490(m, 0x1170000, 0);
    if (t != 0) {
        if (m->x20 != 20) {
            *(f32 *)(v + 0x30) -= *(f32 *)(t + 0x2C);
            v[0x167] = 0xFF;
            func_003C4A40(m, v + 0x160);
            if ((*(f32 *)(v + 0x30) <= 0.0f || 10.0f <= *(f32 *)(t + 0x2C)) && m->x95 != 1 && m->x95 != 0) {
                if (40.0f <= *(f32 *)(t + 0x2C) && *(u8 **)(t + 0x20) != 0) {
                    vec_sub_ba(&d, &m->pos, *(u8 **)(t + 0x20) + 0x10);
                    d.z = 0.0f;
                    func_0038CF68(&d, &d, D_L23_001DE220 + D_L23_001DE248);
                    p = m->pos;
                    p.z += 1.0f;
                    vec_add_ab(&q, &p, &d);
                    if (func_003D3CB0(&p, &q, 0, m, 0) != 0) {
                        vec_sub_ba(&d, &D_L23_001E87A0, &m->pos);
                        d.z = 0.0f;
                        len = func_0038CEA8(&d);
                        if (D_L23_001DE248 < len) {
                            func_0038CE20(&d, &d, (len - D_L23_001DE248) / len);
                        } else {
                            qzero(&d);
                        }
                    } else {
                        func_0038CE20(&d, &d, D_L23_001DE220 / (D_L23_001DE220 + D_L23_001DE248));
                    }
                    *(f32 *)(v + 0x2B8) = func_0038CEA8(&d);
                    *(f32 *)(v + 0x2B4) = func_0038D160(d.x, d.y);
                }
                func_L01_004450F0(m, 20, -1);
            }
        }
        m->xA8 = 0xFF;
    }
    if (m->x95 == 0 && m->pos.z < *(f32 *)(v + 0x298) - 10.0f) {
        *(s32 *)(v + 0x30) = 0;
        func_L01_004450F0(m, 20, -1);
    }
    func_L01_0044ABD0(m, v + 0x160);
    func_L01_00404A10(m, 3);
    *(struct Moby **)(v + 0x180) = D_001A4BE0.hero_moby;
    *(s16 *)(v + 0x184) = 1;
    *(u128_t *)(v + 0x170) = *(u128_t *)&D_001A4BE0.pos;
}
/* localdecomp:end func_L23_003AF6E8 */

/* localdecomp:start func_L23_003AF9B8 */
__asm__(".extern D_L23_001DE244, 4");
__asm__(".extern D_L23_001DE248, 4");
extern f32 D_L23_001DE244;
extern f32 D_L23_001DE248;
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AF9B8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);

    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    *(f32 *)(v + 0x40) = 1.0f;
    v[0x39] = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 0x4B;
        *(f32 *)(v + 0x30) = 75.0f;
    }
    if (*(s32 *)(v + 0x220) != 0) {
        *(f32 *)(v + 0x30) *= D_L23_001DE244;
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x30);
    }
    *(f32 *)(v + 0x70) = D_L23_001DE248;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0x74) = *(f32 *)(v + 0x70);
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.5f;
    *(f32 *)(v + 0x80) = 1.4835298f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    *(V4 *)(v + 0x250) = *(V4 *)(self + 0x10);
    *(V4 *)(v + 0x290) = *(V4 *)(self + 0x10);
    *(f32 *)(v + 0x24C) = *(f32 *)(self + 0xF8);
    *(s32 *)(v + 0x218) = 0;
    *(s32 *)(v + 0x244) = 0;
    *(s32 *)(v + 0x21C) = 0;
    *(s32 *)(v + 0x240) = 0;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x2BC) = 0;
    *(s32 *)(v + 0x210) = 0;
    if (self[0x21] != 0xFF)
        func_L01_004450F0(self, 1, 0);
    else
        func_L01_004450F0(self, 4, 2);
}
/* localdecomp:end func_L23_003AF9B8 */

/* localdecomp:start func_L23_003AFAF0 */
#include "vu0.h"
__asm__(".extern D_L23_001DE250, 4");
__asm__(".extern D_L23_001DE274, 4");
extern f32 D_L23_001DE250;
extern s32 D_L23_001DE274;
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00404808(void *, void *);
void func_L23_003B0480(void *);

void func_L23_003AFAF0(S_3AFAF0 *s)
{
    P_3AFAF0 *p = s->p;
    u8 buf[0x40];
    V4 v;

    if (p->i244 != 0) {
        func_003C4138(&p->f228, D_L23_001DE250, D_L23_001DE250 / 60.0f);
    } else {
        func_003C4138(&p->f228, 0.0f, D_L23_001DE250 / 30.0f);
    }
    if (++p->i2BC >= D_L23_001DE274) {
        p->i2BC = 0;
    }
    func_003C2EC0(s, 0, buf);
    func_0038CF68(&v, buf, p->f228);
    func_003C2F58(s, 1, &p->a2C0[p->i2BC]);
    func_003C2F58(s, 3, &p->a3C0[p->i2BC]);
    vec_add_ba(&p->a340[p->i2BC], &p->a2C0[p->i2BC], &v);
    vec_sub_ba(&p->a440[p->i2BC], &p->a3C0[p->i2BC], &v);
    if (0.0f < p->f228) {
        func_L01_00404808(func_L23_003B0480, s);
    }
}
/* localdecomp:end func_L23_003AFAF0 */

/* localdecomp:start func_L23_003AFC40 */
#include "vu0.h"
__asm__(".extern D_L23_001DE238, 4");
extern f32 D_L23_001DE238;
extern H_3AFC40 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L23_003AFC40(S_3AFC40 *s)
{
    P_3AFC40 *p;
    V4 d;
    V4 t;
    B_3AFC40 b;
    void *h;
    s32 c;

    p = s->p;
    func_0038CE20(&t, (u8 *)s + 0xC0, 3.0f);
    vec_sub_ab(&d, &t, &p->a2C0[p->i2BC]);
    func_0038CF68(&d, &d, 2.5f);
    d.z = 1.0f;
    d.w = 5627.9248f;
    func_L01_00446760(&b, s, s->b20 == 0xF ? 7 : 3, &d, D_L23_001DE238 + D_L23_001DE238);
    b.b18 = 0;
    b.b19 = 1;
    b.h1A = s->hAA;
    if (func_003D3CB0(&p->a2C0[p->i2BC], &p->a340[p->i2BC], 9, s, &b) != 0) {
        h = D_L23_001E8780.p18;
        if (h != p->p22C && h != 0) {
            p->p22C = h;
            c = p->w220 ? 0x60000080 : 0x60008080;
            func_L01_003303B8(D_L23_001E8780.a20, 0.4f, 0, 0, 0xF, 0, 1, 0xF, 0, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0, 0, c, c, c, c, c, c, c, c, 0, 0);
        }
    }
}
/* localdecomp:end func_L23_003AFC40 */

/* localdecomp:start func_L23_003AFE10 */
extern f32 D_L23_001DE224;
__asm__(".extern D_L23_001DE224, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L03_0043FC00(void *, s32, u8 *, s32, s32, f32, f32, f32, f32, u8, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L23_003AFE10(u8 *o)
{
    u8 *v = *(u8 **)(o + 0x68);
    f32 d[4];

    d[0] = func_0038D098(*(f32 *)(v + 0x2B4)) *
           (D_L23_001DE224 < *(f32 *)(v + 0x2B8) ? D_L23_001DE224 * 0.5f : *(f32 *)(v + 0x2B8) * 0.5f);
    d[1] = func_0038D0B0(*(f32 *)(v + 0x2B4)) *
           (D_L23_001DE224 < *(f32 *)(v + 0x2B8) ? D_L23_001DE224 * 0.5f : *(f32 *)(v + 0x2B8) * 0.5f);
    d[2] = 0.0f;
    func_003A52A0(0, 0, o);
    func_L03_0043FC00(o, 0x3FF, (u8 *)d, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 1.0f);
    *(s32 *)(v + 0x210) = 200;
    *(s32 *)(v + 0x228) = 0;
    *(s32 *)(v + 0x244) = 0;
    if (*(s32 *)(v + 0x2B0) == 0)
        func_L01_004443E8(o, 0, 3);
    func_L01_003303B8(o + 0x10, 2.0f, 1, 10, 20, 0, 4, 20, 2, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L23_003AFE10 */

/* localdecomp:start func_L23_003B0010 */
extern void func_L01_004450F0(void *, s32, s32);
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
extern s32 D_L23_001DF198;

void func_L23_003B0010(s32 idx) {
    u16 *p;
    u8 *e;

    if (idx < 0) {
        return;
    }
    p = D_L23_0021C0E0[idx];
    while ((idx & 0xFF) != 0xFF && idx <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[idx])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (e[0x20] == 1) {
            func_L01_004450F0(e, 2, 1);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B0010 */

/* localdecomp:start func_L23_003B0110 */
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L23_003B0200(u8 *, s32, f32 *, void *, void *, s32);

s32 func_L23_003B0110(u8 *m, V4 *target, f32 speed, s32 mode) {
    u8 *v = *(u8 **)(m + 0x68);
    V4 pos;
    f32 before;
    f32 after;
    if (mode == 0) {
        func_L01_0045AA10(m, speed);
        func_L01_0045BD10(m, speed);
        return 1;
    }
    pos = *target;
    func_L23_003B0200(m, *(s32 *)(v + 0x23C), (f32 *)&pos, v + 0x280, v + 0x248, 0);
    before = func_L01_0040E570(&pos, m + 0x10);
    func_L01_0045A748(m, &pos);
    after = func_L01_0040E570(&pos, m + 0x10);
    return !(before > 1.0f && __builtin_fabsf(after - before) < 0.01f);
}
/* localdecomp:end func_L23_003B0110 */

/* localdecomp:start func_L23_003B0200 */
#include "common.h"
#include "vu0.h"
extern Paths_3B0200 *D_L23_001DED4C;
__asm__(".extern D_L23_001DED4C, 16");
extern Node_3B0200 *D_L23_001DF240;
__asm__(".extern D_L23_001DF240, 16");
extern f32 D_L23_001DE24C;
__asm__(".extern D_L23_001DE24C, 4");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L23_003B0200(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4_3B0200 *home = a3;
    s32 *cur = a4;
    Path_3B0200 *path;
    V4_3B0200 pos;
    V4_3B0200 tgt;
    V4_3B0200 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_3B0200 *e;

    if (idx >= 0 && idx < D_L23_001DED4C->count) {
    path = &D_L23_001DED4C->paths[idx];
    pos = *(V4_3B0200 *)(m + 0x10);
    tgt = *(V4_3B0200 *)out;
    pos.z += 1.0f;
    tgt.z += 1.0f;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 0, m, 0) == 0) {
        *cur = -1;
        *home = *(V4_3B0200 *)out;
        return 1;
    }
    lim = d * 4.0f;
    best = -1;
    for (i = 0; i < path->count; i++) {
        id = path->ids[i];
        e = &D_L23_001DF240[id];
        if (id == *cur)
            continue;
        if (func_00382380(&pos, id, 0) != 0) {
            *cur = path->ids[i];
            continue;
        }
        nd = func_L01_0040E570(&tgt, &e->pos);
        if (lim < nd)
            continue;
        if (func_003D3CB0(&pos, &e->pos, 0, m, 0) != 0)
            continue;
        lim = nd;
        best = i;
    }
    if (best < 0) {
        if (func_L01_0040E570(out, home) > D_L23_001DE24C * D_L23_001DE24C)
            *(V4_3B0200 *)out = *home;
        else
            return 0;
    } else {
        *(V4_3B0200 *)out = D_L23_001DF240[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L23_003B0200 */

/* localdecomp:start func_L23_003B0480 */
__asm__(".extern D_L23_001DE288, 4");
__asm__(".extern D_L23_001DE288, 4");
__asm__(".extern D_L23_001DE28C, 4");
__asm__(".extern D_L23_001DE290, 4");
__asm__(".extern D_L23_001DE294, 4");
__asm__(".extern D_L23_001DE274, 4");
extern s32 D_L23_001DE274;
extern s32 D_L23_001DE288;
extern f32 D_L23_001DE28C;
extern f32 D_L23_001DE290;
extern s32 D_L23_001DE294;
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, f32);
extern void func_L23_003B0708(void *, void *, s32, s32, s32, s32, s32, s32, s32);

void func_L23_003B0480(void *arg)
{
    P_3B0480 *p = ((S_3B0480 *)arg)->p;
    V4 a;
    V4 b;
    s32 c1;
    u32 c2;
    u32 c3;

    c2 = p->w220 ? 0x60000080 : 0x60008080;
    c3 = p->w220 ? 0x70707080 : 0x70608080;
    c1 = p->w220 ? 0x101080 : 0x6666;
    p->f238 -= 0.1f;
    if (p->f238 <= -8.0f) {
        p->f238 += 8.0f;
    }
    a = *(p->a2C0 + p->i2BC);
    b = *(p->a340 + p->i2BC);
    func_L01_0040A8C0(&a, &b, D_L23_001DE288, 1, D_L23_001DE290, 0.75f, c2, c2, c2, c2, p->f238);
    a = *(p->a3C0 + p->i2BC);
    b = *(p->a440 + p->i2BC);
    func_L01_0040A8C0(&a, &b, D_L23_001DE288, 1, D_L23_001DE290, 0.75f, c2, c2, c2, c2, p->f238);
    a = *(p->a2C0 + p->i2BC);
    b = *(p->a340 + p->i2BC);
    func_L01_0040A8C0(&a, &b, D_L23_001DE288, 1, D_L23_001DE28C, 0.75f, c3, c3, c3, c3, p->f238);
    a = *(p->a3C0 + p->i2BC);
    b = *(p->a440 + p->i2BC);
    func_L01_0040A8C0(&a, &b, D_L23_001DE288, 1, D_L23_001DE28C, 0.75f, c3, c3, c3, c3, p->f238);
    func_L23_003B0708(p->a340, p->a2C0, D_L23_001DE274, p->i2BC, 2, c1, 0x4C, 0x26, D_L23_001DE294);
    func_L23_003B0708(p->a440, p->a3C0, D_L23_001DE274, p->i2BC, 2, c1, 0x4C, 0x26, D_L23_001DE294);
}
/* localdecomp:end func_L23_003B0480 */

