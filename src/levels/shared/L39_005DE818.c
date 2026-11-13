#include "common.h"

/* localdecomp:start func_L39_005DE818 */
struct W_005DE818;
typedef struct { u8 pad0[0x10]; s32 (*fn10)(struct W_005DE818 *, void *); } V_005DE818;
typedef struct W_005DE818 { u8 pad0[8]; V_005DE818 *vt; u8 padC[0x50 - 0xC]; s32 f50; } W_005DE818;
typedef struct { u8 pad0[4]; s32 f4; } S_005DE818;
extern u8 D_001D8204_sda;
extern void *D_001DA5F0_sda;
extern u8 D_L39_0049A0E0[];
extern S_005DE818 D_L39_0024CD50[];
extern s32 *D_L39_00241120;
extern void func_L01_004D2110_005DE818(s32);
extern void func_003B5060(s32);
extern void func_003E51F8(s32);
extern void func_003E82F8(s32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void *func_003E6C08();
extern void *func_003E6DE8(void *);
extern W_005DE818 *func_003E6378(void *, s32);
extern s32 func_003B43B0(s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);

void func_L39_005DE818(s32 arg0) {
    void *base;
    S_005DE818 *list;
    W_005DE818 *p;
    D_001D8204_sda = 1;
    func_L01_004D2110_005DE818(1);
    func_003B5060(0x80000);
    func_003E51F8(0x80001);
    func_003E51F8(0x80002);
    func_003E51F8(0x80003);
    func_003E82F8((*D_L39_00241120 < 2) ? 0 : 4);

    func_L01_005170B8(0x80001, (D_L39_0049A0E0[3] << 24) | (D_L39_0049A0E0[2] << 16) | (D_L39_0049A0E0[1] << 8) | D_L39_0049A0E0[0]);
    func_L01_00516470(0x80001, 0.8333333f, 0.25f);
    func_L01_00517538(0x80001, -0.3333333f, -0.5f);
    list = D_L39_0024CD50;
    if (list->f4) base = list;
    else base = func_003E6C08();
    p = func_003E6378(func_003E6DE8(base), 0x80001);
    if (p == 0 || p->vt->fn10(p, D_001DA5F0_sda) == 0) p = 0;
    p->f50 = func_003B43B0(1);
    func_L01_00517190(0x80001, 1);

    func_L01_005170B8(0x80002, (D_L39_0049A0E0[3] << 24) | (D_L39_0049A0E0[2] << 16) | (D_L39_0049A0E0[1] << 8) | D_L39_0049A0E0[0]);
    func_L01_00516470(0x80002, 0.16666667f, 0.75f);
    func_L01_00517538(0x80002, 0.33333334f, 0.5f);
    list = D_L39_0024CD50;
    if (list->f4) base = list;
    else base = func_003E6C08();
    p = func_003E6378(func_003E6DE8(base), 0x80002);
    if (p == 0 || p->vt->fn10(p, D_001DA5F0_sda) == 0) p = 0;
    p->f50 = func_003B43B0(2);
    func_L01_00517190(0x80002, 1);

    func_L01_005170B8(0x80003, (D_L39_0049A0E0[3] << 24) | (D_L39_0049A0E0[2] << 16) | (D_L39_0049A0E0[1] << 8) | D_L39_0049A0E0[0]);
    func_L01_00516470(0x80003, 0.75f, 0.95f);
    func_L01_00517538(0x80003, 0.5f, 0.9f);
    list = D_L39_0024CD50;
    if (list->f4) base = list;
    else base = func_003E6C08();
    p = func_003E6378(func_003E6DE8(base), 0x80003);
    if (p == 0 || p->vt->fn10(p, D_001DA5F0_sda) == 0) p = 0;
    p->f50 = func_003B43B0(1);
    func_L01_00517190(0x80003, 1);

    func_003E8630(0x80000, 0x80001);
    func_003E8630(0x80000, 0x80002);
    func_003E8630(0x80000, 0x80003);
    func_003E8348(0, 0x80000);
    func_003E6FF0(arg0, 1);
    func_L01_004D2110_005DE818(0);
}
/* localdecomp:end func_L39_005DE818 */
