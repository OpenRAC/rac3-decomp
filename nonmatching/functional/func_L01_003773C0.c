/* functional: high. Verified vs PAL asm: segment loop (count=len/0.1), per-spark rand/colour/alpha (alpha never equals 0x40 in retail, so byte 3 is always 0x44, kept), smoke puff gated on v[0x34]<50, spinning-angle accumulators D_1E1D60.., 3-point rotated ring with sprite spawn; gp-relative globals mapped (D_001DDAA0/AA4/AB0 via gp+0x11F0/0x11F4/0x1200); func_0038CF68 uses the file's (scale,dst,src) prototype; $vf register names added to asm. */
#include "vu0.h"
extern f32 D_001A4EC0[];
typedef struct { u8 pad[0x5C]; u8 *type; } ParticleGlobal_003773C0;
extern ParticleGlobal_003773C0 D_L01_00221098;
extern u8 *D_L01_0022116C;
extern vu0_v4 D_L01_001DDA70[] __attribute__((section(".sdata")));
extern f32 D_L01_001DDAA0,D_L01_001DDAA4,D_L01_001DDAB0;
extern f32 D_L01_001DDAB4 __attribute__((section(".data")));
extern f32 D_L01_001DDAB8 __attribute__((section(".data")));
extern f32 D_L01_001E1D60[];
__asm__(".extern D_L01_001DDAA0, 4");
__asm__(".extern D_L01_001DDAA4, 4");
__asm__(".extern D_L01_001DDAB0, 4");
void func_L01_003773C0(u8 *m,vu0_v4 *a,vu0_v4 *b) {
    extern f32 func_0038CEA8(void *);
    extern f32 func_L01_00443A18(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
    extern s32 func_00382468(s32);
    extern void func_003C4C18(void *,f32);
    extern u8 *func_L01_00465738(void *,void *,s32,s32,s32,s32,s32,s32,f32,s32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_0038D308(void *,void *);
    extern void func_0038D000(void *,void *,void *);
    extern u8 *func_L01_004713C8(void *,void *,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    vu0_v4 first,second,velocity,current,delta,speed;
    vu0_v4 matrix[3],out;
    u8 *v=*(u8 **)(m+0x68);
    f32 length;
    s32 count,i;
    vu0_v4 *point;
    *(vu0_q *)&first=*(vu0_q *)a;
    *(vu0_q *)&second=*(vu0_q *)b;
    length=func_0038CEA8(v);
    count=(s32)(length/0.1f);
    *(vu0_q *)&current=*(vu0_q *)&second;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(first), "m"(second) : "vf1","vf2");
    func_0038CF68(length/(f32)count, &delta, &delta);
    for(i=0;i<count;i++) {
        s32 kind=(s32)func_L01_00443A18(1.0f,3.0f);
        s32 life,alpha,color;
        u8 *particle;
        func_0038CE20((f32 *)&velocity,D_001A4EC0,-(func_003824E0(0.1f,0.2f)*0.020000001f));
        life=func_00382498(3,6);
        if(func_0013D3E0()&2) { alpha=96;color=0xFF7F40; }
        else { alpha=127;color=0xFF4040; }
        particle=func_L01_0046A610(&current,&velocity,(life*5+2)/6,alpha,color,kind,63000.00390625f,10000.0f,1.0f,0.0f,0.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(current) : "m"(current), "m"(delta) : "vf1","vf2");
        if(particle) {
            particle[2]=*D_L01_00221098.type;
            particle[3]=alpha==64?72:68;
        }
    }
    if(*(s32 *)(v+0x34)<50 && func_00382468(2)) {
        s32 color=0x7F80DFFF;
        u8 *particle;
        func_0038CE20((f32 *)&speed,(f32 *)v,-0.040000003f);
        func_003C4C18(&speed,0.12000000476837158f);
        speed.z+=0.06000000238418579f;
        if(func_00382468(2)) color=0x7F407FFF;
        particle=func_L01_00465738(m+0x10,&speed,color,255,func_00382498(8,17),0,-1,-1,94500.0f,0);
        if(particle) {
            *(f32 *)(particle+0x2C)=0.002400000113993883f;
            particle[2]=*D_L01_0022116C;
        }
    }
    D_L01_001E1D60[0]=func_0038DAB8(D_L01_001E1D60[0],D_L01_001DDAB0*0.017453292f*0.020000001f);
    D_L01_001E1D60[1]=func_0038DAB8(D_L01_001E1D60[1],D_L01_001DDAB4*0.017453292f*0.020000001f);
    D_L01_001E1D60[2]=func_0038DAB8(D_L01_001E1D60[2],D_L01_001DDAB8*0.017453292f*0.020000001f);
    func_0038D308(matrix,D_L01_001E1D60);
    for(i=2,point=D_L01_001DDA70;i>=0;i--,point++) {
        u8 *particle;
        s32 kind;
        f32 size;
        func_0038D000(&out,point,matrix);
        if(*(s32 *)(v+0x34)>=6) func_0038CF68(D_L01_001DDAA0, &out, &out);
        else func_0038CF68(0.0f, &out, &out);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(out) : "m"(out), "m"(*(vu0_v4 *)(m+0x10)) : "vf1","vf2");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(speed) : "m"(out), "m"(*(vu0_v4 *)(m+0x10)) : "vf1","vf2");
        func_0038CF68(D_L01_001DDAA4*0.020000001f, &speed, &speed);
        kind=(s32)func_L01_00443A18(2.0f,5.0f);
        size=func_003824E0(0.11999999731779099f,0.18000000715255737f);
        particle=func_L01_004713C8(&out,&speed,12,0x801020,kind,111,0,6,63000.00390625f,size*210000.0f,0.0f);
        if(particle) particle[3]=func_00382468(4)?72:68;
    }
}
