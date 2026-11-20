/* PAL near miss (Codex wave 7): near miss: 27 words differ with the file's flags.
 * Worker's note: 27 diff: build/codex/w362/func_L20_003EA488.09.log (retained v09); remaining phase temporary FP register, matrix setup order and second UV/color loop allocation; all decoded operations retained; stopped after about ten compiles.
 * Round 16 (b27-k2b, 2026-11-20): retried: the phase temporary `next` declared at function scope in each of the seven positions of the float declarations (134 diff, worse than the block-scoped one), as a ternary (27), updating `phase` in place (173), the two 24-iteration loops as `for (count = 23; count >= 0; count--)` (27) or as `count = 24; ... while (--count)` (30). The two spots stay: the phase temporary is $f3 in ours and $f1 in retail (and the `addiu $s0,$sp,0x1b0` before `addiu $s1,$zero,0x17`), and the second uv/color loop's registers (retail: 0x90 in $t2, pointers $a0-$a3, counter $t0).
 */
#include "common.h"
/* localdecomp:start func_L20_003EA488 */
#include "vu0.h"
extern f32 D_L20_001DF23C;
extern s32 D_001DF244_sda, D_001DF248_sda, D_001DF24C_sda, D_001DF250_sda, D_001DF254_sda;
extern f32 D_001DF258_sda;
extern f32 D_001DF260_sda[];
__asm__(".extern D_001DF260_sda, 4");
extern f32 D_L20_001DF264[] __attribute__((section(".sdata")));
__asm__(".extern D_L20_001DF23C, 4");
__asm__(".extern D_001DF244_sda, 4");
__asm__(".extern D_001DF248_sda, 4");
__asm__(".extern D_001DF24C_sda, 4");
__asm__(".extern D_001DF250_sda, 4");
__asm__(".extern D_001DF254_sda, 4");
__asm__(".extern D_001DF258_sda, 4");
void func_L20_003EA488(void *obj) {
    void func_0038D570(void *, void *);
    void func_0038D328(void *, void *);
    unsigned long func_00389598(s32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    void func_0038D5F0(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003D93B0(void *, s32, s32, s32);
    Q_003E6150 q[3];
    vu0_v4 matrix[4], rotation[4];
    vu0_v4 axis, a,b;
    u8 *m = obj;
    u8 *vars = *(u8 **)(m+0x68);
    f32 fade, phase, offset, angle, nextAngle, radius;
    s32 i,j,count,color;
    *(vu0_q *)&axis = 0;
    axis.z = 0.2617994f;
    func_0038D570(matrix, *(u8 **)(m+0xB8)+0xC0);
    *(vu0_q *)&matrix[3] = *(vu0_q *)(m+0x10);
    matrix[3].w = 1.0f;
    func_0038D328(rotation,&axis);
    fade = (D_L20_001DF23C - *(f32 *)(vars+0x1C)) * 0.5f;
    phase = *(f32 *)(vars+0x20) - (s32)*(f32 *)(vars+0x20);
    if (fade > 1.0f) fade = 1.0f;
    else if (fade < 0.0f) fade = 0.0f;
    for (i=0; i<3; i++) {
        f32 angle, nextAngle, radius;
        q[i].u78 = func_00389598(D_001DF24C_sda);
        q[i].u80 = 0xFF9000000260UL;
        q[i].u70 = 5;
        q[i].gif = ((unsigned long)D_001DF250_sda << 2) | ((unsigned long)D_001DF254_sda << 6) | (0x8000UL << 24);
        radius = *(f32 *)(vars+0x1C) - i * 0.05f;
        angle = i * 0.08726646f;
        nextAngle = func_0038DAB8(angle,0.2617994f);
        a.x = func_0038D098(angle)*radius;
        a.y = func_0038D0B0(angle)*radius;
        a.z = 0;
        a.w = 1;
        b.x = func_0038D098(nextAngle)*radius;
        b.y = func_0038D0B0(nextAngle)*radius;
        b.z = 0;
        b.w = 1;
        offset = phase * (D_001DF258_sda + func_L01_00443A18(0.2f,0.6f));
        *(vu0_q *)&q[i].v[0] = *(vu0_q *)&a;
        q[i].v[0].z = offset;
        *(vu0_q *)&q[i].v[1] = *(vu0_q *)&a;
        q[i].v[1].z = -offset;
        *(vu0_q *)&q[i].v[2] = *(vu0_q *)&b;
        q[i].v[2].z = offset;
        *(vu0_q *)&q[i].v[3] = *(vu0_q *)&b;
        q[i].v[3].z = -offset;
        color = func_0038DBD8(D_001DF248_sda,D_001DF244_sda,(1.0f-phase)*fade);
        for (j=0;j<4;j++) {
            q[i].col[j] = color;
            q[i].uv[j][0] = D_001DF260_sda[j*2];
            q[i].uv[j][1] = D_L20_001DF264[j*2];
        }
        { f32 next;
        if (phase >= 0.666f) next = phase + -0.666f;
        else next = phase + 0.333f;
        phase = next; }
    }
    count = 23;
    do {
        func_0038D5F0(matrix,matrix,rotation);
        func_003D2DA0(&q[0],(s32)matrix,1);
        func_003D2DA0(&q[1],(s32)matrix,1);
        func_003D2DA0(&q[2],(s32)matrix,1);
    } while (--count >= 0);
    for (i=0;i<3;i++) {
        f32 fi;
        func_003D93B0(&q[i],D_001DF24C_sda,3,0x80);
        fi = i;
        radius = *(f32 *)(vars+0x1C) - fi * 0.05f;
        angle = fi * 0.08726646f;
        nextAngle = func_0038DAB8(angle,0.2617994f);
        a.x = func_0038D098(angle)*radius;
        a.y = func_0038D0B0(angle)*radius;
        a.z = 0;
        a.w = 1;
        b.x = func_0038D098(nextAngle)*radius;
        b.y = func_0038D0B0(nextAngle)*radius;
        b.z = 0;
        b.w = 1;
        offset = phase * 0.75f;
        *(vu0_q *)&q[i].v[0] = *(vu0_q *)&a;
        q[i].v[0].z = offset;
        *(vu0_q *)&q[i].v[1] = *(vu0_q *)&a;
        q[i].v[1].z = -offset;
        *(vu0_q *)&q[i].v[2] = *(vu0_q *)&b;
        q[i].v[2].z = offset;
        *(vu0_q *)&q[i].v[3] = *(vu0_q *)&b;
        q[i].v[3].z = -offset;
        for (j=0;j<4;j++) {
            q[i].col[j] = 0x7F7F7F7F;
            q[i].uv[j][0] = D_001DF260_sda[j*2];
            q[i].uv[j][1] = D_L20_001DF264[j*2];
        }
        { f32 next;
        if (phase >= 0.666f) next = phase + -0.666f;
        else next = phase + 0.333f;
        phase = next; }
    }
    count = 23;
    do {
        func_0038D5F0(matrix,matrix,rotation);
        func_003D2DA0(&q[0],(s32)matrix,1);
        func_003D2DA0(&q[1],(s32)matrix,1);
        func_003D2DA0(&q[2],(s32)matrix,1);
    } while (--count >= 0);
}
/* localdecomp:end func_L20_003EA488 */
