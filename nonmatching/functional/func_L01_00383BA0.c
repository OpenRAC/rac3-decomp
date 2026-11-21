/* functional: high. Draft verified vs asm. alpha==64 branch in draft is dead in retail too (alpha is 95 or 79). */
#include "common.h"
/* localdecomp:start func_L01_00383BA0 */
#include "vu0.h"
#include "structs/weapon.h"
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001A4EC0[];
extern u8 D_L01_001D66B0[];
extern u8 *D_L01_00221098[];
extern u8 *D_L01_0022116C[];
void func_L01_00383BA0(u8 *moby, vu0_q *first, vu0_q *second) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(vu0_q *, vu0_q *, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
    vu0_v4 start, end, velocity, point, step, smoke;
    u8 *vars;
    u8 *particle;
    s32 count, level, life, spin, color, alpha, n;
    f32 size, length;
    *(vu0_q *)&start = *first;
    *(vu0_q *)&end = *second;
    vars = *(u8 **)(moby + 0x68);
    size = func_003824E0(0.75f, 1.0f) * 210000.0f;
    length = func_0038CEA8(vars);
    count = (s32)(length / 0.1f);
    *(vu0_q *)&point = *(vu0_q *)&end;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(step) : "m"(start), "m"(end) : "vf1", "vf2");
    func_0038CF68(&step, &step, length / (f32)count);
    level = D_L01_002C5600[D_001425C0[0x87]].level;
    if (level >= 2) {
        count -= 5;
        size = func_003824E0(0.2f, 0.4f) * 210000.0f;
        if (count < 0) count = 0;
    }
    for (; count > 0; count--) {
        spin = (s32)func_L01_00443A18(1.0f, 3.0f);
        func_0038CE20((vu0_q *)&velocity, (vu0_q *)D_001A4EC0, -(func_003824E0(0.1f, 0.2f) * 0.020000001415610313f));
        life = func_00382498(12, 15);
        if (func_0013D3E0() & 2) {
            alpha = 95;
            color = 0x404040;
        } else {
            alpha = 79;
            color = 0x404050;
        }
        point.x += func_003824E0(0.35f, -0.35f);
        point.y += func_003824E0(0.35f, -0.35f);
        point.z += func_003824E0(0.35f, -0.35f);
        particle = func_L01_0046A610(&point, D_L01_001D66B0, (life * 5 + 2) / 6, alpha, color, spin, size, 10000.0f, 1.0f, 0.0f, 0.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(point) : "m"(point), "m"(step) : "vf1", "vf2");
        if (particle) {
            particle[2] = *D_L01_00221098[level < 2 ? 0x17 : 0x5B];
            if (alpha == 64) particle[3] = 72;
        }
    }
    if (*(s32 *)(vars + 0x30) < 50 && func_00382468(2)) {
        func_0038CE20((vu0_q *)&smoke, (vu0_q *)vars, -0.04000000283122063f);
        func_003C4C18(&smoke, 0.12000000476837158f);
        smoke.z += 0.06000000238418579f;
        color = 0x7F80DFFF;
        if (func_00382468(2)) color = 0x7F407FFF;
        particle = func_L01_00465738(moby + 0x10, &smoke, color, 255, func_00382498(8, 17), 0, -1, -1, 0, 94500.0f);
        if (particle) {
            *(f32 *)(particle + 0x2C) = 0.002400000113993883f;
            particle[2] = *D_L01_0022116C[0];
        }
    }
}
/* localdecomp:end func_L01_00383BA0 */
