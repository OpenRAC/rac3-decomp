#include "common.h"

/* localdecomp:start func_L39_0058A5D0 */
__asm__(".extern D_L39_0024B9C8_b, 4");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024B9C8_b;
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern u8 D_1A3940[];
extern void func_003A92F0(s32);
extern s32 func_139E08(s32);
extern void func_003A9108(void);
extern void func_003A9150(void);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L39_005FCDF8(void);

void func_L39_0058A5D0(s32 arg0) {
    s32 i;
    s32 t;

    func_003A92F0(1);
    i = arg0 - 1;
    func_139E08(0);
    D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
    func_003A9108();

    while (i >= 0) {
        func_L39_00597E70();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A9440(1, (long)(0x80 - t) << 24);

        D_L39_0024CAD0[0] = 0x30000014;
        D_L39_0024CAD0[1] = (u32)D_1A3940;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000014;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;

        func_003A92F0(1);
        func_139E08(0);
        D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
        func_L39_005FCDF8();
        func_003A9150();
    }

    func_003A92F0(1);
    func_139E08(0);
    D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
    func_003A9108();
    func_L39_00597E70();
    func_00392350(1);
}
/* localdecomp:end func_L39_0058A5D0 */

/* localdecomp:start func_L39_0058A750 */
extern s32 D_L39_00240468;
extern s32 D_L39_0025CEF4[];
extern s32 D_L39_00241470;
extern u8 D_001A58BD[];
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0058A750(long, f32, s32, f32, s32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_L39_0058A750(void) {
    s32 col;
    f32 colf;
    f32 t;
    s32 save;

    if (D_L39_00240468 == 1) {
        col = 0x5A;
        t = (f32)(D_L39_0025CEF4[0] % 100) / 50.0f - 1.0f;
        if (D_001A58BD[0] != 0) {
            col = 0x30;
        }
        if (t < -1.0f) t = -1.0f;
        if (t > 1.0f) t = 1.0f;
        colf = (f32)col;
        col = func_0038DBD8((func_0038D098(t * 3.14159274f) + 1.0f) * 0.5f, 0x7FE0E0E0, 0x5F66CCFF);
        save = D_L39_00241470;
        func_0038E150(0);
        func_0038E7E8_0058A750(col, 480.0f, func_00381FF0(0x244), colf, -1, 1.0f, 1.0f, 2, 1, 0x80000000, 1.0f, 1.0f);
        func_0038E150(save);
    }
}
/* localdecomp:end func_L39_0058A750 */

INCLUDE_ASM("asm/levels", func_L39_0058A8B0);

/* localdecomp:start func_L39_0058ACE0 */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L39_0024B9E0_0058ACE0, 4");
extern s32 D_L39_0024B9E0_0058ACE0;
__asm__(".extern D_L39_0024CAD0_0058ACE0, 4");
extern u32 *D_L39_0024CAD0_0058ACE0;
extern s32 D_L39_0024B9DC;
extern s32 D_L39_0024B9E0;
extern s32 D_L39_0024B9E0_b;
extern u8 D_1A58BD __attribute__((section(".data")));
extern u128_t D_L39_00244420;
extern u128_t D_L39_00244430;
extern s32 D_L39_00240310;
extern s32 D_L39_00240314;
extern s32 D_L39_00240318;
extern s32 D_L39_0024031C;

void func_L39_0058ACE0(void) {
    s32 x;
    u32 *tmp;
    u32 *p;
    long *tmp2;
    long *q;
    long *n;
    long *q2;
    if (D_L39_0024B9DC != 0) {
        if (D_L39_0024B9E0_0058ACE0 < 0x34) {
            D_L39_0024B9E0_0058ACE0++;
        }
    } else {
        if (D_L39_0024B9E0 == 0) return;
        D_L39_0024B9E0_b = D_L39_0024B9E0 - 1;
    }
    x = D_L39_0024B9E0;
    if (x == 0) return;
    if (D_1A58BD != 0) return;
    D_L39_0024CAD0_0058ACE0[0] = 0x10000007;
    D_L39_0024CAD0[1] = 0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000007;
    p = D_L39_0024CAD0;
    D_L39_0024CAD0_b = p + 4;
    *(u128_t *)(p + 4) = D_L39_00244420;
    *(short *)D_L39_0024CAD0 = -0x7FFF;
    q2 = (long *)D_L39_0024CAD0;
    tmp2 = q2 + 2;
    n = tmp2;
    D_L39_0024CAD0_b = (u32 *)n;
    q2[2] = 0x104;
    n[1] = 0x80000000L;
    tmp = D_L39_0024CAD0;
    p = tmp;
    D_L39_0024CAD0_b = p + 4;
    *(u128_t *)(p + 4) = D_L39_00244430;
    *(short *)D_L39_0024CAD0 = -0x7FF8;
    q = (long *)D_L39_0024CAD0;
    n = q + 2;
    D_L39_0024CAD0_b = (u32 *)n;
    q[2] = (long)D_L39_00240310 | ((long)D_L39_00240314 << 16) | 0xFFFFF300000000L;
    n[1] = (long)D_L39_00240310 | ((long)(D_L39_00240314 + (x << 4)) << 16) | 0xFFFFF300000000L;
    n[2] = (long)D_L39_00240318 | ((long)D_L39_00240314 << 16) | 0xFFFFF300000000L;
    n[3] = (long)D_L39_00240318 | ((long)(D_L39_00240314 + (x << 4)) << 16) | 0xFFFFF300000000L;
    n[4] = (long)D_L39_00240318 | ((long)D_L39_0024031C << 16) | 0xFFFFF300000000L;
    n[5] = (long)D_L39_00240318 | ((long)(D_L39_0024031C - (x << 4)) << 16) | 0xFFFFF300000000L;
    n[6] = (long)D_L39_00240310 | ((long)D_L39_0024031C << 16) | 0xFFFFF300000000L;
    n[7] = (long)D_L39_00240310 | ((long)(D_L39_0024031C - (x << 4)) << 16) | 0xFFFFF300000000L;
    D_L39_0024CAD0_b = D_L39_0024CAD0 + 0x10;
}
/* localdecomp:end func_L39_0058ACE0 */
