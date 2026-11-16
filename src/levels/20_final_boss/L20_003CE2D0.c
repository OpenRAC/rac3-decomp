#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L20_003CE2D0 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003CE2D0;
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L20_001D7C50[4];
extern s32 D_L20_001DEB00;
__asm__(".extern D_L20_001DEB00, 4");
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

/* Adapted from the repository's matched func_L20_003E6150 family member. */
void func_L20_003CE2D0(u8 *a0, f32 size) {
    Q_003CE2D0 q;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 p;
    vu0_v4 z;
    vu0_v4 c[3];
    s32 i;
    s32 j;

    func_003D93B0(&q, D_L20_001DEB00, 1, 0x80);
    q.gif = (0x8000L << 24) | 0x4A;
    p = *(vu0_v4 *)(a0 + 0x10);
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    vec_sub_ab(&d, D_L20_001E2E80, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE90(&e, &d, &D_001A4EC0);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    func_0038CE20(&z, &d, 0.05f);
    vec_add_ab(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L20_001D7C50[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    for (j = 0; j < 4; j++) {
        func_00389478(&q.v[j], &q.uv[j][0], &q.uv[j][1]);
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.gif = (0x8000L << 22) | 0x54;
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003CE2D0 */

INCLUDE_ASM("asm/levels", func_L20_003CE4F8);

/* localdecomp:start func_L20_003CEEB0 */
typedef struct {
    u8 pad0[8];
    s32 total;
    u8 padC[0x22-0xC];
    s16 timer;
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    vu0_v4 src[4];
    vu0_v4 pos[32];
    vu0_v4 vel[28];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    u8 pad630[0x10];
    vu0_v4 src2[4];
    vu0_v4 pos2[32];
    vu0_v4 vel2[28];
    vu0_v4 grid2[4][4];
    vu0_v4 gvel2[4][4];
} V_003CEEB0;

extern s32 D_L20_001DEB78;
extern s32 D_L20_001DEB7C;
extern s32 D_L20_001DEB1C;
extern s32 D_L20_001DEB20;
extern s32 D_L20_001DEB24;
__asm__(".extern D_L20_001DEB78, 4");
__asm__(".extern D_L20_001DEB7C, 4");
__asm__(".extern D_L20_001DEB1C, 4");
__asm__(".extern D_L20_001DEB20, 4");
__asm__(".extern D_L20_001DEB24, 4");
extern s32 func_0038DBD8(s32, s32, f32);

void func_L20_003CEEB0(u8 *self) {
    V_003CEEB0 *v = *(V_003CEEB0 **)(self + 0x68);
    s32 i;
    s32 k;
    s32 j;
    s32 j2;

    if (v->timer != 0) {
        v->timer--;
        for (i = 0; i < 23; i++) {
            vec_add_ab(&v->pos[i], &v->pos[i], &v->vel[i]);
        }
        for (i = 0; (f32)i < 4.0f; i++) {
            for (k = 1; k < 4; k++) {
                vec_add_ab(&v->grid[k][i], &v->grid[k][i], &v->gvel[k][i]);
            }
        }
        for (j = 0; j < 4; j++) {
            *(vu0_q *)&v->grid[0][j] = *(vu0_q *)&v->src[v->idx[j]];
        }
    }
    if (D_L20_001DEB78 < v->timer) {
        v->color = func_0038DBD8(D_L20_001DEB20, D_L20_001DEB1C,
            (f32)(v->timer - D_L20_001DEB78) / (f32)(v->total - D_L20_001DEB78));
    } else if (D_L20_001DEB7C < v->timer) {
        v->color = func_0038DBD8(D_L20_001DEB24, D_L20_001DEB20,
            (f32)(v->timer - D_L20_001DEB7C) / (f32)(D_L20_001DEB78 - D_L20_001DEB7C));
    } else {
        v->color = 0;
    }
    if (v->timer != 0) {
        v->timer--;
        for (i = 0; i < 23; i++) {
            vec_add_ab(&v->pos2[i], &v->pos2[i], &v->vel2[i]);
        }
        for (i = 0; (f32)i < 4.0f; i++) {
            for (k = 1; k < 4; k++) {
                vec_add_ab(&v->grid2[k][i], &v->grid2[k][i], &v->gvel2[k][i]);
            }
        }
        for (j2 = 0; j2 < 4; j2++) {
            *(vu0_q *)&v->grid2[0][j2] = *(vu0_q *)&v->src2[v->idx[j2]];
        }
    }
}
/* localdecomp:end func_L20_003CEEB0 */

INCLUDE_ASM("asm/levels", func_L20_003CF108);

/* localdecomp:start func_L20_003CFB08 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DEB80;
__asm__(".extern D_L20_001DEB80, 4");
extern void func_L20_003CE2D0(u8 *, f32);
extern f32 D_L20_001DF178;
__asm__(".extern D_L20_001DF178, 4");
extern s32 D_L20_001DF170;
__asm__(".extern D_L20_001DF170, 4");
extern s32 D_L20_001DF174;
__asm__(".extern D_L20_001DF174, 4");
extern f32 D_L20_001DF17C;
__asm__(".extern D_L20_001DF17C, 4");
extern f32 D_L20_001DF180;
__asm__(".extern D_L20_001DF180, 4");
extern f32 D_L20_001DF184;
__asm__(".extern D_L20_001DF184, 4");
extern u32 D_L20_001DF188;
__asm__(".extern D_L20_001DF188, 4");
extern u32 D_L20_001DF18C;
__asm__(".extern D_L20_001DF18C, 4");
extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L01_00404808(void (*)(void *), void *);

void func_L20_003CFB08(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);
    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DEB80, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DEB80, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DEB80, 2.0f, 0.1f);
    }
    func_L20_003CE2D0(p, D_L20_001DEB80);
}
/* localdecomp:end func_L20_003CFB08 */
