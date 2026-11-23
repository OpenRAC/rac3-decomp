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

INCLUDE_ASM("asm/levels", func_L01_003326A8);

/* localdecomp:start func_L01_00333D80 */
extern u8 *D_L01_001E001C;
s32 func_L01_00333D80(u8 *m)
{
    extern void func_L01_003362B0(u8 *,s32);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern Vt00335B98 *func_L01_0043B568(s32,s32,s32);
    extern void func_L01_00329F00(u8 *,u8 *);
    u8 *vars;
    u8 *table;
    u8 *child;
    u8 *parent;
    if (m[0x20]==0) {
        u8 *init;
        init=*(u8 **)(m+0x68);
        *(u8 **)(init+0x2C)=init+0x30;
        *(s32 *)(init+0x50)=-1;
        *(s32 *)(init+0x60)=0;
        *(s32 *)(init+0x64)=0;
        *(s32 *)(init+0x68)=0;
        *(s32 *)(init+0x54)=0;
        *(s32 *)(init+0x58)=0;
        ((s8 *)init)[0x5C]=-1;
        init[0x5D]=0;
        init[0x5E]=0;
        init[0x5F]=0;
        if (*(s32 *)(init+0x30)>0) {
            *(s32 *)(init+0x30)=-1;
            init[0x3E]=3;
            func_L01_003362B0(m,0);
        } else {
            func_L01_004450F0(m,1,-1);
        }
        return 1;
    } else if (m[0x20]==1) {
        u8 *base;
        vars=*(u8 **)(m+0x68);
        table=(u8 *)func_L01_0043B568(*(s32 *)(vars+0x40),4,156);
        *(u8 **)(m+0xB8)=D_L01_001E001C+(*(s32 *)(vars+0x44)<<8);
        child=(*(u8 *(**)(u8 *))table)(m);
        base=D_L01_001E001C;
        *(s32 *)(vars+0x50)=(child-base)>>8;
        func_L01_00329F00(base+(*(s32 *)(vars+0x44)<<8),m);
        *(s32 *)(vars+0x4C)=-1;
        parent=*(u8 **)(m+0xB8);
        if (parent!=0 && child!=0) {
            u8 *pv=*(u8 **)(parent+0x68);
            if (pv[0x90]!=0 && *(void (**)(u8 *))(table+0x90)!=0) {
                (*(void (**)(u8 *))(table+0x90))(child);
            }
            *(u16 *)(vars+0x7A)=*(u16 *)((*(u8 *(**)(u8 *))(table+0x94))(child)+0x34);
        }
        func_L01_004450F0(m,2,-1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00333D80 */

INCLUDE_ASM("asm/levels", func_L01_00333F18);

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

INCLUDE_ASM("asm/levels", func_L01_00334358);

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

INCLUDE_ASM("asm/levels", func_L01_00335418);

/* localdecomp:start func_L01_003355B8 */
extern u8 D_001A4BE0[];
extern u8 *D_L01_001E001C;
extern void func_L01_00334358(void *, void *, f32);

/* As func_L01_003352B8, aimed at the record cfg +0x60 names (0x100-byte records at
 * D_L01_001E001C) or, with none (-1), at the hero's moby. Each arm copies its target's
 * position itself: retail has the copy once, merged from the two arms' tails. */
s32 func_L01_003355B8(u8 *a0, u8 *b, u8 *c, u8 *d, s32 t0, u8 *cfg)
{
    u8 *t;
    s32 idx = *(s32 *)(cfg + 0x60);

    if (idx != -1) {
        t = D_L01_001E001C + (idx << 8);
        *(u128_t *)(d + 0x4A0) = *(u128_t *)(t + 0x10);
    } else {
        t = *(u8 **)(D_001A4BE0 + 0x25C0);
        *(u128_t *)(d + 0x4A0) = *(u128_t *)(t + 0x10);
    }
    *(u8 **)(d + 0x440) = t;
    *(u128_t *)(d + 0x400) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x3F0) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x410) = *(u128_t *)(t + 0x10);
    func_L01_00334358(c, d, 12.0f);
    *(u128_t *)(b + 0x80) = *(u128_t *)(c + 0x10);
    *(u128_t *)(d + 0x4A0) = *(u128_t *)(t + 0x10);
    return 0;
}
/* localdecomp:end func_L01_003355B8 */

/* localdecomp:start func_L01_00335670 */
s32 func_L01_00335670(u8 *a, u8 *b, u8 *m, u8 *d, s32 value, u8 *cfg, u8 *vt)
{
    extern s32 func_L01_0045BDE8(u8 *, s32);
    extern s32 func_L01_00335150(u8 *, s32, u8 *, u8 *, s32, u8 *);
    extern void func_L01_00458F78(u8 *, void *, s32, s32);
    extern void func_L01_0045A748(u8 *, void *);
    if (*(s32 *)(cfg + 0x6C) != -1 && cfg[0x99] == 0 && b[0x5E] == 0) {
        if (func_L01_0045BDE8(m, *(s32 *)(cfg + 0x6C))) {
            func_L01_00335150(a, (s32)b, m, d, value, cfg);
            b[0x5E] = 1;
        }
    } else if (cfg[0x10] != 2 && cfg[0x11] != 2) {
        if (*(s32 *)(cfg + 0x64) != -1 || *(s32 *)(cfg + 0x60) != -1) {
            u8 *position = d + 0x3F0;
            func_L01_00458F78(m, position, 0, 0);
            func_L01_0045A748(m, position);
        }
    }
    if (cfg[0x97] == 0) {
        (*(void (**)(u8 *, s32, s32))(vt + 0x24))(m, 0, 8);
    } else {
        (*(void (**)(u8 *, s32, s32))(vt + 0x20))(m, 0, 8);
    }
    return 0;
}
/* localdecomp:end func_L01_00335670 */

/* localdecomp:start func_L01_003357C8 */
s32 func_L01_003357C8(u8 *a, u8 *b, u8 *m, u8 *d, s32 value, u8 *cfg, u8 *vt)
{
    extern void func_L01_003347C0(u8 *, u8 *);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00334358(void *, void *, f32);
    extern s32 func_L01_0045A748(u8 *, void *);
    u128_t target;
    func_L01_003347C0(m,d);
    target=*(u128_t *)(*(u8 **)(d+0x440)+0x10);
    if (func_0038CF38(d+0x410,&target)>1.0f ||
        func_0038CF38(m+0x10,d+0x3f0)<0.75f ||
        func_0038CF38(m+0x10,b+0x80)>4.0f) {
        u8 *t=*(u8 **)(d+0x440);
        *(u128_t *)(d+0x3f0)=*(u128_t *)(t+0x10);
        *(u128_t *)(d+0x410)=*(u128_t *)(t+0x10);
        func_L01_00334358(m,d,12.0f);
        *(u128_t *)(b+0x80)=*(u128_t *)(m+0x10);
        *(s32 *)(d+0x430)=0;
    }
    func_L01_0045A748(m,d+0x3f0);
    *(u128_t *)(d+0x400)=*(u128_t *)(*(u8 **)(d+0x440)+0x10);
    if (cfg[0x97]==0) (*(void (**)(u8 *,s32,s32))(vt+0x24))(m,0,8);
    else (*(void (**)(u8 *,s32,s32))(vt+0x20))(m,0,8);
    return 0;
}
/* localdecomp:end func_L01_003357C8 */

/* localdecomp:start func_L01_00335950 */
extern s32 *D_L01_0021F6C0[];
s32 func_L01_00335950(u8 *a, u8 *b, u8 *c, u8 *d, s32 t0, u8 *cfg, u8 *vt) {
    extern s32 func_L01_0045BDE8(u8 *, s32);
    extern void func_L01_0045C150(void *, void *, s32, s32);
    s32 old;
    if (*(s32 *)(cfg+0x6c) != -1 && b[0x5e] == 0) {
        old=*(s16 *)(d+0x258);
        if (func_L01_0045BDE8(c,*(s32 *)(cfg+0x6c))) {
            if (cfg[0x13]==3 || cfg[0x13]==4) {
                s32 *path=D_L01_0021F6C0[*(s32 *)(cfg+0x6c)];
                if (*(s16 *)(d+0x25a)==0) {
                    func_L01_0045C150(c,path,path[0]-1,0);
                } else {
                    func_L01_0045C150(c,path,0,0);
                }
            } else {
                b[0x5e]=1;
                a[0xbc]=1;
            }
            if (cfg[0x13]==4) a[0xbc]=1;
        } else if (cfg[0x13]==2 || cfg[0x13]==4) {
            if (*(s16 *)(d+0x258)!=old) a[0xbc]=1;
        }
    }
    if (cfg[0x97]==0) {
        (*(void (**)(u8 *,s32,s32))(vt+0x24))(c,0,8);
    } else {
        (*(void (**)(u8 *,s32,s32))(vt+0x20))(c,0,8);
    }
    return 0;
}
/* localdecomp:end func_L01_00335950 */

/* localdecomp:start func_L01_00335AD0 */
typedef void (*Callback_00335AD0)(u8 *, s32, s32);
s32 func_L01_00335AD0(u8 *a, u8 *b, u8 *moby, u8 *state, s32 value, u8 *cfg, Callback_00335AD0 *vt) {
    extern void func_L01_0045A898(u8 *, void *, f32);
    extern f32 func_0038D160(f32, f32);
    extern void func_L01_00448890(f32 *, f32 *, s32, f32, f32, f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern s32 func_L01_00335418(u8 *, u8 *, u8 *, u8 *, s32, u8 *);
    extern s32 func_0038CAD0(u8 *);
    extern s32 func_00382498(s32, s32);
    f32 *yaw=(f32 *)(moby+0xf8);
    f32 *target=(f32 *)(state+0x4a0);
    f32 angle;
    func_L01_0045A898(moby,target,*yaw);
    angle=func_0038D160(*(f32 *)(state+0x4a0)-*(f32 *)(moby+0x10),*(f32 *)(state+0x4a4)-*(f32 *)(moby+0x14));
    func_L01_00448890(yaw,(f32 *)(b+0x74),0,angle,
        *(f32 *)(state+0x1a4)*0.2f,*(f32 *)(state+0x1a8)*0.2f,*(f32 *)(state+0x1ac)*0.2f);
    if(func_0038CF38(moby+0x10,target)<2.0f) {
        func_L01_00335418(a,b,moby,state,value,cfg);
    }
    if(func_0038CAD0(b+0x68)) {
        a[0xbc]=1;
        *(s32 *)(b+0x68)=func_00382498(300,530);
    }
    if(!cfg[0x97]) vt[9](moby,0,8);
    else vt[8](moby,0,8);
    return 0;
}
/* localdecomp:end func_L01_00335AD0 */

/* localdecomp:start func_L01_00335C58 */
extern u8 *D_L01_001E0100;
extern u8 *D_L01_001E001C;
extern u8 D_001A4BE0[];
s32 func_L01_00335C58(u8 *m, u8 *d, u8 *cfg, u8 *vt, s32 value)
{
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    if (!cfg[0x8f] && *(s32 *)(cfg + 0x64) != -1)
        *(u128_t *)(d + 0x4a0) = *(u128_t *)(D_L01_001E0100 + (*(s32 *)(cfg + 0x64) << 7) + 0x30);
    else if (!cfg[0x8f] && *(s32 *)(cfg + 0x60) != -1)
        *(u128_t *)(d + 0x4a0) = *(u128_t *)(D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8) + 0x10);
    else
        *(u128_t *)(d + 0x4a0) = *(u128_t *)(*(u8 **)(D_001A4BE0 + 0x25c0) + 0x10);
    if (func_0038DBA0(*(f32 *)(m + 0xf8),func_0038D160(*(f32 *)(d + 0x4a0)-*(f32 *)(m + 0x10),*(f32 *)(d + 0x4a4)-*(f32 *)(m + 0x14))) > 0.034906585f) {
        if (*(void (**)(u8 *, s32, s32))(vt + 0x2c))
            (*(void (**)(u8 *, s32, s32))(vt + 0x2c))(m,0,(value*5+2)/6);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00335C58 */

/* localdecomp:start func_L01_00335D60 */
s32 func_L01_00335D60(u8 *a, u8 *b, u8 *c, u8 *d, u8 *cfg, u8 *vt) {
    extern s32 func_0038CAD0(u8 *);
    extern s32 func_00382498(s32,s32);
    if (a[0xbc] == 0) {
        if (*(void (**)(u8 *,s32,s32))(vt+0x5c))
            (*(void (**)(u8 *,s32,s32))(vt+0x5c))(c,1,8);
        if (b[0x5d]) {
            a[0xbc]=1;
            *(s32 *)(b+0x60)=func_00382498(120,240);
        }
    } else if (a[0xbc]==1) {
        if (*(void (**)(u8 *,s32,s32))(vt+0x60))
            (*(void (**)(u8 *,s32,s32))(vt+0x60))(c,0,2);
        if ((cfg[0x16]!=2 && func_0038CAD0(b+0x60)) ||
            (((s8 *)b)[0x5c]!=-1 && func_0038CAD0(b+0x7c))) a[0xbc]=2;
    } else if (a[0xbc]==2) {
        if (*(void (**)(u8 *,s32,s32))(vt+0x64))
            (*(void (**)(u8 *,s32,s32))(vt+0x64))(c,1,2);
        if (b[0x5d]) {
            a[0xbc]=3;
            *(s32 *)(b+0x60)=func_00382498(60,150);
        }
    } else if (a[0xbc]==3) {
        if (*(void (**)(u8 *,s32,s32))(vt+0x68))
            (*(void (**)(u8 *,s32,s32))(vt+0x68))(c,1,2);
        if (func_0038CAD0(b+0x60) && b[0x5d]) a[0xbc]=0;
    }
    return 0;
}
/* localdecomp:end func_L01_00335D60 */

/* localdecomp:start func_L01_00335EC0 */
int func_L01_00335EC0(u8 *a0, int a1) {
    int *p = *(int **)(a0 + 104);
    if (a0[149] || a1 == -1) {
        p[28] = -1;
        return 0;
    }
    p[28] = a1;
    a0[149] = 1;
    return 1;
}
/* localdecomp:end func_L01_00335EC0 */

/* localdecomp:start func_L01_00335EF8 */
/* Whether the moby's pending value (vars +0x70) is set and its busy byte (+0x95) is clear.
   The result is a 64-bit `long`: retail widens the int comparison into it with a plain
   register copy. */
long func_L01_00335EF8(u8 *moby)
{
    long r = 0;

    if (*(s32 *)(*(u8 **)(moby + 0x68) + 0x70) != -1) {
        s32 clear = moby[0x95] == 0;
        r = clear;
    }
    return r;
}
/* localdecomp:end func_L01_00335EF8 */

/* localdecomp:start func_L01_00335F28 */
void func_L01_00335F28(u8 *a, u8 b) {
    (*(u8 **)(a + 104))[92] = b;
}
/* localdecomp:end func_L01_00335F28 */

/* localdecomp:start func_L01_00335F38 */
void func_L01_00335F38(u8 *a, u8 b) {
    (*(u8 **)(a + 104))[93] = b;
}
/* localdecomp:end func_L01_00335F38 */

/* localdecomp:start func_L01_00335F48 */
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
__asm__(".extern D_L01_001E0058, 4");
__asm__(".extern D_L01_001E001C, 16");
u8 *func_L01_00335F48(u8 *parent) {
    extern Vt00335B98 *func_L01_0043B568(s32, s32, s32);
    extern u8 *func_003C24B0(s32, u8 *);
    extern void func_003C3938(u8 *, s32, s32);
    extern void func_0038CB78(void *, s32, s32);
    u8 *moby = 0;
    u8 *vars = 0;
    u8 *cfg = *(u8 **)(parent + 0x68);
    Vt00335B98 *vt = func_L01_0043B568(*(s32 *)(cfg + 0x40), 4, 0x9C);
    u16 *p;
    s32 found;
    if (*(s32 *)(cfg + 0x48) != -1) {
        p = D_L01_0021DE20[*(s32 *)(cfg + 0x48)];
        found = 0;
        while ((*(s32 *)(cfg + 0x48) & 0xFF) != 0xFF &&
               *(s32 *)(cfg + 0x48) <= D_L01_001E0058 && p &&
               ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(cfg + 0x48)])) {
            moby = D_L01_001E001C + ((p[0] & 0x7FFF) << 8);
            if (!moby) break;
            vars = vt->fn(moby);
            if (*(s16 *)(moby + 0xAA) == *(s32 *)(cfg + 0x40) && !*(s32 *)(vars + 0x470)) {
                found = 1;
                break;
            }
            p++;
        }
        if (!found) return 0;
        if (moby) {
            u8 *object = *(u8 **)(moby + 0x24);
            *(u16 *)(moby + 0x34) &= 0xFFBC;
            *(u16 *)(moby + 0x34) |= *(u16 *)(object + 0x44) & 0x1000;
            *(s32 *)(moby + 0x98) = *(s32 *)(object + 0x10);
        }
    } else {
        moby = func_003C24B0(*(s32 *)(cfg + 0x40), (*(u8 *(**)(void))((u8 *)vt + 0x98))());
        vars = vt->fn(moby);
    }
    moby[0x30] = parent[0x30];
    *(u16 *)(moby + 0x32) = 0x80;
    moby[0x31] = 1;
    if (*(u16 *)(parent + 0x34) & 0x80) {
        *(u16 *)(moby + 0x34) |= 0x80;
    } else {
        *(u16 *)(moby + 0x34) &= 0xFF7F;
    }
    func_003C3938(moby, 0, 0);
    if (parent) {
        *(u8 **)(moby + 0xB8) = parent;
        *(u128_t *)(moby + 0x10) = *(u128_t *)(parent + 0x10);
        *(u128_t *)(moby + 0xF0) = *(u128_t *)(parent + 0xF0);
        *(unsigned long *)(moby + 0x38) = *(unsigned long *)(parent + 0x38);
    }
    if (*(s32 *)(cfg + 0x48) == -1) {
        func_0038CB78(vars, 0, 0x4D0);
        *(u16 *)(moby + 0x34) |= 0x20;
        *(u8 **)(vars + 0) = vars + 0x30;
        *(u8 **)(vars + 8) = vars + 0x70;
        *(u8 **)(vars + 0xC) = vars + 0xB0;
        *(u8 **)(vars + 0x10) = vars + 0xD0;
        *(u8 **)(vars + 0x1C) = vars + 0x190;
    }
    *(s32 *)(vars + 0x470) = 1;
    (*(u8 **)(moby + 0x24))[0x46] = 14;
    *(u16 *)(moby + 0x34) &= 0xEFFF;
    return moby;
}
/* localdecomp:end func_L01_00335F48 */

/* localdecomp:start func_L01_003361D8 */
extern Vt00335B98 *func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);
extern void func_003C2880(u8 *a0);
void func_L01_003361D8(u8 *a0) {
    u8 *s0 = *(u8 **)(*(u8 **)(a0 + 184) + 104);
    u8 *r;
    r = func_L01_0043B568(*(s32 *)(s0 + 64), 4, 156)->fn(a0);
    *(s32 *)(r + 1136) = 0;
    *(s32 *)(s0 + 80) = -1;
    *(s32 *)(a0 + 152) = 0;
    *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x43) & 0xEFFF;
    func_L01_004AA7E8(a0, 1);
    if (*(s32 *)(s0 + 72) == -1) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003361D8 */

