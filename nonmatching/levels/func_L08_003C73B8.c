/* NTSC-U draft (Codex wave 3): C of func_L08_003C50F0, the NTSC-U twin of func_L08_003C73B8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 145 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L08_003C50F0", whose code is not the PAL one).
 * Worker's note: 145 diff; best log w122/func_L08_003C50F0.check1.log; permitted flags verified once; literal-pool lwc1 vs retail inline 210000, 1/60, 0.3 and 1/3600; documented unlisted @ps2as blocker; retained prior best; stack/register/VU scheduling also differs
 */
#include "common.h"
/* localdecomp:start func_L08_003C50F0 */
typedef int Vec __attribute__((mode(TI)));
extern s32 D_001DE8B8_sda,D_001DE8BC_sda,D_001DE8C0_sda,D_001DE8C4_sda,D_001DE8C8_sda,D_001DE8CC_sda;
extern f32 D_001DE8D0_sda,D_001DE8D4_sda,D_001DE8D8_sda,D_001DE8DC_sda,D_001DE8E0_sda;
typedef struct {u8 a[16];u8 *p;} Table;
extern Table D_L08_0021EB18;
extern void func_0037E2F0(void *,f32,f32),func_00388830(void *,void *,f32);
extern f32 func_0037E250(f32,f32);
extern s32 func_0037E1D8(s32),func_0037E208(s32,s32);
extern u8 *func_L01_00472438(void *,void *,s32,s32,s32,s32,f32,f32,f32,s32);
extern void func_L01_0046CF70(void *,void *,s32,f32);
__asm__(".extern D_001DE8B8_sda, 4");
__asm__(".extern D_001DE8BC_sda, 4");
__asm__(".extern D_001DE8C0_sda, 4");
__asm__(".extern D_001DE8C4_sda, 4");
__asm__(".extern D_001DE8C8_sda, 4");
__asm__(".extern D_001DE8CC_sda, 4");
__asm__(".extern D_001DE8D0_sda, 4");
__asm__(".extern D_001DE8D4_sda, 4");
__asm__(".extern D_001DE8D8_sda, 4");
__asm__(".extern D_001DE8DC_sda, 4");
__asm__(".extern D_001DE8E0_sda, 4");
void func_L08_003C50F0(u8 *m,Vec *a,Vec *b) {
    Vec vel,pos;
    u8 *p,*q;
    s32 i,color,k;
    u8 alpha;
    f32 x,y,t;
    pos=*a;
    p=*(u8 **)(m+0x68);
    if(*(s32 *)(p+0x10)<50) alpha=(s32)((*(s32 *)(p+0x10)*127.0f)/50.0f);
    else alpha=127;
    for(i=0;i<D_001DE8B8_sda;i++) {
        t=D_001DE8D8_sda * *(f32 *)(p+0x14);
        func_0037E2F0(&vel,t*0.5f,t);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(vel) : "m"(vel), "m"(*b) : "vf1", "vf2");
        t=func_0037E250(D_001DE8DC_sda*0.5f,D_001DE8DC_sda);
        func_00388830(&vel,&vel,t*0.0166666675f);
        if(func_0037E1D8(4)) color=D_001DE8CC_sda;else color=D_001DE8C4_sda;
        color|=alpha<<24;
        k=func_0037E208(-2,2);
        x=D_001DE8D0_sda*210000.0f;y=D_001DE8D4_sda*210000.0f;
        t=func_0037E250(D_001DE8E0_sda*0.3f,D_001DE8E0_sda);
        q=func_L01_00472438(&pos,&vel,D_001DE8BC_sda,k,color,D_001DE8C8_sda,x,y,t,0);
        if(q) {
            q[2]=D_L08_0021EB18.p[0];
            if(func_0037E1D8(2)) q[3]=0x48;else q[3]=0x44;
        }
    }
    if(!func_0037E1D8(6)) {
        k=func_0037E208(D_001DE8C0_sda-5,D_001DE8C0_sda);
        t=func_0037E250(40,80);
        func_L01_0046CF70(&pos,&vel,k,t*0.000277777785f);
    }
}
/* localdecomp:end func_L08_003C50F0 */
