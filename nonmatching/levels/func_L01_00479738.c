/* PAL near miss (Codex wave 7): near miss: 123 words differ with the file's flags.
 * Worker's note: 123 diff; best build/codex/w357/func_L01_00479738.check.7.log; table-base allocation s0 vs t0, scalar global hoisting/gp delay slots and final loop countdown/branch layout differ. Ten snippet compiles; retained best real draft with exact owner declarations. ...
 */
#include "common.h"
/* localdecomp:start func_L01_00479738 */
extern s32 D_L01_001E03E0, D_L01_001E03E4, D_L01_001E03E8, D_L01_001E03EC, D_L01_001E03F0;
extern s32 D_L01_001D6694;
void func_L01_00479738(void) {
    extern void func_L01_004792D8(s32);
    extern void func_L01_004796B8(void);
    extern void func_003E54E0(s32);
    u8 *p;
    s32 index,old,now,i,step;
    u8 *initial;
    func_L01_004792D8((s32)&D_L01_001E03E0);
    if(D_L01_001D6694==5 && *(s32 *)D_00142660 < D_L01_001E03E0) {
        func_L01_004796B8();
    } else {
        if(!D_L01_001E03F0 && D_L01_001E03EC==-1 && *(s32 *)D_00142660 < D_L01_001E03E0) {
            index=D_L01_001E03C0[0].shown!=0;
            initial=(u8 *)&D_L01_001E03C0[index];
            (*(s16 *)(initial+14))=1;
            (*(s32 *)(initial+4))=0;
            (*(s32 *)(initial+8))=0;
            (*(s32 *)initial)=D_L01_001E03E0-*(s32 *)D_00142660;
            D_L01_001E03EC=index;
            D_L01_001E03F0=1;
        } else if(!D_L01_001E03F0 && D_L01_001E03EC==-1 && D_L01_001E03E0+D_L01_001E03E8 < *(s32 *)D_00142660) {
            index=D_L01_001E03C0[0].shown!=0;
            initial=(u8 *)&D_L01_001E03C0[index];
            (*(s16 *)(initial+14))=1;
            (*(s32 *)initial)=0;
            (*(s32 *)(initial+4))=0;
            (*(s32 *)(initial+8))=0;
            D_L01_001E03EC=index;
            D_L01_001E03F0=0;
        }
    }
    index=D_L01_001E03EC;
    if(index!=-1) {
        p=(u8 *)&D_L01_001E03C0[index];
        if((*(s16 *)(p+14))!=3) {
            old=(*(s32 *)p);
            if(old>=0) {
                now=*(s32 *)D_00142660-D_L01_001E03E0+D_L01_001E03E8;
                (*(s32 *)p)=now;
                if(now!=old) (*(s32 *)(p+4))=0;
            }
            (*(s32 *)(p+4))++;
            (*(s32 *)(p+8))++;
            if((*(s32 *)(p+4))>50) {
                D_L01_001E03E4=D_L01_001E03E0;
                D_L01_001E03E8=(*(s32 *)p);
                (*(s32 *)(p+4))=-1;
                (*(s16 *)(p+14))=3;
            }
        }
    }
    if(index!=-1 || D_L01_001E03C0[0].shown==3 || D_L01_001E03C0[1].shown==3) func_003E54E0(150);
    p=(u8 *)D_L01_001E03C0;
    for(i=0;i<2;i++,p+=16) {
        switch((*(s16 *)(p+14))) {
        case 1:
            if((*(s32 *)(p+8))>12) (*(s16 *)(p+14))=2;
            break;
        case 3:
            (*(s32 *)(p+4))++;
            step=(s32)((f32)D_L01_001E03E8/14.0f);
            D_L01_001E03E0+=step;
            (*(s32 *)p)-=step;
            if(D_L01_001E03F0) {
                if((*(s32 *)p)>0) (*(s32 *)p)=0;
            } else if((*(s32 *)p)<0) (*(s32 *)p)=0;
            if((*(s32 *)(p+4))>12) {
                now=D_L01_001E03E4+D_L01_001E03E8;
                if(D_L01_001E03E0!=now) D_L01_001E03E0=now;
                D_L01_001E03E8=0;
                D_L01_001E03EC=-1;
                (*(s16 *)(p+14))=0;
                D_L01_001E03F0=0;
            }
            break;
        }
    }
}
/* localdecomp:end func_L01_00479738 */
