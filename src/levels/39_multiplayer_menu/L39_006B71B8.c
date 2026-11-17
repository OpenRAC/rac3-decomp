#include "common.h"

/* localdecomp:start func_L39_006B71B8 */
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

extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void func_L01_00517918(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689B80(void *);
extern void func_L39_0068AAB8(void *);
extern void func_L39_006B8458(void *);
extern void func_L39_006B8698(void *);
extern void func_L01_00480B10(s32);
__asm__(".extern D_001DDA54_sda, 4");
extern s32 D_001DDA54_sda;

void func_L39_006B71B8(S_006B71B8 *arg0) {
    f32 f;
    func_L39_0067F100(0x3D0000);
    f = 0.4f;
    func_L39_0068A9B8(0);
    func_L01_00517918(2);
    func_L39_00689BD8(arg0, func_00381FF0(0x10C7));
    func_L39_00689D28(arg0, func_00381FF0(0x124));
    func_L39_00689B80(arg0);
    func_L39_0068AAB8(arg0);
    func_L39_006B8458(arg0);
    func_L39_006B8698(arg0);
    arg0->f2A8 = 1;
    func_L01_00480B10(0xA);
    D_001DDA54_sda = 0;
    arg0->f2B4 = -1;
    arg0->f2B8 = -1;
    arg0->f110->f60->f44(arg0->f110, 1, f, 0.0f);
    arg0->f120->f60->f44(arg0->f120, 1, 0.15f, f);
}
/* localdecomp:end func_L39_006B71B8 */
