#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003F56F8 */
typedef struct {
    u8 pad0[0x10];
    vu0_q pos;
    u8 state;
    u8 pad21[0x24 - 0x21];
    u8 *pclass;
    u8 pad28[0x2C - 0x28];
    f32 scale;
    u8 pad30;
    u8 f31;
    u8 pad32[0x34 - 0x32];
    u16 flags;
    u8 pad36[0x42 - 0x36];
    u8 f42;
    u8 f43;
    u8 pad44[0x48 - 0x44];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 f60;
    u8 pad61[0x68 - 0x61];
    void *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 oClass;
    u8 padAC[0xB0 - 0xAC];
    u8 fB0;
    u8 padB1[0xF0 - 0xB1];
    vu0_q rot;
} Moby_L04_003F56F8;

typedef struct {
    vu0_q pos;
    f32 f10;
    u8 pad14[0x1C - 0x14];
    s16 timer;
    u8 item;
    u8 f1F;
} Vars_L04_003F56F8;

typedef struct {
    u8 pad0[0x76];
    s16 f76;
    u8 pad78[0x98 - 0x78];
    s16 f98;
    u8 pad9A[0x9E - 0x9A];
    s16 f9E;
} G_L04_003F56F8;

extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001D5530[];
extern u8 D_001BBC40[][16];
extern s32 D_001D545C;
extern G_L04_003F56F8 D_001CCFD0_003F56F8;
typedef struct {
    s32 f0;
    s32 f4;
} T_L04_003F56F8;
__asm__(".extern D_L04_001DFB34, 16");
extern T_L04_003F56F8 D_L04_001DFB34;
extern s32 D_L04_001DF75C;
extern void func_L01_00445F40(void *, s32);
extern s32 func_L01_00446058(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_0043B510(s32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);
extern u8 func_L04_003F5AF8(u8 *);
extern void func_L04_003F5B78(u8 *);
extern void func_003A1798(void);
extern void func_L04_003F5E38(u8 *);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);
extern void func_L01_0044FC48(s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_0039EC28(s32, s32);

void func_L04_003F56F8(Moby_L04_003F56F8 *m) {
    Vars_L04_003F56F8 *v = m->vars;
    s32 cls;
    u8 *h;

    if (m->state == 0) {
        switch (m->oClass) {
        case 0x1F4B:
            v->item = 0x21;
            break;
        case 0x1F4C:
            v->item = 0x1F;
            break;
        case 0x1F4D:
            v->item = 0x22;
            break;
        case 0x1F4E:
            v->item = 0x20;
            break;
        case 0x1F4F:
            v->item = 0x23;
            break;
        default:
            v->item = 0xFF;
            break;
        }
        if (v->item == 0xFF || *(D_001D5530 + v->item) != 0) {
            func_003C2880(m);
            return;
        }
        cls = m->oClass;
        if (cls != 0x1F4B) {
            func_L01_00445F40(m, 0x1F4B);
            func_L01_00446058(m, cls, 0x1F4B);
            m->flags &= ~0x40;
            m->f48 = 1.0f;
        }
        v->pos = m->pos;
        v->f10 = ((f32 *)&m->rot)[2];
        ((f32 *)&m->rot)[1] = -1.5707964f;
        ((f32 *)&m->pos)[2] += 1.0f;
        m->scale = *(f32 *)(m->pclass + 0x24) * 3.0f;
        if (v->f1F != 0) {
            m->f31 = 0;
            m->flags |= 1;
            func_L01_004450F0(m, 1, -1);
        } else {
            func_L01_004450F0(m, 2, -1);
        }
    }
    switch (m->state) {
    case 1:
        if (func_L01_00456250(m) == 0) {
            if (m->fB0 == 0xFF) {
                return;
            }
            if (!(D_001BBC40[D_001D545C][m->fB0] & 0x80)) {
                return;
            }
        }
        if (m->fB0 != 0xFF) {
            func_L01_0043B510(m->fB0);
        }
        m->f31 = 1;
        m->flags &= ~1;
        func_L01_004450F0(m, 2, -1);
        break;
    case 2:
        if (D_001D5530[v->item] != 0) {
            func_003C2880(m);
            return;
        }
        ((f32 *)&m->rot)[0] = func_0038DAB8(((f32 *)&m->rot)[0], 0.0837758109f);
        if (func_L04_003F5AF8((u8 *)m)) {
            func_L04_003F5B78((u8 *)m);
        }
        break;
    case 3:
        if (D_001CCFD0_003F56F8.f76 == 0 && D_001CCFD0_003F56F8.f9E == 3 && D_001CCFD0_003F56F8.f98 < 7000) {
            func_003A1798();
        }
        h = D_001A4BE0;
        *(s16 *)(h + 0x1DC) = 3;
        D_L04_001DFB34.f4 = 1;
        func_L04_003F5E38((u8 *)m);
        m->pos = *(vu0_q *)(h + 0x80);
        m->rot = *(vu0_q *)(h + 0x90);
        if (*(s32 *)(h + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (m->f42 != 1) {
            return;
        }
        if (!(m->f60 & 2)) {
            return;
        }
        if (m->f43 != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        m->f31 = 0;
        m->flags |= 1;
        func_L01_004450F0(m, 4, -1);
        break;
    case 4:
        if (func_0038CB00(&v->timer) == 0) {
            return;
        }
        if (v->item != 0xFF) {
            func_L01_0044CCC8(v->item);
            func_0039EF28();
            func_L01_0044FC48(v->item, 0);
        }
        D_L04_001DF75C = 0;
        func_L01_004F50C8(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
        func_L01_003EB5E0(0, 0);
        func_0039EC28(0, -1);
        func_003C2880(m);
        break;
    }
}
/* localdecomp:end func_L04_003F56F8 */

/* localdecomp:start func_L04_003F5AF8 */
extern u8 D_001A4BE0[];
extern s32 func_00382380(void *, s32, s32);
extern f32 func_L01_0040E548(void *, void *);

u8 func_L04_003F5AF8(u8 *m) {
    u8 *g = D_001A4BE0;
    u8 *v = *(u8 **)(m + 0x68);
    s32 id;

    if (*(s32 *)(g + 0x360) == 0) {
        return 0;
    }
    id = *(s32 *)(v + 0x14);
    if (id != -1) {
        return func_00382380(g + 0x80, id, 0);
    }
    return func_L01_0040E548(m + 0x10, g + 0x80) < *(f32 *)(v + 0x18) * *(f32 *)(v + 0x18);
}
/* localdecomp:end func_L04_003F5AF8 */

/* localdecomp:start func_L04_003F5B78 */
typedef int u128_003F5B78 __attribute__((mode(TI)));
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[0x94 - 0x70]; s32 i94; } G_003F5B78;
extern u8 D_001D5469;
extern s32 D_L04_001DF75C_003F5B78;
extern G_003F5B78 D_001CCFD0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern void func_L01_004ED658_003F5B78(s32);
extern void func_L01_004F50C8_003F5B78(void *, void *, s32, s32);
extern void func_L01_003EB438_003F5B78(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350_003F5B78(s32, void *);
extern void func_L01_003EB3C0_003F5B78(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40_003F5B78(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_L01_004450F0_003F5B78(void *, s32, s32);

void func_L04_003F5B78(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;
    *(f32 *)(a0 + 0x2C) = (*(f32 **)(a0 + 0x24))[0x24/4];
    v[0] = func_0038D098(*(f32 *)(q + 0x10)) * 2.5f;
    v[1] = func_0038D0B0(*(f32 *)(q + 0x10)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q);
    qzero(w);
    w[2] = func_0038DAB8(*(f32 *)(q + 0x10), 3.1415927f);
    func_0038A238(8);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L01_004ED658_003F5B78(0);
    }
    func_L01_004F50C8_003F5B78(v, w, 0x74, 0);
    v2[0] = func_0038D098(*(f32 *)(q + 0x10)) * 1.25f;
    v2[1] = func_0038D0B0(*(f32 *)(q + 0x10)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_0038D098(func_0038DAB8(*(f32 *)(q + 0x10), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_0038D0B0(func_0038DAB8(*(f32 *)(q + 0x10), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_0038DB00(*(f32 *)(q + 0x10), 1.5707964f);
    func_L01_003EB438_003F5B78(0, v2, w2, 1, 0, 0);
    func_L01_003EB350_003F5B78(0, v2);
    func_L01_003EB3C0_003F5B78(0, w2);
    *(u128_003F5B78 *)(a0 + 0x10) = *(u128_003F5B78 *)(h + 0x80);
    *(u128_003F5B78 *)(a0 + 0xF0) = *(u128_003F5B78 *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003C3A10(a0, 1, 0, 0);
    }
    func_L01_0050FB40_003F5B78(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L04_001DF75C_003F5B78 = 1;
    *(s16 *)(q + 0x1C) = 0x32;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_003A2B68(0xEB8, 0);
        }
    }
    func_L01_004450F0_003F5B78(a0, 3, -1);
}
/* localdecomp:end func_L04_003F5B78 */

/* localdecomp:start func_L04_003F5E38 */
extern f32 func_L01_004395E0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern u8 D_001A4BE0[];

void func_L04_003F5E38(u8 *a0) {
    vu0_v4 p;
    vu0_v4 r;
    f32 f;
    f32 t;
    f32 yaw;
    u8 *h;

    if (a0[0x42] == 1) {
        t = func_L01_004395E0(a0);
    } else {
        t = 170.0f;
    }
    f = t / 170.0f;
    h = D_001A4BE0;
    yaw = func_0038DAB8(f * 0.69813168f - 0.34906584f, *(f32 *)(h + 0x98));
    p.x = func_0038D098(yaw) * 5.0f;
    p.y = func_0038D0B0(yaw) * 5.0f;
    p.z = 0.0f;
    vec_add_ba(&p, &p, h + 0x80);
    p.z += 1.0f;
    qzero(&r);
    r.z = func_0038DAB8(yaw, 3.14159012f);
    r.y = f * -0.17f;
    func_L01_003EB350(0, &p);
    func_L01_003EB3C0(0, &r);
}
/* localdecomp:end func_L04_003F5E38 */
