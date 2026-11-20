#include "common.h"

/* localdecomp:start func_L28_00333448 */
#include "vu0.h"

typedef struct {
    s32 n;
    u8 pad4[0xC];
    vu0_v4 pts[1];
} Path_00333448;

typedef struct {
    vu0_v4 vel;
    u8 pad10[0x20 - 0x10];
    s32 path;
    f32 x24;
    f32 x28;
    s16 x2C;
    s16 x2E;
} State_00333448;

extern u8 D_001A4BE0[];
extern Path_00333448 *D_L28_0021C940[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_00476B98(void *, void *, void *, void *, void *, s32, f32, f32, f32);
extern s32 func_L01_00476498(void *, void *, void *, void *, s32, f32);

void func_L28_00333448(u8 *p) {
    vu0_v4 at;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 t;
    s32 seg;
    State_00333448 *st;
    Path_00333448 *path;
    s32 i;
    s32 r;
    f32 d;
    f32 m;
    u8 *h1;
    u8 *h2;
    u8 *h3;

    st = *(State_00333448 **)(p + 0x68);
    if (st == 0 || st->path == -1) {
        return;
    }
    path = D_L28_0021C940[st->path];
    if (st->x2E == 0) {
        st->x2E = 1;
        for (i = 0; i < path->n - 1; i++) {
            path->pts[i].w = func_0038CF00(&path->pts[i], &path->pts[i + 1]);
        }
        path->pts[i].w = func_0038CF00(&path->pts[i], &path->pts[0]);
        p[0x30] = 0xFF;
    }
    h1 = D_001A4BE0;
    if (*(s32 *)(h1 + 0x25CC) == 0x11 || *(s32 *)(h1 + 0x25CC) == 0x12 ||
        *(s32 *)(h1 + 0x25D4) == 0x11 || *(s32 *)(h1 + 0x25D4) == 0x12 ||
        *(s32 *)(h1 + 0x25C4) == 0x12 || *(s32 *)(h1 + 0x25D0) == 0x12) {
        func_L01_00476B98(path, D_001A4BE0 + 0x80, &at, &t, &seg, 0, 999.0f, 5.0f, 0.0f);
        r = func_L01_00476498(path, &v10, &t, &seg, 0, 2.0f);
        d = func_0038CF38(D_001A4BE0 + 0x80, &at);
        if (st->x28 < d) {
            return;
        }
        h2 = D_001A4BE0;
        if (*(s32 *)(h2 + 0x25CC) == 0x11 || *(s32 *)(h2 + 0x25CC) == 0x12) {
            if (*(f32 *)(h2 + 0x2864) < d) {
                return;
            }
            *(f32 *)(h2 + 0x2864) = d;
            if (r == 0) {
                {
                    vu0_q qa, qb, qr;
                    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(at));
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v10));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                    __asm__("sqc2 %1, %0" : "=m"(v20) : "j"(qr));
                }
                func_0038CF68(&v20, &v20, 0.0028000001f);
                {
                    vu0_q qa, qb, qr;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(st->vel));
                    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v20));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                    __asm__("sqc2 %1, %0" : "=m"(st->vel) : "j"(qr));
                }
                st->vel.z = 0.0f;
                if (st->x24 < func_0038CEA8(st)) {
                    func_0038CF68(st, st, st->x24);
                }
                *(vu0_q *)(h2 + 0x100) = *(vu0_q *)st;
                if (st->x2C != 0) {
                    {
                        vu0_q qa, qb, qr;
                        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(at));
                        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(D_001A4BE0 + 0x80)));
                        __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                        __asm__("sqc2 %1, %0" : "=m"(v30) : "j"(qr));
                    }
                    v30.z = 0.0f;
                    m = st->x24 * 0.4f;
                    if (m < func_0038CEA8(&v30)) {
                        func_0038CF68(&v30, &v30, m);
                    }
                    {
                        vu0_q qa, qb, qr;
                        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(h2 + 0x100)));
                        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v30));
                        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(h2 + 0x100)) : "j"(qr));
                    }
                }
            } else {
                func_0038CF68(st, st, func_0038CEA8(st) * 0.982f);
                *(vu0_q *)(h2 + 0x100) = *(vu0_q *)st;
            }
            h3 = D_001A4BE0;
            if (*(s32 *)(h3 + 0x25CC) == 0x12 && *(s32 *)(h3 + 0x25D0) == 0x12 &&
                *(s32 *)(h3 + 0x1B8) < 2) {
                if (0.030000001f < *(f32 *)(h3 + 0x1B4)) {
                    *(f32 *)(h3 + 0x1B4) = 0.030000001f;
                }
                qzero(h3 + 0x160);
            }
        } else if ((*(s32 *)(h2 + 0x25D4) == 0x12 || *(s32 *)(h2 + 0x25E0) == 0x12) &&
                   (*(s32 *)(h2 + 0x25CC) == 4 || *(s32 *)(h2 + 0x25CC) == 5)) {
            func_0038CF68(st, st, func_0038CEA8(st) * 0.982f);
            *(vu0_q *)(h2 + 0x100) = *(vu0_q *)st;
            if (*(s16 *)(h2 + 0x1F8) < 0x1D) {
                *(s16 *)(h2 + 0x1F8) = 0x1D;
            }
        }
    }
}
/* localdecomp:end func_L28_00333448 */
