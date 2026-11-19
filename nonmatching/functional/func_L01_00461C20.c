/* functional: medium. 7 diff: retail is a true tail jump (lw/jr, no frame); C makes a call, so the callee sees only a0 explicitly; any other argument registers the retail trampoline would pass through are not modelled */
void func_L01_00461C20(u8 *a) {
    (*(void (**)(u8 *))(a + 0x3C))(a);
}
