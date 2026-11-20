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

/* localdecomp:start func_L01_003B1128 */
typedef struct { u8 p[0x80]; } E_3B1128;
extern E_3B1128 D_001A30B0[];
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 16");
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_003B0D48(void *);
extern void func_L01_003B0BD8(void *);
extern void func_003C2880(void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L01_003B1128(u8 *o) {
    u8 *u = *(u8 **)(o + 0x68);
    s32 i = *(s32 *)(u + 0x334);
    s16 *p;
    if (i != -1) {
        u8 *e = (u8 *)&D_001A30B0[i];
        if (*(u8 **)(e + 0xDC) == o && *(e + 0xD0) != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(u + 0x334) = -1;
    func_003A52A0(4, 0, o);
    *(s32 *)(o + 0x98) = 0;
    func_L01_003B0D48(o);
    if (*(s32 *)(u + 0x2E0) != -1) {
        func_003C2880(D_001E001C_sda + (*(s32 *)(u + 0x2E0) << 8));
    }
    p = D_L01_0021DE20[*(s32 *)(u + 0x2E4)];
    while ((*(s32 *)(u + 0x2E4) & 0xFF) != 0xFF && D_001E0058_sda >= *(s32 *)(u + 0x2E4) && p != 0
           && (p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(u + 0x2E4)])) {
        u8 *q = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
        if (q == 0) break;
        p++;
        func_003C2880(q);
    }
    func_L01_003B0BD8(o);
    func_L01_003303B8(o + 16, 0, 25, 20, 20, 20, 20, 0, 1.25f, 0.0f, 10.0f, 5.0f,
                      0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003C2880(o);
}
/* localdecomp:end func_L01_003B1128 */
