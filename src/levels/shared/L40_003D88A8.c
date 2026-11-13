#include "common.h"

/* localdecomp:start func_L40_003D88A8 */
typedef struct {
    u8 pad0[0x18D];
    s8 f18D;
} S_003D88A8g;

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
    u8 pad9C[0x64];
} S_003D88A8m;

extern S_003D88A8g *D_00241640;
__asm__(".extern D_00241640, 16");
extern u8 *D_L40_0024845C_003D88A8;
__asm__(".extern D_L40_0024845C_003D88A8, 4");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern s32 D_L40_00242930;
__asm__(".extern D_L40_00242930, 16");
extern s32 D_001A5DF8[];
extern s32 D_001A5E00 __attribute__((section(".data")));

extern void func_003C2880(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L39_005F33E0(s32, s32, void *);
extern void func_L39_0061C1E0(void *, s32);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);
extern s32 *func_L39_0066C2B8(void);
extern s32 func_00197498(s32);
extern s32 func_L40_0053D8C8(s32, void *, void *, void *);
extern s32 func_L40_0053F7F0(s32);
extern void func_L40_003D9530(u8 *);
extern void func_L40_003D9160(u8 *);
extern void func_L40_003D8E88(void);
extern void func_L40_003EC320(void);
extern void func_L40_003EBEA0(void);
extern void func_L40_003EBCD8(void);

void func_L40_003D88A8(u8 *moby) {
    u8 *pv = *(u8 **)(moby + 0x68);
    S_003D88A8m *m;

    if (*(s32 *)(pv + 0x1A0) == -1 && moby[0x20] == 0) {
        if (D_00241640->f18D == 0) {
            if (*(s32 *)(pv + 0x1D0) != -1) {
                func_003C2880(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8));
            }
            func_003C2880(moby);
            return;
        }
        func_L39_0061C1E0(moby, -1);
        moby[0x20] = 0x26;
        *(s32 *)(pv + 0x1B0) = 2;
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        if (*(s32 *)(pv + 0x1D0) != -1) {
            func_L39_0061C1E0(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8), -1);
        }
        *(u16 *)(moby + 0x34) = (*(u16 *)(moby + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(moby + 0x98) = 0;
        func_L39_005F2FF8(moby, 1);
        return;
    }
    if (*(s32 *)(pv + 0x1B0) == 0) {
        if (D_00241640->f18D == 0) {
            if (*(s32 *)(pv + 0x1D0) != -1) {
                func_003C2880(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8));
            }
            func_003C2880(moby);
            return;
        }
        func_L39_0061C1E0(moby, -1);
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        *(s32 *)(pv + 0x1B0) = 1;
        *(f32 *)(moby + 0x18) = func_003C3D30(moby + 0x10, 0, 0, 0.5f);
        *(s32 *)(moby + 0x98) = 0;
        *(u16 *)(moby + 0x34) = (*(u16 *)(moby + 0x34) | 0x41) & 0xEFFF;
        moby[0x30] = 0xFF;
        func_L39_005F2FF8(moby, 1);
        if (*(s32 *)(pv + 0x1D0) != -1) {
            func_L39_0061C1E0(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8), -1);
            m = (S_003D88A8m *)D_L40_0024845C;
            m[*(s32 *)(pv + 0x1D0)].f34 |= 0x41;
            m[*(s32 *)(pv + 0x1D0)].f34 &= 0xEFFF;
            m[*(s32 *)(pv + 0x1D0)].f98 = 0;
            func_L39_005F2FF8((u8 *)m + (*(s32 *)(pv + 0x1D0) << 8), 1);
        }
    } else if (func_L40_0053F7F0((moby - D_L40_0024845C_003D88A8) >> 8) != 0) {
        if (*(s32 *)(pv + 0x1B0) == 1) {
            if (*(s32 *)(pv + 0x1D8) == 1 && D_001A5E00 >= 3) {
                func_003C2880(moby);
                return;
            }
            {
            u8 *msg = (u8 *)func_L39_0066C2B8();
            u8 *q;
            s32 off;

            if (msg == 0) {
                return;
            }
            off = ((s32 (*)(s32, s32, s32, s32, void *))func_L39_0066C280)(0, func_00197498(2), D_001A5DF8[0] + 0x1F4, 0x19F6, msg);
            q = msg + off;
            *(s32 *)q = (moby - D_L40_0024845C) >> 8;
            q += 4;
            *(s32 *)msg = q - msg;
            }
            *(s32 *)(pv + 0x1B0) = 2;
            func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
            func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
            *(s32 *)(pv + 0x1C0) = 0;
            *(u16 *)(moby + 0x34) &= 0xFFBE;
            *(u16 *)(moby + 0x34) |= *(u16 *)(*(u8 **)(moby + 0x24) + 0x44) & 0x1000;
            *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
        }
    } else if (*(s32 *)(pv + 0x1B0) == 1) {
        if (*(s32 *)(pv + 0x1D8) == 1 && D_001A5E00 >= 3) {
            func_003C2880(moby);
            return;
        }
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        *(s32 *)(pv + 0x1C0) = 0;
        *(s32 *)(pv + 0x1B0) = 2;
        *(u16 *)(moby + 0x34) &= 0xFFBE;
        *(u16 *)(moby + 0x34) |= *(u16 *)(*(u8 **)(moby + 0x24) + 0x44) & 0x1000;
        *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
    }

    if (moby[0x20] == 0x25) {
        func_L01_00451FE0(moby, 0xF, (u8 *)&D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23,
                          3.0f, 7.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        ((s32 (*)(s32, s32, u8 *))func_L39_005F33E0)(2, 0, moby);
        func_003C2880(moby);
        if (++*(s32 *)(pv + 0x1C0) >= 0x1A2) {
            *(s32 *)(pv + 0x1C0) = 0;
            moby[0x20] = 0;
            *(s32 *)(pv + 0x1B4) = 0;
            *(s32 *)(pv + 0x1B0) = 1;
            func_0038CB78(pv + 0x1A4, 0, 0x48);
        }
    }
    if (moby[0x20] == 0x27) {
        *(s32 *)(pv + 0x1C0) = 0;
        moby[0x20] = 0;
        *(s32 *)(pv + 0x1B4) = 0;
        *(s32 *)(pv + 0x1B0) = 1;
        func_0038CB78(pv + 0x1A4, 0, 0x48);
        {
        u8 *msg = (u8 *)func_L39_0066C2B8();
        u8 *q;
        s32 off;

        if (msg == 0) {
            return;
        }
        off = ((s32 (*)(s32, s32, s32, s32, void *))func_L39_0066C280)(0, func_00197498(2), D_001A5DF8[0] + 0x1F4, 0x19F6, msg);
        q = msg + off;
        *(s32 *)q = (moby - D_L40_0024845C) >> 8;
        q += 4;
        *(s32 *)msg = q - msg;
        }
        *(s32 *)(pv + 0x1B0) = 2;
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        *(s32 *)(pv + 0x1C0) = 0;
        *(u16 *)(moby + 0x34) &= 0xFFBE;
        *(u16 *)(moby + 0x34) |= *(u16 *)(*(u8 **)(moby + 0x24) + 0x44) & 0x1000;
        *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L40_003D88A8 */
