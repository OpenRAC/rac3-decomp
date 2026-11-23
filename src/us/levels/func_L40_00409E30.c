#include "common.h"

/* NTSC-U counterpart of func_L40_0040A4D0 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18D];
    s8 f18D;
} S_0040A4D0;
typedef struct {
    u8 pad0[0x88];
    s32 f88[1];
} S_0040A4D0t;

/* localdecomp:start func_L40_00409E30 */
__asm__(".extern D_L40_002473C4, 4");
extern s32 D_L40_002473C4;
extern S_0040A4D0 *D_L40_002417C0;
extern u8 *D_L40_002485DC;
extern u8 *D_L40_003575EC[];
extern s32 D_001A5F78[];

extern void func_003BD360(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_003BDA38(u8*m, s32 a1, void*pos);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_L39_005F08F8(void *, s32);
extern void func_L39_00619A68(void *, s32);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8*msg);
extern u8*func_L39_006699B0(void);
extern s32 func_00197588(s32);
extern s32 func_L40_0053B018(s32, void *, void *, void *);
extern s32 func_L40_0053CF40(s32);
extern void func_L40_0040B638(u8 *m);
extern void func_L40_0040A500(u8*m);
extern u8*func_L40_0040A350(s32 a0, s32 a1, u8*msg);

void func_L40_00409E30(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 c;
    u8 *t;
    if (*(s32 *)(v + 0x2B8) == -1 && m[0x20] == 0) {
        if (D_L40_002417C0->f18D == 0) {
            func_003BD360(m);
            return;
        }
        func_L39_00619A68(m, -1);
        func_L40_0053B018(0x109F, func_L40_0040B638, func_L40_0040A500, func_L40_0040A350);
        m[0x20] = 0x26;
        *(s32 *)(v + 0x348) = 2;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(m, 1);
        if (*(u8 **)(v + 0x270) != 0) {
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            func_L39_005F08F8(*(u8 **)(v + 0x270), 1);
        }
        return;
    }
    if (*(s32 *)(v + 0x348) == 0) {
        if (D_L40_002417C0->f18D == 0) {
            func_003BD360(m);
            return;
        }
        func_L39_00619A68(m, -1);
        func_L40_0053B018(0x109F, func_L40_0040B638, func_L40_0040A500, func_L40_0040A350);
        *(s32 *)(v + 0x348) = 1;
        m[0x30] = 0xFF;
        c = *(s32 *)(v + 0x2F0);
        if ((u32)c >= 2) {
            c = D_L40_002473C4;
        } else {
            c = ((S_0040A4D0t *)D_L40_003575EC[0])->f88[*(s32 *)(v + 0x2B8)];
        }
        t = *(u8 **)(v + 0x270);
        if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD) {
            u8 *n = func_003BCFB0(0x109E, 0);
            *(u8 **)(v + 0x270) = n;
            if (n != 0) {
                func_L01_00452E70(n, m);
            }
        }
        *(f32 *)(m + 0x18) = func_003BE7F0(m + 0x10, 0, 0, 0.5f);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
        func_003BDA38(m, 0, *(u8 **)(v + 0x270) + 0x10);
        m[0x7E] = ((m[0x7E] | 0x80) & 0x8F) | (c << 4);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(m, 1);
        if (*(u8 **)(v + 0x270) != 0) {
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            func_L39_005F08F8(*(u8 **)(v + 0x270), 1);
        }
    } else if (func_L40_0053CF40((m - D_L40_002485DC) >> 8) != 0) {
        if (*(s32 *)(v + 0x348) == 1) {
            u8 *msg;
            u8 *q;

            msg = (u8 *)func_L39_006699B0();
            if (msg == 0) {
                return;
            }
            q = msg + func_L39_00669978(0, func_00197588(2), D_001A5F78[0] + 0x1F4, 0x109F, msg);
            *(s32 *)q = (m - D_L40_002485DC) >> 8;
            q += 4;
            *(s32 *)q = *(s32 *)(v + 0x2B8);
            q += 4;
            *(s32 *)msg = q - msg;
            *(s32 *)(v + 0x348) = 2;
            func_L40_0053B018(0x109F, func_L40_0040B638, func_L40_0040A500, func_L40_0040A350);
        }
    } else if (*(s32 *)(v + 0x348) == 1) {
        *(s32 *)(v + 0x348) = 2;
        func_L40_0053B018(0x109F, func_L40_0040B638, func_L40_0040A500, func_L40_0040A350);
    }

    if (m[0x20] == 0x25) {
        *(s32 *)(v + 0x2CC) = 0;
        if (*(s32 *)(v + 0x3D8) < ++*(s32 *)(v + 0x34C)) {
            s32 idx;
            s32 r = func_003CF790(m + 0x10, 1, 0, 0, 2.0f);
            *(s32 *)(v + 0x3D8) += 0x258;
            if (r == 0) {
                m[0x20] = 0;
                *(s32 *)(v + 0x360) = 0;
                idx = (m - D_L40_002485DC) >> 8;
                *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
                *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
                if (func_L40_0053CF40(idx) != 0) {
                    u8 *msg;
                    u8 *q;

                    msg = (u8 *)func_L39_006699B0();
                    if (msg == 0) {
                        return;
                    }
                    q = msg + func_L39_00669978(0, func_00197588(2), D_001A5F78[0] + 0x1388, 0x109F, msg);
                    *(s32 *)q = (m - D_L40_002485DC) >> 8;
                    q += 4;
                    *(s32 *)q = *(s32 *)(v + 0x2B8);
                    q += 4;
                    *(s32 *)msg = q - msg;
                }
            }
        }
    }
    if (m[0x20] == 0x27) {
        u8 *msg;
        u8 *q;

        *(s32 *)(v + 0x2CC) = 0;
        *(s32 *)(v + 0x34C) += 1;
        m[0x20] = 0;
        *(s32 *)(v + 0x360) = 0;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
        msg = (u8 *)func_L39_006699B0();
        if (msg == 0) {
            return;
        }
        q = msg + func_L39_00669978(0, func_00197588(2), D_001A5F78[0] + 0x1388, 0x109F, msg);
        *(s32 *)q = (m - D_L40_002485DC) >> 8;
        q += 4;
        *(s32 *)q = *(s32 *)(v + 0x2B8);
        q += 4;
        *(s32 *)msg = q - msg;
    }
}
/* localdecomp:end func_L40_00409E30 */
