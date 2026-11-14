/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_0054C0E8, the NTSC-U twin of func_L39_0054CA00, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 9 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_0054CA00 (src/levels/shared/L39_0054C7E8.c) */
/* localdecomp:start func_L39_0054C0E8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054C0E8;
typedef struct {
    u8 p0[0x10];
    s32 f10;
    u8 p14[0x46 - 0x14];
    u8 b46;
} I_0054C0E8;
struct S_0054C0E8;
typedef struct O_0054C0E8 {
    u8 p0[0x10];
    V4_0054C0E8 pos;
    u8 mode;
    u8 p21[3];
    I_0054C0E8 *p24;
    u8 p28[0x34 - 0x28];
    u16 s34;
    u8 p36[0x68 - 0x36];
    struct S_0054C0E8 *p68;
    u8 p6C[0x98 - 0x6C];
    s32 f98;
    u8 p9C[0xF0 - 0x9C];
    f32 fF0;
    f32 fF4;
} O_0054C0E8;
typedef struct {
    u8 p0[0x2544];
    s32 f2544;
    s32 f2548;
} P_0054C0E8;
typedef struct S_0054C0E8 {
    V4_0054C0E8 v0;
    f32 f10;
    f32 f14;
    u8 p18[8];
    V4_0054C0E8 v20;
    V4_0054C0E8 v30;
    u8 p40[4];
    s32 f44;
    s32 f48;
    O_0054C0E8 *p4C;
    P_0054C0E8 *p50;
} S_0054C0E8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} H_0054C0E8;
typedef struct {
    V4_0054C0E8 a;
    V4_0054C0E8 b;
    V4_0054C0E8 c;
    O_0054C0E8 *obj;
    H_0054C0E8 *hit;
    s32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
} Q_0054C0E8;

extern f32 D_L39_0024B128;
__asm__(".extern D_L39_0024B128, 16");
extern f32 D_001DF900_sda;
__asm__(".extern D_001DF900_sda, 4");
extern f32 D_001DF904_sda;
__asm__(".extern D_001DF904_sda, 4");
extern V4_0054C0E8 D_L39_0025F860[];
extern P_0054C0E8 *D_L39_0024CF20[];
extern void func_L39_005BA378(void *, void *, s32);
extern void func_L19_003AFE00(s32, void *, s32);
extern void func_L39_005FC9F8(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L39_005FCAD0(void *, s32);
extern u8 *func_0037E0B8(void *);
extern u8 *func_L39_0061B038(void *);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_005FD6D8(void);
extern void func_L39_005F0CE0(s32, s32, void *);
extern s32 func_L39_0051E580(void *, void *, s32, void *, void *);
extern s32 func_L39_00576AD8(void);
extern s32 *func_L39_0066BA18(s32);
extern void func_L01_004C4AB8(s32);
extern void func_003BD360(void *);
extern f32 func_00389380(f32, f32);
extern void func_L01_00444070(void *, f32);

void func_L39_0054C0E8(O_0054C0E8 *obj) {
    S_0054C0E8 *state = obj->p68;
    V4_0054C0E8 oldpos;
    H_0054C0E8 hit;
    V4_0054C0E8 t20;
    Q_0054C0E8 pr;
    V4_0054C0E8 v90;
    V4_0054C0E8 vA0;
    V4_0054C0E8 vB0;
    f32 *dir;
    u8 *x;
    u8 *w;
    u8 *e;
    P_0054C0E8 *pl;
    s32 flag;
    s32 r;
    s32 r2;
    s32 r3;
    s32 t;
    s32 id;
    O_0054C0E8 *ho;

    switch (obj->mode) {
    case 0:
        obj->mode = 1;
    case 1:
        oldpos = obj->pos;
        func_L39_005BA378(&oldpos, &t20, 1);
        vec_add_ba(&obj->pos, &obj->pos, &state->v0);
        func_L19_003AFE00(state->f44, state, 0);
        flag = 0;
        func_L39_005FC9F8(state->p50, &obj->pos, &state->v30);
        func_003886E8(&state->v30, &state->v30, -(D_L39_0024B128 * 0.00027777778f));
        vec_add_ab(&state->v0, &state->v0, &state->v30);
        hit.f0 = 0;
        hit.f4 = 0x108A;
        pr.a = oldpos;
        pr.b = obj->pos;
        pr.c = state->v0;
        pr.f40 = D_001DF900_sda;
        pr.f44 = D_001DF904_sda;
        pr.obj = obj;
        pr.hit = &hit;
        pr.f38 = 2;
        pr.f3C = 0.25f;
        pr.f48 = 0;
        pr.f4C = 0;
        pr.f58 = 0;
        if (state->p4C->f98 != 0) {
            state->p4C->f98 = 0;
            flag = 1;
        }
        r = func_L39_005FCAD0(&pr, state->p50->f2544);
        if (flag != 0) {
            state->p4C->f98 = state->p4C->p24->f10;
        }
        if (pr.obj != 0 && pr.obj == state->p4C) {
            pr.a = oldpos;
            pr.b = obj->pos;
            pr.c = state->v0;
            pr.hit = &hit;
            pr.f38 = 2;
            pr.f3C = 0.25f;
            pr.f40 = D_001DF900_sda;
            pr.f44 = D_001DF904_sda;
            pr.obj = 0;
            pr.f48 = 0;
            pr.f4C = 0;
            pr.f58 = 0;
        } else if (r == 2) {
            obj->mode = 2;
        }
        obj->pos = pr.b;
        state->v0 = pr.c;
        state->v20 = pr.a;
        if (pr.obj != 0 && pr.obj != state->p4C) {
            t = pr.obj->p24->b46;
            if (t == 5 || t == 9 || (pr.obj->s34 & 0x4000)) {
                e = func_0037E0B8(pr.obj);
                w = func_L39_0061B038(pr.obj);
                x = 0;
                if (w != 0) {
                    if ((w[3] & 0xF) == 0) {
                        x = w;
                    }
                }
                if (x != 0) {
                    func_L39_005FC9F8(x, (u8 *)pr.obj + 0x10, &vA0);
                    dir = &vA0.x;
                } else {
                    func_00388830(&vA0, &state->v30, -1.0f);
                    dir = &vA0.x;
                }
                v90 = obj->pos;
                if (e != 0) {
                    func_003886E8(&vB0, dir, *(f32 *)(e + 0x10));
                    vec_add_ab(&v90, &v90, &vB0);
                }
                func_003886E8(dir, dir, -3.0f);
                obj->mode = 2;
                vec_add_ab(&vA0, &vA0, &v90);
                obj->pos = D_L39_0025F860[0];
                state->v20 = D_L39_0025F860[2];
                func_00388830(&state->v20, &state->v20, 1.0f);
                ho = pr.obj;
                { P_0054C0E8 *q = state->p50; id = q->f2544; }
                pl = D_L39_0024CF20[id];
                id = -1;
                if (pl != 0) {
                    id = pl->f2548;
                }
                func_L39_005FD658(id);
                r2 = func_003CE740(&v90, dir, 6, ho, 0);
                func_L39_005FD6D8();
                if (r2 != 0) {
                    obj->pos = D_L39_0025F860[0];
                    state->v20 = D_L39_0025F860[2];
                    func_00388830(&state->v20, &state->v20, 1.0f);
                }
            }
        }
        break;
    case 2:
        func_L39_005F0CE0(0, 0, obj);
        r3 = func_L39_0051E580(&obj->pos, &state->v20, state->f48, state->p50, &state->v30);
        if (r3 != 0) {
            if (func_L39_00576AD8() != 0) {
                s32 *q = func_L39_0066BA18(state->f48);
                if (q != 0) {
                    q[0x28 / 4] = r3;
                }
            }
        }
        func_L01_004C4AB8(state->f44);
        func_003BD360(obj);
        return;
    }
    obj->fF0 = func_00389380(obj->fF0, state->f10);
    obj->fF4 = func_00389380(obj->fF4, state->f14);
    func_L01_00444070(obj, 0.2f);
    if (obj->pos.x < 2.0f || 1021.0f < obj->pos.x || obj->pos.y < 2.0f || 1021.0f < obj->pos.y ||
        obj->pos.z < 2.0f || 1021.0f < obj->pos.z) {
        func_L01_004C4AB8(state->f44);
        func_003BD360(obj);
    }
}
/* localdecomp:end func_L39_0054C0E8 */
