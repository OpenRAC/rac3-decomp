#include "common.h"

/* localdecomp:start func_L01_003773C0 */
#include "vu0.h"
__asm__(".extern D_L01_001DDAA0, 4");
__asm__(".extern D_L01_001DDAA4, 4");
__asm__(".extern D_L01_001DDAB0, 4");
extern vu0_v4 D_001A4EC0;
__asm__(".extern D_L01_001DDA70, 4");
extern vu0_v4 D_L01_001DDA70[] __attribute__((section(".sdata")));
extern f32 D_L01_001DDAA0;
extern f32 D_L01_001DDAA4;
extern f32 D_L01_001DDAB0;
extern f32 D_L01_001DDAB4;
extern f32 D_L01_001DDAB8;
extern f32 D_L01_001E1D60[] __attribute__((section(".sdata")));
extern u8 *D_L01_00221098[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68_003773C0(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, f32, f32, f32, s32, s32, s32);
void func_L01_003773C0(u8 *a0, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 step;
    vu0_v4 d;
    vu0_v4 m[3];
    vu0_v4 q;
    u8 *s;
    f32 len;
    s32 n;
    s32 i;
    s32 k = 0;

    from = *a1;
    s = *(u8 **)(a0 + 0x68);
    to = *a2;
    len = func_0038CEA8(s);
    pos = to;
    vec_sub_ab(&step, &from, &to);
    n = len / 0.1f;
    func_0038CF68_003773C0(&step, &step, len / (f32)n);
    for (i = 0; i < n; i++) {
        s32 spin = (s32)func_L01_00443A18(1.0f, 3.0f);
        s32 life;
        s32 alpha;
        s32 rgb;
        u8 *p;
        f32 r = func_003824E0(0.1f, 0.2f);
        func_0038CE20(&vel, &D_001A4EC0, -(r * 0.020000001f));
        life = func_00382498(3, 6);
        if (func_0013D3E0() & 2) {
            alpha = 0x60;
            rgb = 0xFF7F40;
        } else {
            alpha = 0x7F;
            rgb = 0xFF4040;
        }
        p = func_L01_0046A610(&pos, &vel, (life * 5 + 2) / 6, alpha, rgb, spin, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&pos, &pos, &step);
        if (p != 0) {
            p[2] = *D_L01_00221098[0x5C / 4];
            p[3] = (alpha == 0x40) ? 0x48 : 0x44;
        }
    }
    if (*(s32 *)(s + 0x34) < 0x32 && func_00382468(2)) {
        s32 c;
        u8 *p;
        func_0038CE20(&d, s, -0.040000003f);
        c = 0x7F80DFFF;
        func_003C4C18(&d, 0.120000005f);
        d.z += 0.060000002f;
        if (func_00382468(2)) {
            c = 0x7F407FFF;
        }
        p = func_L01_00465738(a0 + 0x10, &d, c, 0xFF, func_00382498(8, 0x11), 0, -1, -1, 0, 94500.0f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = 0.0024f;
            p[2] = *D_L01_00221098[0xD4 / 4];
        }
    }
    D_L01_001E1D60[0] = func_0038DAB8(D_L01_001E1D60[0], D_L01_001DDAB0 * 0.017453292f * 0.020000001f);
    D_L01_001E1D60[1] = func_0038DAB8(D_L01_001E1D60[1], D_L01_001DDAB4 * 0.017453292f * 0.020000001f);
    D_L01_001E1D60[2] = func_0038DAB8(D_L01_001E1D60[2], D_L01_001DDAB8 * 0.017453292f * 0.020000001f);
    func_0038D308(m, D_L01_001E1D60);
    for (k = 0; k < 3; k++) {
        u8 *p;
        func_0038D000(&q, &D_L01_001DDA70[k], m);
        if (*(s32 *)(s + 0x34) >= 6) {
            func_0038CF68_003773C0(&q, &q, D_L01_001DDAA0);
        } else {
            func_0038CF68_003773C0(&q, &q, 0.0f);
        }
        vec_add_ab(&q, &q, a0 + 0x10);
        vec_sub_ab(&d, &q, a0 + 0x10);
        func_0038CF68_003773C0(&d, &d, D_L01_001DDAA4 * 0.020000001f);
        p = func_L01_004713C8(&q, &d, 0xC, 0x801020, (s32)func_L01_00443A18(2.0f, 5.0f), 63000.004f,
                              func_003824E0(0.119999997f, 0.180000007f) * 210000.0f, 0.0f, 0x6F, 0, 6);
        if (p != 0) {
            p[3] = func_00382468(4) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L01_003773C0 */
