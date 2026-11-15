#include "common.h"

/* declared by functions of L39_005E20A8.c, which this file was cut from */
extern s32 *D_L39_00241120;

/* localdecomp:start func_L39_005E2140 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_005E2140;
typedef struct { u8 pad0[8]; void **f8; u8 padC[0x14]; f32 f20; f32 f24; } O_005E2140;
extern u8 D_001D82B5_sda;
extern s32 D_001DA620_sda;
extern s32 *D_L39_00241120;
extern u8 D_L39_002439C8[];
extern S_005E2140 D_L39_0024CD50;
extern void func_L01_004D2110_005E2140(s32);
extern void func_003B5060(s32);
extern s32 func_003E5090(s32);
extern s32 func_003E51F8(s32);
extern void func_003E5360(s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_005169C8(s32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516FD8(s32, void *);
extern s32 func_L01_00516C78_005E2140(s32, s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void func_003EDAD0(void *, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);

void func_L39_005E2140(s32 arg0) {
    O_005E2140 *p;
    void *q;

    func_L01_004D2110_005E2140(1);
    D_001D82B5_sda = 1;
    func_003B5060(0x40000);
    func_003E5090(0x40001);
    func_003E5090(0x40002);
    func_003E5090(0x40003);
    func_003E5090(0x40004);
    func_003E51F8(0x40009);
    func_003E51F8(0x40005);
    func_003E51F8(0x40006);
    func_003E51F8(0x40007);
    func_003E51F8(0x40008);
    func_003E51F8(0x4000A);
    func_003E5360(0x4000B);
    func_L39_00611AC8(0x40003, func_00392A18(), 0xC);
    func_L39_00611AC8(0x40004, func_00392A18(), 0xC);
    func_L39_00611AC8(0x40001, func_00392A18(), 0x6A);
    func_L39_00611AC8(0x40002, func_00392A18(), 0x6B);
    func_L01_00516470(0x40003, 0.26f, 0.841f);
    func_L01_00516470(0x40004, 0.042f, 0.841f);
    func_L01_00516470(0x40009, 0.153f, 0.874f);
    func_L01_00516470(0x40005, 0.153f, 0.826f);
    func_L01_00516470(0x40006, 0.153f, 0.84f);
    func_L01_00516470(0x40007, 0.153f, 0.908f);
    func_L01_00516470(0x40008, 0.153f, 0.9236f);
    func_L01_00517538(0x40005, 0.142f, 0.004f);
    func_L01_00517538(0x40006, 0.142f, 0.004f);
    func_L01_00517538(0x40007, 0.142f, 0.004f);
    func_L01_00517538(0x40008, 0.142f, 0.004f);
    func_L01_00517538(0x40003, 1.0f, 1.0f);
    func_L01_00517538(0x40004, -1.0f, 1.0f);
    func_L01_00517538(0x40009, 0.22f, 0.062f);
    func_L01_005169C8(0x40003, 0.03f);
    func_L01_005169C8(0x40004, 0.03f);
    func_L01_00516470(0x40001, 0.76f, 0.928f);
    func_L01_00516470(0x40002, 0.76f, 0.928f);
    func_L01_005170B8(0x40005, 0x332299DE);
    func_L01_005170B8(0x40006, 0x332299DE);
    func_L01_005170B8(0x40007, 0x332299DE);
    func_L01_005170B8(0x40008, 0x332299DE);
    func_L01_005170B8(0x40003, 0x332299DE);
    func_L01_005170B8(0x40004, 0x332299DE);
    func_L01_005170B8(0x40001, 0x332299DE);
    func_L01_005170B8(0x40002, 0x331465B7);
    func_L01_005170B8(0x40009, 0x331465B7);
    func_L01_00517538(0x40001, 1.15f, 1.15f);
    func_L01_00517538(0x40002, 1.15f, 1.15f);
    func_L01_005169C8(0x40001, 0.155f);
    func_L01_005169C8(0x40002, 0.155f);
    func_L01_005170B8(0x4000A, 0x706EC8FF);
    func_L01_00517190(0x4000A, 0xEC5A);
    if (*D_L39_00241120 == 2) {
        func_L01_00516470(0x4000A, 0.08f, 0.874f);
        func_L01_00517538(0x4000A, 0.04f, 0.04f);
        func_L01_00516470(0x4000B, 0.248f, 0.874f);
        func_L01_00517538(0x4000B, 1.0f, 1.0f);
    } else {
        func_L01_00516470(0x4000A, 0.58f, 0.93f);
        func_L01_00517538(0x4000A, 0.04f, 0.04f);
        func_L01_00516470(0x4000B, 0.76f, 0.93f);
        func_L01_00517538(0x4000B, 1.0f, 1.0f);
    }
    func_L01_005170B8(0x4000B, 0x8066CCFF);
    func_L01_00516FD8(0x4000B, D_L39_002439C8);
    func_L01_00516C78_005E2140(0x4000B, 2, 3);
    if (D_L39_0024CD50.f4 != 0) {
        q = &D_L39_0024CD50;
    } else {
        q = func_003E6C08(&D_L39_0024CD50);
    }
    p = (O_005E2140 *)func_003E6378(func_003E6DE8(q), 0x4000B);
    if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_001DA620_sda) == 0)) {
        p = 0;
    }
    func_003EDAD0(p, 0x40, 1);
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    func_003E8630(0x40000, 0x40009);
    func_003E8630(0x40000, 0x40003);
    func_003E8630(0x40000, 0x40004);
    func_003E8630(0x40000, 0x40005);
    func_003E8630(0x40000, 0x40006);
    func_003E8630(0x40000, 0x40007);
    func_003E8630(0x40000, 0x40008);
    func_003E8630(0x40000, 0x40002);
    func_003E8630(0x40000, 0x40001);
    func_003E8630(0x40000, 0x4000A);
    func_003E8630(0x40000, 0x4000B);
    func_003E8348(0x16, 0x40000);
    func_003E6FF0(arg0, 1);
    func_L01_004D2110_005E2140(0);
}
/* localdecomp:end func_L39_005E2140 */

