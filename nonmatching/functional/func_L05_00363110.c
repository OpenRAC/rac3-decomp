/* functional: high. Same as 00362F30 plus the second submit; checked against asm. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_00363110 */
typedef struct {
    vu0_v4 corner[4];
    u32 color[4];
    f32 uv[8];
    u32 zero[2];
    long id;
    u32 gsreg[2];
    u32 flags[2];
} Quad_00363110;
extern vu0_v4 D_L05_001E2680;
extern f32 D_001DDA68_sda;
extern s32 D_001DDA70_sda;
extern s32 D_001DDA78_sda;
__asm__(".extern D_001DDA68_sda, 4");
__asm__(".extern D_001DDA70_sda, 4");
__asm__(".extern D_001DDA78_sda, 4");
extern f32 D_L05_001DDA80[];
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L05_00363110(u8 *obj, u128_361BA8 *unused) {
    vu0_v4 d1, d2;
    vu0_v4 u, a, b, t;
    Quad_00363110 q;
    u8 *w;
    s32 i;
    s32 col;

    vec_copy(&d1, &D_L05_001E2680);
    vec_copy(&d2, &D_L05_001E2680);
    w = *(u8 **)(obj + 0x68);
    vec_sub_ba(&u, w, w + 0x10);
    vec_sub_ab(&a, w, &d1);
    vec_sub_ba(&b, w + 0x10, &d2);
    func_0038CE90(&a, &a, &u);
    func_0038CF68(&a, &a, D_001DDA68_sda);
    func_0038CE90(&b, &b, &u);
    func_0038CF68(&b, &b, D_001DDA68_sda);
    q.id = func_00389598(19);
    col = D_001DDA78_sda;
    q.gsreg[0] = 0x260;
    q.gsreg[1] = 0xFF90;
    q.flags[0] = 0x48;
    q.flags[1] = D_001DDA70_sda;
    q.color[0] = col;
    q.color[1] = col;
    q.color[2] = col;
    q.color[3] = col;
    q.zero[0] = 0;
    q.zero[1] = 0;
    for (i = 0; i < 4; i++) {
        q.uv[i * 2] = D_L05_001DDA80[i * 2];
        q.uv[i * 2 + 1] = D_L05_001DDA80[i * 2 + 1];
    }
    vec_sub_ba(&t, w, &a);
    q.corner[0] = t;
    vec_add_ba(&t, w, &a);
    q.corner[1] = t;
    vec_sub_ba(&t, w + 0x10, &b);
    q.corner[2] = t;
    vec_add_ab(&t, w + 0x10, &b);
    q.corner[3] = t;
    func_003D2DA0(&q, 0, 0);
    q.id = func_00389598(23);
    q.gsreg[0] = 0x260;
    q.gsreg[1] = 0xFF90;
    q.flags[0] = 0x80000048;
    q.flags[1] = 0;
    q.zero[0] = 0;
    q.zero[1] = 0;
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L05_00363110 */
