/* functional: high. Camera collision resolve: computes the camera position (look+0xB0 + spring), probes it against hero capsule radius, level (func_003FB640) and moby (func_003FE1D8) collision up to 3 passes, nudging to the hit positions and updating steer+0x38 from the hit normal, then runs func_003E75A8 and writes the steer target (steer+0x20). Branches, constants and callee args checked against retail; only VU0 scheduling and register allocation differ */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003E77B0;
typedef int Quad_003E77B0 __attribute__((mode(TI)));
extern u8 D_L01_001E2AA0[];
extern Quad_003E77B0 D_L01_001EAA20[];
extern Quad_003E77B0 D_L01_001EAA30[];
static __inline__ void add_003E77B0(Vec_003E77B0 *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*(Vec_003E77B0 *)a), "m"(*(Vec_003E77B0 *)b) : "vf1","vf2");
}
static __inline__ void sub_003E77B0(Vec_003E77B0 *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*(Vec_003E77B0 *)a), "m"(*(Vec_003E77B0 *)b) : "vf1","vf2");
}
s32 func_L01_003E77B0(u8 *obj) {
    extern f32 func_0038CE68(f32 *,f32 *);
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,s32,s32);
    extern s32 func_L01_003E4050(void *,f32);
    extern s32 func_L01_003FB640(void *,s32,void *,f32);
    extern s32 func_L01_003FE1D8(void *,s32,f32);
    extern s32 func_L01_003E75A8(u8 *,void *,s32,s32);
    Vec_003E77B0 pos,delta,normal;
    u8 *follow=*(u8 **)(obj+0x70);
    u8 *motion=follow+0x60;
    u8 *spring=follow+0x180;
    u8 *steer=follow+0x210;
    u8 *entry=D_L01_001E2AA0+*(s32 *)(obj+0x94)*1120;
    u8 *hero=*(u8 **)(entry-0x10);
    u8 *hero_follow=*(u8 **)(hero+0x70);
    s32 mask=*(s32 *)(steer+0x48);
    f32 radius;
    s32 collided=0,changed=0,i,again,result;
    add_003E77B0(&pos,follow+0xb0,follow+0x180);
    *(s16 *)(steer+0x38)=2;
    sub_003E77B0(&delta,obj+0x30,&pos);
    radius=*(f32 *)(hero_follow+0x254)* *(f32 *)(hero_follow+0x24c)*(*(f32 *)(hero_follow+0x250)-1.0f)+0.35f;
    if (func_0038CE68(&delta.x,&delta.x)>radius*radius && func_003D3CB0(obj+0x30,&pos,mask,0,0)) {
        *(Quad_003E77B0 *)&pos=D_L01_001EAA20[0];
        func_0038CF68(&delta.x,(f32 *)(D_L01_001EAA20+2),0.005f);
        add_003E77B0(&pos,&pos,&delta);
    }
    for (i=0;i<3;i++) {
        if (func_L01_003E4050(&pos,radius)) collided=1;
        again=0;
        if (func_L01_003FB640(&pos,mask,*(void **)(entry+0xc4),radius)) {
            *(Quad_003E77B0 *)&pos=D_L01_001EAA30[0];
            again=1;changed=1;
        }
        if (func_L01_003FE1D8(&pos,0,radius)) {
            *(Quad_003E77B0 *)&pos=D_L01_001EAA30[0];
            again=1;changed=1;
        }
        if (!again) break;
        if (*(s16 *)(steer+0x38)!=0) {
            f32 dot;
            sub_003E77B0(&normal,D_L01_001EAA20,&pos);
            func_0038CF68(&normal.x,&normal.x,1.0f);
            dot=func_0038CE68((f32 *)(entry+0x30),&normal.x);
            if (dot>0.75f) *(s16 *)(steer+0x38)=1;
            else if (dot< -0.5f) *(s16 *)(steer+0x38)=-1;
            else *(s16 *)(steer+0x38)=0;
        }
    }
    result=func_L01_003E75A8(obj,&pos,collided,changed);
    add_003E77B0((Vec_003E77B0 *)(steer+0x20),motion+0x50,spring);
    if (*(s16 *)(steer+0x38)==2) *(s16 *)(steer+0x38)=0;
    return result;
}
