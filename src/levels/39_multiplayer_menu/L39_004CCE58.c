#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004CCE58);

INCLUDE_ASM("asm/levels", func_L39_004CCF68);

INCLUDE_ASM("asm/levels", func_L39_004CD638);

INCLUDE_ASM("asm/levels", func_L39_004CD8E8);

INCLUDE_ASM("asm/levels", func_L39_004CDA00);

INCLUDE_ASM("asm/levels", func_L39_004CDB18);

INCLUDE_ASM("asm/levels", func_L39_004CDC00);

INCLUDE_ASM("asm/levels", func_L39_004CDCF0);

INCLUDE_ASM("asm/levels", func_L39_004CDDD8);

INCLUDE_ASM("asm/levels", func_L39_004CDEC0);

INCLUDE_ASM("asm/levels", func_L39_004CDFE0);

INCLUDE_ASM("asm/levels", func_L39_004CE100);

INCLUDE_ASM("asm/levels", func_L39_004CE2D0);

INCLUDE_ASM("asm/levels", func_L39_004CE4A0);

INCLUDE_ASM("asm/levels", func_L39_004CE750);

INCLUDE_ASM("asm/levels", func_L39_004CE968);

INCLUDE_ASM("asm/levels", func_L39_004CEA80);

INCLUDE_ASM("asm/levels", func_L39_004CEC98);

INCLUDE_ASM("asm/levels", func_L39_004CEE68);

INCLUDE_ASM("asm/levels", func_L39_004CEFC0);

INCLUDE_ASM("asm/levels", func_L39_004CF1D8);

INCLUDE_ASM("asm/levels", func_L39_004CF508);

/* localdecomp:start func_L39_004CF720 */
s32 func_L39_004CF720(s8 *s) {
    s8 *start = s;

    while (*s != 0) {
        s++;
    }
    return s - start;
}
/* localdecomp:end func_L39_004CF720 */

INCLUDE_ASM("asm/levels", func_L39_004CF758);

INCLUDE_ASM("asm/levels", func_L39_004CF890);

INCLUDE_ASM("asm/levels", func_L39_004CFA00);

INCLUDE_ASM("asm/levels", func_L39_004CFBA8);

INCLUDE_ASM("asm/levels", func_L39_004CFE20);

INCLUDE_ASM("asm/levels", func_L39_004CFF30);

/* localdecomp:start func_L39_004D0138 */
extern s32 func_L39_004D0C78(void);
extern u8 D_L39_00469F40[];

void func_L39_004D0138(u8 *arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        arg0[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    for (j = 0; j < 16; j++) {
        arg0[j] ^= D_L39_00469F40[j];
    }
}
/* localdecomp:end func_L39_004D0138 */

/* localdecomp:start func_L39_004D0228 */
extern u8 D_L39_00469F40[];
extern void func_L39_004D2468(u8 *, s32, u8 *);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004D0228(u8 *dst, u8 *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004D0228(u8 *dst, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

void func_L39_004D0228(u8 *a0, u8 *a1, u8 *out) {
    u8 buf[48];
    s32 i;

    copy_004D0228(buf, a0, 16);
    copy_004D0228(buf + 16, a1, 16);
    copy_004D0228(buf + 32, a0, 16);
    for (i = 0; i < 16; i++) {
        buf[i + 16] ^= D_L39_00469F40[i];
        buf[i + 32] ^= D_L39_00469F40[i];
    }
    func_L39_004D2468(buf, 48, out);
    randfill_004D0228(buf, 48);
}
/* localdecomp:end func_L39_004D0228 */

/* localdecomp:start func_L39_004D03B8 */
extern s32 func_L39_004D0C78(void);

static __inline__ void randfill_004D03B8(u8 *dst, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

void func_L39_004D03B8(u8 *data, u8 *key, u32 len) {
    u8 buf[2][20];
    u32 i;

    for (i = 0; i < len; i++) {
        if (i < 20) {
            buf[(i / 20) & 1][i % 20] = data[i];
            data[i] ^= key[i % 20];
        } else {
            buf[(i / 20) & 1][i % 20] = data[i];
            data[i] ^= key[i % 20];
            data[i] ^= buf[(i / 20 + 1) & 1][i % 20];
        }
    }
    randfill_004D03B8(buf[0], 20);
    randfill_004D03B8(buf[1], 20);
}
/* localdecomp:end func_L39_004D03B8 */

INCLUDE_ASM("asm/levels", func_L39_004D05D8);

INCLUDE_ASM("asm/levels", func_L39_004D0B08);
