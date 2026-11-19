/* functional: high. Draft read block by block against asm; all constants and gp offsets agree. VU0 inline asm only. */
#include "common.h"
/* localdecomp:start func_L01_00382890 */
#include "vu0.h"
#include "structs/weapon.h"
typedef struct {
    u8 pad0[0x110]; vu0_v4 velocity;
    u8 pad120[0x360-0x120]; s32 moving;
    u8 pad364[0x6C0-0x364]; vu0_v4 axes[2];
} State_00382890;
extern State_00382890 D_001A4BE0_00382890;
extern vu0_v4 D_L01_001DDCE0;
extern f32 D_L01_001DDD4C;
extern f32 D_L01_001DDD50;
extern s32 D_L01_001DDD54;
extern f32 D_L01_001DDD60;
extern f32 D_L01_001DDD64;
extern f32 D_L01_001DDD68;
extern f32 D_L01_001DDD6C;
extern f32 D_L01_001DDD70;
extern f32 D_L01_001DDD74;
extern u8 *D_L01_00221098[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
void func_L01_00382890(u8 *obj) {
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CE20(vu0_q *, vu0_q *, f32);
    extern u8 *func_L01_004660F8(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 matrix;
    vu0_v4 direction;
    vu0_v4 base;
    vu0_v4 position;
    vu0_v4 velocity;
    vu0_v4 start;
    vu0_v4 extra;
    vu0_v4 *out = &start;
    u8 *particle;
    u8 *data;
    s32 i, n;
    f32 angle;
    *(vu0_q *)&base = 0;
    base.x = 0.3f; base.y = -1.0f; base.w = 1.0f;
    func_0038D000(&position, &D_L01_001DDCE0, obj + 0xC0);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "+m"(position) : "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
    obj[0xBC] = 5;
    func_0038D890(&base, &D_001A4BE0_00382890.axes[0], &D_001A4BE0_00382890.axes[1], 0.3490658402442932f);
    *(vu0_q *)&direction = *(vu0_q *)&base;
    angle = 0;
    for (i = 9; i >= 0; i--) {
        angle = func_0038DAB8(angle, func_003824E0(0.0f, 0.6283185482025146f));
        func_0038CE20((vu0_q *)&velocity, (vu0_q *)&direction, func_003824E0(0.12000000476837158f, 0.36000001430511475f));
        particle = func_L01_004660F8(&position, &velocity);
        if (particle) {
            func_0038CE20((vu0_q *)&velocity, (vu0_q *)&direction, 0.75f);
            data = particle + 0x30;
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(vu0_v4 *)(particle + 0x10)) : "m"(position), "m"(velocity) : "vf1", "vf2");
            *(vu0_q *)(particle + 0x20) = *(vu0_q *)&position;
            *(f32 *)(data + 0xC) = 2.0f;
            *(s32 *)(particle + 0xC) = 0x307F7F7F;
            *(f32 *)(particle + 0x1C) = 0.05f;
            *(f32 *)(particle + 0x2C) = 0.5f;
            *(s32 *)(particle + 4) = 0x307F7F7F;
        }
        if (fabs_asm(angle) > 9.999999747378752e-06f) {
            func_003C4840(&matrix, &D_001A4BE0_00382890.axes[0], angle);
            func_0038D850(&direction, &base, &matrix);
        }
    }
    func_0038D890(&base, &D_001A4BE0_00382890.axes[0], &D_001A4BE0_00382890.axes[1], D_L01_001DDD4C * 0.01745329238474369f);
    *(vu0_q *)&direction = *(vu0_q *)&base;
    qzero(&extra);
    if (D_001A4BE0_00382890.moving) func_0038CE20((vu0_q *)&extra, (vu0_q *)&D_001A4BE0_00382890.velocity, 1.7f);
    angle = 0;
    for (i = 9; i >= 0; i--) {
        angle = func_0038DAB8(angle, func_003824E0(0.0f, 0.6283185482025146f));
        func_0038CE20((vu0_q *)&velocity, (vu0_q *)&direction, func_003824E0(D_L01_001DDD64 * 0.020000001415610313f, D_L01_001DDD68 * 0.020000001415610313f));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %0\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "+m"(velocity) : "m"(extra) : "vf1", "vf2");
        n = func_L01_00443A18(1.0f, 2.0f);
        start.x = position.x + func_L01_00443A18(0.0f, D_L01_001DDD50);
        start.y = position.y + func_L01_00443A18(0.0f, D_L01_001DDD50);
        start.z = position.z + func_L01_00443A18(0.0f, D_L01_001DDD50);
        { f32 scale = func_003824E0(D_L01_001DDD6C, D_L01_001DDD70);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(start) : "m"(velocity) : "vf1", "vf2");
        particle = func_L01_0046A610(out, &velocity, 10, D_L01_001DDD54, 0x505070, n, scale * 210000.0f, D_L01_001DDD74, D_L01_001DDD60, 0.0f, 0.0f); }
        if (particle) {
            u8 *texture = D_L01_00221098[0x16C/4];
            if (D_L01_002C5600[D_001425C0[0x97]].level == 0) particle[2] = texture[1];
            else particle[2] = texture[0];
        }
        if (fabs_asm(angle) > 9.999999747378752e-06f) {
            func_003C4840(&matrix, &D_001A4BE0_00382890.axes[0], angle);
            func_0038D850(&direction, &base, &matrix);
        }
    }
}
/* localdecomp:end func_L01_00382890 */
