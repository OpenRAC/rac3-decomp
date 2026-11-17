#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_003BCF38 */
extern f32 func_0038D0B0(f32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
void func_L22_003BCF38(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    s32 t;
    f32 s;
    if (*(s32 *)(st + 0x178) > 0) {
        t = *(s32 *)(st + 0x170) + 1;
        *(s32 *)(st + 0x170) = t;
        if (t >= 0x19) {
            *(s32 *)(st + 0x178) = -1;
        }
    } else {
        t = *(s32 *)(st + 0x170) - 1;
        *(s32 *)(st + 0x170) = t;
        if (t <= 0) {
            *(s32 *)(st + 0x178) = 1;
        }
    }
    s = func_0038D0B0((f32)*(s32 *)(st + 0x170) * 3.14159274f / 60.0f);
    func_0038AE20(0x7F, 0, 0, (s32)(s * 0.85000002f * 16.0f));
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L22_003BCF38 */

/* localdecomp:start func_L22_003BCFF8 */
__asm__(".extern D_L22_001DE6C4, 4");
__asm__(".extern D_L22_001DE6C8, 4");
__asm__(".extern D_L22_001DE6CC, 4");
__asm__(".extern D_L22_001DE6D0, 4");
__asm__(".extern D_L22_001DE6D4, 4");
extern f32 D_L22_001DE6C4;
extern s32 D_L22_001DE6C8;
extern f32 D_L22_001DE6CC;
extern s32 D_L22_001DE6D0;
extern f32 D_L22_001DE6D4;
extern s32 D_001A71A0[];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L22_003BCF38(u8 *);
extern void func_L22_003BD410(void *);
extern s32 func_L01_004561B8(void *);
extern void func_003C3938(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L22_00344050(void *, void *, void *, s32, s32, s32, f32, f32);
typedef struct { u8 pad[0x134]; s32 x134; } S_3BCFF8;
void func_L22_003BCFF8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    vu0_v4 m[4];
    vu0_v4 p2, p1, d;
    u8 *hero;
    if (*(s32 *)(st + 0x138) != -1 && *(s32 *)(st + 0x130) == 0) {
        hero = D_001A4C60;
        if (func_00382380(hero, *(s32 *)(st + 0x138), 0) != 0 && hero[0x2564] != 3) {
            *(s32 *)(st + 0x170) = 0;
            *(s32 *)(st + 0x178) = 1;
            *(s32 *)(st + 0x130) = 1;
        }
    }
    if (*(s32 *)(st + 0x130) != 0 && *(s32 *)(st + 0x138) != -1) {
        if (func_00382380(D_001A4C60, *(s32 *)(st + 0x138), 0) == 0) {
            *(s32 *)(st + 0x130) = 0;
            *(s32 *)(st + 0x13C) = 0;
        }
    }
    if (*(s32 *)(st + 0x130) != 0 || *(s32 *)(st + 0x170) != 0) {
        if (*(s32 *)(st + 0x130) == 0 && *(s32 *)(st + 0x178) != -1) *(s32 *)(st + 0x178) = -1;
        func_L01_00404808(func_L22_003BCF38, a0);
    }
    switch (a0[0x20]) {
    case 0:
        func_L22_003BD410(a0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0) func_003C3938(a0, 0, 0);
        if (*(s32 *)(st + 0x130) != 0) func_L01_004450F0(a0, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0 && a0[0x43] != 1) func_003C3A10(a0, 1, 0, 5);
        if (*(s32 *)(st + 0x130) == 0) func_L01_004450F0(a0, 5, -1);
        if (a0[0x60] & 2) {
            func_003C3938(a0, 2, 0);
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            ((S_3BCFF8 *)st)->x134 = 0x6E;
            if (D_001D545C == 0x16 && *(s32 *)(st + 0x13C) != 0) ((S_3BCFF8 *)st)->x134 = 0x32;
            func_003C3938(a0, 2, 0);
        }
        if (*(s32 *)(st + 0x130) == 0) func_L01_004450F0(a0, 5, -1);
        {
        u8 *h = D_001A4BE0;
        *(f32 *)(st + 0x118) = func_0038D160(*(f32 *)(h + 0x80) - *(f32 *)(a0 + 0x10), *(f32 *)(h + 0x84) - *(f32 *)(a0 + 0x14)) - (*(f32 *)(a0 + 0xF8) - 1.5707964f);
        }
        func_L01_0044E850(a0, st + 0xB0, 0, 0.043200001f, 0.43200004f);
        if (func_0038CAD0(st + 0x134) != 0) func_L01_004450F0(a0, 4, -1);
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(st + 0x13C) = 1;
            if (a0[0x43] != 3) func_003C3A10(a0, 3, 0, 5);
            func_003C2EC0(a0, 1, m);
            func_0038CF68(&p1, &m[1], -2.0f);
            vec_add_ba(&p1, &p1, &m[3]);
            func_0038CF68(&p2, &m[1], -120.0f);
            vec_add_ba(&p2, &p2, &m[3]);
            vec_sub_ab(&d, &p2, &m[3]);
            func_0038CF68(&d, &d, D_L22_001DE6C4);
            func_L22_00344050(a0, &m[3], &d, D_L22_001DE6C8, D_L22_001DE6D0, D_001A71A0[0], D_L22_001DE6D4, D_L22_001DE6CC);
        }
        if (a0[0x60] & 2) func_L01_004450F0(a0, 3, -1);
        break;
    case 5:
        if (func_L01_004561B8(a0) != 0 && a0[0x43] != 4) func_003C3A10(a0, 4, 0, 5);
        if (*(s32 *)(st + 0x130) != 0) func_L01_004450F0(a0, 2, -1);
        if (a0[0x60] & 2) func_L01_004450F0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L22_003BCFF8 */

/* localdecomp:start func_L22_003BD410 */
void func_0038CB78(void *, s32, s32);
void func_003C2F58(void *, s32, void *);
void func_L01_004513A8(s32, void *, s32);
extern f32 D_L22_001DE6C0;
__asm__(".extern D_L22_001DE6C0, 4");

void func_L22_003BD410(void *arg0) {
    s32 temp_a0;
    void *temp_s1;

    temp_a0 = arg0 + 0x10;
    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)temp_s1 + 0x130) = 0;
    func_L01_004513A8(temp_a0, arg0, temp_a0);
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 0x4000);
    func_003C2F58(arg0, 1, temp_s1 + 0x160);
    *(f32 *)((u8 *)temp_s1 + 0x168) = (f32) ((*(f32 *)((u8 *)temp_s1 + 0x168)) + D_L22_001DE6C0);
    func_0038CB78(temp_s1 + 0x30, 0, 0x80);
    func_0038CB78(temp_s1 + 0xB0, 0, 0x80);
}
/* localdecomp:end func_L22_003BD410 */
