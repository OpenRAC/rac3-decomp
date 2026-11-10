/* Ported from rac4-decomp's func_L00_004FFAC0 (a twin of this function's code), names renamed from retail's
   relocations; 6 instruction(s) still differ under this file's flags. */
s32 func_L39_004C36A8(void *, s32);
s32 func_L39_004C4EE0();

void func_L39_004C3CC0(void *arg0) {
    if (!(func_L39_004C4EE0() & 0x3000) || (func_L39_004C4EE0(arg0) & 0x4000)) {
        func_L39_004C36A8(arg0, 0);
    }
    (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(arg0) + 8))) + 0x14))(arg0);
}