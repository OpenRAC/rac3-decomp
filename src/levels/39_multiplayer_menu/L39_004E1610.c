#include "common.h"

/* declared by functions of L39_004E15D8.c, which this file was cut from */
extern s32 func_L39_004E1610(char *, char *, s32, s32, s32);

/* localdecomp:start func_L39_004E1610 */
extern s32 func_1205B0(char *, char *);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004E1DC8(s32, char **, char **, char **, s64 *);
extern void *func_L39_004DE550(void);
extern s32 func_L39_004E1A78(char *, void *);
extern s32 func_L39_004E18B8(void *, char *, s64 *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004DE828(void *);
extern char D_L39_004772A0[];
extern char D_L39_004772B0[];
extern char D_L39_004772C0[];
extern char D_L39_004772D0[];
extern char D_L39_004772E8[];
extern char D_L39_004772F8[];
extern char D_L39_00477310[];

s32 func_L39_004E1610(char *cb, char *name, s32 a2, s32 a3, s32 a4) {
    char *s0 = 0;
    char *s1 = 0;
    s32 arg = 0;
    char *s2 = 0;
    s64 len;
    void *ctx;
    s32 ret = 0;

    for (;;) {
        if (!func_L39_004E1DC8(a2, &s0, &s1, &s2, &len)) {
            return 0;
        }
        if (!func_1205B0(s0, name)
            || (!func_1205B0(s0, D_L39_004772A0) && !func_1205B0(name, D_L39_004772B0))
            || (!func_1205B0(s0, D_L39_004772C0) && !func_1205B0(name, D_L39_004772B0))
            || (!func_1205B0(s0, D_L39_004772D0) && !func_1205B0(name, D_L39_004772E8))
            || (!func_1205B0(s0, D_L39_004772F8) && !func_1205B0(name, D_L39_00477310))) {
            break;
        }
        func_L39_004BEF28(s0);
        func_L39_004BEF28(s1);
        func_L39_004BEF28(s2);
    }
    ctx = func_L39_004DE550();
    if (ctx && func_L39_004E1A78(s1, ctx) && func_L39_004E18B8(ctx, s2, &len, a4)) {
        arg = (s32)s2;
        if (!func_1205B0(name, D_L39_004772B0)) {
            if (!func_1205B0(s0, D_L39_004772A0)) {
                ret = ((s32 (*)(s32, s32, s32 *, s64))cb)(6, a3, &arg, len);
            } else if (!func_1205B0(s0, D_L39_004772C0)) {
                ret = ((s32 (*)(s32, s32, s32 *, s64))cb)(0x74, a3, &arg, len);
            }
        } else {
            ret = ((s32 (*)(s32, s32 *, s64))cb)(a3, &arg, len);
        }
        if (!ret) {
            func_L39_004BC6C8(9, 0x67, 0x80D, 0, 0);
        }
    }
    func_L39_004BEF28(s0);
    func_L39_004BEF28(s1);
    func_L39_004BEF28(s2);
    if (ctx) {
        func_L39_004DE828(ctx);
    }
    return ret;
}
/* localdecomp:end func_L39_004E1610 */
