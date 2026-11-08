/* func_L07_003ACA00: 5 diff (only reg choice: retail puts the -0x11 mask in $a1 before saving s0, ours $a0 after move s0,a0). Tried: signature with extra arg, void proto, split v, unsigned. Left for Opus. */
extern void func_L07_00334740(void);
extern void func_L07_003ACA90(void *, int);

void func_L07_003ACA00(char *obj) {
    char *p = *(char **)(obj + 0x68);
    *(int *)(p + 0x56C) = 0;
    *(int *)(p + 0x188) &= ~0x10;
    func_L07_00334740();
    func_L07_003ACA90(obj, 1);
}
