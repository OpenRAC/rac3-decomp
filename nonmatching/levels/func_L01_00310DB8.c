/* PAL near miss (sonnet-b30-j2, round 19): 25 words differ when aligned (difflib; the raw count is 209 because retail has one extra
 * `move $v0, $s0` in the loop head), 7 with registers masked, 5 with opcodes only. Same function as func_L01_003973F8 and
 * func_L01_003DE510 (same fingerprint, 34 places): this C replaces those two drafts' C (215 / 312 diffs) as a starting point.
 * Needs S mode: retail builds the `lui $v0, 0x1e; lqc2 $vf1, 0x29c0($v0)` of D_L01_001E29C0 with split addresses, the file's
 * line has -mno-split-addresses. Check it with `python tools/check.py nonmatching/levels/func_L01_00310DB8.c func_L01_00310DB8
 * --no-context --mode S --as ps2as --flags=-mvu0-use-vf0-vf2` (a match would be a cut: a file of its own at 0x310DB8,
 * `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2`; the function is the old file's last block).
 * What fixed the rest (all one compile each): the order of the prologue stores (climb over the 10 statements), `inner.pos[2]`
 * stored before `outer.pos[2]` in the last segment, `bytes + points` (not points + bytes), `v -= 1.0f; u -= 1.0f` in the loop's
 * if (and `u -= 1.0f; v -= 1.0f` in the last segment: sched1 emits the two subs in reverse source order).
 * Still different: (a) the loop's u/v: retail has u in $f1 and v in $f0 there ($f0/$f1 in the last segment, which matches), about
 * 12 words of registers: global-alloc priorities u 22 refs/18 insns > v 18/17, retail needs v first; separate per-block variables,
 * declaration order, extra copies (cprop removes them), the order of the stores and of the phase adds did not move it;
 * (b) retail's loop head has `sll $v0; addu $s0,$v0,$a0; ...; move $v0,$s0; lqc2 $vf1,0($s0); lqc2 $vf2,16($v0)`: a copy of the
 * point pointer as the base of `point + 1` that every pointer form tried here (&point[1], (u8 *)point + 16, two pointer
 * variables, points + next) loses to cprop; (c) the last segment's `lq`/`sq` order (retail stores matrix[3] before loading
 * the two offsets and keeps `sq $v1, 0x30` in the jal slot). */
#include "common.h"
/* localdecomp:start func_L01_00310DB8 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_310DB8;
typedef struct {
    V_310DB8 pos[4];
    u32 color[4];
    f32 uv[4][2];
    u8 tail[0x20];
} Poly_310DB8;
extern vu0_v4 D_L01_001E29C0;
void func_L01_00310DB8(V_310DB8 *start,V_310DB8 *points,u32 color,s32 count,f32 phase,f32 width,f32 step)
{
    extern void func_003D93B0(void *,s32,s32,s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern void func_0038D028(void *,void *,void *);
    extern void func_003D2DA0(void *,s32,s32);
    V_310DB8 origin;
    Poly_310DB8 outer,inner;
    V_310DB8 matrix[4];
    V_310DB8 offset,offset2;
    s32 i,next;
    s32 bytes;
    V_310DB8 *point;
    f32 u,v;
    origin.q=start->q;
    start=&origin;
    func_003D93B0(&outer,43,1,128);
    func_003D93B0(&inner,43,1,128);
    offset2.q=offset.q=0;
    width*=0.25f;
    outer.color[0]=outer.color[1]=color;
    inner.color[0]=inner.color[1]=color;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    offset.f[3]=1.0f;
    offset2.f[3]=1.0f;
    offset.f[2]=width;
    offset2.f[2]=width+width;
    if ((func_0013D3E0()&1)==0) {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=0.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=1.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=0.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=1.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=0.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=1.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=0.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=1.0f;
    } else {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=1.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=0.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=1.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=0.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=1.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=0.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=1.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=0.0f;
    }
    vec_sub_ba(&matrix[0],points,start);
    func_0038CF68(&matrix[0],&matrix[0],1.0f);
    vec_sub_ba(&matrix[1],&D_L01_001E29C0,start);
    func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
    i=0;
    bytes=count<<4;
    func_0038CF68(&matrix[2],&matrix[2],1.0f);
    func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
    matrix[3].q=start->q;
    outer.pos[0].q=offset.q;
    inner.pos[0].q=offset2.q;
    func_0038CE20(outer.pos[1].f,outer.pos[0].f,-1.0f);
    func_0038CE20(inner.pos[1].f,inner.pos[0].f,-1.0f);
    func_0038D028(&outer.pos[0],&outer.pos[0],matrix);
    func_0038D028(&outer.pos[1],&outer.pos[1],matrix);
    func_0038D028(&inner.pos[0],&inner.pos[0],matrix);
    func_0038D028(&inner.pos[1],&inner.pos[1],matrix);
    while (i<count-1) {
        point=(V_310DB8 *)((i<<4)+(s32)points);
        next=i+1;
        vec_sub_ab(&matrix[0],point+1,point);
        func_0038CF68(&matrix[0],&matrix[0],1.0f);
        vec_sub_ab(&matrix[1],&D_L01_001E29C0,point);
        func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
        func_0038CF68(&matrix[2],&matrix[2],1.0f);
        func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
        offset.f[2]*=0.7f;
        matrix[3].q=point->q;
        offset2.f[2]=offset.f[2]+offset.f[2];
        outer.pos[2].q=offset.q;
        inner.pos[2].q=offset2.q;
        func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
        func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
        func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
        func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
        func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
        func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
        u=step*(f32)next; v=u+step;
        if (u>=1.0f) {v-=1.0f;u-=1.0f;}
        v+=phase;u+=phase;
        outer.uv[0][0]=u;outer.uv[1][0]=u;
        outer.uv[2][0]=v;outer.uv[3][0]=v;
        inner.uv[0][0]=u;inner.uv[1][0]=u;
        inner.uv[2][0]=v;inner.uv[3][0]=v;
        func_003D2DA0(&outer,0,0);
        func_003D2DA0(&inner,0,0);
        if (i!=0) {
            outer.color[0]=outer.color[1]=color|0x7F000000;
            inner.color[0]=inner.color[1]=color|0x3F000000;
        }
        i=next;
        outer.pos[0].q=outer.pos[2].q;
        outer.pos[1].q=outer.pos[3].q;
        inner.pos[0].q=inner.pos[2].q;
        inner.pos[1].q=inner.pos[3].q;
        outer.color[2]=outer.color[3]=color|0x7F000000;
        inner.color[2]=inner.color[3]=color|0x3F000000;
    }
    offset.f[2]*=0.7f;
    matrix[3].q=((V_310DB8 *)(bytes+(s32)points))[-1].q;
    offset2.f[2]=offset.f[2]+offset.f[2];
    inner.pos[2].q=offset2.q;
    outer.pos[2].q=offset.q;
    func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
    func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
    func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
    func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
    func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
    func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
    u=step*(f32)(i+1);v=u+step;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    if (u>=1.0f) {u-=1.0f;v-=1.0f;}
    u+=phase;v+=phase;
    outer.uv[0][0]=u;outer.uv[1][0]=u;
    outer.uv[2][0]=v;outer.uv[3][0]=v;
    inner.uv[0][0]=u;inner.uv[1][0]=u;
    inner.uv[2][0]=v;inner.uv[3][0]=v;
    func_003D2DA0(&outer,0,0);
    func_003D2DA0(&inner,0,0);
}
/* localdecomp:end func_L01_00310DB8 */
