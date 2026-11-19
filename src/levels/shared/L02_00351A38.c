#include "common.h"

/* localdecomp:start func_L02_00351A38 */
#include "vu0.h"
typedef int Q_00351A38 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00351A38;
extern u8 D_001A30B0[], D_001A4BE0[];
extern V_00351A38 D_L02_001D66B0 __attribute__((section(".sdata")));
extern s32 D_L02_001DE4C0;
extern void func_L02_00351838(void *);
extern f32 func_0038CF38(void *,void *);
extern void func_003C2EC0(void *,s32,void *);
extern void func_003C2F58(void *,s32,void *);
extern void func_003C4098(void *,void *,void *,f32);
extern void func_0038CF68(void *,void *,f32);
extern void func_0038D890(void *,void *,void *,f32);
extern s32 func_003A52A0(s32,s32,void *);
extern void func_0038CE20(void *,void *,f32);
extern u8 *func_00382348(void *);
extern void func_L01_00446760(void *,void *,s32,void *,f32);
extern void func_003D4D00(void *,s32,void *,void *,f32);
extern void func_003C4138(void *,f32,f32);
extern f32 func_0038CEA8(void *);
extern f32 func_L01_00447878(void *,void *,s32,f32,f32);
extern void func_L01_0044C280(void *,void *,void *,s32,f32);
extern void func_003C2880(void *);
extern void func_003A4F28(s32);
extern u8 *func_003C24B0(s32,s32);
extern void func_L01_00456160(void *,void *);
extern void func_003C7C38(void *);
extern void func_L02_00351950(void *);
extern void func_L01_00404808(void *,void *);
/* points the trail (p) at its target moby p+0x20: the hero's point at +0xD0, or the moby's position plus
   the value at +0x10 of what func_00382348 returns for it. Inlined at both arms of the 0x920 test (retail
   has the code twice, its tails cross-jumped). */
