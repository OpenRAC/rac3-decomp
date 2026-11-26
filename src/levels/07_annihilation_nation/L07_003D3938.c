#include "common.h"

/* localdecomp:start func_L07_003D3938 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D3938;
typedef struct {
    u8 p0[0x10];
    V4_003D3938 pos;
    u8 state;
    u8 p21[3];
    u8 *cls;
    u8 p28[8];
    u8 p30[4];
    u16 flags;
    u8 p36[0x32];
    u8 *vars;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0xE];
    s16 oclass;
    u8 pAC[0xC];
    u8 *owner;
    u8 pBC[4];
    u8 mtx[0x30];
    f32 rot[4];
} M_003D3938;
typedef struct {
    V4_003D3938 v;
    u8 *owner;
    s32 w14;
    u8 b18;
    u8 b19;
    s16 h1A;
    f32 f1C;
    s32 w20;
    f32 f24;
    u8 p28[8];
} S_003D3938;

extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L07_003D4330_003D3938(void *, void *);
extern void func_003C2880(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_003A4FF8(u8 *, s32, s32, s32, s32);
extern void func_L01_00404808(void (*)(void *), void *);
extern void func_L07_003D48D0_003D3938(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004CB320(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_004CB358(void);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L06_00359A88(void *, void *);
extern s32 func_00382468(s32);
extern s16 D_L07_001DE7C0;
extern s16 D_L07_001DE7C2;
extern u8 D_L07_001D9AE0[];
extern u8 *D_L07_001E8C18[];
extern s32 D_L07_001ECC80[];
extern u8 D_001A4BE0[];

void func_L07_003D3938(M_003D3938 *m) {
    u8 *pv = m->vars;
    V4_003D3938 tmp;
    S_003D3938 s;
    V4_003D3938 dir;
    f32 k;
    f32 drop;
    s32 hit;
    s32 n;
    s32 i;
    void *o;
    u8 *e;

    switch (m->state) {
    case 1:
        if (func_L01_004561B8(m) && (pv[0xC] & 4)) {
            *(s32 *)pv = (*(s32 *)pv >> 2) + func_00382468(*(s32 *)pv - (*(s32 *)pv >> 2));
        }
        k = (f32)*(s32 *)pv / 100.0f;
        *(f32 *)((u8 *)m + 0x2C) = *(f32 *)(m->cls + 0x24) * 1.25f * k;
        *(s16 *)(pv + 0x38) = (f32)D_L07_001DE7C0 * k;
        *(s16 *)(pv + 0x3A) = (f32)D_L07_001DE7C2 * k;
        func_0038CF68(&dir, pv + 0x10, 1.0f);
        func_L01_0044C280(&dir, &dir, D_L07_001D9AE0, 1, 0.0096f);
        func_0038CF68(pv + 0x10, &dir, func_0038CEA8(pv + 0x10));
        m->rot[2] = func_0038D160(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
        m->rot[1] = -func_0038D160(func_0038CED8(pv + 0x10), *(f32 *)(pv + 0x18));
        vec_add_ba(&tmp, &m->pos, pv + 0x10);
        m->rot[0] = func_0038DAB8(m->rot[0], 0.11170108f);
        func_0038D308(m->mtx, m->rot);
        m->pos = tmp;
        func_L06_00359A88(m, pv);
        if (func_0038CAD0(pv)) {
            if (pv[0xC] & 4) {
                func_L01_004450F0(m, 6, -1);
                return;
            }
            func_L01_004450F0(m, 2, -1);
            m->flags = (m->flags | 0x41) & ~0x1000;
            m->w98 = 0;
            func_L01_004AA7E8(m, 1);
            if (pv[0xC] & 2) {
                *(s32 *)pv = 200;
            } else {
                *(s32 *)pv = 8;
            }
        }
        break;
    case 2:
        if (func_0038CAD0(pv)) {
            func_L01_004450F0(m, 3, -1);
            if (func_L07_003D4330_003D3938(m, pv) == 0) {
                func_003C2880(m);
                return;
            }
            *(s32 *)pv = 50;
            func_003A4FF8(*(u8 **)(m->cls + 0x28) + 0x20, 0, 0, (s32)(pv + 0x20), 0x400);
        }
        break;
    case 3:
        func_L01_00404808(func_L07_003D48D0_003D3938, m);
        if (func_0038CAD0(pv)) {
            func_L01_004450F0(m, 4, -1);
            *(s32 *)pv = 4;
        }
        break;
    case 4:
        func_L01_00404808(func_L07_003D48D0_003D3938, m);
        if (func_0038CAD0(pv)) {
            u8 *c;
            u8 *vel = pv + 0x10;
            func_L01_004450F0(m, 5, -1);
            m->flags &= ~0x41;
            c = m->cls;
            m->flags |= *(u16 *)(c + 0x44) & 0x1000;
            m->w98 = *(s32 *)(c + 0x10);
            qzero(vel);
            *(f32 *)(pv + 0x18) = -*(f32 *)(pv + 0x8);
            m->rot[2] = func_0038D160(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
            m->rot[1] = -func_0038D160(func_0038CED8(vel), *(f32 *)(pv + 0x18));
            func_0038D308(m->mtx, m->rot);
            *(vu0_q *)&m->pos = *(vu0_q *)(pv + 0x20);
            m->pos.z += 20.0f;
            *(s32 *)pv = 200;
        }
        break;
    case 5:
        func_L01_00404808(func_L07_003D48D0_003D3938, m);
        k = *(f32 *)((u8 *)m + 0x2C) / *(f32 *)(m->cls + 0x24) + 0.037499998f;
        if (1.25f < k) {
            k = 1.25f;
        }
        *(f32 *)((u8 *)m + 0x2C) = *(f32 *)(m->cls + 0x24) * k;
        k = k * 0.8f;
        drop = 0.004f;
        *(s16 *)(pv + 0x38) = (f32)D_L07_001DE7C0 * k;
        *(s16 *)(pv + 0x3A) = (f32)D_L07_001DE7C2 * k;
        vec_add_ba(&tmp, &m->pos, pv + 0x10);
        *(f32 *)(pv + 0x18) -= drop;
        s.w14 = 0x10001;
        qzero(&s.v);
        s.w20 = 0;
        s.owner = m->owner;
        s.f1C = *(f32 *)(pv + 0x4);
        s.f24 = *(f32 *)(pv + 0x4);
        s.h1A = m->oclass;
        vec_sub_ab(&s.v, &m->pos, m->owner + 0x10);
        s.v.z = 0.0f;
        func_0038CF68(&s.v, &s.v, 2.0000002f);
        s.b18 = 3;
        s.v.w = 5627.925f;
        s.w20 |= 1;
        o = m->owner;
        func_L01_004CB320();
        hit = func_003D3CB0(&m->pos, &tmp, 0, (s32)o, (s32)&s);
        if (hit) {
            e = D_L07_001E8C18[0];
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit || func_L01_003FB640(&m->pos, 1, 0.2f, m->owner) ||
            func_0038CAD0(pv)) {
            n = func_003D4D00(&m->pos, 0, 1.5f, m->owner, &s);
            for (i = 0; i < n; i++) {
                s32 *l = D_L07_001ECC80;
                u8 *h = D_001A4BE0;
                if (l[i] == *(s32 *)(h + 0x25C0)) {
                    func_L01_00456230(m->owner, 1);
                }
            }
            func_003A52A0(0, 0, m);
            func_L01_003303B8(&m->pos, 0, 0, 6, 6, 3, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            m->flags = (m->flags | 0x41) & ~0x1000;
            m->w98 = 0;
            func_L01_004AA7E8(m, 1);
            func_L01_004450F0(m, 7, -1);
            return;
        }
        m->pos = tmp;
        func_L06_00359A88(m, pv);
        break;
    case 6:
        func_003A52A0(0, 0, m);
        m->flags = (m->flags | 0x41) & ~0x1000;
        m->w98 = 0;
        func_L01_004AA7E8(m, 1);
        func_L01_003303B8(&m->pos, 0, 0, 6, 6, 3, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_004450F0(m, 7, -1);
        return;
    case 7:
        if (func_L01_004561B8(m)) {
            *(s32 *)pv = 50;
        }
        if (func_0038CAD0(pv)) {
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L07_003D3938 */

