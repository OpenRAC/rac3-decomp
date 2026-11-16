/* PAL near miss (Codex wave 6): near miss: 71 words differ with the file's flags.
 * Worker's note: 68 diff, func_L01_003839C8.03.log; fixed whole-file flags use default assembler: 0.7, 0.15 and angle constants go to lit4 pools while retail builds them inline. Branch/store order improved; no alternate flags tried. Other byte/halfword store scheduling ...
 */
#include "common.h"
/* localdecomp:start func_L01_003839C8 */
#include "structs/weapon.h"
typedef int Q_003839C8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x16B0]; s32 f16B0; u8 pad16B4[0x25C0-0x16B4]; u8 *f25C0; } Hero_003839C8;
typedef struct { u8 pad0[0x30]; u8 f30,f31; s16 f32; } Moby_003839C8;
extern Hero_003839C8 D_001A4BE0[];
extern u8 D_00142647[];
extern struct WeaponRow D_L01_002C5600[];
u8 *func_L01_003839C8(s32 arg0, Q_003839C8 *arg1,Q_003839C8 *arg2,Q_003839C8 *arg3,s32 arg4,s32 arg5,f32 arg6) {
    extern u8 *func_003C24B0(s32,s32);
    extern void func_L01_00445F40(void *,s32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_004CAC78(void *,void *,f32,f32,f32);
    extern s32 func_L01_004C85C8(void *,s32,f32,f32,f32);
    extern void func_003C7C38(void *);
    u8 *m=func_003C24B0(0x1872,0x80);
    u8 *priv;
    if(m) {
        ((Moby_003839C8 *)m)->f30=255;
        ((Moby_003839C8 *)m)->f31=1;
        ((Moby_003839C8 *)m)->f32=255;
        m[0x20]=0;
        priv=*(u8 **)(m+0x68);
        *(long *)(m+0x38)=*(long *)(D_001A4BE0->f25C0+0x38);
        *(Q_003839C8 *)(m+0x10)=*arg2;
        *(Q_003839C8 *)(m+0xF0)=*arg3;
        func_L01_00445F40(m,arg4);
        *(s32 *)(priv+0x3C)=arg4;
        *(s16 *)(m+0xAA)=0x1872;
        *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*(f32)0.7;
        *(Q_003839C8 *)priv=*arg1;
        *(s32 *)(priv+0x10)=arg0;
        *(f32 *)(priv+0x14)=arg6;
        *(f32 *)(priv+0x20)=(f32)0.15;
        *(s32 *)(priv+0x34)=arg5;
        if(D_L01_002C5600[D_00142647[0]].level>=2) *(s32 *)(priv+0x2C)=0x110000;
        else *(s32 *)(priv+0x2C)=0x10000;
        if(D_001A4BE0->f16B0) {
            func_L01_004CAC78(priv,arg2,func_0038CEA8(priv),30.0f,(f32)0.34906584);
        }
        *(s32 *)(priv+0x38)=func_L01_004C85C8(m,0,1.0f,1.0f,1.0f);
        *(s32 *)(priv+0x24)=0;
        func_003C7C38(m);
    }
    *(s32 *)(m+0x98)=0;
    return m;
}
/* localdecomp:end func_L01_003839C8 */
