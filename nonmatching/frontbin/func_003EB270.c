/* US draft of func_003EB270 (rac3-uya-decomp func_003E5D08, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003EB270 */
typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D9790_func_003EB270;
extern V16_func_003E5D08 D_001D96C0_func_003EB270;
s32 func_003EB270(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_func_003E5D08 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9790_func_003EB270) != 0) {
        v = D_001D96C0_func_003EB270;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB270 */
