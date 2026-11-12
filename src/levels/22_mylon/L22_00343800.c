#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_00343800 */
extern vu0_v4 D_L22_001E2A80;
extern u8 D_L22_001D66B0[8];
extern u8 *D_L22_0021FFAC[];
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);

void func_L22_00343800(vu0_v4 *pos, s32 a1, s32 big) {
    vu0_v4 d;
    vu0_v4 vel;
    vu0_v4 at;
    vu0_v4 pt;
    f32 heading;
    f32 speed;
    f32 size;
    f32 tilt;
    f32 yaw;
    s32 n;
    s32 i;
    u8 *q;
    u8 *data;

    vec_sub_ab(&d, &D_L22_001E2A80, pos);
    heading = func_0038D160(d.x, d.y);
    for (i = 0; i < 20; i++) {
        speed = func_003824E0(0.2f, 3.0f);
        func_003C5180(pos, &at, 1);
        func_0038CE20(&vel, &at, -(speed * 0.020000001f));
        n = func_L01_00443A18(1.0f, 2.0f);
        size = func_003824E0(0.3f, 0.75f) * 210000.0f;
        pt.x = pos->x + func_L01_00443A18(0.0f, 0.2f);
        pt.y = pos->y + func_L01_00443A18(0.0f, 0.2f);
        pt.z = pos->z + func_L01_00443A18(0.0f, 0.2f);
        q = func_L01_004669B0(&pt, 0.0f, 1.0f, 1.01f, size, n, &vel, 0x7F202020, 1);
        if (q != 0) {
            q[3] = 0x44;
            *(s16 *)(q + 0xA) = 0x4B;
            q[9] = 0x44;
            data = q + 0x20;
            *(f32 *)(data + 0x1C) = 4.0f;
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x30;
            data[0xB] = q[0xA];
        }
        speed = func_003824E0(1.0f, 2.0f);
        tilt = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&vel, speed * 0.020000001f, yaw, tilt);
        pt.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
        pt.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
        pt.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
        func_L01_0046A610(&pt, &vel, 0x19, 0x7F, 0x7F7F7F, n, func_003824E0(0.1f, 0.5f) * 210000.0f, 500.0f, 1.0f, 0.0f, 1.0f);
    }
    if (big == 1) {
        n = func_00382468(0xFF);
        q = func_L01_0046A610(pos, D_L22_001D66B0, 4, 0x7F, 0x207080, n, 525000.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        if (q != 0) {
            q[2] = *D_L22_0021FFAC[0];
        }
        q = func_L01_0046A610(pos, D_L22_001D66B0, 4, 0x7F, 0x207080, (n + 0x80) & 0xFF, 525000.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        if (q != 0) {
            q[2] = *D_L22_0021FFAC[0];
        }
    }
}
/* localdecomp:end func_L22_00343800 */

INCLUDE_ASM("asm/levels", func_L22_00343C18);

/* localdecomp:start func_L22_00344050 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern u8 *func_00382348(s32);
extern f32 D_L22_001DD0BC;
__asm__(".extern D_L22_001DD0BC, 4");
u8 *func_L22_00344050(s32 a0, u128_t *a1, f32 *a2, s32 a3, s32 a4, s32 a5, f32 fa, f32 fb) {
    u8 *o = func_003C24B0(0xA72, 0x80);
    u8 *st;
    u8 *q;
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        func_L01_00456160(o, a0);
        *(u128_t *)(o + 0x10) = *a1;
        *(f32 *)(o + 0xF8) = func_0038D160(a2[0], a2[1]);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CED8(a2), a2[2]);
        *(u128_t *)st = *(u128_t *)a2;
        *(u16 *)(st + 0x10) = 0x4B;
        *(s32 *)(st + 0x14) = a0;
        *(s32 *)(st + 0x18) = a3;
        *(s32 *)(st + 0x1C) = a4;
        *(f32 *)(st + 0x28) = fb;
        *(u16 *)(st + 0x12) = 0;
        *(f32 *)(st + 0x20) = fa;
        if (a5 != 0) {
            q = func_00382348(a5);
            if (q != 0) {
                *(u16 *)(q + 0x1E) = *(u16 *)(q + 0x1E) | 0x80;
                if (q[0xB] != 0) {
                    *(s32 *)(st + 0x24) = 0;
                } else {
                    *(s32 *)(st + 0x24) = a5;
                }
            } else {
                *(s32 *)(st + 0x24) = a5;
            }
        }
        if (fa == 1.0f) {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * D_L22_001DD0BC;
        } else {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * fa;
        }
    }
    return o;
}
/* localdecomp:end func_L22_00344050 */
