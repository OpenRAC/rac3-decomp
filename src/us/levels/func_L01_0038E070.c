#include "common.h"

/* NTSC-U counterpart of func_L01_0038F3F8 (src/levels/shared/L01_0038EB80.c) */
/* localdecomp:start func_L01_0038E070 */
#include "vu0.h"
extern vu0_q D_L01_002917D0[][4][137];
extern f32 D_L01_0029C310[][4][137];
extern vu0_v4 D_L01_0029EEE0[][4];
extern s32 D_L01_0029EE80[][4];
extern s32 D_L01_0029EDE0[][4];
extern s32 D_L01_0029EE30[][4];
extern f32 D_L01_001E1FD0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1FE8[] __attribute__((section(".sdata")));
extern f32 D_L01_001E2000[] __attribute__((section(".sdata")));
extern s32 D_L01_001E2060_0038E070[] __attribute__((section(".sdata")));
extern s32 D_L01_001E2018_0038E070[] __attribute__((section(".sdata")));
extern f32 D_L01_001E2030[] __attribute__((section(".sdata")));
extern f32 D_L01_001E2048[] __attribute__((section(".sdata")));
void func_L01_0038E070(u8 *obj) {
    extern f32 func_0037E250(f32, f32);
    extern s32 func_0013D3E0(void);
    s32 *index = *(s32 **)(obj+0x68);
    s32 i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<137;j++) {
            f32 r=func_0037E250(0.5f,4.0f);
            qzero(&D_L01_002917D0[*index][i][j]);
            D_L01_0029C310[*index][i][j]=r;
        }
        *(vu0_q *)((u8 *)D_L01_0029EEE0 + *index * 64 + i * 16)=*(vu0_q *)(obj+0x10);
        D_L01_0029EE80[*index][i]=6;
        D_L01_0029EDE0[*index][i]=func_0013D3E0()%128+128;
        D_L01_0029EE30[*index][i]=func_0013D3E0()%2+6;
        D_L01_0029EEE0[*index][i].x += func_0037E250(0.0f,0.5f)+ -0.25f;
        D_L01_0029EEE0[*index][i].y += func_0037E250(0.0f,0.5f)+ -0.25f;
        D_L01_0029EEE0[*index][i].z += func_0037E250(0.0f,0.5f)+ -0.25f;
    }
    D_L01_001E1FD0[*index]=0.01f;
    D_L01_001E1FE8[*index]=128;
    D_L01_001E2000[*index]=0.1f;
    D_L01_001E2060_0038E070[*index]=6;
    D_L01_001E2018_0038E070[*index]=128;
    D_L01_001E2030[*index]=0.0f;
    D_L01_001E2048[*index]=0.0f;
}
/* localdecomp:end func_L01_0038E070 */
