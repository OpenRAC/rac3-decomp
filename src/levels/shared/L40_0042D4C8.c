#include "common.h"

/* localdecomp:start func_L40_0042D4C8 */
extern u8 D_L40_0039FE00[];
__asm__(".extern D_L40_00247940, 4");
__asm__(".extern D_L40_00247944, 4");
__asm__(".extern D_L40_00247948, 4");
extern s32 D_L40_00247940;
extern s32 D_L40_00247944;
extern s32 D_L40_00247948;
extern void func_L01_0039AEB8(void *, s32, s32, s32, f32, f32, f32, s32, s32);

void func_L40_0042D4C8(void) {
    func_L01_0039AEB8(D_L40_0039FE00, 0x32, 0x32, 10, 0.07f, 0.15f, 0.2f, D_L40_00247940, D_L40_00247944);
    func_L01_0039AEB8(D_L40_0039FE00 + 0xA0, 15, 15, 10, 0.03f, 0.09f, 0.2f, D_L40_00247940, D_L40_00247948);
    func_L01_0039AEB8(D_L40_0039FE00 + 0x140, 15, 15, 10, 0.03f, 0.09f, 0.2f, D_L40_00247940, D_L40_00247948);
    func_L01_0039AEB8(D_L40_0039FE00 + 0x1E0, 15, 15, 10, 0.03f, 0.09f, 0.2f, D_L40_00247940, D_L40_00247948);
}
/* localdecomp:end func_L40_0042D4C8 */

/* localdecomp:start func_L40_0042D5D8 */
#include "vu0.h"

extern vu0_v4 D_L40_00249F40;
extern u8 D_L40_0029AF58[];
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L39_005B4468(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L40_0042D5D8(vu0_v4 *pos) {
    vu0_v4 dir;
    vu0_v4 vel;
    vu0_v4 at;
    vu0_v4 pt;
    f32 heading;
    f32 speed;
    f32 size;
    f32 tilt;
    f32 yaw;
    s32 n;
    s32 i;
    u8 *q;
    u8 *data;
    s32 alpha = 0x7F;
    s32 col;

    vec_sub_ab(&dir, &D_L40_00249F40, pos);
    heading = func_0038D160(dir.x, dir.y);
    for (i = 0; i < 20; i++) {
        u8 *tbl = D_L40_0029AF58;
        col = (alpha << 24) | 0xFF8040;
        speed = func_L39_005B4410(0.2f, 3.0f);
        qzero(&at);
        at.z = -1.0f;
        func_0038CE20(&vel, &at, -(speed * 0.020000001f));  /* 0x3CA3D70B: PAL's 50 Hz frame step (NTSC-U's twin has 1/60) */
        n = func_L39_005B4468(1.0f, 2.0f);
        size = func_L39_005B4410(0.3f, 0.75f) * 210000.0f;
        pt.x = pos->x + func_L39_005B4468(0.0f, 0.2f);
        pt.y = pos->y + func_L39_005B4468(0.0f, 0.2f);
        pt.z = pos->z + func_L39_005B4468(0.0f, 0.2f);
        q = func_L01_004669B0(&pt, 0.0f, 1.0f, 1.01f, size, n, &vel, 0x7F202020, 0);
        if (q != 0) {
            q[3] = 0x44;
            *(s16 *)(q + 0xA) = 0x4B;
            q[9] = 0x44;
            data = q + 0x20;
            *(f32 *)(data + 0x1C) = 4.0f;
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x30;
            data[0xB] = q[0xA];
        }
        speed = func_L39_005B4410(1.0f, 2.0f);
        tilt = func_L39_005B4410(0.0f, 1.3962634f);
        yaw = func_0038DAB8(heading, func_L39_005B4468(0.0f, 1.3962634f));
        func_00382760(&vel, speed * 0.020000001f, yaw, tilt);  /* 0x3CA3D70B: PAL's 50 Hz frame step (NTSC-U's twin has 1/60) */
        pt.x = pos->x + func_L39_005B4468(0.0f, 0.1f);
        pt.y = pos->y + func_L39_005B4468(0.0f, 0.1f);
        pt.z = pos->z + func_L39_005B4468(0.0f, 0.1f);
        q = func_L01_0046A610(&pt, &vel, 0x19, alpha, col, n, func_L39_005B4410(0.25f, 0.7f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[2] = (*(u8 **)(tbl + 0x184))[6];
        }
    }
}
/* localdecomp:end func_L40_0042D5D8 */
