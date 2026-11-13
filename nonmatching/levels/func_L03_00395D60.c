/* near miss (level 3, Starship Phoenix): 15 differences, prologue only (measured with a config/levels/divs_nops.txt row `func_L03_00395D60 2`, which a match needs: two nops before its div.s): retail saves $f22 in register order and sets `mov.s $f13,$f20` before `move $s6,$zero`, this C saves $f22 first and sets i first; everything else matches, including the spilled pointer at 0x120($sp). Found: one vu0_v4 seg[4] for the current and previous strip ends (copied with `for (k = 2; k < 4; k++) seg[k] = seg[k - 2]`), sine and cosine called before the quadword zero, x80/x88 stored before the corner copies, and four ab/ba choices of the vector helpers (out of eleven, by search). Declaration orders, an early `int i = 0` and a local copy of the angle parameter do not move the prologue */
#include "common.h"

/* localdecomp:start func_L03_00395D60 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_00395D60;
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x40 - 0x24]; s32 i40; f32 f44; } S_00395D60;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00395D60 *p68; u8 pad6C[0xC0 - 0x6C]; u8 mtx[0x40]; } A_00395D60;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_L03_001E2840[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);

void func_L03_00395D60(void *arg, f32 ang) {
    A_00395D60 *a = arg;
    S_00395D60 *s = a->p68;
    u8 *e = D_L03_001DF99C + (s->i20 << 8);
    if (e != 0) {
        vu0_v4 seg[4];
        vu0_v4 d;
        vu0_v4 p;
        vu0_v4 w;
        vu0_v4 x;
        vu0_v4 y;
        Q_00395D60 q;
        f32 step = 1.0f / (f32)s->i40;
        f32 t = 0.0f;
        f32 r1 = func_003824E0(0.0f, 1.0f);
        f32 r2 = func_003824E0(0.0f, 1.0f);
        int i;
        vec_sub_ab(&d, e + 0x10, &a->pos);
        for (i = 0; i <= s->i40; i++) {
            int k;
            if (t == 0.0f) {
                p = a->pos;
            } else if (t == 1.0f) {
                p = *(vu0_v4 *)(e + 0x10);
            } else {
                func_0038CE20(&p, &d, t);
                vec_add_ba(&p, &a->pos, &p);
            }
            {
                f32 sy = func_0038D098(ang);
                f32 cz = func_0038D0B0(ang);
                *(vu0_q *)&w = 0;
                w.y = sy * 0.3f;
                w.z = cz * 0.3f;
            }
            func_0038D000(&w, &w, a->mtx);
            func_0038CE90(&x, &d, D_L03_001E2840);
            func_0038CF68(&x, &x, 0.1f);
            vec_add_ab(&p, &p, &w);
            vec_add_ba(&seg[0], &p, &x);
            vec_sub_ab(&seg[1], &p, &x);
            func_0038CF68(&y, &x, func_003824E0(-0.1f, 0.1f));
            vec_add_ba(&seg[0], &seg[0], &y);
            vec_add_ab(&seg[1], &seg[1], &y);
            if (i != 0) {
                f32 u;
                q.x78 = func_00389598(0x17);
                q.x80 = 0xFF9000000260L;
                q.x88 = 0x8000000048L;
                q.v[0] = seg[2];
                q.v[1] = seg[3];
                q.v[2] = seg[0];
                q.v[3] = seg[1];
                q.x70 = 0;
                q.color[3] = 0x7FFFFFFF;
                q.color[2] = 0x7FFFFFFF;
                q.color[1] = 0x7FFFFFFF;
                q.color[0] = 0x7FFFFFFF;
                q.uv[0][0] = r1;
                q.uv[1][0] = r1;
                q.uv[0][1] = 0.0f;
                q.uv[1][1] = 1.0f;
                q.uv[2][0] = r1 + 1.0f;
                q.uv[3][0] = r1 + 1.0f;
                q.uv[2][1] = 0.0f;
                q.uv[3][1] = 1.0f;
                func_003D2DA0(&q, 0, 0);
                func_0038CE20(&x, &x, 4.0f);
                vec_add_ba(&q.v[0], &q.v[0], &x);
                vec_sub_ba(&q.v[1], &q.v[1], &x);
                vec_add_ab(&q.v[2], &q.v[2], &x);
                vec_sub_ab(&q.v[3], &q.v[3], &x);
                u = r2 + 0.3f;
                q.uv[1][0] = r2;
                q.uv[0][0] = r2;
                q.color[3] = 0x4010FF10;
                q.color[2] = 0x4010FF10;
                q.color[1] = 0x4010FF10;
                q.color[0] = 0x4010FF10;
                q.uv[2][0] = u;
                q.uv[3][0] = u;
                r2 = u;
                if (u >= 1.0f) r2 = u - 1.0f;
                func_003D2DA0(&q, 0, 0);
            }
            ang = func_0038DAB8(ang, s->f44);
            t += step;
            for (k = 2; k < 4; k++) seg[k] = seg[k - 2];
        }
    }
}
/* localdecomp:end func_L03_00395D60 */
