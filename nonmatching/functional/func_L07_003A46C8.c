/* functional: medium. Medium: control flow reconstructed by hand; func_L01_00451FE0 call has 18 args (stack words 0 and 3). The per-type float table is gp-relative D_001DE348_sda[] (size unknown). State 6 on failed check and state 19's success go to state 0x12. */
/* reserved50 P01: current-file check 555, then 553 after restoring case 1's
 * default destination from the retail jump table. Same-file prototypes now
 * agree with their definitions, including the u8 selector result/parameters.
 * Still a functional seed, not a matching candidate. The inherited four-byte
 * size hint below has no independently established table extent; do not promote
 * it as size evidence. Wide-call scheduling and shared tails remain unresolved. */
#include "common.h"
/* localdecomp:start func_L07_003A46C8 */
extern f32 D_001DE348_sda[];
__asm__(".extern D_001DE348_sda, 4");
extern void func_L07_003A5078(u8 *);
extern void func_L07_003A52F0(u8 *);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003A5780(void *, s32);
extern void func_L01_0045A748(u8 *, f32 *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_00451FE0(s32, s32, void *, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(s32);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L07_003315B0(void *);
extern s32 func_L07_00331008(void *, void *);
extern u8 func_L07_003A5FA0(u8 *);
extern void func_L07_003A5CA8(void *, f32 *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L07_003A5ED0(u8 *);
extern void func_L07_003A5FE0(void *, u8);
extern void func_L07_00334588(void *);
extern void func_L07_003A5D80(u8 *, u8);
extern f32 func_0038DB00(f32, f32);
extern s32 func_L07_003A6110(void *, s32);
extern f32 func_L01_004395E0(void *);
extern void func_L07_003A61E8(void *);
extern void func_L07_003A6460(void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern s32 func_00382468(s32);

void func_L07_003A46C8(u8 *obj) {
    u8 *s;
    s32 flags;
    f32 d, d2, r, base;
    s32 idx;

    if (obj[0x20] == 0) func_L07_003A5078(obj);
    func_L07_003A52F0(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 2:
        func_L01_0045A9F0(obj);
        if (func_0038CB00(s + 0x27E)) func_L07_003A5780(obj, 3);
        return;
    case 3:
        func_L01_0045A9F0(obj);
        func_L07_003A5780(obj, 4);
        return;
    case 4:
        func_L01_0045A748(obj, *(u8 **)(s + 0x270) + 0x10);
        d = func_L01_0040E570(*(u8 **)(s + 0x270) + 0x10, obj + 0x10);
        if (d < 484.0f) {
            s[0x28E] = 1;
            goto set6;
        }
        return;
    case 5:
        func_L01_0045A9F0(obj);
        flags = func_L01_00454370(obj, s + 0x70);
        if (obj[0x42] == 0x13 && func_L01_0044E1B8(obj, 5.0f) != 0) {
            if (*(s32 *)(s + 0x494) != 0) {
                func_L01_00451FE0(*(s32 *)(s + 0x494), 1, s + 0xF0, 0xFF, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0xB4, 0, 0, 0x23, 0, 3);
                func_003C2880(*(s32 *)(s + 0x494));
                *(s32 *)(s + 0x494) = 0;
                *(s32 *)(s + 0x260) = 0;
            }
        }
        if (flags & 1) {
            func_L01_00315900(obj, 0, (void *)func_L07_003315B0);
            return;
        }
        if (!(flags & 2)) return;
        if (s[0x28E] != 0) goto set6;
        func_L07_003A5780(obj, 4);
        return;
    case 6:
        if (func_L07_00331008(*(void **)(s + 0x270), obj) == 0) goto set18;
        idx = func_L07_003A5FA0(obj);
        s[0x4A5] = idx;
        r = D_001DE348_sda[idx & 0xFF] + 5.0f;
        d = func_L01_0040E570(obj + 0x10, s + 0x130);
        r = r * r;
        if (d < r) goto set8;
        goto set7;
    case 7:
        func_L07_003A5CA8(obj, s + 0x130, D_001DE348_sda[s[0x4A5]] + 1.5f);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) == 0) goto set6;
        r = D_001DE348_sda[s[0x4A5]] + 2.0f;
        d = func_L01_0040E570(obj + 0x10, s + 0x130);
        r = r * r;
        if (!(d < r)) return;
        goto set8;
    case 8:
        func_L07_003A5CA8(obj, s + 0x130, D_001DE348_sda[s[0x4A5]]);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) == 0) goto set6;
        d2 = func_0038CF38(obj + 0x10, s + 0x130);
        base = D_001DE348_sda[s[0x4A5]];
        if (base + 5.0f < d2) goto set7;
        if (!(d2 < base + 1.0f)) return;
        goto set9;
    case 9:
        d = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(s + 0x134) - *(f32 *)(obj + 0x14));
        func_L01_0045AA10(obj, d);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) == 0) {
            func_L07_00334588(obj);
            goto set6;
        }
        d = func_0038CF38(obj + 0x10, s + 0x130);
        if (D_001DE348_sda[s[0x4A5]] + 1.5f < d) goto near_stop;
        if (func_L07_003A5ED0(obj) != 0) return;
        if (func_0038CB00(s + 0x492)) func_L07_003A5FE0(obj, 0xA);
        return;
    case 10:
        func_L07_003A5D80(obj, 0);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) == 0) {
            func_L07_00334588(obj);
            goto set6;
        }
        d = func_0038CF38(obj + 0x10, s + 0x130);
        if (D_001DE348_sda[s[0x4A5]] + 2.0f < d) goto near_stop;
        if (func_L07_003A5ED0(obj) != 0) return;
        if (!(obj[0x60] & 2)) return;
        if (0.26179939f < func_0038DB00(*(f32 *)(s + 0x284), *(f32 *)(s + 0x280))) goto set9;
        if (func_L07_003A6110(obj, 0) != 0) return;
        goto set9;
    case 11:
        func_L07_003A5D80(obj, 1);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) == 0) {
            func_L07_00334588(obj);
            goto set6;
        }
        d = func_0038CF38(obj + 0x10, s + 0x130);
        if (D_001DE348_sda[s[0x4A5]] + 2.0f < d) goto near_stop;
        if (func_L07_003A5ED0(obj) != 0) return;
        if (!(obj[0x60] & 2)) return;
        if (0.26179939f < func_0038DB00(*(f32 *)(s + 0x280), *(f32 *)(s + 0x284))) goto set9;
        if (func_L07_003A6110(obj, 1) != 0) return;
        goto set9;
    case 12:
        if (obj[0x60] & 2) func_L07_003A5780(obj, 0xD);
        return;
    case 13:
        if (func_0038CB00(s + 0x492)) func_L07_003A5780(obj, 0xE);
        return;
    case 14:
        if (!(obj[0x60] & 2)) return;
        func_L07_00334588(obj);
        goto set6;
    case 15:
        if (obj[0x60] & 2) func_L07_003A5780(obj, 0x10);
        return;
    case 16:
        if (func_0038CB00(s + 0x492)) func_L07_003A5780(obj, 0x11);
        return;
    case 17:
        d = func_L01_004395E0(obj);
        if (17.0f <= d && d < 23.0f) {
            func_L07_003A61E8(obj);
            func_L01_00404808((void *)func_L07_003A6460, obj);
        }
        if (!(obj[0x60] & 2)) return;
        func_L07_00334588(obj);
        goto set6;
    case 18:
        func_L07_003A5CA8(obj, s + 0x130, *(f32 *)(s + 0x49C) + -0.5f);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) != 0) goto set6;
        d = func_L01_0040E548(obj + 0x10, s + 0x130);
        r = *(f32 *)(s + 0x49C);
        if (d < r * r) {
            func_L07_003A5FE0(obj, 0x14);
            return;
        }
        if (!((r + r) * (r + r) < d)) return;
        if (func_00382468(0xF0) != 0) return;
        func_L07_003A5780(obj, 0x13);
        return;
    case 19:
        func_L07_003A5CA8(obj, s + 0x130, *(f32 *)(s + 0x49C) + -0.5f);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) != 0) goto set6;
        d = func_L01_0040E548(obj + 0x10, s + 0x130);
        r = *(f32 *)(s + 0x49C);
        if (d < r * r) {
            func_L07_003A5FE0(obj, 0x14);
            return;
        }
        if (!(d < (r * 1.3f) * (r * 1.3f))) return;
        if (func_00382468(0xF0) != 0) return;
        goto set12;
    case 20:
        func_L07_003A5D80(obj, 0);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) != 0) goto set6;
        if (!(obj[0x60] & 2)) return;
        d = func_L01_0040E570(obj + 0x10, s + 0x130);
        r = *(f32 *)(s + 0x49C) + 2.0f;
        if (r * r < d) goto set12;
        if (*(f32 *)(s + 0x4A0) < 0.43633232f) func_L07_003A5780(obj, 0x15);
        return;
    case 21:
        func_L07_003A5D80(obj, 1);
        if (func_L07_00331008(*(void **)(s + 0x270), obj) != 0) goto set6;
        if (!(obj[0x60] & 2)) return;
        d = func_L01_0040E570(obj + 0x10, s + 0x130);
        r = *(f32 *)(s + 0x49C) + 2.0f;
        if (r * r < d) goto set12;
        if (*(f32 *)(s + 0x4A0) < 0.43633232f) func_L07_003A5780(obj, 0x14);
        return;
    case 1:
    default:
        return;
    }
set6:
    func_L07_003A5780(obj, 6);
    return;
set7:
    func_L07_003A5780(obj, 7);
    return;
set8:
    func_L07_003A5780(obj, 8);
    return;
set9:
    func_L07_003A5780(obj, 9);
    return;
set12:
    func_L07_003A5780(obj, 0x12);
    return;
set18:
    func_L07_003A5780(obj, 0x12);
    return;
near_stop:
    func_L07_00334588(obj);
    func_L07_003A5780(obj, 8);
    return;
}
/* localdecomp:end func_L07_003A46C8 */
