#include "common.h"

/* localdecomp:start func_L01_00376178 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x18]; unsigned long tag;
} Draw_00376178;
typedef struct {
    Draw_00376178 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta; vu0_v4 matrix[3];
} Work_00376178;
typedef int u128_00376178 __attribute__((mode(TI)));
extern vu0_v4 D_L01_001E2A40;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68_00376178(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

void func_L01_00376178(void *position, s32 texture, f32 size, f32 offset, f32 angle, f32 stretch) {
    Work_00376178 w;
    s32 i;
    func_003D93B0(&w.draw, texture, 1, 0x80);
    w.draw.tag = 0x800000004A;
    w.draw.color[3] = 0x80808080;
    w.draw.color[2] = 0x80808080;
    w.draw.color[1] = 0x80808080;
    w.draw.color[0] = 0x80808080;
    *(u128_00376178 *)&w.pos = *(u128_00376178 *)position;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    vec_sub_ab(&w.basis[0], &D_L01_001E2A40, &w.pos);
    func_0038CF68_00376178(&w.basis[0], &w.basis[0], 1.0f);
    func_0038CE90(&w.basis[1], &w.basis[0], &D_001A4EC0);
    func_0038CF68_00376178(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    if (angle != 0.0f) {
        *(u128_00376178 *)&w.delta = 0;
        w.delta.x = angle;
        func_0038D308(w.matrix, &w.delta);
        func_0038D5F0(w.basis, w.basis, w.matrix);
    }
    func_0038CE20(&w.delta, w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&w.draw.v[i], &D_L01_001D7C50[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&w.draw, 0, 0);
    {
        s32 k;
        s32 j;
        *(u128_00376178 *)&w.matrix[0] = *(u128_00376178 *)&w.draw.v[0];
        for (k = 1; k < 4; k++) vec_add_ba(&w.matrix[0], &w.matrix[0], &w.draw.v[k]);
        func_0038CE20(&w.matrix[0], &w.matrix[0], 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ab(&w.matrix[1], &w.draw.v[j], &w.matrix[0]);
            func_0038CE20(&w.matrix[1], &w.matrix[1], stretch);
            vec_add_ab(&w.matrix[1], &w.matrix[0], &w.matrix[1]);
            func_00389478(&w.matrix[1], &w.draw.uv[j][0], &w.draw.uv[j][1]);
        }
    }
    func_003D93B0(&w.draw, -1, 1, 0x80);
    w.draw.tag = 0x2000000054;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&w.draw, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_00376178 */

INCLUDE_ASM("asm/levels", func_L01_00376490);

INCLUDE_ASM("asm/levels", func_L01_00376D08);

/* localdecomp:start func_L01_003770A8 */
__asm__(".extern D_L01_001DDAD4, 4");
__asm__(".extern D_L01_001DDAE0, 4");
__asm__(".extern D_L01_001DDAEC, 4");
__asm__(".extern D_L01_001DDAE4, 4");
__asm__(".extern D_L01_001DDAF0, 4");
__asm__(".extern D_L01_001DDAE8, 4");
__asm__(".extern D_L01_001DDAF4, 4");
__asm__(".extern D_L01_001DDAF8, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_3770A8;

extern f32 D_L01_001DDAD4;   /* spin of the first billboard, degrees a frame */
extern f32 D_L01_001DDAE0;
extern f32 D_L01_001DDAEC;
extern f32 D_L01_001DDAE4;
extern f32 D_L01_001DDAF0;
extern f32 D_L01_001DDAE8;
extern f32 D_L01_001DDAF4;
extern f32 D_L01_001DDAF8;   /* the drawn size */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040AAC8(void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);

/* rift_flight_draw: the rift's in-flight draw within 96 u of the view */
void func_L01_003770A8(M_3770A8 *obj) {
    f32 *q = obj->pos;
    f32 *st = (f32 *)obj->state;
    f32 s;
    f32 r;

    st[12] = func_0038DAB8(st[12], D_L01_001DDAD4 * 0.017453292f);
    D_L01_001DDAE0 = func_0038DAB8(D_L01_001DDAE0, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    D_L01_001DDAEC = func_0038DAB8(D_L01_001DDAEC, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    D_L01_001DDAE4 = func_0038DAB8(D_L01_001DDAE4, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    D_L01_001DDAF0 = func_0038DAB8(D_L01_001DDAF0, func_003824E0(-1.5f, -2.5f) * 0.017453292f);
    D_L01_001DDAE8 = func_0038DAB8(D_L01_001DDAE8, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    D_L01_001DDAF4 = func_0038DAB8(D_L01_001DDAF4, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    func_003D9508(q, 76, 0x6FFF4040, 1, D_L01_001DDAF8 * 1.2f, 0.01f, D_L01_001DDAF0);
    func_003D9508(q, 76, 0x7FFF0032, 1, D_L01_001DDAF8 * 0.7f, 0.01f, -D_L01_001DDAEC);
    func_003D9508(q, 76, 0x7F701010, 1, D_L01_001DDAF8 * 0.2f, 0.01f, D_L01_001DDAEC);
    func_003D9508(q, 75, 0x7F204080, 1, D_L01_001DDAF8 * 0.7f, 0.01f, D_L01_001DDAF0);
    func_L01_0040AAC8(q, 71, 72, 0x4FFF0032, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE0, D_L01_001DDAEC, 0.0f);
    func_L01_0040AAC8(q, 71, 72, 0x4F804020, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE4, D_L01_001DDAF0, 0.05f);
    func_L01_0040AAC8(q, 71, 72, 0x4F20207F, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE8, D_L01_001DDAF4, 0.1f);
    s = D_L01_001DDAF8 * 1.4f;
    r = func_00382538();
    func_003D9508(q, 11, 0x3FFF2040, 1, s, 0.01f, r);
}
/* localdecomp:end func_L01_003770A8 */
