/* NTSC-U draft (2026-11-14, Codex worker): C of func_L05_003BB658, the NTSC-U twin of func_L05_003BD5E0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L05_003BD078.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003BB658 */
static __inline__ void sub_003BB658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_003BB658(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
typedef struct { u8 pad[0x10]; vu0_v4 pos; u8 state; u8 pad21[0x47]; u8 *vars; u8 pad6C[0x3E]; s16 type; u8 padAC[0xC]; void *parent; } M_003BB658;
extern void func_003BDA38(void *, s32, void *);
extern void func_003BFC18(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_L05_003BC008(void *, s32, void *);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L05_003BB120(void *);
extern void func_L01_004026A0(void *, void *);
extern M_003BB658 *D_001A71A0[];
extern f32 D_001DEB24_sda;
extern s32 D_001DEB20_sda;
extern vu0_v4 D_L05_001EA760[];
extern u8 D_L05_002A6540[];
extern u8 D_L05_002207D8[];
extern u8 D_L05_001D66B0[];
extern u8 D_L05_003BBBC8[];
void func_L05_003BB658(M_003BB658 *m) {
    vu0_v4 p0, p10, p20, p30, hit, dir;
    u8 damage[0x30] __attribute__((aligned(16)));
    u8 *v = m->vars;
    f32 angle;
    s32 i;
    u8 *part;
    func_003BDA38(m->parent, *(s32 *)(v+0x1C), &p0);
    *(vu0_q *)&m->pos = *(vu0_q *)&p0;
    func_003BFC18(&m->pos, &p10, 1);
    *(vu0_q *)&p20 = *(vu0_q *)&m->pos;
    sub_003BB658(&p30, v+0x30, &m->pos);
    func_00388830(&p30, &p30, 1.0f);
    angle = func_00388A28(*(f32 *)(v+0x30)-(*D_001A71A0)->pos.x, *(f32 *)(v+0x34)-(*D_001A71A0)->pos.y);
    if (angle < 1.57079637f) angle=func_0037E250(0.0f,-0.785398185f);
    else angle=func_0037E250(0.0f,0.785398185f);
    *(vu0_q *)(v+0x40)=*(vu0_q *)&m->pos;
    *(f32 *)(v+0x48)-=D_001DEB24_sda;
    sub_003BB658(v+0x40,v+0x40,&m->pos);
    func_00389158(v+0x40,v+0x40,&p30,angle);
    add_003BB658(v+0x40,&m->pos,v+0x40);
    switch (m->state) {
    case 0:
        if (((M_003BB658 *)m->parent)->type != 0x1BF6) {
            if (func_003CE740(&m->pos,v+0x30,2,m->parent,0))
                *(vu0_q *)(v+0x30)=*(vu0_q *)D_L05_001EA760;
            if (func_003CE740(&m->pos,v+0x30,0,m->parent,0)) {
                f32 scale=1.0f;
                u8 *other;
                *(vu0_q *)&hit=*(vu0_q *)D_L05_001EA760;
                sub_003BB658(&dir,v+0x30,&m->pos);
                func_00388830(&dir,&dir,1.0f);
                func_003886E8(&dir,&dir,1.0f);
                dir.w=5627.9248046875f;
                other=func_0037E0B8(m->parent);
                if(other) scale=(f32)other[0x14];
                func_L01_00443628(damage,m,1,&dir,scale);
                damage[0x19]=1;
                *(u16 *)(damage+0x1A)=m->type;
                damage[0x18]=1;
                func_003CF790(&hit,0,m,damage,0.25f);
                other=*(u8 **)((u8 *)D_L05_001EA760-8);
                if(!other) func_L05_003BC008(&hit,15,m);
                else if (*(s32 *)(other+0x98)) func_L05_003BC008(&hit,10,m);
                m->state=1;
                *(s32 *)(v+0x10)=D_001DEB20_sda;
                if(((M_003BB658 *)m->parent)->type==0x1BF6) *(s32 *)(v+0x10)<<=3;
            } else {
                m->state=1;
                *(s32 *)(v+0x10)=D_001DEB20_sda;
                if(((M_003BB658 *)m->parent)->type==0x1BF6) *(s32 *)(v+0x10)<<=3;
            }
        } else {
            m->state=1;
            *(s32 *)(v+0x10)=D_001DEB20_sda;
            if(((M_003BB658 *)m->parent)->type==0x1BF6) *(s32 *)(v+0x10)<<=3;
        }
        break;
    case 1:
        if(func_00388398(v+0x10)) {
            *(s32 *)(v+0xC)=0;
            *(s16 *)(D_L05_002A6540+(*(s32 *)(v+0x60)<<3))=0;
            func_003BD360(m);
            return;
        }
        for(i=9;i>=0;i--) {
            f32 size=func_0037E250(0.15f,0.25f)*210000.0f;
            part=func_L01_0046C468(&m->pos,D_L05_001D66B0,2,0x1010FF,2,127,16,0,size,size,0.0f);
            if(part) part[2]=**(u8 **)(D_L05_002207D8+0x64);
            part=func_L01_0046C468(&m->pos,D_L05_001D66B0,2,0x1010FF,-1,127,16,0,size,size,0.0f);
            if(part) part[2]=**(u8 **)(D_L05_002207D8+0x1A0);
        }
        if(*(s32 *)(v+0x10)>=6) func_L05_003BB120(m);
        func_L01_004026A0(D_L05_003BBBC8,m);
        break;
    }
    if(m->pos.x<2.0f || m->pos.x>1021.0f || m->pos.y<2.0f || m->pos.y>1021.0f || m->pos.z<2.0f || m->pos.z>1021.0f) {
        *(s16 *)(D_L05_002A6540+(*(s32 *)(v+0x60)<<3))=0;
        func_003BD360(m);
    }
}
/* localdecomp:end func_L05_003BB658 */
