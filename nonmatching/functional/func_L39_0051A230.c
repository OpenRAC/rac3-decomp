/* functional: high. Opens/queries an entry through the file layer: gets the context (func_L39_005190E8), runs func_001486F8 on its embedded record with command 0x41, maps the error to a small status code (1..4) stored at ctx+0x10 or translates it with func_L39_00519468, and on success fills the static result record D_00453EF8 (words: 0, &D_0046F568, 2, 4, &D_0046F570 with D_0046F570 = D_00453DF0) and returns a pointer to it; returns 0 on any failure. */
typedef struct { s32 f0; void *f4; s32 f8; s32 fC; void *f10; } R_0051A230;
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x40]; s32 f54; } C_0051A230;
extern R_0051A230 D_L39_00453EF8;
extern u8 D_L39_00453DF0[];
extern u8 D_L39_0046F568[];
extern void *D_L39_0046F570;
extern C_0051A230 *func_L39_005190E8(s32);
extern void func_L39_005190C8(void);
extern s32 func_L39_00519058(void);
extern s32 func_L39_005192A8(void *, s32);
extern s32 func_L39_00519468(s32);
extern void func_L39_00519408(void *, void *);
extern s32 func_001486F8(void *, s32, s32, void *, s32, s32, s32);

R_0051A230 *func_L39_0051A230(s32 arg) {
    u8 buf[16];
    C_0051A230 *ctx;
    R_0051A230 *res = &D_L39_00453EF8;
    s32 r;
    s32 code;

    ctx = func_L39_005190E8(0);
    if (ctx == 0) {
        return 0;
    }
    func_L39_005190C8();
    ctx->f10 = 0;
    r = func_001486F8((u8 *)ctx + 0x14, ctx->f54, 0x41, buf, arg, 0, 0);
    if (func_L39_00519058() < 0) {
        ctx->f10 = -1;
        func_L39_005192A8(ctx, -1);
        return 0;
    }
    if (r < 0) {
        if (r == -0x1F4 || r == -0x203) {
            code = 1;
        } else if (r == -0x204) {
            code = 2;
        } else if (r == -0x205) {
            code = 3;
        } else if (r == -0x206) {
            code = 4;
        } else {
            ctx->f10 = -1;
            func_L39_005192A8(ctx, func_L39_00519468(r));
            return 0;
        }
        ctx->f10 = code;
        func_L39_005192A8(ctx, 0);
        return 0;
    }
    res->f0 = 0;
    res->f4 = D_L39_0046F568;
    res->f8 = 2;
    res->fC = 4;
    func_L39_00519408(D_L39_00453DF0, buf);
    ctx->f10 = 0;
    D_L39_0046F570 = D_L39_00453DF0;
    res->f10 = &D_L39_0046F570;
    func_L39_005192A8(ctx, 0);
    return res;
}
