#include "common.h"

/* localdecomp:start func_L39_00516238 */
extern void *func_L39_004BEED8(s32);
extern void *func_L39_004BEF00(void *, s32, s32);
extern void func_L39_004BEF28(void *);
extern void func_11D534(void *, s32, s32);

typedef struct S_00516238 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 f18;
    /* 0x1C */ long *f1C;
    /* 0x20 */ s32 pad20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
    /* 0x2C */ u8 pad2C[0x10];
    /* 0x3C */ void *f3C;
    /* 0x40 */ s32 *f40;
    /* 0x44 */ u8 pad44[0x8C];
    /* 0xD0 */ s32 fD0;
} S_00516238;

s32 func_L39_00516238(void *arg0, void *arg1) {
    S_00516238 *ctx = arg0;
    long *text = arg1;
    s32 maxLen = 0;
    s32 maxVal = 0;
    s32 i = 0;
    s32 cap = ctx->f28;
    s32 *buf;
    unsigned long ent;
    s32 idx;
    s32 val;
    s32 j;

    if (cap == 0) {
        buf = func_L39_004BEED8(0x10);
        cap = 4;
    } else {
        buf = ctx->f40;
        ctx->f40 = 0;
    }
    func_11D534(buf, 0xFF, cap * 4);
    ctx->fD0 = -1;
    ctx->f18 = 0;
    ctx->f1C = text;
    ent = text[i++];
    ctx->f18++;
    while (ent != 0) {
        idx = -1;
        val = -1;
        switch ((u32)(u8)ent) {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            val = (ent >> 16) & 0xFFFF;
            break;
        case 0x20:
            idx = (ent >> 16) & 0xFFFF;
            break;
        case 0x92:
            i++;
            break;
        }
        if (idx >= 0) {
            if (cap < idx + 1) {
                buf = func_L39_004BEF00(buf, (idx + 5) * 4, cap * 4);
                cap = idx + 4;
                ctx->f28 = cap;
                for (j = maxLen; j < cap; j++) {
                    buf[j] = 0xFFFF;
                }
            }
            buf[idx] = i;
            if (maxLen < idx + 1) {
                maxLen = idx + 1;
            }
        }
        if (maxVal < val) {
            maxVal = val;
        }
        ent = text[i++];
        ctx->f18++;
    }
    ctx->f28 = maxLen;
    if (ctx->f40 != 0) {
        func_L39_004BEF28(ctx->f40);
    }
    ctx->f40 = buf;
    maxVal++;
    ctx->f24 = maxVal;
    if (maxVal > 0) {
        if (ctx->f3C != 0) {
            func_L39_004BEF28(ctx->f3C);
        }
        ctx->f3C = func_L39_004BEED8(maxVal * 4);
        func_11D534(ctx->f3C, 0, maxVal * 4);
    } else {
        ctx->f3C = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_00516238 */
