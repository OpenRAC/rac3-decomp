/* US draft of func_003BA608 (rac3-uya-decomp func_003B5128, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BA608 */
void func_003BA608(void *arg0) {
    f32 var_f0;
    f32 var_f1;
    s32 temp_v1;

    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1C));
    var_f0 = 0.0048076925f;
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_f1 = -1.0f;
        break;
    case 3:
        var_f1 = -1.0f;
        var_f0 = 0.01923077f;
        break;
    case 2:
        var_f1 = 1.0f;
        break;
    case 4:
        var_f1 = 1.0f;
        var_f0 = 0.01923077f;
        break;
    default:
        var_f1 = 0.0f;
        break;
    }
    (*(f32 *)((u8 *)(arg0) + 0x58)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x58)) + (var_f1 * var_f0));
}
/* localdecomp:end func_003BA608 */
