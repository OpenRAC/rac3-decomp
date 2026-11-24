#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003BD218;
typedef int s128_3C1AB8 __attribute__((mode(TI)));
typedef union { s128_3C1AB8 q; f32 f[4]; } V_3C1AB8;
typedef struct {
    u8 pad[0x38];
    f32 f38;
    u8 pad3C[0x180 - 0x3C];
    s128_3C1AB8 v180;
    s128_3C1AB8 v190;
    s128_3C1AB8 v1A0;
    u8 pad1B0[0x1D0 - 0x1B0];
    s32 w1D0;
} P_3C1AB8;
typedef struct {
    u8 pad[0x10];
    s128_3C1AB8 pos;
    u8 pad20[0x68 - 0x20];
    P_3C1AB8 *p68;
} M_3C1AB8;
typedef int s128_3C1EE0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x20]; u8 b20; } M_3C1EE0;
typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[106];
    f32 unk6C;
    u8 pad70[128];
} S_002C5640;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[88];
    s32 a[6];
    s32 b[4];
    s32 c[4];
    u8 pad1[224];
    u8 d[16];
} Obj_003C3C68;
typedef int u128_3C3E90 __attribute__((mode(TI)));
typedef struct { u8 pad[0x25C4]; s32 w25C4; u8 pad25C8[0x283C - 0x25C8]; f32 f283C; } G_3C4008;
typedef struct { u8 pad[0x98]; s32 w98; } P_3C4008;
typedef struct { u8 pad[0x54]; P_3C4008 *p54; u8 pad58[0x100 - 0x58]; u8 b100; } B_3C4008;
typedef struct { u8 pad[0x20]; u8 b20; } M_3C4008;
typedef struct {
    u8 pad0[1724];
    s32 idx;
    s32 arr[1];
} S_3C40F0;
typedef struct {
    u8 p0[0x24];
    s32 id;
    u8 p28[0x698];
    s32 a1728[36];
    s32 a1872[4];
} O_3C41F8;
typedef struct { u8 p0[0x34]; u16 h52; u8 p36[0xCA]; } M_3C41F8;
typedef struct M3C48A8 M3C48A8;
typedef struct {
    u8 pad0[80];
    s32 link;
    u8 pad84[1360 - 84];
    M3C48A8 *child;
} V3C48A8;
struct M3C48A8 {
    u8 pad0[32];
    u8 state;
    u8 pad21[52 - 33];
    u16 flags;
    u8 pad36[104 - 54];
    V3C48A8 *vars;
    u8 pad6C[152 - 108];
    s32 f98;
    u8 pad9C[256 - 156];
};
typedef struct {
    u8 pad0[258];
    u8 active;
    u8 pad103[264 - 259];
    s32 group;
} O3C48A8;

LINKER_REMNANT("asm/levels", func_L01_003BE598);

/* localdecomp:start func_L01_003BE5A0 */
#include "vu0.h"
extern f32 D_L01_001DEB80;
extern f32 D_L01_001DEB84;
__asm__(".extern D_L01_001DEB80, 4");
__asm__(".extern D_L01_001DEB84, 4");
extern s32 D_001A71A0[];
typedef struct { u128_t position, normal; } HitPair_003BE5A0;
extern HitPair_003BE5A0 D_L01_001EAA30;
extern vu0_v4 D_L01_001EAA20;
void func_L01_003BE5A0(u8 *m) {
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003C5278(void *, void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, s32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_004561B8(u8 *);
    extern void func_L01_0044C638(u8 *, M_3C1AB8 *, void *, void *, void *, void *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern s32 func_L01_00448070(s32, s32, f32);
    extern void func_003C2880(u8 *);
    V_3C1AB8 a, b;
    u8 *p = *(u8 **)(m + 0x68);
    f32 *velocity;
    u8 *pos;
    u8 *ground_pos;
    u8 *normal;
    f32 fade;
    s32 one = 1;
    u8 *hit;
    M_3C1AB8 *object;
    switch (m[0x20]) {
    case 0:
        pos = m + 0x10;
        a.q = *(u128_t *)pos;
        velocity = (f32 *)(p + 0x20);
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), *(f32 *)(p + 8));
        vec_add_ab(pos, pos, velocity);
        func_003C5278(pos, velocity, velocity, D_L01_001DEB80 * 0.00040000002f);
        if (func_L01_003FB640(pos, 4, D_001A71A0[0], 0.07f)) {
            *(u128_t *)pos = D_L01_001EAA30.position;
            normal = (u8 *)&D_L01_001EAA30.normal;
            if (func_0038CE68(velocity, normal) < 0.0f) {
                func_L01_0040E790(velocity, velocity, normal);
                func_0038CE20(velocity, velocity, 0.15f);
            }
            goto speed_check;
        } else if (func_003D3CB0(&a, pos, 2, 0, 0)) {
            *(u128_t *)pos = *(u128_t *)&D_L01_001EAA20;
            func_L01_0040E790(velocity, velocity, (u8 *)&D_L01_001EAA20 + 0x20);
            func_0038CE20(velocity, velocity, 0.15f);
speed_check:
            if (func_0038CEA8(velocity) < 0.014f) {
                m[0x20] = one;
                break;
            }
        }
        if (func_0038CAD0(p) || *(f32 *)(m + 0x10) < 2.0f || *(f32 *)(m + 0x10) > 1021.0f ||
            *(f32 *)(m + 0x14) < 2.0f || *(f32 *)(m + 0x14) > 1021.0f ||
            *(f32 *)(m + 0x18) < 2.0f) goto destroy;
        if (!(*(f32 *)(m + 0x18) > 1021.0f)) break;
        goto destroy;
    case 1:
        if (func_L01_004561B8(m)) {
            a.q = *(u128_t *)(m + 0x10);
            a.f[2] += 1.0f;
            b.q = a.q;
            b.f[2] = 0.0f;
            if (func_003D3CB0(&a, &b, 0, (M_3C1AB8 *)m, 0)) *(f32 *)(m + 0x18) = D_L01_001EAA20.z + 0.057f;
        } else {
            ground_pos = m + 0x10;
            a.q = *(u128_t *)ground_pos;
            a.f[2] += 1.0f;
            b.q = a.q;
            b.f[2] = 0.0f;
            if (func_003D3CB0(&a, &b, 0, (M_3C1AB8 *)m, 0)) {
                /* The collision record starts 0x20 bytes before its position vector. */
                hit = (u8 *)&D_L01_001EAA20 - 0x20;
                object = *(M_3C1AB8 **)(hit + 0x18);
                if (object != 0) func_L01_0044C638(m, object, ground_pos, m + 0xF0, ground_pos, m + 0xF0);
                else *(f32 *)(m + 0x18) = *(f32 *)(hit + 0x28) + 0.057f;
            }
        }
        if (m[0x95] == 1) func_L01_004450F0(m, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(m)) *(u16 *)(m + 0x34) |= 0x2800;
        ground_pos = m + 0x10;
        a.q = *(u128_t *)ground_pos;
        a.f[2] += 1.0f;
        b.q = a.q;
        b.f[2] = 0.0f;
        if (func_003D3CB0(&a, &b, 0, (M_3C1AB8 *)m, 0)) {
            hit = (u8 *)&D_L01_001EAA20 - 0x20;
            object = *(M_3C1AB8 **)(hit + 0x18);
            if (object != 0) func_L01_0044C638(m, object, ground_pos, m + 0xF0, ground_pos, m + 0xF0);
            else *(f32 *)(m + 0x18) = *(f32 *)(hit + 0x28) + 0.057f;
        }
        fade = (f32)*(u16 *)(m + 0x96) / D_L01_001DEB84;
        fade = 1.0f < fade ? 1.0f : fade;
        m[0x23] = func_L01_00448070(128, 0, fade);
        if (m[0x23] < 2) {
destroy:
            func_003C2880(m);
            return;
        }
        break;
    }
    (*(u16 *)(m + 0x96))++;
}
/* localdecomp:end func_L01_003BE5A0 */

LINKER_REMNANT("asm/levels", func_L01_003BEA58);

/* localdecomp:start func_L01_003BEA60 */

extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];

s32 func_L01_003BEA60(Moby_003BD218 *m) {
    u8 *p = m->w68;
    if ((p != 0 && *(s32 *)(p + 264) == 2) || D_L01_001D6740 != 0 || D_001A4F48[0] != 0) return 1;
    return 0;
}
/* localdecomp:end func_L01_003BEA60 */

/* localdecomp:start func_L01_003BEAA0 */
extern s32 D_L01_001D673C_003BEAA0;
s32 func_L01_003BEAA0(void) {
    return D_L01_001D673C_003BEAA0;
}
/* localdecomp:end func_L01_003BEAA0 */

/* localdecomp:start func_L01_003BEAA8 */
s32 func_L01_003BEAA8(u32 a) {
    s32 r = 0;
    if (a < 2 || a == 11 || a == 13 || a == 14) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003BEAA8 */

/* localdecomp:start func_L01_003BEAE0 */
typedef union { vu0_q q; f32 f[4]; } Q_3BEAE0;
typedef struct { u8 pad0[0x10]; s32 w10; } P24_3BEAE0;
struct V_3BEAE0;
typedef struct M_3BEAE0 {
    u8 pad0[0x10];
    Q_3BEAE0 pos;
    u8 state;
    u8 pad21[2];
    u8 b23;
    P24_3BEAE0 *p24;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0xA];
    u8 pad40[2];
    u8 anim;
    u8 b43;
    u8 pad44[4];
    f32 speed;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[7];
    struct V_3BEAE0 *vars;
    u8 pad6C[0xC];
    u32 w78;
    u8 pad7C[0x1C];
    s32 w98;
    u8 pad9C[0xE];
    s16 oclass;
    u8 padAC[0xC];
    s32 wB8;
    u8 padBC[4];
    vu0_q qC0;
    vu0_q qD0;
    vu0_q qE0;
    Q_3BEAE0 rot;
} M_3BEAE0;
typedef struct V_3BEAE0 {
    u8 pad0[0x30];
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    u8 pad44[0x18];
    s32 f5C;
    f32 f60;
    f32 f64;
    s32 f68;
    u8 pad6C[0xB4];
    vu0_q q120;
    u8 pad130[4];
    u8 f134[8];
    s32 f13C;
    M_3BEAE0 *f140;
    s32 f144;
    u8 pad148[4];
    f32 f14C;
    s32 f150;
    u8 pad154[8];
    s16 h15C;
    u8 pad15E[2];
    Q_3BEAE0 v160;
    Q_3BEAE0 v170;
    Q_3BEAE0 v180;
    Q_3BEAE0 v190;
    Q_3BEAE0 v1A0;
    u8 pad1B0[0x10];
    s32 f1C0;
    u8 pad1C4[4];
    f32 f1C8;
    f32 f1CC;
    M_3BEAE0 *f1D0;
    f32 f1D4;
    u8 pad1D8[0x128];
    M_3BEAE0 *f300;
    u8 f304[4];
    s32 f308;
    u8 pad30C[4];
    f32 f310;
    f32 f314;
    u8 pad318[8];
    Q_3BEAE0 v320;
    u8 f330[0xC];
    s32 f33C;
    s32 f340;
    s32 f344;
} V_3BEAE0;
typedef struct {
    u8 pad0[0x80];
    Q_3BEAE0 pos;
    u8 pad90[0x368 - 0x90];
    s16 h368;
    u8 pad36A[0x25C0 - 0x36A];
    M_3BEAE0 *moby;
} H_3BEAE0;
extern H_3BEAE0 D_001A4BE0_003BEAE0;
extern s32 D_L01_001E2200[2];
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];
extern vu0_q D_L01_001E21C0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E29C0[];
extern u8 *D_L01_002210B4[];
extern s32 D_L01_001E2230;
extern s32 D_L01_001DFB40;

