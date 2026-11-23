#include "common.h"

/* localdecomp:start func_L32_0039F828 */
#include "vu0.h"
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L32_001DE480;
__asm__(".extern D_L32_001DE480, 4");
extern f32 D_L32_001DE484;
__asm__(".extern D_L32_001DE484, 4");
extern f32 D_L32_001DE488;
__asm__(".extern D_L32_001DE488, 4");
extern f32 D_L32_001DE48C;
__asm__(".extern D_L32_001DE48C, 4");
extern s32 D_L32_001DE4A4;
__asm__(".extern D_L32_001DE4A4, 4");
extern s32 D_L32_001DE4A8;
__asm__(".extern D_L32_001DE4A8, 4");
extern s32 D_L32_001DE4D0;
__asm__(".extern D_L32_001DE4D0, 4");
extern s32 D_L32_001DE4D4;
__asm__(".extern D_L32_001DE4D4, 4");
extern f32 D_L32_001DE524;
__asm__(".extern D_L32_001DE524, 4");
extern f32 D_L32_001DE528;
__asm__(".extern D_L32_001DE528, 4");
extern f32 D_L32_001DE53C;
__asm__(".extern D_L32_001DE53C, 4");
extern f32 D_L32_001DE558;
__asm__(".extern D_L32_001DE558, 4");
extern f32 D_L32_001DE55C;
__asm__(".extern D_L32_001DE55C, 4");
extern f32 D_L32_001DE560;
__asm__(".extern D_L32_001DE560, 4");
extern f32 D_L32_001DE564;
__asm__(".extern D_L32_001DE564, 4");
extern f32 D_L32_001DE574;
__asm__(".extern D_L32_001DE574, 4");
extern f32 D_L32_001DE578;
__asm__(".extern D_L32_001DE578, 4");
extern f32 D_L32_001DE57C;
__asm__(".extern D_L32_001DE57C, 4");
extern f32 D_L32_001DE580;
__asm__(".extern D_L32_001DE580, 4");

typedef int q_0039F828 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 v[2][2][32];
} T_0039F828;

typedef struct {
    q_0039F828 q0;
    q_0039F828 pos;
    u8 pad20[0x20];
    s32 f40;
    s32 f44;
    T_0039F828 *f48;
    s32 f4C;
    s32 f50;
    s32 pad54;
    s32 f58;
    f32 f5C;
    f32 f60;
    s32 fx64;
    s32 f68;
    f32 f6C;
    f32 f70;
    f32 f74;
    f32 f78;
    u8 pad7C[4];
    f32 a[32];
    f32 b[32];
    s32 f180;
} S_0039F828;

typedef struct {
    u8 pad0[0x24];
    f32 f24;
} U_0039F828;

typedef struct {
    u8 pad0[0x10];
    q_0039F828 pos;
    u8 pad20[4];
    U_0039F828 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    S_0039F828 *f68;
} O_0039F828;

void func_L32_0039F828(O_0039F828 *o, T_0039F828 *src) {
    S_0039F828 *s = o->f68;
    s32 i;
    f32 amp;
    f32 period;
    f32 t;
    f32 w;

    qzero(&s->q0);
    *(q_0039F828 *)&s->pos = o->pos;
    s->f40 = 0;
    s->f44 = 0;
    s->f50 = 0;
    s->f4C = 0;
    s->f58 = 0;
    s->f5C = func_003824E0(D_L32_001DE484, D_L32_001DE480);
    s->f60 = func_003824E0(D_L32_001DE48C, D_L32_001DE488);
    s->fx64 = func_00382498(D_L32_001DE4A8, D_L32_001DE4A4);
    s->f68 = func_00382498(D_L32_001DE4D4, D_L32_001DE4D0);
    s->f70 = func_003824E0(D_L32_001DE528, D_L32_001DE524);
    o->f2C = o->f24->f24 * s->f70;
    s->f6C = D_L32_001DE53C * s->f70;
    s->f74 = func_003824E0(D_L32_001DE578, D_L32_001DE574);
    s->f78 = func_003824E0(D_L32_001DE580, D_L32_001DE57C);
    s->f48 = src;
    if (src != 0) {
        amp = func_003824E0(D_L32_001DE55C / D_L32_001DE558, 1.0f);
        period = func_003824E0(D_L32_001DE564, D_L32_001DE560) * 32.0f;
        for (i = 0; i < 32; i++) {
            t = (f32)i / period;
            t = t - cvtsw_asm(cvtws_asm(t));
            w = amp * 0.5f * func_0038D0B0(func_0038DB48(t * 6.2831855f)) + 0.5f;
            s->a[i] = func_003C4088(src->v[0][0][i], src->v[1][0][i], w);
            s->b[i] = func_003C4088(src->v[0][1][i], src->v[1][1][i], w);
        }
    }
    s->f180 = 0;
}
/* localdecomp:end func_L32_0039F828 */
