#include "common.h"

/* localdecomp:start func_L02_004BDFD8 */
/* follows func_L39_006233A8, the multiplayer version of the same function */
#include "vu0.h"

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[4];
    f32 f24;
    s32 f28;
    u8 pad2C[8];
    s32 f34;
    void *f38;
} Out_004BDFD8;

typedef struct {
    vu0_v4 v0;
    u8 pad10[0x10];
    vu0_v4 v20;
    u8 pad30[0xF0 - 0x30];
    vu0_v4 vF0;
    u8 pad100[0x1D0 - 0x100];
    s16 h1D0;
    u8 pad1D2[0x284 - 0x1D2];
    f32 f284;
    u8 pad288[0x2E0 - 0x288];
    vu0_v4 v2E0;
    u8 pad2F0[0x33C - 0x2F0];
    f32 f33C;
    u8 pad340[0x46E - 0x340];
    u8 b46E;
    u8 pad46F[0x500 - 0x46F];
    Out_004BDFD8 out500;
    u8 pad540[0xC18 - 0x540];
    f32 fC18;
    u8 padC1C[0x25C0 - 0xC1C];
    void *p25C0;
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
} G_004BDFD8;

typedef struct {
    u8 pad0[0x18];
    void *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} H_004BDFD8;

extern G_004BDFD8 D_001A4BE0;
extern H_004BDFD8 D_L02_001E8040;
extern f32 func_L01_005114B0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D160(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00511508(void *, void *, f32);
extern f32 func_L01_00511848(void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(void *);

/* a += b through VU0 with the sum in a's register, loading a then b */
static __inline__ void addi_ab_004BDFD8(void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)a) : "j"(qa));
}

/* d = s, a quadword copy */
static __inline__ void vcopy_004BDFD8(vu0_v4 *d, vu0_v4 *s) {
    *d = *s;
}

/* a -= b through VU0 with the difference in a's register, loading a then b */
static __inline__ void subi_ab_004BDFD8(void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)a) : "j"(qa));
}

