#include "common.h"

/* declared by functions of L17_003B8B18.c, which this file was cut from */
extern f32 D_L17_001DE59C;
extern f32 D_L17_001DE5AC;
extern void func_L17_003B8BF8(void *, s32, s32, s32, f32, f32, f32);

/* localdecomp:start func_L17_003B8BF8 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    u32 c[4];
    f32 uv[8];
    unsigned long prim, tex, mode, flags;
} Pkt_003B8BF8;
extern vu0_v4 D_L17_001E1900;
extern f32 D_L17_001DE5AC;
__asm__(".extern D_L17_001DE5AC, 4");
extern f32 D_L17_001DE59C;
__asm__(".extern D_L17_001DE59C, 4");
extern s32 D_L17_001DE5A4;
__asm__(".extern D_L17_001DE5A4, 4");
extern s32 D_L17_001DE5A8;
__asm__(".extern D_L17_001DE5A8, 4");
extern s32 D_L17_001DE5D0_003B8BF8;
__asm__(".extern D_L17_001DE5D0_003B8BF8, 4");
extern s32 D_L17_001DE5D4;
__asm__(".extern D_L17_001DE5D4, 4");
extern long func_00389598(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_003A9440(s32, unsigned long);

/* from rac2-decomp's func_0030D5B8 */
void func_L17_003B8BF8(void *arg0, s32 alpha, s32 haloAlpha, s32 count, f32 unused, f32 width, f32 extend) {
    vu0_v4 *points = arg0;
    Pkt_003B8BF8 core, halo;
    vu0_v4 normal, widthVector, eye, tangent, first, last, firstRay, lastRay, toEye, extension;
    f32 length, initialLength, haloLength, firstLength, lastLength;
    s32 i;
    u32 coreColor, haloColor;

    core.tex = func_00389598(D_L17_001DE5D0_003B8BF8);
    coreColor = D_L17_001DE5A4 | (alpha << 24);
    core.flags = 0x8000000048UL;
    core.mode = 0xFF9000000260UL;
    core.prim = 0;
    core.c[3] = coreColor; core.c[2] = coreColor;
    core.c[1] = coreColor; core.c[0] = coreColor;
    halo.tex = func_00389598(D_L17_001DE5D4);
    halo.flags = core.flags; halo.mode = core.mode; halo.prim = core.prim;
    haloColor = D_L17_001DE5A8 | (haloAlpha << 24);
    halo.c[3] = haloColor; halo.c[2] = haloColor;
    halo.c[1] = haloColor; halo.c[0] = haloColor;
    halo.uv[0] = 0; halo.uv[1] = 0; halo.uv[2] = 0; halo.uv[3] = 1;
    halo.uv[4] = 1; halo.uv[5] = 0; halo.uv[6] = 1; halo.uv[7] = 1;
    core.uv[0] = D_L17_001DE59C + 0.0f; core.uv[1] = 0; core.uv[2] = D_L17_001DE59C + 0.0f; core.uv[3] = 1;
    core.uv[4] = D_L17_001DE59C + 1.0f; core.uv[5] = 0; core.uv[6] = D_L17_001DE59C + 1.0f; core.uv[7] = 1;
    vec_sub_ab(&eye, points, &D_L17_001E1900);
    vec_sub_ab(&tangent, points + 1, points);
    func_0038CE90(&normal, &tangent, &eye);
    initialLength = func_0038CEA8(&normal);
    if (initialLength != 0) initialLength = 1.0f / initialLength;
    func_0038CE20(&normal, &normal, D_L17_001DE5AC * initialLength);
    vec_add_ba(&core.v[0], points, &normal);
    vec_sub_ab(&core.v[1], points, &normal);
    for (i = 1; i < count - 1; i++) {
        vec_sub_ab(&eye, points + i, &D_L17_001E1900);
        vec_sub_ab(&tangent, points + i + 1, points + i);
        func_0038CE90(&normal, &tangent, &eye);
        length = func_0038CEA8(&normal);
        if (length != 0) length = 1.0f / length;
        func_0038CE20(&normal, &normal, D_L17_001DE5AC * length);
        vec_add_ba(&core.v[2], points + i, &normal);
        vec_sub_ab(&core.v[3], points + i, &normal);
        if (i == 1) { core.c[1] = D_L17_001DE5A4; core.c[0] = D_L17_001DE5A4; }
        else if (i == count - 2) { core.c[3] = D_L17_001DE5A4; core.c[2] = D_L17_001DE5A4; }
        else if (i == 2) { core.c[1] = coreColor; core.c[0] = coreColor; }
        func_003D2DA0(&core, 0, 0);
        *(vu0_q *)&core.v[0] = *(vu0_q *)&core.v[2];
        *(vu0_q *)&core.v[1] = *(vu0_q *)&core.v[3];
    }
    for (i = 0; i < count - 2; i++) {
        vec_sub_ab(&firstRay, points + i, &D_L17_001E1900);
        vec_sub_ab(&lastRay, points + i + 1, &D_L17_001E1900);
        firstLength = func_0038CEA8(&firstRay);
        lastLength = func_0038CEA8(&lastRay);
        if (lastLength < firstLength) {
            if (lastLength == 0) { *(vu0_q *)&lastRay = *(vu0_q *)&firstRay; }
            else func_0038CE20(&lastRay, &lastRay, firstLength / lastLength);
        } else if (firstLength == 0) { *(vu0_q *)&firstRay = *(vu0_q *)&lastRay; }
        else func_0038CE20(&firstRay, &firstRay, lastLength / firstLength);
        vec_add_ba(&first, &D_L17_001E1900, &firstRay);
        vec_add_ab(&last, &D_L17_001E1900, &lastRay);
        vec_sub_ba(&tangent, &last, &first);
        func_0038CE20(&extension, &tangent, extend);
        vec_sub_ab(&first, &first, &extension);
        vec_add_ab(&last, &last, &extension);
        vec_sub_ab(&toEye, &D_L17_001E1900, &first);
        func_0038CE90(&normal, &toEye, &tangent);
        haloLength = func_0038CEA8(&normal);
        if (haloLength != 0) haloLength = 1.0f / haloLength;
        func_0038CE20(&widthVector, &normal, width * haloLength);
        vec_add_ba(&halo.v[0], &first, &widthVector);
        vec_sub_ab(&halo.v[1], &first, &widthVector);
        vec_add_ba(&halo.v[2], &last, &widthVector);
        vec_sub_ab(&halo.v[3], &last, &widthVector);
        if (i == 0) { halo.c[1] = D_L17_001DE5A8; halo.c[0] = D_L17_001DE5A8; }
        else if (i == count - 3) { halo.c[3] = D_L17_001DE5A8; halo.c[2] = D_L17_001DE5A8; }
        else if (i == 1) { halo.c[1] = haloColor; halo.c[0] = haloColor; }
        func_003D2DA0(&halo, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L17_003B8BF8 */
