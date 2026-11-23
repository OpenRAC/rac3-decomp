#include "common.h"

/* NTSC-U counterpart of func_00384640 (boot_elf). */
extern f32 func_U_0038D3C0(f32);
extern f32 func_U_0038D3D8(f32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_U_00222500[];
extern void func_U_0038D290(s32 a, s32 b, f32 x);
#include "vu0.h"
#include "vu0.h"
extern s32 func_U_0038CDF8(void *);

/* localdecomp:start func_U_00384620 */
#include "vu0.h"
typedef struct { f32 strength, value; s32 timer, duration; } Shake_00384640;
extern f32 D_U_001D57B4;
__asm__(".extern D_U_001D57B4, 4");
extern s32 func_U_0038CDF8(void *);
extern f32 func_U_0038DE70(f32);
extern void func_U_003C4F38_00384620(void *, void *, f32);
extern void func_U_0038DB38_00384620(void *, void *);
extern void func_U_0038D918_00384620(void *, void *, void *);
void func_U_00384620(s32 player, Shake_00384640 *shake, s32 mode) {
    vu0_v4 v;
    vu0_v4 matrix[3];
    u8 *entry = (u8 *)&D_U_00222500[player];
    f32 ratio, cube, elapsed, fade, angle;
    if (*(u8 **)(entry + 0x50) && *(s16 *)(*(u8 **)(entry + 0x50) + 0x86) == 6) {
        shake->timer = 0;
        shake->duration = 0;
    } else if (shake->timer != 0) {
        if (shake->duration < shake->timer) shake->duration = shake->timer;
        func_U_0038CDF8(&shake->timer);
        ratio = (f32)shake->timer / (f32)shake->duration;
        switch (mode) {
        case 0:
            shake->value = shake->strength * func_U_0038D3C0(func_U_0038DE70((f32)shake->timer * 2.0f)) * ratio * ratio;
            func_U_0038D290((s32)&v, (s32)(entry + 0x3A0), shake->value);
            vec_add_ab(entry, entry, &v);
            break;
        case 1:
            shake->value = shake->strength * func_U_0038D3C0(func_U_0038DE70((f32)shake->timer * 2.0f)) * ratio * ratio;
            func_U_0038D290((s32)&v, (s32)(entry + 0x380), shake->value);
            vec_add_ab(entry, entry, &v);
            break;
        case 2:
            cube = ratio * ratio * ratio;
            elapsed = (f32)(shake->duration - shake->timer) / 60.0f;
            fade = elapsed * 6.0f;
            angle = D_U_001D57B4 * 0.01745329238474369f;
            if (fade > 1.0f) fade = 1.0f;
            shake->value = shake->strength * func_U_0038D3D8(func_U_0038DE70(elapsed * angle - angle * 10.0f)) * cube * fade;
            func_U_003C4F38_00384620(&v, entry + 0x380, shake->value);
            func_U_0038DB38_00384620(&v, matrix);
            func_U_0038D918_00384620(entry + 0x380, matrix, entry + 0x380);
            break;
        }
    } else {
        shake->duration = 0;
    }
}
/* localdecomp:end func_U_00384620 */
