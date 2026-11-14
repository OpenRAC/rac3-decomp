#include "common.h"

/* NTSC-U counterpart of func_L40_00420BC8 (src/levels/shared/L40_00420BC8.c): 418 -> 501 */
/* localdecomp:start func_L40_00420328 */
typedef struct { u8 pad[0x128]; s32 w128; u8 pad12C[0x168 - 0x12C]; u8 b168; } G_00420BC8;

extern G_00420BC8 D_001A5E50;
__asm__(".extern D_L40_002417C0_00420328, 16");
extern s8 *D_L40_002417C0_00420328;
__asm__(".extern D_L40_002485DC, 16");
extern u8 *D_L40_002485DC;
extern s16 *D_L40_0028EBA0[];
extern s32 D_L40_00248618;
extern void func_003BD360(u8 *a0);
extern void func_L39_00619A68(u8 *, s32);
extern void func_L39_005F08F8(void *, s32);
extern s32 func_L40_0053B018(s32, s32, s32, s32);
extern void func_L40_00421350();
extern void func_L40_00420CB0();
extern void func_L40_004208A8();
extern void func_L40_003F42F0();
extern void func_L40_003F37A0();
extern void func_L40_003F4178();
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern u8 *func_L39_006699B0(void);
extern s32 func_00197588(s32);
extern s32 func_L39_00669978(s32, s32, s32, s32, u8 *);
extern void func_00388440(void *, s32, s32);

void func_L40_00420328(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s16 *p;
    u8 *o;
    u8 *msg;
    u8 *q;
    s32 st;

    if (*(s32 *)(v + 0x290) == -1 && self[0x20] == 0) {
        if (D_L40_002417C0_00420328[0x18D] == 0) {
            func_003BD360(self);
            return;
        }
        func_L39_00619A68(self, -1);
        self[0x20] = 0x26;
        *(s32 *)(v + 0x2A0) = 2;
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(self, 1);
        func_L40_0053B018(0x1A91, (s32)func_L40_00421350, (s32)func_L40_00420CB0, (s32)func_L40_004208A8);
        func_L40_0053B018(0x1A1B, (s32)func_L40_003F42F0, (s32)func_L40_003F37A0, (s32)func_L40_003F4178);
        *(s32 *)(v + 0x2AC) = -1;
        p = D_L40_0028EBA0[*(s32 *)(v + 0x464)];
        while ((*(s32 *)(v + 0x464) & 0xFF) != 0xFF && *(s32 *)(v + 0x464) <= D_L40_00248618 && p != 0
               && (p[-1] >= 0 || p == D_L40_0028EBA0[*(s32 *)(v + 0x464)])) {
            o = D_L40_002485DC + ((*p & 0x7FFF) << 8);
            if (o == 0) {
                break;
            }
            func_L39_00619A68(o, -1);
            p++;
        }
        return;
    }
    if (*(s32 *)(v + 0x2A0) == 0) {
        if (D_L40_002417C0_00420328[0x18D] == 0) {
            func_003BD360(self);
            return;
        }
        *(s32 *)(v + 0x2AC) = -1;
        func_L39_00619A68(self, -1);
        *(s32 *)(v + 0x2A0) = 1;
        self[0x30] = 0xFF;
        func_L40_0053B018(0x1A91, (s32)func_L40_00421350, (s32)func_L40_00420CB0, (s32)func_L40_004208A8);
        func_L40_0053B018(0x1A1B, (s32)func_L40_003F42F0, (s32)func_L40_003F37A0, (s32)func_L40_003F4178);
        *(f32 *)(self + 0x18) = func_003BE7F0(self + 0x10, 0, 0, 0.5f) + 0.6f;
        p = D_L40_0028EBA0[*(s32 *)(v + 0x464)];
        while ((*(s32 *)(v + 0x464) & 0xFF) != 0xFF && *(s32 *)(v + 0x464) <= D_L40_00248618 && p != 0
               && (p[-1] >= 0 || p == D_L40_0028EBA0[*(s32 *)(v + 0x464)])) {
            o = D_L40_002485DC + ((*p & 0x7FFF) << 8);
            if (o == 0) {
                break;
            }
            func_L39_00619A68(o, -1);
            p++;
        }
    } else if (D_001A5E50.b168 != 0) {
        if (*(s32 *)(v + 0x2A0) == 1) {
            msg = func_L39_006699B0();
            if (msg == 0) {
                return;
            }
            q = msg + func_L39_00669978(0, func_00197588(2), D_001A5E50.w128 + 500, 0x1A91, msg);
            *(s32 *)q = (self - D_L40_002485DC) >> 8;
            q += 4;
            *(s32 *)msg = q - msg;
            *(s32 *)(v + 0x2A0) = 2;
            func_L40_0053B018(0x1A91, (s32)func_L40_00421350, (s32)func_L40_00420CB0, (s32)func_L40_004208A8);
            func_L40_0053B018(0x1A1B, (s32)func_L40_003F42F0, (s32)func_L40_003F37A0, (s32)func_L40_003F4178);
            *(s32 *)(v + 0x2B0) = 0;
            *(u16 *)(self + 0x34) &= 0xFFBE;
            *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
        }
    } else if (*(s32 *)(v + 0x2A0) == 1) {
        func_L40_0053B018(0x1A91, (s32)func_L40_00421350, (s32)func_L40_00420CB0, (s32)func_L40_004208A8);
        func_L40_0053B018(0x1A1B, (s32)func_L40_003F42F0, (s32)func_L40_003F37A0, (s32)func_L40_003F4178);
        *(s32 *)(v + 0x2B0) = 0;
        *(s32 *)(v + 0x2A0) = 2;
        *(u16 *)(self + 0x34) &= 0xFFBE;
        *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    }
    if (self[0x20] == 0x25) {
        func_003BD360(self);
        if (++*(s32 *)(v + 0x2B0) >= 0x1F5) {
            *(s32 *)(v + 0x2B0) = 0;
            self[0x20] = 0;
            *(s32 *)(v + 0x2A4) = 0;
            *(s32 *)(v + 0x2A0) = 1;
            func_00388440(v + 0x294, 0, 0x1D8);
        }
    }
    if (self[0x20] == 0x27) {
        *(s32 *)(v + 0x2B0) = 0;
        self[0x20] = 0;
        *(s32 *)(v + 0x2A4) = 0;
        *(s32 *)(v + 0x2A0) = 1;
        func_00388440(v + 0x294, 0, 0x1D8);
        msg = func_L39_006699B0();
        if (msg == 0) {
            return;
        }
        q = msg + func_L39_00669978(0, func_00197588(2), D_001A5E50.w128 + 500, 0x1A91, msg);
        *(s32 *)q = (self - D_L40_002485DC) >> 8;
        q += 4;
        *(s32 *)msg = q - msg;
        *(s32 *)(v + 0x2A0) = 2;
        func_L40_0053B018(0x1A91, (s32)func_L40_00421350, (s32)func_L40_00420CB0, (s32)func_L40_004208A8);
        func_L40_0053B018(0x1A1B, (s32)func_L40_003F42F0, (s32)func_L40_003F37A0, (s32)func_L40_003F4178);
        *(s32 *)(v + 0x2B0) = 0;
        *(u16 *)(self + 0x34) &= 0xFFBE;
        *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L40_00420328 */
