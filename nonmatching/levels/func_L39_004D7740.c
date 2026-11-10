/* Ported from rac4-decomp's func_L00_00513540 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
s32 func_L39_004B5910(s32);

void func_L39_004D7740(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = func_L39_004B5910(arg1);
}