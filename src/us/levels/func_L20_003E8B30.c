#include "common.h"

/* NTSC-U counterpart of func_L20_003EAA70 (src/levels/20_final_boss/L20_003E6150.c) */
#include "vu0.h"
#include "vu0.h"
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
#include "vu0.h"
#include "vu0.h"
extern u8 *func_0037E0B8(s32);

/* localdecomp:start func_L20_003E8B30 */
typedef struct M_003EAA70 {
    u8 pad0[0x10];
    vu0_q pos;                      /* 0x10 */
    s8 state;                       /* 0x20 */
    u8 pad21[0x2C - 0x21];
    f32 scale;                      /* 0x2C */
    u8 b30;                         /* 0x30 */
    u8 b31;                         /* 0x31 */
    u16 h32;                        /* 0x32 */
    u8 pad34[0x38 - 0x34];
    unsigned long d38;              /* 0x38 */
    u8 pad40[0x68 - 0x40];
    void *pvar;                     /* 0x68 */
    u8 pad6C[0xB8 - 0x6C];
    struct M_003EAA70 *parent;      /* 0xB8 */
    u8 padBC[0xF8 - 0xBC];
    f32 rotz;                       /* 0xF8 */
} M_003EAA70;

typedef struct {
    vu0_q pos;                      /* 0x00 */
    u8 pad10[0x18 - 0x10];
    s32 i18;                        /* 0x18 */
    f32 f1C;                        /* 0x1C */
    u8 pad20[0x30 - 0x20];
    vu0_q dir;                      /* 0x30 */
} V_003EAA70;

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_00388A28(f32, f32);
extern u8 *func_0037E0B8(s32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_00443648(void *, void *, f32, s32, f32, f32, s32, s32, s32);

M_003EAA70 *func_L20_003E8B30(M_003EAA70 *parent, f32 *dir, vu0_q *pos) {
    M_003EAA70 *m = (M_003EAA70 *)func_003BCFB0(0x1D26, 0x40);

    if (m != 0) {
        V_003EAA70 *v;
        u8 *r;
        f32 scale;

        m->b30 = parent->b30;
        m->parent = parent;
        m->h32 = parent->h32;
        m->b31 = 1;
        m->state = 0;
        v = m->pvar;
        m->d38 = parent->d38;
        scale = 2.0f;
        m->scale = m->scale * 0.5f;
        m->pos = *pos;
        v->dir = *(vu0_q *)dir;
        m->rotz = func_00388A28(dir[0], dir[1]);
        v->pos = m->pos;
        m->state = 3;
        v->i18 = 0x14;
        if (m->parent != 0) {
            r = func_0037E0B8((s32)m->parent);
            if (r != 0) {
                scale = r[0x16];
            }
        }
        func_L01_004A72A8(0x12, 0, m, 0x1AFD);
        func_L01_00443648(m, &m->pos, 2.0f, 1, scale, 1.0f, 0, 1, 0);
        v->f1C = 2.0f;
    }
    return m;
}
/* localdecomp:end func_L20_003E8B30 */
