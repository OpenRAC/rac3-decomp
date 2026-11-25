/* Unlinked regional matching draft. NTSC-U: 322 positional differences. The retail lowering and scheduling are still unresolved. */
#include "common.h"

/* localdecomp:start func_L32_003B61B8 */
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
} E_003B61B8;

typedef struct {
    u8 pad0[0x50];
    vu0_v4 f50;
    u8 pad60[0x20];
    E_003B61B8 e[4];
    s32 slot[4];
    s32 f8D0;
    s32 f8D4;
    f32 f8D8;
    f32 f8DC;
    f32 f8E0;
    f32 f8E4;
    s32 f8E8;
    f32 f8EC;
} V_003B61B8;

extern void func_L31_00345E88(void *, void *);
extern void func_L32_00347918(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_003887C8(void *, void *);
extern s32 func_L01_003F9498(void *, f32, s32, void *);
extern void func_L02_003B8758(void *, void *, void *, void *);
extern f32 func_00388770(void *);
extern void *D_L32_0021DF40[];
extern vu0_v4 D_L32_001E99A0;
extern f32 D_L32_001DE564;
extern f32 D_L32_001DE57C;
extern f32 D_L32_001DE598;
extern s32 D_L32_001DEFC8;
__asm__(".extern D_L32_001DEFC8, 4");

void func_L32_003B61B8(u8 *a0) {
    V_003B61B8 *v = *(V_003B61B8 **)(a0 + 0x68);
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

    func_L31_00345E88(a0, &v->f50);
    r = D_L32_001DE564 * D_L32_001DE57C;
    w = r + D_L32_001DE598;
    qzero(&up);
    up.y = 1.0f;
    i = 0;
    do {
        E_003B61B8 *entry = &v->e[i];
        v->slot[i] = 0;
        i++;
        entry->end = entry->end;
        func_L32_00347918(D_L32_0021DF40[entry->id], &A, 0.0f);
        entry->a[0] = entry->c[0] = A.x;
        entry->b[0] = entry->d[0] = A.z;
        for (j = 1; j < 32; j++) {
            func_L32_00347918(D_L32_0021DF40[entry->id], &B, (f32)j * 0.03125f);
            vec_sub_ab(&C, &B, &A);
            func_00388758(&D, &C, &up);
            func_00388830(&E, &D, w);
            vec_add_ab(&F, &E, &B);
            if (func_003CE740(&B, &F, 2, 0, 0)) {
                func_00388830(&E, &E, func_003887C8(&B, &D_L32_001E99A0) - r);
            }
            flag = 0;
            for (k = 0; k < D_L32_001DEFC8 && flag == 0; k++) {
                vec_add_ab(&F, &E, &B);
                if (func_L01_003F9498(&F, r, 2, 0)) {
                    vec_sub_ba(&G, &D_L32_001E99A0, &F);
                    func_L02_003B8758(&G, &D, &H, &I);
                    {
                        f32 eLength = func_00388770(&E);
                        f32 hLength = func_00388770(&H);
                        func_00388830(&E, &E, eLength - r + hLength);
                    }
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) {
                entry->a[j] = B.x;
                entry->b[j] = B.z;
            } else {
                entry->a[j] = F.x;
                entry->b[j] = F.z;
            }
            func_00388830(&E, &D, -w);
            vec_add_ab(&F, &E, &B);
            if (func_003CE740(&B, &F, 2, 0, 0)) {
                func_00388830(&E, &E, func_003887C8(&B, &D_L32_001E99A0) - r);
            }
            flag = 0;
            for (k = 0; k < D_L32_001DEFC8 && flag == 0; k++) {
                vec_add_ab(&F, &E, &B);
                if (func_L01_003F9498(&F, r, 2, 0)) {
                    vec_sub_ba(&G, &D_L32_001E99A0, &F);
                    func_L02_003B8758(&G, &D, &H, &I);
                    {
                        f32 eLength = func_00388770(&E);
                        f32 hLength = func_00388770(&H);
                        func_00388830(&E, &E, eLength - r + hLength);
                    }
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) {
                entry->c[j] = B.x;
                entry->d[j] = B.z;
            } else {
                entry->c[j] = F.x;
                entry->d[j] = F.z;
            }
            *(vu0_q *)&A = *(vu0_q *)&B;
        }
    } while (i < 4);
    v->f8E8 = 0;
    v->f8EC = v->f8EC * 0.00027777778f;
}
/* localdecomp:end func_L32_003B61B8 */
