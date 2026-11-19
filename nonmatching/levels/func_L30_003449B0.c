/* PAL near miss: 101 diff with the file's flags plus -mvu0-use-vf0-vf2 (add it to the L30_00344610.c line; the line is already @ps2as), 240 before (round 12, s4).
 * What moved it: the three hand-written lqc2/vsub/vadd/sqc2 asm blocks are vec_sub_ba / vec_add_ba / vec_sub_ba from vu0.h
 * (240 -> 121; the vf numbers of the VU0 words match retail's now), and func_L01_003303B8 declared `s32` instead of `void`
 * (it returns its first argument; moves the `lui 0x101` constant of the stack arguments from $v1 to $v0 as in retail: 115 -> 101).
 * Left: (1) `whole = (s32)quotient;` in case 8 compiles to cvt.w.s / mfc1 / mtc1 / nop / cvt.s.w, retail has only
 * `cvt.w.s $f0,$f12; cvt.s.w $f0,$f0` (no GPR round trip): 4 words and a shift of everything after it, about 80 of the 101
 * diffs. A study-only asm `cvt.w.s %0,%1; cvt.s.w %0,%0` gives 12 diff (2 of them the jump table's %hi/%lo). The same pair is
 * why func_L32_003BE098, func_L33_003453C8, func_L16_00345E98, func_L32_003B37A8 and others stay at 100+: a vu0.h-style
 * helper for it (the compiler cannot emit it; retail has it in many functions) would unlock them; the maintainers decide.
 * (2) the order of the three stores of `s->f1A8 = s->f160 = s->f1A4 = func_L03_0034B148(...)` in case 10: retail stores
 * 0x1a8 and 0x160 before the call to func_0038CAD0 and 0x1a4 in its delay slot; all 6 chain orders and 6 separate-statement
 * orders were tried (12-15 diff with the asm study).
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L30_003449B0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003449B0;
typedef int Q_003449B0 __attribute__((mode(TI)));
extern s32 D_L30_001DCEDC;
extern f32 D_L30_001DCED8;
__asm__(".extern D_L30_001DCEDC, 4");
__asm__(".extern D_L30_001DCED8, 4");
void func_L30_003449B0(M_00344610 *m) {
    extern s32 func_L01_004561B8(void *);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CE68(void *,void *);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_004450F0(void *,s32,s32);
    extern void func_L01_004AA7E8(void *,s32);
    extern s32 func_0038CAD0(void *);
    extern f32 func_L03_0034B148(s32,s32,f32);
    extern void func_L30_00343798(void *,f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_L05_00328FF8(void *);
    extern s32 func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,
        s32,s32,s32,s32,s32,s32,
        s32,s32,s32,s32,s32,s32,
        s32,s32,s32,s32,s32,s32);
    S_00344610 *s=m->p68;
    V_003449B0 v,delta;
    V_003449B0 *vp, *dp;
    f32 phase, quotient, whole;
    switch (m->b20) {
    case 6:
        if (func_L01_004561B8(m)) {
            *(s32 *)((u8 *)m+0xf4)=0;
            *(s32 *)((u8 *)s+0x164)=0;
            s->f160=0;
            if (m->hAA==0x19b9) func_003A52A0(2,0,m);
            if (m->hAA==0x1745) func_003A52A0(5,0,m);
        }
        *(f32 *)((u8 *)s+0x164)+=*(f32 *)((u8 *)s+0x170);
        if (*(f32 *)((u8 *)s+0x178)<*(f32 *)((u8 *)s+0x164)) *(f32 *)((u8 *)s+0x164)=*(f32 *)((u8 *)s+0x178);
        s->f160+=*(f32 *)((u8 *)s+0x164);
        if (1.0f<s->f160) s->f160=1.0f;
        vp=&v;
        vec_sub_ba(vp, (u8 *)s+0x150, (u8 *)s+0x140);
        func_0038CE20(vp,vp,s->f160);
        dp=&delta;
        vec_add_ba((u8 *)s+0x130, (u8 *)s+0x140, vp);
        vec_sub_ab(dp, (u8 *)s+0x150, (u8 *)s+0x130);
        if (func_0038CE68(vp,dp)<0.0f || func_0038CEA8(dp)<0.001f) func_L01_004450F0(m,7,-1);
        break;
    case 7:
        if (func_L01_004561B8(m)) {
            if (m->hAA==0x1745) func_003A52A0(2,0,m);
            if (m->hAA==0x19b9) func_003A52A0(3,0,m);
            s->f180=s->f18C;
            func_L01_003303B8((u8 *)m+0x10,1,25,20,20,20,45,2,1.0f,0.0f,0.0f,2.0f,
                1,1,1,0,1,0,0x1010000,0,0x388ef7,0x63f7,0x407fff,0x20ff,0x8fff,0x3064ff,0x7f60a0ff,0x280000ff,0x3064ff,0);
            m->f98=0;
            m->h34=(m->h34|0x41)&0xefff;
            func_L01_004AA7E8(m,1);
        }
        if (func_0038CAD0(&s->f180)) func_L01_004450F0(m,10,-1);
        break;
    case 8:
        if (func_L01_004561B8(m)) {
            s->f180=s->f17C;
            if (m->hAA==0x1745) func_003A52A0(3,0,m);
            if (m->hAA==0x19b9) func_003A52A0(1,0,m);
        }
        s->f160=0;
        func_L30_00343798(m,s->f160);
        quotient=(f32)D_L30_001DF2C0/(f32)D_L30_001DCEDC;
        whole=(s32)quotient;
        phase=(quotient-whole)*6.283185482025146484375f;
        *(f32 *)((u8 *)m+0xf4)=D_L30_001DCED8*func_0038D0B0(phase);
        if (func_0038CAD0(&s->f180)) func_L01_004450F0(m,6,-1);
        break;
    case 9:
        s->f160=0;
        func_L30_00343798(m,s->f160);
        if (func_L05_00328FF8(m)) func_L01_004450F0(m,8,-1);
        break;
    case 10:
        if (func_L01_004561B8(m)) {
            *(Q_003449B0 *)((u8 *)s+0x130)=*(Q_003449B0 *)((u8 *)s+0x140);
            s->f180=s->f190;
            s->f160=0;
            if (m->hAA==0x1745) func_003A52A0(1,0,m);
            m->h34 &= 0xffbe;
            m->h34 |= *(u16 *)(m->p24+0x44)&0x1000;
            m->f98=*(s32 *)(m->p24+0x10);
        }
        if (s->f160<0.25f) m->f98=0;
        else m->f98=*(s32 *)(m->p24+0x10);
        s->f1A8=s->f160=s->f1A4=func_L03_0034B148(s->f180,s->f190,0.0f);
        if (func_0038CAD0(&s->f180)) {
            s->f1A8=s->f1A4=1.0f;
            func_L01_004450F0(m,9,-1);
        }
        break;
    }
}
/* localdecomp:end func_L30_003449B0 */
