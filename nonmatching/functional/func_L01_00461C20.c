/* functional: medium. Retail is a pure tail jump through the function pointer at a0+0x3C: every argument register and the return value pass through. C forwards a0..a3 and returns the callee's result; float arguments (f12..) are not modelled */
s32 func_L01_00461C20(u8 *a, s32 a1, s32 a2, s32 a3) {
    return (*(s32 (**)(u8 *, s32, s32, s32))(a + 0x3C))(a, a1, a2, a3);
}
