#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L21_003AF360 */
extern void func_003BD360(void *);
extern void func_003886E8(void *,void *,float);
extern void func_L01_00443610(void *,void *,int,float);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern int func_003CE740(void *,void *,int,void *,void *);
extern u8 *D_L21_001E84D8[];
extern void func_L21_003AF6C8(void *);
extern void func_L01_0032FE90(void *,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,float,float,float,float);
void func_L21_003AF360(u8 *obj) {
    vu0_v4 old; u8 loc[0x30];
    vu0_v4 *op;
    u8 *v=*(u8 **)(obj+0x68);
    int hit;
    u8 *owner;
    if (++*(int *)(v+0x2c)>300) {func_003BD360(obj);return;}
    op=&old; old=*(vu0_v4 *)(obj+0x10);
    *(vu0_v4 *)(v+0x10)=*(vu0_v4 *)(obj+0xc0);
    func_003886E8(v+0x10,v+0x10,*(float *)(v+0x28));
    vec_add_ba(obj+0x10,v+0x10,obj+0x10);
    func_L01_00443610(&loc,obj,0x10001,*(float *)(v+0x24));
    owner=*(u8 **)(obj+0xb8);
    func_L01_004C76B8();
    hit=func_003CE740(op,obj+0x10,16,owner,&loc);
    if(hit && D_L21_001E84D8[0] && *(short *)(D_L21_001E84D8[0]+0xaa)==0x186d &&
       D_L21_001E84D8[0][0x20]!=2 && D_L21_001E84D8[0][0x20]!=5)
        D_L21_001E84D8[0][0x20]=4;
    func_L01_004C76F0();
    if(hit) {
        func_L01_0032FE90(obj+0x10,0,0,5,0,5,5,0,0,0,0,0,0,0,0,0,0xffde5ced,0xffe01fc8,0x407fff,0x20ff,0x8fff,0x3064ff,0x7f60a0ff,0x280000ff,0x3064ff,0,0.75f,0.0f,0.0f,0.0f);
        func_003BD360(obj);
    } else func_L21_003AF6C8(obj);
}
/* localdecomp:end func_L21_003AF360 */
