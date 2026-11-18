#include "common.h"

/* localdecomp:start func_L31_003AB8D0 */
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_L05_00441508(f32, f32, f32);
extern u8 D_001A30B0[];

void func_L31_003AB8D0(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    s32 idx;
    u8 *o;
    f32 t;

    switch (m[0x20]) {
    case 0:
        *(f32 *)pv = *(f32 *)pv * 3.1415927f / 180.0f;
        *(s32 *)(pv + 4) = (*(s32 *)(pv + 4) * 5 + 2) / 6;
        t = *(f32 *)(m + 0xF4);
        *(f32 *)(pv + 0xC) = t;
        *(f32 *)pv = func_0038DAB8(*(f32 *)pv, t);
        *(s32 *)(pv + 0x10) = -1;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(m)) {
            idx = *(s32 *)(pv + 0x10);
            if (idx != -1) {
                o = D_001A30B0 + (idx << 7);
                if (*(u8 **)(o + 0xDC) == m && o[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            *(s32 *)(pv + 0x10) = -1;
            *(f32 *)(m + 0xF4) = *(f32 *)(pv + 0xC);
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        if (func_L01_00456250(m)) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m)) {
            *(s32 *)(pv + 8) = *(s32 *)(pv + 4);
            if (*(s32 *)(pv + 0x14) == 0) {
                *(s32 *)(m + 0x98) = 0;
            }
        }
        if (*(s32 *)(pv + 0x10) == -1 || (o = D_001A30B0 + (*(s32 *)(pv + 0x10) << 7), *(u8 **)(o + 0xDC) != m) || o[0xD0] == 0) {
            *(s32 *)(pv + 0x10) = func_003A52A0(0, 4, m);
        }
        *(f32 *)(m + 0xF4) = func_L05_00441508(*(f32 *)(pv + 0xC), *(f32 *)pv, func_L03_0034B148(*(s32 *)(pv + 8), *(s32 *)(pv + 4), 0.0f));
        if (func_0038CAD0(pv + 8)) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(m)) {
            idx = *(s32 *)(pv + 0x10);
            if (idx != -1) {
                o = D_001A30B0 + (idx << 7);
                if (*(u8 **)(o + 0xDC) == m && o[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            *(s32 *)(pv + 0x10) = -1;
            *(f32 *)(m + 0xF4) = *(f32 *)pv;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        if (func_L01_00456250(m) == 0) {
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(m)) {
            *(s32 *)(pv + 8) = *(s32 *)(pv + 4);
            if (*(s32 *)(pv + 0x14) == 0) {
                *(s32 *)(m + 0x98) = 0;
            }
        }
        if (*(s32 *)(pv + 0x10) == -1 || (o = D_001A30B0 + (*(s32 *)(pv + 0x10) << 7), *(u8 **)(o + 0xDC) != m) || o[0xD0] == 0) {
            *(s32 *)(pv + 0x10) = func_003A52A0(0, 4, m);
        }
        *(f32 *)(m + 0xF4) = func_0038DB48(*(f32 *)pv * (1.0f - func_L03_0034B148(*(s32 *)(pv + 8), *(s32 *)(pv + 4), 0.0f)));
        if (func_0038CAD0(pv + 8)) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L31_003AB8D0 */
