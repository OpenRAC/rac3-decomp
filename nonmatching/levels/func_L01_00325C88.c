/* PAL near miss (Codex wave 8): near miss: 164 words differ with the file's flags.
 * Worker's note: 164 diff w432/func_L01_00325C88.07.log; three final forms identical. Iterator control flow, saved-register allocation and mixed global-load scheduling remain. TYPE CONTRACT FAIL w432/func_L01_00325C88.type-contract.log: owner later declares target with ...
 */
#include "common.h"
/* localdecomp:start func_L01_00325C88 */
typedef struct {
    s32 next;
    u8 pad4[8];
    s32 list;
    u8 pad10[0x5C];
    s32 object;
} Chain_00325C88;
typedef struct {
    u8 p0[0x68];
    Chain_00325C88 *vars;
    u8 p6C[0xAA-0x6C];
    s16 kind;
    u8 pAC[0x100-0xAC];
} Moby_00325C88;
extern u8 *D_L01_001E001C;
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
__asm__(".extern D_L01_001E0058, 16");
void func_L01_00325C88(u8 *checkpoint, u8 *save, u8 *moby) {
    extern s32 func_L01_00449050(void *);
    extern s32 func_L01_00325C40(s32, u8 *, s32);
    s32 owner=(s32)checkpoint;
    u8 *root;
    u8 *base;
    Moby_00325C88 *current;
    Moby_00325C88 *linked;
    u8 *object;
    s32 id;
    s32 link;
    u8 *node;
    *(s32 *)((u8 *)save+0x60)=0;
    root=*(u8 **)(moby+0x68);
    id=*(s32 *)(root+0x18);
    if(id==-1) return;
    base=D_L01_001E001C;
    current=(Moby_00325C88 *)base+id;
    while(current!=0 && current->kind!=0x19E4) {
        Chain_00325C88 *chain;
        u16 *p;
        s32 id;
        chain=current->vars;
        id=chain->list;
        if(id!=-1) {
            p=D_L01_0021DE20[id];
            if((id&0xFF)==0xFF || id>D_L01_001E0058 || p==0) goto next1;
body1:
                    linked=(Moby_00325C88 *)base+(*p&0x7FFF);
                    if(linked==0) goto next1;
                    link=linked->vars->object;
                    if(link!=-1) {
                        node=(u8 *)func_L01_00449050(base+(link<<8));
                        *(s32 *)(node+4)=0;
                    }
                    p++;
                    base=D_L01_001E001C;
                    id=chain->list;

            if((id&0xFF)==0xFF || id>D_L01_001E0058 || p==0) goto next1;
            if((s16)p[-1]>=0 || p==D_L01_0021DE20[id]) goto body1;

        }
next1:
        if(chain->next==-1) break;
        current=(Moby_00325C88 *)base+chain->next;
    }
    current=(Moby_00325C88 *)base+*(s32 *)(root+0x18);
    while(current!=0 && current->kind!=0x19E4) {
        Chain_00325C88 *chain;
        u16 *p;
        s32 id;
        chain=current->vars;
        id=chain->list;
        if(id!=-1) {
            p=D_L01_0021DE20[id];
            if((id&0xFF)==0xFF || id>D_L01_001E0058 || p==0) goto next2;
body2:
                    linked=(Moby_00325C88 *)D_L01_001E001C+(*p&0x7FFF);
                    if(linked==0) goto next2;
                    link=linked->vars->object;
                    if(link!=-1) {
                        object=D_L01_001E001C+(link<<8);
                        if(func_L01_00325C40(owner,(u8 *)save,(s32)object)==0) {
                            node=(u8 *)func_L01_00449050(object);
                            *(s32 *)(node+4)=*(s32 *)((u8 *)save+0x60);
                            *(u8 **)((u8 *)save+0x60)=object;
                        }
                    }
                    id=chain->list;
                    p++;

            if((id&0xFF)==0xFF || id>D_L01_001E0058 || p==0) goto next2;
            if((s16)p[-1]>=0 || p==D_L01_0021DE20[id]) goto body2;

        }
next2:
        if(chain->next==-1) break;
        current=(Moby_00325C88 *)D_L01_001E001C+chain->next;
    }
}
/* localdecomp:end func_L01_00325C88 */