/* localdecomp:start func_L07_003D41D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D41D8;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern u32 D_L07_001DE7B8[2];
__asm__(".extern D_L07_001DE7B8, 8");

u8 *func_L07_003D41D8(void *owner, V4_003D41D8 *pos, f32 *dir, u8 kind, f32 speed) {
    u8 *m = func_003C24B0(0x1C81, 0x80);
    u8 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(void **)(m + 0xB8) = owner;
        m[0x20] = 0;
        pv = *(u8 **)(m + 0x68);
        func_L01_0044A7D0(m);
        *(V4_003D41D8 *)(m + 0x10) = *pos;
        *(V4_003D41D8 *)(pv + 0x10) = *(V4_003D41D8 *)dir;
        *(f32 *)(pv + 0x8) = func_0038CEA8(dir);
        *(f32 *)(pv + 0x4) = speed;
        pv[0xC] = kind;
        func_L01_004450F0(m, 1, -1);
        *(s32 *)pv = 0x53;
        *(u16 *)(m + 0x34) |= 0x100;
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF8) = func_0038D160(dir[0], dir[1]);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(dir), dir[2]);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.25f;
        func_0038CC88(pv + 0x30, D_L07_001DE7B8, 0x10);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L07_003D41D8 */

/* localdecomp:start func_L07_003D4330 */
#include "vu0.h"
typedef struct { u8 pad[0xC]; vu0_v4 *owner; } Link_003D4330;
typedef struct { u8 pad[0x68]; Link_003D4330 *link; } State_003D4330;
typedef struct { u8 pad[0xB8]; State_003D4330 *state; } Obj_003D4330;
typedef struct { u8 pad[0xC]; u8 flags; u8 padD[0x13]; vu0_v4 pos; } Out_003D4330;
extern vu0_v4 D_L07_001E8C20;
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L04_00455AF8(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_00382538(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
s32 func_L07_003D4330(Obj_003D4330 *obj, Out_003D4330 *out) {
    vu0_v4 pos, delta, best, offset;
    vu0_v4 *origin;
    u8 *target;
    s32 i;
    f32 height;
    origin = obj->state->link->owner;
    if (out->flags & 1) {
        pos = *origin;
        if (func_L01_0040E570((u8 *)obj->state + 0x10, &pos) > 4.0f) {
            pos.z += 0.5f;
            if (func_L04_00455AF8(&pos) >= origin->z + 64.0f) {
                pos.z = func_003C3D30(&pos, 0, 0, 0.0f);
                out->pos = pos;
                out->pos.z += 0.1f;
                return 1;
            }
        }
    }
    best.z = -1.0f;
    i = 0; do {
        target = *(u8 **)((u8 *)origin + 0x10);
        if (target) {
            f32 distance, angle;
            func_0038CF68(&offset, target + 0xC0, -4.0f);
            distance = func_003824E0(0.0f, 15.0f);
            angle = func_0038DAB8(*(f32 *)(target + 0xF8), func_003824E0(-0.7853981853f, 0.7853981853f));
            pos.x = func_0038D098(angle) * distance;
            pos.y = func_0038D0B0(angle) * distance;
            pos.z = 0.0f;
            vec_add_ba(&pos, &offset, &pos);
            vec_add_ab(&pos, origin, &pos);
        } else {
            f32 angle = func_00382538();
            pos.x = func_0038D098(angle) * 5.0f;
            pos.y = func_0038D0B0(angle) * 5.0f;
            pos.z = 0.0f;
            vec_add_ab(&pos, &pos, origin);
        }
        if (func_L01_0040E570((u8 *)obj->state + 0x10, &pos) < 4.0f) continue;
        if (func_003D3CB0(origin, &pos, 2, 0, 0)) {
            vec_sub_ab(&delta, &pos, origin);
            func_0038CF68(&pos, &delta, -0.8f);
            vec_add_ab(&pos, &pos, &D_L07_001E8C20);
        }
        height = func_003C3D30(&pos, 0, 0, 0.0f);
        pos.z = height;
        if (origin->z - height > 2.5f && best.z < height) best = pos;
        out->pos = pos;
        out->pos.z += 0.1f;
        return 1;
    } while (++i < 8);
    if (best.z >= 0.0f) {
        out->pos = best;
        out->pos.z += 0.1f;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003D4330 */