static __inline__ void retarget_00351A38(u8 *p) {
    u8 *hero=D_001A4BE0;
    if (*(s32 *)(p+0x20)==*(s32 *)(hero+0x25C0)) {
        *(Q_00351A38 *)(p+0x30)=*(Q_00351A38 *)(hero+0xD0);
    } else {
        u8 *q=func_00382348(*(void **)(p+0x20));
        *(Q_00351A38 *)(p+0x30)=*(Q_00351A38 *)(*(u8 **)(p+0x20)+0x10);
        if (q) *(f32 *)(p+0x38)+=*(f32 *)(q+0x10);
    }
}
void func_L02_00351A38(u8 *m) {
    u8 *pos;
    f32 dmg;
    u8 *p=*(u8 **)(m+0x68), *ownerp=*(u8 **)(*(u8 **)(m+0xB8)+0x68);
    union { V_00351A38 mtx[4]; struct { V_00351A38 seg[2]; u8 hit[0x20]; } ray; } u;
    V_00351A38 va, vb, vc, vd;
    *(u16 *)(m+0x34)|=0x100;
    if (m[0x20]==1 && func_0038CF38(m+0x10,p+0x30)<1.5f && *(u16 *)(m+0x96)>=3) {
        func_003C2EC0(*(void **)(m+0xB8),0,u.mtx);
        va=*(V_00351A38 *)(m+0xE0); vb=u.mtx[2];
        func_003C4098(m+0xE0,&va,&vb,0.25f);
        func_0038CF68(m+0xE0,m+0xE0,1.0f);
        func_0038D890(m+0xC0,m+0xC0,m+0xE0,1.1170108f);
        func_0038D890(m+0xD0,m+0xD0,m+0xE0,1.1170108f);
    } else {
        u.mtx[0]=D_L02_001D66B0;
        u.mtx[0].z=1.0f;
        u.mtx[1]=*(V_00351A38 *)(m+0xE0);
        func_003C4098(m+0xE0,&u.mtx[1],&u.mtx[0],0.041f);
        func_0038CF68(m+0xE0,m+0xE0,1.0f);
        func_0038D890(m+0xC0,m+0xC0,m+0xE0,1.1170108f);
        func_0038D890(m+0xD0,m+0xD0,m+0xE0,1.1170108f);
    }
    {
        s32 i=*(s32 *)(p+0x24);
        u8 *t;
        if (i==-1 || (t=D_001A30B0+(i<<7), *(void **)(t+0xDC)!=m) || t[0xD0]==0) *(s32 *)(p+0x24)=func_003A52A0(0,4,m);
    }
    pos=m+0x10;
    u.ray.seg[0]=*(V_00351A38 *)(m+0x10);
    func_0038CF68(&u.ray.seg[1],p,0.5f);
    func_0038CE20(&u.ray.seg[1],&u.ray.seg[1],2.0f);
    u.ray.seg[1].w=5627.925f;
    dmg=func_00382348(*(void **)(m+0xB8))[0x15];
    func_L01_00446760(u.ray.hit,m,0x10001,&u.ray.seg[1],dmg);
    u.ray.hit[0x19]=1;
    *(u16 *)(u.ray.hit+0x1A)=*(u16 *)(m+0xAA);
    u.ray.hit[0x18]=0;
    func_003D4D00(u.ray.seg,0,*(void **)(m+0xB8),u.ray.hit,0.35f);
    if (m[0x20]==0) {
        ++*(u16 *)(m+0x96);
        func_003C4138(p+0x14,0.25f,0.0075f);
        *(f32 *)(p+8)=func_L01_00447878(pos,p+0x30,0,func_0038CEA8(p),0.0f);
        func_0038CF68(p,p,func_0038CEA8(p));
        vec_add_ba(pos,pos,p);
        vec_sub_ba(&vb,p+0x30,pos); vb.z=0.0f;
        func_0038CF68(&vc,p,1.0f);
        func_L01_0044C280(p,p,&vb,0,*(f32 *)(p+0x14));
        if (func_0038CF38(pos,p+0x30)<1.5f || *(u16 *)(m+0x96)>=126 || func_0038CF38(pos,*(u8 **)(m+0xB8)+0x10)>50.0f) {
            *(u16 *)(m+0x96)=0;
            m[0x20]=1;
            *(Q_00351A38 *)(p+0x30)=*(Q_00351A38 *)(*(u8 **)(m+0xB8)+0x10);
            *(f32 *)(p+0x14)=0.0025f;
        }
        if (*(s32 *)(ownerp+0x920)==0) {
            if (func_0038CF38(pos,p+0x30)>4.0f) retarget_00351A38(p);
        } else {
            if (func_0038CF38(pos,p+0x30)>3.25f) retarget_00351A38(p);
        }
    } else if (m[0x20]==1) {
        ++*(u16 *)(m+0x96);
        func_003C4138(p+0x14,0.5f,0.0075f);
        func_003C2F58(*(void **)(m+0xB8),0,&vb);
        *(Q_00351A38 *)(p+0x30)=*(Q_00351A38 *)&vb;
        func_0038CF68(p,p,func_0038CEA8(p));
        vec_add_ba(pos,pos,p);
        vec_sub_ba(&vc,p+0x30,pos); vc.z=0;
        func_0038CF68(&vd,p,1.0f);
        func_L01_0044C280(p,p,&vc,0,*(f32 *)(p+0x14));
        *(f32 *)(p+8)=func_L01_00447878(pos,p+0x30,0,func_0038CEA8(p),0.0f);
        if (func_0038CF38(pos,p+0x30)<0.5f) {
            m[0x20]=0; *(u16 *)(m+0x96)=0;
            func_003C2880(*(void **)(p+0x18)); *(s32 *)(p+0x18)=0;
            func_003C2880(*(void **)(p+0x1C)); *(s32 *)(p+0x1C)=0;
            (*(u8 **)(m+0xB8))[0xBC]=0;
            {
                s32 i=*(s32 *)(p+0x24);
                u8 *t;
                if (i!=-1 && (t=D_001A30B0+(i<<7), *(void **)(t+0xDC)==m) && t[0xD0]!=0) func_003A4F28(i);
            }
            *(s32 *)(p+0x24)=-1;
            *(u16 *)(m+0x34)|=2;
            return;
        }
    }
    if (!*(void **)(p+0x18)) {
        *(void **)(p+0x18)=func_003C24B0(0x1743,0x80);
        func_L01_00456160(*(void **)(p+0x18),m);
        *(u16 *)(*(u8 **)(p+0x18)+0x34)|=2;
        *(u16 *)(*(u8 **)(p+0x18)+0x34)|=4;
        *(u16 *)(*(u8 **)(p+0x18)+0x34)|=0x100;
        (*(u8 **)(p+0x18))[0x23]=0x20;
        *(void **)(p+0x1C)=func_003C24B0(0x1743,0x80);
        func_L01_00456160(*(void **)(p+0x1C),m);
        *(u16 *)(*(u8 **)(p+0x1C)+0x34)|=2;
        *(u16 *)(*(u8 **)(p+0x1C)+0x34)|=4;
        *(u16 *)(*(u8 **)(p+0x1C)+0x34)|=0x100;
        (*(u8 **)(p+0x1C))[0x23]=0x10;
    } else {
        *(Q_00351A38 *)(*(u8 **)(p+0x18)+0xC0)=*(Q_00351A38 *)(m+0xC0);
        *(Q_00351A38 *)(*(u8 **)(p+0x18)+0xD0)=*(Q_00351A38 *)(m+0xD0);
        *(Q_00351A38 *)(*(u8 **)(p+0x18)+0xE0)=*(Q_00351A38 *)(m+0xE0);
        *(Q_00351A38 *)(*(u8 **)(p+0x18)+0x10)=*(Q_00351A38 *)(m+0x10);
        func_0038CF68(&vb,p,-0.5f);
        vec_add_ba(*(u8 **)(p+0x18)+0x10,*(u8 **)(p+0x18)+0x10,&vb);
        func_003C7C38(*(void **)(p+0x18));
        *(Q_00351A38 *)(*(u8 **)(p+0x1C)+0xC0)=*(Q_00351A38 *)(m+0xC0);
        *(Q_00351A38 *)(*(u8 **)(p+0x1C)+0xD0)=*(Q_00351A38 *)(m+0xD0);
        *(Q_00351A38 *)(*(u8 **)(p+0x1C)+0xE0)=*(Q_00351A38 *)(m+0xE0);
        vec_add_ba(*(u8 **)(p+0x1C)+0x10,*(u8 **)(p+0x18)+0x10,&vb);
        func_003C7C38(*(void **)(p+0x1C));
    }
    if (!(D_L02_001DE4C0&1)) func_L02_00351950(m);
    func_L01_00404808(func_L02_00351838,m);
}
/* localdecomp:end func_L02_00351A38 */
