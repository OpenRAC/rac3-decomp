#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003B0F48 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0F48;
typedef struct { V4_3B0F48 r[4]; } M4_3B0F48;
extern V4_3B0F48 D_L01_001E29C0;
extern u8 D_001DE5A0_sda[8];
__asm__(".extern D_001DE5A0_sda, 8");
extern void func_0043A778(void *, s32, void *);
extern void func_0043A6E0(void *, s32, void *);
extern void func_0040E828(void *, void *, void *);
extern void func_0040E620(void *dst, void *src, f32 s);
extern f32 func_0040E428(void *, void *);
extern s32 func_0040F550(s32, s32, f32);
extern void func_004518A0(void *, s32, f32, f32);

void func_L01_003B0F48(void *a0) {
    V4_3B0F48 v0;
    M4_3B0F48 m;
    V4_3B0F48 v50;
    V4_3B0F48 v60;
    V4_3B0F48 v70;
    f32 d;
    func_0043A778(a0, 11, &v0);
    func_0043A6E0(a0, 11, &m);
    func_0040E828(&v50, &D_001DE5A0_sda, &m);
    vec_add_ba(&v0, &v0, &v50);
    vec_sub_ab(&v60, &D_L01_001E29C0, &v0);
    func_0040E620(&v60, &v60, 1.0f);
    v70 = m.r[0];
    d = func_0040E428(&v60, &v70);
    if (0.0f < d) {
        d = d * d;
        func_004518A0(&v0, func_0040F550(0x806040, 0x80806040, d), 0.5f, 0.1f);
    }
}
/* localdecomp:end func_L01_003B0F48 */

/* localdecomp:start func_L01_003B1040 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B1040;
typedef struct { V4_3B1040 r[4]; } M4_3B1040;
extern u8 D_001DE5D0_sda[8];
__asm__(".extern D_001DE5D0_sda, 8");
extern u8 D_001DE600_sda[8];
__asm__(".extern D_001DE600_sda, 8");
extern u8 D_001DE5C0_sda[8];
__asm__(".extern D_001DE5C0_sda, 8");
extern u8 D_001DE5B0_sda[8];
__asm__(".extern D_001DE5B0_sda, 8");
extern void func_0043A778(void *, s32, void *);
extern void func_0043A6E0(void *, s32, void *);
extern void func_0040E828(void *, void *, void *);
extern void func_004518A0(void *, s32, f32, f32);

void func_L01_003B1040(void *a0) {
    V4_3B1040 v0;
    M4_3B1040 m;
    V4_3B1040 v50;
    s32 i;
    for (i = 0; i < 3; i++) {
        func_0043A778(a0, 8, &v0);
        func_0043A6E0(a0, 8, &m);
        func_0040E828(&v50, (V4_3B1040 *)D_001DE5D0_sda + i, &m);
        vec_add_ab(&v0, &v0, &v50);
        func_004518A0(&v0, ((s32 *)D_001DE600_sda)[i], ((f32 *)D_001DE5C0_sda)[i], ((f32 *)D_001DE5B0_sda)[i]);
    }
}
/* localdecomp:end func_L01_003B1040 */

INCLUDE_ASM("asm/levels", func_L01_003B1128);
