#include "common.h"

/* localdecomp:start func_L40_00420BC8 */
typedef struct { u8 pad[0x128]; s32 w128; u8 pad12C[0x168 - 0x12C]; u8 b168; } G_00420BC8;

extern G_00420BC8 D_001A5CD0;
__asm__(".extern D_L40_00241640_00420BC8, 16");
extern s8 *D_L40_00241640_00420BC8;
__asm__(".extern D_L40_0024845C, 16");
extern u8 *D_L40_0024845C;
extern s16 *D_L40_0028EA20[];
extern s32 D_L40_00248498;
extern void func_003C2880(u8 *a0);
extern void func_L39_0061C1E0(u8 *, s32);
extern void func_L39_005F2FF8(void *, s32);
extern s32 func_L40_0053D8C8(s32, s32, s32, s32);
extern void func_L40_00421C08();
extern void func_L40_00421550();
extern u8 *func_L40_00421148(s32, s32, u8 *);
extern void func_L40_003F47B0();
extern void func_L40_003F3C60();
extern u8 *func_L40_003F4638();
extern f32 func_003C3D30(void *, s32, s32, f32);
extern u8 *func_L39_0066C2B8(void);
extern s32 func_00197498(s32);
extern s32 func_L39_0066C280(s32, s32, s32, s32, u8 *);
extern void func_0038CB78(void *, s32, s32);

