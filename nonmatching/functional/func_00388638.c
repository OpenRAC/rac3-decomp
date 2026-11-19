/* functional: high. Read against all 235 PAL instructions: offsets, gp-relative constants (D_001D59B0/B4/B8/BC, 5948..5964), vector call arguments, packet layout and the speed>0 / speed<=0 wrap logic agree. Bytes differ (282 words with boot_elf as retail: frame 0x160 vs 0x140, float global bases) which does not change behaviour. The snippet needed 'extern u8 D_00222480[]' (the file declares it as an array of S_00222500_0037E7D8); retail reads a quad from it. */
extern u8 D_00222480[];
#include "vu0.h"
typedef struct { u8 pad0[0x24]; f32 width,height; u8 pad2C[8]; f32 speed,phase; s32 timer; } O_00388638;
typedef struct { vu0_v4 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a,tex,c,d; } P_00388638;
extern f32 D_001D59B0,D_001D59B4,D_001D59BC;
extern s32 D_001D59B8;
extern f32 D_001D5948,D_001D5958;
extern f32 D_001D594C[],D_001D5950[],D_001D5954[];
extern f32 D_001D595C[],D_001D5960[],D_001D5964[];
void func_00388638(O_00388638 *o, vu0_v4 *v, long tex) {
    extern s32 func_0038CEB0(void *);
    extern void func_003C4450(vu0_v4 *,vu0_v4,vu0_v4,f32);
    extern void func_0038D270(vu0_v4 *,vu0_v4,vu0_v4);
    extern f32 func_0038D248(void *,void *);
    extern void func_0038D348(s32,s32,f32);
    extern f32 func_003C4440(f32,f32,f32);
    extern void func_003D3158();
    extern s32 func_00382878(s32,s32);
    P_00388638 p;
    vu0_v4 va,vb,normal,delta,b,c,d;
    f32 angle;
    if(func_0038CEB0(&o->timer)) {
        p.c=0xFF9000000260L;
        p.d=0x8000000044L;
        p.tex=tex;
        p.a=5;
        p.rgba[0]=D_001D59B8;
        p.rgba[3]=D_001D59B8;
        p.rgba[2]=D_001D59B8;
        p.rgba[1]=D_001D59B8;
        *(vu0_q *)&va=*(vu0_q *)&v[0];
        *(vu0_q *)&vb=*(vu0_q *)&v[1];
        func_003C4450(&p.pos[0],va,vb,o->phase-D_001D59B0);
        *(vu0_q *)&va=*(vu0_q *)&v[0];
        *(vu0_q *)&vb=*(vu0_q *)&v[1];
        func_003C4450(&p.pos[1],va,vb,o->phase+D_001D59B0);
        *(vu0_q *)&va=*(vu0_q *)&v[2];
        *(vu0_q *)&vb=*(vu0_q *)&v[3];
        func_003C4450(&p.pos[2],va,vb,o->phase-D_001D59B0);
        *(vu0_q *)&va=*(vu0_q *)&v[2];
        *(vu0_q *)&vb=*(vu0_q *)&v[3];
        func_003C4450(&p.pos[3],va,vb,o->phase+D_001D59B0);
        vec_copy(&b,&v[1]);
        vec_copy(&d,&v[2]);
        vec_sub_ba(&c,&b,&v[0]);
        vec_sub_ab(&d,&d,&v[0]);
        *(vu0_q *)&va=*(vu0_q *)&c;
        *(vu0_q *)&vb=*(vu0_q *)&d;
        func_0038D270(&normal,va,vb);
        vec_sub_ba(&delta,(void *)D_00222480,&v[0]);
        { f32 side=func_0038D248(&normal,&delta);
          angle=D_001D59BC;
          if(!(side>0.0f)) angle=-angle; }
        func_0038D348((s32)&normal,(s32)&normal,angle);
        vec_add_ba(&p.pos[0],&p.pos[0],&normal);
        vec_add_ba(&p.pos[1],&p.pos[1],&normal);
        vec_add_ab(&p.pos[2],&p.pos[2],&normal);
        vec_add_ab(&p.pos[3],&p.pos[3],&normal);
        p.uv[0][0]=o->width*D_001D5948+0.5f+D_001D59B4;
        p.uv[1][0]=o->width*D_001D594C[0]+0.5f+D_001D59B4;
        p.uv[2][0]=o->width*D_001D5950[0]+0.5f-D_001D59B4;
        p.uv[3][0]=o->width*D_001D5954[0]+0.5f-D_001D59B4;
        p.uv[0][1]=o->height*func_003C4440(D_001D5958,D_001D595C[0],o->phase-D_001D59B0)+0.5f;
        p.uv[1][1]=o->height*func_003C4440(D_001D595C[0],D_001D5958,o->phase-D_001D59B0)+0.5f;
        p.uv[2][1]=o->height*func_003C4440(D_001D5960[0],D_001D5964[0],o->phase-D_001D59B0)+0.5f;
        p.uv[3][1]=o->height*func_003C4440(D_001D5964[0],D_001D5960[0],o->phase-D_001D59B0)+0.5f;
        func_003D3158(&p,0,0);
        o->phase+=o->speed;
        if(o->speed>0.0f) {
            if(o->phase>=1.0f-D_001D59B0) {
                o->phase-=1.0f;
                o->timer=(func_00382878(30,120)*5+2)/6;
            }
            if(o->phase<D_001D59B0) o->phase=D_001D59B0;
        } else {
            if(o->phase<=D_001D59B0) {
                o->phase+=1.0f;
                o->timer=(func_00382878(30,120)*5+2)/6;
            }
            if(o->phase>=1.0f-D_001D59B0) o->phase=1.0f-D_001D59B0;
        }
    }
}
