/* functional: medium. 420 diff, same frame size; written from asm (no draft) and cross-checked by opcode/immediate histogram: only differences are register/scheduling, retail's add.s-vs-mul.s for 2.0*x and por-style zeroing. Delay-slot nops rechecked in raw asm; all float constants bit-exact. Declares D_L01_001E2A40 / D_L01_00221098 locally (file declares them later with other types); func_L01_003E0058 returns void* and func_L01_0039D818 u8* as in the file */
#include "common.h"
#include "vu0.h"
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_00390AB8;
typedef struct { f32 pos[4]; u8 pad10[0x10]; f32 strength; s32 pad24; s32 time; s32 mode; } Effect_00390AB8;
typedef struct { u8 pad0[0x5C]; u8 *first; u8 pad60[0x88 - 0x60]; u8 *third; u8 pad8C[0x1A4 - 0x8C]; u8 *second; } Assets_00390AB8;
extern Effect_00390AB8 D_L01_001E2A40;
extern Assets_00390AB8 D_L01_00221098;
extern s32 D_001D673C;
void func_L01_00390AB8(u8 *obj, f32 *dir1, f32 *dir2) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern s32 func_00382468(s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_0040E6B8(void *, void *, f32);
    extern void *func_L01_003E0058(void *, void *, s32);
    extern u8 *func_L01_0039D818(void *, void *, void *);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_0046B288(void *, s32, s32, s32, f32, f32);
    extern s32 func_L01_004CB2D8(void);
    Vec_00390AB8 d, e, c, b, ppos, pvel;
    u8 *vars = *(u8 **)(obj + 0x68);
    vu0_v4 *pos = (vu0_v4 *)(obj + 0x10);
    f32 dist, yaw;
    s32 n, i;
    u8 *p;
    func_0038CE20(dir1, dir1, 2.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(d) : "m"(D_L01_001E2A40), "m"(*pos) : "vf1", "vf2");
    dist = func_0038CEA8(&d);
    obj[0x20] = 0;
    /* five random shots, each flattened against dir2 (remove its component, add a random
     * multiple of it) and sent out from the object */
    n = 4;
    do {
        f32 dot, k, sc;
        qzero(&b);
        b.f[0] = func_003824E0(-1.0f, 1.0f);
        b.f[1] = func_003824E0(-1.0f, 1.0f);
        c = b;
        dot = func_0038CE68(&c, dir2);
        func_0038CF68(&e, dir2, dot);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(c) : "m"(e), "m"(c) : "vf1", "vf2");
        k = func_003824E0(1.0f, 2.0f);
        func_0038CF68(&e, dir2, k);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(c) : "m"(e), "m"(c) : "vf1", "vf2");
        sc = func_003824E0(3.5f, 5.0f);
        sc = 2.0f * sc;
        func_0038CF68(&c, &c, sc * 0.020000001f);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(c) : "m"(*(vu0_v4 *)dir1), "m"(c) : "vf1", "vf2");
        b = *(Vec_00390AB8 *)(obj + 0x10);
        b.f[2] = b.f[2] + 0.5f;
        func_L01_003E0058(&b, &c, 0);
    } while (--n >= 0);
    /* one big shot toward D_L01_001E2A40 */
    qzero(&b);
    b.f[0] = func_003824E0(-1.0f, 1.0f);
    b.f[1] = func_003824E0(-1.0f, 1.0f);
    b.f[2] = func_003824E0(-1.0f, 1.0f);
    d.f[2] = d.f[2] + dist * 0.5f;
    c = b;
    func_0038CF68(&c, &c, (dist / 5.0f) * 0.020000001f);
    func_0038CF68(&d, &d, (dist + dist) * 0.020000001f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(c) : "m"(c), "m"(d) : "vf1", "vf2");
    func_L01_0040E6B8(&c, &c, 0.20000001788139343f);
    b = *(Vec_00390AB8 *)(obj + 0x10);
    b.f[2] = b.f[2] + 0.5f;
    func_L01_0039D818(obj, &b, &c);
    *(s32 *)vars = 0;
    obj[0xBC] = 0;
    if (dist < 20.0f) D_L01_001E2A40.strength = 0.4f - dist * 0.017500000074505806f;
    else D_L01_001E2A40.strength = 0.050000011920928955f;
    D_L01_001E2A40.mode = 0;
    D_L01_001E2A40.time = 21;
    yaw = func_0038D160(D_L01_001E2A40.pos[0] - *(f32 *)(obj + 0x10), D_L01_001E2A40.pos[1] - *(f32 *)(obj + 0x14));
    /* two sprays of 20 particles around the yaw (second with the third asset byte) */
    n = 19;
    do {
        s32 kind = (s32)func_L01_00443A18(2.0f, 5.0f);
        f32 size, speed, ang, h, vz;
        s32 life;
        ppos.f[0] = *(f32 *)(obj + 0x10) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[1] = *(f32 *)(obj + 0x14) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[2] = *(f32 *)(obj + 0x18) + func_L01_00443A18(0.0f, 0.1f);
        size = func_003824E0(0.7f, 1.4f);
        speed = func_003824E0(7.0f, 10.0f);
        speed = speed * 0.020000001f;
        ang = func_0038DAB8(yaw, func_L01_00443A18(0.0f, 1.3962634f));
        pvel.f[0] = func_0038D098(ang) * speed;
        pvel.f[1] = func_0038D0B0(ang) * speed;
        h = func_003824E0(0.0f, 12.0f);
        vz = h * 0.020000001f;
        pvel.f[2] = vz;
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        p = func_L01_004713C8(&ppos, &pvel, life, 0x6C182, kind, 0x30, 0x30, 0,
                size * 210000.0f, (size * 0.1f) * 210000.0f, 0.006400000303983688f);
        if (p != 0) p[2] = *D_L01_00221098.second;
    } while (--n >= 0);
    n = 19;
    do {
        s32 kind = (s32)func_L01_00443A18(2.0f, 5.0f);
        f32 size, speed, ang, h, vz;
        s32 life;
        ppos.f[0] = *(f32 *)(obj + 0x10) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[1] = *(f32 *)(obj + 0x14) + func_L01_00443A18(0.0f, 0.1f);
        ppos.f[2] = *(f32 *)(obj + 0x18) + func_L01_00443A18(0.0f, 0.1f);
        size = func_003824E0(0.7f, 1.4f);
        speed = func_003824E0(7.0f, 10.0f);
        speed = speed * 0.020000001f;
        ang = func_0038DAB8(yaw, func_L01_00443A18(0.0f, 1.3962634f));
        pvel.f[0] = func_0038D098(ang) * speed;
        pvel.f[1] = func_0038D0B0(ang) * speed;
        h = func_003824E0(0.0f, 12.0f);
        vz = h * 0.020000001f;
        pvel.f[2] = vz;
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        p = func_L01_004713C8(&ppos, &pvel, life, 0x6C182, kind, 0x30, 0x30, 0,
                size * 210000.0f, (size * 0.05f) * 210000.0f, 0.006400000303983688f);
        if (p != 0) p[2] = *D_L01_00221098.third;
    } while (--n >= 0);
    if (D_001D673C == 0 && func_L01_004CB2D8() == 0) {
        i = 4;
        do {
            f32 angle = func_00382538();
            f32 radius = func_003824E0(0.5f, 2.75f);
            f32 size = func_003824E0(0.0f, 1.5f);
            f32 life = func_003824E0(3.0f, 5.0f);
            s32 alpha = func_00382498(100, 160);
            ppos.f[0] = func_0038D098(angle) * radius;
            ppos.f[1] = func_0038D0B0(angle) * radius;
            ppos.f[2] = 0.0f;
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(ppos) : "m"(ppos), "m"(*pos) : "vf1", "vf2");
            p = func_L01_0046B288(&ppos, 0x5005D152, 0x5D152, alpha, size, life);
            if (p != 0) p[3] = func_00382468(3) ? 0x48 : 0x44;
        } while (--i >= 0);
    }
}
