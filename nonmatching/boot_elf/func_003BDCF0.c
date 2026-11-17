/* PAL near miss (Codex wave 7): near miss: 79 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003BDC00; did not compile with its file's flags under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 79).
 * Worker's note: 79 diff; build/codex/w367/func_003BDCF0.02.log. Context correction for Claude: func_0038DE98 is declared void(f32,f32), but PAL caller 003BDD74 uses its f0 return and callee 0038DE98 computes wrapped sum in f0. Draft preserves compatible declarations and ...
 */
#include "common.h"
/* localdecomp:start func_003BDCF0 */
typedef int Q_003BDCF0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x34]; u16 flags; u8 pad36[0x74]; s16 classid; } M_003BDCF0;
extern s32 D_001DA2A0_003BDCF0[2];
extern f32 D_001DA2BC;
extern s32 D_001DA2B0_003BDCF0;
extern f32 D_001DA2B4_003BDCF0;
extern f32 D_001DA2B8_003BDCF0;
/* The file declares the retail angle helper void. Its decoded calculation is
 * kept here until that return declaration can be corrected by the integrator. */
static __inline__ f32 wrap_003BDCF0(f32 x, f32 step) {
    f32 r=x+step;
    s32 below_min=r < -3.1415927410125732421875f;
    if (!(r<3.1415927410125732421875f)) {
        r-=3.1415927410125732421875f;
        r-=3.1415927410125732421875f;
    }
    if (below_min) {
        r+=3.1415927410125732421875f;
        r+=3.1415927410125732421875f;
    }
    return r;
}
void func_003BDCF0(M_003BDCF0 *m) {
    extern void func_003BDB58(void *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_003C3310_003BDCF0(void *,s32,void *);
    extern f32 func_0038D490(f32);
    extern void func_0038A140(void (*)(),s32);
    extern void func_003BDB18(void);
    Q_003BDCF0 pos;
    f32 a;
    s32 id;
    m->flags|=16;
    func_003BDB58(m,56,136,64,128,24,64,24,100);
    if (m->classid==10) id=1;
    else id=m->classid==601 ? 8 : 0;
    func_003C3310_003BDCF0(m,id,&pos);
    a=wrap_003BDCF0(D_001DA2BC,0.080285154283046722412109375f);
    D_001DA2BC=a;
    a=func_0038D490(a);
    *(Q_003BDCF0 *)D_001DA2A0_003BDCF0=pos;
    D_001DA2B8_003BDCF0=0.070000000298023223876953125f;
    D_001DA2B4_003BDCF0=0.039999999105930328369140625f;
    D_001DA2B0_003BDCF0=(((s32)((a*0.5f+0.5f)*13.0f)+23)<<24)|0xc0;
    func_0038A140(func_003BDB18,(s32)m);
}
/* localdecomp:end func_003BDCF0 */
