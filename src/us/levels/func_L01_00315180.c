#include "common.h"

/* NTSC-U counterpart of func_L01_003155A8 (src/levels/shared/L01_00314158.c): the effect call passes 150 in place of 125 (60 Hz) */
/* localdecomp:start func_L01_00315180 */
#include "vu0.h"
typedef struct { vu0_v4 a,b; } Scratch_00315180;
extern u8 D_L01_001D66B0_00315180[] __attribute__((section(".sdata")));
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_003BD668(void *, s32);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L01_00472700(void *, void *, s32, u8, f32, f32);
void func_L01_00315180(u8 *m) {
    vu0_v4 a,b,c;
    f32 f=func_003BE7F0(m+0x10,0,0,0.5f);
    s32 count=func_003BD668(m,0);
    s32 i,n;
    Scratch_00315180 *p;
    for(i=0;i<5;i++) {
        if(count) {
            p=(Scratch_00315180 *)0x70000000; /* EE scratchpad results. */
            for(n=0;n<count;n++,p++) {
                f32 size;
                if(p->b.w==0.0f) {
                    *(vu0_q *)&a=*(vu0_q *)&p->a;
                    a.w=1.0f;
                    func_0037E2F0(&b,0.0f,p->a.w);
                    vec_add_ab(&a,&a,&b);
                    size=func_0037E250(0.7f,1.0f)*p->a.w;
                    func_L01_00472700(&a,D_L01_001D66B0_00315180,150,(u8)func_0037E1D8(2),size,f);
                } else {
                    *(vu0_q *)&a=*(vu0_q *)&p->a;
                    *(vu0_q *)&b=*(vu0_q *)&p->b;
                    a.w=1.0f;
                    b.w=1.0f;
                    func_003886C0(&c,&a,&b,func_0037E250(0.0f,1.0f));
                    c.x+=func_0037E250(-p->a.w*0.4f,p->a.w*0.4f);
                    c.y+=func_0037E250(-p->a.w*0.4f,p->a.w*0.4f);
                    c.z+=func_0037E250(-p->a.w*0.4f,p->a.w*0.4f);
                    size=func_0037E250(0.7f,1.0f)*p->a.w;
                    func_L01_00472700(&c,D_L01_001D66B0_00315180,150,(u8)func_0037E1D8(2),size,f);
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00315180 */
