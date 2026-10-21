/* US draft of func_003BB760 (rac3-uya-decomp func_003BB688, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` and without `@ps2as` (a single-function override). */


/* localdecomp:start func_003BB760 */
extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB8E8(s32);
extern void func_0038CF58();

s32 func_003BB760(s32 mode) {
    register u32 *flags_base __asm__("$8") = D_001DA1B4;
    register s32 index __asm__("$6") = 0;
    register void **pointer __asm__("$16") = D_001DA1B0;
    register u32 *flags __asm__("$7") = flags_base;

    do {
        register u32 check_state __asm__("$2");
        register u32 entry_state __asm__("$3");
        register u32 updated_state __asm__("$2");
        register u32 *selected_flags __asm__("$5");
        register s32 offset __asm__("$3") = index << 3;

        if (mode != 0) {
            check_state = *(u8 *)flags ^ 1;
        } else {
            check_state = *flags;
        }
        if ((check_state & 1) == 0 && *pointer != 0) {
            selected_flags = (u32 *)((u8 *)offset + (s32)flags_base);
            entry_state = *selected_flags;
            if ((entry_state & 2) == 0) {
                updated_state = entry_state | 2;
                *selected_flags = updated_state;
                func_0038CF58(*pointer, 0xDEADBEEF, func_003BB8E8((s32)*pointer));
                return (s32)*pointer;
            }
        }
        index++;
        pointer = (void **)((u8 *)pointer + 8);
        flags += 2;
    } while (index < 7);
    return 0;
}
/* localdecomp:end func_003BB760 */
