#include "common.h"

/* NTSC-U counterpart of func_L20_003F22C0 (src/levels/20_final_boss/L20_003F1A78.c) */
#include "vu0.h"
#include "vu0.h"
extern u8 D_001A30B0[];
extern vu0_v4 D_L20_001E9BE0_003F0250;
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BD360(void *);
extern void func_L01_004026A0(void (*)(void *), void *);
extern f32 func_00389380(f32, f32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L20_003F0250 */
typedef struct {
    vu0_v4 vel;
    f32 gravity, radius;
    s32 id;
    u8 pad1C[4];
    f32 angle0, angle1;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34; s16 h36, h38, h3A;
    u16 i3C; u8 pad3E[2];
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
extern vu0_v4 D_L20_001D66B0_003F0250 __attribute__((section(".sdata")));
extern u8 *D_L20_002202B4_003F0250 __attribute__((section(".data")));
__asm__(".extern D_L20_002202B4_003F0250, 16");
extern u8 D_001A30B0[];
extern vu0_v4 D_L20_001E9BE0_003F0250;
extern vu0_v4 D_001A4CB0;
extern vu0_v4 D_L20_001E2E00_003F0250;
extern s32 D_L20_001DF444_003F0250;
__asm__(".extern D_L20_001DF444_003F0250, 4");
void func_L20_003F0250(M_003F22C0 *m) {
    extern s32 func_0037E1D8(s32);
    extern f32 func_0037E250(f32, f32);
    extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_0039FE80(s32, s32, void *);
    extern s32 func_003CE740(void *, void *, s32, s32, s32);
    extern void func_L01_00441FB8(void *, s32, s32);
    extern void func_0039FB08(s32);
    extern s32 func_L04_00324BA8(void *, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
    extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003BD360(void *);
    extern f32 func_00389380(f32, f32);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern void func_00388830(void *, void *, f32);
    extern void func_00388758(void *, void *, void *);
    extern f32 func_0037E2A8(void);
    extern void func_00389158(void *, void *, void *, f32);
    extern void func_L20_003F0878(void *);
    extern s32 func_003883C8(s16 *);
    extern void func_L01_004026A0(void (*)(void *), void *);
    extern void func_L20_003F1DF0(void *);
    extern void func_L20_003F1EC0(void *);
    extern void func_L20_003F13F0(void *);
    extern void func_L20_003F1198(void *);
    S_003F22C0 *s = m->s;
    vu0_v4 old, delta;
    vu0_v4 *position = &m->pos;
    u8 *particle;
    s32 random;
    f32 size;
    s32 i;
    E_003F22C0 *entry;
    random = func_0037E1D8(40);
    size = func_0037E250(500.0f, 1500.0f);
    particle = func_L01_00466F98(position, &D_L20_001D66B0_003F0250, 40, 127, 0x101010, random,
        672000.0f, size, 1.0f, 0.0f, 0.0f);
    if (particle) {
        u8 color = D_L20_002202B4_003F0250[0];
        particle[3] = 0x44;
        particle[2] = color;
    }
    if (s->id == -1 || (entry = (E_003F22C0 *)(D_001A30B0 + (s->id << 7)))->owner != m || !entry->active) {
        s->id = func_0039FE80(0, 4, m);
    }
    switch (m->state) {
    case 0:
        old = m->pos;
        vec_add_ab(&m->pos, &m->pos, &s->vel);
        s->vel.z -= s->gravity;
        if (func_003CE740(&old, &m->pos, 0, m->collision, 0)) {
            m->pos = D_L20_001E9BE0_003F0250;
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 1:
        if (s->id != -1) {
            entry = (E_003F22C0 *)(D_001A30B0 + (s->id << 7));
            if (entry->owner == m && entry->active) func_0039FB08(s->id);
        }
        s->id = -1;
        func_0039FE80(1, 0, m);
        func_L04_00324BA8(&m->pos, 1.0f, 0, 25, 20, 20, 20, 45, 1, 1, 0, 0, 0, 20.0f);
        func_L01_00443648(m, &m->pos, 1, 0, 1, 0, 2.0f, s->radius, 1.0f);
        func_003BD360(m);
        return;
    }
    s->angle0 = func_00389380(s->angle0, 0.029088823f);
    s->angle1 = func_00389380(s->angle1, 0.087266468f);
    switch (m->phase) {
    case 0:
        s->base = D_001A4CB0;
        for (i = 0; i < 12; i++) {
            s->rates[i] = func_0037E250(0.014544412f, 0.043633234f);
            s->scale = 2.0f;
            old.x = func_00388960(m->angle);
            old.y = func_00388978(m->angle);
            old.z = 0.0f;
            vec_sub_ba(&delta, &D_L20_001E2E00_003F0250, &m->pos);
            func_00388830(&delta, &delta, 1.0f);
            func_00388758(&s->vectors[i], &old, &delta);
            func_00388830(&s->vectors[i], &s->vectors[i], s->scale);
            func_00389158(&s->vectors[i], &s->vectors[i], &delta, func_0037E2A8());
        }
        func_L20_003F0878(m);
        s->timer = s->i3C;
        m->phase = 2;
        s->f2C = 2.5f;
        s->h38 = 1;
        s->h3A = 1;
        break;
    case 2:
        if (func_003883C8(&s->timer)) {
            m->phase = 1;
            s->timer = s->h34;
            func_L20_003F0878(m);
        }
        break;
    case 1:
        if (func_003883C8(&s->timer)) {
            if (s->h36) {
                m->phase = 2;
                s->timer = 5;
            } else s->timer = 5;
        } else if (s->hits == 0) {
            func_L20_003F0878(m);
        }
        break;
    }
    func_L01_004026A0(func_L20_003F1DF0, m);
    func_L01_004026A0(func_L20_003F1EC0, m);
    if (s->hits) {
        func_L20_003F1198(m);
        if (s->hits > D_L20_001DF444_003F0250) func_L01_004026A0(func_L20_003F13F0, m);
    }
}
/* localdecomp:end func_L20_003F0250 */
