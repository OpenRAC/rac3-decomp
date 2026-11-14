/* NTSC-U draft (2026-11-14, Codex worker): C of func_L02_00350928, the NTSC-U twin of func_L02_00351A38, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L02_00351A38.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L02_00350928 */
typedef int Q_350928 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_350928;
typedef struct { u8 pad[0x80]; } Slot_350928;
extern u8 D_L02_001D66B0[], D_001A30B0[], D_001A4BE0[], D_L02_00350728[];
extern s32 D_L02_001DE540[];
extern f32 func_00388800(void *,void *);
extern void func_003BD9A0(void *,s32,void *);
extern void func_003BDA38(void *,s32,void *);
extern void func_003BEB58(void *,void *,void *,f32);
extern void func_00388830(void *,void *,f32);
extern void func_00389158(void *,void *,void *,f32);
extern s32 func_0039FE80(s32,s32,void *);
extern void func_003886E8(void *,void *,f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_00443628(void *,void *,s32,void *,f32);
extern void func_003CF790(void *,s32,void *,void *,f32);
extern void func_003BEBF8(void *,f32,f32);
extern f32 func_00388770(void *);
extern f32 func_L01_00444740(void *,void *,s32,f32,f32);
extern void func_L01_00449008(void *,void *,void *,s32,f32);
extern void func_003BD360(void *);
extern void func_0039FB08(s32);
extern u8 *func_003BCFB0(s32,s32);
extern void func_L01_00452E70(void *,void *);
extern void func_003C26C8(void *);
extern void func_L02_00350840(void *);
extern void func_L01_00402498(void *,void *);
static __inline__ void add_350928(void *dst,void *a,void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_350928 *)dst) : "m"(*(V_350928 *)a), "m"(*(V_350928 *)b) : "vf1","vf2");
}
static __inline__ void sub_350928(void *dst,void *a,void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V_350928 *)dst) : "m"(*(V_350928 *)a), "m"(*(V_350928 *)b) : "vf1","vf2");
}
void func_L02_00350928(u8 *m) {
    V_350928 mat[4], va, vb;
    u8 hit[0x20];
    u8 *p=*(u8 **)(m+0x68), *ownerp=*(u8 **)(*(u8 **)(m+0xB8)+0x68);
    u8 *slot;
    *(u16 *)(m+0x34)|=0x100;
    if (m[0x20]==1 && func_00388800(m+0x10,p+0x30)<1.5f && *(u16 *)(m+0x96)>=3) {
        func_003BD9A0(*(void **)(m+0xB8),0,mat);
        va=*(V_350928 *)(m+0xE0); vb=mat[2];
        func_003BEB58(m+0xE0,&va,&vb,0.25f);
        func_00388830(m+0xE0,m+0xE0,1.0f);
        func_00389158(m+0xC0,m+0xC0,m+0xE0,0.93084234f);
        func_00389158(m+0xD0,m+0xD0,m+0xE0,0.93084234f);
    } else {
        mat[0]=*(V_350928 *)D_L02_001D66B0;
        va=*(V_350928 *)(m+0xE0);
        mat[0].z=1.0f;
        func_003BEB58(m+0xE0,&va,mat,0.041f);
        func_00388830(m+0xE0,m+0xE0,1.0f);
        func_00389158(m+0xC0,m+0xC0,m+0xE0,0.93084234f);
        func_00389158(m+0xD0,m+0xD0,m+0xE0,0.93084234f);
    }
    slot=D_001A30B0+*(s32 *)(p+0x24)*128;
    if (*(s32 *)(p+0x24)==-1 || *(u8 **)(slot+0xDC)!=m || !slot[0xD0]) *(s32 *)(p+0x24)=func_0039FE80(0,4,m);
    mat[0]=*(V_350928 *)(m+0x10);
    func_00388830(&mat[1],p,0.5f);
    func_003886E8(&mat[1],&mat[1],2.0f);
    mat[1].w=5627.925f;
    func_L01_00443628(hit,m,0x10001,&mat[1],(f32)func_0037E0B8(*(void **)(m+0xB8))[0x15]);
    *(u16 *)(hit+0x1A)=*(u16 *)(m+0xAA);
    hit[0x19]=1; hit[0x18]=0;
    func_003CF790(mat,0,*(void **)(m+0xB8),hit,0.35f);
    if (m[0x20]==0) {
        ++*(u16 *)(m+0x96);
        func_003BEBF8(p+0x14,0.25f,0.0075f);
        *(f32 *)(p+8)=func_L01_00444740(m+0x10,p+0x30,0,func_00388770(p),0.0f);
        func_00388830(p,p,func_00388770(p));
        add_350928(m+0x10,m+0x10,p);
        sub_350928(&vb,p+0x30,m+0x10); vb.z=0.0f;
        func_00388830(&va,p,1.0f);
        func_L01_00449008(p,p,&vb,0,*(f32 *)(p+0x14));
        if (func_00388800(m+0x10,p+0x30)<1.5f || *(u16 *)(m+0x96)>=151 || func_00388800(m+0x10,*(u8 **)(m+0xB8)+0x10)>50.0f) {
            *(u16 *)(m+0x96)=0; m[0x20]=1;
            *(f32 *)(p+0x14)=0.0025f;
            *(Q_350928 *)(p+0x30)=*(Q_350928 *)(*(u8 **)(m+0xB8)+0x10);
        }
        if (*(s32 *)(ownerp+0x920)==0) {
            if (!(func_00388800(m+0x10,p+0x30)>4.0f)) goto effects;
        } else {
            if (!(func_00388800(m+0x10,p+0x30)>3.25f)) goto effects;
        }
        if (*(s32 *)(p+0x20)==*(s32 *)(D_001A4BE0+0x25C0)) {
            *(Q_350928 *)(p+0x30)=*(Q_350928 *)(D_001A4BE0+0xD0);
        } else {
            u8 *q=func_0037E0B8(*(void **)(p+0x20));
            *(Q_350928 *)(p+0x30)=*(Q_350928 *)(*(u8 **)(p+0x20)+0x10);
            if(q) *(f32 *)(p+0x38)+=*(f32 *)(q+0x10);
        }
    } else if (m[0x20]==1) {
        ++*(u16 *)(m+0x96);
        func_003BEBF8(p+0x14,0.5f,0.0075f);
        func_003BDA38(*(void **)(m+0xB8),0,&vb);
        *(Q_350928 *)(p+0x30)=*(Q_350928 *)&vb;
        func_00388830(p,p,func_00388770(p));
        add_350928(m+0x10,m+0x10,p);
        sub_350928(&va,p+0x30,m+0x10); va.z=0;
        func_00388830(&vb,p,1.0f);
        func_L01_00449008(p,p,&va,0,*(f32 *)(p+0x14));
        *(f32 *)(p+8)=func_L01_00444740(m+0x10,p+0x30,0,func_00388770(p),0.0f);
        if (func_00388800(m+0x10,p+0x30)<0.5f) {
            m[0x20]=0; *(u16 *)(m+0x96)=0;
            func_003BD360(*(void **)(p+0x18)); *(s32 *)(p+0x18)=0;
            func_003BD360(*(void **)(p+0x1C)); *(s32 *)(p+0x1C)=0;
            (*(u8 **)(m+0xB8))[0xBC]=0;
            slot=D_001A30B0+*(s32 *)(p+0x24)*128;
            if (*(s32 *)(p+0x24)!=-1 && *(u8 **)(slot+0xDC)==m && slot[0xD0]) func_0039FB08(*(s32 *)(p+0x24));
            *(s32 *)(p+0x24)=-1;
            *(u16 *)(m+0x34)|=2;
            return;
        }
    }
    effects:
    if (!*(void **)(p+0x18)) {
        *(void **)(p+0x18)=func_003BCFB0(0x1743,0x80);
        func_L01_00452E70(*(void **)(p+0x18),m);
        *(u16 *)(*(u8 **)(p+0x18)+0x34)|=2;
        *(u16 *)(*(u8 **)(p+0x18)+0x34)|=4;
        *(u16 *)(*(u8 **)(p+0x18)+0x34)|=0x100;
        (*(u8 **)(p+0x18))[0x23]=0x20;
        *(void **)(p+0x1C)=func_003BCFB0(0x1743,0x80);
        func_L01_00452E70(*(void **)(p+0x1C),m);
        *(u16 *)(*(u8 **)(p+0x1C)+0x34)|=2;
        *(u16 *)(*(u8 **)(p+0x1C)+0x34)|=4;
        *(u16 *)(*(u8 **)(p+0x1C)+0x34)|=0x100;
        (*(u8 **)(p+0x1C))[0x23]=0x10;
    } else {
        *(Q_350928 *)(*(u8 **)(p+0x18)+0xC0)=*(Q_350928 *)(m+0xC0);
        *(Q_350928 *)(*(u8 **)(p+0x18)+0xD0)=*(Q_350928 *)(m+0xD0);
        *(Q_350928 *)(*(u8 **)(p+0x18)+0xE0)=*(Q_350928 *)(m+0xE0);
        *(Q_350928 *)(*(u8 **)(p+0x18)+0x10)=*(Q_350928 *)(m+0x10);
        func_00388830(&vb,p,-0.5f);
        add_350928(*(u8 **)(p+0x18)+0x10,*(u8 **)(p+0x18)+0x10,&vb);
        func_003C26C8(*(void **)(p+0x18));
        *(Q_350928 *)(*(u8 **)(p+0x1C)+0xC0)=*(Q_350928 *)(m+0xC0);
        *(Q_350928 *)(*(u8 **)(p+0x1C)+0xD0)=*(Q_350928 *)(m+0xD0);
        *(Q_350928 *)(*(u8 **)(p+0x1C)+0xE0)=*(Q_350928 *)(m+0xE0);
        add_350928(*(u8 **)(p+0x1C)+0x10,*(u8 **)(p+0x18)+0x10,&vb);
        func_003C26C8(*(void **)(p+0x1C));
    }
    if (!(D_L02_001DE540[0]&1)) func_L02_00350840(m);
    func_L01_00402498(D_L02_00350728,m);
}
/* localdecomp:end func_L02_00350928 */
