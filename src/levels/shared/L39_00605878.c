#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00605878);

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
