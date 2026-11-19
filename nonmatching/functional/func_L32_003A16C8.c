/* functional: high. Codex near miss (299 diff, scheduling/regalloc) re-read line by line against PAL asm: all branches, offsets, gp globals (DE77C/DE78C/DE790/DE794/DE798/DE79C/DE7A0/DE7A4/DE7A8) and callees verified; raw lqc2 asm replaced by vu0.h helpers. Retail ignores the 2nd func_0038DBD8 result and reuses out->color; kept. Note the power-loop is a plain counted loop. */
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
    vec_sub_ba(&delta, &to->pos, &from->pos);
    func_0038CE20(&delta,&delta,t);
    r0=0.5f-fabs_asm(t-0.5f);
    vec_add_ab(&pos, &delta, &from->pos);
    vec_sub_ab(&offset, &pos, &owner->pos);
    func_0038CF68(&offset,&offset,D_L32_001DE77C*x*(r0+r0)+y*D_L32_001DE7A4);
    vec_add_ab(&pos, &pos, &offset);
    *(long *)&out->a=*(long *)&pos;
    *(s32 *)&out->a.z=*(s32 *)&pos.z;
    vec_sub_ba(&delta, &to->pos, &from->pos);
    func_0038CE20(&delta,&delta,power);
    r0=0.5f-fabs_asm(power-0.5f);
    vec_add_ab(&pos, &delta, &from->pos);
    vec_sub_ab(&offset, &pos, &owner->pos);
    func_0038CF68(&offset,&offset,D_L32_001DE77C*x*(r0+r0)+y*D_L32_001DE7A4);
    vec_add_ab(&pos, &pos, &offset);
    *(long *)&out->b=*(long *)&pos;
    *(s32 *)&out->b.z=*(s32 *)&pos.z;
    out->color=(func_0038DBD8(D_L32_001DE7A0,D_L32_001DE79C,t)&0xFFFFFF)+((s32)(t*64.0f+63.0f)<<24);
    func_0038DBD8(D_L32_001DE7A0,D_L32_001DE79C,power);
    out->color2=(out->color&0xFFFFFF)+((s32)(power*64.0f+63.0f)<<24);
}
/* localdecomp:end func_L32_003A16C8 */
