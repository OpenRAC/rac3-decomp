#include "common.h"

/* NTSC-U counterpart of func_003E3B68 (boot_elf). */
/* localdecomp:start func_U_003E3A20 */
#include "vu0.h"
typedef struct { char pad[48]; } Block48_003E37B0;
typedef struct { char pad[16]; } __attribute__((aligned(16))) Block16_003E37B0;
extern f32 D_U_001D9E90;
__asm__(".extern D_U_001D9E90, 16");
extern f32 D_U_00222480_003E37B0[];
extern s32 D_U_001D9580;
__asm__(".extern D_U_001D9580, 4");
extern f32 D_U_002224A0[];
extern void func_U_0038D290(void *, void *, f32);
extern void func_U_0038D630(void *, void *);
extern void func_U_0038D918(void *, void *, void *);
extern void func_U_0038D1B8(void *, void *, void *);
extern f32 func_U_0038D1D0(void *);
extern void func_U_003C4F38(void *, void *, f32);
extern void func_U_003C45E0(void *, f32, f32, f32, f32);
extern void func_U_0038DB38(void *, void *);

void func_U_003E3A20(f32 *arg0, s32 arg1)
{
    Block48_003E37B0 a;
    Block48_003E37B0 b;
    Block48_003E37B0 c;
    Block16_003E37B0 d;
    Block16_003E37B0 e;
    f32 v;
    vec_sub_ba(&e, D_U_00222480_003E37B0, &D_U_001D9E90);
    func_U_0038D290(&e, &e, 1.0f);
    func_U_0038D630(&c, &D_U_001D9580);
    func_U_0038D918(&b, D_U_00222480_003E37B0 + 8, &c);
    func_U_0038D1B8(&d, &b, &e);
    v = func_U_0038D1D0(&d) * 0.5f;
    if (arg1 != 0) {
        func_U_003C4F38(&d, &d, -v);
    } else {
        func_U_003C45E0(arg0, v, 0.0005817764322273433f, 0.0005817764322273433f, 0.05235988274216652f);
        func_U_003C4F38(&d, &d, -*arg0);
    }
    func_U_0038DB38(&d, &a);
    func_U_0038D918(D_U_002224A0, &a, D_U_002224A0);
}
/* localdecomp:end func_U_003E3A20 */
