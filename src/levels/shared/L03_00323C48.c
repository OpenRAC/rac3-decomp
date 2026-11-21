#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_00323C48);

/* localdecomp:start func_L03_003240B8 */
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);

void func_L03_003240B8(u8 *a0) {
    switch (*(s32 *)(*(u8 **)(a0 + 0x68) + 0x10)) {
    case 0: func_L01_00452560(0, 12, 0x8BD, 1, 0, 0, 0); break;
    case 1: func_L01_00452560(0, 12, 0x14D6, 1, 0, 0, 0); break;
    case 2: func_L01_00452560(0, 12, 0x16B6, 1, 0, 0, 0); break;
    case 3: func_L01_00452560(0, 12, 0x16B7, 1, 0, 0, 0); break;
    case 4: func_L01_00452560(0, 12, 0x16B8, 1, 0, 0, 0); break;
    case 5: func_L01_00452560(0, 12, 0x16C2, 1, 0, 0, 0); break;
    default: func_L01_00452560(0, 12, 0x850, 1, 0, 0, 0); break;
    }
}
/* localdecomp:end func_L03_003240B8 */

/* localdecomp:start func_L03_00324190 */
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_00324190;
typedef struct { u8 pad0[0x34]; f32 radius; } V_00324190;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; V_00324190 *p68; u8 pad6C[0xC0 - 0x6C]; vu0_v4 rot; } M_00324190;

extern s32 D_L03_001DCA78;
__asm__(".extern D_L03_001DCA78, 4");
extern s32 D_L03_001DCA7C;
__asm__(".extern D_L03_001DCA7C, 4");
extern s32 D_L03_001DCA80;
__asm__(".extern D_L03_001DCA80, 4");
extern s32 D_L03_001DCA84;
__asm__(".extern D_L03_001DCA84, 4");
extern s32 D_L03_001DCA88;
__asm__(".extern D_L03_001DCA88, 4");
extern s32 D_L03_001DCA8C;
__asm__(".extern D_L03_001DCA8C, 4");
extern f32 D_L03_001DCA90[][2] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DCA90, 8");
extern f32 D_L03_001DCAB0;
__asm__(".extern D_L03_001DCAB0, 4");
extern u8 D_001A71C5 __attribute__((section(".data")));
extern void func_0038D570(void *, void *);
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L03_00324190(M_00324190 *m) {
    V_00324190 *v = m->p68;
    Q_00324190 q;
    vu0_v4 mat[4];
    f32 t;
    f32 off;
    f32 ang;
    s32 i;
    s32 j;
    s32 k;

    func_0038D570(mat, &m->rot);
    mat[3] = m->pos;
    q.x78 = func_00389598(D_L03_001DCA88);
    q.x80 = 0xFF9000000260L;
    q.x88 = (long)D_L03_001DCA78 | ((long)D_L03_001DCA7C << 2) | ((long)D_L03_001DCA80 << 4) | ((long)D_L03_001DCA84 << 6) | 0x8000000000L;
    q.x70 = 0;
    for (i = 0; i < 4; i++) {
        q.uv[i][0] = D_L03_001DCA90[i][0];
        q.uv[i][1] = D_L03_001DCA90[i][1];
        q.color[i] = D_L03_001DCA8C;
    }
    off = 0.1f;
    if (v->radius < 1.15f) {
        t = (1.15f - v->radius) * 2.0f;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        off = t + 0.1f;
        if (v->radius < 0.65f) {
            D_001A71C5 = 1;
        } else {
            D_001A71C5 = 0;
        }
    }
    for (j = 0; j < 32; j++) {
        for (k = 0; k < 4; k++) {
            ang = (f32)(j + k / 2) * 6.2839208f * 0.03125f - 3.14159f;
            q.v[k].x = func_0038D098(ang) * v->radius;
            q.v[k].y = func_0038D0B0(ang) * v->radius;
            q.v[k].z = 0.0f;
            if (k & 1) {
                q.v[k].z = D_L03_001DCAB0 + off + 0.0f;
            } else {
                q.v[k].z = D_L03_001DCAB0 - off + 0.0f;
            }
            q.v[k].w = 1.0f;
        }
        func_003D2DA0(&q, mat, 0);
    }
}
/* localdecomp:end func_L03_00324190 */
