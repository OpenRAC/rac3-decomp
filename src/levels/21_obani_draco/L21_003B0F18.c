#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L21_003B0F18 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_003AF360.c */
#include "vu0.h"
extern void func_003C2880(void *);
extern void func_0038CE20(void *,void *,float);
extern void func_L01_00446748(void *,void *,int,float);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern int func_003D3CB0(void *,void *,int,void *,void *);
extern u8 *D_L21_001E8458[];
extern void func_L21_003B1280(void *);
extern void func_L01_0032FE90(void *,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,float,float,float,float);
void func_L21_003B0F18(u8 *obj) {
    vu0_v4 old; u8 loc[0x30];
    vu0_v4 *op;
    u8 *v=*(u8 **)(obj+0x68);
    int hit;
    u8 *owner;
    if (++*(int *)(v+0x2c)>250) {func_003C2880(obj);return;}
    op=&old; old=*(vu0_v4 *)(obj+0x10);
    *(vu0_v4 *)(v+0x10)=*(vu0_v4 *)(obj+0xc0);
    func_0038CE20(v+0x10,v+0x10,*(float *)(v+0x28));
    vec_add_ba(obj+0x10,v+0x10,obj+0x10);
    func_L01_00446748(&loc,obj,0x10001,*(float *)(v+0x24));
    owner=*(u8 **)(obj+0xb8);
    func_L01_004CB320();
    hit=func_003D3CB0(op,obj+0x10,16,owner,&loc);
    if(hit && D_L21_001E8458[0] && *(short *)(D_L21_001E8458[0]+0xaa)==0x186d &&
       D_L21_001E8458[0][0x20]!=2 && D_L21_001E8458[0][0x20]!=5)
        D_L21_001E8458[0][0x20]=4;
    func_L01_004CB358();
    if(hit) {
        func_L01_0032FE90(obj+0x10,0,0,5,0,5,5,0,0,0,0,0,0,0,0,0,0xffde5ced,0xffe01fc8,0x407fff,0x20ff,0x8fff,0x3064ff,0x7f60a0ff,0x280000ff,0x3064ff,0,0.75f,0.0f,0.0f,0.0f);
        func_003C2880(obj);
    } else func_L21_003B1280(obj);
}
/* localdecomp:end func_L21_003B0F18 */

INCLUDE_ASM("asm/levels", func_L21_003B1118);

INCLUDE_ASM("asm/levels", func_L21_003B1280);

INCLUDE_ASM("asm/levels", func_L21_003B1328);

INCLUDE_ASM("asm/levels", func_L21_003B1518);

INCLUDE_ASM("asm/levels", func_L21_003B1690);

INCLUDE_ASM("asm/levels", func_L21_003B17D8);
