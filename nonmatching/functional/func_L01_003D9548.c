/* functional: medium. Written from the disassembly (no draft), compiled in context; not byte-compared. States 0/2/3/4 of a Veldin creature AI (jump table 0:idle 2:attack-pursue 3:wander 4:return); VU0 vadd/vsub.xyz and lq/sq copies written as scalar/u128 C; every call and its argument constants re-read from the asm; func_L01_003DAAE0 is declared extern here because the file defines it later. */
#include "common.h"
/* localdecomp:start func_L01_003D9548 */
typedef struct { f32 x, y, z, w; } V4_003D9548 __attribute__((aligned(16)));
typedef struct {
    u8 p00[0x14];
    f32 move14;
    u8 *look;          /* 0x18: moby to face when idle */
    u8 turn1C[0x0C];
    u8 *target;        /* 0x28 */
    u8 p2C[0x10];
    s32 hits;          /* 0x3C */
    u8 p40[8];
    s32 override;      /* 0x48: set while cutscene/hero control is on */
    s32 timer;         /* 0x4C */
} Vars_003D9548;
extern f32 D_L01_001E2420[];
extern s32 D_L01_001E2430;
__asm__(".extern D_L01_001E2430, 16");
extern u8 D_001A4BE0[];
extern u8 D_L01_002C5600[];
extern u8 D_001425C0[];
void func_L01_003D9548(u8 *obj) {
    extern s32 func_L01_003D9FD0(u8 *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_003DB588(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    extern u8 *func_00382348(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_004395E0(u8 *);
    extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
    extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_00450010(void *, f32, f32, f32, f32, s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_00404808(void (*)(void *), void *);
    extern void func_L01_003DAAE0(void *);
    extern s32 func_L01_003D9510(u8 *);
    V4_003D9548 tgt, aim, probe;
    Vars_003D9548 *v;
    u8 *t, *h, *cam;
    f32 d, save;
    s32 go;
    v = *(Vars_003D9548 **)(obj + 0x68);
    if (func_L01_003D9FD0(obj)) return;
    go = 0; /* 0: fall to the end; 1: finish with look-at flow; set per state below */
    switch (obj[0x20]) {
    case 0:
        if (func_0038CAD0(&D_L01_001E2430) == 0) {
            func_L01_003DB588(obj);
            break;
        }
        func_L01_004450F0(obj, 3, -1);
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 0);
        break;
    case 2:
        *(s32 *)(obj + 0x98) = 0;
        if (func_L01_003D9540() != 0 || func_L01_003D9510(obj) != 0) {
            v->override = 1;
            *(u16 *)(obj + 0x34) |= 0x100;
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xC0) = *(u128_t *)(cam + 0xC0);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xD0) = *(u128_t *)(cam + 0xD0);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xE0) = *(u128_t *)(cam + 0xE0);
        }
        t = v->target;
        if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD) {
            v->target = 0;
            go = 3;
            goto react;
        }
        *(u128_t *)&tgt = *(u128_t *)(t + 0x10);
        h = func_00382348(v->target);
        if (h) {
            func_0038CE20(&tgt, v->target + 0xE0, *(f32 *)(h + 0x10));
            tgt.x = tgt.x + *(f32 *)(v->target + 0x10);
            tgt.y = tgt.y + *(f32 *)(v->target + 0x14);
            tgt.z = tgt.z + *(f32 *)(v->target + 0x18);
        }
        d = func_L01_0040E548(&tgt, obj + 0x10);
        func_L01_00448340(obj + 0x10, &tgt, &v->move14, 0.001600000075995922f, 0.001600000075995922f, 0.2600000202655792f);
        if (func_L01_003D9540() == 0 && func_L01_003D9510(obj) == 0) {
            f32 ang = func_0038D160(tgt.x - *(f32 *)(obj + 0x10), tgt.y - *(f32 *)(obj + 0x14));
            func_L01_00448890(obj + 0xF8, v->turn1C, 0, ang, 0.0062831854447722435f, 0.0062831854447722435f, 0.3141592741012573f);
        }
        if (!(d < 0.75f)) break;
        if (v->timer == 0) {
            v->timer = 8;
            func_003A52A0(3, 0, obj);
        }
        v->hits = v->hits + 1;
        func_L01_00446780(obj, obj + 0x10, 0x110000, 0, 1, 0,
                          2.0f, *(f32 *)(D_L01_002C5600 + D_001425C0[0x8F] * 0xF0 + 0x6C) * 0.20000000298023224f, 1.0f);
        *(u128_t *)&aim = *(u128_t *)(obj + 0x10);
        t = func_L01_00450010(&aim, 1.0471975803375244f, 30.0f, -1.0f, -1.0f, 0);
        v->target = t;
        if (t == 0) { v->target = 0; break; }
        if ((*(u16 *)(t + 0x34) & 2) || t[0x20] == 0xFE || t[0x20] == 0xFD || *(u8 **)(t + 0x24) == 0 ||
            (*(u8 **)(t + 0x24))[0x46] != 5) {
            v->target = 0;
            break;
        }
        *(u128_t *)&aim = *(u128_t *)(t + 0x10);
        h = func_00382348(v->target);
        if (h) {
            func_0038CE20(&aim, v->target + 0xE0, *(f32 *)(h + 0x10));
            aim.x = aim.x + *(f32 *)(v->target + 0x10);
            aim.y = aim.y + *(f32 *)(v->target + 0x14);
            aim.z = aim.z + *(f32 *)(v->target + 0x18);
        }
        if (func_003D3CB0(obj + 0x10, &aim, 2, obj, 0) == 0) break;
        v->target = 0;
        go = 3;
        goto react;
    case 3:
        if (func_L01_003D9540() != 0 || func_L01_003D9510(obj) != 0) {
            v->override = 1;
            *(u16 *)(obj + 0x34) |= 0x100;
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xC0) = *(u128_t *)(cam + 0xC0);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xD0) = *(u128_t *)(cam + 0xD0);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xE0) = *(u128_t *)(cam + 0xE0);
        }
        {
            f32 r1, r2, r3;
            *(s32 *)(obj + 0x98) = 0;
            r1 = func_003824E0(3.0f, 4.0f) * 0.0004000000189989805f;
            r2 = func_003824E0(2.0f, 3.0f) * 0.0004000000189989805f;
            r3 = func_003824E0(6.0f, 8.0f) * 0.020000001415610313f;
            func_L01_00448340(obj + 0x10, D_L01_001E2420, &v->move14, r1, r2, r3);
        }
        if (func_L01_003D9540() == 0 && func_L01_003D9510(obj) == 0) {
            f32 ang = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(obj + 0x10), *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(obj + 0x14));
            func_L01_00448890(obj + 0xF8, v->turn1C, 0, ang, 0.012566370889544487f, 0.012566370889544487f, 0.6283185482025146f);
        }
        d = func_L01_004395E0(obj);
        if (obj[0x42] == 2 && 9.0f <= d && obj[0x43] != 3) func_003C3A10(obj, 3, 0, 0);
        if (!(func_0038CF38(obj + 0x10, D_L01_001E2420) < 0.5f)) break;
        func_L01_004450F0(obj, 4, -1);
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 0);
        break;
    case 4:
        if (func_L01_003D9540() != 0 || func_L01_003D9510(obj) != 0) {
            v->override = 1;
            *(u16 *)(obj + 0x34) |= 0x100;
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xC0) = *(u128_t *)(cam + 0xC0);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xD0) = *(u128_t *)(cam + 0xD0);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xE0) = *(u128_t *)(cam + 0xE0);
        }
        *(s32 *)(obj + 0x98) = 0;
        d = func_L01_0040E548(obj + 0x10, D_001A4BE0 + 0x80);
        if (50.0f < d) {
            func_L01_00448340(obj + 0x10, D_L01_001E2420, &v->move14, 0.001600000075995922f, 0.001600000075995922f, 0.20000001788139343f);
        } else {
            if (20.0f < d && d < 50.0f) {
                *(u128_t *)&probe = *(u128_t *)(obj + 0x10);
                save = v->move14;
                func_L01_00448340(&probe, D_L01_001E2420, &v->move14, 0.001600000075995922f, 0.001600000075995922f, 0.20000001788139343f);
            } else {
                f32 r1, r2, r3;
                *(u128_t *)&probe = *(u128_t *)(obj + 0x10);
                save = v->move14;
                r1 = func_003824E0(0.5f, 1.0f) * 0.0004000000189989805f;
                r2 = func_003824E0(0.5f, 1.0f) * 0.0004000000189989805f;
                r3 = func_003824E0(3.0f, 6.0f) * 0.020000001415610313f;
                func_L01_00448340(&probe, D_L01_001E2420, &v->move14, r1, r2, r3);
            }
            aim.x = probe.x - *(f32 *)(obj + 0x10);
            aim.y = probe.y - *(f32 *)(obj + 0x14);
            aim.z = probe.z - *(f32 *)(obj + 0x18);
            aim.w = probe.w;
            func_0038CF68(&aim, &aim, 0.20000000298023224f);
            aim.x = aim.x + *(f32 *)(obj + 0x10);
            aim.y = aim.y + *(f32 *)(obj + 0x14);
            aim.z = aim.z + *(f32 *)(obj + 0x18);
            if (func_003D3CB0(obj + 0x10, &aim, 0, obj, 0) == 0) {
                *(u128_t *)(obj + 0x10) = *(u128_t *)&probe;
            } else {
                v->move14 = save;
            }
        }
        if (func_L01_003D9540() != 0 || func_L01_003D9510(obj) != 0) break;
        t = (u8 *)v->look;
        if (t != 0 && t[0x20] != 0xFE && t[0x20] != 0xFD) {
            f32 ang = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(obj + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(obj + 0x14));
            func_L01_00448890(obj + 0xF8, v->turn1C, 0, ang, 0.012566370889544487f, 0.012566370889544487f, 0.6283185482025146f);
        } else if (func_0038CF00(obj + 0x10, D_L01_001E2420) < 0.10000000149011612f) {
            cam = *(u8 **)(D_001A4BE0 + 0x25C0);
            tgt.x = *(f32 *)(obj + 0x10) + *(f32 *)(cam + 0xC0);
            tgt.y = *(f32 *)(obj + 0x14) + *(f32 *)(cam + 0xC4);
            tgt.z = *(f32 *)(obj + 0x18) + *(f32 *)(cam + 0xC8);
            tgt.w = *(f32 *)(obj + 0x1C);
            {
                f32 ang = func_0038D160(tgt.x - *(f32 *)(obj + 0x10), tgt.y - *(f32 *)(obj + 0x14));
                func_L01_00448890(obj + 0xF8, v->turn1C, 0, ang, 0.0027925269678235054f, 0.0027925269678235054f, 0.13962635397911072f);
            }
        } else {
            f32 ang = func_0038D160(D_L01_001E2420[0] - *(f32 *)(obj + 0x10), D_L01_001E2420[1] - *(f32 *)(obj + 0x14));
            func_L01_00448890(obj + 0xF8, v->turn1C, 0, ang, 0.0062831854447722435f, 0.0062831854447722435f, 0.3141592741012573f);
        }
        break;
    default:
        break;
    }
    goto finish;
react:
    func_L01_004450F0(obj, go, -1);
    if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 0);
finish:
    if (func_L01_003D9540() == 0 && func_L01_003D9510(obj) == 0 && v != 0 && v->override != 0) {
        v->override = 0;
        *(u16 *)(obj + 0x34) &= 0xFEFF;
        cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xC0) = *(u128_t *)(cam + 0xC0);
        cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xD0) = *(u128_t *)(cam + 0xD0);
        cam = *(u8 **)(D_001A4BE0 + 0x25C0); *(u128_t *)(obj + 0xE0) = *(u128_t *)(cam + 0xE0);
    }
    func_L01_00404808(func_L01_003DAAE0, obj);
}
/* localdecomp:end func_L01_003D9548 */
