#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;
typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;
typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;
typedef void (*Fn_003B52B0)(u8 *, s32);

extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);
extern s32 func_L01_003B3548(u8 *);

/* localdecomp:start func_L01_003B4840 */
__asm__(".extern D_L01_001DE64C, 4");
__asm__(".extern D_L01_001DE650, 4");
__asm__(".extern D_L01_001DE654, 4");
__asm__(".extern D_L01_001DE658, 4");
__asm__(".extern D_L01_001DE65C, 4");
__asm__(".extern D_L01_001DE660, 4");
__asm__(".extern D_L01_001DE664, 4");
__asm__(".extern D_L01_001DE668, 4");
__asm__(".extern D_L01_001DE66C, 4");
__asm__(".extern D_L01_001DE670, 4");
__asm__(".extern D_L01_001DE674, 4");
__asm__(".extern D_L01_001DE678, 4");
__asm__(".extern D_L01_001DE67C, 4");
__asm__(".extern D_L01_001DE680, 4");
__asm__(".extern D_L01_001DE684, 4");
__asm__(".extern D_L01_001DE688, 4");
__asm__(".extern D_L01_001DE68C, 4");
__asm__(".extern D_L01_001DE690, 4");
__asm__(".extern D_L01_001DE694, 4");
extern f32 D_L01_001DE64C;
extern f32 D_L01_001DE650;
extern f32 D_L01_001DE654;
extern f32 D_L01_001DE658;
extern f32 D_L01_001DE65C;
extern f32 D_L01_001DE660;
extern f32 D_L01_001DE664;
extern f32 D_L01_001DE668;
extern f32 D_L01_001DE66C;
extern f32 D_L01_001DE670;
extern f32 D_L01_001DE674;
extern f32 D_L01_001DE678;
extern f32 D_L01_001DE67C;
extern f32 D_L01_001DE680;
extern f32 D_L01_001DE684;
extern f32 D_L01_001DE688;
extern f32 D_L01_001DE68C;
extern f32 D_L01_001DE690;
extern f32 D_L01_001DE694;
typedef struct { u8 pad0[8]; void **f8; u8 padC[0x14]; f32 f20; f32 f24; } O_003B4840;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003B4840;
extern S_003B4840 D_L01_001E15E0;
extern u8 D_L01_001DE720[];
extern s32 D_L01_001DC1E0;
extern void func_L01_00516468_003B4840(s32);
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E5360(s32);
extern void func_003E51F8(s32);
extern s32 func_00392A18(void);
extern void func_L01_00517448(s32, s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_005169C8(s32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516FD8(s32, void *);
extern void func_L01_00516B90(s32, s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void func_003EDAD0(void *, s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_003B4818(void *a, u8 *b);

void func_L01_003B4840(u8 *a0, u8 *a1) {
    O_003B4840 *p;
    void *q;

    if (*(s32 *)(a1 + 0x24) == 0) {
        return;
    }
    func_L01_00516468_003B4840(1);
    func_003B5060(0x140000);
    func_003E5090(0x140001);
    func_003E5090(0x140002);
    func_003E51F8(0x140003);
    func_003E5360(0x140004);
    if (func_L01_003B4818(a0, a1)) {
        func_003E51F8(0x140005);
        func_003E51F8(0x140006);
        func_003E5360(0x140007);
    }
    func_L01_00517448(0x140001, func_00392A18(), 0x6A);
    func_L01_00517448(0x140002, func_00392A18(), 0x6B);
    func_L01_00516470(0x140001, D_L01_001DE64C, D_L01_001DE650);
    func_L01_00516470(0x140002, D_L01_001DE64C, D_L01_001DE650);
    if (func_L01_003B4818(a0, a1)) {
        func_L01_005169C8(0x140001, D_L01_001DE680);
        func_L01_005169C8(0x140002, D_L01_001DE680);
    } else {
        func_L01_005169C8(0x140001, D_L01_001DE65C);
        func_L01_005169C8(0x140002, D_L01_001DE65C);
    }
    func_L01_005170B8(0x140001, 0x332299DE);
    func_L01_005170B8(0x140002, 0x331465B7);
    func_L01_00517538(0x140001, D_L01_001DE654, D_L01_001DE658);
    func_L01_00517538(0x140002, D_L01_001DE654, D_L01_001DE658);
    func_L01_00516470(0x140003, D_L01_001DE660, D_L01_001DE664);
    func_L01_005170B8(0x140003, 0x706EC8FF);
    func_L01_00517538(0x140003, D_L01_001DE668, D_L01_001DE66C);
    func_L01_00517190(0x140003, 0xEC5A);
    func_L01_00516470(0x140004, D_L01_001DE670, D_L01_001DE674);
    func_L01_005170B8(0x140004, 0x8066CCFF);
    func_L01_00517538(0x140004, D_L01_001DE678, D_L01_001DE67C);
    func_L01_00516FD8(0x140004, D_L01_001DE720);
    func_L01_00516B90(0x140004, 2, 3);
    if (D_L01_001E15E0.f4 != 0) { q = &D_L01_001E15E0; } else { q = func_003E6C08(); }
    p = (O_003B4840 *)func_003E6378(func_003E6DE8(q), 0x140004);
    if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0) == 0)) { p = 0; }
    func_003EDAD0(p, 0x40, 1);
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    func_003E8630(0x140000, 0x140002);
    func_003E8630(0x140000, 0x140001);
    func_003E8630(0x140000, 0x140003);
    func_003E8630(0x140000, 0x140004);
    if (func_L01_003B4818(a0, a1)) {
        func_L01_00516470(0x140005, D_L01_001DE684, D_L01_001DE674);
        func_L01_00517538(0x140005, D_L01_001DE688, D_L01_001DE68C);
        func_L01_005170B8(0x140005, 0x332299DE);
        func_L01_00516B90(0x140005, 3, 3);
        func_L01_00516470(0x140006, D_L01_001DE694, D_L01_001DE664);
        func_L01_005170B8(0x140006, 0x706EC8FF);
        func_L01_00517538(0x140006, D_L01_001DE668, D_L01_001DE66C);
        func_L01_00517190(0x140006, 0xED55);
        func_L01_00516470(0x140007, D_L01_001DE690, D_L01_001DE674);
        func_L01_005170B8(0x140007, 0x8066CCFF);
        func_L01_00517538(0x140007, D_L01_001DE678, D_L01_001DE67C);
        func_L01_00516FD8(0x140007, D_L01_001DE720);
        func_L01_00516B90(0x140007, 3, 3);
        if (D_L01_001E15E0.f4 != 0) { q = &D_L01_001E15E0; } else { q = func_003E6C08(); }
        p = (O_003B4840 *)func_003E6378(func_003E6DE8(q), 0x140007);
        if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0) == 0)) { p = 0; }
        func_003EDAD0(p, 0x40, 1);
        p->f20 = 0.005f;
        p->f24 = 0.005f;
        func_003E8630(0x140000, 0x140005);
        func_003E8630(0x140000, 0x140006);
        func_003E8630(0x140000, 0x140007);
    }
    func_003E8348(0, 0x140000);
    func_L01_00516468_003B4840(0);
}
/* localdecomp:end func_L01_003B4840 */
