/* functional: high. Draft from a Codex near miss, 57 words differ in scheduling and register choice only (0x7f kept in v1 vs v0, VU0 sub ordering); I fixed the func_00382348 call to pass the old moby (retail passes it in a0). */
#include "common.h"
/* localdecomp:start func_L01_003DA3F0 */
typedef int Q_003DA3F0 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V_003DA3F0;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D67B0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L01_001E2430;
__asm__(".extern D_L01_001E2430, 16");
extern s32 D_L01_001DDBB0;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001DDBB0, 4");
static __inline__ void sub_003DA3F0(V_003DA3F0 *d, vu0_v4 *a, void *b) {
    __asm__("lqc2 vf2, %2
	lqc2 vf1, %1
	vsub.xyz vf1, vf1, vf2
	sqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*(V_003DA3F0 *)b) : "vf1", "vf2");
}
u8 *func_L01_003DA3F0(u8 *old) {
    extern u8 *func_003C24B0(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_L01_003DB3F8(void);
    extern void func_L01_003DB680(void *);
    extern void func_L01_00459C50(s32);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038D570(void *,void *);
    extern void func_003C48A8(void *,void *);
    extern void func_L01_004443E8(void *,s32,s32);
    extern u8 *func_00382348(u8 *);
    extern void func_003C2880(u8 *);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern void func_003C3A10(u8 *,s32,s32,s32);
    extern void func_003C7C38(void *);
    V_003DA3F0 a,b,c;
    f32 matrix[16] __attribute__((aligned(16)));
    u8 *obj=func_003C24B0(0x1D3E,0x100);
    u8 *v,*h,*rotation;
    s32 i;
    if (obj) {
        { s32 alpha=127;
        *(u16 *)(obj+0x32)=alpha;
        obj[0x31]=1;
        obj[0x30]=alpha; }
        *(Q_003DA3F0 *)(obj+0x10)=*(Q_003DA3F0 *)(old+0x10);
        v=*(u8 **)(obj+0x68);
        *(f32 *)(v+0)=func_003824E0(4.0f,5.5f);
        *(f32 *)(v+4)=func_003824E0(5.5f,6.5f);
        *(u32 *)(obj+0x78)=0x80808080;
        *(f32 *)(obj+0x2C)=*(f32 *)(*(u8 **)(obj+0x24)+0x24)*0.7f;
        *(f32 *)(v+8)=func_003824E0(0.02617993950843811f,0.06981317698955536f);
        *(s32 *)(v+0x24)=-1;
        *(s32 *)(v+0x30)=-1;
        *(s32 *)(v+0x3C)=0;
        D_L01_001E2430=50;
        D_L01_001DDBB0=0;
        func_L01_003DB3F8();
        for(i=63;i>=0;i--) func_L01_003DB680(&a);
        if(D_001D545C==5 && *(s16 *)(old+0xAA)==0x19DB) {
            if(++D_L01_001D67B0>=15) func_L01_00459C50(7);
        }
        if(D_L01_001D6740 || D_L01_001D673C) {
            func_L01_004C7D98(obj+0x10,&a);
            rotation=obj+0xF0;
            func_0038CF68(&a,&a,-1.0f);
            sub_003DA3F0(&b,&D_L01_001E29C0,obj+0x10);
            func_0038CF68(&b,&b,1.0f);
            func_0038CE90(&b,&b,&a);
            func_0038CE90(&c,&b,&a);
            *(Q_003DA3F0 *)(obj+0xC0)=*(Q_003DA3F0 *)&c;
            *(Q_003DA3F0 *)(obj+0xD0)=*(Q_003DA3F0 *)&b;
            *(Q_003DA3F0 *)(obj+0xE0)=*(Q_003DA3F0 *)&a;
            *(Q_003DA3F0 *)(obj+0xF0)=*(Q_003DA3F0 *)(obj+0x10);
            func_0038D570(matrix,obj+0xC0);
            func_003C48A8(matrix,rotation);
        }
        *(s32 *)(v+0x48)=0;
        *(s32 *)(v+0x4C)=8;
        if(*(u16 *)(obj+0x34)&0x1000) func_L01_004443E8(old,0,3);
        h=func_00382348(old);
        if(h && h[0xE]==1) h[0xE]=2;
        else func_003C2880(old);
        *(s32 *)(v+0x28)=0;
        *(s32 *)(v+0x20)=2500;
        *(s32 *)(obj+0x98)=*(s32 *)(*(u8 **)(obj+0x24)+0x10);
        func_L01_004450F0(obj,0,-1);
        if(obj[0x43]!=1) func_003C3A10(obj,1,0,0);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003DA3F0 */