extern s32 func_L01_003C1978(void *);
extern s32 func_L01_003BEAA0_003BEAE0(void);
extern void func_L01_003C38D0(u8 *);
extern void func_L01_003C39A8(u8 *);
extern void func_L01_003C2E88(M_3C1AB8 *, f32);
extern void func_L01_003C3320(M_3C1AB8 *);
extern s32 func_L01_003C3410_003BEAE0(u8 *);
extern void func_L01_003C35A0(M_3C1EE0 *);
extern u8 *func_L01_003968F8(void *, s32, void *, void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
extern s32 func_L01_003FB640(void *, s32, s32, f32);
extern s32 func_003D5630(void);
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_0038D570(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038DC20(void *, f32);
extern f32 func_L01_004395E0(void *);
extern u8 *func_00382348(void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3DA0(void *, void *, s32, f32, void *);
extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_003C48A8(void *, void *);
extern void func_003C4C18(s128_3C1EE0 *, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_0045A898(void *, void *, f32);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045CED0(void *, void *);
extern s32 func_L01_0045D218(void *, void *);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_004C7D98(u8 *, u8 *);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004CB128(void *, void *, s32);
extern s32 func_L01_004CB2D8(void);
extern s32 func_0013D3E0(void);

void func_L01_003BEAE0(M_3BEAE0 *m) {
    V_3BEAE0 *v = m->vars;
    Q_3BEAE0 pos0;
    Q_3BEAE0 t;
    Q_3BEAE0 t2;

    if (func_L01_003C1978(m)) {
        func_L01_003C38D0((u8 *)m);
        return;
    }
    if (v->f13C == 0) {
        switch (m->state) {
        case 13:
            if (func_0038CAD0(&v->f340) || v->f140 == 0) {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0((u8 *)m, 12, -1);
            } else {
                func_L01_0045BD78(m, 0.00173333345f, v->f310 * 0.0200000014f, 0.00502654864f, 0.251327425f);
                func_L01_004CB128(&pos0, v->f140, 0);
                func_L01_0045D218(m, &pos0);
            }
            break;
        case 17: {
            s32 hit;
            func_L01_003C35A0((M_3C1EE0 *)m);
            hit = 0;
            m->speed = 1.0f;
            if (m->anim == 5) {
                if (func_L01_0044E1B8(m, 59.0f)) {
                    hit = 1;
                    if (func_00382468(2)) {
                        if (m->b43 != hit) func_003C3A10(m, 1, 0, 3);
                    } else {
                        if (m->b43 != 4) func_003C3A10(m, 4, 0, 3);
                    }
                }
            }
            if (m->anim == 4) {
                if (func_L01_0044E1B8(m, 30.0f)) {
                    hit = 1;
                    if (func_00382468(2)) {
                        if (m->b43 != hit) func_003C3A10(m, 1, 0, 3);
                    } else {
                        if (m->b43 != 5) func_003C3A10(m, 5, 0, 3);
                    }
                }
            }
            if (m->anim == 1) {
                if (func_L01_0044E1B8(m, 35.0f)) {
                    hit = 1;
                    if (func_00382468(2)) {
                        if (m->b43 != 5) func_003C3A10(m, 5, 0, 3);
                    } else {
                        if (m->b43 != 4) func_003C3A10(m, 4, 0, 3);
                    }
                }
            }
            if (hit) {
                if (1.5f < func_0038CF00(&m->pos, &D_001A4BE0_003BEAE0.pos)) {
                    if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                    func_L01_004450F0((u8 *)m, 12, -1);
                    m->speed = 3.0f;
                }
            }
            break;
        }
        case 12:
            m->flags |= 0x100;
            v->f34 = 0.25f;
            v->f68 |= 4;
            v->f64 = 0.5f;
            v->f30 = 0.25f;
            v->f60 = 2.09439516f;
            v->f38 = 0.75f;
            v->f3C = 1.0f;
            v->f5C = 0;
            v->f40 = 6.28318548f;
            func_L01_0045BD78(m, 0.00173333345f, v->f310 * 0.0200000014f, 0.00502654864f, 0.251327425f);
            func_L01_0045D218(m, &D_001A4BE0_003BEAE0.pos);
            if (func_0038CF00(&m->pos, &D_001A4BE0_003BEAE0.pos) < 1.75f) {
                if (v->f140 == 0) {
                    if (m->b43 != 5) func_003C3A10(m, 5, 0, 8);
                    func_L01_004450F0((u8 *)m, 17, -1);
                    m->speed = 0.5f;
                }
            }
            break;
        case 15:
            if (func_0038CAD0(&v->f340) || v->f140 == 0) {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0((u8 *)m, 14, -1);
            } else {
                func_L01_0045BD78(m, 0.00520000048f, v->f310 * 0.0200000014f, 0.00502654864f, 0.251327425f);
                func_L01_004CB128(&pos0, v->f140, 0);
                func_L01_0045CED0(m, &pos0);
                func_003C3DA0(&m->pos, &m->pos, 0, 0.5f, 0);
            }
            break;
        case 14: {
            vu0_q *pp;
            m->flags |= 0x100;
            pp = &m->pos.q;
            v->f68 |= 1;
            func_L01_0045BD78(m, 0.00520000048f, v->f310 * 0.0200000014f, 0.00502654864f, 0.251327425f);
            func_L01_0045CED0(m, &D_001A4BE0_003BEAE0.pos);
            func_003C3DA0(pp, pp, 0, 0.5f, 0);
            if (func_0038CF00(pp, &D_001A4BE0_003BEAE0.pos) < 1.0f) {
                if (m->b43 != 5) func_003C3A10(m, 5, 0, 8);
                func_L01_004450F0((u8 *)m, 0, -1);
                m->speed = 0.5f;
            }
            break;
        }
        case 3: {
            s32 mode;
            f32 ang;
            f32 *yp;
            Q_3BEAE0 *vp;
            if (D_001A4BE0_003BEAE0.h368 != 0) {
                func_L01_004450F0((u8 *)m, 12, -1);
                break;
            }
            if (func_L01_003BEAA0_003BEAE0()) {
                func_L01_004450F0((u8 *)m, 14, -1);
                break;
            }
            if (func_L01_004561B8((u8 *)m)) {
                M_3BEAE0 *p = D_001A4BE0_003BEAE0.moby;
                v->f1D0 = p;
                v->v190.q = p->pos.q;
                v->v180.q = p->pos.q;
                v->v1A0.q = p->pos.q;
                func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                v->v170.q = m->pos.q;
                func_L01_0045BD78(m, 0.00520000048f, v->f310 * 0.0200000014f, 0.00502654864f, 0.251327425f);
            }
            mode = func_L01_003C3410_003BEAE0((u8 *)m);
            if (mode == 0) {
                func_L01_003C3320((M_3C1AB8 *)m);
                pos0.q = D_001A4BE0_003BEAE0.pos.q;
                if (func_0038CF38(&v->v1A0, &pos0) > 1.0f) {
                    v->v180.q = v->f1D0->pos.q;
                    v->v1A0.q = v->f1D0->pos.q;
                    func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                    v->v170.q = m->pos.q;
                    v->f1C0 = 0;
                }
                vp = &v->v180;
                if (func_0038CF38(&m->pos, vp) < 0.75f) {
                    v->v180.q = v->f1D0->pos.q;
                    v->v1A0.q = v->f1D0->pos.q;
                    func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                    v->v170.q = m->pos.q;
                    v->f1C0 = 0;
                }
                if (func_0038CF38(&m->pos, &v->v170) > 4.0f) {
                    v->v180.q = v->f1D0->pos.q;
                    v->v1A0.q = v->f1D0->pos.q;
                    func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                    v->v170.q = m->pos.q;
                    v->f1C0 = 0;
                }
                v->v190.q = v->f1D0->pos.q;
                yp = &m->rot.f[2];
                func_L01_0045A898(m, vp, m->rot.f[2]);
                ang = func_0038D160(v->v180.f[0] - m->pos.f[0], v->v180.f[1] - m->pos.f[1]);
                func_L01_00448890(yp, ang, v->f134, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
            }
            if (func_0038CF38(&m->pos, &D_001A4BE0_003BEAE0.pos) < func_003824E0(1.0f, 4.0f)) {
                if (m->b43 != 5) func_003C3A10(m, 5, 0, 8);
                func_L01_004450F0((u8 *)m, 0, -1);
                m->speed = 0.5f;
            }
            if (mode == 1) {
                if (v->f1CC <= m->pos.f[2] || fabs_asm(m->pos.f[2] - v->f1CC) < 0.5f) {
                    func_L01_004450F0((u8 *)m, 9, -1);
                } else {
                    func_L01_004450F0((u8 *)m, 10, -1);
                }
                if (m->b43 != 8) func_003C3A10(m, 8, 0, 7);
            } else if (mode == 2) {
                u8 x;
                if (v->h15C != -1) D_L01_001E2200[v->h15C] = 0;
                x = D_L01_002C5600[D_001425C0[87]].unk1;
                if (x != 0) if (x < 4) {
                    u8 *e = func_L01_003968F8(m, v->f308, &m->pos, (u8 *)D_001A4BE0_003BEAE0.moby + 0xC0, 1, 0);
                    if (e) *(s32 *)(e + 0xB8) = m->wB8;
                }
                func_L01_003C39A8((u8 *)m);
            }
            break;
        }
        case 9: {
            f32 d;
            u8 *s;
            vu0_q *pp;
            func_L01_003C35A0((M_3C1EE0 *)m);
            pp = &m->pos.q;
            pos0.q = m->pos.q;
            if (func_L01_004561B8((u8 *)m)) {
                v->f1C8 = 0;
                v->f1D4 = m->pos.f[2];
                v->v160.f[2] = v->f1CC;
                v->f150 = 0;
            }
            if (v->f140) {
                s = func_00382348(v->f140);
                if (func_0038CF38(pp, &v->f140->pos) < 2.0f && v->f140 && v->f140->state != 0xFE &&
                    v->f140->state != 0xFD && s && *(f32 *)s > 0.0f && !(v->f140->flags & 2) &&
                    v->f140->oclass != 0x1AE6) {
                    u8 x;
                    if (v->h15C != -1) D_L01_001E2200[v->h15C] = 0;
                    x = D_L01_002C5600[D_001425C0[87]].unk1;
                    if (x != 0) if (x < 4) {
                        u8 *e = func_L01_003968F8(m, v->f308, pp, (u8 *)D_001A4BE0_003BEAE0.moby + 0xC0, 1, 0);
                        if (e) *(s32 *)(e + 0xB8) = m->wB8;
                    }
                    func_L01_003C39A8((u8 *)m);
                    break;
                }
            }
            d = func_L01_004395E0(m);
            if ((m->anim == 8 && 7.0f <= d) || (*(long *)&m->pad40 & 0xFFFF0000) == 0x07FF0000 ||
                m->anim == 6 || (m->anim == 7 && d <= 28.0f)) {
                if (m->pos.f[2] != v->f1CC) {
                    f32 k = 0.200000018f;
                    t.f[0] = func_0038D098(m->rot.f[2]) * k;
                    t.f[1] = func_0038D0B0(m->rot.f[2]) * k;
                    t.f[2] = 0;
                    vec_add_ab(&pos0, &pos0, &t);
                }
            }
            if (m->b43 == 6) {
                if (fabs_asm(v->f1CC - m->pos.f[2]) <= 1.35000002f) {
                    if (m->anim == 6) func_003C3A10(m, 7, 0, 0);
                    else func_003C3A10(m, 7, 0, 7);
                } else if (m->anim != 6) {
                    func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.00200000009f, 0.00400000019f, 0.0800000057f);
                } else {
                    func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.0160000008f, 0.0400000028f, 0.76000005f);
                }
            }
            if ((*(long *)&m->pad40 & 0xFFFF0000) == 0x08080000) {
                if (7.0f <= func_L01_004395E0(m) && m->anim == m->b43) {
                    func_003C41A0(&pos0.f[2], &v->f1C8, v->f1D4 + 1.35000002f, 0.0280000009f, 0.00800000038f, 0.600000024f);
                }
                if (m->b60 & 2) {
                    v->f1C8 = 0;
                    if (m->b43 != 6) func_003C3A10(m, 6, 0, 12);
                }
            }
            if (m->anim == 7) {
                if (func_L01_004395E0(m) <= 28.0f) {
                    func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.0120000001f, 0.0400000028f, 0.150000006f);
                }
                if (m->b60 & 2) {
                    if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                    func_L01_004450F0((u8 *)m, 3, -1);
                }
            }
            if (m->b43 == 7 && m->anim != m->b43 && m->anim != 6) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.00200000009f, 0.0120000001f, 0.0800000057f);
            }
            vec_sub_ab(&t, &pos0, &m->pos);
            func_L01_0045AA30(m, &t);
            break;
        }
        case 10: {
            f32 d;
            u8 *s;
            vu0_q *pp;
            func_L01_003C35A0((M_3C1EE0 *)m);
            pp = &m->pos.q;
            pos0.q = m->pos.q;
            if (func_L01_004561B8((u8 *)m)) {
                v->f1C8 = 0;
                v->f1D4 = m->pos.f[2];
                v->v160.f[2] = v->f1CC;
                v->f150 = 0;
            }
            if (v->f140) {
                s = func_00382348(v->f140);
                if (func_0038CF38(pp, &v->f140->pos) < 2.0f && v->f140 && v->f140->state != 0xFE &&
                    v->f140->state != 0xFD && s && *(f32 *)s > 0.0f && !(v->f140->flags & 2) &&
                    v->f140->oclass != 0x1AE6) {
                    u8 x;
                    if (v->h15C != -1) D_L01_001E2200[v->h15C] = 0;
                    x = D_L01_002C5600[D_001425C0[87]].unk1;
                    if (x != 0) if (x < 4) {
                        u8 *e = func_L01_003968F8(m, v->f308, pp, (u8 *)D_001A4BE0_003BEAE0.moby + 0xC0, 1, 0);
                        if (e) *(s32 *)(e + 0xB8) = m->wB8;
                    }
                    func_L01_003C39A8((u8 *)m);
                    break;
                }
            }
            d = func_L01_004395E0(m);
            if ((m->anim == 8 && 7.0f <= d) || (*(long *)&m->pad40 & 0xFFFF0000) == 0x07FF0000 ||
                m->anim == 6 || (m->anim == 7 && d <= 28.0f)) {
                if (m->pos.f[2] != v->f1CC) {
                    f32 k = 0.26000002f;
                    t.f[0] = func_0038D098(m->rot.f[2]) * k;
                    t.f[1] = func_0038D0B0(m->rot.f[2]) * k;
                    t.f[2] = 0;
                    vec_add_ab(&pos0, &m->pos, &t);
                }
            }
            if (m->b43 == 6) {
                if (fabs_asm(v->f1CC - m->pos.f[2]) <= 1.0f && v->f1C8 <= 0.0f) {
                    if (m->anim == 6) func_003C3A10(m, 7, 0, 0);
                    else func_003C3A10(m, 7, 0, 7);
                } else {
                    u8 a = m->anim;
                    if (a != 6) func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.0160000008f, 0.0400000028f, 0.76000005f);
                    if (a == 6) func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.0160000008f, 0.0400000028f, 0.76000005f);
                }
            }
            if ((*(long *)&m->pad40 & 0xFFFF0000) == 0x08080000) {
                if (7.0f <= func_L01_004395E0(m) && m->anim == m->b43) {
                    func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC + 4.0f, 0.0280000009f, 0.00800000038f, 1.20000005f);
                }
                if (m->b60 & 2) {
                    if (m->b43 != 6) func_003C3A10(m, 6, 0, 12);
                }
            }
            if (m->anim == 7) {
                if (func_L01_004395E0(m) <= 28.0f) {
                    func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.0160000008f, 0.0400000028f, 0.76000005f);
                }
                if (m->b60 & 2) {
                    if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                    func_L01_004450F0((u8 *)m, 3, -1);
                }
            }
            if (m->b43 == 7 && m->anim != m->b43 && m->anim != 6) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.0160000008f, 0.0400000028f, 0.76000005f);
            }
            vec_sub_ab(&t, &pos0, &m->pos);
            func_L01_0045AA30(m, &t);
            break;
        }
        case 0: {
            s32 hit;
            f32 ang;
            f32 *yp;
            vu0_q *pp;
            if (func_L01_003BEA60((Moby_003BD218 *)m)) {
                Q_3BEAE0 mtx[4];
                Q_3BEAE0 *rot;
                pos0.q = m->qE0;
                rot = &m->rot;
                func_0038CF68(&pos0, &pos0, -1.0f);
                vec_sub_ba(&t, D_L01_001E29C0, &m->pos);
                func_0038CF68(&t, &t, 1.0f);
                func_0038CE90(&t, &t, &pos0);
                func_0038CE90(&t2, &t, &pos0);
                m->qC0 = t2.q;
                m->qD0 = t.q;
                m->qE0 = pos0.q;
                m->rot.q = m->pos.q;
                func_0038D570(mtx, &m->qC0);
                func_003C48A8(mtx, rot);
            }
            func_L01_003C35A0((M_3C1EE0 *)m);
            if (v->f300 && v->f300->state != 0xFE && v->f300->state != 0xFD) {
                yp = &m->rot.f[2];
                ang = func_0038D160(v->f300->pos.f[0] - m->pos.f[0], v->f300->pos.f[1] - m->pos.f[1]);
                func_L01_00448890(yp, ang, v->f304, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
            }
            hit = 0;
            if (m->anim == 5) {
                if (func_L01_0044E1B8(m, 59.0f)) {
                    hit = 1;
                    if (func_00382468(2)) {
                        if (m->b43 != hit) func_003C3A10(m, 1, 0, 3);
                    } else {
                        if (m->b43 != 4) func_003C3A10(m, 4, 0, 3);
                    }
                }
            }
            if (m->anim == 4) {
                if (func_L01_0044E1B8(m, 30.0f)) {
                    hit = 1;
                    if (func_00382468(2)) {
                        if (m->b43 != hit) func_003C3A10(m, 1, 0, 3);
                    } else {
                        if (m->b43 != 5) func_003C3A10(m, 5, 0, 3);
                    }
                }
            }
            if (m->anim == 1) {
                if (func_L01_0044E1B8(m, 35.0f)) {
                    hit = 1;
                    if (func_00382468(2)) {
                        if (m->b43 != 5) func_003C3A10(m, 5, 0, 3);
                    } else {
                        if (m->b43 != 4) func_003C3A10(m, 4, 0, 3);
                    }
                }
            }
            if (hit) {
                if (!func_00382468(3) &&
                    (v->f300 == 0 || v->f300->state == 0xFE || v->f300->state == 0xFD) &&
                    !func_L01_003BEA60((Moby_003BD218 *)m) && !func_L01_003BEAA0_003BEAE0()) {
                    if (m->b43 != 2) func_003C3A10(m, 2, 0, 14);
                    func_L01_004450F0((u8 *)m, 1, -1);
                }
                if (4.0f < func_0038CF38(&m->pos, &D_001A4BE0_003BEAE0.pos) &&
                    !func_L01_003BEA60((Moby_003BD218 *)m) && !func_L01_003BEAA0_003BEAE0()) {
                    if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                    func_L01_004450F0((u8 *)m, 3, -1);
                    break;
                }
                if (func_L01_003BEA60((Moby_003BD218 *)m) || func_L01_003BEAA0_003BEAE0()) {
                    if (2.0f < func_0038CF38(&m->pos, &D_001A4BE0_003BEAE0.pos)) {
                        if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                        func_L01_004450F0((u8 *)m, 3, -1);
                    }
                }
            }
            break;
        }
        case 1: {
            f32 ang;
            f32 *yp;
            if (func_L01_004561B8((u8 *)m)) {
                f32 a;
                f32 b;
                v->f64 = 0.400000006f;
                func_L01_0045BD78(m, 0.000400000019f, 0.00500000035f, 0.00251327432f, 0.0209439527f);
                a = func_00382538();
                b = func_003824E0(2.0f, 6.0f);
                qzero(&v->v160);
                v->v160.f[0] = func_0038D098(a) * b;
                v->v160.f[1] = func_0038D0B0(a) * b;
                vec_add_ba(&v->v160, &v->v160, &D_001A4BE0_003BEAE0.pos);
                v->f68 |= 3;
            }
            func_L01_0045A898(m, &v->v160, m->rot.f[2]);
            yp = &m->rot.f[2];
            ang = func_0038D160(v->v160.f[0] - m->pos.f[0], v->v160.f[1] - m->pos.f[1]);
            func_L01_00448890(yp, ang, v->f134, 0.00181514258f, 0.00181514258f, 0.0209439527f, 0);
            if (func_0038CF38(&m->pos, &v->v160) <= 0.5f) {
                f32 a;
                f32 b;
                a = func_00382538();
                b = func_003824E0(2.0f, 6.0f);
                qzero(&v->v160);
                v->v160.f[0] = func_0038D098(a) * b;
                v->v160.f[1] = func_0038D0B0(a) * b;
                vec_add_ab(&v->v160, &v->v160, &D_001A4BE0_003BEAE0.pos);
            }
            if (5.5f < func_0038CF38(&m->pos, &D_001A4BE0_003BEAE0.pos)) {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0((u8 *)m, 3, -1);
            }
            break;
        }
        case 5: {
            s32 mode;
            f32 ang;
            f32 *yp;
            Q_3BEAE0 *vp;
            vu0_q *pp;
            u8 *s;
            if (v->f300 && v->f300->state != 0xFE && v->f300->state != 0xFD) {
                yp = &m->rot.f[2];
                ang = func_0038D160(v->f300->pos.f[0] - m->pos.f[0], v->f300->pos.f[1] - m->pos.f[1]);
                func_L01_00448890(yp, ang, v->f304, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
            }
            if (func_L01_004561B8((u8 *)m) && v->f140) {
                M_3BEAE0 *p;
                func_L01_0045BD78(m, 0.00520000048f, v->f314 * 0.0200000014f, 0.00502654864f, 0.251327425f);
                p = v->f140;
                v->f1D0 = p;
                v->v190.q = p->pos.q;
                v->v180.q = p->pos.q;
                v->v1A0.q = p->pos.q;
                func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                v->v170.q = m->pos.q;
                m->w78 = 0x80202080;
            }
            mode = func_L01_003C3410_003BEAE0((u8 *)m);
            if (mode == 0) {
                func_L01_003C3320((M_3C1AB8 *)m);
                pos0.q = v->f1D0->pos.q;
                if (func_0038CF38(&v->v1A0, &pos0) > 1.0f ||
                    (v->f140 && D_L01_001DFB40 % 5 == 0 && v->f140->oclass == 0x1AB8)) {
                    v->v180.q = v->f1D0->pos.q;
                    v->v1A0.q = v->f1D0->pos.q;
                    func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                    v->v170.q = m->pos.q;
                    v->f1C0 = 0;
                }
                pp = &m->pos.q;
                vp = &v->v180;
                if (func_0038CF38(pp, vp) < 0.75f) {
                    v->v180.q = v->f1D0->pos.q;
                    v->v1A0.q = v->f1D0->pos.q;
                    func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                    v->v170.q = m->pos.q;
                    v->f1C0 = 0;
                }
                if (func_0038CF38(pp, &v->v170) > 4.0f) {
                    v->v180.q = v->f1D0->pos.q;
                    v->v1A0.q = v->f1D0->pos.q;
                    func_L01_003C2E88((M_3C1AB8 *)m, 12.0f);
                    v->v170.q = m->pos.q;
                    v->f1C0 = 0;
                }
                yp = &m->rot.f[2];
                func_L01_0045A898(m, vp, m->rot.f[2]);
                ang = func_0038D160(v->v180.f[0] - m->pos.f[0], v->v180.f[1] - m->pos.f[1]);
                func_L01_00448890(yp, ang, v->f134, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
            }
            v->v190.q = v->f1D0->pos.q;
            if (mode == 1) {
                if (v->f1CC <= m->pos.f[2] || fabs_asm(m->pos.f[2] - v->f1CC) < 0.5f) {
                    func_L01_004450F0((u8 *)m, 9, -1);
                } else {
                    func_L01_004450F0((u8 *)m, 10, -1);
                }
                if (m->b43 != 8) func_003C3A10(m, 8, 0, 7);
            } else if (mode == 2) {
                if (m->b43 != 5) func_003C3A10(m, 5, 0, 8);
                func_L01_004450F0((u8 *)m, 0, -1);
                m->speed = 0.5f;
                yp = &m->rot.f[2];
                ang = func_0038D160(v->v190.f[0] - m->pos.f[0], v->v190.f[1] - m->pos.f[1]);
                func_L01_00448890(yp, ang, v->f134, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
            }
            if (v->f140) {
                s = func_00382348(v->f140);
                if (v->f140 == 0 || v->f140->state == 0xFE || v->f140->state == 0xFD || (s && *(f32 *)s <= 0.0f)) {
                    func_L01_004450F0((u8 *)m, 3, -1);
                    if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                }
                func_L01_0045A898(m, &v->v190, m->rot.f[2]);
                if (func_0038CAD0(&v->f344) ||
                    (func_0038CF38(&m->pos, &v->f140->pos) < 2.0f && v->f140 && v->f140->state != 0xFE &&
                     v->f140->state != 0xFD && !(v->f140->flags & 2) && v->f140->oclass != 0x1AE6)) {
                    u8 x;
                    if (v->h15C != -1) D_L01_001E2200[v->h15C] = 0;
                    x = D_L01_002C5600[D_001425C0[87]].unk1;
                    if (x != 0) if (x < 4) {
                        u8 *e = func_L01_003968F8(m, v->f308, &m->pos, (u8 *)D_001A4BE0_003BEAE0.moby + 0xC0, 1, 0);
                        if (e) *(s32 *)(e + 0xB8) = m->wB8;
                    }
                    func_L01_003C39A8((u8 *)m);
                }
            } else {
                func_L01_004450F0((u8 *)m, 3, -1);
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
            }
            break;
        }
        case 11:
            func_L01_003C35A0((M_3C1EE0 *)m);
            if (fabs_asm(v->v320.f[2] - m->pos.f[2]) > 0.200000003f) {
                func_L01_00448340(&m->pos, &v->v320, v->f330, 0.000800000038f, 0.000800000038f, 0.0800000057f);
                v->f68 |= 4;
            } else {
                func_L01_004450F0((u8 *)m, 5, -1);
                v->f344 = 350;
                func_003C3A10(m, 3, 0, 0);
                v->f68 |= 1;
            }
            break;
        }
    } else if (v->f13C == 1) {
        switch (m->state) {
        case 16:
            if (func_0038CAD0(&v->f33C) == 0) {
                u32 c;
                s32 r;
                s32 n;
                u8 *e;
                pos0.q = m->pos.q;
                t.q = 0;
                func_003C4C18(&pos0.q, 0.300000012f);
                c = func_0013D3E0() & 0x2F;
                c |= ((func_0013D3E0() + 0x10) & 0x3F) << 8;
                c |= 0x7F0000;
                c |= 0xFF000000;
                r = func_0013D3E0() % 2;
                n = func_00382498(20, 40);
                e = func_L01_0046B458(&pos0, n, func_003824E0(0.349999994f, 0.600000024f), 0.00100000005f, c, 2, r, &t, -0.00180000009f, 0);
                if (e) {
                    e[3] = 0x48;
                    e[2] = D_L01_002210B4[0x61][func_00382468(4)];
                }
                m->flags |= 0x200;
                m->b23 += 4;
                m->rot.f[2] = func_0038DAB8(m->rot.f[2], func_003824E0(100.0f, 1440.0f) * 0.0174532924f * 0.0200000014f);
            } else {
                m->b23 = 0x80;
                m->flags &= ~0x200;
                func_L01_004450F0((u8 *)m, 7, -1);
            }
            break;
        case 6: {
            f32 ang;
            f32 *yp;
            m->w98 = 0;
            yp = &m->rot.f[2];
            func_L01_00448340(&m->pos, &D_L01_001E21C0[v->h15C], &v->f14C, func_003824E0(2.0f, 3.0f) * 0.000400000019f,
                              func_003824E0(1.0f, 2.0f) * 0.000400000019f, func_003824E0(3.5f, 5.0f) * 0.0200000014f);
            ang = func_0038D160(D_001A4BE0_003BEAE0.pos.f[0] - m->pos.f[0], D_001A4BE0_003BEAE0.pos.f[1] - m->pos.f[1]);
            func_L01_00448890(yp, ang, v->f304, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
            if (func_0038CF38(&m->pos, &D_L01_001E21C0[v->h15C]) < 0.100000001f || D_L01_001E2230 <= 0) {
                func_L01_004450F0((u8 *)m, 7, -1);
            }
            break;
        }
        case 7: {
            f32 d;
            f32 ang;
            f32 *yp;
            m->w98 = 0;
            if (func_L01_003BEAA0_003BEAE0() || func_L01_003BEA60((Moby_003BD218 *)m)) {
                m->flags |= 0x100;
                m->qC0 = D_001A4BE0_003BEAE0.moby->qC0;
                m->qD0 = D_001A4BE0_003BEAE0.moby->qD0;
                m->qE0 = D_001A4BE0_003BEAE0.moby->qE0;
            }
            d = func_L01_0040E548(&m->pos, &D_001A4BE0_003BEAE0.pos);
            if (100.0f < d) {
                func_L01_00448340(&m->pos, &D_L01_001E21C0[v->h15C], &v->f14C, 0.00160000008f, 0.00160000008f, 0.200000018f);
            } else if (40.0f < d && d < 100.0f) {
                f32 saved;
                pos0.q = m->pos.q;
                saved = v->f14C;
                func_L01_00448340(&pos0, &D_L01_001E21C0[v->h15C], &v->f14C, 0.00160000008f, 0.00160000008f, 0.200000018f);
                vec_sub_ba(&t, &pos0, &m->pos);
                func_0038CF68(&t, &t, 0.200000003f);
                vec_add_ab(&t2, &t, &m->pos);
                if (func_003D3CB0(&m->pos, &t2, 0, (M_3C1AB8 *)m, 0)) {
                    v->f14C = saved;
                } else {
                    m->pos.q = pos0.q;
                }
            } else {
                f32 saved;
                pos0.q = m->pos.q;
                saved = v->f14C;
                func_L01_00448340(&pos0, &D_L01_001E21C0[v->h15C], &v->f14C, func_003824E0(0.5f, 1.0f) * 0.000400000019f,
                                  func_003824E0(0.5f, 1.0f) * 0.000400000019f, func_003824E0(3.0f, 6.0f) * 0.0200000014f);
                vec_sub_ba(&t, &pos0, &m->pos);
                func_0038CF68(&t, &t, 0.200000003f);
                vec_add_ab(&t2, &t, &m->pos);
                if (func_003D3CB0(&m->pos, &t2, 0, (M_3C1AB8 *)m, 0)) {
                    v->f14C = saved;
                } else {
                    m->pos.q = pos0.q;
                }
            }
            if (!func_L01_003BEAA0_003BEAE0() && !func_L01_003BEA60((Moby_003BD218 *)m)) {
                if (v->f300 && v->f300->state != 0xFE && v->f300->state != 0xFD) {
                    yp = &m->rot.f[2];
                    ang = func_0038D160(v->f300->pos.f[0] - m->pos.f[0], v->f300->pos.f[1] - m->pos.f[1]);
                    func_L01_00448890(yp, ang, v->f304, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
                } else if (func_0038CF00(&m->pos, &D_L01_001E21C0[v->h15C]) < 0.100000001f) {
                    yp = &m->rot.f[2];
                    vec_add_ab(&pos0, &m->pos, &D_001A4BE0_003BEAE0.moby->qC0);
                    ang = func_0038D160(pos0.f[0] - m->pos.f[0], pos0.f[1] - m->pos.f[1]);
                    func_L01_00448890(yp, ang, v->f304, 0.00558505394f, 0.00558505394f, 0.279252708f, 0);
                } else {
                    yp = &m->rot.f[2];
                    ang = func_0038D160(((Q_3BEAE0 *)D_L01_001E21C0)[v->h15C].f[0] - m->pos.f[0],
                                        ((Q_3BEAE0 *)D_L01_001E21C0)[v->h15C].f[1] - m->pos.f[1]);
                    func_L01_00448890(yp, ang, v->f304, 0.0125663709f, 0.0125663709f, 0.628318548f, 0);
                }
            }
            if (D_L01_001E2230 > 0) break;
            func_L01_004C7D98((u8 *)&m->pos, (u8 *)&pos0);
            func_0038CF68(&pos0, &pos0, -10.0f);
            vec_add_ab(&t2, &m->pos, &D_001A4BE0_003BEAE0.moby->qC0);
            func_0038CF68(&t2, &t2, 5.0f);
            vec_add_ba(&t2, &m->pos, &t2);
            vec_add_ab(&t, &pos0, &t2);
            D_001A4BE0_003BEAE0.moby->w98 = 0;
            if (func_003D3CB0(&m->pos, &t, 0, (M_3C1AB8 *)m, 0)) {
                v->q120 = *(vu0_q *)&D_L01_001EAA20;
            } else {
                v->q120 = D_001A4BE0_003BEAE0.pos.q;
            }
            D_001A4BE0_003BEAE0.moby->w98 = D_001A4BE0_003BEAE0.moby->p24->w10;
            if (func_L01_003BEAA0_003BEAE0() || func_L01_003BEA60((Moby_003BD218 *)m)) {
                m->flags &= ~0x100;
            }
            func_L01_004450F0((u8 *)m, 8, -1);
            D_L01_001E2200[v->h15C] = 0;
            break;
        }
        case 8: {
            f32 a;
            f32 b;
            m->w98 = m->p24->w10;
            if (func_L01_004CB2D8()) func_L01_004CAB30(&v->q120, &v->q120);
            a = func_003824E0(1.0f, 2.0f) * 0.000400000019f;
            b = func_003824E0(1.0f, 2.0f) * 0.000400000019f;
            func_L01_00448340(&m->pos, &v->q120, &v->f14C, a, b, func_003824E0(3.0f, 4.0f) * 0.0200000014f);
            if (func_0038CF00(&m->pos, &v->q120) < 0.100000001f) {
                v->f13C = 0;
                v->f68 |= 1;
                if (D_001A4BE0_003BEAE0.h368) func_L01_004450F0((u8 *)m, 12, -1);
                else func_L01_004450F0((u8 *)m, 3, -1);
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 0);
            }
            break;
        }
        }
    }
    func_0038CAD0(&v->f144);
    if (v->f144 < 25) {
        u32 c;
        s32 r;
        s32 n;
        u8 *e;
        pos0.q = m->pos.q;
        t.q = 0;
        func_003C4C18(&pos0.q, 0.300000012f);
        c = func_0013D3E0() & 0x2F;
        c |= ((func_0013D3E0() + 0x10) & 0x3F) << 8;
        c |= 0x7F0000;
        c |= 0xFF000000;
        r = func_0013D3E0() % 2;
        n = func_00382498(20, 40);
        e = func_L01_0046B458(&pos0, n, func_003824E0(0.5f, 0.75f), 0.00100000005f, c, 2, r, &t, -0.00180000009f, 0);
        if (e) {
            e[3] = func_00382468(4) ? 0x48 : 0x44;
            e[2] = D_L01_002210B4[0x61][func_00382468(4)];
        }
        m->flags |= 0x200;
        m->b23 -= 4;
        m->rot.f[2] = func_0038DAB8(m->rot.f[2], func_003824E0(100.0f, 1440.0f) * 0.0174532924f * 0.0200000014f);
        if (v->f144 <= 0) func_L01_003C38D0((u8 *)m);
    }
    {
        f32 d = 0.0f;
        if (D_L01_001DFB40 % 60 == 0) {
            d = func_L01_0040E548(&m->pos, &D_001A4BE0_003BEAE0.pos);
            if (625.0f < d) {
                u8 x;
                if (v->h15C != -1) D_L01_001E2200[v->h15C] = 0;
                x = D_L01_002C5600[D_001425C0[87]].unk1;
                if (x != 0) if (x < 4) {
                    u8 *e = func_L01_003968F8(m, v->f308, &m->pos, (u8 *)D_001A4BE0_003BEAE0.moby + 0xC0, 1, 0);
                    if (e) *(s32 *)(e + 0xB8) = m->wB8;
                }
                func_L01_003C39A8((u8 *)m);
            }
            if (func_L01_003FB640(&m->pos, 0, (s32)m, 0.100000001f)) {
                if (func_L01_003BEAA8(func_003D5630())) {
                    u8 x;
                    if (v->h15C != -1) D_L01_001E2200[v->h15C] = 0;
                    x = D_L01_002C5600[D_001425C0[87]].unk1;
                    if (x != 0) if (x < 4) {
                        u8 *e = func_L01_003968F8(m, v->f308, &m->pos, (u8 *)D_001A4BE0_003BEAE0.moby + 0xC0, 1, 0);
                        if (e) *(s32 *)(e + 0xB8) = m->wB8;
                    }
                    func_L01_003C39A8((u8 *)m);
                }
            }
        }
        if (v->f13C) return;
        if (400.0f < d || 4.0f < fabs_asm(D_001A4BE0_003BEAE0.pos.f[2] - m->pos.f[2])) {
            if (func_L01_003BEA60((Moby_003BD218 *)m)) return;
            if (func_L01_003BEAA0_003BEAE0()) return;
            pos0.q = m->pos.q;
            pos0.f[3] = 0.25f;
            if (func_0038DC20(&pos0, 64.0f) > 0) return;
            func_L01_004C7D98((u8 *)D_L01_001E29C0, (u8 *)&t);
            func_0038CE20(&t, &t, -10.0f);
            vec_add_ba(&t2, D_L01_001E29C0, &t);
            if (func_003D3CB0(D_L01_001E29C0, &t2, 16, (M_3C1AB8 *)m, 0)) {
                if (func_L01_003BEAA8(func_003D5630())) {
                    func_L01_003C38D0((u8 *)m);
                } else {
                    Q_3BEAE0 t3;
                    Q_3BEAE0 t4;
                    t3.q = *(vu0_q *)&D_L01_001EAA20;
                    func_0038CE20(&t4, &D_L01_001E29C0[2], -1.0f);
                    vec_add_ab(&m->pos, &t3, &t4);
                }
            }
            if (!func_L01_003BEA60((Moby_003BD218 *)m) && !func_L01_003BEAA0_003BEAE0()) {
                if (m->b43 != 2) func_003C3A10(m, 2, 0, 14);
                func_L01_004450F0((u8 *)m, 1, -1);
            } else {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0((u8 *)m, 3, -1);
            }
        }
    }
}
/* localdecomp:end func_L01_003BEAE0 */

INCLUDE_ASM("asm/levels", func_L01_003C1978);

INCLUDE_ASM("asm/levels", func_L01_003C27E0);

/* localdecomp:start func_L01_003C2E10 */
/* The hero's four agent slots (the agent on each, 0 when free); declared small so the
   address is one la, as retail builds it. */
extern s32 D_L01_001E2200[2];

/* agent_slot_free: whether one of the hero's four agent slots has no agent hovering on it */
s32 func_L01_003C2E10(void) {
    s32 slot;

    for (slot = 0; slot < 4; slot++) {
        if (D_L01_001E2200[slot] == 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003C2E10 */

/* localdecomp:start func_L01_003C2E48 */
s32 func_L01_003C2E48(s32 a0) {
    s32 slot;

    for (slot = 0; slot < 4; slot++) {
        if (D_L01_001E2200[slot] == 0) {
            D_L01_001E2200[slot] = a0;
            return slot;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_003C2E48 */

/* localdecomp:start func_L01_003C2E88 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x38];
    f32 height;
    u8 pad3C[0x180 - 0x3C];
    vu0_q destination;
    vu0_q desired;
    u8 pad1A0[0x10];
    vu0_q best;
    u8 pad1C0[4];
    f32 best_distance;
    u8 pad1C8[8];
    void *target;
} Path_003C2E88;
typedef struct { u8 pad[0x18]; void *object; } Hit_003C2E88;
typedef struct { u8 pad[0xD0]; vu0_q position; u8 padE0[0x25C0 - 0xE0]; void *moby; } Hero_003C2E88;
extern u8 D_001A4BE0[];
extern Hit_003C2E88 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
void func_L01_003C2E88(M_3C1AB8 *m, f32 minimum) {
    extern u8 *func_00382348(void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    vu0_v4 start;
    vu0_v4 end;
    vu0_v4 candidate;
    vu0_v4 direction;
    vu0_v4 displacement;
    Path_003C2E88 *p = (Path_003C2E88 *)m->p68;
    u8 *target;
    f32 angle;
    f32 distance;
    f32 degrees;
    f32 step;
    f32 collision_distance;
    f32 score;
    p->destination = p->desired;
    *(vu0_q *)&start = m->pos;
    *(vu0_q *)&end = p->desired;
    start.z += p->height;
    end.z += p->height;
    target = func_00382348(p->target);
    if (p->target == ((Hero_003C2E88 *)D_001A4BE0)->moby) {
        *(vu0_q *)&end = ((Hero_003C2E88 *)D_001A4BE0)->position;
    } else if (target != 0) {
        end.z += *(f32 *)(target + 0x10);
    }
    if (func_L01_0040E548(&start, &end) >= 3600.0f) return;
    if (!func_003D3CB0(&start, &end, 16, m, 0)) return;
    if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.object == p->target) return;
    for (degrees = 10.0f; degrees <= 160.0f; degrees += 10.0f) {
        vec_sub_ab(&direction, &end, &start);
        angle = func_0038D160(direction.x, direction.y);
        distance = func_0038CED8(&direction);
        if (distance < minimum) distance = minimum;
        step = degrees * 0.01745329238474369f;
        candidate.x = func_0038D098(func_0038DAB8(step, angle)) * distance;
        candidate.y = func_0038D0B0(func_0038DAB8(step, angle)) * distance;
        candidate.z = 0.0f;
        vec_add_ab(&candidate, &start, &candidate);
        if (candidate.x < 0.0f) candidate.x = 0.5f;
        if (candidate.y < 0.0f) candidate.y = 0.5f;
        if (candidate.z < 0.0f) candidate.z = 0.5f;
        if (!func_003D3CB0(&start, &candidate, 16, m, 0)) {
            p->destination = *(vu0_q *)&candidate;
            return;
        }
        if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.object == p->target) {
            p->destination = *(vu0_q *)&candidate;
        }
        vec_sub_ab(&displacement, &m->pos, &D_L01_001EAA20);
        collision_distance = func_0038CED8(&displacement);
        if (p->best_distance < collision_distance && degrees < 60.0f) {
            score = func_0038CF38(&D_L01_001EAA20, &p->desired);
            if (score < func_0038CF38(&p->best, &p->desired)) {
                p->best_distance = collision_distance;
                p->best = *(vu0_q *)&D_L01_001EAA20;
            }
        }
        step = -(degrees * 0.01745329238474369f);
        candidate.x = func_0038D098(func_0038DAB8(step, angle)) * distance;
        candidate.y = func_0038D0B0(func_0038DAB8(step, angle)) * distance;
        candidate.z = 0.0f;
        vec_add_ab(&candidate, &start, &candidate);
        if (candidate.x < 0.0f) candidate.x = 0.5f;
        if (candidate.y < 0.0f) candidate.y = 0.5f;
        if (candidate.z < 0.0f) candidate.z = 0.5f;
        if (!func_003D3CB0(&start, &candidate, 16, m, 0)) {
            p->destination = *(vu0_q *)&candidate;
            return;
        }
        if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.object == p->target) {
            p->destination = *(vu0_q *)&candidate;
        }
        vec_sub_ab(&displacement, &m->pos, &D_L01_001EAA20);
        collision_distance = func_0038CED8(&displacement);
        if (p->best_distance < collision_distance && degrees < 60.0f) {
            p->best_distance = collision_distance;
            p->best = *(vu0_q *)&D_L01_001EAA20;
        }
    }
    p->destination = p->best;
}
/* localdecomp:end func_L01_003C2E88 */

/* localdecomp:start func_L01_003C3320 */
extern s32 D_L01_001EAA18[];
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
void func_L01_003C3320(M_3C1AB8 *m) {
    V_3C1AB8 a;
    V_3C1AB8 b;
    P_3C1AB8 *p;
    a.q = m->pos;
    p = m->p68;
    a.f[2] += 0.1f;
    b.q = p->v190;
    a.f[2] += p->f38;
    b.f[2] += p->f38;
    if (3600.0f <= func_L01_0040E548(&a, &b)) {
        return;
    }
    if (func_003D3CB0(&a, &b, 16, m, 0) != 0) {
        if (D_L01_001EAA18[0] == 0) {
            return;
        }
        if (D_L01_001EAA18[0] != p->w1D0) {
            return;
        }
    }
    p->v180 = p->v190;
    p->v1A0 = p->v190;
}
/* localdecomp:end func_L01_003C3320 */

LINKER_REMNANT("asm/levels", func_L01_003C3408);

/* localdecomp:start func_L01_003C3410 */
#include "vu0.h"
extern u128_t D_L01_001EAA40;
s32 func_L01_003C3410(u8 *o) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003C3D30(void *,s32,s32,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    V_3C1AB8 a,b,c;
    u8 *d;
    f32 height, z, angle;
    a.q=*(u128_t *)(o+0x10);
    d=*(u8 **)(o+0x68);
    b.f[0]=func_0038D098(*(f32 *)(o+0xF8));
    b.f[1]=func_0038D0B0(*(f32 *)(o+0xF8));
    b.f[2]=0;
    vec_add_ab(&a,&a,&b);
    height=func_003C3D30(&a,34,0,0.5f);
    if(height<*(f32 *)(o+0x18) && *(f32 *)(d+0x3C)<fabs_asm(height-*(f32 *)(o+0x18))) {
        b.f[0]=func_0038D098(*(f32 *)(o+0xF8))*9.0f;
        b.f[1]=func_0038D0B0(*(f32 *)(o+0xF8))*9.0f;
        b.f[2]=0;
        vec_add_ab(&a,o+0x10,&b);
        *(u128_t *)(d+0x160)=a.q;
        height=func_003C3D30(&a,34,0,6.0f);
        z=*(f32 *)(o+0x18)-2.0f;
        c.q=D_L01_001EAA40;
        angle=func_0038CED8(&c);
        angle=func_0038D160(c.f[2],angle);
        if(z<height && angle<0.1745329201221466f) {
            *(f32 *)(d+0x1CC)=height;
            return 1;
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L01_003C3410 */

/* localdecomp:start func_L01_003C35A0 */
extern s32 D_L01_001D6694;
extern s32 D_L01_001DEBC8;
__asm__(".extern D_L01_001DEBC8, 8");
extern s32 D_L01_001DEBD8;
__asm__(".extern D_L01_001DEBD8, 8");
extern s32 D_L01_001DEBE8;
__asm__(".extern D_L01_001DEBE8, 8");
extern void func_003C2F58(M_3C1EE0 *, s32, s128_3C1EE0 *);
extern void func_003C4C18(s128_3C1EE0 *, f32);
extern f32 func_003824E0(f32 a, f32 b);
extern void func_L01_0046E078(M_3C1EE0 *, s128_3C1EE0 *, s128_3C1EE0 *, s32 *, s32);

/* agent_jets_emit: an agent's jets (V4 and up) while it hovers and lands: three type 0x4A
   particles a frame at its point 0 */
void func_L01_003C35A0(M_3C1EE0 *agent)
{
    s128_3C1EE0 q[5];

    if (D_L01_001D6694 == 2)
        return;
    q[0] = 0;
    func_003C2F58(agent, 0, &q[1]);
    ((f32 *)&q[1])[3] = 0.0f;
    q[2] = q[1];
    q[3] = q[1];
    q[4] = q[1];
    func_003C4C18(&q[1], 0.025f);
    func_003C4C18(&q[2], 0.025f);
    func_003C4C18(&q[3], 0.025f);
    func_003C4C18(&q[4], 0.025f);
    ((f32 *)&q[0])[2] = -(func_003824E0(30.0f, 40.0f) * 0.02000000141561031f) * 0.1f;
    func_L01_0046E078(agent, &q[2], &q[0], &D_L01_001DEBC8, 1);
    ((f32 *)&q[0])[2] = -(func_003824E0(30.0f, 40.0f) * 0.02000000141561031f) * 0.1f;
    func_L01_0046E078(agent, &q[3], &q[0], &D_L01_001DEBD8, 1);
    ((f32 *)&q[0])[2] = -(func_003824E0(30.0f, 40.0f) * 0.02000000141561031f) * 0.1f;
    func_L01_0046E078(agent, &q[4], &q[0], &D_L01_001DEBE8, 1);
}
/* localdecomp:end func_L01_003C35A0 */

/* localdecomp:start func_L01_003C3748 */
extern void func_003C2F58(M_3C1EE0 *, s32, s128_3C1EE0 *);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003C3748(M_3C1EE0 *m) {
    s128_3C1EE0 v;
    u32 col;
    if (m == 0) {
        return;
    }
    if (m->b20 == 254) {
        return;
    }
    if (m->b20 == 253) {
        return;
    }
    col = (m->b20 == 5) ? 0x40202080 : 0x40802020;
    func_003C2F58(m, 2, &v);
    func_003D9508(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
    func_003C2F58(m, 3, &v);
    func_003D9508(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003C3748 */

/* localdecomp:start func_L01_003C3830 */
#include "vu0.h"
extern s32 D_L01_001E2210[1];
extern s32 D_L01_001DD6E8;
extern vu0_q D_L01_001E21C0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E2200[2];
void func_L01_003C3830(void) {
    s32 i, j;
    s32 *slot;
    vu0_q *p;
    for (i = 7; i >= 0; i--) {
        D_L01_001E2210[i] = 0;
    }
    D_L01_001DD6E8 = 0;
    slot = D_L01_001E2200;
    p = D_L01_001E21C0;
    for (j = 3; j >= 0; j--) {
        qzero(p);
        *slot = 0;
        p++;
        slot++;
    }
}
/* localdecomp:end func_L01_003C3830 */

/* localdecomp:start func_L01_003C3898 */
extern s32 D_L01_001E2210[1];

s32 func_L01_003C3898(void)
{
    s32 i;
    s32 *p;

    i = 0;
    p = D_L01_001E2210;
    for (; i < 8; i++) {
        if (*p == 0)
            return 0;
        p++;
    }
    return 1;
}
/* localdecomp:end func_L01_003C3898 */

/* localdecomp:start func_L01_003C38D0 */
extern s32 D_001A71A0[];
extern s32 D_L01_001E2200[2];
extern s32 D_L01_001E2210[1];
extern s32 D_L01_001DD6E8;
void func_L01_003C38D0(u8 *obj) {
    extern void func_L01_004C8598(s32);
    extern void func_L01_003F5EE0(u8 *);
    extern void func_003C2880(u8 *);
    u8 *p;
    s32 i;
    func_L01_004C8598(D_001A71A0[0]);
    p = *(u8 **)(obj + 0x68);
    func_L01_003F5EE0(obj);
    if (p != 0 && *(s16 *)(p + 0x15C) != -1) {
        D_L01_001E2200[*(s16 *)(p + 0x15C)] = 0;
    }
    for (i = 0; i < 8; i++) {
        if (D_L01_001E2210[i] == (s32)obj) {
            D_L01_001E2210[i] = 0;
            break;
        }
    }
    D_L01_001DD6E8--;
    if (D_L01_001DD6E8 < 0) D_L01_001DD6E8 = 0;
    func_003C2880(obj);
}
/* localdecomp:end func_L01_003C38D0 */

/* localdecomp:start func_L01_003C39A8 */

extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];

extern void func_L01_004C7D98(u8 *, u8 *);
extern u8 *func_L01_00392908(u8 *, u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_L01_003BEAA0_003C39A8(void);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_003C38D0(u8 *);

void func_L01_003C39A8(u8 *arg0) {
    u8 buf[16];
    u8 *v;
    u8 x;
    s32 t;

    x = D_L01_002C5600[D_001425C0[87]].unk1;
    t = x < 4;
    if (!t) {
        func_L01_004C7D98(arg0 + 16, buf);
        v = func_L01_00392908(arg0 + 16, buf);
        if (v != 0) {
            *(s32 *)(v + 184) = *(s32 *)(arg0 + 184);
        }
    } else if (x == 0 || !t) {
        func_003A52A0(0, 0, arg0);
        func_L01_003303B8(arg0 + 16, 0, 20, 20, 20, 20, 0, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                      func_L01_003BEAA0_003C39A8() == 0, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00446780(arg0, arg0 + 16, 0x1010000, 0, 1, 0, 2.0f, D_L01_002C5600[D_001425C0[87]].unk6C, 0.0f);
    }
    if (func_L01_004CB2D8() != 0) {
        func_L01_003303B8(arg0 + 16, 0, 3, 3, 3, 6, 3, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                      0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    func_L01_003C38D0(arg0);
}
/* localdecomp:end func_L01_003C39A8 */

/* localdecomp:start func_L01_003C3C50 */
extern s32 func_L01_003C3898(void);
extern s32 func_00382468(s32);
extern void func_L01_003C39A8(u8 *);

void func_L01_003C3C50(u8 *arg) {
    s32 i;
    if (((s32 (*)(u8 *))func_L01_003C3898)(arg) == 0) {
        for (i = 0; i < 8; i++) {
            if (((u8 **)D_L01_001E2210)[i] == 0) {
                ((u8 **)D_L01_001E2210)[i] = arg;
                return;
            }
        }
    } else {
        s32 idx = func_00382468(8);
        func_L01_003C39A8(((u8 **)D_L01_001E2210)[idx]);
        ((u8 **)D_L01_001E2210)[idx] = arg;
    }
}
/* localdecomp:end func_L01_003C3C50 */

/* localdecomp:start func_L01_003C3CE8 */
extern s32 D_L01_002BB3E0[];
s32 *func_L01_003C3CE8(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 104;
        return D_L01_002BB3E0;
    }
    return 0;
}
/* localdecomp:end func_L01_003C3CE8 */

/* localdecomp:start func_L01_003C3D08 */
extern void func_L01_003C4C40();
extern void func_L01_003C57E0(u8 *, u8 *);
extern void func_L01_003C5888(M_3C4008 *, B_3C4008 *);
extern s32 func_L01_003C5BA8(s32, u8 *);
extern void func_L01_003C66F8(u8 *, s32, s32);
extern void func_L01_003C57B0(void *, void *, int);
extern void func_L01_003C5290(u8 *, u8 *);
extern void func_L01_003C6F68(void *, s32);
extern s32 func_00382380(u8 *, s32, s32);
extern s32 func_L01_003C7D38(u8 *, u8 *);
extern void func_0038D308(u8 *, u8 *);
extern void func_L01_003C6E78(u8 *, u8 *);
extern s32 func_L01_003C6860(M_3C4008 *);
extern void func_L01_003C5CA8(void *, u8 *);
extern void func_L01_003C5C60(s32, u8 *);
extern void func_L01_003C6EC0(u8 *, u8 *);
extern void func_L01_003C7810(u8 *, u8 *, s32, s32, s32);
extern void func_L01_003C54E8(void *, Obj_003C3C68 *);
extern void func_L01_003C5CE8(u8 *, u8 *);
extern void func_L01_003C5EC0(s32, s32);
extern f32 func_L01_003C7A68(u8 *, u8 *, f32);
void func_L01_003C5DF0(s32, s32, s32);
extern void func_L01_004AA760(s32, s32);
extern s32 func_L01_003C55B8(void *, u8 *);
extern s32 func_L01_004AA710(s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_003A4F28(s32);
extern void func_L01_003C5710(u8 *, u128_t *, u128_t *);
extern s32 func_L01_004BA800(void);
extern void func_L01_003C6D30(u8 *, u8 *, f32 *, f32 *, f32 *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_003C5220(u8 *, u8 *);
extern s32 func_L01_003C7000(u8 *, u8 *);
extern s32 func_L01_003C7560(u8 *, u8 *);
extern void func_L01_003C5F10(void *, O3C48A8 *);
extern void func_L01_003C6128(void *, O3C48A8 *);
extern s32 func_L01_003C6668(u8 *);
extern void func_L01_00404A10_003C3D08(void *, void *);
extern void func_L01_003C8D60(u8 *);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_001BBC40[][16];
extern s16 D_001A4DC0[];
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern s32 D_L01_001F3F40[];
extern f32 D_L01_001DF950;
extern s32 D_L01_001DECD8;
extern f32 D_L01_001DECDC;
extern f32 D_L01_001DECE0;
extern f32 D_L01_001DECE4;
extern f32 D_L01_001DECE8;
extern s32 D_L01_001DECF8;
__asm__(".extern D_L01_001DECD8, 4");
__asm__(".extern D_L01_001DECDC, 4");
__asm__(".extern D_L01_001DECE0, 4");
__asm__(".extern D_L01_001DECE4, 4");
__asm__(".extern D_L01_001DECE8, 4");
__asm__(".extern D_L01_001DECF8, 4");

typedef struct {
    u128_t q0;
    u128_t q10;
    u8 pad20[0x4C - 0x20];
    s32 w4C;
    u8 pad50[0xA0 - 0x50];
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s32 wAC;
    s32 wB0;
    u8 padB4[0xC8 - 0xB4];
    s32 wC8;
    u8 padCC[0xD8 - 0xCC];
    s32 wD8;
    u8 padDC[4];
    s32 wE0;
    u8 padE4[0xF0 - 0xE4];
    s32 wF0;
    f32 fF4;
    f32 fF8;
    f32 fFC;
    u8 b100;
    u8 b101;
    u8 pad102[2];
    s32 w104;
    s32 w108;
    s32 w10C;
    u128_t q110;
    f32 f120;
    f32 f124;
    f32 f128;
    u8 pad12C[0x674 - 0x12C];
    f32 f674;
    u8 pad678[0x6A8 - 0x678];
    f32 f6A8;
    u8 pad6AC[0x6BC - 0x6AC];
    s32 w6BC;
    s32 a6C0[4];
    s32 a6D0[4];
    s32 a6E0[4];
    u8 pad6F0[0x10];
    s32 a700[4];
    s32 a710[4];
    u8 pad720[0x750 - 0x720];
    s32 a750[4];
} V_003C3D08;

typedef struct { u8 pad[0x96]; u16 h96; } Mob_003C3D08;

static __inline__ s32 stop_003C3D08(s32 id, s32 owner)
{
    if (id != -1) {
        u8 *e = D_001A30B0 + id * 128;
        if (*(s32 *)(e + 0xDC) == owner && e[0xD0] != 0) {
            func_003A4F28(id);
        }
    }
    return -1;
}

void func_L01_003C3D08(u8 *m)
{
    u8 *obj = *(u8 **)(m + 0x68);
    V_003C3D08 *v = (V_003C3D08 *)obj;
    vu0_v4 oldpos;
    vu0_v4 oldvel;
    s32 i;
    s32 r;
    s32 owner;
    s32 cur;
    s32 t;
    s32 moved;
    f32 f;
    f32 a, b, c;

    if (m[0x20] == 0) {
        func_L01_003C4C40(m, obj);
    }
    oldpos = *(vu0_v4 *)(m + 0x10);
    oldvel = *(vu0_v4 *)(m + 0xF0);
    *(u128_t *)(m + 0x10) = v->q0;
    *(u128_t *)(m + 0xF0) = v->q10;
    func_L01_003C57E0(m, obj);
    func_L01_003C5888((M_3C4008 *)m, (B_3C4008 *)obj);
    switch (m[0x20]) {
    case 1:
        i = func_L01_003C5BA8((s32)m, obj);
        if (i >= 0) {
            if (i != v->w6BC) {
                func_L01_003C66F8(m, i, 0);
            }
            func_L01_003C57B0(m, obj, v->a6D0[i]);
            func_L01_003C5290(m, obj);
            func_L01_003C6F68(m, (s32)obj);
            func_L01_004450F0(m, 4, -1);
        } else {
            s32 t = v->a710[v->w6BC];
            if (t != -1 && func_00382380(D_001A4C60, t, 0)) {
                func_L01_004450F0(m, 3, -1);
            }
        }
        break;
    case 2:
        i = func_L01_003C5BA8((s32)m, obj);
        if (i >= 0) {
            if (i != v->w6BC) {
                func_L01_003C66F8(m, i, 0);
            }
            func_L01_003C57B0(m, obj, v->a6D0[i]);
            func_L01_003C5290(m, obj);
            func_L01_003C6F68(m, (s32)obj);
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(m)) {
            func_L01_003C5290(m, obj);
        }
        r = func_L01_003C7D38(m, obj);
        func_0038D308(m + 0xC0, m + 0xF0);
        if (r == 2) {
            v->wC8 = 0;
            func_L01_003C6E78(m, obj);
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 4:
        i = func_L01_003C5BA8((s32)m, obj);
        if (i >= 0 && i != v->w6BC) {
            func_L01_003C66F8(m, i, 0);
            func_L01_003C57B0(m, obj, v->a6D0[i]);
            func_L01_003C5290(m, obj);
            func_L01_003C6F68(m, (s32)obj);
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 5:
        if (func_L01_003C6860((M_3C4008 *)m)) {
            func_L01_003C5CA8(m, obj);
            func_L01_003C6E78(m, obj);
        } else {
            func_L01_003C5C60((s32)m, obj);
            func_L01_003C6EC0(m, obj);
        }
        if (v->wB0 == 0) {
            func_L01_004450F0(m, 6, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(m)) {
            func_L01_003C6EC0(m, obj);
            func_L01_003C7810(m, obj, v->a700[v->w6BC], -1, 0);
        }
        r = func_L01_003C7D38(m, obj);
        func_0038D308(m + 0xC0, m + 0xF0);
        if (r != 0) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(m)) {
            func_L01_003C54E8(m, (Obj_003C3C68 *)obj);
        }
        break;
    case 8:
        if (func_L01_004561B8(m)) {
            v->wF0 = 0;
        }
        D_001A4DC0[0] = 2;
        func_L01_003C5CE8(m, obj);
        if (v->wF0 != 0) {
            if (func_0038CAD0(&v->wF0)) {
                D_L01_001DF950 = 2.0f;
                func_L01_003C5EC0((s32)m, (s32)obj);
                func_L01_004450F0(m, 10, -1);
            } else {
                D_L01_001DF950 = (1.0f - (f32)v->wF0 / (f32)D_L01_001DECF8) * 1.1f;
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            v->wF0 = D_L01_001DECF8;
        }
        ((Mob_003C3D08 *)m)->h96++;
        if (((Mob_003C3D08 *)m)->h96 > (D_L01_001DECD8 * 5 + 2) / 6) {
            func_L01_003C6EC0(m, obj);
            func_L01_004450F0(m, 9, -1);
        } else {
            func_L01_003C5DF0((s32)m, (s32)obj, 1);
        }
        break;
    case 9:
        D_001A4DC0[0] = 2;
        if (v->wF0 != 0) {
            if (func_0038CAD0(&v->wF0)) {
                D_L01_001DF950 = 2.0f;
                func_L01_003C5EC0((s32)m, (s32)obj);
                func_L01_004450F0(m, 10, -1);
            } else {
                D_L01_001DF950 = (1.0f - (f32)v->wF0 / (f32)D_L01_001DECF8) * 1.1f;
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            v->wF0 = D_L01_001DECF8;
        }
        r = func_L01_003C7D38(m, obj);
        func_0038D308(m + 0xC0, m + 0xF0);
        func_L01_003C5CE8(m, obj);
        f = func_L01_003C7A68(m, obj, D_L01_001DECDC + D_L01_001DECE0 + 1.0f);
        if (f < D_L01_001DECDC + D_L01_001DECE0) {
            if (f < D_L01_001DECE0) {
                D_L01_001DF950 = 2.0f;
                f = 0.0f;
            } else {
                D_L01_001DF950 = 1.0f - (f - D_L01_001DECE0) / D_L01_001DECDC;
            }
        }
        if (f == 0.0f || r != 0) {
            D_L01_001DF950 = 2.0f;
            func_L01_003C5EC0((s32)m, (s32)obj);
            func_L01_004450F0(m, 10, -1);
        } else {
            func_L01_003C5DF0((s32)m, (s32)obj, 1);
        }
        break;
    case 11:
        if (func_L01_004561B8(m)) {
            v->wF0 = 0;
        }
        D_001A4DC0[0] = 2;
        if (v->wF0 != 0) {
            if (func_0038CAD0(&v->wF0)) {
                D_L01_001DF950 = 2.0f;
                func_L01_003C5EC0((s32)m, (s32)obj);
                func_L01_004450F0(m, 12, -1);
            } else {
                D_L01_001DF950 = (1.0f - (f32)v->wF0 / (f32)D_L01_001DECF8) * 1.1f;
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            v->wF0 = D_L01_001DECF8;
        }
        r = func_L01_003C7D38(m, obj);
        func_0038D308(m + 0xC0, m + 0xF0);
        func_L01_003C5CE8(m, obj);
        f = func_L01_003C7A68(m, obj, D_L01_001DECE4 + D_L01_001DECE8 + 1.0f);
        if (f < D_L01_001DECE4 + D_L01_001DECE8) {
            if (f < D_L01_001DECE8) {
                D_L01_001DF950 = 2.0f;
                f = 0.0f;
            } else {
                D_L01_001DF950 = 1.0f - (f - D_L01_001DECE8) / D_L01_001DECE4;
            }
        }
        if (f == 0.0f || r != 0) {
            D_L01_001DF950 = 2.0f;
            func_L01_003C5EC0((s32)m, (s32)obj);
            func_L01_004450F0(m, 12, -1);
        } else {
            func_L01_003C5DF0((s32)m, (s32)obj, 1);
        }
        break;
    case 12:
        if (func_L01_004561B8(m)) {
            v->wC8 = 0;
        }
    case 10:
        D_L01_001DF950 = 2.0f;
        D_001A4DC0[0] = 2;
        break;
    }

    if (v->wAC != D_L01_001F3F40[0]) {
        func_L01_004AA760(0, v->w4C);
        if (v->wD8 != 0) {
            func_L01_004AA760(0, v->wD8);
        }
        v->wA0 = -1;
        func_L01_004AA760(1, v->w4C);
        if (v->wD8 != 0) {
            func_L01_004AA760(1, v->wD8);
        }
        v->wA8 = -1;
        v->wAC = D_L01_001F3F40[0];
    }
    if (D_L01_001F3F40[0] == v->wE0) {
        owner = v->wD8;
    } else {
        owner = v->w4C;
    }
    if (func_L01_003C55B8(m, obj)) {
        moved = 0;
        if (!func_L01_004AA710(owner, v->wA8)) {
            if ((*(G_3C4008 *)&D_001A4BE0).w25C4 != 0x74) {
                if (v->a6E0[v->w6BC] != 0 ||
                    m[0x20] == 8 || m[0x20] == 9 || m[0x20] == 10 || m[0x20] == 11 || m[0x20] == 12) {
                    v->wA8 = ((s32 (*)(s32, s32, s32))func_003A52A0)(1, 4, owner);
                } else {
                    v->wA8 = stop_003C3D08(v->wA8, owner);
                }
            } else {
                v->wA8 = stop_003C3D08(v->wA8, owner);
            }
        } else if ((*(G_3C4008 *)&D_001A4BE0).w25C4 == 0x74) {
            v->wA8 = stop_003C3D08(v->wA8, owner);
        }
        func_L01_003C5710(obj, (u128_t *)(m + 0x10), (u128_t *)(m + 0xF0));
        if (func_L01_004BA800() && v->fF4 > 0.0f) {
            v->fF4 = v->fF4 - 0.020000001f;
            if (v->fF4 < 0.0f) {
                v->fF4 = 0.0f;
            }
        } else if (v->fF4 < 1.0f) {
            v->fF4 = v->fF4 + 0.020000001f;
            if (1.0f < v->fF4) {
                v->fF4 = 1.0f;
            }
        }
        if (0.0f < v->fF4) {
            func_L01_003C6D30(m, obj, &a, &b, &c);
            *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + a * v->fF4;
            *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), b * v->fF4);
            *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), c * v->fF4);
        }
        if (func_L01_0040E548(m + 0x10, &v->q110) > 9.9999994e-11f ||
            func_0038DBA0(*(f32 *)(m + 0xF0), v->f120) > 1.7453292e-06f ||
            func_0038DBA0(*(f32 *)(m + 0xF4), v->f124) > 1.7453292e-06f ||
            func_0038DBA0(*(f32 *)(m + 0xF8), v->f128) > 1.7453292e-06f) {
            func_L01_003C5220(m, obj);
            moved = 1;
        }
        switch (v->wB0) {
        case 0:
            v->wA0 = stop_003C3D08(v->wA0, owner);
            break;
        case 1:
            if (func_L01_003C7000(m, obj)) {
                v->wA0 = stop_003C3D08(v->wA0, owner);
                v->wB0 = 2;
            } else if (!func_L01_004AA710(owner, v->wA0) &&
                       (*(G_3C4008 *)&D_001A4BE0).w25C4 != 0x74) {
                v->wA0 = ((s32 (*)(s32, s32, s32))func_003A52A0)(0, 4, owner);
            }
            break;
        case 2:
            v->wA0 = stop_003C3D08(v->wA0, owner);
            func_L01_003C7000(m, obj);
            break;
        case 3:
            if (func_L01_003C7560(m, obj)) {
                v->wA0 = stop_003C3D08(v->wA0, owner);
                v->wB0 = 0;
            } else if (!func_L01_004AA710(owner, v->wA0) &&
                       (*(G_3C4008 *)&D_001A4BE0).w25C4 != 0x74) {
                v->wA0 = ((s32 (*)(s32, s32, s32))func_003A52A0)(0, 4, owner);
            }
            break;
        }
        if (!moved) {
            if (fabs_asm(v->f674 - v->fF8) > 1.7453292e-06f ||
                fabs_asm(v->f6A8 - v->fFC) > 9.9999997e-06f) {
                func_L01_003C5220(m, obj);
            }
        }
    } else {
        v->wA0 = stop_003C3D08(v->wA0, owner);
        v->wA8 = stop_003C3D08(v->wA8, owner);
    }
    if (func_L01_003C55B8(m, obj)) {
        switch (m[0x20]) {
        case 8:
        case 9:
        case 10:
            t = v->a750[v->w6BC];
            if (t < 0) {
                cur = v->a6C0[v->w6BC];
            } else {
                cur = t;
            }
            break;
        case 11:
        case 12:
            t = v->a750[v->w104];
            if (t < 0) {
                cur = v->a6C0[v->w104];
            } else {
                cur = t;
            }
            break;
        default:
            cur = v->a6C0[v->w6BC];
            break;
        }
    } else {
        cur = -1;
    }
    if (v->w108 != -1) {
        if (D_001D545C == 9 && D_L01_001F3F40[0] == v->wE0) {
            func_L01_003C5F10(m, (O3C48A8 *)obj);
        } else if (v->b101 != 0 || cur != D_L01_001F3F40[0] ||
                   (v->w10C != -1 && !(D_001BBC40[D_001D545C][v->w10C] & 0x80))) {
            func_L01_003C6128(m, (O3C48A8 *)obj);
        } else {
            func_L01_003C5F10(m, (O3C48A8 *)obj);
        }
    }
    if (func_L01_003C55B8(m, obj) && cur == D_L01_001F3F40[0] && !func_L01_003C6668(m)) {
        func_L01_00404A10_003C3D08(func_L01_003C8D60, m);
    }
}
/* localdecomp:end func_L01_003C3D08 */

/* localdecomp:start func_L01_003C4C40 */
typedef struct {
    u8 pad0[0x32];
    s16 h32;
    u16 h34;
    u8 pad36[0x98 - 0x36];
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
    u8 padAC[0x100 - 0xAC];
} Moby_003C4C40;
typedef struct {
    u8 pad0[0x10];
    s16 h10;
    u8 pad12[0x1C - 0x12];
    u8 b1C;
    u8 pad1D[0x20 - 0x1D];
} Shrub_003C4C40;
typedef struct {
    u8 pad0[0x20];
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 pad3C[4];
    Moby_003C4C40 *m40;
    Moby_003C4C40 *m44;
    Moby_003C4C40 *m48;
    Moby_003C4C40 *m4C;
    Moby_003C4C40 *m50;
    Moby_003C4C40 *m54;
    s32 a[6];
    s32 b[4];
    s32 c[4];
    s32 w90;
    s32 w94;
    f32 f98;
    f32 f9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s32 wAC;
    s32 wB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    u8 padC0[0x10];
    s32 wD0;
    s32 wD4;
    Moby_003C4C40 *mD8;
    Moby_003C4C40 *mDC;
    u8 padE0[0x14];
    f32 fF4;
    f32 fF8;
    f32 fFC;
    u8 b100;
    u8 b101;
    u8 b102;
    u8 b103;
    u8 pad104[4];
    s32 w108;
    u8 pad10C[4];
    u128_t q110;
    u128_t q120;
    u8 pad130[0x40];
    u8 s170[0x4D];
    u8 b1BD;
    u8 pad1BE[0x670 - 0x1BE];
    u8 s670[0x20];
    u8 s690[0x2C];
    s32 w6BC;
    u8 pad6C0[0x40];
    s32 x700[4];
    u8 pad710[0x10];
    s32 x720[4];
    u8 pad730[0x50];
    s32 x780[4];
    s32 x790[4];
} Vars_003C4C40;
extern u16 *D_L01_0021DE20[];
extern Moby_003C4C40 *D_L01_001E001C_003C4C40;
extern s32 D_L01_001E0058;
extern u16 **D_L01_001D6764;
extern u8 *D_L01_001E0ED4;
extern f32 D_L01_001DEC54;
__asm__(".extern D_L01_001DEC54, 4");
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0044F888(void *, s32, s32, void *, s32);
extern void func_L01_003C76A0(void *, void *, s32);
extern void func_L01_003C5710(u8 *, u128_t *, u128_t *);
extern void func_L01_003C6128(void *, O3C48A8 *);
extern void func_L01_00477BC0(s32, s32);

static __inline__ Moby_003C4C40 *moby_003C4C40(u16 id)
{
    return D_L01_001E001C_003C4C40 + (id & 0x7FFF);
}

static __inline__ s32 index_003C4C40(Moby_003C4C40 *e)
{
    return e - D_L01_001E001C_003C4C40;
}

void func_L01_003C4C40(u8 *m, Vars_003C4C40 *v)
{
    u16 *list;
    s32 i;
    s32 j;

    func_L01_0044ED88(m, v->s170, 16, v->w24, v->w20, -1, 7, 0);
    v->b1BD = 1;
    func_0038CB78(&v->m40, 0, 24);
    list = D_L01_0021DE20[v->w24];
    while ((v->w24 & 0xFF) != 0xFF && v->w24 <= D_L01_001E0058 && list != 0 &&
           ((s16)list[-1] >= 0 || list == D_L01_0021DE20[v->w24])) {
        Moby_003C4C40 *e = moby_003C4C40(*list);
        s16 uid;

        if (e == 0) {
            break;
        }
        e->h32 = 0x80;
        uid = e->hAA;
        if (uid == v->w34) {
            v->m48 = e;
        } else if (uid == v->w90) {
            v->m40 = e;
        } else if (uid == v->w94) {
            v->m44 = e;
        } else if (uid != v->w30) {
            if (uid == v->w28) {
                v->m4C = e;
                func_L01_0044F888(v->s170, 0, index_003C4C40(e), v->s670, 0x60);
            } else if (uid == v->w2C) {
                v->m50 = e;
                func_L01_0044F888(v->s170, 0, index_003C4C40(e), v->s690, 0x60);
            } else if (uid == v->w38) {
                v->m54 = e;
                func_L01_0044F888(v->s170, 0, index_003C4C40(e), v->s690, 0x60);
                e->w98 = 0;
            }
        }
        list++;
    }
    v->m40->h34 |= 0x41;
    v->m44->h34 |= 0x41;
    v->m48->h34 |= 0x41;
    {
        u16 *l;

        for (l = D_L01_001D6764[v->w20];
             l != 0 && ((s16)l[-1] >= 0 || l == D_L01_001D6764[v->w20]);
             l++) {
            Shrub_003C4C40 *s = (Shrub_003C4C40 *)D_L01_001E0ED4 + (*l & 0x7FFF);

            if (s == 0) {
                break;
            }
            s->b1C = 0x80;
            s->h10 = 0x7F80;
        }
    }
    if (v->wD0 != -1) {
        v->mD8 = D_L01_001E001C_003C4C40 + v->wD0;
    }
    if (v->wD4 != -1) {
        v->mDC = D_L01_001E001C_003C4C40 + v->wD4;
    }
    m[0x30] = 0xFF;
    v->b100 = 0;
    v->wB0 = 0;
    v->f98 = 0.0f;
    v->f9C = 0.0f;
    v->fF8 = 0.0f;
    v->fFC = 0.0f;
    v->wA4 = 0;
    v->wA0 = -1;
    v->wA8 = -1;
    v->wAC = -1;
    v->fB4 = func_003824E0(-D_L01_001DEC54, D_L01_001DEC54);
    v->fB8 = func_003824E0(0.0f, 3.1415927f);
    v->fBC = func_003824E0(0.0f, 3.1415927f);
    v->fF4 = 1.0f;
    for (j = 0; j < 6; j++) {
        v->a[j] = 0;
    }
    for (j = 0; j < 4; j++) {
        v->b[j] = 0;
        v->c[j] = 0;
    }
    qzero(&v->q110);
    qzero(&v->q120);
    v->w6BC = func_L01_003C5698(m, (u8 *)v);
    func_L01_003C76A0(m, v, 1);
    func_L01_003C5710((u8 *)v, (u128_t *)(m + 0x10), (u128_t *)(m + 0xF0));
    v->b102 = 1;
    if (v->w108 != -1) {
        func_L01_003C6128(m, (O3C48A8 *)v);
    }
    v->b103 = 0;
    for (i = 0; i < 4; i++) {
        if (v->x700[i] != -1) {
            func_L01_00477BC0(v->x700[i], 0);
        }
        if (v->x720[i] != -1) {
            func_L01_00477BC0(v->x720[i], 0);
        }
        if (v->x780[i] != -1) {
            func_L01_00477BC0(v->x780[i], 0);
        }
        if (v->x790[i] != -1) {
            func_L01_00477BC0(v->x790[i], 0);
        }
    }
}
/* localdecomp:end func_L01_003C4C40 */

/* localdecomp:start func_L01_003C5110 */

extern void func_003C7C38(u8 *a0);

void func_L01_003C5110(void *a0, u8 *a1) {
    s32 i;
    u8 **pp = (u8 **)(a1 + 64);
    for (i = 4; i >= 0; i--) {
        u8 *m = *pp++;
        if (m != 0) {
            u8 *v = *(u8 **)(m + 104);
            func_003C7C38(m);
            *(u128_t *)(v + 112) = *(u128_t *)(m + 16);
            *(u128_t *)(v + 128) = *(u128_t *)(m + 240);
        }
    }
}
/* localdecomp:end func_L01_003C5110 */

/* localdecomp:start func_L01_003C5188 */
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L01_003C5188(u8 *a0, u8 *a1) {
    u8 **pp = (u8 **)(a1 + 0x40);
    s32 i;

    for (i = 0; i < 5; i++) {
        u8 *p = pp[i];

        if (p != 0) {
            u8 *v = *(u8 **)(p + 0x68);
            u128_t tmp;

            func_003C7C38(p);
            vec_sub_ab(&tmp, p + 0x10, v + 0x70);
            func_003C4DA8(v + 0x30, &tmp, v + 0x80, p + 0xF0);
            *(u128_t *)(v + 0x70) = *(u128_t *)(p + 0x10);
            *(u128_t *)(v + 0x80) = *(u128_t *)(p + 0xF0);
        }
    }
}
/* localdecomp:end func_L01_003C5188 */

/* localdecomp:start func_L01_003C5220 */

extern void func_0038D308(u8 *, u8 *);
extern void func_L01_0044F450(u8 *, u8 *);
extern void func_L01_003C5188(u8 *, u8 *);

void func_L01_003C5220(u8 *a0, u8 *a1) {
    func_0038D308(a0 + 192, a0 + 240);
    func_L01_0044F450(a0, a1 + 368);
    *(u128_t *)(a1 + 272) = *(u128_t *)(a0 + 16);
    *(u128_t *)(a1 + 288) = *(u128_t *)(a0 + 240);
    *(f32 *)(a1 + 248) = *(f32 *)(a1 + 1652);
    *(f32 *)(a1 + 252) = *(f32 *)(a1 + 1704);
    func_L01_003C5188(a0, a1);
}
/* localdecomp:end func_L01_003C5220 */

/* localdecomp:start func_L01_003C5290 */
extern vu0_v4 D_L01_002BB2E0[];
extern s32 D_L01_001DECFC;
extern f32 D_L01_001DED00;
extern f32 D_L01_001DED04;
extern s32 D_L01_001DED10;
extern s32 D_L01_001DED14;
extern f32 D_L01_001DED18;
extern f32 D_L01_001DED1C;
extern vu0_v4 D_L01_001DED20[] __attribute__((section(".sdata")));
extern f32 D_L01_001DEDB8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DECFC, 4");
__asm__(".extern D_L01_001DED00, 4");
__asm__(".extern D_L01_001DED04, 4");
__asm__(".extern D_L01_001DED10, 4");
__asm__(".extern D_L01_001DED14, 4");
__asm__(".extern D_L01_001DED18, 4");
__asm__(".extern D_L01_001DED1C, 4");
__asm__(".extern D_L01_001DED20, 4");
__asm__(".extern D_L01_001DEDB8, 4");
extern void func_L01_0044F9F8(void *, s32, s32);
extern void func_L01_003C5CA8(void *, u8 *);
extern u8 *func_L01_00470150(void *, u8 *, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);

void func_L01_003C5290(u8 *moby, u8 *vars)
{
    Obj_003C3C68 *o = (Obj_003C3C68 *)vars;
    s32 i;
    u8 *p;

    func_L01_0044F9F8(vars + 0x170, 128, 1);
    *(u16 *)(*(u8 **)(vars + 0x40) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(vars + 0x44) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(vars + 0x48) + 0x34) |= 0x41;
    if (*(u8 **)(vars + 0x54)) {
        *(u16 *)(*(u8 **)(vars + 0x54) + 0x34) |= 0x41;
        func_L01_003C5CA8(moby, vars);
    }
    func_L01_003C5220(moby, vars);
    for (i = 0; i < 6; i++) {
        if (o->a[i] == 0) {
            p = func_L01_00470150(&D_L01_002BB2E0[i], moby, D_L01_001DECFC, -1, 1, -1, 0, -1,
                                  D_L01_001DED00 * 210000.0f, D_L01_001DED04, 1.0f, 0, 0);
            o->a[i] = (s32)p;
            if (p) p[3] = 0x44;
        }
    }
    for (i = 0; i < 4; i++) {
        if (o->b[i] == 0) {
            p = func_L01_00470150(&D_L01_001DED20[i], moby, D_L01_001DED10, -1, 1, -1, 3, -1,
                                  D_L01_001DEDB8[i] * 210000.0f, D_L01_001DED18, 1.0f, 0, 0);
            o->b[i] = (s32)p;
            if (p) p[3] = 0x44;
        }
        if (o->c[i] == 0) {
            p = func_L01_00470150(&D_L01_001DED20[i], moby, D_L01_001DED14, -1, 1, -1, 0, -1,
                                  D_L01_001DEDB8[i] * 210000.0f, D_L01_001DED1C, 1.0f, 0, 0);
            o->c[i] = (s32)p;
            if (p) p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L01_003C5290 */

/* localdecomp:start func_L01_003C54E8 */
extern void func_L01_003C5CA8(void *self, u8 *obj);

extern void func_L01_0044F8D8(void *, s32);
extern void func_003CD250(s32);

void func_L01_003C54E8(void *self, Obj_003C3C68 *o) {
    s32 i;

    func_L01_0044F8D8(o->d, 0);
    ((void (*)(void *, Obj_003C3C68 *))func_L01_003C5CA8)(self, o);
    for (i = 0; i < 6; i++) {
        if (o->a[i] != 0) {
            func_003CD250(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (o->b[i] != 0) {
            func_003CD250(o->b[i]);
            o->b[i] = 0;
        }
        if (o->c[i] != 0) {
            func_003CD250(o->c[i]);
            o->c[i] = 0;
        }
    }
}
/* localdecomp:end func_L01_003C54E8 */

/* localdecomp:start func_L01_003C55B8 */
extern u16 **D_L01_001D6764;
extern u8 *D_L01_001E0ED4;
s32 func_L01_003C55B8(void *a0, u8 *a1) {
    u16 *p = D_L01_001D6764[*(s32 *)(a1 + 0x20)];
    u8 *e = D_L01_001E0ED4 + ((*p & 0x7FFF) << 5);

    return e[0x1C] != 0;
}
/* localdecomp:end func_L01_003C55B8 */

/* localdecomp:start func_L01_003C55F8 */
extern s32 D_L01_001DEE54;
s32 func_L01_003C55F8(void) {
    return D_L01_001DEE54;
}
/* localdecomp:end func_L01_003C55F8 */

/* localdecomp:start func_L01_003C5600 */
u8 func_L01_003C5600(u8 *a) {
    return *(*(u8 **)(a + 0x68) + 0x103);
}
/* localdecomp:end func_L01_003C5600 */

/* localdecomp:start func_L01_003C5610 */
extern void func_L01_003C6F68(void *, s32);
void func_L01_003C5610(void *p) {
    func_L01_003C6F68(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C5610 */

/* localdecomp:start func_L01_003C5630 */
extern void func_L01_003C6EF0(void *, s32);
void func_L01_003C5630(void *p) {
    func_L01_003C6EF0(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C5630 */

/* localdecomp:start func_L01_003C5650 */
extern void func_L01_00456230(u8 *o, s32 a);

void func_L01_003C5650(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    func_L01_00456230(a, 1);
    p[259] = 1;
}
/* localdecomp:end func_L01_003C5650 */

/* localdecomp:start func_L01_003C5688 */
void func_L01_003C5688(u8 *obj) {
    (*(u8 **)(obj + 104))[259] = 1;
}
/* localdecomp:end func_L01_003C5688 */

/* localdecomp:start func_L01_003C5698 */
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_L01_001DFE80[1];

s32 func_L01_003C5698(u8 *a0, u8 *a1) {
    s32 i;
    if ((a0[0xB0] != 0xFF && (D_001BBC40[D_001D545C][a0[0xB0]] & 0x80)) ||
        ((i = *(s32 *)(a1 + 0x6B4)) != -1 && (D_L01_001DFE80[i] & 0x80))) {
        return *(s32 *)(a1 + 0x6B8);
    }
    return *(s32 *)(a1 + 0x6B0);
}
/* localdecomp:end func_L01_003C5698 */

/* localdecomp:start func_L01_003C5710 */

void func_L01_003C5710(u8 *a0, u128_3C3E90 *a1, u128_3C3E90 *a2) {
    *(u128_3C3E90 *)(a0 + 0x00) = *a1;
    *(u128_3C3E90 *)(a0 + 0x10) = *a2;
}
/* localdecomp:end func_L01_003C5710 */

/* localdecomp:start func_L01_003C5728 */
extern void func_L01_003C5110(void *a0, u8 *a1);

extern void func_L01_003C5710(u8 *, u128_t *, u128_t *);
extern void func_0038D308(u8 *, u8 *);
extern void func_L01_0044F450(u8 *, u8 *);

void func_L01_003C5728(u8 *m, u8 *b, u128_t *pos, u128_t *dir) {
    func_L01_003C5710(b, pos, dir);
    *(u128_t *)(m + 16) = *pos;
    *(u128_t *)(m + 240) = *dir;
    func_0038D308(m + 192, m + 240);
    func_L01_0044F450(m, b + 368);
    ((void (*)(u8 *, u8 *))func_L01_003C5110)(m, b);
}
/* localdecomp:end func_L01_003C5728 */

/* localdecomp:start func_L01_003C57B0 */
extern void func_L01_003C5728(u8 *m, u8 *b, u128_t *pos, u128_t *dir);
extern char *D_L01_001E0100;
void func_L01_003C57B0(void *a, void *b, int i) {
    char *p = D_L01_001E0100 + i * 128;
    ((void (*)(void *, void *, char *, char *))func_L01_003C5728)(a, b, p + 48, p + 112);
}
/* localdecomp:end func_L01_003C57B0 */

/* localdecomp:start func_L01_003C57E0 */
extern u8 D_001A4BE0[];
extern s32 func_00382380(u8 *, s32, s32);
extern void func_L01_00456230(u8 *o, s32 a);

void func_L01_003C57E0(u8 *a0, u8 *a1) {
    u8 *p = D_001A4BE0;
    s32 v = *(s32 *)(p + 9668);
    if (v == 116 || v == 49 || v == 101) {
        return;
    }
    if (*(s32 *)(p + 860) == *(s32 *)(a1 + 72) ||
        (*(s32 *)(a1 + 204) != -1 && func_00382380(p + 128, *(s32 *)(a1 + 204), 0) != 0)) {
        func_L01_00456230(a0, 1);
        a1[259] = 1;
    } else {
        func_L01_00456230(a0, 0);
    }
}
/* localdecomp:end func_L01_003C57E0 */

/* localdecomp:start func_L01_003C5888 */
extern u8 D_001A4BE0[];
extern s32 func_L01_00511A98(void);
extern void func_L01_00511AE8(void);
extern s32 func_L01_003C6860(M_3C4008 *);
extern s32 func_L01_00456250(M_3C4008 *);
void func_L01_003C5888(M_3C4008 *m, B_3C4008 *b) {
    if (b->b100 == 0) {
        return;
    }
    if (func_L01_00511A98() != 0) {
        if (b->b100 == 2) {
            return;
        }
        if ((*(G_3C4008 *)&D_001A4BE0).w25C4 == 105) {
            return;
        }
        if (m->b20 == 5 && func_L01_003C6860(m) != 0) {
            if (b->p54 == 0) {
                return;
            }
            if (b->p54->w98 == 0) {
                return;
            }
        }
        if (func_L01_00456250(m) != 0) {
            return;
        }
        if (!(0.9f < (*(G_3C4008 *)&D_001A4BE0).f283C)) {
            return;
        }
        func_L01_00511AE8();
        b->b100 = 0;
    } else {
        b->b100 = 0;
    }
}
/* localdecomp:end func_L01_003C5888 */

/* localdecomp:start func_L01_003C5970 */
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001F3F40[];
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_0042B068(s32, s32);
extern void func_L01_003C5290(u8 *, u8 *);


void func_L01_003C5970(u8 *m, u8 *v) {
    s32 e = ((S_3C40F0 *)v)->arr[((S_3C40F0 *)v)->idx];
    u16 *list;
    u8 *o;

    if (e != -1 && e != D_L01_001F3F40[0]) {
        func_L01_0042B068(e, 0);
    }
    func_L01_003C5290(m, v);
    list = D_L01_0021DE20[*(s32 *)(v + 36)];
    while ((*(s32 *)(v + 36) & 0xFF) != 255 && *(s32 *)(v + 36) <= D_L01_001E0058 && list != 0 &&
           ((s16)list[-1] >= 0 || list == D_L01_0021DE20[*(s32 *)(v + 36)])) {
        o = (*(u8 * *)&D_L01_001E001C) + ((*list & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        list++;
        *(u16 *)(o + 52) &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_003C5970 */

/* localdecomp:start func_L01_003C5A78 */
extern void func_L01_003C5290(u8 *, u8 *);

extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001F3F40[];
extern void func_L01_0042B068(s32 a, s32 b);

void func_L01_003C5A78(void *a, O_3C41F8 *o, s32 i) {
    u16 *p;
    M_3C41F8 *e;
    s32 s = o->a1872[i];

    if (s == -1) {
        s32 t = o->a1728[i];
        if (t != s && t != D_L01_001F3F40[0]) {
            func_L01_0042B068(t, 0);
        }
    } else if (s != D_L01_001F3F40[0]) {
        func_L01_0042B068(s, 0);
    }
    ((void (*)(void *a, O_3C41F8 *o))func_L01_003C5290)(a, o);
    for (p = D_L01_0021DE20[o->id];
         (o->id & 0xFF) != 0xFF && o->id <= D_L01_001E0058 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L01_0021DE20[o->id]);
         p++) {
        e = *(M_3C41F8 **)&D_L01_001E001C + (p[0] & 0x7FFF);
        if (e == 0) {
            break;
        }
        e->h52 &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_003C5A78 */

/* localdecomp:start func_L01_003C5BA8 */
extern s32 func_00382380(u8 *, s32, s32);
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];


s32 func_L01_003C5BA8(s32 unused, u8 *obj) {
    s32 i;
    s32 *p = (s32 *)(obj + 1856);
    for (i = 0; i < 4; i++, p++) {
        s32 a = p[-4];
        s32 b;
        if (a == -1) {
            continue;
        }
        b = p[0];
        if (b != -1 && !(D_001BBC40[D_001D545C][b] & 0x80)) {
            continue;
        }
        if (((s32 (*)(void *a, s32 b, s32 c))func_00382380)(D_001A4C60, a, 0) != 0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_003C5BA8 */

/* localdecomp:start func_L01_003C5C60 */
extern void func_L01_003F5E88(u8 *);
void func_L01_003C5C60(s32 a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 84);
    if (s != 0 && *(s32 *)(s + 152) == 0) {
        func_L01_003F5E88(s);
        *(s32 *)(s + 152) = *(s32 *)(*(u8 **)(s + 36) + 16);
    }
}
/* localdecomp:end func_L01_003C5C60 */

/* localdecomp:start func_L01_003C5CA8 */
extern void func_L01_003F5EE0(u8 *);

void func_L01_003C5CA8(void *self, u8 *obj) {
    u8 *s = *(u8 **)(obj + 84);
    if (s != 0 && *(s32 *)(s + 152) != 0) {
        func_L01_003F5EE0(s);
        *(s32 *)(s + 152) = 0;
    }
}
/* localdecomp:end func_L01_003C5CA8 */

#include "vu0.h"
/* localdecomp:start func_L01_003C5CE8 */

typedef struct { vu0_q q; } vu0_s_003C5CE8;
static __inline__ void vec_add_copy_003C5CE8(void *d, void *b, void *cd, void *cs, f32 *zp, f32 z) {
    vu0_q x, y, w;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)cs));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)cd) : "j"(y), "j"(x));
    *zp = z;
    __asm__("lqc2 %0, %1" : "=j"(w) : "m"(*(vu0_v4 *)d));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(w) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(w));
}
extern f32 D_L01_001DECEC;
extern f32 D_L01_001DECF0;
extern f32 D_L01_001DECF4;
__asm__(".extern D_L01_001DECEC, 4");
__asm__(".extern D_L01_001DECF0, 4");
__asm__(".extern D_L01_001DECF4, 4");
extern vu0_v4 D_L01_001E2A40[];
extern char *D_L01_001E0100;
extern f32 fe_func_0038CED8(void *);
extern f32 fe_func_0038D160(f32, f32);
extern void fe_func_0038CE20(void *, void *, f32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB350(s32, void *);

void func_L01_003C5CE8(u8 *self, u8 *p) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 c;
    s32 i;
    f32 z;
    char *e;

    fe_func_0038CE20(&t, self + 0xC0, D_L01_001DECEC + D_L01_001DECF0 * *(f32 *)(p + 0xC8));
    z = t.z + D_L01_001DECF4;
    vec_add_copy_003C5CE8(&t, self + 0x10, &c, D_L01_001E2A40, &t.z, z);
    vec_sub_ab(&d, &t, &c);
    qzero(&r);
    r.y = -fe_func_0038D160(fe_func_0038CED8(&d), d.z);
    r.z = fe_func_0038D160(d.x, d.y);
    func_L01_003EB3C0(0, &r);
    if ((u8)(self[0x20] - 11) < 2) {
        e = D_L01_001E0100 + *(s32 *)((*(s32 *)(p + 0x104) << 2) + p + 0x760) * 128;
    } else {
        e = D_L01_001E0100 + *(s32 *)((*(s32 *)(p + 0x6BC) << 2) + p + 0x760) * 128;
    }
    func_L01_003EB350(0, e + 0x30);
}
/* localdecomp:end func_L01_003C5CE8 */

/* localdecomp:start func_L01_003C5DF0 */
#include "vu0.h"
__asm__(".extern D_L01_001DEDD0, 8");
extern u8 D_L01_001DEDD0[8];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
void func_L01_003C5DF0(s32 arg0, s32 unused, s32 flag) {
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_005003D0(s32, s32);
    vu0_v4 pos, rot;
    u8 *m = (u8 *)arg0;
    u8 *hero;
    f32 angle;
    func_0038D000(&pos, D_L01_001DEDD0, m + 0xC0);
    {
        vu0_q qa, qb, qr;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(m + 0x10)));
        angle = *(f32 *)(m + 0xF8);
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qr));
    }
    qzero(&rot);
    rot.z = func_0038DAB8(angle, 3.1415927f);
    *(vu0_q *)D_001A4C60 = *(vu0_q *)&pos;
    hero = D_001A4C60 - 0x80;
    *(vu0_q *)(*(u8 **)(hero + 0x25C0) + 0x10) = *(vu0_q *)&pos;
    *(vu0_q *)(hero + 0x90) = *(vu0_q *)&rot;
    if (flag) {
        if (*(s32 *)(hero + 0x25C4) != 0x31) func_L01_005003D0(0x31, 1);
    } else {
        if (*(s32 *)(hero + 0x25C4) != 0x74) func_L01_005003D0(0x74, 1);
    }
}
/* localdecomp:end func_L01_003C5DF0 */

/* localdecomp:start func_L01_003C5EC0 */
void func_L01_003C5DF0(s32, s32, s32);
void func_L01_003EB5E0(s32, s32);
extern s32 D_L01_001DF95C;

void func_L01_003C5EC0(s32 arg0, s32 arg1) {
    func_L01_003EB5E0(0, 3);
    func_L01_003C5DF0(arg0, arg1, 0);
    D_L01_001DF95C = 0;
}
/* localdecomp:end func_L01_003C5EC0 */

/* localdecomp:start func_L01_003C5F10 */
extern u8 *D_L01_001E001C_003C5F10;
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
void func_L01_003C5F10(void *self, O3C48A8 *obj) {
    extern void func_L01_003C64E0(void *, s32, u128_t *, f32 *);
    extern void func_0038D308(u8 *, u8 *);
    extern void func_L01_0044FD88(u8 *, u8 *, s32, s32);
    u128_t pos;
    f32 angle;
    u16 *p;
    u8 *m, *v, *o, *child;
    s32 i = 0;
    s32 g;
    p = D_L01_0021DE20[obj->group];
    while (g = obj->group, (g & 255) != 255 && g <= D_L01_001E0058 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20[g])) {
        m = D_L01_001E001C_003C5F10 + ((*p & 0x7FFF) << 8);
        if (m == 0) break;
        if (m[0x20] == 254) goto next;
        if (m[0x20] == 253) goto next;
        v = *(u8 **)(m + 0x68);
        *(u16 *)(m + 0x34) &= 0xFFFD;
        func_L01_003C64E0(self, i, &pos, &angle);
        *(u128_t *)(m + 0x10) = pos;
        *(f32 *)(m + 0xF8) = angle;
        if (*(s32 *)(v + 0x50) == -1) goto next;
        o = D_L01_001E001C_003C5F10 + (*(s32 *)(v + 0x50) << 8);
        *(u128_t *)(o + 0x10) = pos;
        *(f32 *)(o + 0xF8) = angle;
        if (!(*(u16 *)(o + 0x34) & 2) && o[0x31] && !(*(u16 *)(o + 0x34) & 0x80)) goto next;
        child = *(u8 **)(*(u8 **)(o + 0x68) + 0x550);
        *(u16 *)(o + 0x34) &= 0xFFBC;
        *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
        { s32 data = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        *(u16 *)(o + 0x34) &= 0xFF7F;
        *(s32 *)(o + 0x98) = data; }
        func_0038D308(m + 0xC0, m + 0xF0);
        func_0038D308(o + 0xC0, o + 0xF0);
        if (child != 0) {
            *(u16 *)(child + 0x34) &= 0xFFBE;
            *(u16 *)(child + 0x34) |= *(u16 *)(*(u8 **)(child + 0x24) + 0x44) & 0x1000;
            { s32 data = *(s32 *)(*(u8 **)(child + 0x24) + 0x10);
            *(u16 *)(child + 0x34) &= 0xFF7F;
            *(s32 *)(child + 0x98) = data; }
            func_L01_0044FD88(o, child, 0, 0);
        }
next:
        i++;
        p++;
    }
    obj->active = 1;
}
/* localdecomp:end func_L01_003C5F10 */

/* localdecomp:start func_L01_003C6128 */
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_004AA7E8(M3C48A8 *m, s32 a1);
void func_L01_003C6128(void *a0, O3C48A8 *obj) {
    s16 *p;
    M3C48A8 *m;
    M3C48A8 *o;
    M3C48A8 *c;
    s32 g;

    p = ((s16 * *)&D_L01_0021DE20)[obj->group];
    while (g = obj->group, (g & 0xFF) != 255 && g <= D_L01_001E0058 && p != 0 &&
             (p[-1] >= 0 || p == ((s16 * *)&D_L01_0021DE20)[g])) {
        m = &(*(M3C48A8 * *)&D_L01_001E001C)[*p & 0x7FFF];
        if (m == 0) {
            break;
        }
        if (m->state == 254) {
            goto next;
        }
        if (m->state == 253) {
            goto next;
        }
        if (m->flags & 2) {
            goto next;
        }
        if (m->vars->link == -1) {
            goto next;
        }
        o = &(*(M3C48A8 * *)&D_L01_001E001C)[m->vars->link];
        c = o->vars->child;
        m->flags |= 2;
        o->f98 = 0;
        o->flags = (o->flags | 0x43) & ~0x1000;
        func_L01_004AA7E8(o, 1);
        if (c != 0) {
            c->f98 = 0;
            c->flags = (c->flags | 0x41) & ~0x1000;
            func_L01_004AA7E8(c, 1);
        }
next:
        p++;
    }
    obj->active = 0;
}
/* localdecomp:end func_L01_003C6128 */

/* localdecomp:start func_L01_003C6288 */
typedef struct {
    u8 p0[0x170];
    s32 x170;
    s32 x174;
    u8 p178[8];
    s32 x180;
} V_003C6288;

extern f32 func_0038DAB8(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
__asm__(".extern D_L01_001DEDD0, 8");
extern u8 D_L01_001DEDD0[8];
extern u8 D_001A4BE0[];

void func_L01_003C6288(u8 *obj) {
    vu0_v4 a;
    vu0_v4 b;

    func_L01_003C5970(obj, *(u8 **)(obj + 0x68));
    func_0038D000(&a, D_L01_001DEDD0, obj + 0xC0);
    vec_add_ba(&a, &a, obj + 0x10);
    qzero(&b);
    b.z = func_0038DAB8(*(f32 *)(obj + 0xF8), 3.1415927f);
    (*(V_003C6288 *)&D_001A4BE0).x170 = 0;
    (*(V_003C6288 *)&D_001A4BE0).x174 = 0;
    (*(V_003C6288 *)&D_001A4BE0).x180 = 0;
    func_L01_004F50C8(&a, &b, 0x74, 1);
}
/* localdecomp:end func_L01_003C6288 */

/* localdecomp:start func_L01_003C6318 */
extern void func_0038CF68(void *, void *, f32);

void func_L01_003C6318(u8 *obj, f32 *out) {
    vec_neg(out, obj + 0xC0);
    out[2] = 0.0f;
    func_0038CF68(out, out, 1.0f);
}
/* localdecomp:end func_L01_003C6318 */

/* localdecomp:start func_L01_003C6350 */
extern f32 func_0038DAB8(f32, f32);

void func_L01_003C6350(u8 *obj, u8 *out) {
    qzero(out);
    *(f32 *)(out + 8) = func_0038DAB8(*(f32 *)(obj + 0xF8), 3.1415927f);
}
/* localdecomp:end func_L01_003C6350 */

/* localdecomp:start func_L01_003C6390 */
#include "vu0.h"
extern u8 D_L01_001DEDE0[8];
__asm__(".extern D_L01_001DEDE0, 8");
void func_L01_003C6390(u8 *obj, void *out) {
    extern void func_0038D000(void *, void *, void *);
    func_0038D000(out, D_L01_001DEDE0, obj+0xC0);
    vec_add_ba(out,out,obj+0x10);
}
/* localdecomp:end func_L01_003C6390 */

/* localdecomp:start func_L01_003C63E0 */
#include "vu0.h"
extern s32 D_L01_001F3F40[];
extern char *D_L01_001E0100;
extern u8 D_L01_001DEE10[8];
extern u8 D_L01_001DEDF0[8];
extern f32 D_L01_001DEE20;
extern u8 D_001A4CD0[];
__asm__(".extern D_L01_001E0100, 4");
__asm__(".extern D_L01_001DEE10, 8");
__asm__(".extern D_L01_001DEDF0, 8");
__asm__(".extern D_L01_001DEE20, 4");
void func_L01_003C63E0(u8 *obj,s32 flag) {
    extern void func_L01_003C5970(u8 *,u8 *);
    extern void func_0038D000(void *,void *,void *);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_0038CBA0(void *,s32);
    extern void func_L01_004F50C8(void *,void *,s32,s32);
    vu0_v4 pos,rot;
    u8 *v=*(u8 **)(obj+0x68);
    func_L01_003C5970(obj,v);
    if(D_L01_001F3F40[0]==*(s32 *)(v+0xE0) && *(s32 *)(v+0xE4)!=-1) {
        char *p=D_L01_001E0100+(*(s32 *)(v+0xE4)<<7);
        *(vu0_q *)&pos=*(vu0_q *)(p+0x30);
        *(vu0_q *)&rot=*(vu0_q *)(p+0x70);
    } else {
        if(flag)func_0038D000(&pos,D_L01_001DEE10,obj+0xC0);
        else func_0038D000(&pos,D_L01_001DEDF0,obj+0xC0);
        vec_add_ab(&pos,&pos,obj+0x10);
        qzero(&rot);
        if(flag)rot.z=func_0038DAB8(*(f32 *)(obj+0xF8),D_L01_001DEE20);
        else rot.z=*(f32 *)(obj+0xF8);
    }
    func_0038CBA0(D_001A4CD0,0xA0);
    func_L01_004F50C8(&pos,&rot,0x74,1);
}
/* localdecomp:end func_L01_003C63E0 */
