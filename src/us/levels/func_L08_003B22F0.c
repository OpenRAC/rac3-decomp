#include "common.h"

/* NTSC-U counterpart of func_L08_003B4200 (src/levels/08_aquatos/L08_003B4200.c) */
/* localdecomp:start func_L08_003B22F0 */
#include "vu0.h"

typedef struct {
    f32 f0;
    f32 f4;
    long d8;
    f32 f10;
    f32 f14;
    s32 i18;
} P_003B4200;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[0x38 - 0x21];
    long d38;
    u8 pad40[0x68 - 0x40];
    P_003B4200 *p68;
    u8 pad6C[0xA8 - 0x6C];
    u8 bA8;
    u8 padA9[0xBC - 0xA9];
    u8 bBC;
} M_003B4200;

extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 D_L08_001E8A98_003B22F0 __attribute__((section(".data")));
extern f32 D_L08_001DE610 __attribute__((section(".sdata")));
extern f32 D_L08_001DE614 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE610, 4");
__asm__(".extern D_L08_001DE614, 4");
extern f32 func_0037E2A8(void);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_003887C8(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00438908(void *, s32, s32, s32);
extern s32 func_L01_0032FE90_003B22F0(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);

void func_L08_003B22F0(void *arg) {
    M_003B4200 *m = arg;
    P_003B4200 *p = m->p68;

    switch (m->b20) {
    case 0:
        p->f10 = func_0037E2A8();
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1: {
        s32 idx = p->i18;
        u8 *e;
        if (idx == -1 || (e = D_001A30B0 + (idx << 7), *(void **)(e + 0xDC) != m) || e[0xD0] == 0) {
            p->i18 = func_0039FE80(2, 4, m);
        }
        if (func_003887C8(&m->pos, D_001A4C60) <= p->f4) {
            func_L01_00441FB8(m, 2, -1);
        }
        break;
    }
    case 2: {
        vu0_v4 v __attribute__((aligned(16)));
        s32 flag;
        vec_sub_ba(&v, D_001A4BE0 + 0xD0, &m->pos);
        func_00388830(&v, &v, p->f0 * 0.01666666753590107f);
        vec_add_ba(&m->pos, &v, &m->pos);
        flag = 0;
        if (func_L01_003F9498(&m->pos, 1, (u8 *)m, 1.5f) != 0 && D_L08_001E8A98_003B22F0 == *(s32 *)(D_001A4BE0 + 0x25C0)) {
            flag = 1;
        }
        if (m->bBC == 0) {
            m->bBC = 0xB3;
            p->d8 = m->d38;
            *(s32 *)&p->d8 = *(s32 *)&m->d38;
        } else if (m->bBC > 0xF && flag) {
            f32 r = 5.0f;
            m->bBC = (s32)func_0037E250(r, 15.0f);
        }
        if (m->bBC % 60 == 0x39 || m->bBC == 0xD) {
            func_0039FE80(0, 0x20, m);
        }
        if (m->bBC % 60 >= 0x29 || m->bBC < 0xF) {
            func_L01_00438908(m, 0xC8, 0x40, 0x40);
        } else {
            m->d38 = p->d8;
        }
        if (m->bBC == 1) {
            m->d38 = p->d8;
            func_L01_00441FB8(m, 3, -1);
        }
        m->bA8 = 0xFF;
        m->bBC--;
        break;
    }
    case 3:
        func_0039FE80(1, 0x20, m);
        func_L01_0032FE90_003B22F0((u8 *)&m->pos, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 2, 1.0f, 0.0f, 4.0f, 2.0f,
            0, 1, 0, 0, 0, 1, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
            0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(m);
        return;
    }
    func_L01_0044B860(m, &p->f10, &p->f14, D_L08_001DE610, D_L08_001DE614 * 0.017453292f * 0.01666666753590107f, -1.0f);
}
/* localdecomp:end func_L08_003B22F0 */
