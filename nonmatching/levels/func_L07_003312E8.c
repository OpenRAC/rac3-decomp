/* PAL near miss (Codex wave 6): near miss: 132 words differ with the file's flags.
 * Worker's note: Best 132 diff, func_L07_003312E8.10.log (also 07,09); record traversal, nearest/farthest selection and exact earlier callee prototypes reconstructed. Remaining address folding/prologue scheduling and loop code layout; ten compile attempts.
 */
#include "common.h"
/* localdecomp:start func_L07_003312E8 */
typedef struct { u8 pad0[0x1C]; s32 ids[6]; u8 pad34[0x90-0x34]; s16 counts[6]; } Private_003312E8;
extern s16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 *D_L07_001DF41C;
extern u8 D_001A4C60[];
static __inline__ s32 id_003312E8(s32 *ids,s32 index) { return ids[index]; }
void func_L07_003312E8(s32 arg0,s32 index) {
    extern s32 *func_L07_00333918(void *);
    extern f32 func_0038CF38(void *,void *);
    extern void func_L07_003310E8(u8 *,void *);
    extern void func_L07_00331008(void *,void *);
    u8 *obj=(u8 *)arg0;
    Private_003312E8 *priv=*(Private_003312E8 **)(obj+0x68);
    s32 enabled,allowfar=1;
    s32 count=priv->counts[index];
    u8 *farthest=0,*closest=0;
    f32 worst=-1.0f,best=10000000.0f;
    s16 *p=D_L07_0021C020[priv->ids[index]];
    enabled=0;
    if(count!=-1)enabled=allowfar;
    if(count>=1)allowfar=0;
    if((priv->ids[index]&255)==255)goto done;
    if(priv->ids[index]>D_L07_001DF458)goto done;
    if(!p)goto done;
loop:
    {
        u8 *candidate;
        u8 *state;
        f32 distance;
        if(p[-1]<0 && p!=D_L07_0021C020[priv->ids[index]])goto done;
        candidate=D_L07_001DF41C+((p[0]&0x7FFF)<<8);
        if(!candidate)goto done;
        state=(u8 *)func_L07_00333918(candidate);
        if(candidate[0x20]<6)goto next;
        if(state[0x1D]!=index)goto next;
        if(!enabled)goto next;
        if(state[0x1C]!=3) {
            distance=func_0038CF38(candidate+0x10,D_001A4C60);
            if(distance<best) {
                closest=candidate;
                best=distance;
            }
            if(allowfar && state[0x1C]==1 && distance>worst) {
                farthest=candidate;
                worst=distance;
            }
        }
next:
        p++;
        if((priv->ids[index]&255)==255)goto done;
        if(priv->ids[index]>D_L07_001DF458)goto done;
        if(p)goto loop;
    }
done:
    if(closest && ((u8 *)func_L07_00333918(closest))[0x1C]!=1) {
        if(farthest)func_L07_003310E8(obj,farthest);
        func_L07_00331008(obj,closest);
    }
}
/* localdecomp:end func_L07_003312E8 */
