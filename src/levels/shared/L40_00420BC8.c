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
extern void func_L40_00421148();
extern void func_L40_003F47B0();
extern void func_L40_003F3C60();
extern void func_L40_003F4638();
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

INCLUDE_ASM("asm/levels", func_L40_00421148);
