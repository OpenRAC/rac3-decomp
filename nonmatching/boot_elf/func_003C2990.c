/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Fresh complete PAL reconstruction; no object diff: existing P_3BD0D8/S_3BD490 typedefs and table declarations occur after marker and are unavailable to snippet context. Needs owner declaration ordering correction; retained exact existing types without ...
 */
#include "common.h"
/* localdecomp:start func_003C2990 */
void func_003C2990(O_3A1870_003A70C8 *obj, s32 id) {
    extern void func_0038CF58(void *, int, int);
    extern void func_003C2D68(S_3BD490 *);
    P_3BD0D8 *p=(P_3BD0D8 *)obj;
    u8 slot;
    func_0038CF58(p,0,0x100);
    slot=D_002DB190[id];
    p->b23=128;
    p->b22=slot;
    p->bA8=255;
    p->b21=255;
    p->b61=255;
    p->b62=255;
    *(unsigned long *)p->d38=0x4040400000000000UL;
    p->h36=0x7F80;
    p->b6D=255;
    p->bA5=127;
    p->wAC=(((s32)p-(s32)D_001DA49C)>>8)<<16;
    p->bA7=128;
    p->hAA=id;
    p->b6E=0;
    p->b6C=255;
    p->bA4=127;
    p->bA6=128;
    if (D_002DAFB0[slot]!=id) {
        p->h34|=5;
        p->w24=0;
        p->w98=0;
        p->w64=D_002DD190[p->b22];
        if (!p->w64) p->h34|=2;
    } else {
        p->w64=D_002DAB00[slot];
        if (!p->w64) p->h34|=2;
        p->w24=D_002DA740[p->b22];
        p->b62=p->w24->bE;
        p->h34|=p->w24->h44;
        p->w98=p->w24->w10;
        p->f2C=p->w24->f24;
        p->f4C=1.0f;
        *(f32 *)&p->w48=1.0f;
        if (p->w24->w40) {
            p->h34|=0x10;
            p->w78=p->w24->w40;
        }
        if (p->w24->bF) {
            p->b6F=24;
            p->h34|=0x400;
            p->w70=0;
            p->w74=0;
            p->bBD=0;
        }
        if (p->w24->b6) p->b63=24;
        if (p->w24->w48) {
            func_003C2D68((S_3BD490 *)p);
            if (p->w24->w48->b10>=2) p->h34&=~2;
            if (p->w24->bC==1) {
                if (p->w24->w48->b10<2) {
                    p->w48=0;
                    if (p->w24->w48->b11<0) p->h34|=0x40;
                } else if (!p->w64) {
                    *(f32 *)&p->w48=0.8333333134651184f;
                }
            }
        }
        p->b7E|=p->w24->b47;
    }
}
/* localdecomp:end func_003C2990 */
