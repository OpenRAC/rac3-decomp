/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: COMPILE ERROR type conflict; build/codex/w442/func_003C1AE0.ordinary.log and .01.log; context declares func_0038DE98 void(f32,f32), retail consumes f0 and needs f32 return; correct canonical declaration in src/boot_elf/text/38DE98.c before matching, no ...
 */
#include "common.h"
/* localdecomp:start func_003C1AE0 */
extern S_BC0F0 D_002D2060[];
extern s32 D_001D9094;
extern f32 D_001D9044;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
s32 func_003C1AE0(void) {
    extern void func_003BBC00(s32);
    extern s32 func_0038CEB0();
    extern s32 func_003BE2D0();
    extern void func_003BBD20();
    extern s32 func_003BE6B8(void);
    extern void func_003BBCA8(s32,f32);
    extern f32 func_0038DE98(f32,f32);
    S_BC0F0 *g=D_002D2060;
    s32 done=0;
    if (((u8 *)g)[0x60]==0) { func_003BBC00(2); ((u8 *)g)[0x60]=1; }
    if (g->f40) {
        switch(g->f48) {
        case 0:
            *(f32 *)&g->f30=1.0f-(f32)g->f4C/50.0f;
            if(func_0038CEB0(&g->f4C)) { g->f4C=75;g->f48=1; }
            break;
        case 1:
            if(func_0038CEB0(&g->f4C)) { g->f48=2; g->f4C=g->f34*3; }
            break;
        case 2:
            *(f32 *)&g->f30=1.0f;
            if((g->f34*3-g->f4C)%D_001D9094==0)func_003BBC00(0);
            if(func_0038CEB0(&g->f4C)) { g->f4C=75;g->f48=3;func_003BBC00(1); }
            break;
        case 3:
            *(f32 *)&g->f30=1.0f;
            if(func_0038CEB0(&g->f4C)) { g->f48=4;g->f4C=100; }
            if(*(u32 *)(D_001D52FC+0x1C4)&0x40)g->f4C=0;
            break;
        case 4:
            if(func_003BE2D0())func_003BBD20();
            if(func_003BE6B8()) {
                if(func_0038CEB0(&g->f4C)) {g->f48=5;g->f4C=50;}
            }
            break;
        case 5:
            done=(func_0038CEB0(&g->f4C)==1);
            *(f32 *)&g->f30=(f32)g->f4C/50.0f;
            func_003BBCA8(2,*(f32 *)&g->f30);
            break;
        }
    } else {
        switch(g->f48) {
        case 0:
            *(f32 *)&g->f30=1.0f-(f32)g->f4C/50.0f;
            if(func_0038CEB0(&g->f4C)) {g->f48=1;g->f4C=100;}
            break;
        case 1:
            *(f32 *)&g->f30=1.0f;
            if(func_003BE6B8()) {
                if(func_0038CEB0(&g->f4C)) {g->f4C=50;g->f48=2;}
            }
            break;
        case 2:
            done=(func_0038CEB0(&g->f4C)==1);
            *(f32 *)&g->f30=(f32)g->f4C/50.0f;
            break;
        }
        *(f32 *)&g->f50=func_0038DE98(*(f32 *)&g->f50,D_001D9044);
    }
    return done;
}
/* localdecomp:end func_003C1AE0 */
