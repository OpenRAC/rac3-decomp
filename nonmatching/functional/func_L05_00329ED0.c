/* functional: high. Follows retail instruction order; note the delay-slot store v1=e+0x70 happens before func_L01_004450F0 in the else path. Diffs are scheduling/early re-read of s+0xB0 only. */
typedef int u128_329ED0 __attribute__((mode(TI)));
extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L03_003F6A80(void *, void *, void *, s32, s32);
extern void func_L05_0032A0B0(u8 *, u8 *, s32, s32);

void func_L05_00329ED0(u8 *a0, u8 *s, s32 idx) {
    u8 *e = D_L05_001DFC80 + (*(s32 *)(s + 0x90 + idx * 4) << 7);
    u128_329ED0 v[2];
    s32 t;
    s32 *tp;
    f32 lim;

    if (idx == *(s32 *)(s + 0x15C)) {
        t = *(s32 *)(s + 0xB0 + idx * 4);
        if (t != -1) {
            tp = D_L05_0021ED80[t];
            lim = func_0038CF00(e + 0x30, (u8 *)tp + 0x10) + 5.0f;
        } else {
            lim = 10.0f;
        }
        if (func_0038CF00(e + 0x30, a0 + 0x10) <= lim) {
            return;
        }
    }
    t = *(s32 *)(s + 0xB0 + idx * 4);
    if (t != -1) {
        tp = D_L05_0021ED80[t];
        v[0] = *(u128_329ED0 *)((u8 *)tp + 0x10);
        v[1] = 0;
        *(f32 *)((u8 *)&v[1] + 8) = func_0038D160(*(f32 *)((u8 *)tp + 0x20) - *(f32 *)((u8 *)tp + 0x10),
                                                   *(f32 *)((u8 *)tp + 0x24) - *(f32 *)((u8 *)tp + 0x14));
        func_L01_004450F0(a0, 3, -1);
    } else {
        v[0] = *(u128_329ED0 *)(e + 0x30);
        v[1] = *(u128_329ED0 *)(e + 0x70);
        func_L01_004450F0(a0, 2, -1);
    }
    *(s32 *)(s + 0x15C) = idx;
    func_L03_003F6A80(a0, &v[0], &v[1], 0, 0);
    func_L05_00328E98(s, *(Vec4 *)&v[0], *(Vec4 *)&v[1]);
    if (*(s32 *)(s + 0xB0 + idx * 4) != -1) {
        func_L05_0032A0B0(a0, s, *(s32 *)(s + 0xB0 + idx * 4), *(s32 *)(s + 0x90 + idx * 4));
    }
}
