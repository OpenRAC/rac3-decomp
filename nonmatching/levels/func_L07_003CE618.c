/* PAL near miss, 2026-11-16 (P05): 41 raw positional word differences
 * with the owning file's -O2 -G8 -fopt-stack -mno-check-zero-division
 * @ps2as. Reconstructed from retail. The frame and rendering flow agree;
 * count*2 is scheduled too early, table pointers take different saved
 * registers, and table-store/address setup order differs. Separate tail
 * count-down iteration improved 102 to 41. Incomplete-array .sdata made
 * it worse (120). No flags, padding tables or compiler transforms changed.
 * Not promoted; full-program equality has not been established.
 */
#include "common.h"
typedef struct { float x,y,z; } V_3CE618;
typedef struct { float x,y,z,w; } T_3CE618;
extern V_3CE618 D_L07_002A2BD0[];
extern u32 D_L07_002A2CC0[][2];
extern T_3CE618 D_L07_002A2D10[];
extern f32 D_L07_001E17A0[];
extern void func_0038C750(void);
extern s32 func_00389598(s32);
extern s32 func_003A9440(s32, unsigned long);
extern f32 func_0038CF00(void *,void *);
extern void func_0038CC88(void *,void *,s32);
extern u32 func_0038DBD8(u32,u32,f32);
extern void func_003D3A24(s32,void *,void *,void *,s32);
void func_L07_003CE618(void *arg0,void *arg1,s32 count,s32 head,s32 texture,u32 col0,u32 col1) {
    u8 *a=arg0,*b=arg1;
    s32 i,idx,next;
    f32 sum, t, inv;
    u32 col;
    s32 n;
    if (count<2) return;
    func_0038C750();
    sum=0.0f;
    texture=func_00389598(texture);
    func_003A9440(6,texture);
    func_003A9440(20,0xFF9000000260UL);
    func_003A9440(8,0);
    n=count*2;
    func_003A9440(66,0x4000000044UL);
    for(i=0;i<count;i++) {
        idx=(i+head)%count;
        next=(idx+1)%count;
        if (i!=count-1) {
            f32 d=func_0038CF00(a+idx*16,a+next*16);
            sum+=d;
            D_L07_001E17A0[i]=d;
        }
        func_0038CC88(&D_L07_002A2BD0[i*2],a+idx*16,12);
        func_0038CC88(&D_L07_002A2BD0[i*2+1],b+idx*16,12);
    }
    inv=1.0f/sum;
    t=0.0f;
    i=0;
    if(count>0) do {
        col=func_0038DBD8(col1,col0,t);
        count--;
        D_L07_002A2CC0[i][1]=col;
        D_L07_002A2CC0[i][0]=col;
        D_L07_002A2D10[i].x=t;
        D_L07_002A2D10[i].y=0.0f;
        D_L07_002A2D10[i].z=t;
        D_L07_002A2D10[i].w=1.0f;
        t+=D_L07_001E17A0[i]*inv;
        i++;
    } while(count!=0);
    func_003D3A24(n,D_L07_002A2BD0,D_L07_002A2CC0,D_L07_002A2D10,1);
    func_003A9440(71,0x5360B);
}
