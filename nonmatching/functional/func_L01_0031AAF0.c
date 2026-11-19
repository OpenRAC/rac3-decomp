/* functional: high. 96 diff with --no-context (scheduling/spills); same structure as func_L01_0031A820 with different tables, verified vs retail. Integration: the earlier 'extern u8 func_L01_0031AAF0[]' (before func_L01_0031AAA8) must become a function declaration. */
/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Context compile blocked: earlier func_L01_0031AAA8 declares extern u8 func_L01_0031AAF0[]; change that callback declaration to function type for integration. .01.log; isolated diagnostic 96 diff/161 words (.02-no-context.log).
 */
#include "common.h"
/* localdecomp:start func_L01_0031AAF0 */
#include "vu0.h"
typedef struct { vu0_v4 pos[4]; u32 color[4]; float uv[4][2]; unsigned long d70,d78,d80,d88; } R_0031AAF0;
extern vu0_v4 D_L01_002AE520[];
extern vu0_v4 D_L01_002AE200[];
extern vu0_v4 D_L01_002AD570[];
extern s16 D_L01_002ADBB0[][8];
extern float D_L01_002ADED0[][2];
extern float D_L01_002ADED4[][2];
extern vu0_v4 D_L01_001E29C0;
void func_L01_0031AAF0(u8 *m) {
    extern unsigned long func_00389598(s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE68(void *, void *);
    extern void func_003D2DA0(void *, void *, s32);
    R_0031AAF0 r;
    vu0_v4 matrix[4];
    vu0_v4 diff, point;
    s32 i=0,j;
    s32 *state = *(s32 **)(m+0x68);
    r.d78=func_00389598(5);
    r.d80=0xFF9000000260UL;
    r.d88=0x8000000048UL;
    *(vu0_q *)&matrix[0]=*(vu0_q *)(m+0xC0);
    *(vu0_q *)&matrix[1]=*(vu0_q *)(m+0xD0);
    *(vu0_q *)&matrix[2]=*(vu0_q *)(m+0xE0);
    matrix[3].x=*(float *)(m+0x10);
    matrix[3].y=*(float *)(m+0x14);
    matrix[3].z=*(float *)(m+0x18);
    matrix[3].w=1.0f;
    r.d70=0;
    r.color[0]=r.color[3]=r.color[2]=r.color[1]=(*state<<24)|0xFF0000;
    do {
        func_0038CE20((float *)&point,(float *)&D_L01_002AE520[i],1.0f);
        func_0038D028(&point,&point,matrix);
        vec_sub_ab(&diff,&point,&D_L01_001E29C0);
        func_0038CF68((float *)&diff,(float *)&diff,1.0f);
        func_0038D000(&point,&D_L01_002AE200[i],matrix);
        func_0038CE68(&diff,&point);
        for (j=0;j<4;j++) {
            vu0_v4 *v=&D_L01_002AD570[D_L01_002ADBB0[i][j*2]];
            s32 u=D_L01_002ADBB0[i][j*2+1];
            func_0038CE20((float *)&r.pos[j],(float *)v,1.0f);
            r.uv[j][0]=D_L01_002ADED0[u][0];
            r.uv[j][1]=D_L01_002ADED4[u][0];
            if (v->z==0.0014319999609142542f) r.color[j]=0xFF0000;
        }
        func_003D2DA0(&r,matrix,0);
        i++;
    } while(i<50);
}
/* localdecomp:end func_L01_0031AAF0 */
