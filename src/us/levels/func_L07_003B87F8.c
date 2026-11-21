#include "common.h"

/* NTSC-U counterpart of func_L07_003BA0E8 (src/levels/07_annihilation_nation/L07_003B9A90.c): 60 Hz drain 0.08f per frame (PAL 0.096f), sound 120 (PAL 100) */
/* localdecomp:start func_L07_003B87F8 */
extern u8 *D_L07_001DE548;
__asm__(".extern D_L07_001DE548, 4");
extern f32 D_L07_001DED50;
extern f32 D_001DED50_sda;
__asm__(".extern D_001DED50_sda, 4");
extern s32 D_L07_001F2140 __attribute__((section(".data")));
extern s32 D_001D545C;
extern u32 D_001A8018 __attribute__((section(".data")));
extern u32 D_001A8060 __attribute__((section(".data")));
extern u32 D_001A7F4C __attribute__((section(".data")));
extern u16 D_001A7D00 __attribute__((section(".data")));
extern u16 D_001A7DA8 __attribute__((section(".data")));
extern u8 D_001A4C60[];
extern s32 D_001D4C38, D_L07_001D7B20, D_L07_001DF518;
extern s32 D_001A7430 __attribute__((section(".data")));
extern f32 D_L07_001E0540 __attribute__((section(".sdata")));
__asm__(".extern D_L07_001E0540, 16");
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_0045BE58(s32, s32);
extern void func_L01_00475A28(void);
extern void func_L01_00477BD0(void);
extern void func_L01_00478140(void);
extern s32 func_L01_00452EC8(u8 *);
extern void func_0039FE80(s32, s32, u8 *);
extern void func_L07_003B9A70(u8 *);
extern void func_L07_003B9B20(u8 *);
extern void func_L01_00417F60(s32, s32);
extern s32 func_L01_0050FF18(void);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L07_003A0BC0(s32, u8 *, s32, s32);
extern void func_L07_003B9080(u8 *);
void func_L07_003B87F8(u8 *obj) {
    u8 *s=*(u8 **)(obj+0x68);
    s32 i;
    s32 *slot;
    f32 health;
    switch(obj[0x20]) {
    case 0:
        D_L07_001DE548=obj;
        obj[0x30]=255;
        s[0xAE]=255;
        s[0xAF]=0;
        *(u16 *)(obj+0x34)|=1;
        func_L01_00441FB8(obj,1,-1);
        break;
    case 1:
        break;
    case 2:
        if(D_L07_001DED50<=0.0f) {
            D_L07_001DED50=0.0f;
            func_L01_004FC518(0,1);
            s[0xB0]=1;
            func_L01_0045BE58(*(s32 *)(s+0x90),-1);
            func_L01_00475A28();
            func_L01_00477BD0();
            func_L01_00478140();
            func_L01_00441FB8(obj,3,-1);
        } else D_001DED50_sda=D_L07_001DED50-0.0799999982f;
        break;
    case 3:
        if(!D_L07_001F2140 && func_L01_00452EC8(obj)) {
            func_0039FE80(0,4,obj);
            func_0039FE80(1,4,obj);
        }
        func_L07_003B9A70(obj);
        func_L07_003B9B20(obj);
        if(++*(u16 *)(obj+0x96)>900) {
            if(!(D_001A8018&((u32)1<<D_001D545C)) && !D_001A7D00) func_L01_00417F60(0xB87,0x2A);
        }
        if(!func_L01_0050FF18()) {
            if(func_0037E0F0(D_001A4C60,*(s32 *)(s+0x48),0) && !D_001A7DA8 && !(D_001A8060&((u32)1<<D_001D545C))) func_L01_00417F60(0xB8D,0x30);
        }
        D_L07_001D7B20=s[0xAE]+0x21;
        D_L07_001DF518=D_001D4C38;
        for(i=0;i<8;i++) {
            slot=(s32 *)(s+i*4);
            if(slot[0]!=-1 && slot[8]!=-1) {
                if(func_0037E0F0(D_001A4C60,slot[0],0)) s[0xAF]|=1<<i;
                else s[0xAF]&=~(1<<i);
            }
        }
        if(s[0xB0]==1) {
            health=(f32)D_001A7430+D_L07_001E0540;
            if(*(f32 *)(s+0x9C)<health) *(f32 *)(s+0x9C)=health;
            else if(health<*(f32 *)(s+0x9C)) s[0xB0]=0;
        }
        if(!func_L01_0050FF18()) {
            if(*(s32 *)(s+0xBC)!=-1 && func_0037E0F0(D_001A4C60,*(s32 *)(s+0xBC),0) && !(D_001A7F4C&((u32)1<<D_001D545C))) func_L01_00417F60(0xB76,0x19);
        }
        if(*(s16 *)(s+0xA0)&0x8080) {
            switch(func_0037E1D8(4)) {
            case 0: func_L07_003A0BC0(0x4F,obj,0,120); break;
            case 1: func_L07_003A0BC0(0x50,obj,0,120); break;
            default: func_L07_003A0BC0(func_0037E208(0x67,0x69)&255,obj,0,120); break;
            }
            func_L07_003B9080(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003B87F8 */