s32 func_L02_004BDFD8(vu0_v4 *pos, void *arg1, Out_004BDFD8 *out) {
    s32 flag;
    s32 i;
    s32 j;
    s32 hit;
    s32 r;
    s32 ok;
    void *obj;
    u8 *m;
    u8 *c;
    f32 lo;
    f32 up;
    f32 h;
    f32 w;
    f32 z;
    f32 step;
    f32 lim;

    if (out != 0) {
        out->f28 = 0;
    }
    if (D_001A4BE0.h1D0 != 0) {
        return 0;
    }
    flag = 0;
    if (D_001A4BE0.b25E4 == 0) {
        if ((D_001A4BE0.w25CC == 4 &&
             (D_001A4BE0.b46E != 0 || func_L01_005114B0(&D_001A4BE0.vF0) < 0.0700000077f)) ||
            D_001A4BE0.w25CC == 2 || D_001A4BE0.w25C4 == 8 || D_001A4BE0.w25C4 == 0x19 ||
            D_001A4BE0.w25C4 == 0x1A) {
            flag = 1;
        }
        if (D_001A4BE0.w25C4 == 0xE && D_001A4BE0.fC18 < 37.0f) {
            flag = 0;
        }
    }
    if (out != &D_001A4BE0.out500) {
        flag = 1;
    }
    if (flag != 0) {
        lo = -0.7f;
        up = 1.5f;
        h = 1.15f;
        z = -1.43f;
        w = 1.8f;
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

            vcopy_004BDFD8(&v0, pos);
            func_0038CF68(&t40, &D_001A4BE0.v0, D_001A4BE0.f284);
            vec_add_ba(&v0, &v0, &t40);
            func_0038CF68(&t40, &D_001A4BE0.v20, up + 0.15f);
            vec_add_ba(&v10, &v0, &t40);
            func_0038CF68(&t40, &D_001A4BE0.v20, -h);
            vec_add_ab(&v20, &v0, &t40);
            hit = 0;
            func_0038CF68(&t30, &D_001A4BE0.v0, 0.075f);
            for (i = 0; i < 4; i++) {
                addi_ab_004BDFD8(&v10, &t30);
                addi_ab_004BDFD8(&v20, &t30);
                if (func_003D3CB0(&v10, &v20, 4, D_001A4BE0.p25C0, 0) != 0) {
                    r = func_003D5630();
                    if (r != 9 && r != 12 && r != 0 &&
                        func_L01_00511848(&D_L02_001E8040.v40) < 0.349065840f) {
                        hit = 1;
                    }
                }
                if (hit) {
                    break;
                }
            }
            obj = 0;
            if (hit) {
                f32 d;

                if (D_L02_001E8040.f18 != 0) {
                    ok = 0;
                    m = func_00382348(D_L02_001E8040.f18);
                    c = func_003C4D58(D_L02_001E8040.f18);
                    if (m != 0 && (*(u16 *)(m + 0x1E) & 1)) {
                        ok = 1;
                    } else if (c != 0) {
                        ok = *(s32 *)(c + 0x3C) & 1;
                    }
                    if (!ok) {
                        return 0;
                    }
                    obj = D_L02_001E8040.f18;
                }
                if (out != 0) {
                    out->f38 = D_L02_001E8040.f18;
                }
                vcopy_004BDFD8(&v60, &D_L02_001E8040.v20);
                vec_sub_ba(&d50, &v60, pos);
                if (up < func_L01_005114B0(&d50)) {
                    return 0;
                }
                func_0038CF68(&v70, &D_001A4BE0.v20, 0.005f);
                addi_ab_004BDFD8(&v70, &v60);
                func_0038CF68(&v80, &D_001A4BE0.v0, -1.0f);
                addi_ab_004BDFD8(&v80, &v70);
                if (func_003D3CB0(&v80, &v70, 2, D_001A4BE0.p25C0, 0) != 0 &&
                    (D_L02_001E8040.f18 == 0 || D_L02_001E8040.f18 != obj)) {
                    return 0;
                }
                if (out != 0) {
                    func_0038CF68(&v90, &D_001A4BE0.v20, 0.6f);
                    addi_ab_004BDFD8(&v90, &v60);
                    if (func_L01_003FB640(&v90, 4, D_001A4BE0.p25C0, 0.45f) != 0) {
                        out->f34 |= 1;
                    } else {
                        out->f34 &= ~1;
                    }
                }
                d = func_L01_005114B0(&d50);
                if (d + D_001A4BE0.f33C < w) {
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

                    func_0038D000(&vB0, &vB0, &D_001A4BE0.v0);
                    found = 0;
                    vec_add_ba(&vB0, &vB0, &v60);
                    vec_sub_ab(&v90, pos, &vB0);
                    func_L01_00511508(&v90, &v90, 0.0f);
                    addi_ab_004BDFD8(&v90, &vB0);
                    func_0038CF68(&vA0, &D_001A4BE0.v20, -lo / 5.0f);
                    for (j = 0; j < 5; j++) {
                        if (func_003D3CB0(&v90, &vB0, 2, 0, 0) != 0) {
                            func_0038CF68(&vC0, &D_L02_001E8040.v40, 1.0f);
                            found = 1;
                            func_L01_00511508(&vC0, &vC0, 0.0f);
                            break;
                        }
                        addi_ab_004BDFD8(&v90, &vA0);
                        addi_ab_004BDFD8(&vB0, &vA0);
                    }
                    if (!found) {
                        return 0;
                    }
                    if (!(func_0038CE68(&D_001A4BE0.v0, &vC0) < func_0038D098(1.13446403f))) {
                        return 0;
                    }
                    vcopy_004BDFD8(&v120, &v60);
                    step = 0.03f;
                    func_0038CF68(&v110, &D_001A4BE0.v2E0, -0.05f);
                    func_0038CF68(&v100, &vC0, step);
                    lim = 2.4f;
                    t = 0.0f;
                    vec_add_ba(&vF0, &v100, &v110);
                    subi_ab_004BDFD8(&v100, &v110);
                    vec_add_ab(&vD0, &v120, &v100);
                    vec_add_ab(&vE0, &v120, &vF0);
                    do {
                        if (func_003D3CB0(&vE0, &vD0, 4, D_001A4BE0.p25C0, 0) == 0) {
                            if (out != 0) {
                                vcopy_004BDFD8(&out->v10, &v120);
                                func_0038CF68(&v130, &vC0, 0.5f);
                                func_0038CF68(&out->v0, &D_001A4BE0.v2E0, -z);
                                vec_add_ba(&out->v0, &v130, &out->v0);
                                vec_add_ab(&out->v0, &out->v10, &out->v0);
                                out->f24 = func_0038D160(vC0.x, vC0.y);
                                out->f28 = 1;
                            }
                            return 1;
                        }
                        t += step;
                        vcopy_004BDFD8(&v120, &D_L02_001E8040.v20);
                        vec_add_ab(&vE0, &v120, &vF0);
                        vec_add_ab(&vD0, &v120, &v100);
                    } while (t < lim);
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L02_004BDFD8 */
