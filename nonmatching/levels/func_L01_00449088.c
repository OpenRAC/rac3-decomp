/* NTSC-U draft (Codex wave 3): C of func_L01_00445F50, the NTSC-U twin of func_L01_00449088, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 304 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_00445F50", whose code is not the PAL one).
 * Worker's note: 304 diff; best log func_L01_00445F50.check01.log; GNU literal-pool loads differ from retail inline constants 0x48389200/0x48CD1400/0x3991A2B4/0x3ECCCCCD; no flags_alt; VU source retained; forbidden flags not tried
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00445F50 */
extern vu0_v4 D_L01_70000000[];
extern u8 D_L01_00221118[], D_L01_001D66B0[];
extern s32 func_003BD668(void *, s32);
extern void *func_0037E0B8(void *);
extern s32 func_L01_00444800(void *, s32, void *, s32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32,s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32,f32);
extern void func_003886C0(void *,void *,void *,f32);
extern void func_00388770(void *);
extern void func_003886E8(void *,void *,f32);
extern void func_00388830(void *,void *,f32);
extern f32 func_00388730(void *,void *);
extern u8 *func_L01_0046C468(void *,void *,s32,s32,s32,s32,s32,f32,f32,s32,f32);

void func_L01_00445F50(u8 *obj, s32 unused, s32 mode) {
    vu0_v4 a,b,c,points[8];
    vu0_v4 *scratch;
    s32 n,i,j,r1,r2,boost;
    f32 w,h,f,d;
    u8 *particle;
    u8 *state;
    n=func_003BD668(obj,0);
    if (n) {
        scratch=D_L01_70000000;
        for (; n>0; --n, scratch+=2) {
            if (scratch[1].w==0.0f) {
                a=scratch[0];
                a.w=1.0f;
                func_0037E2F0(&b,0.0f,scratch[0].w);
                vec_add_ab(&a,&a,&b);
                r1=func_0037E208(10,20);
                r2=func_0037E208(-10,10);
                w=scratch[0].w*189000.0f;
                h=scratch[0].w*420000.0f;
                f=func_0037E250(-4.0f,-10.0f)*0.00027777778450399637f;
                particle=func_L01_0046C468(&a,D_L01_001D66B0,r1,0x808080,r2,0x40,0,w,h,0,f);
            } else {
                a=scratch[0];
                b=scratch[1];
                a.w=b.w=1.0f;
                f=func_0037E250(0.0f,1.0f);
                func_003886C0(&c,&a,&b,f);
                c.x+=func_0037E250(-scratch[0].w*0.4f,scratch[0].w*0.4f);
                c.y+=func_0037E250(-scratch[0].w*0.4f,scratch[0].w*0.4f);
                c.z+=func_0037E250(-scratch[0].w*0.4f,scratch[0].w*0.4f);
                r1=func_0037E208(10,20);
                r2=func_0037E208(-10,10);
                w=scratch[0].w*189000.0f;
                h=scratch[0].w*420000.0f;
                f=func_0037E250(-4.0f,-10.0f)*0.00027777778450399637f;
                particle=func_L01_0046C468(&c,D_L01_001D66B0,r1,0x808080,r2,0x40,0,w,h,0,f);
            }
            if (particle) {
                if (func_0037E1D8(3)) {
                    particle[2]=(*(u8 **)(D_L01_00221118+0x16C))[4];
                    particle[3]=func_0037E1D8(4)?0x44:0x48;
                } else {
                    particle[2]=(*(u8 **)(D_L01_00221118+0x16C))[0];
                    particle[3]=0x48;
                }
            }
        }
    } else {
        state=func_0037E0B8(obj);
        if (state && *(f32 *)(state+0x10)>5.0f) return;
        n=func_L01_00444800(obj,8,points,mode,6.0f);
        if (!n) return;
        for (i=0; i<n; i++) {
            vec_sub_ba(&a,&points[i],obj+0x10);
            func_00388770(&a);
            func_003886E8(&a,&a,0.8f);
            vec_add_ab(&points[i],&a,obj+0x10);
            func_00388830(&b,&a,1.0f);
            d=func_00388730(&b,obj+0xE0);
            boost=(s32)(d*d*d*d*d*d*20.0f);
            j=0;
            do {
                r1=func_0037E208(10,20)+boost;
                r2=func_0037E208(-10,10);
                f=func_0037E250(-4.0f,-10.0f)*0.00027777778450399637f;
                particle=func_L01_0046C468(&points[i],D_L01_001D66B0,r1,0x808080,r2,0x40,0,63000.00390625f,210000.0f,0,f);
                if (particle) {
                    if (func_0037E1D8(3)) {
                        particle[2]=(*(u8 **)(D_L01_00221118+0x16C))[4];
                        particle[3]=func_0037E1D8(4)?0x44:0x48;
                    } else {
                        particle[2]=(*(u8 **)(D_L01_00221118+0x16C))[0];
                        particle[3]=0x48;
                    }
                }
            } while (--j>=0);
        }
    }
}
/* localdecomp:end func_L01_00445F50 */
