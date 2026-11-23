#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00434DA8);

/* localdecomp:start func_L40_00435388 */
typedef struct {
    f32 x, y, z, w;
} V4_00435388 __attribute__((aligned(16)));

typedef struct {
    f32 u, v;
} UV_00435388;

typedef struct {
    V4_00435388 pos[4];
    u32 col[4];
    UV_00435388 uv[4];
    unsigned long a70;
    unsigned long a78;
    unsigned long a80;
    unsigned long a88;
} Q_00435388;

typedef int U128_00435388 __attribute__((mode(TI)));
extern void func_0038D570(void *, void *);
extern void func_0038D308(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern unsigned long func_L39_00589890(s32);
extern void func_L04_0041AE18(void *, s32, void *, s32, void *);

__asm__(".extern D_L40_00247B60, 4");
__asm__(".extern D_L40_00247B64, 4");
__asm__(".extern D_L40_00247B68, 4");
__asm__(".extern D_L40_00247B6C, 4");
__asm__(".extern D_L40_00247B70, 4");
__asm__(".extern D_L40_00247BA0, 4");
__asm__(".extern D_L40_00247BA8, 4");
extern s32 D_L40_00247B60;
extern s32 D_L40_00247B64;
extern s32 D_L40_00247B68;
extern s32 D_L40_00247B6C;
extern s32 D_L40_00247B70;
__asm__(".extern D_L40_00247B78, 8");
__asm__(".extern D_L40_00247B80, 8");
extern u32 D_L40_00247B78[] __attribute__((section(".sdata")));
extern UV_00435388 D_L40_00247B80[] __attribute__((section(".sdata")));
extern f32 D_L40_00247BA0;
extern f32 D_L40_00247BA8;
extern f32 D_L40_00247ED8;

static __inline__ f32 max_00435388(f32 x, f32 lo) {
    if (x < lo) {
        x = lo;
    }
    return x;
}

void func_L40_00435388(u8 *a0) {
    Q_00435388 q[4];
    V4_00435388 m[4];
    V4_00435388 r[3];
    V4_00435388 rot;
    f32 *t = *(f32 **)(a0 + 0x68);
    f32 a, b, c, d;
    s32 k;

    func_0038D570(m, a0 + 0xC0);
    m[3] = *(V4_00435388 *)(a0 + 0x10);
    for (k = 0; k < 4; k++) {
        q[k].a78 = func_L39_00589890(D_L40_00247B70);
        q[k].a80 = 0xFF9000000260UL;
        q[k].a70 = 0;
        q[k].a88 = (long)D_L40_00247B60 | ((long)D_L40_00247B64 << 2) | ((long)D_L40_00247B68 << 4) |
                    ((long)D_L40_00247B6C << 6) | 0x8000000000UL;
    }

    a = (0.85f - *t) * 2.0f;
    b = 0.15f;
    if (a > 1.0f) {
        a = 1.0f;
    } else if (a < 0.0f) {
        a = 0.0f;
    }
    if (*t < 1.15f) {
        c = max_00435388(1.15f - *t, 0.0f);
        d = max_00435388((0.2f - *t) / 0.2f, 0.0f);
        D_L40_00247ED8 = d;
        b = c + 0.15f;
    }

    {
        s32 i, j;
        f32 x;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i].uv[j].u = D_L40_00247B80[j].u;
                q[i].uv[j].v = D_L40_00247B80[j].v;
                q[i].col[j] = D_L40_00247B78[i != 0];
                q[i].col[j] = func_0038DBD8(q[i].col[j] & 0xFFFFFF, q[i].col[j], a);
                __asm__("sqc2 $vf0, %0" : "=m"(*(U128_00435388 *)&q[i].pos[j]));
                q[i].pos[j].x = x = *t + (i != 0 ? 0.01f : 0.0f);
                if (j & 1) {
                    switch (i) {
                    case 0:
                        q[i].pos[j].z += D_L40_00247BA0 + b;
                        break;
                    case 1:
                        q[i].pos[j].z += D_L40_00247BA0 + D_L40_00247BA8;
                        break;
                    case 2:
                        q[i].pos[j].z += D_L40_00247BA0 - b * 0.8f + D_L40_00247BA8;
                        break;
                    case 3:
                        q[i].pos[j].z += D_L40_00247BA0 + b * 0.8f + D_L40_00247BA8;
                        break;
                    }
                } else {
                    switch (i) {
                    case 0:
                        q[i].pos[j].z += D_L40_00247BA0 - b;
                        break;
                    case 1:
                        q[i].pos[j].z += D_L40_00247BA0 - D_L40_00247BA8;
                        break;
                    case 2:
                        q[i].pos[j].z += D_L40_00247BA0 - b * 0.8f - D_L40_00247BA8;
                        break;
                    case 3:
                        q[i].pos[j].z += D_L40_00247BA0 + b * 0.8f - D_L40_00247BA8;
                        break;
                    }
                }
            }
        }
    }

    *(U128_00435388 *)&rot = 0;
    rot.z = 0.19634954f;
    func_0038D308(r, &rot);
    func_L04_0041AE18(q, 4, r, 0x20, m);
}
/* localdecomp:end func_L40_00435388 */
