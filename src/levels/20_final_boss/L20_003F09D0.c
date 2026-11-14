#include "common.h"

/* localdecomp:start func_L20_003F09D0 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x44 - 0x14];
    u16 f44;
} C_003F09D0;
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[3];
    C_003F09D0 *pclass;
    u8 pad28[0x30 - 0x28];
    u8 f30;
    u8 pad31[3];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    s32 *pvar;
    u8 pad6c[0x98 - 0x6C];
    s32 f98;
    u8 pad9c[0x100 - 0x9C];
} M_003F09D0;
typedef struct {
    u8 pad[0x30];
    u8 a[0x40];
    u8 b[0x10];
} R_003F09D0;
extern M_003F09D0 *D_L20_001E029C;
__asm__(".extern D_L20_001E029C, 16");
extern R_003F09D0 *D_L20_001E0380;
__asm__(".extern D_L20_001E0380, 16");
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);

void func_L20_003F09D0(M_003F09D0 *a0) {
    s32 *v = a0->pvar;

    if (a0->state == 0) {
        M_003F09D0 *a;
        M_003F09D0 *b;
        a0->f30 = 0xFF;
        a = &D_L20_001E029C[v[3]];
        a->f98 = 0;
        a->flags = (a->flags | 0x41) & ~0x1000;
        func_L01_004AA7E8(a, 1);
        a->flags |= 2;
        b = &D_L20_001E029C[v[4]];
        b->f98 = 0;
        b->flags = (b->flags | 0x41) & ~0x1000;
        func_L01_004AA7E8(b, 1);
        b->flags |= 2;
        a0->state = 1;
    }
    if (a0->state == 1) {
        M_003F09D0 *m = &D_L20_001E029C[v[0]];
        if (m == 0 || m->state == 0xFE || m->state == 0xFD) {
            M_003F09D0 *a;
            M_003F09D0 *b;
            R_003F09D0 *c;
            func_L01_00456230(&D_L20_001E029C[v[1]], 1);
            c = &D_L20_001E0380[v[2]];
            func_L01_004F50C8(c->a, c->b, 0, 1);
            a = &D_L20_001E029C[v[3]];
            a->flags &= ~0x41;
            a->flags |= a->pclass->f44 & 0x1000;
            a->f98 = a->pclass->f10;
            a->flags &= ~2;
            b = &D_L20_001E029C[v[4]];
            b->flags &= ~0x41;
            b->flags |= b->pclass->f44 & 0x1000;
            b->f98 = b->pclass->f10;
            b->flags &= ~2;
            a0->state = 2;
        }
    }
}
/* localdecomp:end func_L20_003F09D0 */
