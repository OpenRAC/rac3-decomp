/* PAL port (round 8) of the NTSC-U draft of func_L01_0049D920: PAL port, 8 words off with @ps2as on a cut file and a divs_nops row (func_L01_004A1180 0 2 1): the argument scheduling of the two func_003E8FE8 calls (move a1,v0 comes earlier in ours) and the last -1 store uses v0 where retail uses v1. Tried: temp for the call result, unsigned colour parameter, signed colour literal, separate loop pointer (that one fixed 4 words). */
#include "common.h"
/* localdecomp:start func_L01_004A1180 */
typedef struct { int id,a,b,c,d; unsigned char enabled; char pad[3]; } Entry_004A1180;
extern Entry_004A1180 D_L01_002ED850[];
extern float D_L01_001DC0E8;
__asm__(".extern D_L01_001DC0E8,16");
extern char D_L01_002ED898[];
extern int D_001D9660_sda,D_001D965C_sda,D_001D9658_sda;
__asm__(".extern D_001D9660_sda,4\n.extern D_001D965C_sda,4\n.extern D_001D9658_sda,4");
extern void func_L01_004A1CA8(void),func_L01_004A1910(void),func_L01_004A1F78(void),func_L01_004A1E18(void);
extern int func_00381FF0(int),func_0038E548(float,int,int);
extern float func_003C4088(float,float,float);
extern void func_003B9298(int,float,int,int,int,int,int,int,int,int,int,int,int,int,int);
extern void func_003E8FE8(int,int,int,float,float,float,float),func_003E7F20(int,int),func_003E8A08(int,int,int);
extern void func_L01_00517538(int,float,float),func_L01_004A1630(void *),func_L01_00518010(int,int),func_003E8898(int,float,float),func_003E8348(int,int);
extern void *func_003B42F8(s32);
extern void func_003E8710(int,int),func_L01_00516D60(int,int),func_L01_00517190(int,int),func_003E87B8(int,int,int);

void func_L01_004A1180(void) {
    int i=0,scaled=0,selected;
    float ratio,scale;
    float resize=0.0f,min=0.0f,max=0.49f,low=6.0f,high=11.0f;
    Entry_004A1180 *p,*q;
    func_L01_004A1CA8();
    ratio=(float)func_0038E548(1.2f,func_00381FF0(0x106),-1)/D_L01_001DC0E8;
    if (max<ratio) {
        resize=0.588000059f/ratio;
        scaled=1;
        ratio=max;
    }
    ratio=(ratio-min)/(max-min);
    scale=func_003C4088(low,high,ratio);
    if (high<scale) scale=high;
    else if (scale<low) scale=low;
    func_003B9298(0x10,scale,0xd000b,0xd0000,0xd0001,0xd0002,0xd0003,0xd0004,0xd0005,0xd0008,func_00381FF0(0x106),0xd0006,0x124,0xd0007,0xcd5);
    func_003E8FE8(0xd0009,func_00381FF0(0x1b80),0x8066ccff,0.035f,0.5f,1.0f,1.0f);
    func_003E7F20(0xd0009,1);
    func_003E8FE8(0xd000a,func_00381FF0(0x1b81),0x8066ccff,0.97f,0.5f,1.0f,1.0f);
    func_003E7F20(0xd000a,1);
    func_003E8A08(0xd000b,0xd0009,0xd000a);
    if (scaled) func_L01_00517538(0xd0005,resize,resize);
    func_L01_004A1630(D_L01_002ED898);
    func_L01_00518010(0x570005,1);
    func_003E8898(0x570005,0.49f,0.0f);
    func_003E8348(0x11,0x570000);
    func_003E7F20(0x570006,1);
    func_003E8710(0x570009,(int)func_003B42F8(0));
    func_L01_004A1910();
    func_L01_004A1F78();
    D_001D9660_sda=-1;
    p=&D_L01_002ED850[i];
    if (p->id) {
        selected=-1;
        q=p;
        do {
            if (q->enabled) selected=i;
            q++;
            i++;
        } while (q->id && selected<0);
        D_001D9660_sda=selected;
    }
    if (D_001D9660_sda<0 && D_001D965C_sda) D_001D9660_sda=0;
    func_L01_00516D60(0x570009,0);
    func_L01_00517190(0x570009,0);
    func_003E87B8(0x570009,1,8);
    D_001D9658_sda=-1;
    func_L01_004A1E18();
}
/* localdecomp:end func_L01_004A1180 */
