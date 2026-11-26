#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
typedef void (*Fn_335C70)(u8 *);
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;

/* declared by earlier blocks of L01_003326A8.c, which this file was cut from */
extern u8 *D_L01_001E001C;


/* localdecomp:start func_L01_00334188 */
extern u8 D_0014275B[];
extern s32 D_001D545C;
extern f32 D_L01_001DAA30;
extern f32 D_L01_001DAA38;
extern f32 D_L01_002F1510[];
extern f32 D_L01_002F16F0[];

void func_L01_00334188(u8 *cfg, u8 *out) {
    s32 n;
    s32 r;
    s32 level = D_001D545C;

    if (*(s8 *)(cfg + 0x8e) != -1) {
        r = (s32)((f32)*(s8 *)(cfg + 0x8e) *
                  (level == 7 && D_0014275B[0] ? D_L01_001DAA30 : D_L01_002F1510[level]));
        *(s16 *)(out + 0x34) = r;
        *(f32 *)(out + 0x30) = *(s8 *)(cfg + 0x8e);
    }
    level = D_001D545C;
    n = (s32)(*(f32 *)(cfg + 0x80) *
              (level == 7 && D_0014275B[0] ? D_L01_001DAA38 : D_L01_002F16F0[level]));
    if (n > 255)
        n = 255;
    out[0x44] = n;
}
/* localdecomp:end func_L01_00334188 */

/* localdecomp:start func_L01_00334250 */

