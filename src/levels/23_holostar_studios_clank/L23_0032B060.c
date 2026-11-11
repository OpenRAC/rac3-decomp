#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x18]; u8 *target; } S_1E8780;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; s16 h1A; u8 pad1C[0x14]; } Hit_32B190;

/* localdecomp:start func_L23_0032B060 */
extern u8 *func_003C24B0(s32, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

u8 *func_L23_0032B060(V4 *pos, V4 *dir, f32 *arg, f32 scale)
{
    V4 up;
    V4 fwd;
    u8 *m;
    u8 *v;

    func_003C5180(pos, &up, 1);
    m = func_003C24B0(0xF5D, 0x80);
    if (m != 0) {
        v = *(u8 **)(m + 0x68);
        *(f32 *)(v + 0x1C) = *arg;
        *(s32 *)(v + 0x10) = 0x43;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x20] = 0;
        *(V4 *)(m + 0x10) = *pos;
        *(V4 *)v = *dir;
        *(s32 *)(v + 0x18) = 0;
        *(s32 *)(v + 0x14) = 0;
        func_0038CF68(&fwd, dir, 1.0f);
        *(f32 *)(m + 0x2C) = scale;
        *(V4 *)(m + 0xC0) = fwd;
        func_0038CE90(m + 0xD0, m + 0xC0, &up);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        *(f32 *)(m + 0xCC) = *(f32 *)(m + 0xDC) = *(f32 *)(m + 0xEC) = 0.0f;
    }
    return m;
}
/* localdecomp:end func_L23_0032B060 */

/* localdecomp:start func_L23_0032B190 */
extern S_1E8780 D_L23_001E8780;
__asm__(".extern D_L23_001E8780, 16");
extern s32 D_001A71A0[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
void func_L23_0032B570(u8 *a0, s32 a1, s32 a2, f32 scale);

void func_L23_0032B190(u8 *o, void *arg)
{
    u8 *v = *(u8 **)(o + 0x68);
    V4 dir;
    Hit_32B190 hit;
    V4 pos;
    u8 *t;

    if (*(f32 *)(v + 0x18) < 1.0f)
        return;
    if (func_003D3CB0(arg, o + 0x10, 0, o, 0) == 0)
        return;
    t = D_L23_001E8780.target;
    if (t == 0)
        return;
    if (*(s16 *)(t + 0xAA) == 0x1B6A || *(s16 *)(t + 0xAA) == 0x1BD9 || *(s16 *)(t + 0xAA) == 0x1BC7)
        return;
    if ((s32)t == D_001A71A0[0] && 50.0f <= *(f32 *)(v + 0x1C))
        return;
    if (50.0f <= *(f32 *)(v + 0x1C))
        *(f32 *)(v + 0x1C) = 50.1f;
    func_0038CF68(&dir, v, 1.0f);
    func_L01_00446760(&hit, o, 0x10B0003, &dir, *(f32 *)(v + 0x1C));
    hit.b18 = 5;
    hit.h1A = *(s16 *)(o + 0xAA);
    hit.b19 = 3;
    func_L01_00446978(D_L23_001E8780.target, &hit);
    func_L23_0032B570(o + 0x10, 10, 1, *(f32 *)(o + 0x2C));
    if (D_L23_001E8780.target == 0) {
        pos = *(V4 *)(o + 0x10);
        func_L23_0032B570((u8 *)&pos, 15, 0, *(f32 *)(o + 0x2C));
    }
    o[0x20] = 2;
}
/* localdecomp:end func_L23_0032B190 */

/* localdecomp:start func_L23_0032B328 */
extern u32 D_L23_001DCB70;
__asm__(".extern D_L23_001DCB70, 4");
extern u32 D_L23_001DCB74;
__asm__(".extern D_L23_001DCB74, 4");
extern u32 D_L23_001DCB78;
__asm__(".extern D_L23_001DCB78, 4");
extern u32 D_L23_001DCB7C;
__asm__(".extern D_L23_001DCB7C, 4");
extern s32 D_L23_001DCB80;
__asm__(".extern D_L23_001DCB80, 4");
extern u32 D_L23_001DCB84;
__asm__(".extern D_L23_001DCB84, 4");
extern s32 D_L23_001DCB88;
__asm__(".extern D_L23_001DCB88, 4");
extern u32 D_L23_001DCB8C;
__asm__(".extern D_L23_001DCB8C, 4");
extern s32 D_L23_001DCB90;
__asm__(".extern D_L23_001DCB90, 4");
extern float D_L23_001DCB94;
__asm__(".extern D_L23_001DCB94, 4");
extern float func_0038CEA8(void *);
extern float func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, float, float, float);
extern void func_L01_0040A4A0(void *, void *, s32, u32, s32, s32, float, float, float);

void func_L23_0032B328(u8 *obj) {
    float v[4];
    u8 *pl = *(u8 **)(obj + 0x68);
    float f;
    float t;
    float s1;

    *(u128_t *)v = 0;
    v[3] = 1.0f;
    f = *(float *)(pl + 0x14) - 0.1f;
    *(float *)(pl + 0x14) = f;
    if (f <= -8.0f) {
        *(float *)(pl + 0x14) = f + 8.0f;
    }
    t = func_0038CEA8(pl);
    s1 = D_L23_001DCB94 * 0.2f;
    *(float *)(pl + 0x18) = *(float *)(pl + 0x18) + t;
    s1 = s1 * *(float *)(obj + 0x2C);
    func_003D9508(obj + 0x10, 0x31, D_L23_001DCB70, 1, s1, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 0x31, D_L23_001DCB74, 1, D_L23_001DCB94 * 0.1f * *(float *)(obj + 0x2C), 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 0x2F, D_L23_001DCB78, 1, D_L23_001DCB94 * 0.05f * *(float *)(obj + 0x2C), 0.0f, func_00382538());
    if (*(float *)(pl + 0x18) > 1.0f) {
        func_L01_0040A4A0(obj, v, 1, D_L23_001DCB7C, D_L23_001DCB80, 0x17, D_L23_001DCB94 * 0.02f * *(float *)(obj + 0x2C),
                          D_L23_001DCB94 * 0.4f, *(float *)(pl + 0x14));
        func_L01_0040A4A0(obj, v, 1, D_L23_001DCB84, D_L23_001DCB88, 0x17, D_L23_001DCB94 * 0.07f * *(float *)(obj + 0x2C),
                          D_L23_001DCB94 * 0.4f, *(float *)(pl + 0x14));
        func_L01_0040A4A0(obj, v, 1, D_L23_001DCB8C, D_L23_001DCB90, 0x17, D_L23_001DCB94 * 0.07f * *(float *)(obj + 0x2C),
                          D_L23_001DCB94 * 0.4f, *(float *)(pl + 0x14));
    }
}
/* localdecomp:end func_L23_0032B328 */

/* localdecomp:start func_L23_0032B570 */
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L23_0032B570(u8 *a0, s32 a1, s32 a2, f32 scale) {
    func_L01_003303B8(a0, 0, 1, 4, 1, 4, 0, 0, func_003824E0(0.8f, 1.2f) * scale, 0.0f, 0.0f, 0.0f,
                      0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0x63F7, 0x402FFF, 0x20FF, 0x2FFF, 0x3024FF, 0x7F60A0FF, 0x680000FF, 0x3064FF, 1);
}
/* localdecomp:end func_L23_0032B570 */
