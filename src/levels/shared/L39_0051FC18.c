#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* localdecomp:start func_L39_0051FC18 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D278(void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

u8 *func_L39_0051FC18(u128_t *pos, u128_t *dir, s32 a2, u8 *a3)
{
    Local_51FC18 local;
    u8 *o = func_003C24B0(0x1091, 0x80);
    u8 *data = *(u8 **)(o + 0x68);
    u8 *axis;
    f32 half;
    s16 header;

    if (o != 0) {
        header = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        o[0x20] = 0;
        *(s16 *)(o + 0x32) = header;
        o[0x30] = header;
        *(u128_t *)(o + 0x10) = *pos;
        *(u128_t *)data = *dir;
        *(s32 *)(data + 0x2C) = a2;
        *(u8 **)(data + 0x30) = a3;
        if (a3 != 0)
            func_0038D308((o + 0xC0), *(u8 **)(a3 + 0x2524) + 0xF0);
        else
            func_0038D278((o + 0xC0));
        func_L39_005BC330(o + 0x10, &local.v2, 1);
        axis = o + 0xE0;
        func_0038CF68(&local.v2, &local.v2, 1.0f);
        func_0038CE90(&local.v1, axis, &local.v2);
        half = func_0038CE68(axis, &local.v2) * 0.5f;
        func_0038CE20(&local.v0, &local.v1, func_0038D0B0(half));
        *(f32 *)((u8 *)&local.v0 + 12) = func_0038D098(half);
        func_0038D810(&local.v0, local.matrix);
        func_0038D5F0((o + 0xC0), local.matrix, (o + 0xC0));
    }
    return o;
}
/* localdecomp:end func_L39_0051FC18 */
