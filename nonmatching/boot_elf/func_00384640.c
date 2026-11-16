/* PAL near miss (Codex wave 10): near miss: 119 words differ with the file's flags.
 * Worker's note: Best 116 diff w517/func_00384640.v3.log with --divs 0,2; default assembler puts 50.333332 and radians constant in literal pool vs retail inline constants; reset/exit branches also differ; exact existing func_0038D348(s32,s32,f32) respected
 */
#include "common.h"
/* localdecomp:start func_00384640 */
#include "vu0.h"
typedef struct { f32 strength, value; s32 timer, duration; } Shake_00384640;
extern S_00222500_0037E7D8 D_00222480[];
extern f32 D_001D57B4;
void func_00384640(s32 player, Shake_00384640 *shake, s32 mode) {
    extern void func_0038CEB0(s32 *);
    extern f32 func_0038DF28(f32);
    extern f32 func_0038D478(f32);
    extern f32 func_0038D490(f32);
    extern void func_0038D348(s32, s32, f32);
    extern void func_003C50A0(void *, void *, f32);
    extern void func_0038DBF0(void *, void *);
    extern void func_0038D9D0(void *, void *, void *);
    vu0_v4 v;
    vu0_v4 matrix[3];
    u8 *entry = (u8 *)&D_00222480[player];
    f32 ratio, cube, elapsed, fade, angle;
    if (*(u8 **)(entry + 0x50) && *(s16 *)(*(u8 **)(entry + 0x50) + 0x86) == 6) {
        shake->timer = shake->duration = 0;
        goto done;
    }
    if (shake->timer == 0) {
        shake->duration = 0;
        goto done;
    }
    if (shake->duration < shake->timer) shake->duration = shake->timer;
    func_0038CEB0(&shake->timer);
    ratio = (f32)shake->timer / (f32)shake->duration;
    switch (mode) {
    case 0:
        shake->value = shake->strength * func_0038D478(func_0038DF28((f32)shake->timer * 2.0f)) * ratio * ratio;
        func_0038D348((s32)&v, (s32)(entry + 0x3A0), shake->value);
        vec_add_ab(entry, entry, &v);
        break;
    case 1:
        shake->value = shake->strength * func_0038D478(func_0038DF28((f32)shake->timer * 2.0f)) * ratio * ratio;
        func_0038D348((s32)&v, (s32)(entry + 0x380), shake->value);
        vec_add_ab(entry, entry, &v);
        break;
    case 2:
        cube = ratio * ratio * ratio;
        elapsed = (f32)(shake->duration - shake->timer) / 50.33333206176758f;
        fade = elapsed * 6.0f;
        angle = D_001D57B4 * 0.01745329238474369f;
        if (fade > 1.0f) fade = 1.0f;
        shake->value = shake->strength * func_0038D490(func_0038DF28(elapsed * angle - angle * 8.0f)) * cube * fade;
        func_003C50A0(&v, entry + 0x380, shake->value);
        func_0038DBF0(&v, matrix);
        func_0038D9D0(entry + 0x380, matrix, entry + 0x380);
        break;
    }
done:
    ;
}
/* localdecomp:end func_00384640 */
