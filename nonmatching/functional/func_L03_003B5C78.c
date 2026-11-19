/* functional: high. Jump table jtbl_002BE4E0 read from data (0->5CC0, 1->5E44, 2->5EB4, 3 and >=5 -> nothing, 4->5E9C). vsub/vadd.xyz as plain float math. */
/* localdecomp:start func_L03_003B5C78 */
typedef int Q_3B5C78 __attribute__((mode(TI)));
extern s32 func_L01_004561B8(u8 *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L03_003AD510(u8 *);
extern void func_L03_003ADB38(u8 *);
extern void func_L03_003B6740(void *, s32, s32, s32);
extern void func_L03_003B6180(void *);
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_00404808(void (*)(void *), u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L03_003B5C78(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    f32 delta[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    u8 *owner;
    switch (m[0x20]) {
    case 0: {
        f32 d;
        func_L01_004561B8(m);
        func_003C2F58(*(void **)(s + 0x2C), *(s32 *)(s + 0x30), s + 0x10);
        func_003C2F58(*(void **)(s + 0x2C), *(s32 *)(s + 0x30) + 0x20, s);
        *(f32 *)(s + 0x28) += *(f32 *)(s + 0x20);
        delta[0] = *(f32 *)(s + 0) - *(f32 *)(s + 0x10);
        delta[1] = *(f32 *)(s + 4) - *(f32 *)(s + 0x14);
        delta[2] = *(f32 *)(s + 8) - *(f32 *)(s + 0x18);
        delta[3] = *(f32 *)(s + 0xC);
        func_0038CF68(delta, delta, *(f32 *)(s + 0x28));
        *(f32 *)(m + 0x10) = *(f32 *)(s + 0x10) + delta[0];
        *(f32 *)(m + 0x14) = *(f32 *)(s + 0x14) + delta[1];
        *(f32 *)(m + 0x18) = *(f32 *)(s + 0x18) + delta[2];
        *(f32 *)(m + 0x1C) = *(f32 *)(s + 0x1C);
        *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), 0.034906585f);
        *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), 0.034906585f);
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.034906585f);
        func_0038D308(m + 0xC0, m + 0xF0);
        d = func_0038CF38(m + 0x10, s);
        if (d <= *(f32 *)(s + 0x20) * 0.88f) {
            if (*(s32 *)(s + 0x24) == 0) {
                owner = *(u8 **)(m + 0xB8);
                if (owner != 0 && *(s16 *)(owner + 0xAA) == 0x1AE0) {
                    func_L03_003AD510(owner);
                    *(s32 *)(s + 0x24) = *(s32 *)(s + 0x24) + 3;
                    return;
                }
            }
            *(Q_3B5C78 *)tmp = *(Q_3B5C78 *)(m + 0x10);
            func_L03_003B6740(tmp, 100, 0x88202020, 0x88208020);
            func_003C2880(m);
        } else if (func_L01_00447490(m, 0x10000, 0) != 0) {
            func_003C2880(m);
        } else {
            m[0xA8] = 0xFF;
            func_L01_00404808(func_L03_003B6180, m);
        }
        break;
    }
    case 1:
        *(s32 *)(m + 0x98) = 0;
        *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), 0.034906585f);
        *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), 0.034906585f);
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.034906585f);
        func_L01_00404808(func_L03_003B6180, m);
        break;
    case 2:
        owner = *(u8 **)(m + 0xB8);
        if (owner != 0 && *(s16 *)(owner + 0xAA) == 0x1AE0) func_L03_003ADB38(owner);
        func_003C2880(m);
        break;
    case 4:
        func_L01_004450F0(m, 0, -1);
        break;
    default:
        break;
    }
}
/* localdecomp:end func_L03_003B5C78 */
