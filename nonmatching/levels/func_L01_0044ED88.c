/* PAL near miss (neon-w1): 167 words differ with the file's flags; tieid spills to stack (0xb10 frame instead of 0xb00) and D_L01_0021DE20 needs -msplit-addresses. */
#include "common.h"
/* localdecomp:start func_L01_0044ED88 */
#include "vu0.h"
typedef int Q_0044ED88 __attribute__((mode(TI)));
typedef struct {
    Q_0044ED88 mat[3];
    Q_0044ED88 pos;
    s32 f40;
    u8 *parent;
    s16 id;
    u8 last, bone, flags, f4D, period, phase;
} Entry_0044ED88;
extern u8 *D_L01_001E001C[];
extern s32 D_L01_001E0058[];
extern s16 *D_L01_0021DE20[];
__asm__(".extern D_L01_0021DE20, 16");
extern s32 D_L01_001D6768[];
extern s16 **D_001D6764_sda;
extern s32 D_001D6770_sda;
extern s16 **D_L01_001D676C[];
extern u8 *D_L01_001E0EDC[];
extern u8 *D_L01_001E0DD0;
__asm__(".extern D_L01_001E0DD0, 16");
void func_L01_0044ED88(u8 *obj, Entry_0044ED88 *out, s32 max, s32 mobyid, s32 tieid, s32 shrubid, s32 tex, u8 *parent)
{
    extern void func_003C2EC0(u8 *, int, Q_0044ED88 *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5B0(void *, void *);
    extern void func_0038D590(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    extern int func_L01_0044EC78(int, u8 *, int, s128_44B9F8 *, s128_44B9F8 *, s128_44B9F8 *, void *);
    Q_0044ED88 joints[40][4];
    Q_0044ED88 inverse[3];
    Q_0044ED88 pos[1],a[1],b[1];
    Q_0044ED88 mat[4];
    s32 njoints;
    s32 count;
    s32 i;
    if (max<=0) { out->last=0; return; }
    if (mobyid==-1 && tieid==mobyid && shrubid==tieid) { out->last=0; return; }
    njoints=0;
    if (parent!=0) {
        u8 *data=*(u8 **)(parent+0x24);
        s32 *n=*(s32 **)(data+0x1C);
        if(n!=0) njoints=*n;
        if(njoints!=0 && njoints<=40) { } else return;
        for(i=0;i<njoints;i++) func_003C2EC0(parent,i,joints[i]);
        *(u16 *)(parent+0x34)|=1;
        parent[0x31]=0;
    }
    count=0;
    func_0038D308(pos,obj+0xF0);
    func_0038D5B0(mat,pos);
    func_0038D590(inverse,mat);
    pos[0]=*(Q_0044ED88 *)(obj+0x10);
    {
    s16 *list;
    if(mobyid!=-1 && mobyid<D_L01_001E0058[0] && (list=D_L01_0021DE20[mobyid])!=0) {
        do {
            s32 id=*(u16 *)list&0x7FFF;
            u8 *m0=D_L01_001E001C[0]+(id<<8);
            u8 *rotation0;
            if(count>=max) goto finish;
            out[count].id=id;
            out[count].last=2;
            out[count].flags=0;
            out[count].f40=0;
            if(parent!=0) {
                out[count].parent=parent;
                if(out[count].bone==255) {
                a[0]=*(Q_0044ED88 *)(m0+0x10);
                b[0]=*(Q_0044ED88 *)(m0+0xC0);
                out[count].bone=func_L01_0044EC78((int)parent,(u8 *)joints,njoints,a,b,pos,inverse);
                }
            }
            vec_sub_ab(&out[count].pos,m0+0x10,pos);
            func_0038D000(&out[count].pos,&out[count].pos,inverse);
            rotation0=m0+0xC0;
            if(*(s32 *)(m0+0x24)==0) func_0038D308(rotation0,m0+0xF0);
            func_0038D5F0(&out[count],inverse,rotation0);
            *(u16 *)(m0+0x34)|=0x104;
            count++;
        } while(*list++>=0);
    }
    if(tieid!=-1) {
        s32 anim=0;
        if(tex>0) anim=func_00382498(0,tex);
        if(tieid<D_L01_001D6768[0] && (list=D_001D6764_sda[tieid])!=0) {
            do {
                s32 id=*(u16 *)list&0x7FFF;
                u8 *m1=D_L01_001E0EDC[0]+(id<<6);
                if(count>=max) goto finish;
                out[count].flags=1;
                out[count].id=id;
                out[count].last=2;
                out[count].f40=0;
                if(parent!=0) {
                    out[count].parent=parent;
                    if(out[count].bone==255) {
                    a[0]=*(Q_0044ED88 *)(m1+0x30);
                    b[0]=*(Q_0044ED88 *)m1;
                    out[count].bone=func_L01_0044EC78((int)parent,(u8 *)joints,njoints,a,b,pos,inverse);
                    }
                }
                if(tex<=0) {
                    out[count].period=(tex<0)?255:0;
                } else {
                    out[count].period=tex+1;
                    out[count].phase=anim;
                    anim=(anim+1)%out[count].period;
                }
                vec_sub_ba(&out[count].pos,m1+0x30,pos);
                func_0038D000(&out[count].pos,&out[count].pos,inverse);
                func_0038D5F0(&out[count],inverse,m1);
                count++;
            } while(*list++>=0);
        }
    }
    if(shrubid!=-1 && shrubid<D_001D6770_sda && (list=D_L01_001D676C[0][shrubid])!=0) {
        do {
            s32 id=*(u16 *)list&0x7FFF;
            u8 *m2=D_L01_001E0DD0+(id<<6);
            if(count>=max) goto finish;
            out[count].id=id;
            out[count].flags=2;
            out[count].last=2;
            out[count].f40=0;
            vec_sub_ab(&out[count].pos,m2+0x30,pos);
            func_0038D000(&out[count].pos,&out[count].pos,inverse);
            func_0038D5F0(&out[count],inverse,m2);
            count++;
        } while(*list++>=0);
    }
    }
finish:
    if(count!=0) out[count-1].last=1;
    else out->last=0;
}
/* localdecomp:end func_L01_0044ED88 */
