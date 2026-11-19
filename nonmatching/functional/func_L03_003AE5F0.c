/* functional: high. Loops instead of unrolled calls; same call order and args. Callee func_L01_00516AA0 unknown purpose (id, 1, value). */
/* localdecomp:start func_L03_003AE5F0 */
extern void func_L01_00516AA0(s32, s32, s32);
void func_L03_003AE5F0(s32 on) {
    s32 i;
    s32 a = (on != 0);
    for (i = 0x4A000A; i <= 0x4A000C; i++) {
        func_L01_00516AA0(i, 1, a);
    }
    for (i = 0x4A0001; i <= 0x4A0009; i++) {
        func_L01_00516AA0(i, 1, !a);
    }
}
/* localdecomp:end func_L03_003AE5F0 */
