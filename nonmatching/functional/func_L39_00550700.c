/* functional: high. PAL twin of the NTSC draft: spawns the multiplayer-menu projectile object (0x1097) and initialises its state; PAL constants verified (frame step 0.02, +0.5 rounding on the 190/(speed*step) lifetime, 33 steps, 1/33 factor, which differ from NTSC); callees renamed to PAL addresses; lqc2/vadd.xyz/sqc2 kept as VU0 asm; 177 words differ (register allocation/scheduling). */
#include "common.h"
#include "vu0.h"
extern u8 *func_003C24B0(s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_00648AE0(void *, s32);
extern u8 D_L39_0049C890[];
extern void func_L39_005F2FF8(void *, s32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00347640(void *, void *);
extern s32 D_001DFA40;
extern s32 *D_001D5A10;
extern void func_L39_00551F68(void *);
extern s32 func_L39_00550D48(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L39_005516B0(void *, void *);
extern void func_L39_005515E8(void *);
u8 *func_L39_00550700(vu0_q *position, vu0_q *velocity, u8 *owner, s32 value, s32 kind, s32 arg5, vu0_q *target) {
    u8 *m;
    u8 *p;
    u8 *settings;
    vu0_v4 direction;
    vu0_q old;
    vu0_v4 point;
    s32 i;
    m=func_003C24B0(0x1097,0x60);
    if (m) {
        p=*(u8 **)(m+0x68);
        *(u8 **)(p+0x3C)=owner;
        m[0x30]=255;
        *(s16 *)(m+0x32)=255;
        m[0x31]=1;
        m[0x20]=0;
        *(vu0_q *)(m+0x10)=*position;
        *(vu0_q *)p=*velocity;
        *(vu0_q *)(p+0x10)=*position;
        if (target) {
            *(s16 *)(p+0x40)=1;
            *(vu0_q *)(p+0x20)=*target;
            *(f32 *)(p+0x50)=func_L01_0040E548(p+0x10,p+0x20);
        }
        if (func_L39_00648AE0(owner,3))
            settings=D_L39_0049C890+((s8 *)D_L39_0049C890)[0x1A1]*0x80;
        else
            settings=D_L39_0049C890+0x180;
        *(s16 *)(p+0x42)=(s16)(190.0f/(*(f32 *)(settings+0x24)*0.02f)+0.5f);
        *(f32 *)(p+0x44)=1.0f / *(s16 *)(p+0x42);
        *(s16 *)(p+0x32)=33;
        p[0x39]=arg5;
        *(f32 *)(p+0x34)=0.030303031f;
        *(s32 *)(p+0x4C)=value;
        *(s16 *)(p+0x30)=0;
        p[0x38]=kind;
        *(s32 *)(m+0x98)=0;
        *(s32 *)(m+0x90)=*(s32 *)owner;
        *(u16 *)(m+0x34)=(*(u16 *)(m+0x34)|0x41)&0xEFFF;
        func_L39_005F2FF8(m,1);
        func_L39_005BC330(m+0x10,&direction,1);
        func_0038CE20(&direction,&direction,-1.0f);
        func_L01_00347640(m,&direction);
        if ((u32)D_001DFA40>=10) D_001DFA40=0;
        p[0x3A]=((u8 *)&D_001DFA40)[0];
        D_001DFA40=(D_001DFA40+1)%10;
        func_L39_00551F68(m);
        if (kind==1 || (owner && !owner[0x1A14])) {
            old=*position;
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(vu0_v4 *)(m+0x10)) : "m"(*(vu0_v4 *)position), "m"(*(vu0_v4 *)velocity) : "vf1", "vf2");
            if (func_L39_00550D48(m,&old)) m[0x20]=2;
            if (p[0x38]!=1 && *D_001D5A10==1) {
                for (i=0;i<10;i++) {
                    func_0038CDF8(&point,&old,m+0x10,(f32)i/10.0f);
                    func_L39_005516B0(m,&point);
                }
            }
            func_L39_005515E8(m);
        }
    }
    return m;
}
