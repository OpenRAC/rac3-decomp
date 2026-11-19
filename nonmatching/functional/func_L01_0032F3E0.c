/* functional: high. Compiles; stack layout and block order differ, same operations; every branch read against the asm (0xFE/0xFD/null target or flag 0x1000 clear all drop to state 3 and clear vars+0x64). */
extern f32 *func_00382348(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032F3E0(u8 *obj) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 *h = func_00382348(*(void **)(vars + 0x64));
    u8 *t;
    s32 st;

    func_L01_004C7D98(obj + 0x10, b);
    *(s128 *)a = *(s128 *)(*(u8 **)(vars + 0x64) + 0x10);
    if (h != 0) {
        func_0038CE20(d, *(u8 **)(vars + 0x64) + 0xE0, h[4]);
        vec_add_ab(a, a, d);
    }
    t = *(u8 **)(vars + 0x64);
    if (t == 0 || t[0x20] == 0xFE) {
        st = 3;
    } else if (t[0x20] == 0xFD) {
        st = 3;
    } else if ((*(u16 *)(t + 0x34) & 0x1000) == 0) {
        st = 3;
    } else {
        func_003C2F58(obj, 0, c);
        vec_sub_ab(d, a, c);
        func_L01_0040EE50(e, obj + 0xC0);
        func_0038D000(vars + 0x20, d, e);
        return;
    }
    obj[0x20] = st;
    *(s32 *)(vars + 0x64) = 0;
}
