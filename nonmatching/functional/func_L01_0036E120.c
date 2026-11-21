/* functional: high. Draft near miss (233 words, VU scheduling). Corrected the draft: kind=(D_L01_001DD8E0*5+2)/6 (draft had *3; asm is sll 2 + addu = x5). All constants, $gp globals, struct stores and both loops verified against PAL asm. */
#include "common.h"
/* localdecomp:start func_L01_0036E120 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern u8 D_L01_00221098[];
extern f32 D_L01_001DD8D0;
__asm__(".extern D_L01_001DD8D0, 4");
extern f32 D_L01_001DD8D4;
__asm__(".extern D_L01_001DD8D4, 4");
extern s32 D_L01_001DD8D8;
__asm__(".extern D_L01_001DD8D8, 4");
extern s32 D_L01_001DD8DC;
__asm__(".extern D_L01_001DD8DC, 4");
extern s32 D_L01_001DD8E0;
__asm__(".extern D_L01_001DD8E0, 4");
extern f32 D_L01_001DD8E4;
__asm__(".extern D_L01_001DD8E4, 4");
extern f32 D_L01_001DD8E8;
__asm__(".extern D_L01_001DD8E8, 4");
extern f32 D_L01_001DD8EC;
__asm__(".extern D_L01_001DD8EC, 4");
extern f32 D_L01_001DD8F0;
__asm__(".extern D_L01_001DD8F0, 4");
extern f32 D_L01_001DD8F4;
__asm__(".extern D_L01_001DD8F4, 4");
extern f32 D_L01_001DD8F8;
__asm__(".extern D_L01_001DD8F8, 4");
void func_L01_0036E120(u8 *object) {
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern u8 *func_L01_004660F8(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 rotation, direction, original, position, velocity, endpoint, inherited;
    f32 angle, speed, life;
    s32 i, size, kind;
    u8 *effect;
    *(vu0_q *)&original=0;
    original.x=0.3f;
    original.y=-1.0f;
    original.w=1.0f;
    func_0038D000(&original, &original, object+0xc0);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(position) : "m"(*(vu0_v4 *)(object+0x10)), "m"(original) : "vf1", "vf2");
    object[0xbc]=5;
    func_0038D890(&original, D_001A4BE0+0x6c0, D_001A4BE0+0x6d0, 0.34906584f);
    *(vu0_q *)&direction=*(vu0_q *)&original;
    angle=0.0f;
    for(i=19;i>=0;i--) {
        angle=func_0038DAB8(angle, func_003824E0(0.0f,0.62831855f));
        speed=func_003824E0(0.120000005f,0.36f);
        func_0038CE20(&velocity, &direction, speed);
        effect=func_L01_004660F8(&position, &velocity);
        if(effect) {
            func_0038CE20(&velocity, &direction, 0.75f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(vu0_v4 *)(effect+0x10)) : "m"(position), "m"(velocity) : "vf1", "vf2");
            *(vu0_q *)(effect+0x20)=*(vu0_q *)&position;
            *(f32 *)(effect+0x3c)=2.0f;
            *(u32 *)(effect+0x0c)=0x307f7f7f;
            *(f32 *)(effect+0x1c)=0.05f;
            *(f32 *)(effect+0x2c)=0.5f;
            *(u32 *)(effect+4)=0x307f7f7f;
        }
        if(fabs_asm(angle)>0.00001f) {
            func_003C4840(&rotation, D_001A4BE0+0x6c0, angle);
            func_0038D850(&direction, &original, &rotation);
        }
    }
    func_0038D890(&original, D_001A4BE0+0x6c0, D_001A4BE0+0x6d0, D_L01_001DD8D0*0.017453292f);
    *(vu0_q *)&direction=*(vu0_q *)&original;
    qzero(&inherited);
    if(*(s32 *)(D_001A4BE0+0x360)) func_0038CE20(&inherited, D_001A4BE0+0x110, 1.7f);
    angle=0.0f;
    for(i=19;i>=0;i--) {
        angle=func_0038DAB8(angle,func_003824E0(0.0f,0.62831855f));
        speed=func_003824E0(D_L01_001DD8E8*0.0200000014f, D_L01_001DD8EC*0.0200000014f);
        func_0038CE20(&velocity, &direction, speed);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(velocity) : "m"(inherited), "m"(velocity) : "vf1", "vf2");
        kind=(D_L01_001DD8E0*5+2)/6;
        size=(s32)func_L01_00443A18(1.0f,2.0f);
        endpoint.x=position.x+func_L01_00443A18(0.0f,D_L01_001DD8D4);
        endpoint.y=position.y+func_L01_00443A18(0.0f,D_L01_001DD8D4);
        endpoint.z=position.z+func_L01_00443A18(0.0f,D_L01_001DD8D4);
        life=func_003824E0(D_L01_001DD8F0,D_L01_001DD8F4);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(endpoint) : "m"(endpoint), "m"(velocity) : "vf1", "vf2");
        effect=func_L01_0046A610(&endpoint, &velocity, kind, D_L01_001DD8D8, D_L01_001DD8DC, size, life*210000.0f, D_L01_001DD8F8, D_L01_001DD8E4, 0.0f,0.0f);
        if(effect) effect[2]=**(u8 **)(D_L01_00221098+0x16c);
        if(fabs_asm(angle)>0.00001f) {
            func_003C4840(&rotation, D_001A4BE0+0x6c0, angle);
            func_0038D850(&direction, &original, &rotation);
        }
    }
}
/* localdecomp:end func_L01_0036E120 */
