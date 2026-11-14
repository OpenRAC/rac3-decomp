/* NTSC-U draft (2026-11-14, Codex worker): C of func_L09_003EF778, the NTSC-U twin of func_L09_003F1600, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/09_tyhrranosis/L09_003F1600.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L09_003EF778 */
extern void func_003886E8(void *, void *, float);
extern float func_0037E2A8(void);
extern float func_00388960(float), func_00388978(float),func_0037E250(float,float);
extern void func_0037E2F0(void *,float,float);
extern int func_0037E1D8(int),func_0037E208(int,int);
extern u8 *func_L01_00472438(void *,void *,int,int,int,int,float,float,float,int);
extern struct { char pad[0x10]; u8 *colors; } D_L09_00220098[];
void func_L09_003EF778(char *object) {
    struct { vu0_v4 pos,dir,scaled; } local;
    float ratio=*(float *)(object+0x2c) / *(float *)(*(char **)(object+0x24)+0x24);
    float angle,cosine,sine,min,max,size,fade;
    int i,color,variation;
    u8 *effect;
    func_003886E8(&local.scaled,object+0xe0,4.0f);
    for(i=9;i>=0;i--) {
        angle=func_0037E2A8();
        size=ratio*210000.0f;
        cosine=func_00388960(angle);
        max=ratio*4.0f;
        min=max*0.5f;
        local.pos.x=cosine*func_0037E250(min,max);
        sine=func_00388978(angle);
        local.pos.y=sine*func_0037E250(min,max);
        local.pos.z=func_0037E250(-3.0f,3.0f)*ratio;
        local.pos.w=0;
        __asm__("lqc2 $vf2, %1\n\t"
                "lqc2 $vf1, %0\n\t"
                "vadd.xyz $vf2, $vf2, $vf1\n\t"
                "sqc2 $vf2, %0\n\t"
                "lqc2 $vf1, %2\n\t"
                "lqc2 $vf2, %0\n\t"
                "vadd.xyz $vf1, $vf1, $vf2\n\t"
                "sqc2 $vf1, %0"
                : "+m"(local.pos)
                : "m"(*(vu0_v4 *)(object+0x10)), "m"(local.scaled)
                : "vf1", "vf2");
        func_0037E2F0(&local.dir,0.0031250002793967724f,0.0052083334885537624f);
        color=func_0037E1D8(4) ? 0x7f426066 : 0x7f668a90;
        variation=func_0037E208(-2,2);
        fade=ratio*2.5f*210000.0f;
        effect=func_L01_00472438(&local.pos,&local.dir,0x46,variation,color,0x426066,
                                  size,fade,func_0037E250(-0.3f,-1.0f),0);
        if(effect) {
            effect[2]=D_L09_00220098[0].colors[0];
            effect[3]=func_0037E1D8(2) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L09_003EF778 */
