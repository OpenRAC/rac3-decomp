/* functional: high. Rewritten from PAL asm; trivial loop, only register allocation differs. */
/* localdecomp:start func_L01_004BF618 */
extern S_00244740 D_L01_002446C0[];

void func_L01_004BF618(s32 a0) {
    u8 *u = (u8 *)D_L01_002446C0;
    s32 i;
    u8 *p;
    p = u + 0x150;
    for (i = 0; i < *(s32 *)(u + 0x740); i++, p += 0x14) {
        if (*(s32 *)(p - 0x10) == a0) *p = 1;
    }
}
/* localdecomp:end func_L01_004BF618 */
