#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L20_003F1A78);

INCLUDE_ASM("asm/levels", func_L20_003F21A8);

/* localdecomp:start func_L20_003F22C0 */
typedef struct {
    vu0_v4 vel;
    f32 gravity, radius;
    s32 id;
    u8 pad1C[4];
    f32 angle0, angle1;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    s16 h34, h36, h38, h3A;
    s32 i3C;
    s16 timer, hits;
    u8 pad44[8];
    f32 scale;
    u8 pad50[0xC70-0x50];
    vu0_v4 vectors[12];
    f32 rates[12];
    u8 padD60[0x10];
    vu0_v4 base;
} S_003F22C0;
typedef struct {
    u8 pad0[0x10]; vu0_v4 pos;
    u8 state; u8 pad21[0x47];
    S_003F22C0 *s;
    u8 pad6C[0x29]; u8 phase;
    u8 pad96[0x22]; s32 collision;
    u8 padBC[0x3C]; f32 angle;
} M_003F22C0;
typedef struct { u8 pad0[0xD0]; u8 active; u8 padD1[0xB]; void *owner; } E_003F22C0;
extern vu0_v4 D_L20_001D66B0 __attribute__((section(".sdata")));
extern u8 *D_L20_002202B4 __attribute__((section(".data")));
__asm__(".extern D_L20_002202B4, 16");
extern u8 D_001A30B0[];
extern vu0_v4 D_L20_001E9BE0;
extern vu0_v4 D_001A4CB0;
extern vu0_v4 D_L20_001E2E00;
extern s32 D_L20_001DF404;
__asm__(".extern D_L20_001DF404, 4");
void func_L20_003F22C0(M_003F22C0 *m) {
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003A4F28(s32);
    extern s32 func_L04_00325460(void *, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
    extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003C2880(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_00382538(void);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L20_003F2918(void *);
    extern s32 func_0038CB00(s16 *);
    extern void func_L01_00404A10(void (*)(void *), void *);
    extern void func_L20_003F3F28(void *);
    extern void func_L20_003F3FF8(void *);
    extern void func_L20_003F3528(void *);
    extern void func_L20_003F32D0(void *);
    S_003F22C0 *s = m->s;
    vu0_v4 old, delta;
    vu0_v4 *position = &m->pos;
    u8 *particle;
    s32 random;
    f32 size;
    s32 i;
    E_003F22C0 *entry;
    random = func_00382468(40);
    size = func_003824E0(500.0f, 1500.0f);
    particle = func_L01_0046A610(position, &D_L20_001D66B0, 33, 127, 0x101010, random,
        672000.0f, size, 1.0f, 0.0f, 0.0f);
    if (particle) {
        u8 color = D_L20_002202B4[0];
        particle[3] = 0x44;
        particle[2] = color;
    }
    if (s->id == -1 || (entry = (E_003F22C0 *)(D_001A30B0 + (s->id << 7)))->owner != m || !entry->active) {
        s->id = func_003A52A0(0, 4, m);
    }
    switch (m->state) {
    case 0:
        old = m->pos;
        vec_add_ab(&m->pos, &m->pos, &s->vel);
        s->vel.z -= s->gravity;
        if (func_003D3CB0(&old, &m->pos, 0, m->collision, 0)) {
            m->pos = D_L20_001E9BE0;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (s->id != -1) {
            entry = (E_003F22C0 *)(D_001A30B0 + (s->id << 7));
            if (entry->owner == m && entry->active) func_003A4F28(s->id);
        }
        s->id = -1;
        func_003A52A0(1, 0, m);
        func_L04_00325460(&m->pos, 1.0f, 0, 25, 20, 20, 20, 45, 1, 1, 0, 0, 0, 20.0f);
        func_L01_00446780(m, &m->pos, 1, 0, 1, 0, 2.0f, s->radius, 1.0f);
        func_003C2880(m);
        return;
    }
    s->angle0 = func_0038DAB8(s->angle0, 0.034906588f);
    s->angle1 = func_0038DAB8(s->angle1, 0.10471976f);
    switch (m->phase) {
    case 0:
        s->base = D_001A4CB0;
        for (i = 0; i < 12; i++) {
            s->rates[i] = func_003824E0(0.017453294f, 0.05235988f);
            s->scale = 2.0f;
            old.x = func_0038D098(m->angle);
            old.y = func_0038D0B0(m->angle);
            old.z = 0.0f;
            vec_sub_ba(&delta, &D_L20_001E2E00, &m->pos);
            func_0038CF68(&delta, &delta, 1.0f);
            func_0038CE90(&s->vectors[i], &old, &delta);
            func_0038CF68(&s->vectors[i], &s->vectors[i], s->scale);
            func_0038D890(&s->vectors[i], &s->vectors[i], &delta, func_00382538());
        }
        func_L20_003F2918(m);
        s->timer = (s->i3C * 5 + 2) / 6;
        m->phase = 2;
        s->f2C = 2.5f;
        s->h38 = 1;
        s->h3A = 1;
        break;
    case 2:
        if (func_0038CB00(&s->timer)) {
            m->phase = 1;
            s->timer = (s->h34 * 5 + 2) / 6;
            func_L20_003F2918(m);
        }
        break;
    case 1:
        if (func_0038CB00(&s->timer)) {
            if (s->h36) {
                m->phase = 2;
                s->timer = 4;
            } else s->timer = 4;
        } else if (s->hits == 0) {
            func_L20_003F2918(m);
        }
        break;
    }
    func_L01_00404A10(func_L20_003F3F28, m);
    func_L01_00404A10(func_L20_003F3FF8, m);
    if (s->hits) {
        func_L20_003F32D0(m);
        if (s->hits > D_L20_001DF404) func_L01_00404A10(func_L20_003F3528, m);
    }
}
/* localdecomp:end func_L20_003F22C0 */

/* localdecomp:start func_L20_003F27E8 */
typedef int q_003F27E8 __attribute__((mode(TI)));

typedef struct P_003F27E8 {
    q_003F27E8 q0;
    f32 f10;
    f32 f14;
} P_003F27E8;

typedef struct M_003F27E8 {
    u8 pad0[0x10];
    q_003F27E8 q10;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34;
    u8 pad36[0x32];
    P_003F27E8 *p68;
    u8 pad6C[0x2C];
    s32 i98;
    u8 pad9C[0x24];
    u8 vC0[0x30];
    u8 vF0[0x10];
} M_003F27E8;

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0044E820(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

M_003F27E8 *func_L20_003F27E8(u8 *a0, q_003F27E8 *a1, q_003F27E8 *a2, f32 x, f32 y) {
    M_003F27E8 *m = (M_003F27E8 *)func_003C24B0(0x1D8D, 0xD90);
    P_003F27E8 *p;
    if (m != 0) {
        func_L01_00456160((u8 *)m, a0);
        m->q10 = *a1;
        func_L01_00443B88(m->vF0, -3.1415927f, 3.1415927f);
        func_0038D308(m->vC0, m->vF0);
        m->i98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
        m->h34 |= 0x100;
        p = m->p68;
        p->q0 = *a2;
        p->f10 = x;
        p->f14 = y;
        m->f2C = *(f32 *)(m->p24 + 0x24) * 0.6f;
        func_L01_0044E820(m, 0x800000C0);
        func_L01_004450F0(m, 0, -1);
    }
    return m;
}
/* localdecomp:end func_L20_003F27E8 */

INCLUDE_ASM("asm/levels", func_L20_003F2918);
