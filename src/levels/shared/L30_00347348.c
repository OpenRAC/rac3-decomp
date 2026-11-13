#include "common.h"

/* localdecomp:start func_L30_00347348 */
#include "vu0.h"
typedef int Q_00347348 __attribute__((mode(TI)));
__asm__(".extern D_L30_001DCF48, 4");
extern f32 D_L30_001DCF48;
extern Q_00347348 D_L30_001E9020;
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L30_00346ED8(u8 *);
extern s32 func_L30_0034DB30(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L30_00347348(Q_00347348 *pos, f32 a) {
    u8 *m = func_003C24B0(0x15C6, 0xB0);
    u8 *v;
    if (m == 0) {
        return;
    }
    *(Q_00347348 *)(m + 0x10) = *pos;
    v = *(u8 **)(m + 0x68);
    m[0x30] = 0xFF;
    qzero(v + 0x80);
    qzero(v + 0x90);
    *(f32 *)(v + 0x90) = func_0038D098(a) * D_L30_001DCF48;
    *(f32 *)(v + 0x98) = func_0038D0B0(a) * D_L30_001DCF48;
    *(f32 *)(v + 0xA0) = a;
    func_L30_00346ED8(m);
    if (func_L30_0034DB30(m)) {
        *(Q_00347348 *)(m + 0x10) = D_L30_001E9020;
        func_L01_004450F0(m, 2, -1);
    } else {
        func_L01_004450F0(m, 1, -1);
    }
}
/* localdecomp:end func_L30_00347348 */

/* localdecomp:start func_L30_00347428 */
__asm__(".extern D_L30_001DF2C0, 4");
extern s32 D_L30_001DF2C0;
extern u8 D_001A30B0[];
extern void func_L30_00347EF0(u8 *);
extern void func_L30_00348198(u8 *);
extern s32 func_L30_00347600(u8 *);
extern void func_L30_00347FC8(u8 *);
extern s32 func_L30_0034D8D8(u8 *, f32);
extern void func_L30_003477C8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L30_00347428(u8 *moby) {
    u8 *v = *(u8 **)(moby + 0x68);
    u8 *e;
    s32 k;

    switch (moby[0x20]) {
    case 0x42:
        k = *(s32 *)(v + 0x64);
        if (k != -1 && *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) == moby && e[0xD0] != 0) {
            func_003A4F28(k);
        }
        *(s32 *)(v + 0x64) = -1;
        break;
    case 0:
        func_L30_00347EF0(moby);
        if (*(s32 *)(v + 0x6C) != 0) {
            func_L01_004450F0(moby, 3, -1);
        } else if (*(s32 *)(v + 0x68) & 1) {
            func_L01_004450F0(moby, 4, -1);
        } else {
            func_L01_004450F0(moby, 2, -1);
        }
        break;
    case 1:
        func_L30_00348198(moby);
        if (func_L30_00347600(moby)) {
            func_L01_004450F0(moby, 2, -1);
        }
        break;
    case 2:
        func_L30_00347FC8(moby);
        func_L30_00348198(moby);
        func_L30_00347600(moby);
        if (*(s32 *)(v + 0x64) == -1 || *(u8 **)((e = D_001A30B0 + (*(s32 *)(v + 0x64) << 7)) + 0xDC) != moby || e[0xD0] == 0) {
            *(s32 *)(v + 0x64) = func_003A52A0(0, 4, moby);
        }
        break;
    case 3:
        if (func_L01_00456250(moby)) {
            func_L01_004450F0(moby, 1, -1);
        }
        break;
    case 4:
        if (func_L30_0034D8D8(moby + 0x10, 1.0f) && D_L30_001DF2C0 >= 6) {
            func_L01_004450F0(moby, 2, -1);
        }
        break;
    }
    func_L30_003477C8(moby);
}
/* localdecomp:end func_L30_00347428 */

INCLUDE_ASM("asm/levels", func_L30_00347600);
