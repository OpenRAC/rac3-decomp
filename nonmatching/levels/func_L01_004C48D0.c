/* PAL near miss (opus-w4): 101 words differ with the file's flags (was 237); rewritten after the matched sibling func_L01_004C3EB8 (col = func_0038DBD8() passed to the second func_L01_00415A58 call, menu reads through the global, entries of 0x24 bytes). Left: retail saves $s0 with sq (a TImode value shares $s0 with pulse/col/the double temporary; a long long col gives the sq but on $s1), so its frame is 0x10 larger; the (f32)D_L01_001DAE44 operand is la + lwc1 0(reg) in retail (the float conversion's memory operand reloaded into a register) where every declaration tried gives lui $at + lwc1; the colors stores and two saved registers ($s3/$s4) differ with them. */
#include "common.h"
/* localdecomp:start func_L01_004C48D0 */
#include "vu0.h"
typedef struct { s32 f0; u8 p4[0x18]; u32 rgb; u8 p20[4]; } Entry_004C48D0;
typedef struct { u8 p0[4]; s32 timer; u8 p8[0x64]; s32 offset; u8 p70[0x10]; s32 selected; u8 p84[0xBC]; Entry_004C48D0 entries[42]; u8 p7A8[0x740 - 0x140 - 42 * 0x24]; s32 count; } Menu_004C48D0;
extern f32 D_L01_001E0FD0;
extern s32 D_001D4BC0, D_001D4BC4;
extern s32 D_L01_001DAE44;
void func_L01_004C48D0(void) {
    extern void func_003A9500(s32,s32,s32,s32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_00415A58(s32,s32,s32,s32,s32,s32,s32);
    extern s32 func_00396968(s32,s32);
    extern void func_00396E50(s32,s32,s32,s32,s32,u32 *);
    Menu_004C48D0 *m;
    s32 pulse, col, i, y, text, a, b;
    u32 rgb;
    u32 colors[4];
    f64 d;
    func_003A9500(58,456,(s32)(D_L01_001E0FD0*292.0f+0.5f),
       (s32)(D_L01_001E0FD0*382.0f+0.5f)+(*(s32 *)D_00143950 ? 4:0));
    { Menu_004C48D0 *o=(Menu_004C48D0 *)&D_L01_002446C0;
    if(o->offset<0) o->offset+=4;
    else if(o->offset>0) o->offset-=4; }
    m=(Menu_004C48D0 *)&D_L01_002446C0;
    pulse=abs_asm(((m->timer*4)&63)-32);
    pulse+=64;
    rgb=0x66CCFF;
    col=func_0038DBD8(0x331465B7,0,0.8f);
    func_L01_00415A58(229,(s32)(D_L01_001E0FD0*297.0f+0.5f)+(*(s32 *)D_00143950?4:0),285,(s32)(D_L01_001E0FD0*353.0f+0.5f)+(*(s32 *)D_00143950?4:0),D_001D4BC0,D_001D4BC4,(pulse*0x10202)|0x80000000);
    func_L01_00415A58(231,(s32)(D_L01_001E0FD0*299.0f+0.5f)+(*(s32 *)D_00143950?4:0),283,(s32)(D_L01_001E0FD0*351.0f+0.5f)+(*(s32 *)D_00143950?4:0),D_001D4BC0,D_001D4BC4,col);
    y=m->offset-45;
    for(i=-5;i<7;i++,y+=56) {
        s32 n=i+((Menu_004C48D0 *)&D_L01_002446C0)->selected;
        if(n>=0 && n<((Menu_004C48D0 *)&D_L01_002446C0)->count) {
            Entry_004C48D0 *e=&((Menu_004C48D0 *)&D_L01_002446C0)->entries[n];
            text=func_00396968(0xEA97,e->f0);
            d=256.0f-(f32)(y+2);
            if(d<0.0) d=0.0-d;
            a=128-(s32)(d*0.75);
            d=256.0f-(f32)(y+40);
            if(d<0.0) d=0.0-d;
            b=128-(s32)(d*0.75);
            if(a<0) a=0;
            if(b<0) b=0;
            a<<=24;
            b<<=24;
            if(e->f0==0) {
                s32 shadow;
                rgb=((Menu_004C48D0 *)&D_L01_002446C0)->entries[n].rgb;
                shadow=func_00396968(0xEA97,1);
                colors[2]=a|rgb;
                colors[0]=a|rgb;
                colors[3]=b|rgb;
                colors[1]=b|rgb;
                func_00396E50(shadow,y+2,(s32)((f32)D_L01_001DAE44*D_L01_001E0FD0+0.5f)+(*(s32 *)D_00143950?4:0),40,(s32)(D_L01_001E0FD0*40.0f+0.5f),colors);
                rgb=0xF0F0B0;
            }
            colors[2]=a|rgb;
            colors[3]=b|rgb;
            colors[0]=a|rgb;
            colors[1]=b|rgb;
            func_00396E50(text,y+2,(s32)((f32)D_L01_001DAE44*D_L01_001E0FD0+0.5f)+(*(s32 *)D_00143950?4:0),40,(s32)(D_L01_001E0FD0*40.0f+0.5f),colors);
        }
    }
}
/* localdecomp:end func_L01_004C48D0 */
