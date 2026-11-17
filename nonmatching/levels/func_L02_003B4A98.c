/* NTSC-U draft (Codex wave 3): C of func_L02_003B2960, the NTSC-U twin of func_L02_003B4A98, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 71 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2") (NTSC-U twin "func_L02_003B2960", whose code is not the PAL one).
 * Worker's note: 71 diff (improved 73); guarded final reload fixes loop branch; VU0/EE interleaving remains; j helpers fail permitted flags with fixed/forbidden vf17 VU_REGS (06.log); NEEDS divs row 'func_L02_003B2960 0 2'; best log func_L02_003B2960.03.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L02_003B2960 */

static __inline__ void add_ab(void *d,void *a,void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void add_keep_b(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void sub_ba(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}

extern void func_003888C8(void *,void *,void *);
extern int func_0037E1D8(int);
extern void func_L01_00440A88(void *,float,float);
extern void func_L01_00468DC0(void *,void *,int,float,int,int,int,int,int);
extern void func_00388830(void *,void *,float);
extern int func_003894A0(int,int,float);
extern void func_L01_00468C38(void *,int,int,float,int,int,int,int,int);
extern vu0_v4 D_L02_001E1300[];
extern u32 D_L02_001DE540;

extern int D_001DE540_sda;
__asm__(".extern D_001DE540_sda, 4");
extern u32 D_001DDF90_sda;
__asm__(".extern D_001DDF90_sda, 4");
extern float D_001DDF54_sda;
__asm__(".extern D_001DDF54_sda, 4");
extern float D_001DDF58_sda;
__asm__(".extern D_001DDF58_sda, 4");
extern float D_001DDF5C_sda;
__asm__(".extern D_001DDF5C_sda, 4");
extern float D_001DDF60_sda;
__asm__(".extern D_001DDF60_sda, 4");
extern float D_001DDF70_sda;
__asm__(".extern D_001DDF70_sda, 4");
extern float D_001DDF74_sda;
__asm__(".extern D_001DDF74_sda, 4");
extern float D_001DDF80_sda;
__asm__(".extern D_001DDF80_sda, 4");
extern float D_001DDF84_sda;
__asm__(".extern D_001DDF84_sda, 4");
extern int D_001DDF64_sda;
__asm__(".extern D_001DDF64_sda, 4");
extern int D_001DDF68_sda;
__asm__(".extern D_001DDF68_sda, 4");
extern int D_001DDF6C_sda;
__asm__(".extern D_001DDF6C_sda, 4");
extern int D_001DDF78_sda;
__asm__(".extern D_001DDF78_sda, 4");
extern int D_001DDF7C_sda;
__asm__(".extern D_001DDF7C_sda, 4");
extern int D_001DDF88_sda;
__asm__(".extern D_001DDF88_sda, 4");
extern int D_001DDF8C_sda;
__asm__(".extern D_001DDF8C_sda, 4");
void func_L02_003B2960(u8 *m) {
    vu0_v4 a,b,c,d,e;
    int i,j,color,t;
    int alpha;
    float size;
    func_003888C8(&a,&D_001DDF90_sda,m+0xC0);
    add_ab(&a,&a,m+0x10);
    if(!func_0037E1D8(4)) {
        func_L01_00440A88(&b,D_001DDF54_sda*0.0166666675f,D_001DDF58_sda*0.0166666675f);
        func_L01_00468DC0(&a,&b,D_001DDF68_sda,D_001DDF70_sda,D_001DDF64_sda,(u8)func_0037E1D8(255),0,64,0);
        j=2;
        do {
            --j;
            func_L01_00440A88(&c,D_001DDF5C_sda*0.0166666675f,D_001DDF60_sda*0.0166666675f);
            add_keep_b(&b,&b,&c);
            func_L01_00468DC0(&a,&b,D_001DDF6C_sda,D_001DDF74_sda,D_001DDF64_sda,(u8)func_0037E1D8(255),0,64,0);
        }while(j>=0);
    }
    sub_ba(&d,D_L02_001E1300,&a);
    func_00388830(&d,&d,-0.3f);
    func_00388830(&e,&d,0.1f);
    add_ab(&d,&d,&a);
    t=D_L02_001DE540;
    for(i=0;;) {
        color=func_003894A0(D_001DDF78_sda,D_001DDF7C_sda,fabs_asm(0.5f-(255-((t+i*20)&255))/255.0f));
        size=(D_001DDF80_sda+i*D_001DDF84_sda)*(*(float *)(m+0x2C)/(*(float *)(*(u8 **)(m+0x24)+0x24)));
        alpha=*(u8 *)&D_L02_001DE540;
        if(i&2)alpha*=2;
        if(i&1)alpha=255-alpha;
        ++i;
        func_L01_00468C38(&d,color,(u8)alpha,size,D_001DDF8C_sda,D_001DDF88_sda,2,0,0);
        add_keep_b(&d,&d,&e);
        if(i>=4)break;
        t=D_001DE540_sda;
    }
}
/* localdecomp:end func_L02_003B2960 */
