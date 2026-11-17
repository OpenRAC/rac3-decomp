/* PAL near miss (Codex wave 8): near miss: 156 words differ with the file's flags.
 * Worker's note: 155 diff in w386/func_003E3E68.07.log with trial --divs 1,2,2 (not a matching metadata row); 10 checks; remaining base/axis pointer lifetime, loop-counter allocation and scalar/VU scheduling. Retained literals decoded exactly from retail.
 */
#include "common.h"
/* localdecomp:start func_003E3E68 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0,v10,v20,v30;
    f32 f40,f44,f48,f4c;
    s32 f50;
    f32 f54;
} S_003E3E68;
extern f32 D_001D9D0C;
extern f32 D_001D9D10;
extern S_003E3E68 D_00306DA0;
extern vu0_v4 D_00306DB0;
extern u8 D_001D5474[];
extern u8 D_001A4C60[];
void func_003E3E68(void) {
    extern void func_0038D348(void *, void *, f32);
    extern f32 func_0038DF28(f32);
    extern void func_0038DC70(void *, void *, void *, f32);
    extern s32 func_003E41A8(void);
    extern void func_0038D1D8(void *, void *, void *, f32);
    extern void func_003E3DA8(void *);
    vu0_v4 d,b,a;
    f32 rate;
    s32 i,n;
    S_003E3E68 *s;
    if (D_001D9D0C>1.0f || D_001D9D10>1.0f) rate=2.0f;
    else rate=1.0f;
    s=(S_003E3E68 *)((u8 *)&D_00306DB0-16);
    vec_sub_ab(&d,D_00222400_003E37B0,&D_00306DB0);
    func_0038D348(&d,&d,s->f54);
    i=0;
    do {
        n=i++;
        func_0038DC70(&a,&d,&s->v30,func_0038DF28((f32)n*6.2831855f/10.0f));
        vec_add_ba(&a,&a,&s->v10);
        func_0038DC70(&b,&d,&s->v30,func_0038DF28((f32)i*6.2831855f/10.0f));
        vec_add_ab(&b,&b,&s->v10);
    } while(i<10);
    if(func_003E41A8() && D_001D5474[0] && !s->f50) {
        f32 diff;
        s=&D_00306DA0;
        if(s->f48<0.031415928f) s->f48+=rate*0.00020943953131791204f;
        else s->f48=0.031415928f;
        s->f4c=s->f48/0.031415928f;
        diff=s->f54-s->f40;
        if(fabs_asm(diff)>0.1f) {
            f32 angle=s->f40+(s->f4c*0.04200005531311035f)*diff;
            vec_sub_ba(D_00222400_003E37B0,D_00222400_003E37B0,&s->v10);
            s->f40=angle;
            func_0038D348(D_00222400_003E37B0,D_00222400_003E37B0,angle);
            vec_add_ab(D_00222400_003E37B0,D_00222400_003E37B0,&s->v10);
        }
        vec_sub_ba(D_00222400_003E37B0,D_00222400_003E37B0,&s->v10);
        func_0038DC70(D_00222400_003E37B0,D_00222400_003E37B0,&s->v30,rate*s->f48*s->f44);
        vec_add_ab(D_00222400_003E37B0,D_00222400_003E37B0,&s->v10);
        func_0038D1D8(s,s,D_001A4C60,s->f4c*0.02399998903274536f);
        func_003E3DA8(s);
    }
}
/* localdecomp:end func_003E3E68 */
