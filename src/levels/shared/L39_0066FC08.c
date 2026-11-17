#include "common.h"

/* localdecomp:start func_L39_0066FC08 */
typedef struct { s32 a, b, c, d, e; } S_0066FC08_E;
typedef struct { char pad[0x1AC]; S_0066FC08_E e[3]; } S_0066FC08_G;

extern s32 D_L39_0024BD18;
extern s32 *D_L39_00241120;
extern s32 D_L39_00241470;
extern S_0066FC08_G D_L39_00352940_0066FC08;
extern s32 D_L39_00352AF4[];
extern u8 *D_L39_00241640_0066FC08;
extern u8 D_L39_00246418[];
__asm__(".extern D_L39_002463C8, 8");
__asm__(".extern D_L39_00246408, 8");
extern s32 D_L39_002463C8[2];
extern s32 D_L39_00246408[2];
extern void func_0038E150(s32);
extern void func_0038E138(void);
extern void func_003A9440(s32, unsigned long);
extern u8 *func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_00120884(void *);
extern void func_L01_00412BC0(unsigned long, u8 *, f32, f32, s32, f32);
extern s32 func_L39_0066F5C0(s32);

s32 func_L39_0066FC08(void) {
    u8 buf[0x200];
    s32 y, step, saved, i, r, a, b;
    f32 scale, fy;
    if (D_L39_0024BD18 == 0) {
        y = 0x186;
        scale = 1.0f;
        step = 15;
        switch (*D_L39_00241120) {
        case 1: y = 0x168; break;
        case 2: y = 0xA2; scale = 0.68f; step = 12; break;
        case 3:
        case 4: y = 0xB8; scale = 0.6f; step = 8; break;
        }
        saved = D_L39_00241470;
        if (*D_L39_00241120 >= 2) func_0038E150(1);
        for (i = 0; i < (*D_L39_00241120 >= 3 ? 2 : 3); i++) {
            if (D_L39_00352940_0066FC08.e[i].e > 0) continue;
            if (D_L39_00352940_0066FC08.e[i].d == 0) continue;
            b = D_L39_00352940_0066FC08.e[i].b;
            a = D_L39_00352940_0066FC08.e[i].a;
            if (b >= 0 && a >= 0) {
                fy = (f32)y;
                y += step;
                func_00120048(buf, D_L39_00246418, D_L39_00241640_0066FC08 + a * 16, func_00381FF0(D_L39_002463C8[D_L39_00352AF4[i * 5]]), D_L39_00241640_0066FC08 + b * 16);
                func_L01_00412BC0((s32)0x90FFFFFF, buf, 15.0f, fy, func_00120884(buf), scale);
            } else if (a < -1) {
                u8 *s1;
                r = func_L39_0066F5C0(a);
                if (r < 0) return 0;
                fy = (f32)y;
                y += step;
                s1 = func_00381FF0(D_L39_00246408[r]);
                func_00120048(buf, D_L39_00246418, s1, func_00381FF0(D_L39_002463C8[D_L39_00352AF4[i * 5]]), D_L39_00241640_0066FC08 + b * 16);
                func_L01_00412BC0((s32)0x90FFFFFF, buf, 15.0f, fy, func_00120884(buf), scale);
            }
        }
        func_0038E150(saved);
        func_0038E138();
        func_003A9440(0x47, 0x5340B);
    }
    return 0;
}
/* localdecomp:end func_L39_0066FC08 */

INCLUDE_ASM("asm/levels", func_L39_0066FF08);
