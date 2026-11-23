#include "common.h"
/* localdecomp:start func_L39_0051A230 */
typedef struct C_0051A098 { char p0[0x14]; char f14[0x40]; s32 f54; } C_0051A098;
typedef struct { void *f0; void *f4; s32 f8; s32 fC; void *f10; } R_0051A230;
typedef struct { u8 pad0[0x10]; s32 f10; } C_0051A230;
extern R_0051A230 D_L39_00453EF8;
extern u8 D_L39_00453DF0[];
extern u8 D_L39_0046F568[];
extern void *D_L39_0046F570[];
extern C_0051A098 *func_L39_005190E8(s32);
extern s32 func_L39_005192A8(C_0051A098 *, s32);
extern void func_L39_005190C8(void);
extern s32 func_L39_00519058(void);
extern s32 func_L39_00519468(s32);
extern void func_L39_00519408(void *, void *);
extern s32 func_001486F8(void *, s32, s32, void *, s32, s32, s32);

R_0051A230 *func_L39_0051A230(s32 arg) {
    u8 buf[16];
    C_0051A098 *ctx;
    R_0051A230 *res = &D_L39_00453EF8;
    s32 r;
    s32 code;

    ctx = func_L39_005190E8(0);
    if (ctx == 0) {
        return 0;
    }
    ((C_0051A230 *)ctx)->f10 = 0;
    func_L39_005190C8();
    r = func_001486F8(ctx->f14, ctx->f54, 0x41, buf, arg, 0, 0);
    if (func_L39_00519058() < 0) {
        ((C_0051A230 *)ctx)->f10 = -1;
        func_L39_005192A8(ctx, -1);
        goto fail;
    }
    if (r < 0) {
        if (r == -0x1F4 || r == -0x203) {
            ((C_0051A230 *)ctx)->f10 = 1;
            func_L39_005192A8(ctx, 0);
            goto fail;
        } else if (r == -0x204) {
            ((C_0051A230 *)ctx)->f10 = 2;
            func_L39_005192A8(ctx, 0);
            goto fail;
        } else if (r == -0x205) {
            ((C_0051A230 *)ctx)->f10 = 3;
            func_L39_005192A8(ctx, 0);
            goto fail;
        } else if (r == -0x206) {
            ((C_0051A230 *)ctx)->f10 = 4;
            func_L39_005192A8(ctx, 0);
            goto fail;
        }
def:
        ((C_0051A230 *)ctx)->f10 = -1;
        func_L39_005192A8(ctx, func_L39_00519468(r));
        goto fail;
    }
    res->f0 = 0;
    res->f4 = D_L39_0046F568;
    res->f8 = 2;
    res->fC = 4;
    func_L39_00519408(D_L39_00453DF0, buf);
    ((C_0051A230 *)ctx)->f10 = 0;
    D_L39_0046F570[0] = D_L39_00453DF0;
    res->f10 = D_L39_0046F570;
    func_L39_005192A8(ctx, 0);
    return res;
fail:
    return 0;
}
/* localdecomp:end func_L39_0051A230 */
