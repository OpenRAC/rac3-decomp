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

/* localdecomp:start func_L39_004CCF68 */
extern s32 D_L39_00465848;
extern u8 D_L39_00469F58[];
extern u8 D_L39_00469F60[];
extern u8 D_L39_00469F70[];
extern u8 D_L39_0046A048[];
extern u8 D_L39_0046A058[];
extern s32 func_L39_004D3FA0(u8 *a0, u8 *out);
extern s32 func_L39_004CE750(u8 *);
extern s32 func_L39_004CEA80(u8 *);
extern s32 func_L39_004CEFC0(u8 *);
extern s32 func_L39_004CF508(u8 *);
extern s32 func_L39_004D40A8(u8 *, u8 *, u8 *);
extern s32 func_L39_004D0C78(void);
extern s32 func_L39_004D1C18(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L39_004D1D28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

static __inline__ void copy_004CCF68(u8 *dst, u8 *src, u32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CCF68(u8 *dst, u32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CCF68(u8 *ctx, u8 *out) {
    u8 id[40];
    u8 b30[56];
    u8 b70[32];
    u8 b90[40];
    u8 key[16];
    u8 type;
    s32 ret;
    u32 i;
    u8 *p;
    s32 k;

    type = 0;
    DNAS_BEGIN(func_L39_004CCF68, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
        goto cleanup;
    }
    if (func_L39_004D3FA0(ctx, &type) < 0) {
        ret = -0x193;
        goto cleanup;
    }
    if (type >= 2) {
        ret = -0x193;
        goto cleanup;
    }
    if (func_L39_004CE750(id) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    if (func_L39_004CEA80(b30) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    if (type == 0) {
        if (func_L39_004CEFC0(b70) < 0) {
            ret = -0x192;
            goto cleanup;
        }
        if (func_L39_004CF508(b90) < 0) {
            ret = -0x192;
            goto cleanup;
        }
    }
    if (type == 1) {
        if (func_L39_004D40A8(ctx, b70, b90) < 0) {
            ret = -0x193;
            goto cleanup;
        }
    }
    for (i = 0; i < 0x100; i++) {
        out[i] = 0;
    }
    copy_004CCF68(out, id, 40);
    p = out + 40;
    copy_004CCF68(p, b30, 56);
    p += 56;
    copy_004CCF68(p, b90, 40);
    p += 40;
    copy_004CCF68(p, b70, 32);
    p = out + 0xE8;
    for (k = 0; k < 16; k++) {
        p[k] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    p += 16;
    {
        u8 *d = p;
        u8 *s = D_L39_00469F58;
        s32 j;
        for (j = 0; j < 8; j++) {
            d[j] = s[j];
        }
    }
    if (func_L39_004D1D28((s32)out, (s32)(out + 0xE8), (s32)out, (s32)(out + 0xF0), 0x1D) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    if (func_L39_004D1C18((s32)D_L39_0046A048, (s32)D_L39_0046A058, (s32)key, 2) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    if (func_L39_004D1D28((s32)(out + 0xE8), (s32)key, (s32)(out + 0xE8), (s32)(key + 8), 2) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    if (func_L39_004D1C18((s32)D_L39_00469F60, (s32)D_L39_00469F70, (s32)key, 2) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    if (func_L39_004D1D28((s32)(out + 0xE8), (s32)key, (s32)(out + 0xE8), (s32)(key + 8), 3) < 0) {
        ret = -0x191;
        goto cleanup;
    }
    ret = 0x100;
cleanup:
    randfill_004CCF68(b70, 32);
    randfill_004CCF68(id, 40);
    randfill_004CCF68(b30, 56);
    randfill_004CCF68(b90, 40);
    randfill_004CCF68(key, 16);
    DNAS_END(func_L39_004CCF68, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CCF68 */

/* localdecomp:start func_L39_004CD638 */
extern s32 D_L39_00465848;
extern u8 D_L39_0046A060[];
extern u8 D_L39_0046A080[];
extern s32 func_L39_004D1C18(s32, s32, s32, s32);
extern s32 func_L39_004D1FB8(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L39_004D2AF8(u8 *, u8 *, u8 *, u8 *, u8 *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004CD638(void *a0, void *a1, void *a2, void *a3, void *a4) {
    u8 data[0x120];
    u8 key[32];
    s32 ret;
    u32 i;

    DNAS_BEGIN(func_L39_004CD638, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
        goto wipe;
    }
    if (func_L39_004D1C18((s32)D_L39_0046A060, (s32)D_L39_0046A080, (s32)key, 4) < 0) {
        ret = -0x191;
        goto wipe;
    }
    if (func_L39_004D1FB8((s32)a2, (s32)key, (s32)(key + 16), (s32)(key + 8), (s32)data, (s32)(key + 24), 0x24) < 0) {
        ret = -0x191;
        goto wipe;
    }
    if (func_L39_004D2AF8(a0, a1, data, a3, a4) < 0) {
        ret = -0x1F5;
        goto wipe;
    }
    ret = 0;
wipe:
    {
        u8 *q = data;
        for (i = 0; i < 0x120; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = key;
        for (i = 0; i < 32; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    DNAS_END(func_L39_004CD638, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CD638 */

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

/* localdecomp:start func_L39_004CE100 */
typedef struct {
    s32 value;
    u8 key[8];
} S_004CE100;

extern s32 func_L39_004D05D8(u8 *, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004CE100(u8 *dst, u8 *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CE100(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CE100(u8 *out) {
    S_004CE100 rec;
    s32 ret;

    DNAS_BEGIN(func_L39_004CE100, 0, func_L39_004F7890);
    if (func_L39_004D05D8((u8 *)&rec, sizeof(rec), 0xDCD29) < 0) {
        ret = 0;
    } else {
        ret = rec.value;
        copy_004CE100(out, rec.key, 8);
    }
    randfill_004CE100((u8 *)&rec, sizeof(rec));
    DNAS_END(func_L39_004CE100, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CE100 */

/* localdecomp:start func_L39_004CE2D0 */
extern s32 func_L39_004D05D8(u8 *, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004CE2D0(u8 *dst, u8 *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CE2D0(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CE2D0(u8 *out) {
    u8 buf[12];
    s32 ret;

    DNAS_BEGIN(func_L39_004CE2D0, 0, func_L39_004F7890);
    if (func_L39_004D05D8(buf, 12, 0x57709) < 0) {
        ret = 0;
    } else {
        ret = *(s32 *)buf;
        copy_004CE2D0(out, buf + 4, 8);
    }
    randfill_004CE2D0(buf, 12);
    DNAS_END(func_L39_004CE2D0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CE2D0 */

/* localdecomp:start func_L39_004CE4A0 */
extern s32 func_L39_004CE100(u8 *);
extern s32 func_L39_004CE2D0(u8 *);
extern s32 func_L39_004D0C78(void);

static __inline__ void randfill_004CE4A0(u8 *dst, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CE4A0(u8 *out) {
    u8 a[8];
    u8 b[8];
    s32 ret;
    s32 i;

    DNAS_BEGIN(func_L39_004CE4A0, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
    } else if (func_L39_004CE100(a) == 0) {
        ret = -0x191;
    } else if (func_L39_004CE2D0(b) == 0) {
        ret = -0x191;
    } else {
        out[0] = b[2];
        out[1] = b[1];
        out[2] = b[0];
        out[3] = a[0];
        out[4] = a[7];
        out[5] = a[6];
        out[6] = a[5];
        out[7] = a[4];
        for (i = 7; i >= 0; i--) {
            out[8 + i] = 0;
        }
        ret = 0x10;
    }
    randfill_004CE4A0(a, 8);
    randfill_004CE4A0(b, 8);
    DNAS_END(func_L39_004CE4A0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CE4A0 */

/* localdecomp:start func_L39_004CE750 */
extern u8 D_L39_00469F78[];
extern u8 D_L39_00469FB8[];
extern u8 D_L39_00469FD8[];
extern s32 func_L39_004CFF30(u8 *);
extern s32 func_L39_004CE4A0(u8 *);
extern s32 func_L39_004D4730(u8 *, s32, u8 *, u8 *, s32, u8 *, u8 *, u8 *, u8 *, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004CE750(u8 *dst, u8 *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CE750(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CE750(u8 *out) {
    u8 key[16];
    u8 id[8];
    u8 info[16];
    u8 buf[16];
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004CE750, 0, func_L39_004F7890);
    if (func_L39_004CFF30(info) == 1) {
        copy_004CE750(id, info, 8);
        if (func_L39_004CE4A0(key) < 0) {
            ret = -1;
        } else if (func_L39_004D4730(out, 0x28, buf, key, 0x10, D_L39_00469F78, id,
                                     D_L39_00469FB8, D_L39_00469FD8, 2) < 0) {
            ret = -1;
        } else {
            ret = 0;
        }
    }
    randfill_004CE750(key, 16);
    DNAS_END(func_L39_004CE750, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CE750 */

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

/* localdecomp:start func_L39_004CEA80 */
extern u8 D_L39_00469F98[];
extern u8 D_L39_00469FB8[];
extern u8 D_L39_00469FD8[];
extern s32 func_L39_004CFF30(u8 *);
extern s32 func_L39_004CE968(u8 *);
extern s32 func_L39_004D4730(u8 *, s32, u8 *, u8 *, s32, u8 *, u8 *, u8 *, u8 *, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004CEA80(u8 *dst, u8 *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CEA80(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CEA80(u8 *out) {
    u8 key[32];
    u8 id[8];
    u8 info[16];
    u8 buf[16];
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004CEA80, 0, func_L39_004F7890);
    if (func_L39_004CFF30(info) == 1) {
        copy_004CEA80(id, info, 8);
        if (func_L39_004CE968(key) < 0) {
            ret = -1;
        } else if (func_L39_004D4730(out, 0x38, buf, key, 0x20, D_L39_00469F98, id,
                                     D_L39_00469FB8, D_L39_00469FD8, 2) < 0) {
            ret = -1;
        } else {
            ret = 0;
        }
    }
    randfill_004CEA80(key, 32);
    DNAS_END(func_L39_004CEA80, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CEA80 */

/* localdecomp:start func_L39_004CEC98 */
extern s32 func_L39_004D05D8(u8 *, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004CEC98(u8 *dst, u8 *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CEC98(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CEC98(u8 *out) {
    u8 buf[9];
    s32 ret;

    DNAS_BEGIN(func_L39_004CEC98, 0, func_L39_004F7890);
    if (func_L39_004D05D8(buf, 9, 0xC9C69) < 0) {
        ret = 0;
    } else {
        ret = *(s32 *)buf;
        copy_004CEC98(out, buf + 4, 5);
    }
    randfill_004CEC98(buf, 9);
    DNAS_END(func_L39_004CEC98, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CEC98 */

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

/* localdecomp:start func_L39_004CEFC0 */
extern s32 func_L39_004CFF30(u8 *);
extern s32 func_L39_004CEE68(u8 *);
extern s32 func_L39_004D4730(u8 *, s32, u8 *, u8 *, s32, u8 *, u8 *, u8 *, u8 *, s32);
extern s32 func_L39_004D0C78(void);
extern u8 D_L39_0046A008[];
extern u8 D_L39_00469FE0[];
extern u8 D_L39_0046A000[];

s32 func_L39_004CEFC0(u8 *a0) {
    u8 key[16];
    u8 iv[16];
    u8 id[16];
    u8 out[16];
    s32 ret = -1;
    u32 i;
    s32 j;

    DNAS_BEGIN(func_L39_004CEFC0, 0, func_L39_004F7890);
    if (func_L39_004CFF30(id) == 1) {
        u8 *s = id;
        u8 *d = iv;

        for (i = 0; i < 8; i++) {
            d[i] = s[i];
        }
        ret = -1;
        if (func_L39_004CEE68(key) >= 0) {
            if (func_L39_004D4730(a0, 0x20, out, key, 5, D_L39_0046A008, iv, D_L39_00469FE0,
                                  D_L39_0046A000, 2) >= 0) {
                ret = 0;
            }
        }
    }
    {
        u8 *p = key;

        for (j = 0; j < 5; j++) {
            p[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    DNAS_END(func_L39_004CEFC0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CEFC0 */

/* localdecomp:start func_L39_004CF1D8 */
extern s32 func_0012AA38(char *, s32);
extern s32 func_0012AE40(s32, s32, s32);
extern s32 func_0012B080(s32, void *, s32);
extern s32 func_0012ACC8(s32);
extern void *func_L39_004B7748(u32);
extern void func_L39_004B7A80(void *);
extern s32 func_L39_004CF720(s8 *);

static __inline__ void copy_004CF1D8(u8 *dst, s8 *src, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void wipe_004CF1D8(char *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = 0;
    }
}

s32 func_L39_004CF1D8(u8 *out) {
    char path[24];
    s8 *buf = 0;
    s32 fd = -1;
    s32 ret;
    s32 size;
    s8 *p;
    s32 i;

    DNAS_BEGIN(func_L39_004CF1D8, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = -8;
        goto out;
    }
    if (func_L39_004CDFE0((s32)path) < 0) {
        ret = -0x192;
        goto out;
    }
    fd = func_0012AA38(path, 1);
    if (fd < 0) {
        ret = -0x192;
        goto out;
    }
    size = func_0012AE40(fd, 0, 2);
    if (size < 0) {
        ret = -0x192;
        goto out;
    }
    buf = func_L39_004B7748(size);
    if (buf == 0) {
        ret = -0x192;
        goto out;
    }
    if (func_0012AE40(fd, 0, 0) < 0) {
        ret = -0x192;
        goto out;
    }
    if (func_0012B080(fd, buf, size) < 0) {
        ret = -0x192;
        goto out;
    }
    if (func_0012ACC8(fd) < 0) {
        ret = -0x192;
        goto out;
    }
    fd = -1;
    p = buf;
    i = 0;
    while (*p != '\n' && i < size) {
        p++;
        i++;
    }
    if (i == size) {
        ret = -0x192;
        goto out;
    }
    *p = 0;
    p = buf;
    i = 0;
    while (*p != ':' && i < size) {
        p++;
        i++;
    }
    if (i == size) {
        ret = -0x192;
        goto out;
    }
    p += 2;
    if ((u32)func_L39_004CF720(p) < 11) {
        ret = -0x192;
        goto out;
    }
    copy_004CF1D8(out, p, 4);
    copy_004CF1D8(out + 4, p + 5, 3);
    copy_004CF1D8(out + 7, p + 9, 2);
    func_L39_004B7A80(buf);
    buf = 0;
    ret = 9;
out:
    if (buf != 0) {
        func_L39_004B7A80(buf);
    }
    if (fd >= 0) {
        func_0012ACC8(fd);
    }
    wipe_004CF1D8(path, 24);
    DNAS_END(func_L39_004CF1D8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CF1D8 */

/* localdecomp:start func_L39_004CF508 */
extern s32 func_L39_004CFF30(u8 *);
extern s32 func_L39_004CF1D8(u8 *);
extern s32 func_L39_004D4730(u8 *, s32, u8 *, u8 *, s32, u8 *, u8 *, u8 *, u8 *, s32);
extern s32 func_L39_004D0C78(void);
extern u8 D_L39_0046A028[];
extern u8 D_L39_00469FE0[];
extern u8 D_L39_0046A000[];

s32 func_L39_004CF508(u8 *a0) {
    u8 key[16];
    u8 iv[16];
    u8 id[16];
    u8 out[16];
    s32 ret = -1;
    u32 i;
    s32 j;

    DNAS_BEGIN(func_L39_004CF508, 0, func_L39_004F7890);
    if (func_L39_004CFF30(id) == 1) {
        u8 *s = id;
        u8 *d = iv;

        for (i = 0; i < 8; i++) {
            d[i] = s[i];
        }
        ret = -1;
        if (func_L39_004CF1D8(key) >= 0) {
            if (func_L39_004D4730(a0, 0x28, out, key, 9, D_L39_0046A028, iv, D_L39_00469FE0,
                                  D_L39_0046A000, 2) >= 0) {
                ret = 0;
            }
        }
    }
    {
        u8 *p = key;

        for (j = 0; j < 5; j++) {
            p[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    DNAS_END(func_L39_004CF508, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CF508 */

/* localdecomp:start func_L39_004CF720 */
s32 func_L39_004CF720(s8 *s) {
    s8 *start = s;

    while (*s != 0) {
        s++;
    }
    return s - start;
}
/* localdecomp:end func_L39_004CF720 */

/* localdecomp:start func_L39_004CF758 */
s32 func_L39_004CF758(u8 *a, u8 *b, u32 n) {
    s32 ret;
    u32 i;

    DNAS_BEGIN(func_L39_004CF758, 0, func_L39_004F7890);
    for (i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            ret = -1;
            goto out;
        }
        if (a[i] > b[i]) {
            ret = 1;
            goto out;
        }
    }
    ret = 0;
out:
    DNAS_END(func_L39_004CF758, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CF758 */

/* localdecomp:start func_L39_004CF890 */
typedef struct {
    u8 ident[4];
    u16 class_data;
    u8 pad6[10];
    u16 type;
    u16 machine;
    u32 version;
    u32 entry;
    u32 phoff;
    u32 shoff;
    u32 flags;
    u16 ehsize;
    u16 phentsize;
    u16 phnum;
} S_004CF890_ehdr;

typedef struct {
    u32 type;
    u32 offset;
} S_004CF890_phdr;

s32 func_L39_004CF890(u8 *elf) {
    S_004CF890_ehdr *eh = (S_004CF890_ehdr *)elf;
    S_004CF890_phdr *ph;
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004CF890, 0, func_L39_004F7890);
    ph = (S_004CF890_phdr *)(elf + eh->phoff);
    if (eh->class_data == 0x101 && eh->machine == 8 && eh->phentsize == 0x20 && eh->phnum == 2
        && ph->type == 0x70000080 && (eh->type == 0xFF80 || eh->type == 2)) {
        ret = *(u16 *)(elf + ph->offset + 0x18) == 0x203 ? 0 : -1;
    } else {
        ret = -1;
    }
    DNAS_END(func_L39_004CF890, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CF890 */

/* localdecomp:start func_L39_004CFA00 */
extern s32 func_L39_004CF890(u8 *);
extern void func_00129490(s32);
extern s32 func_0012B8B8(void);
extern s32 func_0012B940(s32);
extern void func_001264E0(s32);
extern s32 func_00126620(s32 *, s32);
extern s32 func_00126600(s32);
extern s32 func_0012C2C0(s32, s32, s32);
extern s32 func_0012BAA8(s32);

s32 func_L39_004CFA00(u8 *image, s32 size) {
    s32 dma[4];
    s32 iop = 0;
    s32 ret = -1;
    s32 id;

    DNAS_BEGIN(func_L39_004CFA00, 0, func_L39_004F7890);
    func_00129490(0);
    if (func_0012B8B8() >= 0 && func_L39_004CF890(image) >= 0) {
        iop = func_0012B940(size);
        if (iop != 0) {
            dma[0] = (s32)image;
            dma[2] = size;
            dma[1] = iop;
            dma[3] = 0;
            func_001264E0(0);
            id = func_00126620(dma, 1);
            if (id != 0) {
                while ((id = func_00126600(id)) >= 0) {
                }
                ret = -1;
                if (func_0012C2C0(iop, 0, 0) >= 0) {
                    ret = func_0012BAA8(iop) < 0 ? -1 : 0;
                }
            }
        }
    }
    if (iop != 0) {
        func_0012BAA8(iop);
    }
    DNAS_END(func_L39_004CFA00, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CFA00 */

/* localdecomp:start func_L39_004CFBA8 */
extern s32 D_L39_00465848;
extern s32 D_L39_0046584C;
extern u8 D_L39_00465850[];
extern u8 D_L39_00469F20[][8];
extern u8 D_L39_00443B00[];
extern s32 func_L39_004CFE20(void);
extern s32 func_L39_004B7FF0(u32, u32);
extern void func_L39_004B7A80(void *);
extern s32 func_L39_004D1E58(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L39_004CFA00(u8 *, s32);
extern s32 func_L39_004D51F0(u8 *, u32, s32);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004CFBA8(void) {
    u8 *buf = 0;
    s32 ret = -1;
    u32 i;

    DNAS_BEGIN(func_L39_004CFBA8, 0, func_L39_004F7890);
    if (D_L39_00465848 != 0) {
        return 0;
    }
    if (func_L39_004CFE20() == 0) {
        buf = (u8 *)func_L39_004B7FF0(0x40, 0x4710);
        if (buf == 0) {
            ret = -1;
            goto cleanup;
        }
        if (func_L39_004D1E58((s32)D_L39_00465850, (s32)D_L39_00469F20[0], (s32)D_L39_00469F20[1],
                              (s32)D_L39_00469F20[2], (s32)(buf + 0x30), (s32)D_L39_00469F20[3], 0x8DA) < 0) {
            ret = -1;
            goto cleanup;
        }
        if (func_L39_004CFA00(buf + 0x40,
                              ((buf[0x30] << 24 | buf[0x31] << 16 | buf[0x32] << 8 | buf[0x33]) + 0x3F) & ~0x3F) < 0) {
            ret = -1;
            goto cleanup;
        }
    }
    if (D_L39_0046584C == 0) {
        if (func_L39_004D51F0(D_L39_00443B00, 0x80000F03, 0) < 0) {
            ret = -1;
            goto cleanup;
        }
        D_L39_0046584C = 1;
    }
    ret = 0;
    D_L39_00465848 = 1;
cleanup:
    if (buf != 0) {
        for (i = 0; i < 0x4710; i++) {
            buf[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
        func_L39_004B7A80(buf);
    }
    DNAS_END(func_L39_004CFBA8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CFBA8 */

/* localdecomp:start func_L39_004CFE20 */
extern s32 func_0012C220(char *);

s32 func_L39_004CFE20(void) {
    s32 ret;

    DNAS_BEGIN(func_L39_004CFE20, 0, func_L39_004F7890);
    ret = func_0012C220(DNAS_STRING("Sys1_driver04")) >= 0;
    DNAS_END(func_L39_004CFE20, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CFE20 */

/* localdecomp:start func_L39_004CFF30 */
extern s32 D_L39_00465848;
extern s32 func_L39_004D05D8(u8 *, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void copy_004CFF30(u8 *dst, u8 *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

static __inline__ void randfill_004CFF30(u8 *dst, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004CFF30(u8 *out) {
    u8 buf[12];
    s32 ret;

    DNAS_BEGIN(func_L39_004CFF30, 0, func_L39_004F7890);
    if (D_L39_00465848 != 1) {
        ret = 0;
        out[5] = 1;
        out[3] = 1;
        out[2] = 1;
        out[1] = 1;
    } else if (func_L39_004D05D8(buf, 12, 0x22799) < 0) {
        ret = 0;
        out[5] = 1;
        out[3] = 1;
        out[2] = 1;
        out[1] = 1;
    } else {
        ret = *(s32 *)buf;
        copy_004CFF30(out, buf + 4, 8);
    }
    randfill_004CFF30(buf, 12);
    DNAS_END(func_L39_004CFF30, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CFF30 */

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

/* localdecomp:start func_L39_004D05D8 */
extern u8 D_L39_00443880[];
extern u8 D_L39_00443890[];
extern u8 D_L39_00443B00[];
extern u8 D_L39_00469F50[];
extern s32 func_L39_004D5288(void *, s32, s32, s32, s32, void *, s32, s32, s32);
extern s32 func_L39_004CF758(u8 *, u8 *, u32);
extern void func_L39_004D0228(u8 *, u8 *, u8 *);
extern void func_L39_004D03B8(u8 *, u8 *, u32);

s32 func_L39_004D05D8(u8 *dst, s32 size, s32 fno) {
    u8 len = size;
    u8 hash[20];
    u8 key[16];
    u8 out[20];
    s32 ret;
    s32 i;
    s32 j;
    u32 k;
    u8 *q;

    DNAS_BEGIN(func_L39_004D05D8, 0, func_L39_004F7890);
    func_L39_004D0138(key);
    {
        u8 *b = D_L39_00443880;

        for (i = 0; i < 640; i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *d = D_L39_00443880;
        u8 *s = key;

        for (j = 0; j < 16; j++) {
            d[j] = s[j];
        }
    }
    {
        u8 *d = D_L39_00443890;
        u8 *s = D_L39_00469F50;

        for (k = 0; k < 8; k++) {
            d[k] = s[k];
        }
    }
    for (k = 0; k < 8; k++) {
        *(D_L39_00443890 + k) ^= key[k];
    }
    if (func_L39_004D5288(D_L39_00443B00, fno, 0, (s32)D_L39_00443880, 640, D_L39_00443880, 640, 0, 0) < 0) {
        ret = -1;
    } else {
        ret = -1;
        func_L39_004D0228(key, D_L39_00443880, out);
        func_L39_004D03B8(D_L39_00443880 + 16, out, 0x270);
        func_L39_004D2468(D_L39_00443880, len + 16, hash);
        q = D_L39_00443880 + 16;
        if (func_L39_004CF758(hash, q + len, 20) == 0) {
            for (j = 0; j < len; j++) {
                dst[j] = q[j];
            }
            ret = 0;
        }
    }
    func_L39_004D5288(D_L39_00443B00, 0x75C19, 0, (s32)D_L39_00443880, 640, D_L39_00443880, 640, 0, 0);
    {
        u8 *b = D_L39_00443880;

        for (i = 0; i < 640; i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *b = hash;

        for (i = 0; i < sizeof(hash); i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *b = key;

        for (i = 0; i < sizeof(key); i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *b = out;

        for (i = 0; i < sizeof(out); i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    DNAS_END(func_L39_004D05D8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D05D8 */

/* localdecomp:start func_L39_004D0B08 */
extern s32 func_0012C220(char *);
extern s32 func_0012BF88(s32, s32, s32, void *);
extern s32 func_0012C190(s32);
extern s32 D_L39_0046584C;

s32 func_L39_004D0B08(void) {
    s32 ret = -1;
    s32 fd;
    u8 buf[16];

    DNAS_BEGIN(func_L39_004D0B08, 0, func_L39_004F7890);
    fd = func_0012C220(DNAS_STRING("Sys1_driver04"));
    if (fd >= 0 && func_0012BF88(fd, 0, 0, buf) >= 0 && func_0012C190(fd) >= 0) {
        ret = 0;
        D_L39_0046584C = 0;
    }
    DNAS_END(func_L39_004D0B08, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D0B08 */
