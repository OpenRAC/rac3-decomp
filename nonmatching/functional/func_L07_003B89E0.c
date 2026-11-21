/* exact: byte-identical at level_07 (func_L07_003B89E0). */

extern f32 func_L01_0040E4C0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003B8AE0(void);

void func_L07_003B89E0(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    vu0_v4 d;
    s32 r;

    if (*(s16 *)(sub + 0x29E) == 0) {
        func_L07_003A2380(8, obj, 0, 100);
        *(s16 *)(sub + 0x29E) = 0x3E8;
    }
    vec_sub_ba(&d, obj + 0x10, sub + 0x70);
    d.z = 0.0f;
    r = 8;
    if (sub[0x296] != 0) {
        r = 9;
    }
    if (func_L01_0040E4C0(&d) < 144.0f) {
        func_L07_003B8690(obj, r);
        return;
    }
    func_0038CF68(&d, &d, 7.0f);
    vec_add_ab(sub + 0x270, sub + 0x70, &d);
    *(f32 *)(sub + 0x278) = *(f32 *)(*(u8 **)(sub + 0x190) + 0x18);
    sub[0x297] = r;
    sub[0x298] = 0;
    *(void **)(sub + 0x290) = func_L07_003B8AE0;
    func_L07_003B8690(obj, 10);
}
