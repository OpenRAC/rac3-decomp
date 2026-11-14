#include "common.h"

/* localdecomp:start func_L39_00508F08 */
typedef struct {
    s32 a;
    s32 b;
    s32 err;
} Out_00508F08;

typedef struct {
    s32 pad;
    s32 arg0;
    s32 arg1;
    Out_00508F08 *out;
} Req_00508F08;

extern u8 D_L39_0046F0B8[];
extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_0050F538(void *, s32, s32, s32, s32, void *);
extern s32 func_L39_0050D890(s32);

s32 func_L39_00508F08(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    Out_00508F08 out;
    Req_00508F08 req;
    s32 ret;

    func_L39_004F74E8(&req, 0, sizeof(req));
    req.arg0 = arg0;
    req.arg1 = arg1;
    req.out = &out;
    ret = func_L39_0050D890(func_L39_0050F538(D_L39_0046F0B8, 0, arg3[0], arg3[1], 0, &req));
    if (ret != 0) {
        return ret;
    }
    if (out.err != 0) {
        return 0x20C;
    }
    arg2[0] = out.a;
    arg2[1] = out.b;
    return 0;
}
/* localdecomp:end func_L39_00508F08 */
