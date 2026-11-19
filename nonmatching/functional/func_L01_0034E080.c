/* functional: medium. Near-miss draft (compiles under file flags); 230 diff words; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034E080 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4C90;
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern s32 D_001A5E08[];
extern f32 D_L01_001DD3F0;
__asm__(".extern D_L01_001DD3F0, 4");
extern f32 D_L01_001DD3F4;
__asm__(".extern D_L01_001DD3F4, 4");
extern f32 D_L01_001DD3DC;
__asm__(".extern D_L01_001DD3DC, 4");
extern f32 D_L01_001DD3E0;
__asm__(".extern D_L01_001DD3E0, 4");
extern f32 D_L01_001DD3E4;
__asm__(".extern D_L01_001DD3E4, 4");
extern f32 D_L01_001DD3E8;
__asm__(".extern D_L01_001DD3E8, 4");
extern f32 D_L01_001DD3EC;
__asm__(".extern D_L01_001DD3EC, 4");
void func_L01_0034E080(vu0_q *pos, s32 count, s32 kind) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382468(s32);
    extern u32 func_0013D3E0(void);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern u8 *func_L01_0046B458(void *, s32, u32, f32, f32, f32, s32, s32, void *, s32);
    vu0_v4 velocity, at, delta, axis, toward;
    s32 i, spin;
    u32 color;
    f32 size, speed, power;
    u8 *p;
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
            : "=m"(delta) : "m"(D_L01_001E29C0), "m"(*(vu0_v4 *)pos) : "vf1", "vf2");
    if (D_L01_001D673C == 0) {
        delta.z = 0.0f;
        axis.w = 1.0f;
        axis.x = 0.0f;
        axis.y = 0.0f;
        axis.z = 1.0f;
    } else {
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(toward) : "m"(*(vu0_v4 *)pos), "m"(D_001A4C90) : "vf1", "vf2");
        func_0038CF68(&axis, &toward, 1.0f);
        func_0038CE20((f32 *)&toward, (f32 *)&axis, func_0038CE68(&axis, &delta));
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(delta) : "m"(delta), "m"(toward) : "vf1", "vf2");
    }
    if (count <= 0) return;
    i = count;
    do {
        size = func_003824E0(D_L01_001DD3F0, D_L01_001DD3F4);
        spin = func_00382468(2);
        spin = spin != 0 ? spin : spin - 1;
        func_0038D890(&velocity, &delta, &axis, func_003824E0(-1.0471976f, 1.0471976f));
        speed = func_003824E0(D_L01_001DD3DC, D_L01_001DD3E0) * 0.020000001f;
        func_0038CF68(&velocity, &velocity, speed);
        velocity.z = func_003824E0(D_L01_001DD3E4, D_L01_001DD3E8) * 0.020000001f;
        *(vu0_q *)&at = *pos;
        at.x += func_L01_00443A18(0.0f, 0.15f);
        at.y += func_L01_00443A18(0.0f, 0.15f);
        at.z += func_L01_00443A18(0.0f, 0.15f);
        color = D_001A5E08[0] == 0x2F ? 0x7F000080 : 0x7F800000;
        if (kind == 0) {
            if ((func_0013D3E0() & 1) == 0) {
                func_0038CE20((f32 *)&velocity, (f32 *)&velocity, 1.5f);
                p = func_L01_0046B458(&at, 50, color, size * 0.1f * 3.5f, size, D_L01_001DD3EC * 1.44f, 0, spin, &velocity, 0);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 50, 0x7F7F7F7F, size * 0.07f * 3.5f, size * 0.7f, D_L01_001DD3EC * 1.44f, 1, -spin, &velocity, 0);
                if (p) p[9] = 0x74;
            } else {
                __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                        : "=m"(toward) : "m"(D_L01_001E29C0), "m"(at) : "vf1", "vf2");
                power = 20.5f;
                goto attracted;
            }
        } else {
            if ((func_0013D3E0() & 1) == 0) {
                func_0038CE20((f32 *)&velocity, (f32 *)&velocity, 1.5f);
                p = func_L01_0046B458(&at, 50, color, size * 0.1f * 3.0f, size, D_L01_001DD3EC * 1.44f, 0, spin, &velocity, 0);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 50, 0x7F7F7F7F, size * 0.07f * 3.0f, size * 0.7f, D_L01_001DD3EC * 1.44f, 1, -spin, &velocity, 0);
                if (p) p[9] = 0x74;
            } else {
                __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                        : "=m"(toward) : "m"(D_L01_001E29C0), "m"(at) : "vf1", "vf2");
                power = 2.5f;
                goto attracted;
            }
        }
        goto next;
attracted:
        func_0038CF68(&toward, &toward, speed);
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(velocity) : "m"(velocity), "m"(toward) : "vf1", "vf2");
        p = func_L01_0046B458(&at, 33, color, size * 0.1f * power, size, D_L01_001DD3EC * 1.44f, 0, spin, &velocity, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(&at, 33, 0x7F7F7F7F, size * 0.07f * power, size * 0.7f, D_L01_001DD3EC * 1.44f, 1, -spin, &velocity, 0);
        if (p) p[9] = 0x74;
next:
        i--;
    } while (i != 0);
}
/* localdecomp:end func_L01_0034E080 */
