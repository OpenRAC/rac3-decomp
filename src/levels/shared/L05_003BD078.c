#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003BD078 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_L05_003BB120;

extern u16 D_L05_002A64C0[][4];
extern u16 D_L05_002A6510[][4];
extern s16 D_L05_002A6560[][4];
extern u8 D_L05_002A4BC0[];
extern f32 D_L05_001DEAE8;
__asm__(".extern D_L05_001DEAE8, 4");
extern f32 D_L05_001DEAEC;
__asm__(".extern D_L05_001DEAEC, 4");

extern s32 func_0038CB00(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L05_003BD078(u8 *obj) {
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
        if (func_0038CB00(&D_L05_002A64C0[*(s32 *)(p + 0x60)][n]) != 0) {
            D_L05_002A6510[*(s32 *)(p + 0x60)][n] = 0;
            D_L05_002A64C0[*(s32 *)(p + 0x60)][n] = (D_L05_002A6560[*(s32 *)(p + 0x60)][n] * 5 + 2) / 6;
            tmp0 = *(V4_L05_003BB120 *)(p + 0x30);
            vec_sub_ba(&tmp1, &tmp0, obj + 0x10);
            func_0038CF68(&tmp1, &tmp1, D_L05_001DEAE8);
            vec_add_ab(&tmp1, &tmp0, &tmp1);
            for (i = 0; i < 10; i++) {
                s32 off;
                f32 t = (f32)i * 0.1f;
                if (i == 9) {
                    t = 1.0f;
                }
                func_L01_00445208(&tmp2, obj + 0x10, &tmp0, p + 0x40, &tmp1, t);
                off = *(s32 *)(p + 0x60) * 0x280;
                *(V4_L05_003BB120 *)(D_L05_002A4BC0 + off + n * 0xA0 + i * 16) = tmp2;
            }
        }
        for (j = 2; j < 10; j++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4BC0 + *(s32 *)(p + 0x60) * 0x280 + j * 16);
            tmp0.x += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.y += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.z += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            *(V4_L05_003BB120 *)(D_L05_002A4BC0 + 0xA0 + *(s32 *)(p + 0x60) * 0x280 + j * 16) = tmp0;
        }
        for (k = 2; k < 10; k++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4BC0 + *(s32 *)(p + 0x60) * 0x280 + k * 16);
            tmp0.x += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.y += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.z += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            *(V4_L05_003BB120 *)(D_L05_002A4BC0 + 0x140 + *(s32 *)(p + 0x60) * 0x280 + k * 16) = tmp0;
        }
        for (l = 2; l < 10; l++) {
            tmp0 = *(V4_L05_003BB120 *)(D_L05_002A4BC0 + *(s32 *)(p + 0x60) * 0x280 + l * 16);
            tmp0.x += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.y += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            tmp0.z += func_L01_00443A18(0.0f, D_L05_001DEAEC);
            *(V4_L05_003BB120 *)(D_L05_002A4BC0 + 0x1E0 + *(s32 *)(p + 0x60) * 0x280 + l * 16) = tmp0;
        }
    }
}
/* localdecomp:end func_L05_003BD078 */
