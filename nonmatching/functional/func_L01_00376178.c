/* functional: high. Verified vs PAL asm: packet init (tex arg, 0x4A flags, colours, uv corners), basis build (cross products, optional rotation by angle), 4 scaled corners, three GS-state calls (0x31001, 0x53001, 0x5360B), second pass with stretched uv via func_00389478; func_0038CF68 calls rewritten to the file's (scale,dst,src) prototype. */
#include "vu0.h"
typedef struct { vu0_q p[4]; u32 color[4]; f32 uv[4][2]; u8 pad[24]; unsigned long flags; } Packet_00376178;
extern vu0_v4 D_L01_001E2A40;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[4];
void func_L01_00376178(void *position, s32 texture, f32 size, f32 shift, f32 angle, f32 stretch) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, unsigned long);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, f32 *, f32 *);
    Packet_00376178 p;
    vu0_v4 basis[4];
    vu0_v4 temp;
    union { vu0_v4 rot[3]; struct { vu0_v4 center, delta, extra; } v; } work;

    func_003D93B0(&p,texture,1,128);
    basis[3]=*(vu0_v4 *)position;
    p.flags=0x800000004AUL;
    p.color[1]=p.color[2]=p.color[3]=p.color[0]=0x80808080;
    p.uv[0][0]=0.0f; p.uv[0][1]=0.0f;
    p.uv[1][0]=0.0f; p.uv[1][1]=1.0f;
    p.uv[2][0]=1.0f; p.uv[2][1]=0.0f;
    p.uv[3][0]=1.0f; p.uv[3][1]=1.0f;
    __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(basis[0]) : "m"(D_L01_001E2A40), "m"(basis[3]) : "vf1","vf2");
    func_0038CF68(1.0f, &basis[0], &basis[0]);
    func_0038CE90(&basis[1],&basis[0],&D_001A4EC0);
    func_0038CF68(1.0f, &basis[1], &basis[1]);
    func_0038CE90(&basis[2],&basis[1],&basis[0]);
    if (angle!=0.0f) {
        *(vu0_q *)&temp=0;
        temp.x=angle;
        func_0038D308(work.rot,&temp);
        func_0038D5F0(basis,basis,work.rot);
    }
    func_0038CE20(&temp,basis,shift);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(basis[3]) : "m"(basis[3]),"m"(temp) : "vf1","vf2");
    { s32 i;
    for(i=3;i>=0;i--) {
        s32 j=3-i;
        func_0038CE20(&p.p[j],&D_L01_001D7C50[j],size);
        func_0038D028(&p.p[j],&p.p[j],basis);
    }
    }
    func_003A9440(0x47,0x31001);
    func_003D2DA0(&p,0,0);
    work.v.center=*(vu0_v4 *)&p.p[0];
    { s32 i;
    for(i=2;i>=0;i--) {
        s32 j=3-i;
        __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(work.v.center) : "m"(work.v.center),"m"(*(vu0_v4 *)&p.p[j]) : "vf1","vf2");
    }
    }
    func_0038CE20(&work.v.center,&work.v.center,0.25f);
    { s32 i;
    for(i=3;i>=0;i--) {
        s32 j=3-i;
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(work.v.delta) : "m"(work.v.center),"m"(*(vu0_v4 *)&p.p[j]) : "vf1","vf2");
        func_0038CE20(&work.v.delta,&work.v.delta,stretch);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(work.v.delta) : "m"(work.v.center),"m"(work.v.delta) : "vf1","vf2");
        func_00389478(&work.v.delta,&p.uv[j][0],&p.uv[j][1]);
    }
    }
    func_003D93B0(&p,-1,1,128);
    p.flags=0x2000000054UL;
    func_003A9440(0x47,0x53001);
    func_003D2DA0(&p,0,0);
    func_003A9440(0x47,0x5360B);
}
