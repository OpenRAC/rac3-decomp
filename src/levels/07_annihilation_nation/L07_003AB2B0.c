#include "common.h"

/* localdecomp:start func_L07_003AB2B0 */
#include "vu0.h"

typedef struct {
    u8 pad[0x18];
    u8 kind;
    u8 flags;
    u16 id;
    u8 rest[0x14];
} Hit_003AB2B0;

typedef struct {
    u8 pad[0x18];
    u8 *object;
    s32 result;
    vu0_v4 position;
} HitResult_003AB2B0;

extern HitResult_003AB2B0 D_L07_001E8C00;
extern u8 *D_001A71A0[];

void func_L07_003AB2B0(void *arg) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_004CB320(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_004CB358(void);
    extern f32 func_0038CF00(void *, void *);
    vu0_v4 start, end, direction;
    Hit_003AB2B0 hit;
    u8 *obj = arg;
    u8 *state = *(u8 **)(obj + 0x68);
    s32 result;
    f32 x, y;

    func_003C2F58(obj, state[0x533], &start.x);
    if (*(f32 *)(state + 0x538) == 1.0f) {
        *(vu0_q *)&end = *(vu0_q *)(state + 0x520);
    } else {
        vec_sub_ba(&end, state + 0x520, &start);
        func_0038CE20(&end, &end, *(f32 *)(state + 0x538));
        vec_add_ab(&end, &start, &end);
    }
    vec_sub_ab(&direction, &end, &start);
    direction.z = 0.0f;
    func_0038CF68(&direction, &direction, 1.0f);
    direction.z = 1.0f;
    direction.w = 5627.9248046875f;
    func_L01_00446760(&hit, obj, 0x10001, &direction, (f32)state[0x44]);
    hit.kind = 5;
    hit.id = *(u16 *)(obj + 0xAA);
    hit.flags = 2;
    func_L01_004CB320();
    result = func_003D3CB0(&start, &end, 0, obj, &hit);
    if (result != 0) {
        u8 *object = D_L07_001E8C00.object;
        if (object != 0 && *(s16 *)(object + 0xAA) == 0x186D && object[0x20] != 2 && object[0x20] != 5) {
            object[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (result != 0) {
        x = func_0038CF00(&start, &D_L07_001E8C00.position);
        y = func_0038CF00(&start, state + 0x520);
        x /= y;
        *(f32 *)(state + 0x538) = x;
        if (x > 1.0f) {
            *(f32 *)(state + 0x538) = 1.0f;
        }
        if (D_L07_001E8C00.object == D_001A71A0[0]) {
            state[0x532] = 1;
        }
    }
}
/* localdecomp:end func_L07_003AB2B0 */
