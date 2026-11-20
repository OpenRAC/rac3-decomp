#include "common.h"

typedef struct Obj_003A2C98 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    f32 f60[1];
} Obj_003A2C98;

/* declared by functions of L02_003A2C98.c, which this file was cut from */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

/* localdecomp:start func_L02_003A2EC8 */
#include "vu0.h"
#include "structs/hero.h"
typedef struct V4_003A2EC8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003A2EC8;

typedef struct V3_003A2EC8 {
    f32 x, y, z;
} V3_003A2EC8;

typedef struct V2_003A2EC8 {
    f32 x, y;
} V2_003A2EC8;

typedef struct Path_003A2EC8 {
    s32 count;
    u8 pad04[0xC];
    V4_003A2EC8 pts[1];
} Path_003A2EC8;

typedef struct Vars_003A2EC8 {
    u8 c0[4];
    u8 pad04[4];
    u8 c1[4];
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0x18];
    s32 f34;
    u8 pad38[4];
    s32 f3C;
    f32 f40;
    s32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    u8 pad54[8];
    s32 f5C;
    V2_003A2EC8 f60[4];
    V4_003A2EC8 f80;
    s32 f90;
    f32 f94;
    s32 f98;
    f32 f9C;
} Vars_003A2EC8;

typedef struct Moby_003A2EC8 {
    u8 pad00[0x10];
    V4_003A2EC8 pos;
    u8 pad20[0x48];
    Vars_003A2EC8 *vars;
} Moby_003A2EC8;

extern struct Hero D_001A4BE0;
extern Path_003A2EC8 *D_L02_0021C700[];
typedef struct Fog_003A2EC8 {
    u8 pad[0x238];
    f32 f238;
    f32 f23C;
} Fog_003A2EC8;
extern Fog_003A2EC8 D_L02_001E5E40;
extern u8 D_L02_001D60F8;
extern s32 D_L02_001D6694;
extern f32 D_L02_001DDCA0;
__asm__(".extern D_L02_001DDCA0, 4");
extern u8 *D_L02_001DE99C;
extern s32 D_L02_001DE4C0;
typedef struct Cam_003A2EC8 {
    u8 pad[0x140];
    V4_003A2EC8 pos;
} Cam_003A2EC8;
extern Cam_003A2EC8 D_L02_001E1140;
extern f32 D_L02_001DC9A8[4] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9A8, 16");
extern f32 D_L02_001DC9B8[4] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9B8, 16");
extern f32 D_L02_001DC948_003A2EC8[4] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC948_003A2EC8, 16");
extern f32 D_L02_001DC958[4] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC958, 16");

extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L02_003A2EC8(Moby_003A2EC8 *moby) {
    V2_003A2EC8 d;
    V4_003A2EC8 c;
    V2_003A2EC8 rot[64];
    V3_003A2EC8 pos[64];
    s32 col[64];
    s32 col2[64];
    V2_003A2EC8 uv[64];
    Vars_003A2EC8 *v;
    Path_003A2EC8 *path;
    f32 save0, save1;
    f32 scale;
    f32 dist;
    f32 h;
    f32 *tbl;
    u32 rgb, rgba;
    u32 rgb2, rgba2;
    s32 fade;
    s32 i, j;


    save0 = D_L02_001E5E40.f238;
    save1 = D_L02_001E5E40.f23C;
    v = moby->vars;
    path = D_L02_0021C700[v->f3C];
    if (D_001A4BE0.state != 0x1C && D_L02_001D60F8 == 0) {
        D_L02_001E5E40.f238 = 255.0f;
        D_L02_001E5E40.f23C = 249.9f;
    }
    scale = D_L02_001DDCA0 * 2.5f;
    func_003A9440(0x42, 0x3200000044);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    fade = (v->c0[3] & 0x80) && v->f5C == 0;
    if (fade) {
        func_003A9440(0x47, 0x5310B);
    } else {
        func_003A9440(0x47, 0x513F1);
    }
    func_003A9440(6, func_00389598(0x16));
    func_0038C750();
    rgba = (v->c0[3] << 24) | (v->c0[2] << 16) | (v->c0[1] << 8) | v->c0[0];
    rgb = (v->c0[2] << 16) | (v->c0[1] << 8) | v->c0[0];
    if (D_001A4BE0.state != 0x7D && D_L02_001D6694 == 0) {
        v->f94 = func_0038DAB8(v->f94, v->f9C * 0.017453292f);
    }
    for (i = 0; i < path->count; i++) {
        s32 k = v->f5C;
        if (k == 0) {
            col[i] = rgba;
        } else if (i <= k * 2) {
            col[i] = func_0038DBD8(rgb, rgba, (f32)(i / 2) / (f32)k);
        } else if (i >= path->count - k * 2) {
            col[i] = func_0038DBD8(rgb, rgba, (f32)((path->count - i - 1) / 2) / (f32)k);
        } else {
            col[i] = rgba;
        }
        uv[i].x = 0.0f;
        uv[i].y = 0.0f;
        pos[i].x = path->pts[i].x;
        pos[i].y = path->pts[i].y;
        pos[i].z = path->pts[i].z;
        if (v->f90 != 0) {
            f32 cs = func_0038D0B0(v->f94);
            pos[i].z += (f32)(v->f90 / 2);
            pos[i].z += (f32)(v->f90 / 2) * cs;
        }
    }
    if (v->f98 != -1) {
        *(f32 *)(D_L02_001DE99C + (v->f98 << 8) + 0x18) = pos[0].z;
    }
    func_003D3A24(path->count, pos, col, uv, 1);
    if (v->f40 != 0.0f) {
        f32 a, sn, cs;
        a = (f32)(D_L02_001DE4C0 % (s32)v->f40);
        a /= v->f40;
        a += a;
        a *= 3.1415927f;
        a -= 3.1415927f;
        a *= v->f50;
        sn = func_0038D098(a);
        cs = func_0038D0B0(a);
        if (v->f44 != 0) {
            c = moby->pos;
        } else {
            c = v->f80;
        }
        for (i = 0; i < path->count; i++) {
            d.x = (pos[i].x - c.x) * v->f48;
            d.y = (pos[i].y - c.y) * v->f4C;
            rot[i].x = d.x * sn + d.y * cs + c.x;
            rot[i].y = d.y * sn - d.x * cs + c.y;
        }
    }
    if (v->f10 != 0 && v->f14 >= 3) {
        tbl = D_L02_001DC958;
    } else {
        tbl = D_L02_001DC948_003A2EC8;
    }
    if (v->f10 != 0) {
        func_003A9440(6, func_00389598(v->f18 + 100));
    } else {
        func_003A9440(0x42, 0x8000000048);
    }
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    func_003A9440(0x47, 0x513F1);
    dist = fabs_asm(D_L02_001E1140.pos.z - moby->pos.z);
    if (dist < 10.0f) {
        dist = 10.0f;
    }
    fade = (v->c0[3] & 0x80) && v->f5C == 0;
    if (fade) {
        h = dist * D_L02_001DDCA0 * 2e-05f * 1.05f;
        if (h < 0.15f) {
            h = 0.15f;
        }
    } else {
        h = dist * D_L02_001DDCA0 * 2e-05f;
        if (h < 0.125f) {
            h = 0.125f;
        }
    }
    if (D_L02_001E1140.pos.z < moby->pos.z) {
        h = -h;
    }
    rgba2 = (v->c1[3] << 24) | (v->c1[2] << 16) | (v->c1[1] << 8) | v->c1[0];
    rgb2 = (v->c1[2] << 16) | (v->c1[1] << 8) | v->c1[0];
    for (i = 0; i < path->count; i++) {
        s32 k = v->f5C;
        if (k == 0) {
            col[i] = rgba2;
        } else if (i <= k * 2) {
            col[i] = func_0038DBD8(rgb2, rgba2, (f32)(i / 2) / (f32)k);
        } else if (i >= path->count - k * 2) {
            col[i] = func_0038DBD8(rgb2, rgba2, (f32)((path->count - i - 1) / 2) / (f32)k);
        } else {
            col[i] = rgba2;
        }
        col2[i] = col[i] & 0xFFFFFF;
    }
    for (j = 0; j < v->f14; j++) {
        f32 a = (1.0f - dist / D_L02_001DC9A8[j]) * D_L02_001DC9B8[j];
        f32 s;
        V2_003A2EC8 *off;
        if (1.0f < a) {
            a = 1.0f;
        } else if (a < 0.0f) {
            a = 0.0f;
        }
        if (v->f10 != 0) {
            if ((v->f14 & 1) && j == v->f14 - 1) {
                continue;
            }
            if (j & 1) {
                if (v->f34 != 0) {
                    func_003A9440(0x42, 0x8000000051);
                } else {
                    func_003A9440(0x42, 0x8000000058);
                }
            } else {
                func_003A9440(0x42, 0x800000006A);
            }
        } else {
            func_003A9440(6, func_00389598(v->f18 + 100 + j));
        }
        off = &v->f60[j];
        s = tbl[j] / scale;
        for (i = 0; i < path->count; i++) {
            if (v->f40 != 0.0f) {
                uv[i].x = (rot[i].x - v->f80.x) * s + off->x;
                uv[i].y = (rot[i].y - v->f80.y) * s + off->y;
            } else {
                uv[i].x = (pos[i].x - v->f80.x) * s + off->x;
                uv[i].y = (pos[i].y - v->f80.y) * s + off->y;
            }
        }
        if (v->f10 != 0 && (j & 1)) {
            func_003D3A24(i, pos, col2, uv, 1);
        } else {
            func_003D3A24(i, pos, col, uv, 1);
        }
    }
    D_L02_001E5E40.f238 = save0;
    D_L02_001E5E40.f23C = save1;
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L02_003A2EC8 */
