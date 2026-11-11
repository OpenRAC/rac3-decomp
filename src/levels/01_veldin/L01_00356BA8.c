#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00356BA8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_356BA8;
typedef struct { V4_356BA8 r[4]; } M4_356BA8;
extern V4_356BA8 D_L01_001E29C0;
extern u8 D_001DD630_sda[8];
__asm__(".extern D_001DD630_sda, 8");
extern f32 D_001DD640_sda;
__asm__(".extern D_001DD640_sda, 4");
extern s32 D_001DD644_sda;
__asm__(".extern D_001DD644_sda, 4");
extern s32 D_001DD648_sda;
__asm__(".extern D_001DD648_sda, 4");
extern f32 D_001DD620_sda;
__asm__(".extern D_001DD620_sda, 4");
extern f32 D_001DD624_sda;
__asm__(".extern D_001DD624_sda, 4");
extern void func_0043A778(void *, s32, void *);
extern void func_0043A6E0(void *, s32, void *);
extern void func_0040E828(void *, void *, void *);
extern void func_0040E620(void *dst, void *src, f32 s);
extern f32 func_0040E428(void *, void *);
extern s32 func_0040F550(s32, s32, f32);
extern void func_004518A0(void *, s32, f32, f32);

void func_L01_00356BA8(void *a0) {
    V4_356BA8 v0;
    M4_356BA8 m;
    V4_356BA8 v50;
    V4_356BA8 v60;
    V4_356BA8 v70;
    f32 d;
    func_0043A778(a0, 0, &v0);
    func_0043A6E0(a0, 0, &m);
    func_0040E828(&v50, &D_001DD630_sda, &m);
    vec_add_ba(&v0, &v0, &v50);
    vec_sub_ab(&v60, &D_L01_001E29C0, &v0);
    func_0040E620(&v60, &v60, 1.0f);
    v70 = m.r[0];
    d = func_0040E428(&v60, &v70);
    if (D_001DD640_sda < d) {
        d = d * d;
        func_004518A0(&v0, func_0040F550(D_001DD648_sda, D_001DD644_sda, d), D_001DD624_sda, D_001DD620_sda);
    }
}
/* localdecomp:end func_L01_00356BA8 */
