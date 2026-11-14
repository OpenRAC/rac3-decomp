#include "common.h"

/* localdecomp:start func_L01_003BACE8 */
extern u8 D_L01_002BB0F0[];
extern u8 D_L01_001E2AC0[];
extern s32 *func_L01_00438488(s32,s32,s32);
extern void func_L01_00441FB8(void *,s32,s32);
extern void func_L01_004A6DF8(void *,s32);
extern f32 func_L01_0040C018(void *,void *);
extern void func_L01_00444188(void *);
void func_L01_003BACE8(u8 *a0) {
    s32 *r;
    s32 h;
    switch(a0[0x20]) {
    case 0:
        r=func_L01_00438488(0x194C,0,4);
        if(r!=0)((void (*)(void *,void *))r[0])(a0,D_L01_002BB0F0);
        goto trans;
    case 2:
        if(a0[0x31]!=0) {
            if(func_L01_0040C018(D_L01_001E2AC0,a0+0x10)<1024.0f) {
                func_L01_00444188(a0);
                a0[0x6F]=30;
            }
        }
        break;
    case 3:
        h=*(u16 *)(a0+0x96)+1;
        *(u16 *)(a0+0x96)=h;
        if((u16)h<0x259)break;
trans:
        func_L01_00441FB8(a0,1,-1);
    case 1:
        *(s32 *)(a0+0x98)=0;
        *(u16 *)(a0+0x34)=(*(u16 *)(a0+0x34)|0x41)&0xEFFF;
        func_L01_004A6DF8(a0,1);
        *(u16 *)(a0+0x34)|=2;
        break;
    }
}
/* localdecomp:end func_L01_003BACE8 */
