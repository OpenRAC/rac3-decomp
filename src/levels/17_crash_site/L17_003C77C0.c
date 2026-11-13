#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L17_003C77C0 */
typedef struct { u8 p0[0x20]; s32 path; u8 p24[0xC]; s32 mode; u8 p34[2]; s16 ahead; u8 p38[4]; u8 b3C; } E_3C77C0;
typedef struct { u8 p0[0x1C]; E_3C77C0 *f1C; } R_3C77C0;
typedef struct { s32 count; u8 p4[0xC]; vu0_v4 pts[1]; } P_3C77C0;
typedef struct { u8 p0[0x54]; vu0_v4 *m; u8 p58[0x408]; } H_3C77C0;
extern R_3C77C0 *D_L17_001DE884;
__asm__(".extern D_L17_001DE884, 16");
extern H_3C77C0 D_L17_001E1980[];
extern s32 D_001A71AC[];
extern P_3C77C0 *D_L17_0021CD80[];
extern u8 D_001A4C60[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_00476B98(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L17_003C6910(u8 *);

void func_L17_003C77C0(u8 *self) {
    E_3C77C0 *e = D_L17_001DE884[*(s16 *)(self + 0x84)].f1C;
    H_3C77C0 *h = &D_L17_001E1980[*(s32 *)(self + 0x94)];
    P_3C77C0 *p;
    P_3C77C0 *q;
    s32 i, j;
    vu0_v4 out, dir, rel;
    s32 idx;
    f32 t;

    *(vu0_v4 *)(self + 0x30) = h->m[3];
    *(vu0_v4 *)(self + 0x00) = h->m[0];
    *(vu0_v4 *)(self + 0x10) = h->m[1];
    *(vu0_v4 *)(self + 0x20) = h->m[2];
    *(vu0_v4 *)(self + 0x40) = *(vu0_v4 *)(self + 0x00);
    if (D_001A71AC[0] == 0x1A) e->b3C = 1;
    else e->b3C = 0;
    if (e->path >= 0) {
        p = D_L17_0021CD80[e->path];
        for (i = 0; i < p->count; i++) {
            p->pts[i].w = func_0038CF00(&p->pts[i], &p->pts[(i + 1) % p->count]);
        }
    }
    e->ahead = 0;
    if (e->mode == 3) {
        q = D_L17_0021CD80[e->path];
        idx = 0;
        t = 0.0f;
        if (func_L01_00476B98(q, D_001A4C60, &out, &idx, &t, 0, 20.0f, 1.0f, 0.0f) != 0) {
            j = idx + 1;
            if (j >= q->count) j = q->count - 1;
            vec_sub_ba(&dir, &q->pts[j], &q->pts[idx]);
            if (func_0038CEA8(&dir) != 0.0f && j != idx) {
                func_0038CF68(&dir, &dir, 1.0f);
                vec_sub_ab(&rel, self + 0x30, D_001A4C60);
                if (0.0f < func_0038CE68(&rel, &dir)) e->ahead = 1;
            }
        }
    }
    func_L17_003C6910(self);
}
/* localdecomp:end func_L17_003C77C0 */

/* localdecomp:start func_L17_003C7A18 */
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } S_7A18_T;
typedef struct { u8 p0[0x1C]; struct S_7A18_E *f1C; } S_7A18_R;
typedef struct S_7A18_E { u8 p0[0x24]; s32 f24; u8 p28[0x14]; u8 b3C; } S_7A18_E;
typedef struct { u8 p0[0x7E]; s16 h7E; u8 p80[4]; s16 h84; s16 h86; } S_7A18_O;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0xC]; s32 f5E0; u8 p5E4[0xAC]; s32 f690; u8 p694[0xC]; s32 f6A0; u8 p6A4[0x2168]; s32 f280C; } S_7A18_G;
extern S_7A18_R *D_L17_001DE884_a;
__asm__(".extern D_L17_001DE884_a, 16");
extern S_7A18_G D_001A4BE0_7A18;
extern S_7A18_T *D_L17_001DED10;
void func_L17_003C7A18(S_7A18_O *a0) {
    S_7A18_E *e = D_L17_001DE884_a[a0->h84].f1C;
    s32 a, b;
    if (e->b3C) {
        b = D_001A4BE0_7A18.f690;
        a = D_001A4BE0_7A18.f6A0;
    } else {
        b = D_001A4BE0_7A18.f5D0;
        a = D_001A4BE0_7A18.f5E0;
    }
    if (D_001A4BE0_7A18.f280C == a0->h86) {
        if (e->f24 < 0) return;
        if (b == D_L17_001DED10[e->f24].f10 && a == 0) return;
    }
    a0->h7E = 3;
}
/* localdecomp:end func_L17_003C7A18 */
