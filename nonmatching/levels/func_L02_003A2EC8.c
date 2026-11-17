/* near miss (levels 02 04 06 07 08 09 10 13 14 17 19 21 27 28 34 35): func_L02_003A2EC8, 0x9AC, written from
 * retail by e12 (2026-11-17): 5 aligned rows left. Needs (when it lands) a file cut: this function in its own
 * src/levels/shared/L02_003A2EC8.c with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (split addresses:
 * retail splits D_001A4BE0's %hi/%lo; @ps2as for li.s/dli and the lui-form loads), the rest of
 * L02_003A2C98.c after it (func_L02_003A3878) in L02_003A3878.c with the old line, and the divs_nops line
 * "func_L02_003A2EC8 2 0 2 0 2". What got it here: the color fade computed through separate variables per loop
 * (c0/c1, c2/c3; lesson 3); k as a per-iteration block variable; func_003A9440 void and func_0038C750 s32
 * (v0 choices after the calls); D_L02_001DC9A8/9B8/948/958 as section(".sdata") arrays (one la each, not hoisted
 * by loop.c); e = &s->e60[j] before the uv loop; the two dead float compares are unused clamps with an empty
 * else-if (`if (t < 0.15f) t = 0.15f; else if (t > 1.0f) {}`, `if (1.0f < a) a = 1.0f; else if (a < 0.0f) a = 0.0f;`);
 * the table pick `{ s32 f = s->w10; tbl = 948; if (f) { f32 *t2 = 958; if (w14 >= 3) tbl = t2; } }` (movz and
 * the re-test of w10 kept); the texture id `s32 t = j + 100;`. Left (5 rows): the camera distance block: retail
 * `lui $v1; lw $a0, 0x920($sp); addiu $v0, $v1, %lo(D_L02_001E1140)` (the %hi in a reload register, then the
 * obj reload in the next one, a0), ours ties %hi and the address in v0 and reloads obj into v1. Merging the
 * fog block (D_L02_001E5E40 = D_L02_001E1140 + 0x4D00) into one struct reproduces exactly this block (the
 * shared %hi becomes a global pseudo that reload rematerialises) but then the fog accesses use base 0x1140 +
 * 0x4F38 instead of retail's 0x5E40 + 0x238; a block-scoped `F *fog = &D.fog` at the start/end fixes those
 * again but loses the sharing. So retail shares (high D_L02_001E1140) with something else; not found. */
#include "common.h"

#include "vu0.h"

typedef struct V4_003A2EC8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003A2EC8;

typedef struct Mesh_003A2EC8 {
    s32 count;
    u8 pad4[0xC];
    V4_003A2EC8 pts[1];
} Mesh_003A2EC8;

typedef struct P3_003A2EC8 {
    f32 x, y, z;
} P3_003A2EC8;

typedef struct UV_003A2EC8 {
    f32 u, v;
} UV_003A2EC8;

typedef struct St_003A2EC8 {
    u8 c0[4];
    u8 pad4[4];
    u8 c8[4];
    u8 padC[4];
    s32 w10;
    s32 w14;
    s32 w18;
    u8 pad1C[0x18];
    s32 w34;
    u8 pad38[4];
    s32 w3C;
    f32 f40;
    s32 w44;
    f32 f48;
    f32 f4C;
    f32 f50;
    u8 pad54[8];
    s32 w5C;
    UV_003A2EC8 e60[4];
    V4_003A2EC8 v80;
    s32 w90;
    f32 f94;
    s32 w98;
    f32 f9C;
} St_003A2EC8;

typedef struct G_003A2EC8 {
    u8 pad0[0x25C4];
    s32 w25C4;
} G_003A2EC8;

typedef struct F_003A2EC8 {
    u8 pad0[0x238];
    f32 f238;
    f32 f23C;
} F_003A2EC8;

typedef struct E_003A2EC8 {
    u8 pad0[0x148];
    f32 f148;
} E_003A2EC8;

