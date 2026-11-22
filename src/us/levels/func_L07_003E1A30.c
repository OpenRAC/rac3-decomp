#include "common.h"

/* NTSC-U counterpart of func_L07_003E3820. */
/* localdecomp:start func_L07_003E1A30 */
struct S_003E1CC0;
typedef struct { u8 pad0[0x80]; f32 x,y; } Hero_003E1A30;
extern u8 *D_L07_001DF500;
extern u8 D_001A4C60[];
extern u8 D_L07_003E1D40[];
__asm__(".extern D_L07_001DF500, 4");
void func_L07_003E1A30(u8 *obj) {
    extern void func_L07_003E1CC0(struct S_003E1CC0 *);
    extern s32 func_L01_004B6C68(void);
    extern f32 func_L01_0040C040(void *,void *);
    extern f32 func_00388A28(f32,f32);
    extern f32 func_003893C8(f32,f32);
    extern s32 func_003883C8(void *);
    extern f32 func_0037E250(f32,f32);
    extern s32 func_0037E1D8(s32);
    extern f32 func_00389410(f32);
    extern void func_L01_00445758(f32,f32,f32,f32,f32 *,f32 *,s32);
    extern f32 func_00388960(f32);
    extern s32 func_003894A0(s32,s32,f32);
    extern void func_L01_00402498(u8 *,u8 *);
    u8 *state;
    void *pos;
    f32 delta,phase;
    if(!obj[0x20]) func_L07_003E1CC0((struct S_003E1CC0 *)obj);
    state=*(u8 **)(obj+0x68);
    if(*(s32 *)state!=-1) pos=D_L07_001DF500+(*(s32 *)state<<7)+0x30;
    else pos=obj+0x10;
    if(func_L01_004B6C68()) delta=0.0f;
    else if(func_L01_0040C040(pos,D_001A4C60)<*(f32 *)(state+4)**(f32 *)(state+4)) {
        delta=func_003893C8(func_00388A28(((Hero_003E1A30 *)(D_001A4C60-0x80))->x-*(f32 *)(obj+0x10),((Hero_003E1A30 *)(D_001A4C60-0x80))->y-*(f32 *)(obj+0x14)),*(f32 *)(state+0x10));
        if(delta>*(f32 *)(state+8)*0.01745329238f) delta=*(f32 *)(state+8)*0.01745329238f;
        else if(delta<-(*(f32 *)(state+0xC)*0.01745329238f)) delta=-(*(f32 *)(state+0xC)*0.01745329238f);
        *(f32 *)(state+0x20)+=0.0299999993f;
        if(*(f32 *)(state+0x20)>=2.0f) *(f32 *)(state+0x20)-=2.0f;
    } else {
        if(func_003883C8(state+0x1C)) {
            *(f32 *)(state+0x18)=func_0037E250(-*(f32 *)(state+0xC),*(f32 *)(state+8))*0.01745329238f*0.75f;
            *(s16 *)(state+0x1C)=func_0037E1D8(60)+120;
        }
        *(f32 *)(state+0x20)*=0.99000001f;
        delta=*(f32 *)(state+0x18);
    }
    delta=func_00389410(*(f32 *)(state+0x10)+delta+3.141592741f);
    func_L01_00445758(delta,0.000218166169f,0.000218166169f,0.0130899707f,(f32 *)(obj+0xF8),(f32 *)(state+0x14),0);
    phase=*(f32 *)(state+0x20);
    phase=func_00388960(phase>1.0f ? 2.0f-phase : phase);
    *(s32 *)(obj+0x78)=func_003894A0(0x202020,0xFF0000FF,(1.0f-phase)*0.5f);
    if(obj[0x31]) func_L01_00402498(D_L07_003E1D40,obj);
}
/* localdecomp:end func_L07_003E1A30 */
