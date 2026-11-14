#include "common.h"

/* localdecomp:start func_L32_003B7BE8 */
#include "vu0.h"
typedef struct {
    s32 count;
    s32 end;
    s32 start;
    s32 id;
    f32 a[32];
    f32 b[32];
    f32 c[32];
    f32 d[32];
} E_003B7BE8;

typedef struct {
    u8 pad0[0x50];
    vu0_v4 f50;
    u8 pad60[0x20];
    E_003B7BE8 e[4];
    s32 slot[4];
    s32 f8D0;
    s32 f8D4;
    f32 f8D8;
    f32 f8DC;
    f32 f8E0;
    f32 f8E4;
    s32 f8E8;
    f32 f8EC;
} V_003B7BE8;

extern void func_L31_00346998(void *, void *);
extern void func_L32_00348578(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void *D_L32_0021DF40[];
extern vu0_v4 D_L32_001E99A0;
extern f32 D_L32_001DE524;
extern f32 D_L32_001DE53C;
extern f32 D_L32_001DE558;
extern s32 D_L32_001DEF88;
__asm__(".extern D_L32_001DEF88, 4");

void func_L32_003B7BE8(u8 *a0) {
    V_003B7BE8 *v = *(V_003B7BE8 **)(a0 + 0x68);
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 C;
    vu0_v4 up;
    vu0_v4 D;
    vu0_v4 E;
    vu0_v4 F;
    vu0_v4 G;
    vu0_v4 H;
    vu0_v4 I;
    f32 r;
    f32 w;
    s32 i;
    s32 j;
    s32 k;
    s32 flag;

    func_L31_00346998(a0, &v->f50);
    r = D_L32_001DE524 * D_L32_001DE53C;
    w = r + D_L32_001DE558;
    qzero(&up);
    up.y = 1.0f;
    for (i = 0; i < 4; i++) {
        v->e[i].end = (v->e[i].end * 5 + 2) / 6;
        v->e[i].start = (v->e[i].start * 5 + 2) / 6;
        v->slot[i] = 0;
        func_L32_00348578(D_L32_0021DF40[v->e[i].id], &A, 0.0f);
        v->e[i].a[0] = v->e[i].c[0] = A.x;
        v->e[i].b[0] = v->e[i].d[0] = A.z;
        for (j = 1; j < 32; j++) {
            func_L32_00348578(D_L32_0021DF40[v->e[i].id], &B, (f32)j * 0.03125f);
            vec_sub_ab(&C, &B, &A);
            func_0038CE90(&D, &C, &up);
            func_0038CF68(&E, &D, w);
            vec_add_ab(&F, &E, &B);
            if (func_003D3CB0(&B, &F, 2, 0, 0)) {
                func_0038CF68(&E, &E, func_0038CF00(&B, &D_L32_001E99A0) - r);
            }
            flag = 0;
            for (k = 0; k < D_L32_001DEF88 && flag == 0; k++) {
                vec_add_ab(&F, &E, &B);
                if (func_L01_003FB640(&F, r, 2, 0)) {
                    vec_sub_ba(&G, &D_L32_001E99A0, &F);
                    func_L02_003BA9F8(&G, &D, &H, &I);
                    func_0038CF68(&E, &E, func_0038CEA8(&E) - r + func_0038CEA8(&H));
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) {
                v->e[i].a[j] = B.x;
                v->e[i].b[j] = B.z;
            } else {
                v->e[i].a[j] = F.x;
                v->e[i].b[j] = F.z;
            }
            func_0038CF68(&E, &D, -w);
            vec_add_ab(&F, &E, &B);
            if (func_003D3CB0(&B, &F, 2, 0, 0)) {
                func_0038CF68(&E, &E, func_0038CF00(&B, &D_L32_001E99A0) - r);
            }
            flag = 0;
            for (k = 0; k < D_L32_001DEF88 && flag == 0; k++) {
                vec_add_ab(&F, &E, &B);
                if (func_L01_003FB640(&F, r, 2, 0)) {
                    vec_sub_ba(&G, &D_L32_001E99A0, &F);
                    func_L02_003BA9F8(&G, &D, &H, &I);
                    func_0038CF68(&E, &E, func_0038CEA8(&E) - r + func_0038CEA8(&H));
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) {
                v->e[i].c[j] = B.x;
                v->e[i].d[j] = B.z;
            } else {
                v->e[i].c[j] = F.x;
                v->e[i].d[j] = F.z;
            }
            *(vu0_q *)&A = *(vu0_q *)&B;
        }
    }
    v->f8E8 = 0;
    v->f8EC = v->f8EC * 0.00040000002f;
    v->f8D4 = (v->f8D4 * 5 + 2) / 6;
}
/* localdecomp:end func_L32_003B7BE8 */
