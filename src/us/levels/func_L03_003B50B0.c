#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L03_003B50B0 */
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x34];
    u8 *p68;
    u8 pad6C[0x24];
    u16 h90pad;
    u8 pad92[4];
    s16 h96;
    u8 pad98[0x20];
    u8 *pB8;
} O_3B50B0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 v10;
    f32 f20;
    s32 w24;
    u8 *p28;
    u8 pad2C[4];
    u8 *p30;
    s32 w34;
    f32 f38;
    f32 f3C;
    u8 pad40[4];
    f32 f44;
    s32 w48;
} S_3B50B0;
extern f32 D_001DEAA8_sda;
__asm__(".extern D_001DEAA8_sda, 4");
extern f32 D_001DEAA4_sda;
__asm__(".extern D_001DEAA4_sda, 4");
extern s32 D_001DEA78_sda;
__asm__(".extern D_001DEA78_sda, 4");
extern u8 D_L03_001E1E68;
extern u8 *func_003BCFB0(s32, s32);
extern void func_003BDA38(void *, void *, void *);
extern void func_L03_0034A658(f32, void *, s32, s32, s32, void *);
extern void func_L03_003B5580(void);

O_3B50B0 *func_L03_003B50B0(u8 *parent, u8 *pos, f32 f) {
    O_3B50B0 *o = (O_3B50B0 *)func_003BCFB0(0x1C06, 0x80);
    S_3B50B0 *st;
    u8 **ps;
    if (o != 0) {
        o->b30 = 0xFF;
        o->b31 = 1;
        o->b20 = 5;
        o->h32 = 0x40;
        st = (S_3B50B0 *)o->p68;
        o->pB8 = parent;
        o->h96 = 0;
        st->f20 = f * 0.016666668f;
        st->f38 = D_001DEAA8_sda;
        st->f3C = D_001DEAA4_sda;
        st->w24 = 0;
        st->p30 = pos;
        st->w34 = 0;
        st->w48 = 0;
        ps = *(u8 ***)(parent + 0x68);
        func_003BDA38(*ps, pos, &st->v10);
        func_003BDA38(*ps, pos + 0x20, st);
        st->f44 = *(f32 *)(*ps + 0xF0);
        st->p28 = *ps;
        *(vu0_v4 *)((u8 *)o + 0x10) = st->v10;
    }
    if (D_001DEA78_sda == 0) {
        D_001DEA78_sda = 1;
        func_L03_0034A658(2.1f, &D_L03_001E1E68, 0x1E, 0x14, 0, func_L03_003B5580);
    }
    return o;
}
/* localdecomp:end func_L03_003B50B0 */
