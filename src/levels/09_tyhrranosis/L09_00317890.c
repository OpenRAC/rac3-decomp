#include "common.h"

/* localdecomp:start func_L09_00317890 */
#include "vu0.h"

extern u8 D_001A4C60[];
extern f32 D_001DC098;
extern f32 D_001DC09C;
__asm__(".extern D_001DC718, 8");
extern s32 D_001DC718[] __attribute__((section(".sdata")));

extern u8 *func_00382348(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

void func_L09_00317890(u8 *a0, s32 mode, void *a2, void *a3, long a4) {
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 g;
    f32 k;
    f32 len;
    f32 s;
    u8 *p;

    k = 0.009f;
    if (mode != 1) {
        k = 0.0065f;
        p = func_00382348(a0);
        if (p != 0) {
            switch (p[8]) {
            case 0:
                k = 0.004f;
                break;
            case 2:
                k = 0.009f;
                break;
            case 3:
                k = 0.0115f;
                break;
            }
        }
        if (mode == 3) {
            k += 0.001f;
        }
    }
    vec_sub_ab(&d, a0 + 0x10, D_001A4C60);
    s = func_0038CE68(&d, a2);
    func_0038CE20(&e, a2, s);
    vec_sub_ab(&d, &d, &e);
    len = func_0038CEA8(&d);
    if (len > 64.0f) {
        len = 64.0f;
    } else if (len < 8.0f) {
        len = 8.0f;
    }
    s = len * 0.015625f;
    func_0038D000(&d, &d, a3);
    func_0038CF68(&g, &d, s * 0.085f);
    g.x = g.x + 0.865f - k;
    g.y = g.y * 1.25f + 0.84f - k;
    func_0038B4D0((s32)(g.x * D_001DC098), (s32)(g.y * D_001DC09C), (s32)((k + k) * D_001DC098), (s32)((k + k) * D_001DC09C), 0, 0, 16, 16, D_001DC718[mode], a4);
}
/* localdecomp:end func_L09_00317890 */

/* localdecomp:start func_L09_00317B20 */
#include "vu0.h"
extern u8 D_001A4C60[];
extern vu0_v4 D_001DC730 __attribute__((section(".sdata")));
__asm__(".extern D_001DC730, 4");
extern u8 D_001D5477;
extern f32 D_001DC098;
extern f32 D_001DC09C;
extern s32 D_001DC720;
__asm__(".extern D_001DC098, 16");
__asm__(".extern D_001DC09C, 16");
__asm__(".extern D_001DC720, 16");
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

void func_L09_00317B20(void *axis, void *up, long color) {
    vu0_v4 d;
    vu0_v4 p;
    vu0_v4 o;
    f32 dot;
    f32 len;
    f32 s;
    f32 r = 0.0115f;

    vec_sub_ba(&d, &D_001DC730, D_001A4C60);
    dot = func_0038CE68(&d, axis);
    func_0038CE20(&p, axis, dot);
    vec_sub_ab(&d, &d, &p);
    len = func_0038CEA8(&d);
    if (len > 64.0f) {
        len = 64.0f;
    } else if (len < 8.0f) {
        len = 8.0f;
    }
    s = len * 0.015625f;
    func_0038D000(&d, &d, up);
    func_0038CF68(&o, &d, s * 0.085f);
    if (D_001D5477) {
        o.x = -o.x;
    }
    o.x = o.x + 0.865f - r;
    o.y = o.y * 1.25f + 0.84f - r;
    func_0038B4D0((s32)(o.x * D_001DC098), (s32)(o.y * D_001DC09C), (s32)(r * 2.0f * D_001DC098),
                  (s32)(r * 2.0f * D_001DC09C), 0, 0, 0x10, 0x10, D_001DC720, color);
}
/* localdecomp:end func_L09_00317B20 */
