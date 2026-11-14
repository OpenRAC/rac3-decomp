#include "common.h"

/* localdecomp:start func_L39_00508B48 */
typedef struct {
    s32 pad;
    void *out;
    void *extra;
} S_00508B48_Req;

extern u8 D_L39_0046F0A8[];
extern u8 D_L39_0046F0A0[];
extern u8 D_L39_0046F038[];
extern s32 func_L39_00508F08(void *, void *, s32 *, s32 *);
extern s32 func_L39_00509078(char *, void *);
extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_0050F538(void *, s32, s32, s32, s32, void *);
extern s32 func_L39_0050D890(s32);
extern s32 func_L39_00508D40(void *, void *);

s32 func_L39_00508B48(void *arg0, s32 *arg1) {
    s32 out[3];
    s32 key[2];
    char name[16];
    s32 info[4];
    S_00508B48_Req req;
    s32 ret;

    ret = func_L39_00508F08(name, info, key, arg1);
    if (ret != 0) {
        return ret;
    }
    if (!func_L39_00509078(name, D_L39_0046F0A8) && !func_L39_00509078(name, D_L39_0046F0A0)) {
        return 0x21E;
    }
    func_L39_004F74E8(&req, 0, sizeof(req));
    req.out = &out[0];
    req.extra = &out[2];
    ret = func_L39_0050D890(func_L39_0050F538(D_L39_0046F038, 0, key[0], key[1], 0, &req));
    if (ret != 0) {
        return ret;
    }
    return func_L39_00508D40(arg0, out);
}
/* localdecomp:end func_L39_00508B48 */

INCLUDE_ASM("asm/levels", func_L39_00508C28);

LINKER_REMNANT("asm/levels", func_L39_00508D38);

/* localdecomp:start func_L39_00508D40 */
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_005155E8(s32, void *, void *, void *, s32, void *);
extern s32 func_L39_004F5EA0(void *, void *, s32);
extern u8 D_L39_0046F0B0[];

s32 func_L39_00508D40(void *a0, void *a1) {
    s32 s[4];
    void *t[2];
    s32 buf[4];
    s32 r;
    r = func_L39_004F6060(a0, buf, 16);
    if (r == 0) {
        t[0] = &s[0];
        t[1] = &s[2];
        r = func_L39_005155E8(buf[0], a1, s, t, 2, a0);
        if (r == 0) {
            r = func_L39_004F5EA0(a0, D_L39_0046F0B0, buf[0]);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00508D40 */

INCLUDE_ASM("asm/levels", func_L39_00508DC0);
