#include "common.h"

/* declared by functions of L39_00563DB8.c, which this file was cut from */
extern void func_L39_005640A0(u8 *);
extern void func_L39_00564498(u8 *);

/* localdecomp:start func_L39_005640A0 */
#include "vu0.h"
#include "structs/camera.h"

typedef struct { vu0_v4 v[4]; s32 col[4]; f32 uv[8]; unsigned long tag[4]; } P_5640A0;
typedef struct { f32 x, y, z; } V3_5640A0;
typedef struct { f32 s, t; } UV_5640A0;

__asm__(".extern D_L39_0024B500, 4");
__asm__(".extern D_L39_0024B504, 4");
__asm__(".extern D_L39_0024B508, 4");
__asm__(".extern D_L39_0024B50C, 4");
__asm__(".extern D_L39_0024B510, 4");
extern s32 D_L39_0024B500;
extern f32 D_L39_0024B504;
extern f32 D_L39_0024B508;
extern f32 D_L39_0024B50C;
extern s32 D_L39_0024B510;
extern s32 D_L39_00241118;
__asm__(".extern D_L39_00241118, 16");
extern struct GameCamera D_L39_0024DE80[];
extern V3_5640A0 D_L39_003CD7A0[];
extern vu0_v4 D_L39_00472610[];
extern UV_5640A0 D_L39_00473830[];
extern vu0_v4 D_L39_00474140[];
extern s16 D_L39_00474740[][4];

extern long func_L39_00589890(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038C750(void);
extern void func_0038D028(void *, void *, void *);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_005640A0(u8 *a0)
{
    P_5640A0 s;
    vu0_v4 mat[4];
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 out;
    s32 cols[290];
    u8 *v;
    s32 i;
    s32 j;
    s32 c;
    s32 c2;
    s32 k;
    V3_5640A0 *pv = D_L39_003CD7A0;
    V3_5640A0 *pv2;
    UV_5640A0 *puv;
    vu0_v4 *src;
    f32 f1;
    f32 f2;

    v = *(u8 **)(a0 + 0x68);
    s.tag[1] = func_L39_00589890(D_L39_0024B500);
    s.tag[2] = 0xFF9000000260;
    s.tag[3] = 0x8000000044;
    s.tag[0] = 0;
    func_003A9440(0x47, 0x53001);
    mat[3] = *(vu0_v4 *)(v + 0x30);
    mat[3].w = 1.0f;
    vec_sub_ba(&d, &D_L39_0024DE80[D_L39_00241118].position, &mat[3]);
    func_0038CF68(&mat[0], &d, 1.0f);
    func_0038CE20(&e, *(u8 **)(v + 0x40) + 0x250, -1.0f);
    func_0038CE90(&mat[1], &mat[0], &e);
    func_0038CF68(&mat[1], &mat[1], 1.0f);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CE20(&mat[0], &mat[0], D_L39_0024B504);
    func_0038CE20(&mat[1], &mat[1], D_L39_0024B504);
    func_0038CE20(&mat[2], &mat[2], D_L39_0024B504);
    c = D_L39_0024B510 | *(s32 *)(v + 8);
    s.col[3] = c;
    s.col[2] = c;
    s.col[1] = c;
    s.col[0] = c;
    func_003A9440(6, func_L39_00589890(D_L39_0024B500));
    func_003A9440(0x42, 0x8000000044);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    func_003A9440(0x4A, 0);
    func_0038C750();
    src = D_L39_00472610;
    for (j = 0; j < 290; j++) {
        f32 x, y, z;
        func_0038D028(&out, src, mat);
        src++;
        x = out.x;
        y = out.y;
        z = out.z;
        pv->x = x;
        pv->y = y;
        pv->z = z;
        pv++;
        cols[j] = s.col[0];
    }
    pv2 = D_L39_003CD7A0;
    puv = D_L39_00473830;
    func_003D3A24(0x94, &pv2[0], &cols[0], &puv[0], 1);
    func_003D3A24(0x6D, &pv2[0x92], &cols[0x92], &puv[0x92], 1);
    func_003D3A24(0x24, &pv2[0xFE], &cols[0xFE], &puv[0xFE], 1);
    s.tag[1] = func_L39_00589890(0xB);
    s.tag[3] = 0x8000000048;
    f1 = D_L39_0024B508;
    f2 = f1 * D_L39_0024B50C;
    c2 = *(s32 *)(v + 8) | 0x40000000;
    s.col[3] = 0;
    s.col[1] = c2;
    s.col[0] = c2;
    s.col[2] = 0;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 4; j++) {
            k = D_L39_00474740[i][j];
            if (j >= 2) {
                func_0038CE20(&s.v[j], &D_L39_00474140[k], f2);
            } else {
                func_0038CE20(&s.v[j], &D_L39_00474140[k], f1);
            }
        }
        s.uv[0] = 0.5f;
        s.uv[1] = 0.5f;
        s.uv[2] = 0.5f;
        s.uv[3] = 0.5f;
        s.uv[4] = 0.5f;
        s.uv[5] = 1.0f;
        s.uv[6] = 0.5f;
        s.uv[7] = 1.0f;
        func_003D2DA0(&s, mat, 0);
    }
}
/* localdecomp:end func_L39_005640A0 */

INCLUDE_ASM("asm/levels", func_L39_00564498);

INCLUDE_ASM("asm/levels", func_L39_00564800);
