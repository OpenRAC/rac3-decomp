#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
typedef void (*Fn_335C70)(u8 *);
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;

INCLUDE_ASM("asm/levels", func_L01_003326A8);

/* localdecomp:start func_L01_00333D80 */
extern u8 *D_L01_001E001C;
s32 func_L01_00333D80(u8 *m)
{
    extern void func_L01_003362B0(u8 *,s32);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern Vt00335B98 *func_L01_0043B568(s32,s32,s32);
    extern void func_L01_00329F00(u8 *,u8 *);
    u8 *vars;
    u8 *table;
    u8 *child;
    u8 *parent;
    if (m[0x20]==0) {
        u8 *init;
        init=*(u8 **)(m+0x68);
        *(u8 **)(init+0x2C)=init+0x30;
        *(s32 *)(init+0x50)=-1;
        *(s32 *)(init+0x60)=0;
        *(s32 *)(init+0x64)=0;
        *(s32 *)(init+0x68)=0;
        *(s32 *)(init+0x54)=0;
        *(s32 *)(init+0x58)=0;
        ((s8 *)init)[0x5C]=-1;
        init[0x5D]=0;
        init[0x5E]=0;
        init[0x5F]=0;
        if (*(s32 *)(init+0x30)>0) {
            *(s32 *)(init+0x30)=-1;
            init[0x3E]=3;
            func_L01_003362B0(m,0);
        } else {
            func_L01_004450F0(m,1,-1);
        }
        return 1;
    } else if (m[0x20]==1) {
        u8 *base;
        vars=*(u8 **)(m+0x68);
        table=(u8 *)func_L01_0043B568(*(s32 *)(vars+0x40),4,156);
        *(u8 **)(m+0xB8)=D_L01_001E001C+(*(s32 *)(vars+0x44)<<8);
        child=(*(u8 *(**)(u8 *))table)(m);
        base=D_L01_001E001C;
        *(s32 *)(vars+0x50)=(child-base)>>8;
        func_L01_00329F00(base+(*(s32 *)(vars+0x44)<<8),m);
        *(s32 *)(vars+0x4C)=-1;
        parent=*(u8 **)(m+0xB8);
        if (parent!=0 && child!=0) {
            u8 *pv=*(u8 **)(parent+0x68);
            if (pv[0x90]!=0 && *(void (**)(u8 *))(table+0x90)!=0) {
                (*(void (**)(u8 *))(table+0x90))(child);
            }
            *(u16 *)(vars+0x7A)=*(u16 *)((*(u8 *(**)(u8 *))(table+0x94))(child)+0x34);
        }
        func_L01_004450F0(m,2,-1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00333D80 */
