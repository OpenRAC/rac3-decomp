/* functional: medium. Written from the asm (no draft): 611 diff but all 48 constants identical and the jal sequence equals retail except two tail-merged calls (retail duplicates func_0038CEA8 per branch and the func_L01_00404A10 re-register per state; mine merges them, same behaviour); stack layout shifted by 0x10; hit-record D_L01_001EAA00 and hero D_001A4BE0 accessed by byte offset; file-context prototypes for func_0038CE20/func_003D4D00/D_L01_002C5600 used; vu0_v4 needed for the spawn vectors since TI-mode lvalue casts ICE the compiler; offsets of ray scratch (+0xC owner/+0x4 flags/+0xA class) reconstructed from the sw/sh/sb pattern, not named */
#include "common.h"
#include "vu0.h"
extern u8 D_001425C0[];
extern u8 D_L01_001EAA00[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001D66B0[];
extern u8 *D_L01_0022116C[];
extern u8 *D_L01_00221098[];
/* functional: Suck Cannon style shot (class 0x1881) update, run every frame by its owner callback */
void func_L01_003854F8(u8 *moby) {
    extern s32 func_L01_00457458(s32, s32);
    extern void func_003C2880(void *);
    extern void func_L01_004C8668(s32);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_00386AD8(s32);
    extern u8 *func_00382348(u8 *);
    extern void func_003C2F58(u8 *, s32, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_L01_00386410(u8 *, void *, s32, s32);
    extern void func_L01_0034C9F0(void *, s32, void *);
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00470668(void *, void *, s32, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_003868A0(u8 *, void *);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_00404A10(void (*)(), void *);
    extern void func_L01_00385EA0(u8 *);
    extern void func_L01_00385EE0();
    vu0_v4 saved;     /* sp+0x90: position before the move */
    vu0_q normal;     /* sp+0xA0 */
    vu0_q ray[3];     /* sp+0xB0: ray/target scratch (0xB0, 0xC0, 0xD0) */
    vu0_v4 eye;        /* sp+0xE0 */
    vu0_v4 spark;      /* sp+0xF0 */
    vu0_v4 spawn;      /* sp+0x100 */
    u8 *vars = *(u8 **)(moby + 0x68);
    u8 *pos = moby + 0x10;
    u8 *tgt;
    u8 *p;
    u8 *r;
    s32 n, spin;
    f32 len, size;
    f32 px;

    if (!func_L01_00457458(*(s32 *)(vars + 0x18), *(s32 *)(vars + 0x14))) {
        func_003C2880(moby);
        func_L01_004C8668(*(s32 *)(vars + 0x30));
        return;
    }
    func_L01_004CAB30(pos, pos);
    *(vu0_q *)&saved = *(vu0_q *)(moby + 0x10);
    func_003C5180(pos, &normal, 1);

    tgt = *(u8 **)(vars + 0x1C);
    if (tgt) {
        if (tgt[0x20] == 0xFE) {
            *(s32 *)(vars + 0x1C) = 0;
        } else if (tgt[0x20] == 0xFD) {
            *(s32 *)(vars + 0x1C) = 0;
        } else if (func_L01_00386AD8((s32)tgt)) {
            *(s32 *)(vars + 0x1C) = 0;
        } else {
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(ray[0]) : "m"(*(vu0_q *)(moby + 0x10)), "m"(*(vu0_q *)(tgt + 0x10)) : "vf1", "vf2");
            r = func_00382348(tgt);
            if (r) {
                func_0038CE20((u128_384E68 *)&ray[1], (u128_384E68 *)(tgt + 0xE0), *(f32 *)(r + 0x10));
                if (*(s16 *)(tgt + 0xAA) == 0x1AB8) {
                    func_003C2F58(tgt, 4, &ray[2]);
                    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                        : "=m"(ray[1]) : "m"(ray[2]), "m"(*(vu0_q *)(tgt + 0x10)) : "vf1", "vf2");
                }
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(ray[0]) : "m"(ray[0]), "m"(ray[1]) : "vf1", "vf2");
            }
            len = func_0038CEA8(&ray[0]);
            if (len == 0.0f) {
                *(s32 *)(vars + 0x1C) = 0;
            } else {
                f32 speed = *(f32 *)(vars + 0x2C);
                func_0038CE20((u128_384E68 *)(vars + 0x20), (u128_384E68 *)&ray[0], speed / len);
                *(f32 *)(vars + 0x2C) = speed;
            }
        }
    }

    if (moby[0x20] == 0) {
        func_L01_004C8688(*(s32 *)(vars + 0x30), vars + 0x20, 0);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_q *)(moby + 0x10)) : "m"(*(vu0_q *)(moby + 0x10)), "m"(*(vu0_q *)(vars + 0x20)) : "vf1", "vf2");
        *(s32 *)((u8 *)&ray[1] + 0x0) = *(s32 *)(moby + 0xB8);
        *(s32 *)((u8 *)&ray[1] + 0x4) = 0x10000;
        *(s32 *)((u8 *)&ray[2]) = 1;
        *(f32 *)((u8 *)&ray[1] + 0xC) = D_L01_002C5600[D_001425C0[0x2F]].damage;
        ray[0] = *(vu0_q *)(vars + 0x20);
        func_0038CF68(&ray[0], &ray[0], 1.0f);
        *(f32 *)((u8 *)&ray[0] + 0xC) = 5627.925f;
        *(u16 *)((u8 *)&ray[1] + 0xA) = *(u16 *)(moby + 0xAA);
        *(u8 *)((u8 *)&ray[1] + 0x8) = 1;
        *(u8 *)((u8 *)&ray[1] + 0x9) = 1;
        if (func_003D3CB0(&saved, pos, 0, *(void **)((u8 *)&D_001A4BE0 + 0x25C0), &ray[0])) {
            u8 *obj = *(u8 **)(D_L01_001EAA00 + 0x18);
            u8 *hit;
            if (obj == 0) {
                *(s32 *)(vars + 0x3C) = *(s32 *)(vars + 0x3C) + 1;
                func_L01_0040E790(vars + 0x20, vars + 0x20, D_L01_001EAA00 + 0x40);
                func_L01_00386410(moby, D_L01_001EAA00 + 0x20, 0xF, 0);
            } else if (*(s16 *)(obj + 0xAA) == 0x1F6) {
                moby[0x20] = 1;
                *(s32 *)(vars + 0x1C) = 0;
                hit = D_L01_001EAA00 + 0x20;
                *(u16 *)(moby + 0x34) |= 0x41;
                *(s32 *)(vars + 0x34) = 5;
                func_L01_00386410(moby, hit, 0xA, 1);
                func_L01_0034C9F0(*(void **)(D_L01_001EAA00 + 0x18), 0x30, *(void **)(moby + 0xB8));
                func_003D4D00(hit, 1.0f, 0, moby, (s32)&ray[0]);
            } else if (*(u8 **)(obj + 0x24) != 0 && (*(u8 **)(obj + 0x24))[0x46] == 5) {
                moby[0x20] = 1;
                *(s32 *)(vars + 0x1C) = 0;
                hit = D_L01_001EAA00 + 0x20;
                *(u16 *)(moby + 0x34) |= 0x41;
                *(s32 *)(vars + 0x34) = 5;
                func_L01_00386410(moby, hit, 0xA, 1);
                func_L01_0034C9F0(*(void **)(D_L01_001EAA00 + 0x18), 0x30, *(void **)(moby + 0xB8));
                func_003D4D00(hit, 1.0f, 0, moby, (s32)&ray[0]);
            } else {
                *(s32 *)(vars + 0x3C) = *(s32 *)(vars + 0x3C) + 1;
                func_L01_0040E790(vars + 0x20, vars + 0x20, D_L01_001EAA00 + 0x40);
                func_L01_00386410(moby, D_L01_001EAA00 + 0x20, 0xF, 0);
                func_003D4D00(D_L01_001EAA00 + 0x20, 1.0f, 0, moby, (s32)&ray[0]);
            }
            if (*(s32 *)(vars + 0x3C) < 2) {
                func_L01_003303B8(D_L01_001EAA00 + 0x20, 0, 1, 1, 1, 1, 1, 0, 0.17f, 0.0f, 0.0f, 0.0f,
                    0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x2040FF, 0x63FF, 0x307FFF, 0x20FF, 0x8FFF,
                    0x2064FF, 0x7F3030FF, 0x280000FF, 0x1010FF, 0);
            }
            if (*(u8 **)(D_L01_001EAA00 + 0x18) != *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0)) {
                __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(eye) : "m"(*(vu0_q *)D_L01_001E29C0), "m"(*(vu0_q *)(D_L01_001EAA00 + 0x20)) : "vf1", "vf2");
                func_0038CF68(&eye, &eye, func_003824E0(0.1f, 0.2f));
                n = (*(s32 *)(vars + 0x3C) > 1) ? 2 : 10;
                if (n != 0) {
                    do {
                        eye.x += func_003824E0(-0.05f, 0.05f);
                        eye.y += func_003824E0(-0.05f, 0.05f);
                        eye.z += func_003824E0(-0.05f, 0.05f);
                        spin = func_00382498(0x19, 0x28);
                        n--;
                        func_L01_00470668(D_L01_001EAA00 + 0x20, &eye, (spin * 5 + 2) / 6, 0.00584f);
                    } while (n != 0);
                }
            }
        } else if (func_0038CAD0(vars + 0x34)) {
            func_L01_003868A0(moby, pos);
            moby[0x20] = 1;
            *(s32 *)(vars + 0x1C) = 0;
            *(u16 *)(moby + 0x34) |= 0x41;
            *(s32 *)(vars + 0x34) = 5;
        }
        spin = func_00382468(255);
        p = func_L01_0046FB40(pos, D_L01_001D66B0, 2, 0x1020FF, spin, 0x40, 0x10, 210000.0f, 210000.0f, 0.0f, 1);
        if (p) p[2] = *D_L01_0022116C[0];
        spin = (spin + 0x80) % 255;
        p = func_L01_0046FB40(pos, D_L01_001D66B0, 2, 0x1020FF, spin, 0x40, 0x10, 210000.0f, 210000.0f, 0.0f, 1);
        if (p) p[2] = *D_L01_0022116C[0];
        spin = (spin + 0x40) % 255;
        p = func_L01_0046FB40(pos, D_L01_001D66B0, 2, 0x4F4FFF, spin, 0x30, 0x10, 126000.0078125f, 126000.0078125f, 0.0f, 1);
        if (p) p[2] = *D_L01_0022116C[0];
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(eye) : "m"(*(vu0_q *)(moby + 0x10)), "m"(saved) : "vf1", "vf2");
        func_0038CE20((u128_384E68 *)&eye, (u128_384E68 *)&eye, 0.4f);
        *(vu0_q *)&spark = *(vu0_q *)&saved;
        n = 1;
        do {
            spin = func_00382468(255);
            size = func_003824E0(0.2f, 0.6f);
            spawn.x = spark.x + func_L01_00443A18(0.0f, 0.05f);
            spawn.y = spark.y + func_L01_00443A18(0.0f, 0.05f);
            spawn.z = spark.z + func_L01_00443A18(0.0f, 0.05f);
            p = func_L01_0046FB40(&spawn, D_L01_001D66B0, 0xC, 0x4080FF, spin, 0x20, 0,
                size * 210000.0f, size * 0.2f * 210000.0f, 0.0f, 1);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(spark) : "m"(spark), "m"(eye) : "vf1", "vf2");
            n--;
            if (p) p[2] = (*(u8 **)((u8 *)D_L01_00221098 + 0x16C))[0];
        } while (n >= 0);
        func_L01_00404A10(func_L01_00385EE0, moby);
        px = *(f32 *)(moby + 0x10);
    } else if (moby[0x20] == 1) {
        if (func_0038CAD0(vars + 0x34)) func_L01_00385EA0(moby);
        func_L01_00404A10(func_L01_00385EE0, moby);
        px = *(f32 *)(moby + 0x10);
    } else {
        px = *(f32 *)(moby + 0x10);
    }
    if (px < 2.0f || px > 1021.0f ||
        *(f32 *)(moby + 0x14) < 2.0f || *(f32 *)(moby + 0x14) > 1021.0f ||
        *(f32 *)(moby + 0x18) < 2.0f || *(f32 *)(moby + 0x18) > 1021.0f ||
        *(s32 *)(vars + 0x3C) >= 8) {
        func_L01_00385EA0(moby);
    }
}
