/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0049D920, the NTSC-U twin of func_L01_004A1180, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_0049E000.c's current line.
 * Worker's note: 212 diff; best func_L01_0049D920.check03.log; allowed GNU flags emit .lit4 loads for 0.49/1.2/0.588 versus retail inline lui/ori/mtc1; absolute runtime divisor declared correctly; no unlisted flags tried; assembler-literal mismatch stops this entry
 */
#include "common.h"

/* localdecomp:start func_L01_0049D920 */
typedef struct { int id,a,b,c,d; unsigned char enabled; char pad[3]; } Entry_49D920;
extern Entry_49D920 D_L01_002ED8A0[];
extern float D_L01_001DC128;
__asm__(".extern D_L01_001DC128,16");
extern char D_L01_002ED8E8[];
extern int D_001D9690_sda,D_001D968C_sda,D_001D9688_sda;
__asm__(".extern D_001D9690_sda,4\n.extern D_001D968C_sda,4\n.extern D_001D9688_sda,4");
extern void func_L01_0049E448(void),func_L01_0049E0B0(void),func_L01_0049E718(void),func_L01_0049E5B8(void);
extern int func_0037DF98(int),func_00389D18(float,int,int);
extern float func_003BEB48(float,float,float);
extern void func_003B3DB8(int,float,int,int,int,int,int,int,int,int,int,int,int,int,int);
extern void func_003E3A80(int,int,int,float,float,float,float),func_003E29B8(int,int),func_003E34A0(int,int,int);
extern void func_L01_00513548(int,float,float),func_L01_0049DDD0(void *),func_L01_00514020(int,int),func_003E3330(int,float,float),func_003E2DE0(int,int);
extern int func_003AED40(int);
extern void func_003E31A8(int,int),func_L01_00512D70(int,int),func_L01_005131A0(int,int),func_003E3250(int,int,int);

void func_L01_0049D920(void) {
    int i=0,scaled=0,selected;
    float ratio,scale;
    float resize=0.0f,min=0.0f,max=0.49f,low=6.0f,high=11.0f;
    Entry_49D920 *p;
    func_L01_0049E448();
    ratio=(float)func_00389D18(1.2f,func_0037DF98(0x106),-1)/D_L01_001DC128;
    if (max<ratio) {
        resize=0.588f/ratio;
        scaled=1;
        ratio=max;
    }
    ratio=(ratio-min)/(max-min);
    scale=func_003BEB48(low,high,ratio);
    if (high<scale) scale=high;
    else if (scale<low) scale=low;
    func_003B3DB8(0x10,scale,0xd000b,0xd0000,0xd0001,0xd0002,0xd0003,0xd0004,0xd0005,0xd0008,func_0037DF98(0x106),0xd0006,0x124,0xd0007,0xcd5);
    func_003E3A80(0xd0009,func_0037DF98(0x1b80),0x8066ccff,0.035f,0.5f,1.0f,1.0f);
    func_003E29B8(0xd0009,1);
    func_003E3A80(0xd000a,func_0037DF98(0x1b81),0x8066ccff,0.97f,0.5f,1.0f,1.0f);
    func_003E29B8(0xd000a,1);
    func_003E34A0(0xd000b,0xd0009,0xd000a);
    if (scaled) func_L01_00513548(0xd0005,resize,resize);
    func_L01_0049DDD0(D_L01_002ED8E8);
    func_L01_00514020(0x570005,1);
    func_003E3330(0x570005,0.49f,0.0f);
    func_003E2DE0(0x11,0x570000);
    func_003E29B8(0x570006,1);
    func_003E31A8(0x570009,func_003AED40(0));
    func_L01_0049E0B0();
    func_L01_0049E718();
    D_001D9690_sda=-1;
    p=&D_L01_002ED8A0[i];
    if (p->id) {
        selected=-1;
        do {
            if (p->enabled) selected=i;
            p++;
            i++;
        } while (p->id && selected<0);
        D_001D9690_sda=selected;
    }
    if (D_001D9690_sda<0 && D_001D968C_sda) D_001D9690_sda=0;
    func_L01_00512D70(0x570009,0);
    func_L01_005131A0(0x570009,0);
    func_003E3250(0x570009,1,10);
    D_001D9688_sda=-1;
    func_L01_0049E5B8();
}
/* localdecomp:end func_L01_0049D920 */
