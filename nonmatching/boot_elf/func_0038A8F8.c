/* PAL near miss (Codex wave 7): near miss: 142 words differ with the file's flags.
 * Worker's note: 142 diff; register allocation and scheduling remain; best log build/codex/w349/logs/func_0038A8F8.wrap8.log; ten compiles
 */
#include "common.h"
/* localdecomp:start func_0038A8F8 */
typedef struct { u8 pad[0x34]; s32 time; u8 pad38[0x14]; u8 *data; } State_0038A8F8;
typedef struct { u8 pad[0xA]; s16 x, width, height; u8 pad10[2]; u16 flags; u8 tail[0xC]; } Text_0038A8F8;
extern State_0038A8F8 D_00225700_0038A8F8;
extern s32 D_001D4BC4_0038A8F8;
extern u8 D_00143950_0038A8F8[] __attribute__((section(".sdata")));
void func_0038A8F8(void) {
    extern void func_00391240(s32,s32,u32,u8 *,s32);
    extern void func_00391390(s32,s32,u32,u8 *,s32);
    extern void func_003914A0(s16 *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_00391510(Text_0038A8F8 *,u32,u8 *,s32);
    extern s32 func_0011B868();
    extern void func_0038C790(s32,s32,s32,s32,s32,s32);
    Text_0038A8F8 text;
    s32 language, row;
    u8 *p,*end;
    if (D_00225700_0038A8F8.data == 0) return;
    {
    u8 *settings=D_00143950_0038A8F8;
    language=0;
    if (settings[0xB7]==5) language=settings[0xB7]-2;
    else if (settings[0xB7]==4) language=settings[0xB7];
    else if ((u8)(settings[0xB7]-2)<4) language=settings[0xB7]-1;
    }
    end=D_00225700_0038A8F8.data+*(s16 *)(D_00225700_0038A8F8.data+4);
    for (p=D_00225700_0038A8F8.data,row=208; p<end; p+=18) {
        s32 now=D_00225700_0038A8F8.time;
        s32 begin=(*(s16 *)p*5+2)/6;
        s32 finish;
        s16 *offsets;
        s32 y,alpha,col,half,width,height;
        u32 color;
        u8 *str;
        if (now<begin) continue;
        finish=(*(s16 *)(p+2)*5+2)/6;
        if (finish<now) continue;
        offsets=(s16 *)(p+4);
        str=D_00225700_0038A8F8.data+offsets[language];
        if (D_00143950_0038A8F8[6]==0 && (D_00225700_0038A8F8.data+offsets[language])[0]!=42) continue;
        if ((D_00225700_0038A8F8.data+offsets[language])[0]==42) {
            u32 special=0xB0000000;
            y=64;
            if ((D_00225700_0038A8F8.data+offsets[language])[1]!=42) y=D_001D4BC4_0038A8F8-200;
            else if (D_00143950_0038A8F8[0xAD]) y=24;
            finish=(*(s16 *)(p+2)*5+2)/6;
            now=D_00225700_0038A8F8.time;
            if (finish-now<18) special=(finish-(now-1))<<27;
            else {
                begin=(*(s16 *)p*5+2)/6;
                if (now-begin<18) special=(now-(begin-1))<<27;
            }
            str=D_00225700_0038A8F8.data+offsets[language];
            if((D_00225700_0038A8F8.data+offsets[language])[1]!=42) { func_00391240(256,row,special|0xE0E0E0,D_00225700_0038A8F8.data+offsets[language]+1,-1); row+=20; }
            else func_00391390(32,y,special|0xE0E0E0,D_00225700_0038A8F8.data+offsets[language]+2,-1);
        } else {
            y=D_00143950_0038A8F8[0xAD] ? D_001D4BC4_0038A8F8-54 : D_001D4BC4_0038A8F8-100;
            alpha=128;
            if(finish-now<8) alpha=(finish-(now-1))<<4;
            else if(now-begin<8) alpha=(now-(begin-1))<<4;
            func_003914A0((s16 *)&text,200,420,40,472,256,y,18,7);
            half=alpha>>1;
            col=alpha+half;
            color=col|(col<<8)|(col<<16)|(alpha<<24);
            func_00391510(&text,color,D_00225700_0038A8F8.data+offsets[language],-1);
            text.x-=4;
            height=(text.height>>1)+5;
            width=(text.width>>1)+10;
            if(D_001D4BC4_0038A8F8-20<text.x+height) text.x=D_001D4BC4_0038A8F8-((text.height>>1)+25);
            text.flags &= ~4;
            if((u32)func_0011B868(D_00225700_0038A8F8.data+offsets[language])>=150) return;
            func_0038C790(text.x-height,text.x+height,256-width,256+width,half+(alpha>>2),0x40404);
            func_00391510(&text,color,D_00225700_0038A8F8.data+offsets[language],-1);
            return;
        }
    }
}
/* localdecomp:end func_0038A8F8 */
