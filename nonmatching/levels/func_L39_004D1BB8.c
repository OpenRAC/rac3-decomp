/* func_L39_004D1BB8: NEAR 5 (p2w2 w5). scheduling only: retail stores a0 to 0x14(sp) before setting a1/a2/a3; ours sinks the store after
   Not delivered as match; checked with chk.sh at home place.
*/
extern int func_L39_004F6E18(int, void *, void *, int, int, int);
extern void func_L39_004F4F18(void *);

int func_L39_004D1BB8(int a0) {
    int buf0[4];
    int buf10[1];
    int v;
    v = func_L39_004F6E18(a0, buf0, buf10, 0, 0, 0);
    func_L39_004F4F18(&a0);
    return v;
}
