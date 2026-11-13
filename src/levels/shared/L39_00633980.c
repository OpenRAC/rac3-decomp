#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

typedef struct { u8 pad0[0xFB0]; f32 f0FB0; u8 pad1[0x2468 - 0xFB4]; f32 f2468; } S_00633160;

typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;

/* declared by functions of L39_00632888.c, which this file was cut from */
extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D160(f32 x, f32 y);

/* localdecomp:start func_L39_00633980 */
#include "vu0.h"

extern void func_L39_00633888(void *, Vec4 *);

void func_L39_00633980(void *a) {
    Vec4 v;

    qzero(&v);
    v.f[2] = 0.6f;
    func_L39_00633888(a, &v);
}
/* localdecomp:end func_L39_00633980 */

INCLUDE_ASM("asm/levels", func_L39_006339B0);

/* localdecomp:start func_L39_00633C78 */
extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004485E0(s32, f32, f32);

void func_L39_00633C78(u8 *a, s32 b, s32 c) {
    f32 v[4];

    ((void (*)(f32 *, s32, void *))func_0038D028)(v, b, a + 96);
    func_L01_004485E0(c, func_0038D160(v[0], v[1]), 0.0f);
}
/* localdecomp:end func_L39_00633C78 */
