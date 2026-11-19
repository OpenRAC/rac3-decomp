/* functional: medium. 240 words differ (register allocation); the return is an index but is typed void* (cast) because the unit's caller, func_L31_00344A08, already declares it void*; every branch re-read against the asm incl. the cntA/cntB candidate tests. */
/* localdecomp:start func_L31_00344FC8 */
#include "vu0.h"
__asm__(".extern D_L31_001DCFB8, 4");
__asm__(".extern D_L31_001DCFBC, 4");
__asm__(".extern D_L31_001DCFC0, 4");
__asm__(".extern D_L31_001DCFC4, 4");
extern f32 D_L31_001DCFB8;
extern f32 D_L31_001DCFBC;
extern f32 D_L31_001DCFC0;
extern f32 D_L31_001DCFC4;
extern u8 D_001A4BE0[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L31_00344C30(void *, s32, void *);
void *func_L31_00344FC8(u8 *o) {
    u8 *p = *(u8 **)(o + 0x68);
    vu0_v4 s;
    s32 i, n, r, cntA, cntB, useA, pick;
    u8 *e;
    f32 x, hx;

    if (p[0x1A6] == 1) {
        i = 0;
        n = p[0x1A4];
        r = func_00382498(0, *(s32 *)(p + 0x194) - 1);
        if (n != 0 && p[2] < r) {
            u8 prev;
            e = p + 2;
            prev = *e;
            for (;;) {
                i++;
                e += 0x30;
                r -= prev;
                if (i >= n) {
                    break;
                }
                if (!(*e < r)) {
                    break;
                }
                prev = *e;
            }
        }
        return (void *)i;
    }
    if (p[0x1A6] == 2) {
        cntA = 0;
        cntB = 0;
        useA = 1;
        if (!(fabs_asm(func_0038DB00(D_L31_001DCFBC, *(f32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0xF8))) <
              fabs_asm(func_0038DB00(D_L31_001DCFC0, *(f32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0xF8))))) {
            useA = 0;
        }
        e = p + 2;
        for (i = 0; i < 8; i++, e += 0x30) {
            func_L31_00344C30(o, i, &s);
            hx = *(f32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0x10);
            x = s.x;
            if (fabs_asm(x - hx) < D_L31_001DCFB8) {
                continue;
            }
            if (*e == 0xFF) {
                continue;
            }
            if (x < hx) {
                if (useA == 0) {
                    cntA++;
                } else {
                    cntB++;
                }
            } else if (hx < x) {
                if (useA == 0) {
                    cntB++;
                } else {
                    cntA++;
                }
            } else {
                cntB++;
            }
        }
        if (D_L31_001DCFC4 < func_003824E0(0.0f, 1.0f) && cntB > 0) {
            pick = func_00382498(0, cntB - 1);
            e = p + 2;
            for (i = 0; i < 8; i++, e += 0x30) {
                func_L31_00344C30(o, i, &s);
                hx = *(f32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0x10);
                x = s.x;
                if (!((useA != 0 && x < hx) || (useA == 0 && hx < x))) {
                    continue;
                }
                if (*e == 0xFF) {
                    continue;
                }
                if (pick <= 0) {
                    return (void *)i;
                }
                pick--;
            }
            return 0;
        }
        if (cntA > 0) {
            pick = func_00382498(0, cntA - 1);
            e = p + 2;
            for (i = 0; i < 8; i++, e += 0x30) {
                func_L31_00344C30(o, i, &s);
                hx = *(f32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0x10);
                x = s.x;
                if (!((useA == 0 && x < hx) || (useA != 0 && hx < x))) {
                    continue;
                }
                if (*e == 0xFF) {
                    continue;
                }
                if (pick <= 0) {
                    return (void *)i;
                }
                pick--;
            }
            return 0;
        }
        return 0;
    }
    if (p[0x1A6] != 0) {
        return 0;
    }
    {
        s32 cur = *(s32 *)(p + 0x190);
        s32 total = *(s32 *)(p + 0x194);
        s32 sum = 0;
        s32 cnt;
        i = 0;
        if (!(cur < total)) {
            cur = cur - total;
            *(s32 *)(p + 0x190) = cur;
        }
        cur = *(s32 *)(p + 0x190);
        cnt = p[0x1A4];
        if (cnt != 0 && !(cur < p[2])) {
            e = p + 2;
            for (;;) {
                u8 prev = *e;
                i++;
                e += 0x30;
                sum += prev;
                if (!(i < cnt)) {
                    break;
                }
                if (cur < *e + sum) {
                    break;
                }
            }
        }
        *(s32 *)(p + 0x190) = cur + 1;
        return (void *)(i != cnt ? i : 0);
    }
}
/* localdecomp:end func_L31_00344FC8 */