extern void func_L01_00456C98(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0038CAD0(u8 *);
extern s32 func_00382498(s32, s32);

s32 func_L01_00334250(u8 *a0, u8 *obj, u8 *who, u8 *m, s32 t0, u8 *cfg) {
    if (*(s32 *)(obj + 100) == 0) {
        func_L01_00456C98(who, *(s32 *)(cfg + 80), 0, 0, 1, 1, 3, 0, cfg[156] != 0, 0, *(f32 *)(cfg + 84), 10.0f, 1.0f);
    } else {
        func_L01_00456C98(who, *(s32 *)(cfg + 88), 0, 0, 1, 1, 3, 0, cfg[156] != 0, 0, *(f32 *)(cfg + 92), 10.0f, 1.0f);
    }
    if (*(s16 *)(m + 196) != 1) {
        return func_0038CAD0(obj + 100) ? 0 : 2;
    }
    *(s32 *)(obj + 100) = func_00382498(300, 480);
    *(s128 *)(m + 1184) = *(s128 *)(m + 176);
    return 1;
}
/* localdecomp:end func_L01_00334250 */

/* localdecomp:start func_L01_00334358 */
#include "vu0.h"
/* PROVISIONAL, VU0 j-constraint form: the two hitdelta sequences interleave an addiu with the VU0 ops. */
typedef struct {
    u8 p0[0x198]; f32 height; u8 p19c[0x3f0-0x19c];
    vu0_v4 chosen, target, spare, best;
    u8 p1c0[4]; f32 distance; u8 p1c8[8]; s32 handle;
} State_0035CC10;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; State_0035CC10 *state; } Moby_0035CC10;
typedef struct { u8 p0[0x18]; s32 handle; u8 p1c[4]; vu0_v4 pos; } Hit_0035CC10;
extern Hit_0035CC10 D_L01_001EAA00;
typedef struct { u8 p0[0xD0]; vu0_v4 pos; u8 pE0[0x25C0-0xE0]; s32 handle; } Hero_0035CC10;
extern Hero_0035CC10 D_001A4BE0_00334358;
extern vu0_v4 D_L01_001EAA20;
void func_L01_00334358(Moby_0035CC10 *m, State_0035CC10 *s, f32 minimum) {
    extern void *func_00382348(s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CF38(void *, void *);

    vu0_v4 from, to, test, delta, hitdelta;
    u8 *object;
    f32 angle, heading, length, rad, distance, previous;
    *(vu0_q *)&s->chosen = *(vu0_q *)&s->target;
    *(vu0_q *)&from = *(vu0_q *)&m->pos;
    *(vu0_q *)&to = *(vu0_q *)&s->target;
    from.z += s->height;
    to.z += s->height;
    object = func_00382348(s->handle);
    if (s->handle == D_001A4BE0_00334358.handle) {
        *(vu0_q *)&to = *(vu0_q *)&D_001A4BE0_00334358.pos;
    } else if (object) {
        to.z += *(f32 *)(object + 0x10);
    }
    if (!func_003D3CB0(&from, &to, 0x10, m, 0)) return;
    if (D_L01_001EAA00.handle && D_L01_001EAA00.handle == s->handle) return;
    for (angle = 10.0f; angle <= 100.0f; angle += 10.0f) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(to), "m"(from) : "vf1", "vf2");
        heading = func_0038D160(delta.x, delta.y);
        length = func_0038CED8(&delta);
        if (length < minimum) length = minimum;
        rad = (angle * 0.017453292f);
        test.x = func_0038D098(func_0038DAB8(rad, heading)) * length;
        test.y = func_0038D0B0(func_0038DAB8(rad, heading)) * length;
        test.z = 0.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(test) : "m"(from), "m"(test) : "vf1", "vf2");
        if (test.x < 0.0f) test.x = 0.5f;
        if (test.y < 0.0f) test.y = 0.5f;
        if (test.z < 0.0f) test.z = 0.5f;
        if (!func_003D3CB0(&from, &test, 0x10, m, 0)) {
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
            return;
        }
        if (D_L01_001EAA00.handle && D_L01_001EAA00.handle == s->handle)
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
        {
            vu0_q hq1, hq2, hqr;
            __asm__("lqc2 %0, %1" : "=j"(hq1) : "m"(m->pos));
            __asm__("lqc2 %0, %1" : "=j"(hq2) : "m"(D_L01_001EAA20));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(hqr) : "j"(hq1), "j"(hq2));
            __asm__("sqc2 %1, %0" : "=m"(hitdelta) : "j"(hqr));
        }
        distance = func_0038CED8(&hitdelta);
        if (s->distance < distance && angle < 60.0f) {
            previous = func_0038CF38(&D_L01_001EAA20, &s->target);
            if (previous < func_0038CF38(&s->best, &s->target)) {
                s->distance = distance;
                *(vu0_q *)&s->best = *(vu0_q *)&D_L01_001EAA20;
            }
        }
        rad = -(angle * 0.017453292f);
        test.x = func_0038D098(func_0038DAB8(rad, heading)) * length;
        test.y = func_0038D0B0(func_0038DAB8(rad, heading)) * length;
        test.z = 0.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(test) : "m"(from), "m"(test) : "vf1", "vf2");
        if (test.x < 0.0f) test.x = 0.5f;
        if (test.y < 0.0f) test.y = 0.5f;
        if (test.z < 0.0f) test.z = 0.5f;
        if (!func_003D3CB0(&from, &test, 0x10, m, 0)) {
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
            return;
        }
        if (D_L01_001EAA00.handle && D_L01_001EAA00.handle == s->handle)
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
        {
            vu0_q hq1, hq2, hqr;
            __asm__("lqc2 %0, %1" : "=j"(hq1) : "m"(m->pos));
            __asm__("lqc2 %0, %1" : "=j"(hq2) : "m"(D_L01_001EAA20));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(hqr) : "j"(hq1), "j"(hq2));
            __asm__("sqc2 %1, %0" : "=m"(hitdelta) : "j"(hqr));
        }
        distance = func_0038CED8(&hitdelta);
        if (s->distance < distance && angle < 60.0f) {
            s->distance = distance;
            *(vu0_q *)&s->best = *(vu0_q *)&D_L01_001EAA20;
        }
    }
}
/* localdecomp:end func_L01_00334358 */

/* localdecomp:start func_L01_003347C0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_3347C0;

extern s32 func_003D3CB0(void *from, void *to, s32 mask, void *skip, s32 t0);
extern void *D_L01_001EAA18[];

/* A line from moby's position (0.1 u up) to the point at d +0x400, both raised by d +0x198:
 * when nothing is in the way, or only what d +0x440 holds, d's +0x3F0 and +0x410 take that
 * point. */
