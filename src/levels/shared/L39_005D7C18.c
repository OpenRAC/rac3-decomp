#include "common.h"

/* localdecomp:start func_L39_005D7C18 */
typedef struct {
    char pad0[0x20C];
    s32 *tbl;
} S_005D7C18;
extern s32 D_L39_00352B34[];
extern S_005D7C18 D_L39_00352940;

void func_L39_005D7C18(s32 *mode, f32 *a, f32 *b, f32 *c, s32 *n0, s32 *n1) {
    s32 i;
    s32 v;
    s32 t;
    S_005D7C18 *q;
    s32 *t2;

    t = D_L39_00352B34[0];
    *mode = t;
    switch (t) {
    case 4:
        *a = -0.144f;
        *b = 0.06f;
        *c = 0.0718f;
        break;
    case 5:
        *a = -0.151f;
        *b = 0.046f;
        *c = 0.057f;
        break;
    case 6:
        *a = -0.154f;
        *b = 0.0376f;
        *c = 0.047f;
        break;
    default:
        *a = -0.159f;
        *b = 0.03f;
        *c = 0.041f;
        break;
    }
    *n0 = 0;
    *n1 = 0;
    q = &D_L39_00352940;
    for (i = 0; i < 8; i++) {
        t2 = q->tbl + 42;
        v = t2[i];
        if (v == 0) {
            *n0 += 1;
        } else if (v == 1) {
            *n1 += 1;
        }
    }
}
/* localdecomp:end func_L39_005D7C18 */

/* localdecomp:start func_L39_005D7D80 */
extern s32 D_L39_0024C284;
__asm__(".extern D_L39_0024C284, 4");
extern s32 D_L39_0024C280_005D7D80;
__asm__(".extern D_L39_0024C280_005D7D80, 4");
extern s32 D_001D7F24_sda;
__asm__(".extern D_001D7F24_sda, 4");
extern s32 *D_L39_00241120;
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);

typedef struct { u8 pad[0x1F4]; s32 w1F4; } V_005D7D80;

void func_L39_005D7D80(void) {
    s32 c0 = 0;
    s32 c1 = 0;
    s32 i;
    s32 v;
    s32 j;
    f32 t;
    f32 f;
    f32 g;
    s32 id;

    for (j = 0; j < 8; j++) {
        v = D_L39_00352940.tbl[42 + j];
        if (v == 0) {
            c0++;
        } else if (v == 1) {
            c1++;
        }
    }
    if (D_L39_0024C284 == 0) {
        D_L39_0024C284 = 1;
        D_L39_0024C280_005D7D80 = ((V_005D7D80 *)&D_L39_00352940)->w1F4;
    }
    f = 0.5f / (f32)(D_L39_0024C280_005D7D80 + (D_L39_0024C280_005D7D80 + 1));
    g = f * 1.5f + 0.25f;
    for (i = 0; i < D_L39_0024C280_005D7D80; i++) {
        long col;
        s32 rem;
        id = i + 0x7001B;
        t = g + (f32)i * 2 * f;
        func_L01_00516AA0(id, 1, 1);
        func_L01_00516470(id, t, 0.5f);
        func_L01_00517538(id, f, 0.018f);
        rem = D_L39_0024C280_005D7D80 - (c1 + c0);
        if (i < c0) {
            col = 0x60FF0000;
        } else {
            col = i < c0 + rem ? D_001D7F24_sda : 0x600000FF;
        }
        func_L01_005170B8(id, col);
    }
    for (i = D_L39_0024C280_005D7D80; i < 7; i++) {
        func_L01_00516AA0(i + 0x7001B, 1, 0);
    }
    func_L01_00516470(0x70022, 0.5f, 0.5f);
    func_L01_00516AA0(0x70022, 1, 1);
    func_L01_005170B8(0x70022, 0x60000000);
    func_L01_00517538(0x70022, 0.48f, 0.02f);
    if (*D_L39_00241120 < 3) {
        func_L01_00516AA0(0x7001A, 1, 0);
    }
}
/* localdecomp:end func_L39_005D7D80 */