/* localdecomp:start func_L01_00336270 */
__asm__(".extern D_L01_001DCF08, 4");
extern s32 D_L01_001DCF08;
__asm__(".extern D_L01_001DCF18, 4");
extern s32 D_L01_001DCF18;

void *func_L01_00336270(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {                                 /* irregular */
    case 0:
        *arg2 = 0x10;
        return &D_L01_001DCF08;
    case 1:
        *arg2 = 0x1C;
        return &D_L01_001DCF18;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_00336270 */

/* localdecomp:start func_L01_003362B0 */
extern Vt00335B98 *func_L01_0043B568(s32 a0, s32 a1, s32 a2);

extern u8 *D_L01_001E001C;
extern Fn_335C70 *func_L01_0043B548(s32, s32);
extern void func_003C2880(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L01_003362B0(u8 *m, s32 flag) {
    u8 *v = *(u8 **)(m + 104);
    u8 *o = 0;
    Fn_335C70 *r;
    Fn_335C70 *t;
    s32 idx;

    r = ((Fn_335C70 * (*)(s32, s32, s32))func_L01_0043B568)(*(s32 *)(v + 64), 4, 156);
    if (*(u8 **)(m + 184) != 0) {
        o = *(u8 **)(*(u8 **)(m + 184) + 104);
    }
    idx = *(s32 *)(v + 80);
    if (idx != -1) {
        r[1](D_L01_001E001C + (idx << 8));
    }
    if (*(s32 *)(v + 48) != 0) {
        t = func_L01_0043B548(6625, 108);
        t[0](m);
        if (flag != 0) {
            t[1](m);
        }
    } else if (o == 0 || *(s16 *)(o + 140) == -1) {
        func_003C2880(m);
    } else {
        *(s32 *)(v + 80) = -1;
        func_L01_004450F0(m, 4, -1);
    }
}
/* localdecomp:end func_L01_003362B0 */

/* localdecomp:start func_L01_003363B0 */
void func_L01_003363B0(u8 *a, u8 *b) {
    u8 *s = *(u8 **)(b + 104);
    u8 *d = *(u8 **)(a + 104);
    *(s32 *)(d + 64) = *(s32 *)(s + 108);
    *(s32 *)(d + 72) = *(s32 *)(s + 124);
    *(s32 *)(d + 68) = *(s32 *)(s + 112);
}
/* localdecomp:end func_L01_003363B0 */

/* localdecomp:start func_L01_003363D8 */
f32 func_L01_003363D8(void) {
    return 0.75f;
}
/* localdecomp:end func_L01_003363D8 */

/* localdecomp:start func_L01_003363E8 */
extern void func_L01_003362B0(u8 *m, s32 flag);
void func_L01_003363E8(void *a0) {
    ((void (*)(void *a0, s32 a1))func_L01_003362B0)(a0, 0);
}
/* localdecomp:end func_L01_003363E8 */

/* localdecomp:start func_L01_00336408 */
void func_L01_00336408(u8 *obj) {
    (*(u8 **)(obj + 104))[120] = 1;
}
/* localdecomp:end func_L01_00336408 */

/* localdecomp:start func_L01_00336418 */
extern u8 *D_L01_001E001C;
void func_L01_00336418(u8 *m,f32 yaw,f32 offset,f32 value) {
 extern Vt00335B98 *func_L01_0043B568(s32,s32,s32);
 extern s32 func_00382498(s32,s32);
 extern f32 func_003824E0(f32,f32);
 extern f32 func_0038DAB8(f32,f32);
 u8 *vars=*(u8 **)(m+0x68);
 u8 *r=func_L01_0043B568(*(s32 *)(vars+0x40),4,156)->fn(D_L01_001E001C+(*(s32 *)(vars+0x50)<<8));
 *(s32 *)(vars+0x6c)=func_00382498(1,6);
 *(f32 *)(r+0x480)=value;
 *(f32 *)(r+0x484)=func_0038DAB8(yaw,func_003824E0(-0.008726646f,0.008726646f));
 *(f32 *)(r+0x488)=func_0038DAB8(yaw,offset);
 *(f32 *)(r+0x48c)=func_003824E0(4.0f,6.0f);
}
/* localdecomp:end func_L01_00336418 */

/* localdecomp:start func_L01_00336500 */
extern Vt00335B98 *func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern u8 *D_L01_001E001C;

/* Sets +0x4B0 of what the vtable call (func_L01_0043B568 +0x94) returns for the moby's record
 * (vars +0x50, 0x100-byte records at D_L01_001E001C) to v. */
void func_L01_00336500(u8 *m, s128 *v)
{
    u8 *vars = *(u8 **)(m + 0x68);
    u8 *r;

    r = func_L01_0043B568(*(s32 *)(vars + 0x40), 4, 156)->fn(D_L01_001E001C + (*(s32 *)(vars + 0x50) << 8));
    *(s128 *)(r + 0x4B0) = *v;
}
/* localdecomp:end func_L01_00336500 */

/* localdecomp:start func_L01_00336560 */
extern Vt00335B98 *func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern u8 *D_L01_001E001C;

/* Reads it back: func_L01_00336500's +0x4B0 into out. */
void func_L01_00336560(u8 *m, s128 *out)
{
    u8 *vars = *(u8 **)(m + 0x68);
    u8 *r;

    r = func_L01_0043B568(*(s32 *)(vars + 0x40), 4, 156)->fn(D_L01_001E001C + (*(s32 *)(vars + 0x50) << 8));
    *out = *(s128 *)(r + 0x4B0);
}
/* localdecomp:end func_L01_00336560 */

INCLUDE_ASM("asm/levels", func_L01_003365C0);

INCLUDE_ASM("asm/levels", func_L01_00336D90);

INCLUDE_ASM("asm/levels", func_L01_00337880);

/* localdecomp:start func_L01_00337E10 */
/* The wrench object's animation: sequence 11 while the hero is in state 0x37, else from
   sequences 11, 19 and 18 back to 1. Both blends go through one helper that skips the call
   when the moby already plays the sequence; the current sequence comes from an int accessor
   narrowed to a byte, which is what leaves retail's `andi` and its copy of the raw value. */
extern u8 D_001A4BE0[];
extern void func_003C3A10(u8 *, s32, s32, s32);

static inline s32 seq_00337E10(u8 *moby)
{
    return moby[0x43];
}

static inline void blend_00337E10(u8 *moby, s32 seq, s32 start, s32 frames)
{
    if (moby[0x43] != seq) {
        func_003C3A10(moby, seq, start, frames);
    }
}

void func_L01_00337E10(u8 *moby)
{
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x37) {
        blend_00337E10(moby, 11, 0, 6);
    } else {
        u8 seq = seq_00337E10(moby);

        if (seq == 11 || seq == 19 || seq == 18) {
            blend_00337E10(moby, 1, 0, 14);
        }
    }
}
/* localdecomp:end func_L01_00337E10 */

/* localdecomp:start func_L01_00337EA8 */
extern void *D_L01_001EAA18[];
extern u8 *func_00382348(void *);
s32 func_L01_00337EA8(void) {
    s32 r = 0;
    u8 *v = 0;
    if (D_L01_001EAA18[0] != 0) {
        v = func_00382348(D_L01_001EAA18[0]);
    }
    if (v != 0) {
        r = v[9] == 1;
    }
    return r;
}
/* localdecomp:end func_L01_00337EA8 */

/* localdecomp:start func_L01_00337EF8 */
extern u8 *func_00382348(void *);
extern void *D_L01_001EAA18[];


s32 func_L01_00337EF8(void) {
    Obj_003378A0 *p = ((Obj_003378A0 * (*)(s32))func_00382348)(((s32 *)&D_L01_001EAA18)[0]);
    if (p != 0 && (p->flags & 2)) return 1;
    return 0;
}
/* localdecomp:end func_L01_00337EF8 */

/* localdecomp:start func_L01_00337F38 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_337F38;

extern u8 D_001A4BE0[];
extern s32 func_L01_003303B8(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_00382760(Vec_337F38 *out, f32 length, f32 yaw, f32 pitch);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(f32 *position, s32 life, s32 colour, s32 roll_kind, s32 spin, Vec_337F38 *velocity,
                             f32 size, f32 start_size, f32 unk, s32 delay);

/* wrench_spark_burst: a burst of count flashes at position (wrench_sparks adds it in the jump
 * attack); with Giant Clank in a wrench attack state, an explosion instead. */
void func_L01_00337F38(f32 *position, s32 count)
{
    Vec_337F38 velocity;
    Vec_337F38 at;       /* unread */
    f32 size;
    f32 yaw;
    f32 pitch;
    s32 spin;
    s32 state;
    s32 i;
    u8 *hero = D_001A4BE0;

    if (*(s32 *)(hero + 0x234) != 0) { /* Giant Clank */
        state = *(s32 *)(hero + 0x25C4);
        /* the combo, 0x20, the grind attack, 0x72 and the jump attack: an explosion at S 0.5 */
        if (state == 0x13 || state == 0x20 || state == 0x2A || state == 0x72 || state == 0x14) {
            func_L01_003303B8(position, 0, 10, 10, 10, 20, 0, 1, 0.5f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            return;
        }
    }
    for (i = 0; i < count; i++) {
        size = func_003824E0(0.1f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) {
            spin--;
        }
        yaw = func_00382538();
        pitch = func_003824E0(0.34906584f, 1.5358897f); /* 20 to 88 degrees up */
        func_00382760(&velocity, func_003824E0(0.05f, 0.1f), yaw, pitch);
        at = *(Vec_337F38 *)position; /* a copy retail makes and never reads */
        position[0] += func_L01_00443A18(0.0f, 0.15f);
        position[1] += func_L01_00443A18(0.0f, 0.15f);
        position[2] += func_L01_00443A18(0.0f, 0.15f);
        func_L01_0046B458(position, 25, 0x7F207F7F, 0, spin, &velocity, size * 0.1f, size, 0.003f, 0);
        func_L01_0046B458(position, 25, 0x7F7F7F7F, 1, -spin, &velocity, size * 0.07f, size * 0.7f, 0.003f, 0);
    }
}
/* localdecomp:end func_L01_00337F38 */

INCLUDE_ASM("asm/levels", func_L01_00338230);

/* localdecomp:start func_L01_003384B0 */
extern u8 D_00142CBA[];
extern u8 *D_L01_001E0028;
typedef struct { u8 pad[0x25C0]; void *hero; } Hero_003384B0;
extern Hero_003384B0 D_001A4BE0_003384B0;
__asm__(".extern D_001A4BE0_003384B0,16");
void func_L01_003384B0(u8 *obj) {
    extern f32 func_0038CF00(void *,void *);
    extern s32 func_L01_002F8D40(void *,void *,s32,f32,f32);
    extern s32 func_L01_0044AF68(void *);
    extern s32 func_L01_0030F4E8(void *);
    u8 *p;
    f32 range=2.7f;
    if (D_00142CBA[0]) range=10.0f;
    p=D_L01_001E0028;
    if (p) do {
        s32 r;
        s32 state=p[0x20];
        if (state==254) break;
        if (state==253) break;
        if (p && *(u8 **)(p+0x24) && (*(u8 **)(p+0x24))[0x46]==19) {
            if (func_0038CF00(p+0x10,obj+0x10)<range) {
                r=func_L01_002F8D40(p,D_001A4BE0_003384B0.hero,0,func_003824E0(-30.0f,30.0f)*0.017453292f,0.0f);
            } else goto next;
        } else {
            if (!func_L01_0044AF68(p)) goto next;
            if (func_0038CF00(p+0x10,obj+0x10)<range) r=func_L01_0030F4E8(p);
            else goto next;
        }
        if (r) break;
    next:
        p=*(u8 **)(p+0x28);
    } while (p);
}
/* localdecomp:end func_L01_003384B0 */

/* localdecomp:start func_L01_00338628 */
extern u8 D_001A4BE0[];
extern f32 func_0038D160(f32 y, f32 x);
extern f32 func_0038DBA0(f32 a, f32 b);
extern f32 func_0038CEA8(void *v);
extern void func_0038CF68(void *out, void *in, f32 s);

/* wrench_line_shorten: shortens a line from the hero by its angle off his facing (hero yaw at
 * D_001A4BE0 + 0x98): full length at 0, down to 70% at 105 degrees and beyond. */
void func_L01_00338628(f32 *line)
{
    f32 shorten_at = 1.8325957f; /* 105 degrees */
    f32 out_yaw;
    f32 off;

    out_yaw = func_0038D160(line[0], line[1]);
    off = func_0038DBA0(*(f32 *)(D_001A4BE0 + 0x98), out_yaw);
    if (shorten_at < off) {
        off = shorten_at;
    }
    /* 0.3: the most it shortens by */
    func_0038CF68(line, line, func_0038CEA8(line) * ((shorten_at - off) / shorten_at * 0.3f + 0.7f));
}
/* localdecomp:end func_L01_00338628 */
