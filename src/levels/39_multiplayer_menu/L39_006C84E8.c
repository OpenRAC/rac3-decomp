#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C84E8 */
typedef struct O_006C84E8 O_006C84E8;
typedef struct {
    u8 pad[0x78];
    s32 (*f78)(O_006C84E8 *);
    u8 pad7C[0x8C - 0x7C];
    s32 (*f8C)(O_006C84E8 *);
    u8 pad90[0x9C - 0x90];
    s32 (*f9C)(O_006C84E8 *, f32 *, f32 *);
    s32 (*fA0)(O_006C84E8 *, f32 *, f32 *);
} Vt_006C84E8;
struct O_006C84E8 { u8 pad[0x60]; Vt_006C84E8 *vt; };
typedef struct {
    u8 pad[0x110];
    O_006C84E8 *objs[0x60];
    s32 unk290;
    u8 pad294[0x2A8 - 0x294];
    s32 unk2A8;
    u8 pad2AC[0x2B8 - 0x2AC];
    s32 unk2B8[0x3C];
    s32 unk3A8;
} S_006C84E8;
__asm__(".extern D_L39_00247914, 16");
extern u8 *D_L39_00247914;
__asm__(".extern D_L39_00249874, 16");
extern f32 D_L39_00249874;
void func_L39_006C89D8(S_006C84E8 *);
void func_L39_006C87E8(S_006C84E8 *);
s32 func_L39_0068AEF8(S_006C84E8 *, s32);
void func_L39_00688340(s32, s32, s32);
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

s32 func_L39_006C84E8(S_006C84E8 *self, s32 arg1) {
    f32 x, y, w, h;
    s32 cur;
    s32 n;
    s32 m;
    s32 s;
    s32 last;
    s32 t;
    O_006C84E8 *o;

    if ((u32)(self->unk3A8 - 2) < 2) {
        func_L39_006C89D8(self);
    } else {
        func_L39_006C87E8(self);
    }
    if (func_L39_0068AEF8(self, arg1) == 1) {
        return 1;
    }
    if (arg1 == 7) {
        if (self->unk290 == 1) {
            o = self->objs[1];
            m = o->vt->f8C(o);
            if (m >= 0) {
                t = self->unk2B8[m];
                if (self->unk3A8 == 0 || self->unk3A8 == 3 || self->unk3A8 == 2) *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
                else *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
                self->unk2A8 = t;
                func_L39_00688340(4, 0, 0);
            }
            return 1;
        }
    } else if (arg1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        *(s32 *)(D_L39_00247914 + 0x284) = 0x2C;
        return 1;
    } else {
        cur = self->unk290;
        if (cur == 1) {
            o = self->objs[1];
            o->vt->f9C(o, &x, &y);
            o = self->objs[self->unk290];
            o->vt->fA0(o, &w, &h);
            if (x == 0.0f || y == 0.0f) {
                return 0;
            }
            y = y + 0.003f;
            func_L39_00689F00(self, 0, 3, 3, x + 0.0f, y, D_L39_00249874, h * 0.65f, 0.04f, 1.0f);
            s = 3;
            n = self->objs[self->unk290]->vt->f8C(self->objs[self->unk290]);
            last = self->objs[self->unk290]->vt->f78(self->objs[self->unk290]) - 1;
            if (n == 0) {
                s = 2;
                if (last == 0) {
                    s = 0;
                }
            } else if (n == self->objs[self->unk290]->vt->f78(self->objs[self->unk290]) - 1) {
                s = 1;
            }
            func_L39_0068A2D0(self, s, 3, 3, x, y);
            goto end;
        }
    }
    func_L39_0068A2D0(self, 0, 3, 3, 2.0f, 2.0f);
end:
    return 0;
}
/* localdecomp:end func_L39_006C84E8 */
