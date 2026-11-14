/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0033D9D0, the NTSC-U twin of func_L01_0033E0C8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" when tried; not with src/levels/shared/L01_0033E0C8.c's current line.
 * Worker's note: 85 diff; real VU0 sequences reconstructed using operands/clobbers; scheduling differs and default assembler emits .lit4 for retail inline 0.075; no unlisted flags tried; best log func_L01_0033D9D0.check01.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0033D9D0 */
extern void func_L01_004420D0(void *,void *,void *,void *,void *,float);
extern float func_0037E250(float,float);
extern void func_00388830(void *,void *,float);
extern int func_0037E208(int,int);
extern void func_L01_0033DBD8(void *,int,void *,int);
static __inline__ void add_vec(void *d,void *a,void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void copy_vec(void *d,void *s) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)s) : "vf1");
}
void func_L01_0033D9D0(void *owner,void *data) {
    vu0_v4 points[25],a,b,noise,tmp; int i;
    for(i=0;i<24;i++) {
        *(vu0_q *)&a=*(vu0_q *)data; *(vu0_q *)&b=*(vu0_q *)((char *)data+0x10);
        copy_vec(&tmp,(char *)data+0x30);
        add_vec(&a,&a,(char *)data+0x20); add_vec(&b,&b,&tmp);
        func_L01_004420D0(&points[i],(char *)data+0x20,(char *)data+0x30,&a,&b,(float)i/23.0f);
        noise.w=0.0f; noise.x=func_0037E250(-1.0f,1.0f); noise.y=func_0037E250(-1.0f,1.0f); noise.z=func_0037E250(-1.0f,1.0f);
        func_00388830(&noise,&noise,0.075f); add_vec(&points[i],&points[i],&noise);
    }
    if(*(int *)((char *)data+0x88)>=7) func_L01_0033DBD8(owner,func_0037E208(64,128),points,25);
    else func_L01_0033DBD8(owner,func_0037E208(0,64),points,25);
}
/* localdecomp:end func_L01_0033D9D0 */
