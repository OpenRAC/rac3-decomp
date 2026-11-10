/* func_L07_00335448: near miss 2 diff (w6 p2w1): lui $a0,0x15 / lui $a1 order in the first call; tried int/float/long/unsigned proto variants */
extern void func_L03_003AECB0(void *);
extern void func_L01_00516FD8(int, void *);
extern char D_L07_001E0D10[];
extern char D_L07_001E0D20[];
extern void func_L07_003354A0(void *);
void func_L07_00335448(void *a) {
    func_L03_003AECB0(a);
    func_L01_00516FD8(0x150006, D_L07_001E0D10);
    func_L01_00516FD8(0x150007, D_L07_001E0D20);
    func_L07_003354A0(a);
}
