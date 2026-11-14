#include "common.h"
#include "dnas.h"

/* the second library's driver: driver(block, k1, k2, k3) (include/dnas.h) */
extern void func_L39_004F7890(s32, s32, s32, u32);

/* localdecomp:start func_L39_004CCE58 */
extern s32 D_L39_00465848;
extern s32 func_L39_004D0B08(void);
extern void func_L39_004B76F8(void);

s32 func_L39_004CCE58(void) {
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004CCE58, 0, func_L39_004F7890);
    if (D_L39_00465848 == 1) {
        if (func_L39_004D0B08() >= 0) {
            ret = 0;
            func_L39_004B76F8();
            D_L39_00465848 = 0;
        }
    } else {
        ret = 0;
    }
    DNAS_END(func_L39_004CCE58, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CCE58 */

INCLUDE_ASM("asm/levels", func_L39_004CCF68);

INCLUDE_ASM("asm/levels", func_L39_004CD638);

/* localdecomp:start func_L39_004CD8E8 */
extern s32 D_L39_00465848;

s32 func_L39_004CD8E8(u8 *buf) {
    s32 ret;
    u32 i;

    DNAS_BEGIN(func_L39_004CD8E8, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
    } else {
        for (i = 0; i < 4; i++) {
            buf[i] = 0xFF;
        }
        ret = 4;
    }
    DNAS_END(func_L39_004CD8E8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CD8E8 */

/* localdecomp:start func_L39_004CDA00 */
extern s32 D_L39_00465848;

s32 func_L39_004CDA00(u8 *buf) {
    s32 ret;
    u32 i;

    DNAS_BEGIN(func_L39_004CDA00, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
    } else {
        for (i = 0; i < 16; i++) {
            buf[i] = 0xFF;
        }
        ret = 16;
    }
    DNAS_END(func_L39_004CDA00, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDA00 */

/* localdecomp:start func_L39_004CDB18 */
extern s32 D_L39_00465848;

s32 func_L39_004CDB18(void) {
    s32 ret;

    DNAS_BEGIN(func_L39_004CDB18, 0, func_L39_004F7890);
    ret = -8;
    if (D_L39_00465848 == 1) {
        ret = 0x10;
    }
    DNAS_END(func_L39_004CDB18, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDB18 */

/* localdecomp:start func_L39_004CDC00 */
extern s32 D_L39_00465848;

s32 func_L39_004CDC00(void) {
    s32 ret;

    DNAS_BEGIN(func_L39_004CDC00, 0, func_L39_004F7890);
    ret = -8;
    if (D_L39_00465848 == 1) {
        ret = 0;
    }
    DNAS_END(func_L39_004CDC00, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDC00 */

LINKER_REMNANT("asm/levels", func_L39_004CDCE8);

/* localdecomp:start func_L39_004CDCF0 */
extern s32 D_L39_00465848;

s32 func_L39_004CDCF0(void) {
    s32 ret;

    DNAS_BEGIN(func_L39_004CDCF0, 0, func_L39_004F7890);
    ret = -8;
    if (D_L39_00465848 == 1) {
        ret = 0x90;
    }
    DNAS_END(func_L39_004CDCF0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDCF0 */

/* localdecomp:start func_L39_004CDDD8 */
extern s32 D_L39_00465848;

s32 func_L39_004CDDD8(void) {
    s32 ret;

    DNAS_BEGIN(func_L39_004CDDD8, 0, func_L39_004F7890);
    ret = -8;
    if (D_L39_00465848 == 1) {
        ret = 1;
    }
    DNAS_END(func_L39_004CDDD8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDDD8 */

/* localdecomp:start func_L39_004CDEC0 */
typedef struct {
    u8 b[8];
} S_004CDEC0;

extern S_004CDEC0 D_L39_00475F50;
extern s32 func_L39_004D1CA0(s32, s32, s32, s32);

s32 func_L39_004CDEC0(s32 a0, s32 a1, s32 a2) {
    S_004CDEC0 key = D_L39_00475F50;
    s32 ret;

    DNAS_BEGIN(func_L39_004CDEC0, 0, func_L39_004F7890);
    ret = func_L39_004D1CA0(a0, (s32)&key, a1, a2);
    DNAS_END(func_L39_004CDEC0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDEC0 */

/* localdecomp:start func_L39_004CDFE0 */
typedef struct {
    u8 b[24];
} S_004CDFE0;

extern S_004CDFE0 D_L39_00475F58;

s32 func_L39_004CDFE0(s32 a0) {
    S_004CDFE0 key = D_L39_00475F58;
    s32 ret;

    DNAS_BEGIN(func_L39_004CDFE0, 0, func_L39_004F7890);
    ret = func_L39_004CDEC0((s32)&key, a0, 3);
    DNAS_END(func_L39_004CDFE0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CDFE0 */

INCLUDE_ASM("asm/levels", func_L39_004CE100);

INCLUDE_ASM("asm/levels", func_L39_004CE2D0);

INCLUDE_ASM("asm/levels", func_L39_004CE4A0);

INCLUDE_ASM("asm/levels", func_L39_004CE750);

/* localdecomp:start func_L39_004CE968 */
extern s32 D_L39_00465848;
s32 func_L39_004CE968(u8 *buf) {
    s32 ret;
    u32 i;
    DNAS_BEGIN(func_L39_004CE968, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
    } else {
        for (i = 0; i < 32; i++) {
            buf[i] = 0xFF;
        }
        ret = 32;
    }
    DNAS_END(func_L39_004CE968, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CE968 */

INCLUDE_ASM("asm/levels", func_L39_004CEA80);

INCLUDE_ASM("asm/levels", func_L39_004CEC98);

/* localdecomp:start func_L39_004CEE68 */
extern s32 D_L39_00465848;
extern s32 func_L39_004CEC98(u8 *);

s32 func_L39_004CEE68(u8 *out) {
    u8 buf[8];
    s32 ret;
    s32 i;
    u8 *p;

    DNAS_BEGIN(func_L39_004CEE68, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
    } else {
        ret = -0x192;
        if (func_L39_004CEC98(buf) != 0) {
            ret = 5;
            out[0] = buf[3] >> 4;
            out[1] = buf[3] & 0xF;
            out[2] = buf[2];
            out[3] = buf[1];
            out[4] = buf[0];
        }
    }
    i = 4;
    p = &buf[4];
    for (; i >= 0; i--) {
        *p-- = 0;
    }
    DNAS_END(func_L39_004CEE68, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CEE68 */

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
