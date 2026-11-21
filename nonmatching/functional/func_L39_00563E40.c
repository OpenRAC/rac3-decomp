/* functional: high. Draw callback companion of func_L39_005635D0; diffs are codegen only (vadd/vsub.xyz, lq/sq as float loops, w lane kept like sqc2). */
#include "common.h"
extern s32 D_001DFDE8_sda;
__asm__(".extern D_001DFDE8_sda, 4");
extern s32 D_001DFDEC_sda;
__asm__(".extern D_001DFDEC_sda, 4");
extern f32 D_001DFE34_sda;
__asm__(".extern D_001DFE34_sda, 4");
extern s16 D_0024D6D0[5];
extern s16 D_0024D6E0[5];
extern s16 D_0024D6F0[5];
extern f32 D_0024D714[];
extern f32 D_003CD480[5][10][4];
void func_L01_00409658(void *, s32, s32, s32, f32, f32, f32, long, long, s32);

void func_L39_00563E40(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    f32 base[4];
    f32 dv[9][4];
    s32 i, k, alpha, col;
    f32 *q;
    base[0] = *(f32 *)(st + 0x30);
    base[1] = *(f32 *)(st + 0x34);
    base[2] = *(f32 *)(st + 0x38);
    base[3] = *(f32 *)(st + 0x3C);
    for (i = 0; i < 5; i++) {
        if (D_0024D6D0[i] != 0) {
            q = D_003CD480[i][0];
            for (k = 0; k < 9; k++) {
                f32 *a = D_003CD480[i][k + 1];
                f32 *b = D_003CD480[i][k];
                dv[k][0] = a[0] - b[0];
                dv[k][1] = a[1] - b[1];
                dv[k][2] = a[2] - b[2];
                dv[k][3] = a[3];
            }
            q[0] = base[0];
            q[1] = base[1];
            q[2] = base[2];
            q[3] = 0.04f;
            for (k = 0; k < 9; k++) {
                f32 *a = D_003CD480[i][k + 1];
                f32 *b = D_003CD480[i][k];
                a[0] = b[0] + dv[k][0];
                a[1] = b[1] + dv[k][1];
                a[2] = b[2] + dv[k][2];
                a[3] = 0.04f;
            }
            if (D_0024D6D0[i] > 0)
                D_0024D6E0[i] = (s32)(D_001DFE34_sda * ((f32)D_0024D6D0[i] / (f32)D_0024D6F0[i]));
            else
                D_0024D6E0[i] = 0;
        }
    }
    for (i = 0; i < 5; i++) {
        if (D_0024D6D0[i] != 0) {
            alpha = (s32)((f32)D_0024D6E0[i] * D_0024D714[0]);
            col = (*(s16 *)(obj + 0xAA) == 0x1192) ? D_001DFDEC_sda : D_001DFDE8_sda;
            func_L01_00409658(D_003CD480[i][0], 0x17, 0xE, 0xA, 0.0f, 4.0f, 0.0f,
                              (long)((alpha << 24) | 0x7F7F7F), (long)((alpha << 24) | col), 1);
        }
    }
}
