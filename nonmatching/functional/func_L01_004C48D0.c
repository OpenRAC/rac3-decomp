/* functional: medium. mostly addressing and stack-copy form differences */
#include "common.h"
/* localdecomp:start func_L01_004C48D0 */
#include "vu0.h"
extern f32 D_L01_001E0FD0;
extern s32 D_001D4BC0, D_001D4BC4;
extern s32 D_L01_001DAE44;
__asm__(".extern D_L01_001E0FD0, 16");
__asm__(".extern D_001D4BC0, 16");
__asm__(".extern D_001D4BC4, 16");
__asm__(".extern D_L01_001DAE44, 16");
void func_L01_004C48D0(void) {
    extern void func_003A9500(s32,s32,s32,s32);
    extern void func_0038DBD8(u32,s32,f32);
    extern void func_L01_00415A58(s32,s32,s32,s32,s32,s32,u32);
    extern s32 func_00396968(s32,s32);
    extern void func_00396E50(s32,s32,s32,s32,s32,u32 *);
    u32 colors[4];
    s32 i;
    s32 y;
    s32 pulse;
    u32 rgb;
    s32 pos;
    s32 index;
    s32 texture;
    s32 top, bottom;
    double distance;
    u8 *base = (u8 *)&D_L01_002446C0;
    func_003A9500(0x3A,456,(s32)(D_L01_001E0FD0*292.0f+0.5f),
        (s32)(D_L01_001E0FD0*382.0f+0.5f)+(*(s32 *)D_00143950 ? 4:0));
    if (*(s32 *)(base+0x6C)<0) *(s32 *)(base+0x6C)+=4;
    else if (*(s32 *)(base+0x6C)>0) *(s32 *)(base+0x6C)-=4;
    pulse=(*(s32 *)(base+4)<<2 & 0x3F)-32;
    pulse=abs_asm(pulse)+64;
    rgb=0x66CCFF;
    func_0038DBD8(0x331465B7,0,0.8f);
    pulse*=0x10202;
    func_L01_00415A58(229,(s32)(D_L01_001E0FD0*297.0f+0.5f)+(*(s32 *)D_00143950 ? 4:0),
        285,(s32)(D_L01_001E0FD0*353.0f+0.5f)+(*(s32 *)D_00143950 ? 4:0),
        D_001D4BC0,D_001D4BC4,pulse|0x80000000);
    func_L01_00415A58(231,(s32)(D_L01_001E0FD0*299.0f+0.5f)+(*(s32 *)D_00143950 ? 4:0),
        283,(s32)(D_L01_001E0FD0*351.0f+0.5f)+(*(s32 *)D_00143950 ? 4:0),
        D_001D4BC0,D_001D4BC4,pulse);
    y=*(s32 *)(base+0x6C)-45;
    for(i=-5;i<7;i++,y+=56) {
        index=*(s32 *)(base+0x80)+i;
        if(index<0 || index>=*(s32 *)(base+0x740)) continue;
        pos=index*0x24;
        texture=func_00396968(0xEA97,*(s32 *)(base+0x140+pos));
        distance=(double)(256.0f-(f32)(y+2));
        if(distance<0.0) distance=0.0-distance;
        top=128-(s32)(distance*0.75);
        distance=(double)(256.0f-(f32)(y+40));
        if(distance<0.0) distance=0.0-distance;
        bottom=128-(s32)(distance*0.75);
        if(top<0) top=0;
        if(bottom<0) bottom=0;
        top<<=24;
        bottom<<=24;
        if(*(s32 *)(base+0x140+pos)==0) {
            rgb=*(u32 *)(base+0x15C+pos);
            {
                s32 shadow=func_00396968(0xEA97,1);
                colors[0]=top|rgb;
                colors[1]=bottom|rgb;
                colors[2]=top|rgb;
                colors[3]=bottom|rgb;
                func_00396E50(shadow,y+2,(s32)((f32)D_L01_001DAE44*D_L01_001E0FD0+0.5f)+(*(s32 *)D_00143950?4:0),
                    40,(s32)(D_L01_001E0FD0*40.0f+0.5f),colors);
            }
            rgb=0xF0F0B0;
        }
        colors[0]=top|rgb;
        colors[1]=bottom|rgb;
        colors[2]=top|rgb;
        colors[3]=bottom|rgb;
        func_00396E50(texture,y+2,(s32)((f32)D_L01_001DAE44*D_L01_001E0FD0+0.5f)+(*(s32 *)D_00143950?4:0),
            40,(s32)(D_L01_001E0FD0*40.0f+0.5f),colors);
    }
}
/* localdecomp:end func_L01_004C48D0 */
