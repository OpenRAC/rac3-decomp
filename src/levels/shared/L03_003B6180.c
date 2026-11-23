#include "common.h"

/* localdecomp:start func_L03_003B6180 */
typedef struct {
    u8 pad0[0x24];
    s32 state;
    u8 pad28[0xC];
    f32 angle;
    f32 f38;
    f32 f3C;
} B6180Data_003B6180;

typedef struct {
    u8 pad0[0x10];
    u8 pos[0x58];
    B6180Data_003B6180 *data;
} B6180Obj_003B6180;

extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L03_0034B248_003B6180(void *, void *);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern u8 D_L03_001E1DC8_003B6180[];
extern f32 D_L03_001DE9FC_003B6180;
__asm__(".extern D_L03_001DE9FC_003B6180, 4");
extern f32 D_L03_001DEA00_003B6180;
__asm__(".extern D_L03_001DEA00_003B6180, 4");
extern f32 D_L03_001DEA04_003B6180;
__asm__(".extern D_L03_001DEA04_003B6180, 4");
extern s32 D_L03_001DEA10_003B6180;
__asm__(".extern D_L03_001DEA10_003B6180, 4");
extern s32 D_L03_001DEA14_003B6180;
__asm__(".extern D_L03_001DEA14_003B6180, 4");
extern s32 D_L03_001DEA18_003B6180;
__asm__(".extern D_L03_001DEA18_003B6180, 4");
extern s32 D_L03_001DEA1C_003B6180;
__asm__(".extern D_L03_001DEA1C_003B6180, 4");
extern f32 D_L03_001DEA20_003B6180;
__asm__(".extern D_L03_001DEA20_003B6180, 4");
extern s32 D_L03_001DEA24_003B6180;
__asm__(".extern D_L03_001DEA24_003B6180, 4");
extern s32 D_L03_001DEA28_003B6180;
__asm__(".extern D_L03_001DEA28_003B6180, 4");
extern s32 D_L03_001DEA2C_003B6180;
__asm__(".extern D_L03_001DEA2C_003B6180, 4");

void func_L03_003B6180(B6180Obj_003B6180 *obj)
{
    B6180Data_003B6180 *p = obj->data;
    f32 roll;
    f32 half;

    roll = func_0038DAB8(0.0f, p->angle * 0.017453292f);
    if (p->state == 0 || p->state == 3 || p->state == 6) {
        func_L03_0034B248_003B6180(D_L03_001E1DC8_003B6180, obj);
        if (p->state == 6) {
            if (func_003C4138(&p->f38, p->f3C, D_L03_001DEA04_003B6180) == 0.0f) {
                if (p->f3C == D_L03_001DE9FC_003B6180) {
                    p->f3C = D_L03_001DEA00_003B6180;
                } else {
                    p->f3C = D_L03_001DE9FC_003B6180;
                }
            }
            func_003D9508(obj->pos, D_L03_001DEA28_003B6180, D_L03_001DEA2C_003B6180, 1, p->f38, 0.0f, -roll);
            func_003D9508(obj->pos, D_L03_001DEA24_003B6180, D_L03_001DEA2C_003B6180, 1, p->f38 * 0.9f, 0.0f, roll);
        }
    } else {
        half = D_L03_001DEA20_003B6180;
        func_L03_0034B248_003B6180(D_L03_001E1DC8_003B6180, obj);
        func_003D9508(obj->pos, D_L03_001DEA1C_003B6180, D_L03_001DEA14_003B6180, 1, half, 0.0f, -roll);
        func_003D9508(obj->pos, D_L03_001DEA18_003B6180, D_L03_001DEA10_003B6180, 1, half, 0.0f, roll);
    }
    p->angle += 1.0f;
    if (359.0f < p->angle) {
        p->angle = 0.0f;
    } else if (p->angle < 0.0f) {
        p->angle = 359.0f;
    }
}
/* localdecomp:end func_L03_003B6180 */

INCLUDE_ASM("asm/levels", func_L03_003B6370);

/* localdecomp:start func_L03_003B6740 */
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L03_003B6740(vu0_v4 *position, s32 count, s32 color1, s32 color2) {
    vu0_v4 point;
    vu0_v4 velocity;
    vu0_v4 *pt = &point;
    f32 size;
    s32 spin;
    s32 i;
    u8 *particle;

    point = *position;
    for (i = 0; i < count; i++) {
        size = func_003824E0(1.0f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) spin--;
        func_L01_00443B88(&velocity, 0.05f, 0.25f);
        particle = func_L01_0046B458(pt, 0x11, size * 0.1f, size, color1, 0, spin, &velocity, 0.0028800003f, 0);
        if (particle) particle[9] = 0x74;
        particle = func_L01_0046B458(pt, 0x11, size * 0.07f, size * 0.7f, color2, 1, -spin, &velocity, 0.0028800003f, 0);
        if (particle) particle[9] = 0x74;
    }
}
/* localdecomp:end func_L03_003B6740 */
