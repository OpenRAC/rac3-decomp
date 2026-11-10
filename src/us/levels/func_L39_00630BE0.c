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

extern void fe_func_0038D328(Vec4 *, Vec4 *);
extern void fe_func_0038D640(Vec4 *, Vec4 *, Vec4 *);
extern void fe_func_003C48A8(Vec4 *, Vec4 *);
extern void fe_func_0038D028(Vec4 *out, void *a, void *b);
extern f32 fe_func_0038D160(f32 x, f32 y);
/* localdecomp:start func_L39_00630BE0 */
extern void func_L39_00630AC0(View_00633428 *, s32, f32, f32, f32);

void func_L39_00630BE0(View_00633428 *v)
{
    f32 speed = v->speed;
    f32 first;
    f32 second;
    f32 third;
    s32 kind;
    if (speed == 1.0f) {
        first = 0.0219999999f;
    } else {
        first = speed * 0.0199999996f;
        if (first > 0.0219999999f)
            first = 0.0219999999f;
        if (first < 0.00999999978f)
            first = 0.00999999978f;
    }
    if (v->speed == 1.0f) {
        third = 0.093084231f;
    } else {
        third = speed * 0.063995406f;
        if (third > 0.093084231f)
            third = 0.093084231f;
        if (third < 0.031997703f)
            third = 0.031997703f;
    }
    second = 0.270000011f;
    if (v->alternate) {
        first = 0.0350000001f;
        third = 0.194895104f;
    }
    kind = -1;
    if (v->mode == 2)
        kind = v->kind;
    if (kind == 1 || kind == 9) {
        if (v->special && !v->alternate) {
            if (speed > 0.95f) {
                first = 0.0170000009f;
                second = 0.180000007f;
                third = 0.14544411f;
            } else {
                first = speed * 0.00899999961f;
                second = 0.150000006f;
                third = speed * 0.0785398185f;
            }
        }
    }
    func_L39_00630AC0(v, 0, first, second, third);
}
/* localdecomp:end func_L39_00630BE0 */
