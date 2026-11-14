#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* declared by functions of L39_00622990.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

/* localdecomp:start func_L39_006233A8 */
#include "vu0.h"

typedef union Buf_006233A8 {
    u8 b[8];
    u32 w[2];
} Buf_006233A8;

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[4];
    f32 f24;
    s32 f28;
    u8 pad2C[8];
    s32 f34;
    s32 f38;
} Out_006233A8;

typedef struct {
    u8 pad0[0x18];
    void *f18;
    u8 pad1C[4];
    vu0_v4 v20;
} D_006233A8;

typedef struct {
    u8 pad0[0x48];
    s32 (*f48)(void *);
} Vt_006233A8;

extern u8 D_L39_004997E0[];
extern D_006233A8 D_L39_0025F740_006233A8;
extern vu0_v4 D_L39_0025F760;
extern vu0_v4 D_L39_0025F780;
extern f32 func_L39_00632678(u8 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D160(f32, f32);
extern s32 func_003D5630(void);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);
extern f32 func_L39_00632100(void *, void *);

static __inline__ u32 Dec_006233A8(u8 *q) {
    Buf_006233A8 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

/* a += b through VU0 with the sum in a's register, loading a then b (the vu0.h helpers
 * put the sum in a fresh register, which allocates vf1/vf2 the other way round) */
static __inline__ void addi_ab_006233A8(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qa));
}

