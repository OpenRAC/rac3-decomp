/* PAL near miss, reserved50 P01 (2026-11-23): 8 differing words with
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * The flag-only full PAL level-07 build matches with all seven existing C siblings.
 * The colour table now uses an incomplete .sdata declaration rather than an
 * unproven two-word extent; this preserves the same eight preheader differences.
 * Vertex/UV .sdata declarations, indexed pointer derivation, and moving the
 * second colour store worsened the check (19, 178, and 17). Explicitly naming
 * the edge colour left the original eight differences. Search parked.
 * Existing position/self/counter fixes are retained. No source promotion.
 */
#include "common.h"

/* localdecomp:start func_L07_003BFAE8 */
#include "vu0.h"
extern f32 D_L07_002A2A90[];
extern f32 D_L07_002A2B50[];
extern u32 D_L07_001E16C8[] __attribute__((section(".sdata")));

void func_L07_003BFAE8(void *arg0, f32 t, f32 scale, u8 mode)
{
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern void func_0038D750(void *, s32, f32);
    extern void func_0038D810(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038C750(void);
    extern long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    vu0_v4 rot;
    vu0_v4 mat[3];
    vu0_v4 offset;
    vu0_v4 radial;
    vu0_v4 temp;
    u8 *original = arg0;
    u8 *self;
    f32 blend, height, r0, r1, a0, a1, f0, f1, position, sign, negh, phase, x;
    f32 s, radius, angle, fade, u;
    u32 color;
    s32 i;
    f32 *vertices;
    f32 *uv;
    u32 *colors;

    blend = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    height = func_003C4088(12.0f, 8.0f, t) * scale;
    r0 = func_003C4088(1.8f, 1.0f, t);
    r1 = func_003C4088(3.0f, 6.0f, t);
    a0 = func_003C4088(1.5707964f, 1.3089969f, blend);
    a1 = func_003C4088(1.5707964f, 0.0f, blend);
    position = 0.0f;
    f1 = func_003C4088(-0.5f, 4.0f, t);
    if (t < 0.5f) {
        color = ((s32)(t * 2.0f * 128.0f) << 24) | 0x808080;
    } else {
        color = ((s32)((1.0f - t) * 2.0f * 128.0f) << 24) | 0x808080;
    }
    x = t * 2.3f * t * 2.0f;
    phase = x - cvtsw_asm(cvtws_asm(x));
    sign = 1.0f;
    if (mode) {
        sign = -1.0f;
    }
    negh = -height;
    self = original;
    i = 0;
    vertices = D_L07_002A2A90;
    uv = D_L07_002A2B50;
    colors = D_L07_001E16C8;
    for (; i < 8; i++) {
        func_0038D750(&rot, 2, *(f32 *)(self + 0xF8));
        func_0038D810(&rot, mat);
        s = (1.0f - func_0038D098(position * 3.1415927f)) * 0.5f;
        radius = func_003C4088(r0, r1, s);
        angle = func_003C4088(a0, a1, s);
        fade = func_003C4088(0.12f, f1, position);
        *(vu0_q *)&offset = 0;
        offset.x = negh * position;
        offset.y = sign * fade;
        func_0038D000(&offset, &offset, mat);
        *(vu0_q *)&temp = 0;
        temp.y = sign * radius * func_0038D098(angle);
        temp.z = radius * func_0038D0B0(angle);
        radial = temp;
        func_0038D000(&radial, &radial, mat);
        vec_add_ba(&temp, original + 0x10, &offset);
        u = s * 2.3f - phase;
        uv[1] = 1.0f;
        vertices[0] = temp.x;
        vertices[1] = temp.y;
        vertices[2] = temp.z;
        vec_add_ab(&temp, &temp, &radial);
        vertices[3] = temp.x;
        vertices[4] = temp.y;
        vertices[5] = temp.z;
        uv[0] = u;
        uv[2] = u;
        uv[3] = 0.0f;
        if (i == 0 || i == 7) {
            colors[0] = 0x808080;
        } else {
            colors[0] = color;
        }
        colors[1] = 0x808080;
        if (**(u8 ***)(self + 0x68) != 0) {
            self = **(u8 ***)(self + 0x68);
            position = 0.0f;
        } else {
            position += 0.16666667f;
        }
        colors += 2;
        uv += 4;
        vertices += 6;
    }
    func_0038C750();
    func_003A9440(6, func_00389598(0x65));
    func_003A9440(8, 4);
    func_003A9440(0x42, 0x8000000044UL);
    func_003D3A24(16, D_L07_002A2A90, D_L07_001E16C8, D_L07_002A2B50, 1);
}
/* localdecomp:end func_L07_003BFAE8 */
