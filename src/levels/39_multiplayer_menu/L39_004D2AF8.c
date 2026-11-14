#include "common.h"

/* localdecomp:start func_L39_004D2AF8 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004D2828(s32, u8 *, u8 *, u8 *);
extern s32 func_L39_004D3408(u8 *, u8 *);
extern s32 func_L39_004D1FB8(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L39_004D3678(u8 *, u8 *, u8 *, u32 *);
extern s32 func_L39_004F88C8(u8 *, s32, u8 *, u32, u8 *, s32, u32 *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D2AF8(u8 *a0, u8 *a1, u8 *a2, u8 *out, u8 *out2) {
    u8 iv[16];
    u8 msg[128];
    u8 data[1024];
    u8 key[32];
    u8 key2[32];
    u32 len;
    u32 len2;
    s32 ret = -1;
    u32 i;
    u32 j;
    u32 k;
    u8 *enc;
    u8 *kp;

    DNAS_BEGIN(func_L39_004D2AF8, 0, func_L39_004F7890);
    enc = a2 + 0x20;
    kp = a2 + 0xA0;
    if (func_L39_004D2828(0x10000, a0, a2, iv) < 0) {
        ret = -1;
        goto wipe;
    }
    if (func_L39_004D3408(a1, key) < 0) {
        ret = -1;
        goto wipe;
    }
    if (func_L39_004D1FB8((s32)kp, (s32)key, (s32)(key + 8), (s32)(key + 16), (s32)key2, (s32)(key + 24), 4) < 0) {
        ret = -1;
        goto wipe;
    }
    if (func_L39_004D3678(a0, key2, data, &len) < 0) {
        ret = -1;
        goto wipe;
    }
    if (func_L39_004F88C8(enc, 0x80, data, len, msg, 0x80, &len2) < 0) {
        ret = -1;
        goto wipe;
    }
    for (k = 0; k < 0x90; k++) {
        out[k] = 0;
    }
    {
        u8 *s = iv;
        for (j = 0; j < 16; j++) {
            out[j] = s[j];
        }
    }
    {
        u8 *d = out + 16;
        u8 *s = msg;
        for (j = 0; j < len2; j++) {
            d[j] = s[j];
        }
    }
    {
        u8 *s = iv;
        for (j = 0; j < 16; j++) {
            out2[j] = s[j];
        }
    }
    ret = 0;
wipe:
    {
        u8 *q = iv;
        for (i = 0; i < 16; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = msg;
        for (i = 0; i < 128; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = data;
        for (i = 0; i < 1024; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = key;
        for (i = 0; i < 32; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = key2;
        for (i = 0; i < 32; i++) {
            q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    DNAS_END(func_L39_004D2AF8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D2AF8 */

INCLUDE_ASM("asm/levels", func_L39_004D3010);

/* localdecomp:start func_L39_004D3160 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern void func_L39_004D2468(u8 *, s32, u8 *);

s32 func_L39_004D3160(s32 a0, u8 *a1, s32 a2, u32 len, u32 off, u8 *out) {
    u8 b0[0x14];
    u8 b1[0x14];
    u32 i;
    u32 o;
    s32 n = 3;
    s32 q;

    DNAS_BEGIN(func_L39_004D3160, 0, func_L39_004F7890);
    {
        u8 *d = b0;
        u32 j;
        for (j = 0; j < 0x14; j++) {
            d[j] = 0;
        }
    }
    {
        u8 *d = b1;
        u32 j;
        for (j = 0; j < 0x14; j++) {
            d[j] = 0;
        }
    }
    q = a2 / n;
    o = off & 0xFF;
    func_L39_004D2468(a1 + o, len & 0xFF, b1);
    o = (off >> 8) & 0xFF;
    func_L39_004D2468(a1 + o, (len >> 8) & 0xFF, b1);
    for (i = 0; i < 0x14; i++) {
        b0[i] ^= b1[i];
    }
    o = (off >> 16) & 0xFF;
    func_L39_004D2468(a1 + o, (len >> 16) & 0xFF, b1);
    for (i = 0; i < 0x14; i++) {
        b0[i] ^= b1[i];
    }
    o = off >> 24;
    func_L39_004D2468(a1 + o, len >> 24, b1);
    for (i = 0; i < 0x14; i++) {
        b0[i] ^= b1[i];
    }
    for (i = 0; i < 8; i++) {
        out[i] = b0[i] ^ b0[i + 8];
    }
    for (i = 0; i < 4; i++) {
        out[i] ^= b0[i + 0x10];
    }
    DNAS_END(func_L39_004D3160, 0, func_L39_004F7890);
    return 0;
}
/* localdecomp:end func_L39_004D3160 */

/* localdecomp:start func_L39_004D3408 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern void func_L39_004D2468(u8 *, s32, u8 *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D3408(u8 *a0, u8 *a1) {
    u8 b0[0x14];
    u8 b1[0x14];
    u8 *q;

    DNAS_BEGIN(func_L39_004D3408, 0, func_L39_004F7890);
    func_L39_004D2468(a0, 0x100, b0);
    q = b1;
    func_L39_004D2468(a0 + 0x14, 0xEC, q);
    {
        s32 i;
        for (i = 0; i < 0x14; i++) {
            a1[i] = q[i];
        }
    }
    {
        u8 *d = a1 + 0x14;
        u8 *p = b0;
        s32 i;
        for (i = 0; i < 0xC; i++) {
            d[i] = p[i];
        }
    }
    {
        u8 *d = b0;
        s32 i;
        for (i = 0; i < 0x14; i++) {
            d[i] = (u32)((f32)func_L39_004D0C78() / 2147483647.0f * 256.0f);
        }
    }
    {
        u8 *d = q;
        s32 i;
        for (i = 0; i < 0x14; i++) {
            d[i] = (u32)((f32)func_L39_004D0C78() / 2147483647.0f * 256.0f);
        }
    }
    DNAS_END(func_L39_004D3408, 0, func_L39_004F7890);
    return 0;
}
/* localdecomp:end func_L39_004D3408 */

INCLUDE_ASM("asm/levels", func_L39_004D3678);

LINKER_REMNANT("asm/levels", func_L39_004D3A18);

/* localdecomp:start func_L39_004D3A20 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);

s32 func_L39_004D3A20(u8 *a, u8 *b, u32 n) {
    s32 ret;
    u32 i;

    DNAS_BEGIN(func_L39_004D3A20, 0, func_L39_004F7890);
    for (i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            ret = -1;
            goto end;
        }
        if (a[i] > b[i]) {
            ret = 1;
            goto end;
        }
    }
    ret = 0;
end:
    DNAS_END(func_L39_004D3A20, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D3A20 */

INCLUDE_ASM("asm/levels", func_L39_004D3B58);

INCLUDE_ASM("asm/levels", func_L39_004D3E90);

/* localdecomp:start func_L39_004D3FA0 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);

s32 func_L39_004D3FA0(u8 *a0, u8 *out) {
    s32 ret = -1;
    u8 v;

    DNAS_BEGIN(func_L39_004D3FA0, 0, func_L39_004F7890);
    v = a0[0xFCA0] & 3;
    *out = v;
    if (v < 2) {
        ret = 0;
    }
    DNAS_END(func_L39_004D3FA0, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D3FA0 */

INCLUDE_ASM("asm/levels", func_L39_004D40A8);

LINKER_REMNANT("asm/levels", func_L39_004D4440);
