/* PAL near miss, P01 wave 2 (2026-11-16), reconstructed from retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 54 positional differences. Remaining differences include
 * register selection in setup/max/quotient calculations and countdown-loop
 * scheduling, plus the destination pointer's induction form.
 * Not a full-program match; retain the source INCLUDE_ASM.
 */
#include "common.h"
typedef struct { u8 pad[4]; u8 *rows; u8 gap[8]; } T_331BB0;
typedef struct { s32 ids[6]; u8 pad[0x86]; u8 mode, index; } V_331BB0;
extern T_331BB0 D_L07_002B0D40_00331BB0[];
extern u8 *D_L07_001DF41C_00331BB0;
extern void *func_0011A264(void *, s32, u32);
extern s32 func_L07_003343E8(s32);
extern void func_L07_00334318(void *, s32 *, s32 *);
extern s32 func_L07_00333B68(void *);
extern s32 func_00382468(s32);
extern s32 func_L07_00333D70(u8 *, s32, s32, s32);
extern s32 func_L07_00333D40(void *, void *);
void func_L07_00331BB0(u8 *self) {
    s32 totals[2];
    u8 counts[7];
    s32 quotient[2];
    s32 remainder[2];
    s32 index, direction;
    V_331BB0 *v = *(V_331BB0 **)(self+0x68);
    u8 *row = D_L07_002B0D40_00331BB0[v->mode].rows + v->index*12;
    s32 empty = 1, i, j, n, rounds;
    func_0011A264(totals, 0, 8);
    row += 2;
    for (i=0; i<7; i++) {
        counts[i] = *row;
        totals[func_L07_003343E8(i)] += *row++;
        if (counts[i]) empty = 0;
    }
    if (empty) return;
    rounds = totals[1];
    if (rounds < totals[0]) rounds = totals[0];
    rounds = (rounds+3)/4;
    if (rounds <= 0) return;
    for (j=0; j<2; j++) {
        quotient[j] = totals[j]/rounds;
        remainder[j] = totals[j]%rounds;
    }
    n=1;
    func_L07_00334318(self, &index, &direction);
    while ((totals[0]>0 || totals[1]>0) && n<6) {
        u8 *obj;
        s32 next=n+1;
        obj=D_L07_001DF41C_00331BB0+(v->ids[index]<<8);
        if (obj[0x20]==1) {
            u8 *r=(u8 *)func_L07_00333B68(obj);
            for (i=0; i<2; i++) {
                s32 take=quotient[i];
                s32 k;
                if (remainder[i]>0) { take++; remainder[i]--; }
                for (k=take; k>0; k--) {
                    s32 selected;
                    s32 random=func_00382468(totals[i]);
                    if (i==1) selected=func_L07_00333D70(counts,random,1,6);
                    else selected=func_L07_00333D70(counts,random,6,0);
                    if (selected!=-1) {
                        r[12+selected]++;
                        counts[selected]--;
                        totals[i]--;
                    }
                }
            }
            func_L07_00333D40(*(void **)(r+8),obj);
        }
        index += n*direction;
        if (index<0) index+=6;
        if (index>=6) index-=6;
        direction=-direction;
        n=next;
    }
}
