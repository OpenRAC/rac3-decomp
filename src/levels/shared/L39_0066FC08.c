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

/* localdecomp:start func_L39_0066FF08 */
typedef struct { char pad[0x1A8]; s32 f1A8; } S_0066FF08;

extern s32 D_L39_0024BD18;
extern S_0066FF08 D_L39_001FD7E8;
extern s32 D_L39_00352B2C[];
extern u8 D_L39_00246428_0066FF08[];
extern s32 *D_L39_00241120;
extern s32 D_L39_00241470;
extern s32 D_L39_00242914;
typedef struct { s32 w; s32 h; } Scr_0066FF08;
extern Scr_0066FF08 D_L39_00240300;
extern void func_0038E150(s32);
extern u8 *func_00381FF0(s32);
extern char *func_L39_0066C7D8(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L01_00412708(void);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern void func_0038E7E8(f32, f32, unsigned long, char *, s32, f32, f32, s32, s32, unsigned long, f32, f32);

/* a text draw at scale 1.0 with a shadow offset */
static __inline__ void text_0066FF08(f32 x, f32 y, unsigned long color, char *buf, f32 shadow) {
    func_0038E7E8(x, y, color, buf, -1, 1.0f, 1.0f, 1, 1, 0x80000000UL, shadow, shadow);
}

s32 func_L39_0066FF08(void) {
    char buf[0x40];
    u32 color;
    s32 saved, w;
    if (D_L39_0024BD18 != 0) {
        return 0;
    }
    color = 0x8066CCFF;
    if (D_L39_001FD7E8.f1A8 != -1 && D_L39_00352B2C[0] != 1) {
        func_00120048((u8 *)buf, func_00381FF0(0x1B9F), func_L39_0066C7D8(D_L39_001FD7E8.f1A8));
    } else {
        func_00120048((u8 *)buf, D_L39_00246428_0066FF08, func_00381FF0(0x185E));
    }
    saved = D_L39_00241470;
    if (*D_L39_00241120 >= 2) func_0038E150(1);
    w = ((s32 (*)(char *, s32))func_L01_00412708)(buf, -1) + 10;
    if (D_L39_00242914 == 0) {
        s32 hw = w / 2;
        f32 shadow;
        func_0038C3B0(D_L39_00240300.h / 2 - 0x78, D_L39_00240300.h / 2 - 0x64, D_L39_00240300.w / 2 - hw, D_L39_00240300.w / 2 + hw, 0x33, 0x331465B7);
        func_L01_00436020(0x33, 0x332299DE, (f32)(D_L39_00240300.h / 2 - 0x78), (f32)(D_L39_00240300.h / 2 - 0x64), (f32)(D_L39_00240300.w / 2 - hw), (f32)(D_L39_00240300.w / 2 + hw));
        shadow = 2.0f;
        text_0066FF08((f32)(D_L39_00240300.w / 2), (f32)(D_L39_00240300.h / 2 - 0x76), color, buf, shadow);
    } else {
        s32 hw = w / 2;
        f32 shadow;
        func_0038C3B0(D_L39_00240300.h / 2 - 0x3C, D_L39_00240300.h / 2 - 0x28, D_L39_00240300.w / 2 - hw, D_L39_00240300.w / 2 + hw, 0x33, 0x331465B7);
        func_L01_00436020(0x33, 0x332299DE, (f32)(D_L39_00240300.h / 2 - 0x3C), (f32)(D_L39_00240300.h / 2 - 0x28), (f32)(D_L39_00240300.w / 2 - hw), (f32)(D_L39_00240300.w / 2 + hw));
        shadow = 2.0f;
        text_0066FF08((f32)(D_L39_00240300.w / 2), (f32)(D_L39_00240300.h / 2 - 0x3A), color, buf, shadow);
    }
    func_0038E150(saved);
    return 0;
}
/* localdecomp:end func_L39_0066FF08 */
