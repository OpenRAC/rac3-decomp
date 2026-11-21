/* functional: high. Behaviour verified block by block. */
#include "common.h"
/* localdecomp:start func_L07_003C9280 */
#include "vu0.h"
typedef struct { u8 pad[0x18]; u8 kind,flags; u16 id; u8 rest[0x14]; } Hit_003C9280;
extern u8 *D_L07_001E8C18;
extern u8 *D_001A71A0;
void func_L07_003C9280(u8 *o) {
    extern void func_003C2F58(u8 *,s32,f32 *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_00446760(void *,void *,s32,void *,f32);
    extern void func_L01_004CB320(void);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern void func_L01_004CB358(void);
    extern f32 func_0038CF00(void *,void *);
    vu0_v4 a,b,direction;
    Hit_003C9280 hit;
    u8 *p=*(u8 **)(o+0x68);
    s32 result;
    f32 x,y;
    func_003C2F58(o,p[0x4DC],&a.x);
    if(*(f32 *)(p+0x488)==1.0f) {
        *(vu0_q *)&b=*(vu0_q *)(p+0x470);
    } else {
        vec_sub_ba(&b,p+0x470,&a);
        func_0038CE20(&b,&b,*(f32 *)(p+0x488));
        vec_add_ab(&b,&a,&b);
    }
    vec_sub_ab(&direction,&b,&a);
    direction.z=0;
    func_0038CF68(&direction,&direction,1.0f);
    direction.z=1.0f;
    direction.w=5627.9248046875f;
    func_L01_00446760(&hit,o,0x10001,&direction,(f32)p[0x44]);
    hit.kind=5;
    hit.flags=2;
    hit.id=*(u16 *)(o+0xAA);
    func_L01_004CB320();
    result=func_003D3CB0(&a,&b,0,o,&hit);
    if(result && D_L07_001E8C18 && *(s16 *)(D_L07_001E8C18+0xAA)==0x186D && D_L07_001E8C18[0x20]!=2 && D_L07_001E8C18[0x20]!=5)
        D_L07_001E8C18[0x20]=4;
    func_L01_004CB358();
    if(result) {
        x=func_0038CF00(&a,&D_L07_001E8C20);
        y=func_0038CF00(&a,p+0x470);
        x=x/y;
        *(f32 *)(p+0x488)=x;
        if(x>1.0f) *(f32 *)(p+0x488)=1.0f;
        if(*(u8 **)((u8 *)&D_L07_001E8C20-8)==D_001A71A0) p[0x4D7]=1;
    }
}
/* localdecomp:end func_L07_003C9280 */
