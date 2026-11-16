/* PAL near miss (Codex wave 7): near miss: 300 words differ with the file's flags.
 * Worker's note: 299 diff; best log build/codex/w357/func_L32_003A16C8.check.3.log (retained revision check.4.log); fixed default assembler emits .lit4 for 0.33f vs retail inline lui/ori/mtc1, VU sequence scheduling and register allocation differ; j helpers unavailable under ...
 */
#include "common.h"
/* localdecomp:start func_L32_003A16C8 */
#include "vu0.h"
typedef struct { u8 pad[0x10]; vu0_v4 pos; u8 pad20[0x48]; void *data; } Obj_003A16C8;
typedef struct { Obj_003A16C8 *owner; u8 pad[4]; u8 life, flags; u16 bits; } State_003A16C8;
typedef struct { u8 pad[0x30]; vu0_v4 pos; } Node_003A16C8;
typedef struct { u8 pad[0x200]; Obj_003A16C8 *nodes[6]; } Owner_003A16C8;
typedef struct { u8 pad[3]; u8 kind; u32 color; u16 pad8; s16 life; u32 color2; vu0_v4 a,b; } Output_003A16C8;
extern u8 D_L32_001E2280[];
extern f32 D_L32_001DE790, D_L32_001DE78C, D_L32_001DE77C, D_L32_001DE7A4;
extern s32 D_L32_001DE798, D_L32_001DE794, D_L32_001DE7A8, D_L32_001DE7A0, D_L32_001DE79C;
void func_L32_003A16C8(Output_003A16C8 *out, State_003A16C8 *state) {
    extern s32 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_003C4088(f32,f32,f32);
    extern s32 func_L01_00448070(s32,s32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    Obj_003A16C8 *owner;
    Owner_003A16C8 *data;
    Obj_003A16C8 **nodes;
    Node_003A16C8 *from,*to;
    vu0_v4 delta, offset, pos;
    s32 first,second,i;
    f32 r0,r1,t,power,x,y;
    u16 bits;
    u8 *settings;
    if (!state) return;
    owner=state->owner;
    settings=D_L32_001E2280;
    if (!owner) return;
    data=owner->data;
    if (!data || !settings) return;
    first=func_00382498(0,5);
    if (func_003824E0(0.0f,1.0f)<0.33f) second=first+3;
    else if (func_003824E0(0.0f,1.0f)<0.5f) second=first+1;
    else second=first+5;
    second%=6;
    nodes=data->nodes;
    if (state->flags&1) {
        r0=func_003824E0(0.0f,1.0f);
        r1=func_003824E0(0.0f,1.0f);
        state->bits=first+(second<<3)+((s32)(r1*31.0f)<<6)+((s32)(r0*31.0f)<<11);
        if (!nodes[first] || !nodes[second]) {out->life=0;return;}
        *(vu0_q *)&out->a=*(vu0_q *)&nodes[first]->pos;
        r0=(r0+1.0f)*0.5f;
        *(vu0_q *)&out->b=*(vu0_q *)&nodes[first]->pos;
        out->a.w=func_003C4088(D_L32_001DE790,D_L32_001DE78C,r0);
        out->b.w=1.0f;
        state->life=func_L01_00448070(D_L32_001DE798,D_L32_001DE794,r0)/4;
        out->life=state->life*4;
        out->kind=settings[0x10];
    }
    if (!nodes[first] || !nodes[second]) {out->life=0;return;}
    t=1.0f-((f32)out->life*0.25f)/(f32)state->life;
    power=1.0f;
    bits=state->bits;
    i=D_L32_001DE7A8; if(i>0) do { power*=t; } while(--i);
    first=bits&7;
    if (!nodes[first]) return;
    from=nodes[first]->data;
    if (!from) return;
    if (!nodes[(bits&0x38)>>3]) return;
    to=nodes[(bits&0x38)>>3]->data;
    if (!to) return;
    y=(f32)(bits>>11)/31.0f;
    x=(f32)((bits&0x7C0)>>6)/31.0f;
    __asm__("lqc2 $vf2, %2\n\t" "lqc2 $vf1, %1\n\t" "vsub.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&delta)) : "m"(*(vu0_v4 *)(&to->pos)), "m"(*(vu0_v4 *)(&from->pos)) : "vf1", "vf2");
    func_0038CE20(&delta,&delta,t);
    r0=0.5f-fabs_asm(t-0.5f);
    __asm__("lqc2 $vf1, %1\n\t" "lqc2 $vf2, %2\n\t" "vadd.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&pos)) : "m"(*(vu0_v4 *)(&delta)), "m"(*(vu0_v4 *)(&from->pos)) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\t" "lqc2 $vf2, %2\n\t" "vsub.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&offset)) : "m"(*(vu0_v4 *)(&pos)), "m"(*(vu0_v4 *)(&owner->pos)) : "vf1", "vf2");
    func_0038CF68(&offset,&offset,D_L32_001DE77C*x*(r0+r0)+y*D_L32_001DE7A4);
    __asm__("lqc2 $vf1, %1\n\t" "lqc2 $vf2, %2\n\t" "vadd.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&pos)) : "m"(*(vu0_v4 *)(&pos)), "m"(*(vu0_v4 *)(&offset)) : "vf1", "vf2");
    *(long *)&out->a=*(long *)&pos;
    *(s32 *)&out->a.z=*(s32 *)&pos.z;
    __asm__("lqc2 $vf2, %2\n\t" "lqc2 $vf1, %1\n\t" "vsub.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&delta)) : "m"(*(vu0_v4 *)(&to->pos)), "m"(*(vu0_v4 *)(&from->pos)) : "vf1", "vf2");
    func_0038CE20(&delta,&delta,power);
    r0=0.5f-fabs_asm(power-0.5f);
    __asm__("lqc2 $vf1, %1\n\t" "lqc2 $vf2, %2\n\t" "vadd.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&pos)) : "m"(*(vu0_v4 *)(&delta)), "m"(*(vu0_v4 *)(&from->pos)) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\t" "lqc2 $vf2, %2\n\t" "vsub.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&offset)) : "m"(*(vu0_v4 *)(&pos)), "m"(*(vu0_v4 *)(&owner->pos)) : "vf1", "vf2");
    func_0038CF68(&offset,&offset,D_L32_001DE77C*x*(r0+r0)+y*D_L32_001DE7A4);
    __asm__("lqc2 $vf1, %1\n\t" "lqc2 $vf2, %2\n\t" "vadd.xyz $vf1, $vf1, $vf2\n\t" "sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&pos)) : "m"(*(vu0_v4 *)(&pos)), "m"(*(vu0_v4 *)(&offset)) : "vf1", "vf2");
    *(long *)&out->b=*(long *)&pos;
    *(s32 *)&out->b.z=*(s32 *)&pos.z;
    out->color=(func_0038DBD8(D_L32_001DE7A0,D_L32_001DE79C,t)&0xFFFFFF)+((s32)(t*64.0f+63.0f)<<24);
    func_0038DBD8(D_L32_001DE7A0,D_L32_001DE79C,power);
    out->color2=(out->color&0xFFFFFF)+((s32)(power*64.0f+63.0f)<<24);
}
/* localdecomp:end func_L32_003A16C8 */
