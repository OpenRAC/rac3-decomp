/* PAL near miss (Codex wave 8): near miss: 226 words differ with the file's flags.
 * Worker's note: 226 diff after 10 checks; full draft retained; loop pointer lifetimes, register allocation and instruction scheduling remain; best log build/codex/w410/func_L07_0032F988-08.log
 */
#include "common.h"
/* localdecomp:start func_L07_0032F988 */
extern u8 *D_L07_001DF41C;
extern s32 D_L07_001DF458;
extern s16 *D_L07_0021C020[];
extern u8 D_L07_001DD104;
extern u8 D_001426E0[];
extern s32 D_00142848[];
void func_L07_0032F988(u8 *obj)
{
    extern s32 *func_L07_00333918(void *);
    extern s32 *func_L07_00333B20(void *);
    extern s32 *func_L07_00333B68(void *);
    extern void func_L07_003328D0(s32);
    extern void func_L07_00332BE0(u8 *);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *d = *(u8 **)(obj+0x68);
    s32 *ids = (s32 *)(d+0x1C);
    s32 *direct = (s32 *)(d+0x38);
    s32 *ids2 = (s32 *)(d+0x44);
    s32 *tail = (s32 *)(d+0x50);
    s32 i, next;
    u8 *p;
    for(i=0;i<7;i=next) {
        s16 *list;
        next=i+1;
        if(i==3 || i==4) continue;
        list=D_L07_0021C020[ids[i]];
        while((((s32 *)(d+0x1C))[i]&0xFF)!=0xFF && ((s32 *)(d+0x1C))[i]<=D_L07_001DF458 && list!=0) {
            u8 *p;
            if(list[-1]<0 && list!=D_L07_0021C020[((s32 *)(d+0x1C))[i]]) break;
            p=D_L07_001DF41C+((*list&0x7FFF)<<8);
            if(p==0) break;
            *(s16 *)(p+0x32)=150;
            p[0x30]=150;
            *func_L07_00333918(p)=(s32)obj;
            if(i==2 || i==5 || i==6) p[0x62]=0;
            list++;
        }
    }
    for(i=2;i>=0;i--) {
        u8 *p=D_L07_001DF41C+(*direct++<<8);
        *(s16 *)(p+0x32)=150;
        p[0x30]=150;
        *func_L07_00333918(p)=(s32)obj;
    }
    { s32 j, next2;
    for(j=0;j<3;j=next2) {
        s16 *list;
        next2=j+1;
        list=D_L07_0021C020[ids2[j]];
        while((ids2[j]&0xFF)!=0xFF && ids2[j]<=D_L07_001DF458 && list!=0) {
            u8 *p;
            if(list[-1]<0 && list!=D_L07_0021C020[ids2[j]]) break;
            p=D_L07_001DF41C+((*list&0x7FFF)<<8);
            if(p==0) break;
            *(s16 *)(p+0x32)=150;
            p[0x30]=150;
            *func_L07_00333B20(p)=(s32)obj;
            list++;
        }
    }
    }
    { s32 k;
    s32 *direct3=(s32 *)d;
    for(k=5;k>=0;k--) {
        u8 *p=D_L07_001DF41C+(*direct3++<<8);
        *(s16 *)(p+0x32)=150;
        p[0x30]=150;
        *func_L07_00333B68(p)=(s32)obj;
    }
    }
    p=D_L07_001DF41C+(*(s32 *)(d+0x18)<<8);
    p[0x30]=150;
    *(s16 *)(p+0x32)=150;
    *func_L07_00333B68(p)=(s32)obj;
    { s32 k;
    for(k=7;k>=0;k--) {
        u8 *p=D_L07_001DF41C+(*tail++<<8);
        p[0x30]=150;
        *(s16 *)(p+0x32)=150;
    }
    }
    if(D_L07_001DD104!=0) {
        d[0xBF]=1;
        func_L07_003328D0((s32)obj);
        D_L07_001DD104=0;
    }
    if(D_001426E0[0xE3]!=0) {
        s32 n=D_001426E0[0xE3];
        D_001426E0[0xE3]=0;
        D_00142848[0]=n-1;
    }
    *(s32 *)(d+0x70)=0;
    func_L07_00332BE0(obj);
    *(u16 *)(obj+0x34)|=1;
    func_L01_004450F0(obj,1,-1);
}
/* localdecomp:end func_L07_0032F988 */
