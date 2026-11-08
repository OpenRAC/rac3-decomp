/* func_L21_00339088: NEAR 2 diff (level 21 only)
   only diff: base ptr D_L21_001DED9C[0] loaded into a0 (retail v1) then addu a0,v1,v0
   prep by w7, p2w2 */
extern short *D_L21_0021B860[];
extern char *D_L21_001DED9C[];
extern int D_L21_001DEDD8;
void func_L02_003A02D8(char *, int);
void func_L21_00339088(int *a) {
    int *s = (int *)a[0x68 / 4];
    short *p;
    char *e;
    for (p = D_L21_0021B860[s[0x3C / 4]];
         (s[0x3C / 4] & 0xFF) != 0xFF && D_L21_001DEDD8 >= s[0x3C / 4] && p != 0 &&
         (p[-1] >= 0 || p == D_L21_0021B860[s[0x3C / 4]]);
         p++) {
        e = D_L21_001DED9C[0] + ((*(unsigned short *)p & 0x7FFF) << 8);
        if (e == 0) break;
        func_L02_003A02D8(e, 0);
    }
}
