/* func_L39_00602010: NEAR 10 diff (15 levels, L39 multiplayer)
   only p/n callee-saved reg swap (retail p=s0,n=s1) and loop-end bnez vs bgtz
   prep by w7, p2w2 */
__asm__(".extern D_001D734C_sda, 4");
extern int D_001D734C_sda;
extern char D_L39_002452A0[];
extern char D_L39_002452E0[];
extern char D_L39_00245310[];
__asm__(".extern D_L39_00242A5C, 16");
extern int D_L39_00242A5C;
void func_00128BF0(void *, ...);
void func_003A9CB8(int);
void func_L39_00602010(int *a) {
    int *p;
    int n;
    func_00128BF0(D_L39_002452A0);
    p = a + 7;
    n = a[6];
    func_00128BF0(D_L39_002452E0, p, n);
    for (; n > 0; n--) {
        p[1] += (int)a;
        func_003A9CB8(p[1]);
        p += 2;
        D_001D734C_sda = D_L39_00242A5C + 1;
    }
    func_00128BF0(D_L39_00245310);
}
