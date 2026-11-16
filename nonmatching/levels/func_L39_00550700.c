/* NTSC-U draft (Codex wave 3): C of func_L39_0054FDD8, the NTSC-U twin of func_L39_00550700, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 174 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0054FDD8", whose code is not the PAL one).
 * Worker's note: 174 diff; best log func_L39_0054FDD8.check1.log; verified allowed GNU assembler literal-pool loads for 1/60 and .025 versus retail inline lui/ori/mtc1; unlisted @ps2as not tried; additional scheduling/VU0 differences; retail div nop counts 2 0 2
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_0054FDD8 */
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L39_00646268(void *, s32);
extern u8 D_L39_0049C950[];
extern void func_L39_005F08F8(void *, s32);
extern void func_L39_005BA378(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00346CF8(void *, void *);
extern s32 D_001DF9D0_sda;
extern s32 *D_001D5A10_sda;
extern void func_L39_00551618(void *);
extern s32 func_L39_00550418(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L39_00550D60(void *, void *);
extern void func_L39_00550C98(void *);
u8 *func_L39_0054FDD8(vu0_q *position, vu0_q *velocity, u8 *owner, s32 value, s32 kind, s32 arg5, vu0_q *target) {
    u8 *m;
    u8 *p;
    u8 *settings;
    vu0_v4 direction;
    vu0_q old;
    vu0_v4 point;
    s32 i;
    m=func_003BCFB0(0x1097,0x60);
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
            *(f32 *)(p+0x50)=func_L01_0040C018(p+0x10,p+0x20);
        }
        if (func_L39_00646268(owner,3))
            settings=D_L39_0049C950+((s8 *)D_L39_0049C950)[0x1A1]*0x80;
        else
            settings=D_L39_0049C950+0x180;
        *(s16 *)(p+0x42)=(s16)(190.0f/(*(f32 *)(settings+0x24)*(1.0f/60.0f)));
        *(f32 *)(p+0x44)=1.0f / *(s16 *)(p+0x42);
        *(s16 *)(p+0x32)=40;
        p[0x39]=arg5;
        *(f32 *)(p+0x34)=0.025f;
        *(s32 *)(p+0x4C)=value;
        *(s16 *)(p+0x30)=0;
        p[0x38]=kind;
        *(s32 *)(m+0x98)=0;
        *(s32 *)(m+0x90)=*(s32 *)owner;
        *(u16 *)(m+0x34)=(*(u16 *)(m+0x34)|0x41)&0xEFFF;
        func_L39_005F08F8(m,1);
        func_L39_005BA378(m+0x10,&direction,1);
        func_003886E8(&direction,&direction,-1.0f);
        func_L01_00346CF8(m,&direction);
        if ((u32)D_001DF9D0_sda>=10) D_001DF9D0_sda=0;
        p[0x3A]=((u8 *)&D_001DF9D0_sda)[0];
        D_001DF9D0_sda=(D_001DF9D0_sda+1)%10;
        func_L39_00551618(m);
        if (kind==1 || (owner && !owner[0x1A14])) {
            old=*position;
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(vu0_v4 *)(m+0x10)) : "m"(*(vu0_v4 *)position), "m"(*(vu0_v4 *)velocity) : "vf1", "vf2");
            if (func_L39_00550418(m,&old)) m[0x20]=2;
            if (p[0x38]!=1 && *D_001D5A10_sda==1) {
                for (i=0;i<10;i++) {
                    func_003886C0(&point,&old,m+0x10,(f32)i/10.0f);
                    func_L39_00550D60(m,&point);
                }
            }
            func_L39_00550C98(m);
        }
    }
    return m;
}
/* localdecomp:end func_L39_0054FDD8 */
