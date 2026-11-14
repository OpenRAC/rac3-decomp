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

/* localdecomp:start func_L39_00508C28 */
typedef struct S_00508C28 { s32 a; u8 *b; u8 *c; } S_00508C28;
typedef struct S_00508C28_Buf { u8 *p; s32 n; } S_00508C28_Buf;
extern u8 D_L39_0046F0B0[];
extern u8 D_L39_0046F038[];
extern u8 D_L39_0046F0A8[];
extern u8 D_L39_0046F3F8[];
extern s32 func_L39_005084A8(void *, s32 **, char *);
extern void *func_L39_0050DA38(void *, s32, S_00508C28 *, void **);
extern s32 func_L39_00508FD0(void *, void *, void *, void **);
extern s32 func_L39_004F6130(void *, void *, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_00508C28(void **arg0, void *arg1) {
    void *h[2];
    S_00508C28 d;
    S_00508C28_Buf buf;
    s32 r;
    void *p;

    r = func_L39_005084A8(arg1, (s32 **)&buf.p, (char *)D_L39_0046F0B0);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F6060(arg1, arg0, 8);
    if (r != 0) {
        return r;
    }
    do {
        p = *arg0;
        h[0] = 0;
        func_L39_004F74E8(&d, 0, sizeof(d));
        d.b = buf.p;
        d.c = buf.p + 8;
        r = func_L39_0050D890((s32)func_L39_0050DA38(D_L39_0046F038, 0, &d, h));
        if (r != 0) break;
        r = func_L39_00508FD0(p, D_L39_0046F0A8, D_L39_0046F3F8, h);
        if (r != 0) break;
        r = func_L39_004F6130(arg1, p, ((s32 *)p)[1]);
    } while (0);
    func_L39_004F7620(h[0]);
    return r;
}
/* localdecomp:end func_L39_00508C28 */

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

/* localdecomp:start func_L39_00508DC0 */
extern char D_L39_0046F468[];
extern s32 func_L39_005084A8(void *, s32 **, char *);
extern s32 func_L39_004F6060(void *, void *, s32);
s32 func_L39_00508DC0(s32 **arg0, void *arg1) {
    s32 *src;
    s32 *dst;
    s32 r;
    r = func_L39_005084A8(arg1, &src, D_L39_0046F468);
    if (r != 0) return r;
    r = func_L39_004F6060(arg1, arg0, 0x10);
    if (r != 0) return r;
    dst = *arg0;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    return r;
}
/* localdecomp:end func_L39_00508DC0 */
