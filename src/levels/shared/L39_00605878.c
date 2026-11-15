#include "common.h"

/* localdecomp:start func_L39_00605878 */
typedef struct {
    u32 rgb : 24;
    u32 alpha : 8;
} C_00605878;

typedef struct {
    u8 pad0[0x5C8];
    u32 col0;
    u8 pad5CC[0x2C];
    u32 col1;
    u8 pad5FC[0x68];
    u8 elem[8][0x30];
} S_00605878;

extern s32 *D_L39_00241120;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003AAED0(void *, f32, f32, f32, f32);
extern void func_003AAFF8(void *, f32, f32, f32, f32);
extern s32 *func_L39_006010E0(void *);

extern f32 D_001D9F60_sda;
__asm__(".extern D_001D9F60_sda, 4");
extern s32 D_001D9F64_sda;
__asm__(".extern D_001D9F64_sda, 4");
extern s32 D_001D9F68_sda;
__asm__(".extern D_001D9F68_sda, 4");
extern f32 D_001D9F6C_sda;
__asm__(".extern D_001D9F6C_sda, 4");
extern f32 D_001D9F70_sda;
__asm__(".extern D_001D9F70_sda, 4");
extern f32 D_001D9F74_sda;
__asm__(".extern D_001D9F74_sda, 4");
extern s32 D_001D9F78_sda;
__asm__(".extern D_001D9F78_sda, 4");
extern s32 D_001D9F7C_sda;
__asm__(".extern D_001D9F7C_sda, 4");
extern s32 D_001D9F80_sda;
__asm__(".extern D_001D9F80_sda, 4");
extern s32 D_001D9F84_sda;
__asm__(".extern D_001D9F84_sda, 4");
extern f32 D_001D9F88_sda;
__asm__(".extern D_001D9F88_sda, 4");
extern f32 D_001D9F8C_sda;
__asm__(".extern D_001D9F8C_sda, 4");
extern f32 D_001D9F90_sda;
__asm__(".extern D_001D9F90_sda, 4");
extern s32 D_001D9F94_sda;
__asm__(".extern D_001D9F94_sda, 4");
extern s32 D_001D9F98_sda;
__asm__(".extern D_001D9F98_sda, 4");
extern s32 D_001D9F9C_sda;
__asm__(".extern D_001D9F9C_sda, 4");

void func_L39_00605878(S_00605878 *arg0) {
    s32 i;
    s32 a;
    s32 b;
    s32 h;
    s32 d;
    f32 e;
    f32 f;
    f32 g;
    f32 ang;
    f32 x;
    f32 y;

    for (i = 0; i < 8; i++) {
        a = D_001D9F80_sda;
        if (*D_L39_00241120 >= 3) {
            D_001D9F60_sda = 18.0f;
            a = D_001D9F64_sda;
            b = D_001D9F68_sda;
            e = D_001D9F6C_sda;
            f = D_001D9F70_sda;
            g = D_001D9F74_sda;
            h = D_001D9F78_sda;
            d = D_001D9F7C_sda;
        } else {
            b = D_001D9F84_sda;
            e = D_001D9F88_sda;
            f = D_001D9F8C_sda;
            g = D_001D9F90_sda;
            h = D_001D9F94_sda;
            d = D_001D9F98_sda;
        }
        ang = func_0038DAB8((f32)i * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(h + a + (s32)(e * func_0038D098(ang) * f));
        y = (f32)(d + b + (s32)(e * func_0038D0B0(ang) * g));
        func_003AAED0(&arg0->elem[i], x, y, 0.0f, 0.0f);
        func_003AAFF8(&arg0->elem[i], D_001D9F60_sda, D_001D9F60_sda, 0.0f, 0.0f);
        ((C_00605878 *)func_L39_006010E0(&arg0->elem[i]))->rgb = D_001D9F9C_sda;
    }
    ((C_00605878 *)func_L39_006010E0(&arg0->col0))->rgb = 0x6EC8FF;
    ((C_00605878 *)func_L39_006010E0(&arg0->col1))->rgb = 0x6EC8FF;
}
/* localdecomp:end func_L39_00605878 */

/* localdecomp:start func_L39_00605AA8 */
/* from the frontend's func_003AEB48 (first half) */
extern s32 *D_L39_00241120;
extern void func_003AAF00(void *, s32);
extern void func_003AD590(void *, s32);
extern void func_003AD500(void *);
extern void func_003AAED0(void *, f32, f32, f32, f32);
extern void func_003AAFF8(void *, f32, f32, f32, f32);

void func_L39_00605AA8(u8 *arg0, s32 arg1) {
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u8 *s3;
    u8 *s4;
    u8 *s5;

    *(s32 *)(arg0 + 0xB38) = arg1;
    if (*(s32 *)(arg0 + 0xB3C) != 0) {
        *(s32 *)(arg0 + 0xB3C) = 0;
        func_003AAF00(arg0 + 0x628, 0);
        s4 = arg0 + 0x7E8;
        func_003AD590(s4, 1);
        s5 = arg0 + 0x870;
        func_003AD590(s5, 1);
        s3 = arg0 + 0x8F8;
        func_003AD590(s3, 1);
        s2 = arg0 + 0x980;
        func_003AD590(s2, 1);
        s1 = arg0 + 0xA08;
        func_003AD590(s1, 1);
        s0 = arg0 + 0xA90;
        func_003AD590(s0, 1);
        func_003AD500(s4);
        func_003AD500(s5);
        func_003AD500(s3);
        func_003AD500(s2);
        func_003AD500(s1);
        func_003AD500(s0);
        if (*D_L39_00241120 >= 3) {
            func_003AAED0(arg0 + 0x550, 89.0f, 245.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x58C, 89.0f, 245.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x5C8, 24.0f, 161.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x5F8, 23.0f, 161.0f, 0.0f, 0.0f);
            func_003AAFF8(arg0 + 0x5C8, 20.0f, 20.0f, 0.0f, 0.0f);
            func_003AAFF8(arg0 + 0x5F8, 20.0f, 20.0f, 0.0f, 0.0f);
        } else if (*D_L39_00241120 >= 2) {
            func_003AAED0(arg0 + 0x550, 78.0f, 256.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x58C, 78.0f, 256.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x5C8, 59.0f, 151.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x5F8, 59.0f, 151.0f, 0.0f, 0.0f);
            func_003AAFF8(arg0 + 0x5C8, 24.0f, 24.0f, 0.0f, 0.0f);
            func_003AAFF8(arg0 + 0x5F8, 24.0f, 24.0f, 0.0f, 0.0f);
        } else {
            func_003AAED0(arg0 + 0x550, 52.0f, 281.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x58C, 52.0f, 281.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x5C8, 24.0f, 278.0f, 0.0f, 0.0f);
            func_003AAED0(arg0 + 0x5F8, 23.0f, 277.0f, 0.0f, 0.0f);
            func_003AAFF8(arg0 + 0x5C8, 32.0f, 32.0f, 0.0f, 0.0f);
            func_003AAFF8(arg0 + 0x5F8, 32.0f, 32.0f, 0.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_L39_00605AA8 */