extern G_003A2EC8 D_001A4BE0;
extern Mesh_003A2EC8 *D_L02_0021C700[];
extern F_003A2EC8 D_L02_001E5E40;
extern u8 D_001D60F8;
extern s32 D_001D6694;
extern f32 D_L02_001DDCA0;
__asm__(".extern D_L02_001DDCA0, 4");
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 4");
extern s32 D_L02_001DE4C0;
extern f32 D_L02_001DC948[] __attribute__((section(".sdata")));
extern f32 D_L02_001DC958[] __attribute__((section(".sdata")));
extern f32 D_L02_001DC9A8[] __attribute__((section(".sdata")));
extern f32 D_L02_001DC9B8[] __attribute__((section(".sdata")));
extern E_003A2EC8 D_L02_001E1140;

extern void func_003A9440(long, unsigned long);
extern s32 func_00389598(s32);
extern s32 func_0038C750(void);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 func_003D3A24(s32, void *, void *, void *, s32);

static inline s32 fade_3A2EC8(u8 *a0) {
    s32 r = 0;
    if (a0[3] & 0x80) {
        r = *(s32 *)(a0 + 92) == 0;
    }
    return r;
}

void func_L02_003A2EC8(u8 *obj) {
    St_003A2EC8 *s = *(St_003A2EC8 **)(obj + 0x68);
    Mesh_003A2EC8 *mesh;
    f32 sv238;
    f32 sv23C;
    f32 scale;
    f32 dist;
    u32 c0, c1;
    u32 c2, c3;
    s32 i, j;
    f32 *tbl;
    struct {
        f32 x, y;
    } d;
    V4_003A2EC8 ctr;
    UV_003A2EC8 rot[64];
    P3_003A2EC8 xyz[64];
    u32 col[64];
    u32 col2[64];
    UV_003A2EC8 uv[64];

    mesh = D_L02_0021C700[s->w3C];
    sv238 = D_L02_001E5E40.f238;
    sv23C = D_L02_001E5E40.f23C;
    if (D_001A4BE0.w25C4 != 0x1C && D_001D60F8 == 0) {
        D_L02_001E5E40.f238 = 255.0f;
        D_L02_001E5E40.f23C = 249.9f;
    }
    scale = D_L02_001DDCA0 * 2.5f;
    func_003A9440(0x42, 0x3200000044);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    if (fade_3A2EC8((u8 *)s)) {
        func_003A9440(0x47, 0x5310B);
    } else {
        func_003A9440(0x47, 0x513F1);
    }
    func_003A9440(6, func_00389598(0x16));
    func_0038C750();
    c1 = (s->c0[3] << 24) | (s->c0[2] << 16) | (s->c0[1] << 8) | s->c0[0];
    c0 = (s->c0[2] << 16) | (s->c0[1] << 8) | s->c0[0];
    if (D_001A4BE0.w25C4 != 0x7D && D_001D6694 == 0) {
        s->f94 = func_0038DAB8(s->f94, s->f9C * 0.017453292f);
    }
    for (i = 0; i < mesh->count; i++) {
        s32 k = s->w5C;
        if (k == 0) {
            col[i] = c1;
        } else if (i <= k * 2) {
            col[i] = func_0038DBD8(c0, c1, (f32)(i / 2) / (f32)k);
        } else if (i >= mesh->count - k * 2) {
            col[i] = func_0038DBD8(c0, c1, (f32)((mesh->count - i - 1) / 2) / (f32)k);
        } else {
            col[i] = c1;
        }
        uv[i].u = 0.0f;
        uv[i].v = 0.0f;
        xyz[i].x = mesh->pts[i].x;
        xyz[i].y = mesh->pts[i].y;
        xyz[i].z = mesh->pts[i].z;
        if (s->w90 != 0) {
            f32 w = func_0038D0B0(s->f94);
            xyz[i].z += (f32)(s->w90 / 2);
            xyz[i].z += (f32)(s->w90 / 2) * w;
        }
    }
    if (s->w98 != -1) {
        *(f32 *)(D_L02_001DE99C + (s->w98 << 8) + 0x18) = xyz[0].z;
    }
    func_003D3A24(mesh->count, xyz, col, uv, 1);
    if (s->f40 != 0.0f) {
        f32 ang, cs, sn;
        ang = (f32)(D_L02_001DE4C0 % (s32)s->f40) / s->f40;
        ang = ang + ang;
        ang = ang * 3.1415927f;
        ang = ang - 3.1415927f;
        ang = ang * s->f50;
        cs = func_0038D098(ang);
        sn = func_0038D0B0(ang);
        if (s->w44 != 0) {
            ctr = *(V4_003A2EC8 *)(obj + 0x10);
        } else {
            ctr = s->v80;
        }
        for (i = 0; i < mesh->count; i++) {
            d.x = (xyz[i].x - ctr.x) * s->f48;
            d.y = (xyz[i].y - ctr.y) * s->f4C;
            rot[i].u = d.x * cs + d.y * sn + ctr.x;
            rot[i].v = d.y * cs - d.x * sn + ctr.y;
        }
    }
    {
        s32 f = s->w10;
        tbl = D_L02_001DC948;
        if (f != 0) {
            f32 *t2 = D_L02_001DC958;
            if (s->w14 >= 3) {
                tbl = t2;
            }
        }
    }
    if (s->w10 != 0) {
        func_003A9440(6, func_00389598(s->w18 + 100));
    } else {
        func_003A9440(0x42, 0x8000000048);
    }
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    func_003A9440(0x47, 0x513F1);
    {
        E_003A2EC8 *cam = &D_L02_001E1140;
        f32 z = *(f32 *)(obj + 0x18);
        dist = fabs_asm(cam->f148 - z);
    }
    if (dist < 10.0f) {
        dist = 10.0f;
    }
    if (fade_3A2EC8((u8 *)s)) {
        f32 t = dist * D_L02_001DDCA0 * 2e-5f * 1.05f;
        if (t < 0.15f) {
            t = 0.15f;
        } else if (t > 1.0f) {
        }
    }
    c3 = (s->c8[3] << 24) | (s->c8[2] << 16) | (s->c8[1] << 8) | s->c8[0];
    c2 = (s->c8[2] << 16) | (s->c8[1] << 8) | s->c8[0];
    for (i = 0; i < mesh->count; i++) {
        s32 k = s->w5C;
        if (k == 0) {
            col[i] = c3;
        } else if (i <= k * 2) {
            col[i] = func_0038DBD8(c2, c3, (f32)(i / 2) / (f32)k);
        } else if (i >= mesh->count - k * 2) {
            col[i] = func_0038DBD8(c2, c3, (f32)((mesh->count - i - 1) / 2) / (f32)k);
        } else {
            col[i] = c3;
        }
        col2[i] = col[i] & 0xFFFFFF;
    }
    for (j = 0; j < s->w14; j++) {
        f32 a = (1.0f - dist / D_L02_001DC9A8[j]) * D_L02_001DC9B8[j];
        f32 sc;
        UV_003A2EC8 *e;
        if (1.0f < a) {
            a = 1.0f;
        } else if (a < 0.0f) {
            a = 0.0f;
        }
        if (s->w10 != 0) {
            if ((s->w14 & 1) && j == s->w14 - 1) {
                continue;
            }
            if (j & 1) {
                if (s->w34 != 0) {
                    func_003A9440(0x42, 0x8000000051);
                } else {
                    func_003A9440(0x42, 0x8000000058);
                }
            } else {
                func_003A9440(0x42, 0x800000006A);
            }
        } else {
            {
                s32 t = j + 100;
                func_003A9440(6, func_00389598(s->w18 + t));
            }
        }
        e = &s->e60[j];
        sc = tbl[j] / scale;
        for (i = 0; i < mesh->count; i++) {
            if (s->f40 != 0.0f) {
                uv[i].u = (rot[i].u - s->v80.x) * sc + e->u;
                uv[i].v = (rot[i].v - s->v80.y) * sc + e->v;
            } else {
                uv[i].u = (xyz[i].x - s->v80.x) * sc + e->u;
                uv[i].v = (xyz[i].y - s->v80.y) * sc + e->v;
            }
        }
        if (s->w10 != 0 && (j & 1)) {
            func_003D3A24(i, xyz, col2, uv, 1);
        } else {
            func_003D3A24(i, xyz, col, uv, 1);
        }
    }
    D_L02_001E5E40.f238 = sv238;
    D_L02_001E5E40.f23C = sv23C;
    func_003A9440(0x47, 0x5360B);
}