/* localdecomp:start func_L39_005E2890 */
__asm__(".extern D_001D82B0_sda, 4");
__asm__(".extern D_001D82B4_sda, 1");
extern s32 D_001D82B0_sda;
extern u8 D_001D82B4_sda;
extern s32 *D_L39_00241120;
extern s32 D_001A5DF8[];
extern s32 D_L39_00352940[];
extern u8 D_L39_002439C8[];
extern u8 D_L39_002439D0[];
extern u8 D_L39_002439E0[];
extern u8 D_L39_0024C5E0[] __attribute__((section(".sdata")));
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_0047C4A8(s32);
extern s32 func_L39_00610490(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L01_00516FD8(s32, void *);

void func_L39_005E2890(void) {
    s32 t;
    s32 m;
    s32 s;

    if (D_001D82B0_sda != 0) {
        if (*D_L39_00241120 == 2) {
            func_L01_00516AA0(0x40002, 1, 0);
            func_L01_00516AA0(0x40001, 1, 0);
            func_L01_00516AA0(0x40005, 1, 1);
            func_L01_00516AA0(0x40006, 1, 1);
            func_L01_00516AA0(0x40007, 1, 1);
            func_L01_00516AA0(0x40008, 1, 1);
            func_L01_00516AA0(0x40009, 1, 1);
            func_L01_00516AA0(0x40003, 1, 1);
            func_L01_00516AA0(0x40004, 1, 1);
        } else {
            func_L01_00516AA0(0x40002, 1, 1);
            func_L01_00516AA0(0x40001, 1, 1);
            func_L01_00516AA0(0x40005, 1, 0);
            func_L01_00516AA0(0x40006, 1, 0);
            func_L01_00516AA0(0x40007, 1, 0);
            func_L01_00516AA0(0x40008, 1, 0);
            func_L01_00516AA0(0x40009, 1, 0);
            func_L01_00516AA0(0x40003, 1, 0);
            func_L01_00516AA0(0x40004, 1, 0);
        }
        D_001D82B0_sda--;
    } else {
        func_L01_00516AA0(0x40000, 1, 0);
        D_001D82B4_sda = 1;
    }
    if (D_001D82B4_sda == 0) {
        if (func_L39_00610490(func_L01_0047C4A8(0)) == 1) {
            t = D_L39_00352940[0] - (D_001A5DF8[0] - D_L39_00352940[1]);
            if (t < 0) {
                t = 0;
            }
            m = t / 60000;
            s = (t % 60000) / 1000;
            func_00120048(D_L39_0024C5E0, D_L39_002439D0, (m < 10) ? D_L39_002439E0 : D_L39_002439C8, m, (s < 10) ? D_L39_002439E0 : D_L39_002439C8, s);
            func_L01_00516FD8(0x4000B, D_L39_0024C5E0);
        }
    }
}
/* localdecomp:end func_L39_005E2890 */
