#include "common.h"

/* localdecomp:start func_L39_00501140 */
extern s32 func_L39_00501200(s32, s32, s32);
extern s32 func_L39_005061A8(void);
extern s32 func_L39_005061C8(void);
extern s32 func_11C090(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_00501140(s32 arg0, s32 arg1, s32 arg2, s64 arg3) {
    s32 r = 0;

    if (arg1 == 1) {
        if (arg3 == 3) {
            r = func_L39_00501200(arg0, func_L39_005061A8(), 1);
            if (r == 0) {
                func_L39_004BC6C8(0xB, 0xD6, 0x9D, 0, 0);
            } else {
                r = func_L39_00501200(arg0, func_11C090(func_L39_005061C8()), 1);
            }
        } else {
            r = func_L39_00501200(arg0, arg2, arg3);
        }
    }
    return r != 0;
}
/* localdecomp:end func_L39_00501140 */

/* localdecomp:start func_L39_00501200 */
typedef struct {
    u8 pad[0x10];
    s32 f10;
} S_00501200;
extern s32 func_L39_005000D0(void);
extern void *func_L39_004DA968(s32);
extern s32 func_L39_004DAE48(void *, s32, s32, s32);
extern s32 func_L39_00505FC8(s32, void *);
extern void func_L39_004F4818(void *);
extern void *func_L39_004E15D8(void *, s32, s32);
extern u64 func_L39_004DE120(void);
extern void func_L39_004DE0C8(void);
extern void *func_L39_004F2118(void *, s32);
extern void func_L39_004DAAB0(void *);
s32 func_L39_00501200(s32 arg0, s32 arg1, s32 arg2) {
    S_00501200 *ctx = (S_00501200 *)arg0;
    s32 ret = 0;
    void *in;
    s32 count = 0;
    void *x = 0;

    if (arg1 == 0)
        return 1;
    in = func_L39_004DA968(func_L39_005000D0());
    if (in == 0 || func_L39_004DAE48(in, 0x6C, 3, arg1) <= 0) {
        func_L39_004BC6C8(0xB, 0xE0, 0x802, 0, 0);
        goto end;
    }
    if (arg2 == 1) {
        for (;;) {
            x = func_L39_004E15D8(in, 0, 0);
            if (x == 0) {
                if ((s32)(func_L39_004DE120() & 0xFFF) == 0x6C && count > 0) {
                    func_L39_004DE0C8();
                    break;
                } else {
                    func_L39_004BC6C8(0xB, 0xE0, 0x809, 0, 0);
                    goto end;
                }
            }
            if (func_L39_00505FC8(ctx->f10, x) == 0)
                goto end;
            count++;
            func_L39_004F4818(x);
        }
        ret = count;
    } else if (arg2 == 2) {
        x = func_L39_004F2118(in, 0);
        if (x == 0) {
            func_L39_004BC6C8(0xB, 0xE0, 0x80D, 0, 0);
            goto end;
        }
        ret = func_L39_00505FC8(ctx->f10, x);
    } else {
        func_L39_004BC6C8(0xB, 0xE0, 0x9A, 0, 0);
        goto end;
    }
end:
    if (x != 0)
        func_L39_004F4818(x);
    if (in != 0)
        func_L39_004DAAB0(in);
    return ret;
}
/* localdecomp:end func_L39_00501200 */
