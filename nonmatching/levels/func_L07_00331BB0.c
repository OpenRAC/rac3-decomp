/* PAL near miss (Codex wave 6): near miss: 30 words differ with the file's flags.
 * Worker's note: 30 diff in w304/331BB0-06.log; full 824-byte draft, remaining scalar/pointer register allocation, inner-loop constant hoisting and addressing; best retained after 10 compiles.
 */
#include "common.h"
/* localdecomp:start func_L07_00331BB0 */
extern S_L07_00331EE8 D_L07_002B0D40[];
extern u8 *D_L07_001DF41C;
void func_L07_00331BB0(void *self) {
    extern void *func_0011A264(void *,s32,s32);
    extern s32 func_L07_003343E8(s32);
    extern void func_L07_00334318(void *,s32 *,s32 *);
    extern s32 func_L07_00333B68(void *);
    extern s32 func_00382468(s32);
    extern s32 func_L07_00333D70(u8 *,s32,s32,s32);
    extern s32 func_L07_00333D40(void *,void *);
    s32 totals[2];
    u8 counts[7];
    s32 quotient[2];
    s32 remainder[2];
    s32 index,direction;
    u8 *state=*(u8 **)((u8 *)self+0x68);
    u8 *row=(u8 *)D_L07_002B0D40[state[0x9E]].f4+state[0x9F]*12;
    s32 empty=1;
    s32 i,j,k,n,choice,amount,pass,next;
    u8 *m;
    s32 vars;
    func_0011A264(totals,0,8);
    row+=2;
    for (i=0;i<7;i++) {
        counts[i]=row[i];
        totals[func_L07_003343E8(i)]+=row[i];
        if (counts[i]) empty=0;
    }
    if (empty) return;
    amount=((totals[0]>totals[1]?totals[0]:totals[1])+3)/4;
    if (amount<=0) return;
    for (k=0;k<2;k++) {
        quotient[k]=totals[k]/amount;
        remainder[k]=totals[k]%amount;
    }
    pass=1;
    func_L07_00334318(self,&index,&direction);
    while ((totals[0]>0 || totals[1]>0) && pass<6) {
        next=pass+1;
        m=D_L07_001DF41C+(*(s32 *)(state+index*4)<<8);
        if (m[0x20]==1) {
            vars=func_L07_00333B68(m);
            for (i=0;i<2;i++) {
                n=quotient[i];
                if (remainder[i]>0) { n++; remainder[i]--; }
                if (n>0) {
                for (j=n;j!=0;j--) {
                    s32 r=func_00382468(totals[i]);
                    switch (i) {
                    case 1: choice=func_L07_00333D70(counts,r,1,6); break;
                    default: choice=func_L07_00333D70(counts,r,6,0); break;
                    }
                    if (choice!=-1) {
                        ((u8 *)(vars+12))[choice]++;
                        counts[choice]--;
                        totals[i]--;
                    }
                }
                }
            }
            func_L07_00333D40(*(void **)(vars+8),m);
        }
        index+=pass*direction;
        if (index<0) index+=6;
        if (index>=6) index-=6;
        direction=-direction;
        pass=next;
    }
}
/* localdecomp:end func_L07_00331BB0 */
