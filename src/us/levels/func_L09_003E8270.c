#include "common.h"

/* NTSC-U counterpart of func_L09_003E9FD0 (src/levels/09_tyhrranosis/L09_003E9FD0.c) */
/* localdecomp:start func_L09_003E8270 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern s32 D_L09_002D1E70[];
extern u8 *D_L09_001E011C;
extern f32 D_L09_001DFA50;
__asm__(".extern D_L09_001DF330, 8");
extern s32 D_L09_001DF330[2];
__asm__(".extern D_L09_001DF340, 8");
extern s32 D_L09_001DF340[2];
__asm__(".extern D_L09_001DF350, 8");
extern s32 D_L09_001DF350[2];
__asm__(".extern D_L09_001DF360, 8");
extern s32 D_L09_001DF360[2];
extern f32 D_L09_001DF348;
extern f32 D_L09_001DF368;
extern s32 D_L09_001F2F40[];
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L09_003E8AB0(u8 *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_00442050(u8 *, u8);
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0050DA68(void *, s32, f32);
extern s32 func_L01_0050DAC0(void);
extern void func_L01_003E6D50(s32, s32, f32, f32);
extern void func_L01_0050DB10(void);
extern void func_L09_00512408(s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_003883C8(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_004282C0(s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003BF838(void *, void *, void *, void *);

void func_L09_003E8270(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    u8 *h;

    func_L09_003E8AB0(a0);
    switch (a0[0x20]) {
    case 1:
        if (func_L01_00452EC8(a0)) {
            func_L01_004A6D70(0, a0);
            func_L01_00442050(a0, 0);
        }
        {
        s32 x = a0[0xBC];
        s16 y = x;
        u8 b;
        if (x == 0 && D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0
            && *(u8 **)(D_001A4BE0 + 0x35C) == a0 && *(s32 *)(D_001A4BE0 + 0x360) >= 2) {
            func_L01_0044F2E8(0, 9, 0x11EA, 1, 0, 0, 0);
            if (D_L09_002D1E70[0] == 9 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
                func_L01_00442050(D_L09_001E011C + (*(s32 *)(v + 0x78) << 8), 1);
                func_L01_0050DA68(a0 + 0x10, 0, D_L09_001DF368);
                func_L01_00442050(a0, 1);
            }
        } else if ((b = y) == 1) {
            if (func_L01_0050DAC0() == 2) {
                func_L01_003E6D50(0, 0, 2.5f, 0.003f);
                func_L01_0050DB10();
                func_L09_00512408(0x74, 1);
                func_L01_00441FB8(a0, 2, -1);
            } else if (a0[0xBC] == b) {
                if (func_L01_0050DAC0()) {
                    func_L01_003E6D50(0, 0, 2.5f, 0.003f);
                }
            }
        }
        }
        if (D_L09_001F2F40[0] == 1) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(a0)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.00555555569f;
            func_0039FE80(0, 4, a0);
        }
        if (func_003883C8(v + 0x74)) {
            if (D_L09_001F2F40[0] != 1) {
                func_L01_004F12C0(D_L09_001DF350, D_L09_001DF360, 0x74, 1);
                D_L09_001DFA50 = 1.5f;
                func_L01_004282C0(1, 0);
            }
            func_L01_00441FB8(a0, 3, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C) + 10.0f, *(f32 *)(v + 0x7C),
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            func_L01_003E6D50(0, 0, 2.5f, 0.003f);
            if (*(s16 *)(v + 0x74) < 60) {
                D_L09_001DFA50 += 0.05f;
                if (D_L09_001DFA50 >= 1.0f) {
                    D_L09_001DFA50 = 1.0f;
                }
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0)) {
            func_L01_004A6D70(0, a0);
            func_L01_00442050(a0, 0);
        }
        h = D_001A4BE0;
        if ((*(u8 **)(h + 0x35C) == a0 && *(s32 *)(h + 0x360) >= 2)
            || D_L09_001F2F40[0] == 2) {
            func_L01_00441FB8(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.00555555569f;
            func_0039FE80(0, 4, a0);
        }
        if (func_003883C8(v + 0x74)) {
            if (a0[0xBC] == 1) {
                func_L09_00512408(0, 1);
            }
            func_L01_00441FB8(a0, 1, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C), *(f32 *)(v + 0x7C) + 10.0f,
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            if (*(s16 *)(v + 0x74) < 0xA0) {
                D_L09_001DFA50 -= 0.05f;
                if (D_L09_001DFA50 <= 0.0f) {
                    D_L09_001DFA50 = 0.0f;
                }
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(a0)) {
            func_L01_004A6D70(0, a0);
            func_L01_00442050(a0, 0);
        }
        h = D_001A4BE0;
        if ((*(u8 **)(h + 0x35C) == a0 && *(s32 *)(h + 0x360) >= 2)
            || D_L09_001F2F40[0] == 1) {
            func_L01_00441FB8(a0, 6, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a0)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.00555555569f;
            func_0039FE80(0, 4, a0);
        }
        if (func_003883C8(v + 0x74)) {
            if (a0[0xBC] == 1) {
                func_L09_00512408(0, 1);
            }
            func_L01_00441FB8(a0, 7, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C), *(f32 *)(v + 0x7C) - 10.0f,
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            if (*(s16 *)(v + 0x74) < 0xA0) {
                D_L09_001DFA50 -= 0.05f;
                if (D_L09_001DFA50 <= 0.0f) {
                    D_L09_001DFA50 = 0.0f;
                }
            }
        }
        break;
    case 7:
        if (func_L01_00452EC8(a0)) {
            func_L01_004A6D70(0, a0);
            func_L01_00442050(a0, 0);
        }
        {
        s32 x = a0[0xBC];
        s16 y = x;
        u8 b;
        if (x == 0 && D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0
            && *(u8 **)(D_001A4BE0 + 0x35C) == a0 && *(s32 *)(D_001A4BE0 + 0x360) >= 2) {
            func_L01_0044F2E8(0, 9, 0x11EB, 1, 0, 0, 0);
            if (D_L09_002D1E70[0] == 9 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
                func_L01_00442050(D_L09_001E011C + (*(s32 *)(v + 0x78) << 8), 1);
                func_L01_0050DA68(a0 + 0x10, 0, D_L09_001DF348);
                func_L01_00442050(a0, 1);
            }
        } else if ((b = y) == 1) {
            if (func_L01_0050DAC0() == 2) {
                func_L01_003E6D50(0, 0, 2.5f, 0.003f);
                func_L01_0050DB10();
                func_L09_00512408(0x74, 1);
                func_L01_00441FB8(a0, 8, -1);
            } else if (a0[0xBC] == b) {
                if (func_L01_0050DAC0()) {
                    func_L01_003E6D50(0, 0, 2.5f, 0.003f);
                }
            }
        }
        }
        if (D_L09_001F2F40[0] == 2) {
            func_L01_00441FB8(a0, 8, -1);
        }
        break;
    case 8:
        if (func_L01_00452EC8(a0)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.00555555569f;
            func_0039FE80(0, 4, a0);
        }
        if (func_003883C8(v + 0x74)) {
            if (D_L09_001F2F40[0] != 2 && D_L09_001F2F40[0] != 0) {
                func_L01_004F12C0(D_L09_001DF330, D_L09_001DF340, 0x74, 1);
                D_L09_001DFA50 = 1.5f;
                func_L01_004282C0(2, 0);
            }
            func_L01_00441FB8(a0, 5, -1);
        } else {
            *(f32 *)(a0 + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C) - 10.0f, *(f32 *)(v + 0x7C),
                                                (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            func_L01_003E6D50(0, 0, 2.5f, 0.003f);
            if (*(s16 *)(v + 0x74) < 60) {
                D_L09_001DFA50 += 0.05f;
                if (D_L09_001DFA50 >= 1.0f) {
                    D_L09_001DFA50 = 1.0f;
                }
            }
        }
        break;
    }
    vec_sub_ba(&d, a0 + 0x10, v + 0x80);
    func_003BF838(v + 0x30, &d, a0 + 0xF0, a0 + 0xF0);
    *(vu0_v4 *)(v + 0x80) = *(vu0_v4 *)(a0 + 0x10);
}
/* localdecomp:end func_L09_003E8270 */
