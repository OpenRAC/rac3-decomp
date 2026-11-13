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
extern void func_0038D328(Vec4 *, Vec4 *);
extern void func_0038D028(Vec4 *out, void *a, void *b);
extern void func_0038D640(Vec4 *, Vec4 *, Vec4 *);
extern void func_003C48A8(Vec4 *, Vec4 *);

/* localdecomp:start func_L39_00633888 */
#include "vu0.h"
extern void func_0038D028(Vec4 *out, void *a, void *b);

void func_L39_00633888(void *p, Vec4 *v, f32 x, f32 y, f32 z) {
    u8 *a = p;
    Vec4 t0;
    Vec4 t1;
    Vec4 t2;
    Vec4 t3;
    Vec4 t4[4];
    Vec4 t6[4];
    Vec4 t7;

    t0 = *v;
    func_0038D328(t4, (Vec4 *)(a + 0xB0));
    func_0038D028(&t1, &t0, t4);
    t7.f[0] = x;
    t7.f[1] = y;
    t7.f[2] = z;
    func_0038D328(t6, &t7);
    func_0038D640(t4, t4, t6);
    func_0038D028(&t2, &t0, t4);
    vec_sub_ba(&t3, &t1, &t2);
    vec_add_ab(a + 0xA0, a + 0xA0, &t3);
    func_003C48A8(t4, (Vec4 *)(a + 0xB0));
}
/* localdecomp:end func_L39_00633888 */
