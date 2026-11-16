/* PAL near miss (Codex wave 10): near miss: 56 words differ with the file's flags.
 * Worker's note: 55 diff: w507/func_00383E48.a1.log; fixed default assembler emits lit4 load for 1.2f versus retail lui/ori/mtc1; remaining stack/base address allocation; no alternate flags tried
 */
#include "common.h"
/* localdecomp:start func_00383E48 */
#include "vu0.h"
extern u8 D_00222640_00383E48[];
s32 func_00383E48(void *arg, void *state)
{
    extern f32 func_003C3FA0(f32,f32,f32);
    extern void func_003C4BA0(void *,void *);
    extern void func_0038DAA8(void *,void *,void *,f32);
    extern void func_0038DC10(void *,void *);
    extern void func_0038D970(void *,void *);
    u128_t v;
    u128_t matrix[4];
    u8 *m=arg;
    u8 *d=state;
    f32 t;
    if (*(f32 *)(d+0x10)==1.0f && *(f32 *)d==1.0f) return 1;
    t=func_003C3FA0(0.0f,1.0f,*(f32 *)(d+0x10));
    vec_add_ba(d+0x30,D_00222640_00383E48+*(s32 *)(m+0x94)*0x460,d+0x30);
    {
        f32 x=*(f32 *)(d+0x30);
        f32 y=*(f32 *)(d+0x34);
        f32 z=*(f32 *)(d+0x38);
        *(f32 *)(d+0x40)=x+(*(f32 *)(m+0x30)-x)*t;
        *(f32 *)(d+0x44)=y+(*(f32 *)(m+0x34)-y)*t;
        *(f32 *)(d+0x48)=z+(*(f32 *)(m+0x38)-z)*t;
    }
    *(u128_t *)(D_00222640_00383E48-0x1c0+*(s32 *)(m+0x94)*0x460)=*(u128_t *)(d+0x40);
    func_003C4BA0(&v,m);
    t=func_003C3FA0(0.0f,1.0f,*(f32 *)d);
    func_0038DAA8(d+0x50,d+0x20,&v,t);
    func_0038DC10(d+0x50,matrix);
    func_0038D970(D_00222640_00383E48+0x1c0+*(s32 *)(m+0x94)*0x460,matrix);
    *(f32 *)(d+0x10)+=*(f32 *)(d+0x14)*1.2f;
    if (*(f32 *)(d+0x10)>1.0f) *(f32 *)(d+0x10)=1.0f;
    *(f32 *)d+=*(f32 *)(d+4)*1.2f;
    if (*(f32 *)d>1.0f) *(f32 *)d=1.0f;
    return 0;
}
/* localdecomp:end func_00383E48 */
