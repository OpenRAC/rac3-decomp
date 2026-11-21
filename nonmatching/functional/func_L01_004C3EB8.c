/* functional: high. regalloc/scheduling only (18 diff lines, same instruction multiset) */
#include "common.h"
/* localdecomp:start func_L01_004C3EB8 */
#include "vu0.h"
typedef struct { u8 p0[4]; s32 timer; u8 p8[0x64]; s32 offset; u8 p70[0x10]; s32 selected; u8 p84[0xBC]; s32 entries[96][4]; s32 count; } Menu_004C3EB8;
extern f32 D_L01_001E0FD0;
extern s32 D_001D4BC0, D_001D4BC4;
extern s32 D_L01_00244800[][4];
void func_L01_004C3EB8(void) {
    extern void func_003A9500(s32,s32,s32,s32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_00415A58(s32,s32,s32,s32,s32,s32,s32);
    extern s32 func_00396968(s32,s32);
    extern void func_00396E50(s32,s32,s32,s32,s32,u32 *);
    G_4BFEA0 *m;
    s32 pulse, col, i, y, text, a, b;
    u32 colors[4];
    f64 d;
    func_003A9500(58,426,(s32)(D_L01_001E0FD0*120.0f+0.5f)+176,
       (s32)(D_L01_001E0FD0*185.0f+0.5f)+(*(s32 *)D_00143950 ? 180:176));
    { Menu_004C3EB8 *o=(Menu_004C3EB8 *)&D_L01_002446C0;
    if(o->offset<0) o->offset+=4;
    else if(o->offset>0) o->offset-=4; }
    m=(G_4BFEA0 *)&D_L01_002446C0;
    pulse=abs_asm(((m->w4*4)&63)-32);
    pulse+=64;
    if(m->ent[m->sel].val>0) {
        col=func_0038DBD8(0x331465B7,0,0.8f);
        func_L01_00415A58(229,(s32)(D_L01_001E0FD0*299.0f+0.5f)+(*(s32 *)D_00143950?4:0),285,(s32)(D_L01_001E0FD0*355.0f+0.5f)+(*(s32 *)D_00143950?4:0),D_001D4BC0,D_001D4BC4,(pulse*0x10202)|0x80000000);
        func_L01_00415A58(231,(s32)(D_L01_001E0FD0*301.0f+0.5f)+(*(s32 *)D_00143950?4:0),283,(s32)(D_L01_001E0FD0*353.0f+0.5f)+(*(s32 *)D_00143950?4:0),D_001D4BC0,D_001D4BC4,col);
    }
    y=*(s32 *)((u8 *)m+0x6C)-61;
    { Menu_004C3EB8 *loop=(Menu_004C3EB8 *)&D_L01_002446C0;
    for(i=-3;i<5;i++,y+=56) {
        s32 n=i+loop->selected;
        s32 draw_y=y+130;
        if(n>=0 && n<loop->count) {
            u32 rgb=0x66CCFF;
            text=func_00396968(D_L01_00244800[n][0],0);
            d=128.0f-(f32)(y+2);
            if(d<0.0) d=0.0-d;
            a=128-(s32)(d*0.75);
            d=128.0f-(f32)(y+40);
            if(d<0.0) d=0.0-d;
            b=128-(s32)(d*0.75);
            if(a<0) a=0;
            if(b<0) b=0;
            a<<=24;
            b<<=24;
            colors[2]=colors[0]=a|rgb;
            colors[3]=colors[1]=b|rgb;
            func_00396E50(text,draw_y,(s32)(D_L01_001E0FD0*305.0f+0.5f)+(*(s32 *)D_00143950?6:2),40,(s32)(D_L01_001E0FD0*40.0f+0.5f),colors);
        }
    }
    }
}
/* localdecomp:end func_L01_004C3EB8 */
