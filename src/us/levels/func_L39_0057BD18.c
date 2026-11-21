#include "common.h"

/* NTSC-U counterpart of func_L39_0057CCC0 (src/levels/shared/L39_0057CCC0.c) */
/* localdecomp:start func_L39_0057BD18 */
typedef struct {
    s32 start;
    s32 end;
} Region_0057CCC0;

typedef struct {
    s32 w0;
    s16 n1;
    s16 n2;
    s32 total1;
    s32 total2;
    Region_0057CCC0 r1[50];
    Region_0057CCC0 r2[50];
} S_0057CCC0;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w[0xC0];
} S_1A6A80_0057CCC0;

extern S_0057CCC0 D_L39_00480E38;
extern u8 D_L39_002403C8[] __attribute__((section(".sdata")));
extern u8 D_L39_00228880[];
extern u8 D_L39_0049C950[];
extern s32 D_L39_0025F780_0057BD18[];
extern S_1A6A80_0057CCC0 D_001A6C00;
extern s32 D_001D6D24_sda_0057BD18;
extern s32 func_00129E18(void *, s32, s32, void *, s32, void *, s32, s32, s32);
extern void func_00388550(void *, void *, s32);

void func_L39_0057BD18(void) {
    u8 buf[16];
    s32 n = D_L39_00480E38.n2;
    s32 i;
    s32 k;

    func_00129E18(D_L39_002403C8, 5, 0, buf, 16, &D_L39_00480E38, 0x1A0, 0, 0);
    func_00388550(D_L39_00228880, &D_L39_00480E38, 0x330);
    D_L39_00480E38.r2[n].start = (s32)D_L39_0049C950;
    D_L39_00480E38.r2[n].end = (s32)D_L39_0049C950 + 0xC80;
    n++;
    D_L39_00480E38.r2[n].start = D_L39_0025F780_0057BD18[10];
    D_L39_00480E38.r2[n].end = D_L39_0025F780_0057BD18[11];
    n++;
    D_L39_00480E38.n2 = n;
    D_L39_00480E38.total2 = 0;
    for (i = 0; i < D_L39_00480E38.n2; i++) {
        D_L39_00480E38.r2[i].start = (D_L39_00480E38.r2[i].start + 3) & ~3;
        D_L39_00480E38.r2[i].end &= ~3;
        D_L39_00480E38.total2 += D_L39_00480E38.r2[i].end - D_L39_00480E38.r2[i].start;
    }
    D_L39_00480E38.total1 = 0;
    for (i = 0; i < D_L39_00480E38.n1; i++) {
        D_L39_00480E38.r1[i].start = (D_L39_00480E38.r1[i].start + 3) & ~3;
        D_L39_00480E38.r1[i].end &= ~3;
        D_L39_00480E38.total1 += D_L39_00480E38.r1[i].end - D_L39_00480E38.r1[i].start;
    }
    D_001D6D24_sda_0057BD18 = 0;
    for (k = 0; k < 0xC0; k++) {
        if (D_001A6C00.w[k] != 0) {
            D_001D6D24_sda_0057BD18++;
        }
    }
}
/* localdecomp:end func_L39_0057BD18 */