void func_L40_00420BC8(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s16 *p;
    u8 *o;
    u8 *msg;
    u8 *q;
    s32 st;

    if (*(s32 *)(v + 0x290) == -1 && self[0x20] == 0) {
        if (D_L40_00241640_00420BC8[0x18D] == 0) {
            func_003C2880(self);
            return;
        }
        func_L39_0061C1E0(self, -1);
        self[0x20] = 0x26;
        *(s32 *)(v + 0x2A0) = 2;
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(self, 1);
        func_L40_0053D8C8(0x1A91, (s32)func_L40_00421C08, (s32)func_L40_00421550, (s32)func_L40_00421148);
        func_L40_0053D8C8(0x1A1B, (s32)func_L40_003F47B0, (s32)func_L40_003F3C60, (s32)func_L40_003F4638);
        *(s32 *)(v + 0x2AC) = -1;
        p = D_L40_0028EA20[*(s32 *)(v + 0x464)];
        while ((*(s32 *)(v + 0x464) & 0xFF) != 0xFF && *(s32 *)(v + 0x464) <= D_L40_00248498 && p != 0
               && (p[-1] >= 0 || p == D_L40_0028EA20[*(s32 *)(v + 0x464)])) {
            o = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (o == 0) {
                break;
            }
            func_L39_0061C1E0(o, -1);
            p++;
        }
        return;
    }
    if (*(s32 *)(v + 0x2A0) == 0) {
        if (D_L40_00241640_00420BC8[0x18D] == 0) {
            func_003C2880(self);
            return;
        }
        *(s32 *)(v + 0x2AC) = -1;
        func_L39_0061C1E0(self, -1);
        *(s32 *)(v + 0x2A0) = 1;
        self[0x30] = 0xFF;
        func_L40_0053D8C8(0x1A91, (s32)func_L40_00421C08, (s32)func_L40_00421550, (s32)func_L40_00421148);
        func_L40_0053D8C8(0x1A1B, (s32)func_L40_003F47B0, (s32)func_L40_003F3C60, (s32)func_L40_003F4638);
        *(f32 *)(self + 0x18) = func_003C3D30(self + 0x10, 0, 0, 0.5f) + 0.6f;
        p = D_L40_0028EA20[*(s32 *)(v + 0x464)];
        while ((*(s32 *)(v + 0x464) & 0xFF) != 0xFF && *(s32 *)(v + 0x464) <= D_L40_00248498 && p != 0
               && (p[-1] >= 0 || p == D_L40_0028EA20[*(s32 *)(v + 0x464)])) {
            o = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (o == 0) {
                break;
            }
            func_L39_0061C1E0(o, -1);
            p++;
        }
    } else if (D_001A5CD0.b168 != 0) {
        if (*(s32 *)(v + 0x2A0) == 1) {
            msg = func_L39_0066C2B8();
            if (msg == 0) {
                return;
            }
            q = msg + func_L39_0066C280(0, func_00197498(2), D_001A5CD0.w128 + 500, 0x1A91, msg);
            *(s32 *)q = (self - D_L40_0024845C) >> 8;
            q += 4;
            *(s32 *)msg = q - msg;
            *(s32 *)(v + 0x2A0) = 2;
            func_L40_0053D8C8(0x1A91, (s32)func_L40_00421C08, (s32)func_L40_00421550, (s32)func_L40_00421148);
            func_L40_0053D8C8(0x1A1B, (s32)func_L40_003F47B0, (s32)func_L40_003F3C60, (s32)func_L40_003F4638);
            *(s32 *)(v + 0x2B0) = 0;
            *(u16 *)(self + 0x34) &= 0xFFBE;
            *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
        }
    } else if (*(s32 *)(v + 0x2A0) == 1) {
        func_L40_0053D8C8(0x1A91, (s32)func_L40_00421C08, (s32)func_L40_00421550, (s32)func_L40_00421148);
        func_L40_0053D8C8(0x1A1B, (s32)func_L40_003F47B0, (s32)func_L40_003F3C60, (s32)func_L40_003F4638);
        *(s32 *)(v + 0x2B0) = 0;
        *(s32 *)(v + 0x2A0) = 2;
        *(u16 *)(self + 0x34) &= 0xFFBE;
        *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    }
    if (self[0x20] == 0x25) {
        func_003C2880(self);
        if (++*(s32 *)(v + 0x2B0) >= 0x1A2) {
            *(s32 *)(v + 0x2B0) = 0;
            self[0x20] = 0;
            *(s32 *)(v + 0x2A4) = 0;
            *(s32 *)(v + 0x2A0) = 1;
            func_0038CB78(v + 0x294, 0, 0x1D8);
        }
    }
    if (self[0x20] == 0x27) {
        *(s32 *)(v + 0x2B0) = 0;
        self[0x20] = 0;
        *(s32 *)(v + 0x2A4) = 0;
        *(s32 *)(v + 0x2A0) = 1;
        func_0038CB78(v + 0x294, 0, 0x1D8);
        msg = func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        q = msg + func_L39_0066C280(0, func_00197498(2), D_001A5CD0.w128 + 500, 0x1A91, msg);
        *(s32 *)q = (self - D_L40_0024845C) >> 8;
        q += 4;
        *(s32 *)msg = q - msg;
        *(s32 *)(v + 0x2A0) = 2;
        func_L40_0053D8C8(0x1A91, (s32)func_L40_00421C08, (s32)func_L40_00421550, (s32)func_L40_00421148);
        func_L40_0053D8C8(0x1A1B, (s32)func_L40_003F47B0, (s32)func_L40_003F3C60, (s32)func_L40_003F4638);
        *(s32 *)(v + 0x2B0) = 0;
        *(u16 *)(self + 0x34) &= 0xFFBE;
        *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L40_00420BC8 */

/* localdecomp:start func_L40_00421148 */
typedef struct { u8 pad[0x30]; u8 x30; u8 x31; u16 x32; u16 x34; } S_00421148;
extern s32 func_L40_0053F2D8(u8 *msg);
extern u8 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C7C38(u8 *m);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 *D_L40_00241120;

u8 *func_L40_00421148(s32 a0, s32 a1, u8 *msg) {
    s32 index = *(s32 *)(msg + 0x18);
    u8 *m;
    u8 *v;
    s32 *h = (s32 *)(msg + 8);
    s32 n;
    f32 f2b4;
    s32 w2c0;
    f32 f2b8;
    s32 w464;
    s32 w468;
    s32 w454;

    m = func_L40_0053F570(0x1A91, h[1], *(s32 *)(msg + 4), func_L40_0053F2D8(msg), index);
    if (m != 0) {
        ((S_00421148 *)m)->x30 = 0x7F;
        ((S_00421148 *)m)->x34 |= 0x20;
        ((S_00421148 *)m)->x32 = 0x7F;
        v = *(u8 **)(m + 0x68);
        if (*D_L40_00241120 >= 2) {
            *(u8 *)(m + 0x62) = 1;
        }
        *(s32 *)(v + 0x2B0) = 0;
        *(u8 *)(m + 0x20) = 0;
        *(s32 *)(v + 0x2A4) = 0;
        n = *(s32 *)(v + 0x44C);
        if (n < 100) {
            n = 100;
        }
        f2b4 = *(f32 *)(v + 0x2B4);
        w2c0 = *(s32 *)(v + 0x2C0);
        f2b8 = *(f32 *)(v + 0x2B8);
        w464 = *(s32 *)(v + 0x464);
        w468 = *(s32 *)(v + 0x468);
        w454 = *(s32 *)(v + 0x454);
        func_0038CB78(v + 0x294, 0, 0x1D8);
        *(f32 *)(v + 0x2B4) = f2b4;
        *(s32 *)(v + 0x2C0) = w2c0;
        *(f32 *)(v + 0x2B8) = f2b8;
        *(s32 *)(v + 0x468) = w468;
        *(s32 *)(v + 0x464) = w464;
        *(s32 *)(v + 0x454) = w454;
        *(s32 *)(v + 0x2A0) = 2;
        func_003C7C38(m);
        func_L01_0045BD78(m, 0.0012f, 0.060000002f, 0.0025132743f, 0.12566371f);
        *(f32 *)(v + 0x1B0) = 1.3f;
        *(f32 *)(v + 0x1AC) = 2.5f;
        *(f32 *)(v + 0x1A8) = 1.0f;
        *(s32 *)(v + 0x44C) = n;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x2B4);
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x2B4);
    }
    return m;
}
/* localdecomp:end func_L40_00421148 */
