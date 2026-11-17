#include "common.h"

/* localdecomp:start func_L24_0035A580 */
#include "vu0.h"

typedef int u128_35A580 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35A580;
typedef struct {
    u8 pad0[0x44];
    u8 f44;
    u8 pad45[0x160 - 0x45];
    V4_35A580 v160;
    V4_35A580 v170;
    u8 pad180[0x196 - 0x180];
    s16 f196;
    u8 pad198[0x1AC - 0x198];
    f32 f1AC;
    u8 pad1B0[0x10];
    u8 f1C0[0x10];
} S_35A580;
typedef struct {
    u8 pad0[0x10];
    V4_35A580 pos;
    u8 state;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    S_35A580 *vars;
    u8 pad6C[0xC0 - 0x6C];
    V4_35A580 vC0;
    V4_35A580 vD0;
    V4_35A580 vE0;
} O_35A580;

extern void func_L24_0035A550(void *, f32);
extern s32 func_L24_003A4E60(void *, void *, void *, f32);
extern void func_L24_003A5360(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_00446780(void *, void *, s32, s32, f32, f32, f32, s32, s32);
extern s32 func_L01_00446720(void *);
extern f32 D_L24_001DD5C0, D_L24_001DD5C4, D_L24_001DD5C8, D_L24_001DD5CC, D_L24_001DD5D0;
__asm__(".extern D_L24_001DD5C0, 4");
__asm__(".extern D_L24_001DD5C4, 4");
__asm__(".extern D_L24_001DD5C8, 4");
__asm__(".extern D_L24_001DD5CC, 4");
__asm__(".extern D_L24_001DD5D0, 4");
extern s32 D_L24_001DD64C;
__asm__(".extern D_L24_001DD64C, 4");
extern u8 *D_L24_0021F034[];
extern void *D_L24_001ECFC0[];

s32 func_L24_0035A580(O_35A580 *self) {
    S_35A580 *s;
    V4_35A580 q;
    V4_35A580 v;
    V4_35A580 w;
    V4_35A580 t;
    s32 ret;
    f32 ang;
    f32 f;
    s32 cnt;
    s32 i;
    u8 *rr;

    s = self->vars;
    ret = 1;
    func_L24_0035A550(self, -s->v170.z);
    vec_sub_ab(&self->pos, &self->pos, &s->v170);
    if ((u32)(self->state - 9) < 2) {
        q = self->pos;
        if (func_L24_003A4E60(s->f1C0, self, &s->v160, -1e13f) & 0xA) {
            ret = 0;
        }
        ang = func_0038CF38(&q, &self->pos) * D_L24_001DD5D0;
        if (s->f196 >= 9) {
            v = self->pos;
            func_003C4C18(&v, 0.2f);
            *(u128_35A580 *)&t = 0;
            t.z = func_003824E0(0.25f, 1.0f) * 0.020000001f;
            w = t;
            f = func_003824E0(0.3f, 1.0f) * 210000.0f;
            rr = func_L01_0046FB40(&v, &w, (func_00382498(0x23, 0x3C) * 5 + 2) / 6, 0x128090A0, func_00382468(2) == 0 ? -1 : 1, 8, 0, f, f, 0, 0.0f);
            if (rr != 0) {
                rr[2] = D_L24_0021F034[0][0];
                rr[3] = 0x44;
            }
        }
    } else {
        func_L24_003A5360(s->f1C0, self);
        ang = s->f1AC;
    }
    self->f34 |= 0x100;
    func_003C4840(&q, &self->vD0, ang);
    func_0038D850(&self->vC0, &self->vC0, &q);
    func_0038D850(&self->vE0, &self->vE0, &q);
    *(u128_35A580 *)&w = 0;
    w.x = D_L24_001DD5C0;
    w.z = D_L24_001DD5C4;
    w.w = 1.0f;
    v = w;
    func_0038D000(&s->v170, &v, &self->vC0);
    s->v170.z += D_L24_001DD5C8;
    func_L24_0035A550(self, s->v170.z);
    w = self->pos;
    vec_add_ab(&self->pos, &self->pos, &s->v170);
    if (self->state != 9) {
        return ret;
    }
    w.z += D_L24_001DD5C8;
    cnt = func_L01_00446780(self, &w, 0x8010001, 0, D_L24_001DD5CC, (f32)s->f44, 1.0f, 1, 0);
    if (s->f196 < (D_L24_001DD64C * 5 + 2) / 6 - ((D_L24_001DD64C >> 2) * 5 + 2) / 6) {
        for (i = 0; i < cnt; i++) {
            if (func_L01_00446720(D_L24_001ECFC0[i]) == 0) {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L24_0035A580 */
