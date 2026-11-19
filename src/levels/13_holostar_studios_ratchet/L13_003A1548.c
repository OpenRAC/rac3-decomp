#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_003A1548 */
/* f78 is signed: a u32 store of 0xFFFF0000 stays a zero-extended constant that gcc never puts in a delay slot */
typedef struct { u8 p0[0x78]; s32 f78; u8 p7C[0x84]; } E_3A1548;
typedef struct { vu0_v4 v[8]; } Mat_3A1548;
typedef struct {
    s32 m0; f32 f4; s32 m8; s32 mC; s32 m10; f32 f14; f32 f18; f32 f1C;
    vu0_v4 v20; vu0_v4 v30; vu0_v4 v40; vu0_v4 v50;
    f32 f60; f32 f64; f32 f68; f32 f6C; f32 f70; s32 m74;
} P_3A1548;
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 p31; s16 h32; u8 p34[0x68 - 0x34];
    P_3A1548 *p68; u8 p6C[0x96 - 0x6C]; u16 h96;
} O_3A1548;
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern E_3A1548 *D_L13_001DF59C;
extern Mat_3A1548 *D_L13_001DF680;
extern s32 D_001D545C;
__asm__(".extern D_L13_001DE2FC, 4");
extern f32 D_L13_001DE2FC;
extern s32 func_L01_00456500(void *, s32);
extern void func_L13_003D2690(s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L13_0044DB78(void *, s32, void *, f32);
extern void func_L13_004429F0(void *, s32, void *, f32);
extern void func_L01_00463218(void *, s32, s32);
void func_L13_003A1548(O_3A1548 *o) {
    P_3A1548 *p = o->p68;
    Mat_3A1548 mat;
    vu0_v4 ax, t90, ta0, tb0, tc0, td0;
    f32 f20, f25, r;
    E_3A1548 *e, *e0;
    s32 idx0, idx1;

    if (p->m74 != -1 && o->b20 != 0 && func_L01_00456500(D_001A4C60, p->m74) == 0) {
        return;
    }
    switch (o->b20) {
    case 0:
        o->b30 = 0xFF;
        o->h32 = 0x40;
        p->f70 = p->f4;
        idx0 = p->m8;
        if (idx0 != -1) {
            e0 = D_L13_001DF59C + idx0;
            if (p->m0 != 0) {
                e0->f78 = 0xFFFF0000;
            } else {
                e0->f78 = 0xFF00FF00;
            }
        }
        p->mC = 0;
        if (p->m0 >= 2) {
            p->m0 = 1;
        } else if (p->m0 < 0) {
            p->m0 = 0;
        }
        if (p->f4 > 2.0f) {
            p->f4 = 2.0f;
        } else if (p->f4 < 0.0f) {
            p->f4 = 0.0f;
        }
        if (D_001D545C == 0xD) {
            func_L13_003D2690(2, p->m0, 0);
        }
        if (p->m10 == -1) {
            func_003C2880(o);
            return;
        }
        mat = D_L13_001DF680[p->m10];
        qzero(&ax);
        ax.x = 1.0f;
        func_0038D000(&p->v20, &ax, &mat);
        p->f14 = func_0038CEA8(&p->v20) * 2.0f;
        qzero(&ax);
        ax.y = 1.0f;
        func_0038D000(&p->v30, &ax, &mat);
        p->f18 = func_0038CEA8(&p->v30) * 2.0f;
        qzero(&ax);
        ax.z = 1.0f;
        func_0038D000(&p->v40, &ax, &mat);
        p->f1C = func_0038CEA8(&p->v40) * 2.0f;
        vec_add_ab(&p->v50, &mat.v[3], &p->v40);
        func_0038CF68(&t90, &p->v30, -func_0038CEA8(&p->v30));
        vec_add_ab(&p->v50, &p->v50, &t90);
        func_0038CF68(&ta0, &p->v20, -func_0038CEA8(&p->v20));
        vec_add_ab(&p->v50, &p->v50, &ta0);
        func_L01_004450F0(o, 1, -1);
    case 1:
        idx1 = p->m8;
        if (idx1 != -1) {
            u8 *cam = D_001A4BE0;
            e = *(E_3A1548 **)(cam + 0x35C);
            if (e == D_L13_001DF59C + idx1 && *(s32 *)(cam + 0x360) != 0) {
                if (p->mC == 0) {
                    p->mC = 1;
                    if (p->m0 == 0) {
                        p->m0 = 1;
                        e->f78 = 0xFFFF0000;
                    } else {
                        p->m0 = 0;
                        e->f78 = 0xFF00FF00;
                    }
                    if (D_001D545C == 0xD) {
                        func_L13_003D2690(2, p->m0, 0);
                    }
                }
            } else if (p->mC != 0) {
                p->mC = 0;
            }
        }
        if (o->h96 >= 11) {
            mat = D_L13_001DF680[p->m10];
            func_0038CF68(&ax, &p->v40, -1.0f);
            f25 = 0.0f;
            p->f4 = D_L13_001DE2FC;
            if (f25 < p->f14) {
                do {
                    *(vu0_q *)&t90 = *(vu0_q *)&p->v50;
                    func_0038CF68(&ta0, &p->v20, f25);
                    f20 = 0.0f;
                    vec_add_ab(&t90, &t90, &ta0);
                    if (f20 < p->f18) {
                        do {
                            *(vu0_q *)&tc0 = *(vu0_q *)&t90;
                            func_0038CF68(&tb0, &p->v30, f20);
                            vec_add_ab(&tc0, &tc0, &tb0);
                            tc0.x += func_003824E0(0.0f, 1.0f / p->f4);
                            tc0.y += func_003824E0(0.0f, 1.0f / p->f4);
                            if (p->m0 != 0) {
                                r = func_003824E0(p->f68, p->f6C);
                                func_0038CF68(&td0, &ax, r);
                                func_L13_0044DB78(&tc0, 0, &td0, mat.v[3].z - p->f1C * 0.5f);
                            } else {
                                r = func_003824E0(p->f60, p->f64);
                                func_0038CF68(&td0, &ax, r);
                                func_L13_004429F0(&tc0, 1, &td0, mat.v[3].z - p->f1C * 0.5f);
                            }
                            if (p->m0 == 0) {
                                if (((s32)f20) & 1) {
                                    tc0.z -= p->f1C;
                                    tc0.y += func_003824E0(-1.0f, 1.0f);
                                    tc0.y += func_003824E0(-1.0f, 1.0f);
                                    func_L01_00463218(&tc0, func_00382498(0x40, 0x88), 0);
                                }
                            }
                            f20 += 1.0f / p->f4;
                        } while (f20 < p->f18);
                    }
                    f25 += 1.0f / p->f4;
                } while (f25 < p->f14);
            }
            o->h96 = 0;
        }
        break;
    default:
        break;
    }
    o->h96++;
}
/* localdecomp:end func_L13_003A1548 */