s32 func_L39_006233A8(u8 *g, vu0_v4 *pos, void *arg2, Out_006233A8 *out) {
    s32 flag;
    s32 n;
    s32 i;
    s32 j;
    s32 hit;
    s32 r;
    f32 lo;
    f32 up;
    f32 h;
    f32 c;
    f32 step;
    f32 lim;
    u32 mode;
    f32 z;
    f32 w;

    if (out != 0 && (Dec_006233A8(g + 0x19E4) ^ 0x17) != 0) {
        out->f28 = 0;
    }
    if (*(s16 *)(g + 0x308) != 0) {
        return 0;
    }
    flag = 0;
    if (((Dec_006233A8(g + 0x19E6) ^ 4) == 0 &&
         (g[0x14AE] != 0 || func_L39_00632678(g, (f32 *)(g + 0x120)) < 0.0700000077f)) ||
        (Dec_006233A8(g + 0x19E6) ^ 2) == 0 || (Dec_006233A8(g + 0x19E4) ^ 8) == 0 ||
        (Dec_006233A8(g + 0x19E4) ^ 0x19) == 0 || (Dec_006233A8(g + 0x19E4) ^ 0x1A) == 0) {
        flag = 1;
    }
    if ((Dec_006233A8(g + 0x19E4) ^ 0xE) == 0 && *(f32 *)(g + 0x628) < 37.0f) {
        flag = 0;
    }
    if (out != (Out_006233A8 *)(g + 0x1540)) {
        flag = 1;
    }
    if (flag != 0) {
        if (g[0x1A14] != 0 || (Dec_006233A8(g + 0x19E6) ^ 4) == 0) {
            n = 1;
            lo = -0.7f;
            c = 0.3f;
            up = 1.5f;
            h = 1.15f;
            z = -1.43f;
            w = 1.8f;
        } else {
            n = 4;
            lo = -0.7f;
            c = 0.3f;
            up = 2.25f;
            h = 1.9f;
            z = -1.43f;
            w = 1.8f;
        }
        mode = Dec_006233A8(g + 0x19E6);
        {
            vu0_v4 v0;
            vu0_v4 v10;
            vu0_v4 v20;
            vu0_v4 t30;
            vu0_v4 t40;
            vu0_v4 d50;
            vu0_v4 v60;
            vu0_v4 v70;
            vu0_v4 v80;
            vu0_v4 v90;
            vu0_v4 vA0;

            v0 = *pos;
            hit = 0;
            func_0038CF68(&t30, g + 0x20, *(f32 *)(g + 0x1F4) + c);
            vec_add_ba(&v0, &v0, &t30);
            func_0038CF68(&t30, g + 0x40, up + 0.15f);
            vec_add_ba(&v10, &v0, &t30);
            func_0038CF68(&t30, g + 0x40, -h);
            vec_add_ab(&v20, &v0, &t30);
            func_0038CF68(&t40, g + 0x20, 0.3f);
            for (i = 0; i < n; i++) {
                addi_ab_006233A8(&v10, &v10, &t40);
                addi_ab_006233A8(&v20, &v20, &t40);
                if (func_003D3CB0(&v10, &v20, 4, *(void **)(g + 0x2524), 0) != 0) {
                    r = func_003D5630();
                    if (r != 9 && r != 12 && r != 0 &&
                        func_L39_00632100(g, &D_L39_0025F780) < 0.349065840f) {
                        hit = 1;
                    }
                }
                if (hit) {
                    break;
                }
            }
            if (hit) {
                f32 d;

                if (D_L39_0025F740_006233A8.f18 != 0) {
                    return 0;
                }
                if (out != 0) {
                    out->f38 = 0;
                }
                v60 = D_L39_0025F740_006233A8.v20;
                vec_sub_ba(&d50, &v60, pos);
                if (up < func_L39_00632678(g, (f32 *)&d50)) {
                    return 0;
                }
                func_0038CF68(&v70, g + 0x40, 0.005f);
                addi_ab_006233A8(&v70, &v70, &v60);
                func_0038CF68(&v80, g + 0x20, -1.0f);
                vec_add_ab(&v80, &v80, &v70);
                if (func_003D3CB0(&v80, &v70, 2, *(void **)(g + 0x2524), 0) != 0) {
                    return 0;
                }
                if (out != 0) {
                    func_0038CF68(&v90, g + 0x40, 0.6f);
                    addi_ab_006233A8(&v90, &v90, &v60);
                    if (func_L01_003FB640(&v90, 4, *(u8 **)(g + 0x2524), 0.45f) != 0) {
                        out->f34 |= 1;
                    } else {
                        out->f34 &= ~1;
                    }
                }
                d = func_L39_00632678(g, (f32 *)&d50);
                if (d + *(f32 *)(g + 0x2AC) < w) {
                    return 0;
                }
                if (d < 0.5f) {
                    return 0;
                }
                {
                    vu0_v4 vB0 = {1.0f, 0.0f, lo};
                    vu0_v4 vC0;
                    vu0_v4 vD0;
                    vu0_v4 vE0;
                    vu0_v4 vF0;
                    vu0_v4 v100;
                    vu0_v4 v110;
                    vu0_v4 v120;
                    vu0_v4 v130;
                    s32 found;
                    f32 t;

                    func_0038D000(&vB0, &vB0, g + 0x20);
                    found = 0;
                    vec_add_ba(&vB0, &vB0, &v60);
                    vec_sub_ba(&v90, pos, &vB0);
                    func_L39_00632558(g, &v90, &v90, 0.0f);
                    addi_ab_006233A8(&v90, &v90, &vB0);
                    func_0038CF68(&vA0, g + 0x40, -lo / 5.0f);
                    for (j = 0; j < 5; j++) {
                        if (func_003D3CB0(&v90, &vB0, 2, 0, 0) != 0) {
                            func_0038CF68(&vC0, &D_L39_0025F780, 1.0f);
                            found = 1;
                            func_L39_00632558(g, &vC0, &vC0, 0.0f);
                            break;
                        }
                        vec_add_ab(&v90, &v90, &vA0);
                        vec_add_ab(&vB0, &vB0, &vA0);
                    }
                    if (!found) {
                        return 0;
                    }
                    if (!(func_0038CE68(g + 0x20, &vC0) < func_0038D098(1.13446403f))) {
                        return 0;
                    }
                    v120 = v60;
                    step = 0.03f;
                    func_0038CF68(&v110, g + 0x250, -0.05f);
                    func_0038CF68(&v100, &vC0, step);
                    lim = 2.4f;
                    t = 0.0f;
                    vec_add_ba(&vF0, &v100, &v110);
                    vec_sub_ba(&v100, &v100, &v110);
                    vec_add_ab(&vD0, &v120, &v100);
                    vec_add_ab(&vE0, &v120, &vF0);
                    do {
                        if (func_003D3CB0(&vE0, &vD0, 4, *(void **)(g + 0x2524), 0) == 0) {
                            if (out != 0) {
                                out->v10 = v120;
                                func_0038CF68(&v130, &vC0, 0.5f);
                                func_0038CF68(&out->v0, g + 0x250, -z);
                                vec_add_ba(&out->v0, &v130, &out->v0);
                                vec_add_ab(&out->v0, &out->v10, &out->v0);
                                out->f24 = func_0038D160(vC0.x, vC0.y);
                                if (g[0x1A14] != 0 ||
                                    (*(Vt_006233A8 **)(g + 0x14))->f48(g) != 0) {
                                    out->f28 = 1;
                                }
                            }
                            return 1;
                        }
                        t += step;
                        v120 = D_L39_0025F760;
                        vec_add_ab(&vE0, &v120, &vF0);
                        vec_add_ab(&vD0, &v120, &v100);
                    } while (t < lim);
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006233A8 */
