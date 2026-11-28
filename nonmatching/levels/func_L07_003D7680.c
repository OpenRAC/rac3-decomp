/* Wave 13 (r27, 2026-11-28) replaces the earlier draft of this function (Codex wave 8 near miss). */
#include "common.h"

/* func_L07_003D7680, retry (wave 13 r27). Changes against the Codex wave 8 draft (204 diff): the draft's own
 * multi-instruction VU0 asm blocks are replaced by include/vu0.h's vec_add_ab/vec_add_ba/vec_sub_ab (the
 * file's other C uses them; retail interleaves the sequences, which one asm block cannot); the second
 * vector of each pair goes to temp again (retail stores both at 0x60, no 'minus'); face is counted
 * through a second variable (n = face + 1 ... face = n), which reproduces retail's face spill (store at
 * the top, reload into a register at the bottom); face = 0 at the top (s-register like retail); loops 1-3
 * use separate counters (j, k, i). Now 168 diff (275 instructions, same count as retail).
 * Still differs: the spill choice (retail spills count-1 @0x80, face @0x84, inner_index @0x88 and keeps
 * outer_index in fp; here inner/outer_index and face are spilled and last stays in s6), the loop 1 store
 * D[last] (CSE substitutes last for j; retail stores through the D[j] pointer), the inner/outer pointer
 * init (retail computes it after the loop's blez, as loop givs) and s0/s1 roles. A variant with no 'last'
 * variable (count - 1 in all three places, unified by gcse into one pseudo) is structurally closer (58
 * aligned differing lines against 78 here, loop 1 then matches) but counts 171 because it has two more
 * instructions. Retail's frame also has an unused 16-byte slot at 0x70 before the spill slots. */
/* localdecomp:start func_L07_003D7680 */
#include "vu0.h"
extern vu0_v4 D_L07_002A2DC0[];
extern vu0_v4 D_L07_001E1EC0[];
extern f32 D_L07_002A2E40[][3];
extern f32 D_L07_002A32C0[][3];
extern s32 D_L07_002A3740[], D_L07_002A38C0[];
extern f32 D_L07_002A3A40[][2];
void func_L07_003D7680(void *arg0, f32 radius, f32 offset, s32 count)
{
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern long func_00389598(s32);
    extern void func_003A9440(s32,long);
    extern void func_0038C750(void);
    extern void func_003D3A24(s32,void *,void *,void *,s32);
    vu0_v4 origin, previous, next, step, view, normal, temp;
    s32 last=count-1;
    s32 face = 0;
    s32 i, j, k;
    s32 total=0, outer_index=0, inner_index=0;
    f32 angle, inv;
    f32 *inner,*outer;
    u8 *obj=arg0;
    *(vu0_q *)&origin=*(vu0_q *)(obj+0x10);
    origin.z+=0.45f;
    angle=func_0038DAB8(*(f32 *)(obj+0xF8),offset);
    inv=1.0f/last;
    previous.x=func_0038D098(angle)*radius;
    previous.y=func_0038D0B0(angle)*radius;
    previous.z=0.0f;
    vec_add_ab(&previous,&origin,&previous);
    do {
        s32 n = face + 1;
        angle=func_0038DAB8(angle,1.0471976f);
        next.x=func_0038D098(angle)*radius;
        next.y=func_0038D0B0(angle)*radius;
        next.z=0.0f;
        vec_add_ba(&next,&origin,&next);
        vec_sub_ab(&step,&next,&previous);
        func_0038CE20(&step,&step,inv);
        *(vu0_q *)&D_L07_002A2DC0[0]=*(vu0_q *)&previous;
        for(j=1;j<count;j++) {
            if(j==last) *(vu0_q *)&D_L07_002A2DC0[j]=*(vu0_q *)&next;
            else vec_add_ab(&D_L07_002A2DC0[j],&D_L07_002A2DC0[j-1],&step);
        }
        for(k=1;k<last;k++) func_003C4C18(&D_L07_002A2DC0[k],0.11f);
        inner=(f32 *)((u8 *)D_L07_002A2E40+inner_index);
        outer=(f32 *)((u8 *)D_L07_002A32C0+outer_index);
        for(i=0;i<count;i++) {
            if(i!=0 || total==0) {
                vec_sub_ab(&view,D_L07_001E1EC0,&D_L07_002A2DC0[i]);
                func_0038CE90(&normal,&step,&view);
                func_0038CF68(&normal,&normal,0.02f);
                vec_add_ba(&temp,&D_L07_002A2DC0[i],&normal);
                inner[0]=temp.x; inner[1]=temp.y; inner[2]=temp.z;
                vec_sub_ab(&temp,&D_L07_002A2DC0[i],&normal);
                inner[3]=temp.x; inner[4]=temp.y; inner[5]=temp.z;
                func_0038CE20(&normal,&normal,8.0f);
                vec_add_ba(&temp,&D_L07_002A2DC0[i],&normal);
                outer[0]=temp.x; outer[1]=temp.y; outer[2]=temp.z;
                vec_sub_ab(&temp,&D_L07_002A2DC0[i],&normal);
                outer[3]=temp.x; outer[4]=temp.y; outer[5]=temp.z;
                total+=2;
                inner_index+=24;
                outer_index+=24;
                inner+=6;
                outer+=6;
            }
        }
        *(vu0_q *)&previous=*(vu0_q *)&next;
        face = n;
    } while(face<6);
    func_003A9440(6,func_00389598(0x2B));
    func_003A9440(8,0);
    func_003A9440(0x42,0x8000000048L);
    func_0038C750();
    func_003D3A24(total,D_L07_002A2E40,D_L07_002A3740,D_L07_002A3A40,1);
    func_003A9440(6,func_00389598(0x2B));
    func_0038C750();
    func_003D3A24(total,D_L07_002A32C0,D_L07_002A38C0,D_L07_002A3A40,1);
}
/* localdecomp:end func_L07_003D7680 */
