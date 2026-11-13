/* near miss (level 3, Starship Phoenix): 155 differences, a first draft (needs L03_0032EDE0.c to take -mvu0-use-vf0-vf2 ... @ps2as, and its other C to be rechecked): the five-slot update loop around func_L03_0032EC38's layout; the prologue, the spill of s+0x80 at 0x30($sp), the abs.s test and the i == 4 branch match, the other branch computes the i % 2 offsets twice where retail keeps one address; sharing the three stack vectors between the branches (retail's 0xC0 frame) took it from 180 to 155, a pointer to the off2 element gave 266 */
#include "common.h"

/* localdecomp:start func_L03_0032F038 */
#include "vu0.h"
typedef struct {
    s32 pair[4][2];
    s32 ids[4];
    s32 snd30[4][2];
    s32 snd50[4];
    u8 pad60[0x80 - 0x60];
    f32 a80[5];
    f32 a94[5];
    u8 padA8[0xF6 - 0xA8];
    u8 bF6;
    u8 bF7;
    f32 fF8;
} S_0032F038;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_0032F038 *p68; } A_0032F038;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_L01_00404808(void *, void *);
extern void func_L03_00330A58(void *);
extern void func_L03_00330EC8(void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_003A4F28(s32);

s32 func_L03_0032F038(void *arg) {
    A_0032F038 *a = arg;
    S_0032F038 *s = a->p68;
    s32 ret = 0;
    int i;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    if (s->bF7 != 0 && s->fF8 < 2.0f) {
        s->fF8 = s->fF8 + 0.036000002f;
        ret = 1;
        func_L01_00404808(func_L03_00330A58, a);
        func_L03_00330EC8(a);
        if (s->fF8 < 1.0f) return 1;
    }
    for (i = 0; i < 5; i++) {
        f32 tgt = 0.0f;
        if ((s->bF6 >> i) & 1) tgt = 1.0f;
        if (__builtin_fabsf(tgt - s->a80[i]) > 1e-05f) {
            if (i == 4) {
                f32 ang;
                f32 r, z;
                int j;
                func_003C41A0(&s->a80[4], &s->a94[4], tgt, 0.0072000003f, 0.0072000003f, 0.006f);
                ang = 0.7853982f;
                r = s->a80[4] * 10.5f;
                z = s->a80[4] * -0.1f;
                for (j = 0; j < 4; j++) {
                    u8 *m = D_L03_001DF99C + (s->ids[j] << 8);
                    *(vu0_q *)&v1 = 0;
                    v1.x = r * func_0038D0B0(ang);
                    v1.y = r * func_0038D098(ang);
                    v1.z = z;
                    v0 = v1;
                    vec_add_ab(m + 0x10, &a->pos, &v0);
                    ang = func_0038DAB8(ang, 1.5707964f);
                    if (s->snd50[j] == -1) s->snd50[j] = func_L01_004AAC98(0, 4, m, 0x1936);
                }
            } else {
                f32 k;
                u8 *e0, *e1;
                func_003C41A0(&s->a80[i], &s->a94[i], tgt, 0.014400001f, 0.014400001f, 0.012f);
                e0 = D_L03_001DF99C + (s->pair[i][0] << 8);
                e1 = D_L03_001DF99C + (s->pair[i][1] << 8);
                *(vu0_q *)&v0 = 0;
                *(vu0_q *)&v1 = 0;
                k = s->a80[i] * 1.7f;
                (&v0.x)[i % 2] += (i < 2) ? 16.65f : -16.65f;
                if ((u32)(i - 1) < 2) {
                    (&v1.x)[1 - i % 2] += k;
                } else {
                    (&v1.x)[1 - i % 2] -= k;
                }
                vec_add_ba(&v2, &a->pos, &v0);
                v2.z += -0.3f;
                vec_sub_ba(e0 + 0x10, &v2, &v1);
                vec_add_ab(e1 + 0x10, &v2, &v1);
                if (s->snd30[i][0] == -1) s->snd30[i][0] = func_L01_004AAC98(1, 4, e1, 0x1936);
                if (s->snd30[i][1] == -1) s->snd30[i][1] = func_L01_004AAC98(1, 4, e0, 0x1936);
            }
            ret = 1;
        } else if (i == 4) {
            if (s->snd50[0] != -1) {
                int j;
                for (j = 0; j < 4; j++) {
                    func_003A4F28(s->snd50[j]);
                    s->snd50[j] = -1;
                }
            }
        } else if (s->snd30[i][0] != -1) {
            int j;
            for (j = 0; j < 2; j++) {
                func_003A4F28(s->snd30[i][j]);
                s->snd30[i][j] = -1;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L03_0032F038 */
