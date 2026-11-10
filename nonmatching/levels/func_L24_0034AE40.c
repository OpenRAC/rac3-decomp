/* func_L24_0034AE40: NEAR 2 diff (level 24)
   only: scheduling of ori $a1,0x360b vs addiu $a0,0x47 around jal func_003A9440; 28-byte copy needs char[28] struct
   prep by w7, p2w2 */
typedef struct { char a[28]; } V7;
extern V7 D_L24_001DD358;
extern int D_L24_002B0FA0[];
int func_00381FF0(int);
void func_003AF408(void *, unsigned int, int, int, int, int, int, int, int, int);
void func_003A9440(int, int);
void func_0038E138(void);
void func_L24_0034AE40(int *a) {
    int *s = (int *)a[0x68 / 4];
    V7 buf;
    int v;
    buf = D_L24_001DD358;
    v = func_00381FF0(D_L24_002B0FA0[s[0]]);
    func_003AF408(&buf, 0x80F0F0F0, v, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
