/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_003BB120, the NTSC-U twin of func_L05_003BD078, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L05_003BD078.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L05_003BD078 (src/levels/shared/L05_003BD078.c) */
/* localdecomp:start func_L05_003BB120 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_L05_003BB120;

extern u16 D_L05_002A6540[][4];
extern u16 D_L05_002A6590[][4];
extern u16 D_L05_002A65E0[][4];
extern u8 D_L05_002A4C40[];
extern f32 D_001DEB28_sda;
__asm__(".extern D_001DEB28_sda, 4");
extern f32 D_001DEB2C_sda;
__asm__(".extern D_001DEB2C_sda, 4");

extern s32 func_003883C8(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004420D0(void *, void *, void *, void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);

void func_L05_003BB120(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V4_L05_003BB120 tmp0;
    V4_L05_003BB120 tmp1;
    V4_L05_003BB120 tmp2;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (n = 0; n < 4; n++) {
        if (func_003883C8(&D_L05_002A6540[*(s32 *)(p + 0x60)][n]) != 0) {
            D_L05_002A6590[*(s32 *)(p + 0x60)][n] = 0;
            D_L05_002A6540[*(s32 *)(p + 0x60)][n] = D_L05_002A65E0[*(s32 *)(p + 0x60)][n];
            tmp0 = *(V4_L05_003BB120 *)(p + 0x30);
            vec_sub_ba(&tmp1, &tmp0, obj + 0x10);
            func_00388830(&tmp1, &tmp1, D_001DEB28_sda);
            vec_add_ab(&tmp1, &tmp0, &tmp1);
            for (i = 0; i < 10; i++) {
                s32 off;
                f32 t = (f32)i * 0.1f;
                if (i == 9) {
                    t = 1.0f;
                }
                func_L01_004420D0(&tmp2, obj + 0x10, &tmp0, p + 0x40, &tmp1, t);
                off = *(s32 *)(p + 0x60) * 0x280;
                *(V4_L05_003BB120 *)(D_L05_002A4C40 + off + n * 0xA0 + i * 16) = tmp2;
            }
        }
        for (j = 2; j < 10; j++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4C40 + *(s32 *)(p + 0x60) * 0x280 + j * 16);
            tmp0.x += func_L01_00440918(0.0f, D_001DEB2C_sda);
            tmp0.y += func_L01_00440918(0.0f, D_001DEB2C_sda);
            tmp0.z += func_L01_00440918(0.0f, D_001DEB2C_sda);
            *(V4_L05_003BB120 *)(D_L05_002A4C40 + 0xA0 + *(s32 *)(p + 0x60) * 0x280 + j * 16) = tmp0;
        }
        for (k = 2; k < 10; k++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4C40 + *(s32 *)(p + 0x60) * 0x280 + k * 16);
            tmp0.x += func_L01_00440918(0.0f, D_001DEB2C_sda);
            tmp0.y += func_L01_00440918(0.0f, D_001DEB2C_sda);
            tmp0.z += func_L01_00440918(0.0f, D_001DEB2C_sda);
            *(V4_L05_003BB120 *)(D_L05_002A4C40 + 0x140 + *(s32 *)(p + 0x60) * 0x280 + k * 16) = tmp0;
        }
        for (l = 2; l < 10; l++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4C40 + *(s32 *)(p + 0x60) * 0x280 + l * 16);
            tmp0.x += func_L01_00440918(0.0f, D_001DEB2C_sda);
            tmp0.y += func_L01_00440918(0.0f, D_001DEB2C_sda);
            tmp0.z += func_L01_00440918(0.0f, D_001DEB2C_sda);
            *(V4_L05_003BB120 *)(D_L05_002A4C40 + 0x1E0 + *(s32 *)(p + 0x60) * 0x280 + l * 16) = tmp0;
        }
    }
}
/* localdecomp:end func_L05_003BB120 */
