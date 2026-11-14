#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005103A0);

/* localdecomp:start func_L39_005108A0 */
extern void func_L39_004F7510(void *, void *, s32);

s32 func_L39_005108A0(s8 *out, s32 *outLen, u32 cap, s32 tag, u8 *tagBytes, void *data, u32 len) {
    s32 n;
    s32 l;
    s32 hi;

    hi = tag & 0x1F;
    n = 0;
    if (hi == 0x1F) {
        while (tagBytes[n] & 0x80) {
            n++;
        }
        n++;
    }
    if (len < 0x80) {
        l = 1;
    } else if (len < 0x100) {
        l = 2;
    } else if (len <= 0xFFFF) {
        l = 3;
    } else if (len <= 0xFFFFFF) {
        l = 4;
    } else {
        l = 5;
    }
    *outLen = n + l + 1;
    if (data != 0) {
        *outLen += len;
    }
    if (out == 0) {
        return 0;
    }
    if (cap < *outLen) {
        return 0x802;
    }
    *out++ = tag;
    if (hi == 0x1F) {
        func_L39_004F7510(out, tagBytes, n);
        out += n;
    }
    if (len < 0x80) {
        *out++ = len;
    } else if (len < 0x100) {
        *out++ = 0x81;
        *out++ = len;
    } else if (len <= 0xFFFF) {
        *out++ = 0x82;
        *out++ = len >> 8;
        *out++ = len;
    } else if (len <= 0xFFFFFF) {
        *out++ = 0x83;
        *out++ = len >> 16;
        *out++ = len >> 8;
        *out++ = len;
    } else {
        *out++ = 0x84;
        *out++ = len >> 24;
        *out++ = len >> 16;
        *out++ = len >> 8;
        *out++ = len;
    }
    if (data != 0) {
        func_L39_004F7510(out, data, len);
    }
    return 0;
}
/* localdecomp:end func_L39_005108A0 */

/* localdecomp:start func_L39_00510A78 */
typedef struct { u32 flags; s32 pad[4]; } S_00510A78_Ent;
typedef struct S_00510A78_Obj S_00510A78_Obj;
typedef struct {
    s32 (*fn0)(S_00510A78_Obj *, s8 *, s32);
} S_00510A78_Vt;
struct S_00510A78_Obj {
    S_00510A78_Vt *vt;
    s32 pad[6];
    S_00510A78_Obj *unk1C;
};
typedef struct { u32 n; s32 pad[3]; } S_00510A78_Res;

extern u8 D_L39_0046F408[];
extern void func_L39_0050CE50(S_00510A78_Res *, S_00510A78_Ent *);
extern void func_L39_0050CC90(S_00510A78_Obj *, s32, s32, u8 *, s32);
void func_L39_00510A78(S_00510A78_Obj *arg0, s32 arg1, S_00510A78_Ent *arg2) {
    s8 buf[2];
    S_00510A78_Res res;
    u32 i;

    func_L39_0050CE50(&res, arg2);
    for (i = 0; i < res.n; i++) {
        if (arg2[i].flags & 0x4000) {
            break;
        }
    }
    if (i < res.n) {
        buf[0] = arg1;
        buf[1] = 0x80;
        arg0->unk1C->vt->fn0(arg0->unk1C, buf, 2);
    } else {
        func_L39_0050CC90(arg0, arg1, 0, D_L39_0046F408, 0);
    }
}
/* localdecomp:end func_L39_00510A78 */
