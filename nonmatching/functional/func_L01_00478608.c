/* functional: high. Call sequence, arguments and constants read against the PAL asm; differs only in register/address allocation. */
#include "common.h"
extern u8 D_L01_001E15E0[];
extern u8 D_L01_00221800[],D_L01_00221400[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
s32 func_L01_00478608(void) {
    extern void func_L01_004CB540(s32);
    extern void func_003E9470(void);
    extern void func_003E72B8(s32);
    extern void *func_003E6C08();
    extern void *func_003B2DC8(s32);
    extern void func_003E5AA0(void *,s32);
    extern void func_003E6CD8(void *,s32,void *);
    extern void *func_003B42C0(void);
    extern void *func_003B42F8(s32);
    extern void *func_003B4380(void);
    extern void *func_003B43B0(s32);
    extern void func_003E69B0(void *,s32,void *);
    extern s32 func_003E6D10(void *,s32,s32,void *,s32);
    extern void func_003E6E10(void *,s32);
    extern s32 func_L01_0041A518(s32);
    extern void *func_L01_00479578(s32);
    extern void *func_L01_0047B638(s32);
    extern void *func_L01_0047C368(s32);
    extern void *func_L01_0047C4A8(void);
    extern void func_003E6FE0(void *);
    extern void func_003E8440(void *);
    s32 ok=1;
    s32 i;
    void *group;
    func_L01_004CB540(1);
    func_003E9470();
    func_003E72B8(1);
    func_003E6C08();
    group=D_L01_001E15E0;
    if(*(s32 *)((u8 *)group+4)==0) group=func_003E6C08();
    for(i=0;i<1;i++) {
        func_003E5AA0(func_003B2DC8(i),i);
        func_003E6CD8(group,i,func_003B2DC8(i));
    }
    func_003E69B0(group,0,func_003B42C0());
    func_003E69B0(group,1,func_003B42F8(0));
    func_003E69B0(group,2,func_003B42F8(1));
    func_003E69B0(group,3,func_003B42F8(2));
    func_003E69B0(group,4,func_003B42F8(3));
    func_003E69B0(group,5,func_003B4380());
    func_003E69B0(group,6,func_003B43B0(0));
    func_003E69B0(group,7,func_003B43B0(1));
    func_003E69B0(group,8,func_003B43B0(1));
    func_003E69B0(group,9,func_003B43B0(1));
    ok=(func_003E6D10(group,0,0x400,D_L01_00221800,16)!=0)&(ok!=0);
    ok=(func_003E6D10(group,1,0x12000,D_L01_00221400,100)!=0)&(ok!=0);
    func_003E6E10(group,0);
    if(!func_L01_0041A518(D_001D545C)) {
        func_003E6FE0(func_L01_00479578(0));
        func_003E6FE0(func_L01_0047B638(0));
        func_003E6FE0(func_L01_0047C368(0));
        func_003E6FE0(func_L01_0047C4A8());
        func_003E8440(func_L01_00479578(0));
        func_003E8440(func_L01_0047B638(0));
        func_003E8440(func_L01_0047C368(0));
        func_003E8440(func_L01_0047C4A8());
    }
    return ok;
}
