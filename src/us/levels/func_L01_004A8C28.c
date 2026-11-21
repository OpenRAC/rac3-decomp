#include "common.h"

/* NTSC-U counterpart of func_L01_004AC618 (src/levels/shared/L01_004AC1C0.c): 126 -> 151 */
/* localdecomp:start func_L01_004A8C28 */
/* localdecomp:start func_L01_004A8C28 */
#include "vu0.h"
typedef struct {
    vu0_v4 verts[4];
    u32 colors[4];
    u8 tag[0x20];
    long q0, q1, q2, q3;
} Quad_4AC618_004AC618;
extern s32 D_L01_001D673C_004A8C28;
extern s32 D_L01_001D6694_004A8C28;
typedef struct { u8 pad[0x20]; s16 h20, h22; } T_16C580_4AC618_004AC618;
extern T_16C580_4AC618_004AC618 D_0016C580_004A8C28;
extern u8 D_L01_001D9970_004A8C28[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9970_004A8C28, 8");
extern f32 D_L01_001D9990_004A8C28[][4] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9990_004A8C28, 8");
extern void func_00388718(void *, void *, f32);
extern s32 func_L01_0040D1B8_004A8C28(void *, s32 *, f32);
extern long func_00384EC0(s32);
extern void func_003885F0(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_003CD830(void *, s32, s32);

void func_L01_004A8C28(u8 *obj)
{
    f32 pos[4];
    Quad_4AC618_004AC618 quad;
    f32 tmp[4];
    s32 alpha;
    f32 z;
    s32 i;

    if (D_L01_001D673C_004A8C28 != 0) {
        return;
    }
    alpha = 0;
    func_00388718(pos, obj, 0.0009765625f);
    if (func_L01_0040D1B8_004A8C28(pos, &alpha, 32.0f) < 0) {
        return;
    }
    if (D_L01_001D6694_004A8C28 == 6 && D_0016C580_004A8C28.h20 == 1
        && D_0016C580_004A8C28.h22 >= 0x97) {
        alpha -= D_0016C580_004A8C28.h22;
        if (alpha <= 0) {
            return;
        }
    }
    quad.q1 = func_00384EC0(0);
    quad.q2 = 0xFF9000000260L;
    quad.q3 = 0x8000000044L;
    quad.q0 = 0;
    func_003885F0(quad.tag, D_L01_001D9970_004A8C28, 0x20);
    func_003886E8(tmp, obj, 0.0009765625f);
    z = *(f32 *)(obj + 0x18) + 0.1f;
    if (D_L01_001D6694_004A8C28 == 6 || D_L01_001D6694_004A8C28 == 0 || D_L01_001D6694_004A8C28 == 4) {
        z = func_003BE7F0(obj + 0x10, 0, 0, 0.5f) + 0.1f;
    }
    for (i = 0; i < 4; i++) {
        quad.colors[i] = ((alpha >> 1) << 24) | 0x808080;
        func_003888C8(&quad.verts[i], D_L01_001D9990_004A8C28[i], obj + 0xC0);
        vec_add_ab(&quad.verts[i], &quad.verts[i], obj + 0x10);
        quad.verts[i].z = z;
    }
    func_003CD830(quad.verts, 0, 0);
}
/* localdecomp:end func_L01_004A8C28 */
