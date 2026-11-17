/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_004038A8, the NTSC-U twin of func_L08_00406AB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L08_00406AB0.c's current line.
 * Worker's note: 239 diff; best log w62/func_L08_004038A8.check01.log. Allowed default assembler lowers 210000.0f/2100.0f/4200.0f/0.00027777778f to gp .lit4 loads where retail has lui/ori/mtc1; no flags_alt provided and forbidden flags not tried. Named scratchpad base also adds addiu 0 absent in retail. Structural l
 */
#include "common.h"
/* localdecomp:start func_L08_004038A8 */
typedef struct {f32 x,y,z,w;} __attribute__((aligned(16))) V_4038A8;
typedef struct {V_4038A8 a,b;} Particle_4038A8;
extern Particle_4038A8 D_L08_70000000[];
extern u8 D_L08_001D66B0[];
typedef struct {u8 pad[0xD4];u8 *bytes;} G_4038A8;
extern G_4038A8 D_L08_0021EB18;
extern s32 func_003BD668(void *,s32);
extern void func_0037E2F0(void *,f32,f32);
extern f32 func_L01_00440918(f32,f32);
extern f32 func_0037E250(f32,f32);
extern s32 func_0037E208(s32,s32);
extern void func_003886C0(void *,void *,void *,f32);
extern u8 *func_L01_0046DCB8(void *,void *,s32,u32,s32,s32,s32,s32,f32,f32,f32);
s32 func_L08_004038A8(void *source,u32 color1,u32 color2,s32 count,f32 low,f32 high,f32 scale) {
    V_4038A8 a,b,c;
    s32 total=func_003BD668(source,0);
    s32 lo,hi,i,j,n;
    f32 inv,size,speed;
    u8 *out;
    Particle_4038A8 *p;
    if (total==0) return 0;
    lo=(s32)(scale*10.0f);
    hi=(s32)(scale*15.0f);
    inv=1.0f/scale;
    p=D_L08_70000000;
    for(i=0;i<total;i++,p++) {
        for(j=count;j>0;j--) {
            if(p->b.w==0.0f) {
                a=p->a;
                a.w=1.0f;
                func_0037E2F0(&b,0.0f,p->a.w);
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(a) : "m"(a), "m"(b));
                n=(s32)func_L01_00440918(2.0f,5.0f);
                size=func_0037E250(low,high)*p->a.w;
                speed=(inv*-3.0f)*0.00027777778f;
                func_L01_0046DCB8(&a,D_L08_001D66B0,func_0037E208(lo,hi),color1,n,127,127,1,size*210000.0f,2100.0f,speed);
                n=-(n*2);
                size*=6.0f;
                out=func_L01_0046DCB8(&a,D_L08_001D66B0,func_0037E208(lo,hi),color2,n,48,48,0,size*210000.0f,4200.0f,speed);
            } else {
                a=p->a;
                a.w=1.0f;
                b=p->b;
                b.w=1.0f;
                func_003886C0(&c,&a,&b,func_0037E250(0.0f,1.0f));
                c.x+=func_0037E250(-p->a.w*0.4f,p->a.w*0.4f);
                c.y+=func_0037E250(-p->a.w*0.4f,p->a.w*0.4f);
                c.z+=func_0037E250(-p->a.w*0.4f,p->a.w*0.4f);
                n=(s32)func_L01_00440918(2.0f,5.0f);
                size=func_0037E250(low,high)*p->a.w;
                size=inv*size;
                speed=(inv*-3.0f)*0.00027777778f;
                func_L01_0046DCB8(&c,D_L08_001D66B0,func_0037E208(lo,hi),color1,n,127,127,1,size*210000.0f,2100.0f,speed);
                n=-(n*2);
                size*=6.0f;
                out=func_L01_0046DCB8(&c,D_L08_001D66B0,func_0037E208(lo,hi),color2,n,48,48,0,size*210000.0f,4200.0f,speed);
            }
            if(out)out[2]=D_L08_0021EB18.bytes[0];
        }
    }
    return 1;
}
/* localdecomp:end func_L08_004038A8 */
