/*
 * P03 PAL near miss, base eb302969 (2026-11-16).
 * Owning file: src/levels/20_final_boss/L20_003E6150.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock check.py: 52 positional differences at level 20.
 * Five compiles: 305, 183, 52, 52, 307; this preserves the 52-difference form.
 * Remaining: first UV stream has an absolute rather than GP address, the other
 * stream's base is rematerialized, saved pointer roles differ, and the phase
 * join uses a different FP temporary. Full-program and NTSC-U checks not run.
 * No artificial extern-size reduction, changed flags, barriers or pins used.
 */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70, u78, u80, gif;
} Packet_A488;
extern long func_00389598(s32);
extern void func_0038D570(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003D93B0(void *, s32, s32, s32);
extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern s32 D_L20_001DF24C;
extern s32 D_L20_001DF250;
extern s32 D_L20_001DF254;
extern s32 D_L20_001DF244;
extern s32 D_L20_001DF248;
extern f32 D_L20_001DF258;
extern f32 D_L20_001DF260[][2] __attribute__((section(".sdata")));
extern f32 D_L20_001DF264[][2];
__asm__(".extern D_L20_001DF24C, 4");
__asm__(".extern D_L20_001DF250, 4");
__asm__(".extern D_L20_001DF254, 4");
__asm__(".extern D_L20_001DF244, 4");
__asm__(".extern D_L20_001DF248, 4");
__asm__(".extern D_L20_001DF258, 4");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
void func_L20_003EA488(void *arg) {
    u8 *obj = arg;
    Packet_A488 q[3];
    vu0_v4 m[4];
    vu0_v4 rot[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    u8 *v;
    f32 alpha;
    f32 phase;
    f32 next;
    f32 z;
    s32 i, j, k, color;
    v = *(u8 **)(obj + 0x68);
    *(vu0_q *)&a = 0;
    a.z = 0.2617994f;
    func_0038D570(m, *(u8 **)(obj + 0xB8) + 0xC0);
    m[3] = *(vu0_v4 *)(obj + 0x10);
    m[3].w = 1.0f;
    func_0038D328(rot, &a);
    alpha = (D_L20_001DF23C - *(f32 *)(v + 0x1C)) * 0.5f;
    phase = *(f32 *)(v + 0x20) - (f32)(s32)*(f32 *)(v + 0x20);
    if (alpha > 1.0f) alpha = 1.0f;
    else if (alpha < 0.0f) alpha = 0.0f;
    for (i = 0; i < 3; i++) {
        f32 angle;
        f32 radius;
        q[i].u78 = func_00389598(D_L20_001DF24C);
        q[i].u80 = 0xFF9000000260L;
        q[i].u70 = 5;
        q[i].gif = ((long)D_L20_001DF250 << 2) | ((long)D_L20_001DF254 << 6) | (0x8000L << 24);
        radius = *(f32 *)(v + 0x1C) - (f32)i * 0.05f;
        angle = (f32)i * 0.08726646f;
        next = func_0038DAB8(angle, 0.2617994f);
        b.x = func_0038D098(angle) * radius;
        b.y = func_0038D0B0(angle) * radius;
        b.z = 0.0f;
        b.w = 1.0f;
        c.x = func_0038D098(next) * radius;
        c.y = func_0038D0B0(next) * radius;
        c.z = 0.0f;
        c.w = 1.0f;
        z = phase * (D_L20_001DF258 + func_L01_00443A18(0.2f, 0.6f));
        *(vu0_q *)&q[i].v[0] = *(vu0_q *)&b;
        q[i].v[0].z = z;
        *(vu0_q *)&q[i].v[1] = *(vu0_q *)&b;
        q[i].v[1].z = -z;
        *(vu0_q *)&q[i].v[2] = *(vu0_q *)&c;
        q[i].v[2].z = z;
        *(vu0_q *)&q[i].v[3] = *(vu0_q *)&c;
        q[i].v[3].z = -z;
        color = func_0038DBD8(D_L20_001DF248, D_L20_001DF244, (1.0f - phase) * alpha);
        for (j = 0; j < 4; j++) {
            q[i].col[j] = color;
            q[i].uv[j][0] = D_L20_001DF260[j][0];
            q[i].uv[j][1] = D_L20_001DF264[j][0];
        }
        {
            f32 p;
            if (phase >= 0.666f) p = phase + -0.666f;
            else p = phase + 0.333f;
            phase = p;
        }
    }
    for (k = 0; k < 24; k++) {
        func_0038D5F0(m, m, rot);
        func_003D2DA0(&q[0], (s32)m, 1);
        func_003D2DA0(&q[1], (s32)m, 1);
        func_003D2DA0(&q[2], (s32)m, 1);
    }
    for (i = 0; i < 3; i++) {
        f32 angle;
        f32 radius;
        func_003D93B0(&q[i], D_L20_001DF24C, 3, 0x80);
        radius = *(f32 *)(v + 0x1C) - (f32)i * 0.05f;
        angle = (f32)i * 0.08726646f;
        next = func_0038DAB8(angle, 0.2617994f);
        b.x = func_0038D098(angle) * radius;
        b.y = func_0038D0B0(angle) * radius;
        b.z = 0.0f;
        b.w = 1.0f;
        c.x = func_0038D098(next) * radius;
        c.y = func_0038D0B0(next) * radius;
        c.z = 0.0f;
        c.w = 1.0f;
        z = phase * 0.75f;
        *(vu0_q *)&q[i].v[0] = *(vu0_q *)&b;
        q[i].v[0].z = z;
        *(vu0_q *)&q[i].v[1] = *(vu0_q *)&b;
        q[i].v[1].z = -z;
        *(vu0_q *)&q[i].v[2] = *(vu0_q *)&c;
        q[i].v[2].z = z;
        *(vu0_q *)&q[i].v[3] = *(vu0_q *)&c;
        q[i].v[3].z = -z;
        for (j = 0; j < 4; j++) {
            q[i].col[j] = 0x7F7F7F7F;
            q[i].uv[j][0] = D_L20_001DF260[j][0];
            q[i].uv[j][1] = D_L20_001DF264[j][0];
        }
        {
            f32 p;
            if (phase >= 0.666f) p = phase + -0.666f;
            else p = phase + 0.333f;
            phase = p;
        }
    }
    for (k = 0; k < 24; k++) {
        func_0038D5F0(m, m, rot);
        func_003D2DA0(&q[0], (s32)m, 1);
        func_003D2DA0(&q[1], (s32)m, 1);
        func_003D2DA0(&q[2], (s32)m, 1);
    }
}
