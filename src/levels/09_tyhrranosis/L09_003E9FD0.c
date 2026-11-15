#include "common.h"

/* localdecomp:start func_L09_003E9FD0 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern s32 D_L09_002D1E30[];
extern u8 *D_L09_001E009C;
extern f32 D_L09_001DF9D0;
__asm__(".extern D_L09_001DF2F0, 8");
extern s32 D_L09_001DF2F0[2];
__asm__(".extern D_L09_001DF300, 8");
extern s32 D_L09_001DF300[2];
__asm__(".extern D_L09_001DF310, 8");
extern s32 D_L09_001DF310[2];
__asm__(".extern D_L09_001DF320, 8");
extern s32 D_L09_001DF320[2];
extern f32 D_L09_001DF308;
extern f32 D_L09_001DF328;
extern s32 D_L09_001F2EC0[];
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L09_003EA810(u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_00445188(u8 *, u8);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern s32 func_L01_00511A98(void);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_00511AE8(void);
extern void func_L09_005164C0(s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_0038CB00(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0042B068(s32, s32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L09_003E9FD0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    u8 *h;

    func_L09_003EA810(a0);
    switch (a0[0x20]) {
    case 1:
        if (func_L01_004561B8(a0)) {
            func_L01_004AA760(0, a0);
            func_L01_00445188(a0, 0);
        }
        {
        s32 x = a0[0xBC];
        s16 y = x;
        u8 b;
        if (x == 0 && D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0
            && *(u8 **)(D_001A4BE0 + 0x35C) == a0 && *(s32 *)(D_001A4BE0 + 0x360) >= 2) {
            func_L01_00452560(0, 9, 0x11EA, 1, 0, 0, 0);
            if (D_L09_002D1E30[0] == 9 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
                func_L01_00445188(D_L09_001E009C + (*(s32 *)(v + 0x78) << 8), 1);
                func_L01_00511A40(a0 + 0x10, 0, D_L09_001DF328);
                func_L01_00445188(a0, 1);
            }
        } else if ((b = y) == 1) {
            if (func_L01_00511A98() == 2) {
                func_L01_003E8BD0(0, 0, 2.5f, 0.003f);
                func_L01_00511AE8();
                func_L09_005164C0(0x74, 1);
                func_L01_004450F0(a0, 2, -1);
            } else if (a0[0xBC] == b) {
                if (func_L01_00511A98()) {
                    func_L01_003E8BD0(0, 0, 2.5f, 0.003f);
                }
            }
        }
        }
        if (D_L09_001F2EC0[0] == 1) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            *(s16 *)(v + 0x74) = 150;
            *(f32 *)(v + 0x70) = 0.006666667f;
            func_003A52A0(0, 4, a0);
        }
        if (func_0038CB00(v + 0x74)) {
            if (D_L09_001F2EC0[0] != 1) {
                func_L01_004F50C8(D_L09_001DF310, D_L09_001DF320, 0x74, 1);
                D_L09_001DF9D0 = 1.5f;
                func_L01_0042B068(1, 0);
            }
            func_L01_004450F0(a0, 3, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003C3BE8(*(f32 *)(v + 0x7C) + 10.0f, *(f32 *)(v + 0x7C),
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            func_L01_003E8BD0(0, 0, 2.5f, 0.003f);
            if (*(s16 *)(v + 0x74) < 50) {
                D_L09_001DF9D0 += 0.060000002f;
                if (D_L09_001DF9D0 >= 1.0f) {
                    D_L09_001DF9D0 = 1.0f;
                }
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            func_L01_004AA760(0, a0);
            func_L01_00445188(a0, 0);
        }
        h = D_001A4BE0;
        if ((*(u8 **)(h + 0x35C) == a0 && *(s32 *)(h + 0x360) >= 2)
            || D_L09_001F2EC0[0] == 2) {
            func_L01_004450F0(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            *(s16 *)(v + 0x74) = 150;
            *(f32 *)(v + 0x70) = 0.006666667f;
            func_003A52A0(0, 4, a0);
        }
        if (func_0038CB00(v + 0x74)) {
            if (a0[0xBC] == 1) {
                func_L09_005164C0(0, 1);
            }
            func_L01_004450F0(a0, 1, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003C3BE8(*(f32 *)(v + 0x7C), *(f32 *)(v + 0x7C) + 10.0f,
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            if (*(s16 *)(v + 0x74) < 0x85) {
                D_L09_001DF9D0 -= 0.060000002f;
                if (D_L09_001DF9D0 <= 0.0f) {
                    D_L09_001DF9D0 = 0.0f;
                }
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(a0)) {
            func_L01_004AA760(0, a0);
            func_L01_00445188(a0, 0);
        }
        h = D_001A4BE0;
        if ((*(u8 **)(h + 0x35C) == a0 && *(s32 *)(h + 0x360) >= 2)
            || D_L09_001F2EC0[0] == 1) {
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            *(s16 *)(v + 0x74) = 150;
            *(f32 *)(v + 0x70) = 0.006666667f;
            func_003A52A0(0, 4, a0);
        }
        if (func_0038CB00(v + 0x74)) {
            if (a0[0xBC] == 1) {
                func_L09_005164C0(0, 1);
            }
            func_L01_004450F0(a0, 7, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003C3BE8(*(f32 *)(v + 0x7C), *(f32 *)(v + 0x7C) - 10.0f,
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            if (*(s16 *)(v + 0x74) < 0x85) {
                D_L09_001DF9D0 -= 0.060000002f;
                if (D_L09_001DF9D0 <= 0.0f) {
                    D_L09_001DF9D0 = 0.0f;
                }
            }
        }
        break;
    case 7:
        if (func_L01_004561B8(a0)) {
            func_L01_004AA760(0, a0);
            func_L01_00445188(a0, 0);
        }
        {
        s32 x = a0[0xBC];
        s16 y = x;
        u8 b;
        if (x == 0 && D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0
            && *(u8 **)(D_001A4BE0 + 0x35C) == a0 && *(s32 *)(D_001A4BE0 + 0x360) >= 2) {
            func_L01_00452560(0, 9, 0x11EB, 1, 0, 0, 0);
            if (D_L09_002D1E30[0] == 9 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
                func_L01_00445188(D_L09_001E009C + (*(s32 *)(v + 0x78) << 8), 1);
                func_L01_00511A40(a0 + 0x10, 0, D_L09_001DF308);
                func_L01_00445188(a0, 1);
            }
        } else if ((b = y) == 1) {
            if (func_L01_00511A98() == 2) {
                func_L01_003E8BD0(0, 0, 2.5f, 0.003f);
                func_L01_00511AE8();
                func_L09_005164C0(0x74, 1);
                func_L01_004450F0(a0, 8, -1);
            } else if (a0[0xBC] == b) {
                if (func_L01_00511A98()) {
                    func_L01_003E8BD0(0, 0, 2.5f, 0.003f);
                }
            }
        }
        }
        if (D_L09_001F2EC0[0] == 2) {
            func_L01_004450F0(a0, 8, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(a0)) {
            *(s16 *)(v + 0x74) = 150;
            *(f32 *)(v + 0x70) = 0.006666667f;
            func_003A52A0(0, 4, a0);
        }
        if (func_0038CB00(v + 0x74)) {
            if (D_L09_001F2EC0[0] != 2 && D_L09_001F2EC0[0] != 0) {
                func_L01_004F50C8(D_L09_001DF2F0, D_L09_001DF300, 0x74, 1);
                D_L09_001DF9D0 = 1.5f;
                func_L01_0042B068(2, 0);
            }
            func_L01_004450F0(a0, 5, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003C3BE8(*(f32 *)(v + 0x7C) - 10.0f, *(f32 *)(v + 0x7C),
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            func_L01_003E8BD0(0, 0, 2.5f, 0.003f);
            if (*(s16 *)(v + 0x74) < 50) {
                D_L09_001DF9D0 += 0.060000002f;
                if (D_L09_001DF9D0 >= 1.0f) {
                    D_L09_001DF9D0 = 1.0f;
                }
            }
        }
        break;
    }
    vec_sub_ba(&d, a0 + 0x10, v + 0x80);
    func_003C4DA8(v + 0x30, &d, a0 + 0xF0, a0 + 0xF0);
    *(vu0_v4 *)(v + 0x80) = *(vu0_v4 *)(a0 + 0x10);
}
/* localdecomp:end func_L09_003E9FD0 */
