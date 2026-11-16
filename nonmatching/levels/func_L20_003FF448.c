/* PAL near miss (Codex wave 7): near miss: 107 words differ with the file's flags.
 * Worker's note: 106 diff; best actual diff build/codex/w357/func_L20_003FF448.check.4.log. Fixed default assembler emits .lit4 for 0.020000001f instead of inline retail 0x3CA3D70B; complete VU blocks cannot reproduce interleaving under this flags line (j helpers ...
 */
#include "common.h"
/* localdecomp:start func_L20_003FF448 */
#include "vu0.h"
extern f32 D_L20_001DF6D0;
extern vu0_v4 D_L20_001E2E00;
extern u32 D_L20_001DF698;
extern s32 D_L20_001DF6B0;
extern f32 D_L20_001DF6B4,D_L20_001DF6B8,D_L20_001DF6BC,D_L20_001DF6C0,D_L20_001DF6C4,D_L20_001DF6C8;
void func_L20_003FF448(A_003FF358 *obj) {
    extern void func_003C2F58(s32,s32,void *);
    extern void func_003C2EC0(s32,s32,void *);
    extern void func_0038D028(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern char *func_00382468(s32);
    extern void func_L05_00468EA8(void *,void *,void *,s32,s32);
    vu0_v4 velocity,position,matrix[4],transformed,delta,target;
    u8 *data=(u8 *)obj->p68;
    s32 i,j,a,b;
    *(vu0_q *)&velocity=0;
    for(i=0;i<2;i++) {
        func_003C2F58(*(s32 *)(data+0x3EC),2,&position);
        j=0;
        func_003C2EC0(*(s32 *)(data+0x3EC),2,matrix);
        func_0038D028(&transformed,&((vu0_v4 *)&D_L20_001DF6D0)[i],matrix);
        __asm__(
            "lqc2 $vf1, %3
	"
            "lqc2 $vf2, %0
	"
            "vadd.xyz $vf2, $vf2, $vf1
	"
            "lqc2 $vf1, 0(%5)
	"
            "sqc2 $vf1, %1
	"
            "sqc2 $vf2, %0
	"
            "lqc2 $vf1, %0
	"
            "lqc2 $vf2, %1
	"
            "vsub.xyz $vf1, $vf2, $vf1
	"
            "sqc2 $vf1, %2"
            : "+m"(position), "=m"(target), "=m"(delta)
            : "m"(transformed), "m"(D_L20_001E2E00), "r"(&D_L20_001E2E00)
            : "vf1","vf2");
        func_0038CF68(&delta,&delta,D_L20_001DF6C8);
        __asm__("lqc2 $vf2, %0
	"
                "lqc2 $vf1, %1
	"
                "vadd.xyz $vf2, $vf2, $vf1
	"
                "sqc2 $vf2, %0"
                : "+m"(position) : "m"(delta) : "vf1","vf2");
        while(j<D_L20_001DF6B0) {
            func_003C4C18(&position,D_L20_001DF6B4);
            j++;
            velocity.x=func_003824E0(D_L20_001DF6B8,D_L20_001DF6BC)*0.020000001f;
            velocity.y=func_003824E0(D_L20_001DF6B8,D_L20_001DF6BC)*0.020000001f;
            velocity.z=func_003824E0(D_L20_001DF6C0,D_L20_001DF6C4)*0.020000001f;
            a=(s32)func_00382468(2);
            b=(s32)func_00382468(3)-1;
            func_L05_00468EA8(&position,&velocity,&D_L20_001DF698,a,b);
        }
    }
}
/* localdecomp:end func_L20_003FF448 */
