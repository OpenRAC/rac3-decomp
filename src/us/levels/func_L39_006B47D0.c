#include "common.h"

/* NTSC-U counterpart of func_L39_006B71B8 (src/levels/39_multiplayer_menu/L39_006B71B8.c) */
/* localdecomp:start func_L39_006B47D0 */
typedef struct V_006B71B8 {
    char _p0[0x44];
    void (*f44)(void *, s32, f32, f32);
} V_006B71B8;
typedef struct O_006B71B8 {
    char _p0[0x60];
    V_006B71B8 *f60;
} O_006B71B8;
typedef struct S_006B71B8 {
    char _p0[0x110];
    O_006B71B8 *f110;
    char _p1[0xC];
    O_006B71B8 *f120;
    char _p2[0x184];
    s32 f2A8;
    char _p3[8];
    s32 f2B4;
    s32 f2B8;
} S_006B71B8;

extern void func_L39_0067C5E0(s32);
extern void func_L39_00687E10(s32);
extern void func_L01_00513928(s32);
extern s32 func_0037DF98(s32);
extern void func_L39_00687030(void *, s32);
extern void func_L39_00687180(void *, s32);
extern void func_L39_00686FD8(void *);
extern void func_L39_00687F10(void *);
extern void func_L39_006B5A50(void *);
extern void func_L39_006B5C90(void *);
extern void func_L01_0047D2B0(s32);
__asm__(".extern D_001DDA14_sda, 4");
extern s32 D_001DDA14_sda;

void func_L39_006B47D0(S_006B71B8 *arg0) {
    f32 f;
    func_L39_0067C5E0(0x3D0000);
    f = 0.4f;
    func_L39_00687E10(0);
    func_L01_00513928(2);
    func_L39_00687030(arg0, func_0037DF98(0x10C7));
    func_L39_00687180(arg0, func_0037DF98(0x124));
    func_L39_00686FD8(arg0);
    func_L39_00687F10(arg0);
    func_L39_006B5A50(arg0);
    func_L39_006B5C90(arg0);
    arg0->f2A8 = 1;
    func_L01_0047D2B0(0xA);
    D_001DDA14_sda = 0;
    arg0->f2B4 = -1;
    arg0->f2B8 = -1;
    (*(V_006B71B8 **)((u8 *)arg0->f110 + 0x60))->f44(arg0->f110, 1, f, 0.0f);
}
/* localdecomp:end func_L39_006B47D0 */
