#include "common.h"

/* NTSC-U counterpart of func_L01_00466678 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
extern u32 D_L01_001DFBC0_004630C0;
extern s32 func_003883C8(u8 *);
#include "vu0.h"
#include "vu0.h"
typedef int s128_00462FD0 __attribute__((mode(TI)));
typedef struct {
    s128_00462FD0 v;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    f32 f1C;
} Sub_00462FD0;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00462FD0 f10;
    Sub_00462FD0 sub;
} Part_00462FD0;

/* localdecomp:start func_L01_004630C0 */
#include "vu0.h"
extern u32 D_L01_001DFBC0_004630C0;
void func_L01_004630C0(u8 *p) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern s32 func_L01_00444338_004630C0(s32, s32, f32);
    extern f32 func_0037E250(f32 low, f32 high);
    extern f32 func_00388770(void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_003886E8(void *, void *, f32);
    extern s32 func_0037E208(s32, s32);
    extern Part_00462FD0 *func_L01_00462FD0(s128_00462FD0 *, s128_00462FD0 *, s32, s32, s32, s32, f32);
    vu0_v4 old;
    vu0_v4 velocity;
    vu0_v4 random;
    u8 *v = p + 0x20;
    f32 ratio;
    if (func_003883C8(p + 0xA)) {
        func_003C7CE0(p);
        return;
    }
    ratio = 1.0f / *(s16 *)(v + 0x18);
    *(f32 *)(p + 0xC) = *(s16 *)(p + 0xA) * *(f32 *)(v + 0x1C) * ratio;
    *(s32 *)(p + 4) = func_L01_00444338_004630C0(*(s32 *)(v + 0x14), *(s32 *)(v + 0x10), *(s16 *)(p + 0xA) * ratio);
    vec_add_ab(p + 0x10, p + 0x10, v);
    *(f32 *)(v + 8) -= 0.001f;
    old = *(vu0_v4 *)(p + 0x10);
    if (*(s16 *)(v + 0x1A) && (D_L01_001DFBC0_004630C0 & 1)) {
        f32 speed;
        *(vu0_q *)&random = 0;
        random.x = func_0037E250(-1.0f, 1.0f);
        random.y = func_0037E250(-1.0f, 1.0f);
        random.z = func_0037E250(-1.0f, 1.0f);
        velocity = random;
        speed = func_00388770(v);
        func_00388830(&velocity, &velocity, speed * func_0037E250(0.21f, 0.25f));
        vec_add_ab(&velocity, &velocity, v);
        func_003886E8(&velocity, &velocity, func_0037E250(0.75f, 0.95f));
        func_L01_00462FD0((s128_00462FD0 *)(p + 0x10), (s128_00462FD0 *)&velocity, *(s32 *)(p + 4), *(s32 *)(v + 0x14), func_0037E208(15,20), 0, *(f32 *)(p + 0xC));
    } else {
        func_003886E8(v, v, 0.96f);
    }
}
/* localdecomp:end func_L01_004630C0 */
