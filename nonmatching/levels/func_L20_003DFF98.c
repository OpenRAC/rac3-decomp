/* func_L20_003DFF98: NEAR 8 diff (prologue save order, i=0 hoisted vs in blez delay slot)
   for loop over o+0x2A4 count of 0xE0-stride entries calling func_L01_0040C948(p, o[0x2A0]) when p[0xC0]>0
   prep by w7, p2w2 */
void func_L01_0040C948(void *, int);
void func_L20_003DFF98(int *a) {
    int *o = (int *)a[0x68 / 4];
    int i;
    int *p = o;
    for (i = 0; i < o[0x2A4 / 4]; i++) {
        if (p[0xC0 / 4] > 0) {
            func_L01_0040C948(p, o[0x2A0 / 4]);
        }
        p += 0xE0 / 4;
    }
}
