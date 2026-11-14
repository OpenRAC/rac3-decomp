#include "common.h"
/* localdecomp:start func_L24_0034A1B8 */
extern s32 func_L24_0034AAE0(void *);
extern void func_L24_0034B238(void *), func_L24_0034B3B8(void *), func_L24_0034B4F8(void *), func_L24_0034BE50(void *), func_L24_0034AD88(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_003154D8(void *, s32, s32);
extern s32 func_0037E208(s32, s32), func_0037E1D8(s32);
extern void func_003BEBF8(void *, f32, f32);
extern void func_L01_00457440(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00458A08(void *, f32);
extern f32 func_L01_00436500(void *);
extern s32 D_001DD3DC_sda, D_001DD3E0_sda;
__asm__(".extern D_001DD3DC_sda, 4");
__asm__(".extern D_001DD3E0_sda, 4");
extern struct { u8 pad[0x80]; f32 x, y; } D_001A4BE0;
extern u8 D_001A4C60[];
void func_L24_0034A1B8(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    if (func_L24_0034AAE0(m)) return;
    if (!*(s32 *)(p + 0x588)) {
        func_L24_0034B238(m);
        func_L24_0034B3B8(m);
        func_L24_0034B4F8(m);
        return;
    }
    switch (m[0x95]) {
    case 0:
        if (*(s16 *)(p + 0x234) == 1) {
            *(f32 *)(p + 0x584) = 0.5f;
            if (m[0x43] != 5) func_003BE4F0(m, 5, 0, 5);
            func_L01_00441FB8(m, 3, 2);
        } else if (*(s32 *)(p + 0x4b8)) {
            func_L01_00441FB8(m, 2, 1);
            *(s32 *)(p + 0x4b8) = 0;
            if (*(s32 *)(p + 0x4b0) < 300) *(s32 *)(p + 0x4b0) = func_0037E208(480, 600);
        }
        break;
    case 1:
        if (*(s16 *)(p + 0x234) == 1) func_L01_00441FB8(m, 5, 2);
        else if (!*(s32 *)(p + 0x4b0)) func_L01_00441FB8(m, 1, 0);
        break;
    case 2:
        break;
    case 3:
        func_003BEBF8(p + 0x584, 0.6f, 0.03333333507f);
        if (m[0x60] & 2) {
            func_L24_0034AD88(m);
            func_L01_003154D8(m, 0, 0);
            return;
        }
        break;
    }
    switch (m[0x20]) {
    case 1: break;
    case 2: break;
    case 3:
if (m[0x60] & 2) {
if (m[0x43] != 2) func_003BE4F0(m, 2, 0, 5);
func_L01_00441FB8(m, 5, -1);
D_001DD3DC_sda = 0;
}
        break;
    case 4:
func_003BEBF8(p + 0x584, 0.6f, 0.03333333507f);
func_L01_00457440(m, D_001A4C60);
func_L01_00441FB8(m, 5, -1);
if (m[0x43] != 2) func_003BE4F0(m, 2, 0, 6);
if (!func_0037E1D8(4)) {
if (m[0x43] != 15) func_003BE4F0(m, 15, 0, 6);
}
        break;
    case 5:
func_L01_00458A08(m, func_00388A28(D_001A4BE0.x-*(f32 *)(m+0x10), D_001A4BE0.y-*(f32 *)(m+0x14)));
func_003BEBF8(p + 0x584, 1.6f, 0.02916666865f);
if (m[0x60] & 2) {
func_L01_00441FB8(m, 6, -1);
if (m[0x43] != 7) func_003BE4F0(m, 7, 0, 10);
if (D_001DD3DC_sda) {
if (m[0x43] != 6) func_003BE4F0(m, 6, 0, 10);
func_L01_00441FB8(m, 7, -1);
if (D_001DD3DC_sda == 2 && func_0037E1D8(10)) {
 if (m[0x43] != func_0037E1D8(2)+4) func_003BE4F0(m, func_0037E1D8(2)+4, 0, 10);
}
}
}
        break;
    case 7:
if (func_L01_00436500(m) < 125.0f && (m[0x42] == 6 || m[0x43] == 6)) {
func_003BEBF8(p + 0x584, 0.0f, 0.06666667014f);
} else if (m[0x42] == 6) {
func_003BEBF8(p + 0x584, 0.6f, 0.06666667014f);
} else {
func_003BEBF8(p + 0x584, 0.6f, 0.6666666865f);
}
if (m[0x60]&2) {
if (m[0x43] != 5) func_003BE4F0(m, 5, 0, 5);
func_L01_00441FB8(m, 3, 2);
}
        break;
    case 6:
func_003BEBF8(p + 0x584, 0.5f, 0.1333333403f);
if (m[0x60]&2) {
 if (m[0x42] == 7) {
func_L01_00441FB8(m, 8, -1);
if (m[0x43] != 11) func_003BE4F0(m, 11, 0, 10);
} else if (D_001DD3DC_sda == 2) {
if (m[0x43] != 5) func_003BE4F0(m, 5, 0, 5);
func_L01_00441FB8(m, 3, 2);
} else {
func_L01_00441FB8(m, 4, -1);
if (m[0x43] != 1) func_003BE4F0(m, 1, 0, 10);
}
}
        break;
    case 8:
func_003BEBF8(p + 0x584, 0.6f, 0.03333333507f);
if(m[0x60]&2) {
if (m[0x43] != 8) func_003BE4F0(m, 8, 0, 10);
func_L01_00441FB8(m, 9, -1);
D_001DD3DC_sda = 1;
}
        break;
    case 9:
func_L01_00458A08(m, func_00388A28(D_001A4BE0.x-*(f32 *)(m+0x10), D_001A4BE0.y-*(f32 *)(m+0x14)));
if (*(f32 *)(p+0x58c)+3.0f < *(f32 *)(m+0x18)) {
if (m[0x43] != 10) func_003BE4F0(m, 10, 0, 10);
func_L01_00441FB8(m, 12, -1);
if(D_001DD3E0_sda) {
if (m[0x43] != 9) func_003BE4F0(m, 9, 0, 10);
}
} else *(f32 *)(m+0x18) += 0.1666666716f;
        break;
    case 12:
func_L01_00458A08(m, func_00388A28(D_001A4BE0.x-*(f32 *)(m+0x10), D_001A4BE0.y-*(f32 *)(m+0x14)));
if (func_L01_00436500(m) < 19.0f) {
func_003BEBF8(p + 0x584, 0.7f, 0.05000000447f);
} else {
func_003BEBF8(p + 0x584, 2.0f, 0.3f);
}
if (m[0x60]&2) {
func_L01_00441FB8(m, 11, -1);
if (m[0x43] != 13) func_003BE4F0(m, 13, 0, 10);
if (D_001DD3E0_sda) {
if (m[0x43] != 14) func_003BE4F0(m, 14, 0, 10);
}
}
        break;
    case 11:
func_L01_00458A08(m, func_00388A28(D_001A4BE0.x-*(f32 *)(m+0x10), D_001A4BE0.y-*(f32 *)(m+0x14)));
func_003BEBF8(p + 0x584, 0.6f, 0.1000000089f);
if(m[0x60]&2) {
if (m[0x43] != 8) func_003BE4F0(m, 8, 0, 5);
func_L01_00441FB8(m, 9, -1);
if(D_001DD3E0_sda) {
func_L01_00441FB8(m, 10, -1);
}
D_001DD3E0_sda = 1;
}
        break;
    case 10:
func_003BEBF8(p + 0x584, 0.5f, 0.03333333507f);
func_L01_00458A08(m, func_00388A28(D_001A4BE0.x-*(f32 *)(m+0x10), D_001A4BE0.y-*(f32 *)(m+0x14)));
if (*(f32 *)(m+0x18) <= *(f32 *)(p+0x58c)) {
if (m[0x43] != 12) func_003BE4F0(m, 12, 0, 10);
func_L01_00441FB8(m, 13, -1);
} else *(f32 *)(m+0x18) -= 0.1000000089f;
        break;
    case 13:
if(m[0x60]&2) {
if (m[0x43] != 5) func_003BE4F0(m, 5, 0, 10);
func_L01_00441FB8(m, 6, -1);
}
        break;
    }
    func_L24_0034B238(m);
    func_L24_0034B3B8(m);
    func_L24_0034B4F8(m);
    func_L24_0034BE50(m);
}
/* localdecomp:end func_L24_0034A1B8 */
