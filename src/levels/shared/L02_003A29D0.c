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

/* localdecomp:start func_L02_003A29D0 */
/* log: start from NTSC-U draft with PAL names */
typedef struct V4_003A29D0 { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A29D0;
typedef struct Mesh_003A29D0 {
    s32 count;
    u8 pad4[0xC];
    V4_003A29D0 pts[1];
} Mesh_003A29D0;
typedef struct Ent_003A29D0 { s32 w0; s32 w4; } Ent_003A29D0;
typedef struct St_003A29D0 {
    u8 pad0[0x14];
    s32 w14;
    u8 pad18[0x18];
    s32 w30;
    u8 pad34[8];
    s32 w3C;
    f32 f40;
    u8 pad44[4];
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    Ent_003A29D0 e60[4];
    V4_003A29D0 v80;
    u8 pad90[8];
    s32 w98;
} St_003A29D0;

extern Mesh_003A29D0 *D_L02_0021C700[];
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 4");
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L02_003A29D0(u8 *a0, void *arg) {
    St_003A29D0 *s = arg;
    V4_003A29D0 mn;
    V4_003A29D0 mx;
    Mesh_003A29D0 *mesh;
    s32 i;
    s32 k;

    a0[0x30] = 0xFF;
    s->w14 = s->w14 << 1;
    if (s->w14 >= 5) {
        s->w14 = 4;
    } else if (s->w14 < 0) {
        s->w14 = 0;
    }
    for (i = 0; i < 4; i++) {
        s->e60[i].w0 = 0;
        s->e60[i].w4 = 0;
    }
    s->w30 = 0;
    if (s->f40 != *(f32 *)&s->w30) {
        if (s->f40 < *(f32 *)&s->w30) {
            s->f40 = -s->f40;
            s->f50 = -1.0f;
        } else {
            s->f50 = 1.0f;
        }
        s->f40 = 360.0f / s->f40 * 60.0f;
        s->f48 = 1.0f / s->f48;
        s->f4C = 1.0f / s->f4C;
    }
    if (s->f54 != 0.0f) {
        s->f54 = s->f54 * 0.020000001f;
    }
    if (s->f58 != 0.0f) {
        s->f58 = s->f58 * 0.020000001f;
    }
    mesh = D_L02_0021C700[s->w3C];
    mn = mesh->pts[0];
    mx = mesh->pts[0];
    for (k = 1; k < mesh->count; k++) {
        if (mn.x > mesh->pts[k].x) {
            mn.x = mesh->pts[k].x;
        }
        if (mn.y > mesh->pts[k].y) {
            mn.y = mesh->pts[k].y;
        }
        if (mn.z > mesh->pts[k].z) {
            mn.z = mesh->pts[k].z;
        }
        if (mx.x < mesh->pts[k].x) {
            mx.x = mesh->pts[k].x;
        }
        if (mx.y < mesh->pts[k].y) {
            mx.y = mesh->pts[k].y;
        }
        if (mx.z < mesh->pts[k].z) {
            mx.z = mesh->pts[k].z;
        }
    }
    func_0038CDF8((f32 *)&s->v80, (f32 *)&mn, (f32 *)&mx, 0.5f);
    if (s->w98 != -1) {
        *(u16 *)(D_L02_001DE99C + (s->w98 << 8) + 0x34) |= 0x41;
    }
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L02_003A29D0 */