void func_L01_003347C0(u8 *moby, u8 *d)
{
    Vec_3347C0 from;
    Vec_3347C0 to;

    from = *(Vec_3347C0 *)(moby + 0x10);
    to = *(Vec_3347C0 *)(d + 0x400);
    from.z = from.z + 0.1f + *(f32 *)(d + 0x198);
    to.z = to.z + *(f32 *)(d + 0x198);
    if (func_003D3CB0(&from, &to, 16, moby, 0) == 0 ||
        (D_L01_001EAA18[0] != 0 && D_L01_001EAA18[0] == *(void **)(d + 0x440))) {
        *(u128_t *)(d + 0x3F0) = *(u128_t *)(d + 0x400);
        *(u128_t *)(d + 0x410) = *(u128_t *)(d + 0x400);
    }
}
/* localdecomp:end func_L01_003347C0 */

LINKER_REMNANT("asm/levels", func_L01_00334860);

/* localdecomp:start func_L01_00334868 */
extern f32 func_0038CF38(void *, void *);
extern u8 *D_L01_001E0100;
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern u8 *D_001A71A0[];
extern u8 *D_L01_001DFC48;
extern s32 D_L01_001D6774;
extern u8 *D_L01_001EFFE8[];
extern s32 D_L01_001F01E8[];
extern u32 D_00142BA0[];
extern u8 D_001BBC40[][16];
extern void func_L01_0032A0C8(u8 *, u8 *, s32);
extern void func_L01_0032A118(u8 *, u8 *, s32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00456270(s32);
extern s32 func_L01_00456B40(u8 *, u8 *, f32, f32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_00456250(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00333F18(u8 *);

s32 func_L01_00334868(u8 *a0, u8 *obj, u8 *who, u8 *m, u8 *t0, u8 *cfg, u8 *t2)
{
    s8 *conds;
    s32 hit;
    u8 *mob;
    u8 *found;

    if (*(s8 *)(obj + 0x5C) != -1) {
        return 1;
    }
    conds = (s8 *)(cfg + 0x30);
    if (conds[0] != 0) {
        hit = 0;
        if (*(s32 *)(cfg + 0x4C) == -1) {
            if (*(s32 *)(cfg + 0x48) != -1) {
                mob = D_L01_001E001C + (*(s32 *)(cfg + 0x48) << 8);
            } else {
                mob = D_001A71A0[0];
            }
            if (*(s32 *)(cfg + 0x40) != -1) {
                hit = func_L01_00456500(mob + 0x10, *(s32 *)(cfg + 0x40)) != 0;
            } else if (0.0f < *(f32 *)(cfg + 0x44)) {
                if (func_0038CF38(who + 0x10, mob + 0x10) < *(f32 *)(cfg + 0x44)) {
                    hit = 1;
                }
            }
        } else {
            u16 *p = D_L01_0021DE20[*(s32 *)(cfg + 0x4C)];
            while ((*(s32 *)(cfg + 0x4C) & 0xFF) != 0xFF && *(s32 *)(cfg + 0x4C) <= D_L01_001E0058 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(cfg + 0x4C)])) {
                mob = D_L01_001E001C + ((p[0] & 0x7FFF) << 8);
                if (mob == 0) {
                    break;
                }
                if (*(s32 *)(cfg + 0x40) != -1 && func_L01_00456500(mob + 0x10, *(s32 *)(cfg + 0x40)) != 0) {
                    break;
                }
                if (0.0f < *(f32 *)(cfg + 0x44) && func_0038CF38(who + 0x10, mob + 0x10) < *(f32 *)(cfg + 0x44)) {
                    break;
                }
                p++;
            }
        }
        if (hit) {
            func_L01_0032A0C8(t0, a0, 0);
        } else {
            func_L01_0032A118(t0, a0, 0);
        }
    }
    if (conds[1] != 0) {
        found = 0;
        if (*(s32 *)(cfg + 0x50) != -1) {
            u8 *e;
            s32 n;
            s32 j;
            func_L01_00456270(*(s32 *)(cfg + 0x50));
            e = D_L01_001DFC48 + *(s32 *)(cfg + 0x50) * 0xE0;
            n = e[4];
            for (j = 0; j < n; j++, e += 8) {
                if (e[5] == 3 && *(u8 **)e != 0 && (*(u8 **)e)[0x20] != 0xFE && (*(u8 **)e)[0x20] != 0xFD) {
                    found = *(u8 **)e;
                    break;
                }
            }
        } else if (0.0f < *(f32 *)(cfg + 0x54)) {
            s32 i;
            for (i = 0; i < D_L01_001D6774; i++) {
                found = D_L01_001EFFE8[i];
                if (D_L01_001F01E8[i] == 3 && func_L01_00456B40(found, who + 0x10, *(f32 *)(cfg + 0x54), 10.0f) &&
                    found != 0 && found[0x20] != 0xFE && found[0x20] != 0xFD) {
                    break;
                }
                found = 0;
            }
        }
        if (found) {
            func_L01_0032A0C8(t0, a0, 1);
        } else {
            func_L01_0032A118(t0, a0, 1);
        }
    }
    if (conds[2] != 0) {
        found = 0;
        if (*(s32 *)(cfg + 0x58) != -1) {
            u8 *e;
            s32 n;
            s32 j;
            func_L01_00456270(*(s32 *)(cfg + 0x58));
            e = D_L01_001DFC48 + *(s32 *)(cfg + 0x58) * 0xE0;
            n = e[4];
            for (j = 0; j < n; j++, e += 8) {
                if (e[5] == 3 && *(u8 **)e != 0 && (*(u8 **)e)[0x20] != 0xFE && (*(u8 **)e)[0x20] != 0xFD) {
                    found = *(u8 **)e;
                    break;
                }
            }
        } else if (0.0f < *(f32 *)(cfg + 0x5C)) {
            s32 i;
            for (i = 0; i < D_L01_001D6774; i++) {
                found = D_L01_001EFFE8[i];
                if (D_L01_001F01E8[i] == 3 && func_L01_00456B40(found, who + 0x10, *(f32 *)(cfg + 0x5C), 10.0f) &&
                    found != 0 && found[0x20] != 0xFE && found[0x20] != 0xFD) {
                    break;
                }
                found = 0;
            }
        }
        if (found) {
            func_L01_0032A0C8(t0, a0, 2);
        } else {
            func_L01_0032A118(t0, a0, 2);
        }
    }
    if (conds[3] != 0) {
        s32 (*fn)(u8 *) = *(s32 (**)(u8 *))(t2 + 0x6C);
        if (fn != 0 && fn(who) != 0) {
            func_L01_0032A0C8(t0, a0, 3);
        } else {
            func_L01_0032A118(t0, a0, 3);
        }
    }
    if (conds[4] != 0) {
        s32 near = 0;
        if (*(s32 *)(cfg + 0x64) != -1 && cfg[0x10] != 2 && cfg[0x11] != 2) {
            if (func_0038CF38(who + 0x10, D_L01_001E0100 + (*(s32 *)(cfg + 0x64) << 7) + 0x30) < 2.0f) {
                near = 1;
            }
        } else if (*(s32 *)(cfg + 0x60) != -1 && cfg[0x10] != 2 && cfg[0x11] != 2) {
            if (func_0038CF38(who + 0x10, D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8) + 0x10) < 5.0f) {
                near = 1;
            }
        } else if (*(s32 *)(cfg + 0x6C) != -1 && cfg[0x99] == 0) {
            near = obj[0x5E] != 0;
        }
        if (near) {
            func_L01_0032A0C8(t0, a0, 4);
        } else {
            func_L01_0032A118(t0, a0, 4);
        }
    }
    if (conds[5] != 0) {
        if (*(s32 *)(cfg + 0x68) != -1 && func_L01_00445AD0(*(s32 *)(cfg + 0x68), -1, 0) == 0) {
            func_L01_0032A0C8(t0, a0, 5);
        } else {
            func_L01_0032A118(t0, a0, 5);
        }
    }
    if (conds[7] != 0) {
        if (obj[0x5D] != 0) {
            func_L01_0032A0C8(t0, a0, 7);
        } else {
            func_L01_0032A118(t0, a0, 7);
        }
    }
    if (conds[8] != 0) {
        s32 on = 0;
        if (*(s32 *)(cfg + 0x60) != -1) {
            on = func_L01_00456250(D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8)) != 0;
        } else if (*(s32 *)(cfg + 0x48) != -1) {
            on = func_L01_00456250(D_L01_001E001C + (*(s32 *)(cfg + 0x48) << 8)) != 0;
        }
        if (on) {
            func_L01_0032A0C8(t0, a0, 8);
        } else {
            func_L01_0032A118(t0, a0, 8);
        }
    }
    if (conds[9] != 0 && *(s32 *)(cfg + 0x60) != -1) {
        s32 (**v)(u8 *) = (s32 (**)(u8 *))func_L01_0043B568(0xF6E, 0, 4);
        u32 id;
        if (v != 0 && (id = (*v)(D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8)),
                       D_00142BA0[id >> 2] & (1 << (id & 0x1F)))) {
            func_L01_0032A0C8(t0, a0, 9);
        } else {
            func_L01_0032A118(t0, a0, 9);
        }
    }
    if (conds[10] != 0 && *(s32 *)(cfg + 0x74) != -1) {
        if (D_001BBC40[D_001D545C][*(s32 *)(cfg + 0x74)] & 0x80) {
            func_L01_0032A0C8(t0, a0, 10);
        } else {
            func_L01_0032A118(t0, a0, 10);
        }
    }
    if (conds[11] != 0) {
        if (who[0x31] != 0) {
            func_L01_0032A0C8(t0, a0, 11);
        } else {
            func_L01_0032A118(t0, a0, 11);
        }
    }
    if (a0[0x20] == 0x19) {
        if (func_L01_004561B8(a0) == 0) {
            func_L01_0032A0C8(t0, a0, 7);
        } else {
            func_L01_0032A118(t0, a0, 7);
        }
        if (*(s8 *)(obj + 0x5C) != -1) {
            func_L01_00333F18(a0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00334868 */

/* localdecomp:start func_L01_00335150 */

extern s32 *D_L01_0021F6C0[];
extern u8 *D_L01_001E0100;
extern u8 *D_L01_001E001C;
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_00459188(void *, void *, void *);

s32 func_L01_00335150(u8 *a0, s32 a1, u8 *a2, u8 *a3, s32 a4, u8 *a5)
{
    s32 *path;
    f32 d;
    u128_t tmp;

    if (*(s32 *)(a5 + 108) != -1 && a5[153] == 0) {
        path = D_L01_0021F6C0[*(s32 *)(a5 + 108)];
        d = func_0038CF38(a2 + 16, path + 4);
        if (func_0038CF38(a2 + 16, path + path[0] * 4) < d) {
            func_L01_0045C150(a2, path, 0, 0);
        } else {
            func_L01_0045C150(a2, path, path[0] - 1, 0);
        }
    }
    if (a5[16] != 2 && a5[17] != 2) {
        if (*(s32 *)(a5 + 100) != -1) {
            tmp = *(u128_t *)(&D_L01_001E0100[*(s32 *)(a5 + 100) << 7] + 48);
            func_L01_004591B8(a2, &tmp, a3 + 1008);
        } else if (*(s32 *)(a5 + 96) != -1) {
            func_L01_00459188(a2, D_L01_001E001C + *(s32 *)(a5 + 96) * 256, a3 + 1008);
        }
    }
    a0[188] = 0;
    return 0;
}
/* localdecomp:end func_L01_00335150 */

/* localdecomp:start func_L01_003352B8 */

extern void func_L01_00334358(void *, void *, f32);

s32 func_L01_003352B8(void *a, u8 *b, u8 *c, u8 *d) {
    u8 *t = *(u8 **)(d + 0xC0);

    *(u8 **)(d + 0x440) = t;
    *(u128_t *)(d + 0x400) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x3F0) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x410) = *(u128_t *)(t + 0x10);
    func_L01_00334358(c, d, 12.0f);
    *(u128_t *)(b + 0x80) = *(u128_t *)(c + 0x10);
    *(u128_t *)(d + 0x4A0) = *(u128_t *)(d + 0x400);
    return 0;
}
/* localdecomp:end func_L01_003352B8 */

/* localdecomp:start func_L01_00335338 */
extern s32 *D_L01_0021F6C0[];
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);

s32 func_L01_00335338(u8 *a0, u8 *a1, u8 *a2, s32 a3, s32 t0, u8 *t1) {
    s32 i = *(s32 *)(t1 + 108);
    if (i != -1) {
        s32 *s = D_L01_0021F6C0[i];
        f32 d = func_0038CF38(a2 + 16, s + 4);
        if (func_0038CF38(a2 + 16, s + s[0] * 4) < d) {
            func_L01_0045C150(a2, s, 0, 0);
        } else {
            func_L01_0045C150(a2, s, s[0] - 1, 0);
        }
    }
    a0[188] = 0;
    a1[94] = 0;
    return 0;
}
/* localdecomp:end func_L01_00335338 */
