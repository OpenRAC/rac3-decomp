/* func_L20_003FEDF0: NEAR 2 diff (level 20). same family as func_L21_00339088.
   only diff: loaded base ptr in a0 vs retail v1
   prep by w7, p2w2 */
extern short *D_L20_0021CFE0[];
extern char *D_L20_001E029C[];
extern int D_L20_001E02D8;
void func_L20_003FEDF0(unsigned char *a) {
    short *p;
    char *e;
    if (a[0x21] == 0xFF) return;
    for (p = D_L20_0021CFE0[a[0x21]];
         a[0x21] != 0xFF && D_L20_001E02D8 >= a[0x21] && p != 0 &&
         (p[-1] >= 0 || p == D_L20_0021CFE0[a[0x21]]);
         p++) {
        e = D_L20_001E029C[0] + ((*(unsigned short *)p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(short *)(e + 0xAA) == *(short *)(a + 0xAA)) {
            *(short *)(*(char **)(e + 0x68) + 0x3D8) = 1;
        }
    }
}
