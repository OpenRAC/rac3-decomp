#include "common.h"

/* NTSC-U counterpart of func_L01_003CAA80 (src/levels/shared/L01_003C8DE8.c) */
/* localdecomp:start func_L01_003C91E8 */
typedef struct M_3C91E8 M_3C91E8;
typedef struct {
    u8 pad0[0x36];
    s16 h36;
    u8 pad38[0x94 - 0x38];
    u8 b94;
    u8 pad95[0x550 - 0x95];
    M_3C91E8 *child;
} V_3C91E8;
struct M_3C91E8 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[6];
    unsigned long q38;
    u8 pad40[0x68 - 0x40];
    V_3C91E8 *p68;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0xA8 - 0x70];
    u8 bA8;
    u8 padA9[0xB8 - 0xA9];
    M_3C91E8 *pB8;
};
extern u8 D_L01_001E2AC0[];
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L01_0044CB08(void *, void *, s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L01_003C91E8(M_3C91E8 *o) {
    V_3C91E8 *v;
    V_3C91E8 *own;

    if (o->b20 != 0) {
        M_3C91E8 *l = o->pB8->pB8;
        own = 0;
        v = o->p68;
        if (l != 0) {
            own = l->p68;
        }
        if (own == 0 || own->b94 == 0) {
            if (func_L01_0044FCD0(o, (u8 *)v + 0xD0, 0, 1, 0) != 0) {
                v->h36 = 0x5A;
            }
        } else {
            o->bA8 = 0xFF;
        }
        if (v->child != 0) {
            v->child->q38 = o->q38;
            func_L01_0044CB08(o, v->child, 0, 0);
            if (v->child->b31 != 0) {
                if (func_L01_0040C018(D_L01_001E2AC0, v->child->pos) < 576.0f) {
                    func_L01_00444188(v->child);
                    v->child->b6F = 0x16;
                }
            }
        }
        if (o->b31 != 0) {
            if (func_L01_0040C018(D_L01_001E2AC0, o->pos) < 576.0f) {
                func_L01_00444188(o);
                o->b6F = 0x16;
            }
        }
        func_L01_0044B5C8(o, (u8 *)v + 0x4D0, 0, 0.03f, 0.3f);
    }
}
/* localdecomp:end func_L01_003C91E8 */
