/* PAL near miss (haiku-w1): 142 words differ with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); pure C with no VU0 block; the remaining words are global address forms (the size hint of D_L01_001E1135 and neighbours) and the store/branch order. */
#include "common.h"
/* localdecomp:start func_L01_004C9500 */
typedef int Q_004C9500 __attribute__((mode(TI)));
typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[0x24]; s32 f94; } S_004C9500;
extern S_004C9500 D_001CCFD0;
extern s32 D_001DB004_sda;
extern s32 D_001DAFE8_sda;
extern s32 D_001DAFE4_sda;
extern u8 D_001A4C60[];
extern Q_004C9500 D_L01_001E1110;
extern Q_004C9500 D_L01_001E1120;
extern s16 D_L01_001E1100;
extern s16 D_L01_001E1102;
extern f32 D_L01_001E1104;
extern short D_L01_001E1108;
extern u8 D_L01_001E110C;
extern u8 D_L01_001E110D;
extern u8 D_001425D6[];
extern u8 D_001425C0[];
extern Ent_004C4F88 D_L01_002C5600[];
extern Obj_4C5DE0 *D_L01_001E1130;
extern u8 D_L01_001E1135;
__asm__(".extern D_L01_001E1100, 16");
__asm__(".extern D_L01_001E1102, 16");
__asm__(".extern D_L01_001E1104, 16");
__asm__(".extern D_L01_001E1108, 16");
__asm__(".extern D_L01_001E110C, 16");
__asm__(".extern D_L01_001E110D, 16");
__asm__(".extern D_L01_001E1130, 16");
__asm__(".extern D_L01_001E1135, 4");
__asm__(".extern D_001DB004_sda, 4");
__asm__(".extern D_001DAFE8_sda, 4");
__asm__(".extern D_001DAFE4_sda, 4");
void func_L01_004C9500(void)
{
    extern void func_003A2B68(s32, s32);
    extern void func_003C2880(void *);
    extern Obj_4C5DE0 *func_L01_00303D30(void *, s32);
    extern Obj_4C5DE0 *func_L01_004C98A8(s32, s32, Obj_4C5DE0 *);
    Vec4_004C4AD8 v;
    S_004C9500 *state=&D_001CCFD0;
    s32 frames=(D_001DB004_sda*5+2)/6;
    u8 *r;
    Obj_4C5DE0 *m;
    s32 level;
    {
        Q_004C9500 a=*(Q_004C9500 *)D_001A4C60;
        Q_004C9500 b=*(Q_004C9500 *)(D_001A4C60+16);
        D_L01_001E1110=a;
        D_L01_001E1120=b;
    }
    D_L01_001E1100=0;
    D_L01_001E1102=frames;
    D_L01_001E1104=1.0f/(f32)D_L01_001E1102;
    if(state->f6C==0 && state->f24==-1 && state->f94==0) {
        func_003A2B68(0xEB7,0);
        D_001DAFE8_sda=0;
        D_001DAFE4_sda=1;
    }
    D_L01_001E110C=0;
    D_L01_001E110D=0;
    switch(D_L01_001E1108) {
    case 22: {
        r=(u8 *)&D_L01_002C5600[D_001425D6[0]];
        D_L01_001E1130=func_L01_004C98A8(*(s32 *)(r+16),-1,0);
        D_L01_001E1135=0;
        break;
    }
    case 87: {
        r=(u8 *)&D_L01_002C5600[D_001425C0[0x57]];
        m=(Obj_4C5DE0 *)((Game_004C5038 *)((u8 *)&D_001A4BE0+*(s32 *)(r+8)*80))->f4608;
        if(m!=0 && *(s16 *)((u8 *)m+0xAA)==0x1852) func_003C2880(m);
        *(Q_004C9500 *)&v=0;
        v.x=5.0f;
        v.y=5.0f;
        v.z=5.0f;
        v.w=1.0f;
        D_L01_001E1130=func_L01_00303D30(&v,0);
        m=func_L01_004C98A8(0x1ADA,-1,D_L01_001E1130);
        D_L01_001E1130=m;
        D_L01_001E1135=0;
        level=D_L01_002C5600[D_001425C0[0x57]].b;
        if(level>=4) *(s16 *)((u8 *)m+0x7C)=5;
        if((u32)(level-1)<3) *(s16 *)((u8 *)D_L01_001E1130+0x7C)=9;
        else if(level==0) *(s16 *)((u8 *)D_L01_001E1130+0x7C)=1;
        break;
    }
    default: {
        r=(u8 *)&D_L01_002C5600[D_001425C0[D_L01_001E1108]];
        D_L01_001E1135=1;
        D_L01_001E1130=(Obj_4C5DE0 *)((Game_004C5038 *)((u8 *)&D_001A4BE0+*(s32 *)(r+8)*80))->f4608;
        break;
    }
    }
}
