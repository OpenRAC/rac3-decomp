#include "common.h"

typedef struct Ent_003BAFA0 {
    u8 pad0[0x24];
    f32 f24;
    u8 pad28[8];
    s32 type;
    u8 pad34[0xC];
} Ent_003BAFA0;
typedef struct Set_003BAFA0 {
    Ent_003BAFA0 e[64];
    s32 count;
    s32 id;
} Set_003BAFA0;
typedef struct Obj_003BAFA0 {
    u8 pad0[0x10];
    u8 v10[0x10];
    u8 pad20[0x8A];
    s16 id;
    u8 pad_AC[0x14];
    u8 vC0[0x10];
} Obj_003BAFA0;

/* localdecomp:start func_L02_003BA9F8 */
#include "vu0.h"
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L02_003BA9F8(void *a, void *b, void *p, void *q) {
    f32 d;

    if (func_0038CEA8(b) <= 0.0f) {
        *(vu0_q *)p = *(vu0_q *)a;
        qzero(q);
    } else {
        d = func_0038CE68(b, a);
        func_0038CE20(p, b, d / func_0038CE68(b, b));
        vec_sub_ab(q, a, p);
    }
}
/* localdecomp:end func_L02_003BA9F8 */

INCLUDE_ASM("asm/levels", func_L02_003BAAB0);

/* localdecomp:start func_L02_003BAFA0 */
#include "vu0.h"


extern f32 func_003824E0(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L02_003BB140(void *, void *, f32, void *);
extern void func_L02_003BB1D0(void *, void *, f32, void *);
extern void func_L02_003BB2D8(void *, void *, f32, void *);

void func_L02_003BAFA0(Obj_003BAFA0 *p, f32 dt, Set_003BAFA0 *s, void *out, void *arg) {
    Ent_003BAFA0 *e;
    f32 r;
    s32 i;
    s32 found;

    found = 0;
    if (p != 0 && p->id == s->id && s->count != 0) {
        r = func_003824E0(0.0f, 1.0f);
        for (i = 0; i < s->count && !found; i++) {
            e = &s->e[i];
            if (r <= e->f24) {
                found = 1;
                if (e->type == 1) func_L02_003BB140(e, out, dt, arg);
                if (e->type == 2) func_L02_003BB1D0(e, out, dt, arg);
                if (e->type == 3) func_L02_003BB2D8(e, out, dt, arg);
            } else {
                r -= e->f24;
            }
        }
        if (found) {
            func_0038D000(out, out, p->vC0);
            vec_add_ba(out, out, p->v10);
            return;
        }
    }
    qzero(out);
}
/* localdecomp:end func_L02_003BAFA0 */

/* localdecomp:start func_L02_003BB140 */
extern void func_00382580(void *, f32, f32);
extern f32 func_0038CEA8(void *);

void func_L02_003BB140(void *pa, void *pb, f32 scale, void *pout) {
    u8 *a = pa;
    u8 *b = pb;
    f32 *out = pout;

    func_00382580(b, scale * *(f32 *)(a + 0x28), *(f32 *)(a + 0x28));
    if (out != 0 && *(f32 *)(a + 0x28) > 0.0f) {
        *out = func_0038CEA8(b) / *(f32 *)(a + 0x28);
    }
    vec_add_ba(b, b, a);
}
/* localdecomp:end func_L02_003BB140 */

/* localdecomp:start func_L02_003BB1D0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x28];
    f32 f28;
} S_003BB1D0;
extern void func_00382580(void *, f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L02_003BA9F8_003BB1D0(void *, void *, void *, void *);

void func_L02_003BB1D0(void *e, void *out, f32 scale, void *res) {
    S_003BB1D0 *a = e;
    vu0_v4 d[3];

    vec_sub_ab(&d[0], (u8 *)a + 0x10, a);
    func_00382580(out, scale * a->f28, a->f28);
    if (res != 0) {
        if (0.0f < a->f28) {
            *(f32 *)res = func_0038CEA8(out) / a->f28;
        }
    }
    func_L02_003BA9F8_003BB1D0(out, &d[0], &d[1], &d[2]);
    if (0.0f < func_0038CE68(&d[0], &d[1])) {
        vec_sub_ab(out, &d[2], &d[1]);
    } else {
        vec_add_ab(out, &d[2], &d[1]);
    }
    vec_add_ba(out, out, a);
}
/* localdecomp:end func_L02_003BB1D0 */

/* localdecomp:start func_L02_003BB2D8 */
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[8];
    f32 f28;
    f32 f2C;
} E_003BB2D8;

extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);

void func_L02_003BB2D8(void *pe, void *out, f32 dt, void *parg) {
    E_003BB2D8 *e = pe;
    f32 *arg = parg;
    vu0_v4 dir;
    vu0_v4 side;
    vu0_v4 up;
    vu0_v4 ofs;
    vu0_v4 p0;
    vu0_v4 p1;
    f32 t;
    f32 len;
    f32 r;
    f32 ang;

    t = func_003824E0(0.0f, 1.0f);
    len = func_003C4088(e->f28, e->f2C, t);
    r = func_003824E0(dt * len, len);
    if (arg != 0 && len != 0.0f) {
        *arg = r / len;
    }
    ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    p0 = e->v0;
    p1 = e->v10;
    func_003C4098(out, &p0, &p1, t);
    vec_sub_ba(&dir, &e->v10, &e->v0);
    side.x = -dir.y - dir.z;
    side.y = dir.x;
    side.z = dir.x;
    side.w = 1.0f;
    func_0038CE90(&up, &side, &dir);
    ofs.x = func_0038D098(ang) * r;
    ofs.y = func_0038D0B0(ang) * r;
    ofs.z = 0.0f;
    func_0038CF68(&side, &side, ofs.x);
    func_0038CF68(&up, &up, ofs.y);
    vec_add_ba(&ofs, &side, &up);
    vec_add_ab(out, out, &ofs);
}
/* localdecomp:end func_L02_003BB2D8 */
