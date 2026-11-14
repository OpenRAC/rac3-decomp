/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_00562AB0, the NTSC-U twin of func_L39_005635D0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" when tried; not with src/levels/shared/L39_00563370.c's current line.
 * Worker's note: 395 diff; best log w133/func_L39_00562AB0.06.log; documented inline-literal assembler mismatch (Matching-Patterns.md:139): retail 210000.0f lui/ori/mtc1, ours lit4 lwc1 f21; no alternate flags permitted; retained .near.c
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00562AB0 */
/* Real VU0 sequences; this file's flags do not enable the compiler's j register class. */
static __inline__ void add_ba133(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void add_ab133(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void sub_ab133(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1","vf2");
}
static __inline__ void sub_global133(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, 0(%3)\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b),"r"(b) : "vf1","vf2");
}
typedef struct {s32 value; u8 pad[12];} Flag133;
extern Flag133 D_L39_002412A8;
extern s32 D_001DFD94_sda;
extern s32 D_001DFDC8_sda;
extern s32 D_001DFD70_sda,D_001DFD68_sda,D_001DFD6C_sda,D_001DFD74_sda;
extern s32 D_001DFDB0_sda,D_001DFDB4_sda,D_001DFDBC_sda;
extern f32 D_001DFD98_sda,D_001DFDB8_sda,D_001DFD84_sda,D_001DFDC0_sda;
extern u8 D_L39_001FE1A0[];
extern u8 *D_L39_0024D790[8];
extern s32 D_L39_0024D7B0[8];
extern s16 D_L39_0024D7D0[5],D_L39_0024D7E0[5],D_L39_0024D7F0[5];
extern u8 *D_L39_002638C0[];
extern u8 D_L39_00296918[];
extern vu0_v4 D_L39_0024DF00;
extern vu0_v4 D_L39_003CD580[5][10];
extern u8 D_L39_003CD570[];
extern void func_L01_004C5800(void);
extern f32 func_L01_004C5828(void);
extern s32 func_L39_005F08A0(void *,s32);
extern s32 func_L39_005F0CE0(s32,s32,void *);
extern void func_L39_005F0988(s32);
extern s32 func_L39_00564490(void *,f32);
extern void func_L01_003116F0(void);
extern void func_003BD360(void *);
extern s32 func_003894A0(s32,s32,f32);
extern s32 func_003883C8(void *);
extern s32 func_00388398(void *);
extern s32 func_L01_0040BB20(void *);
extern void func_003886E8(void *,void *,f32);
extern void func_003BDA38(void *,s32,void *);
extern s32 func_L39_005B24C8(s32,s32);
extern f32 func_L39_005B25C8(void);
extern void func_0037E4B8(void *,f32,f32,f32);
extern u8 *func_L01_00469378(void *,s32,s32,s32);
extern s32 func_003CF790(void *,s32,void *,s32,f32);
extern u8 *func_0037E0B8(void *);
extern void func_00388830(void *,void *,f32);
extern void func_L01_00443840(void *,void *);
extern void func_L01_00342DB8(void *,s32);
extern void func_0037E2F0(void *,f32,f32);
extern f32 func_L39_005B2510(f32,f32);
extern void func_00389158(void *,void *,void *,f32);
extern void func_L39_00563240(void *);
extern void func_L01_00402498(void *,void *);
typedef struct {u8 pad0[0xD0]; u8 active; u8 padD1[11]; u8 *owner;} Entry133;
typedef struct {u8 pad0[0xA0]; vu0_v4 position; u8 padB0[0x2524-0xB0]; u8 *model;} Entity133;
typedef struct {f32 last; s16 timer; u8 pad6[2]; s32 colour,id; f32 delay; s32 other; s16 timers[4]; s32 slots[4]; u8 pad30[16]; Entity133 *entity;} StateLast133;
typedef struct {s32 zero; void *owner; u8 pad8[8]; vu0_v4 offset;} ParticleVars133;
typedef struct {u8 a,b,c,d; s32 colour,pad8; f32 radius; vu0_v4 position; ParticleVars133 vars;} Particle133;
typedef struct {vu0_v4 dir; void *owner; s32 flags; u8 a,b; u16 kind; s32 zero,one;} Hit133;
void func_L39_00562AB0(u8 *obj) {
    vu0_v4 scaled, anchor, position;
    Hit133 hit;
    vu0_v4 temp, endpoint;
    StateLast133 *s=*(StateLast133 **)(obj+0x68);
    u8 *p,*health;
    s32 i,j,id,count;
    f32 value,x,y,sign;
    if (D_L39_002412A8.value) return;
    *(vu0_q *)(obj+0x10)=*(vu0_q *)(&s->entity->position);
    func_L01_004C5800();
    if (!D_L39_002412A8.value) {
        if (!func_L39_005F08A0(obj,s->id)) s->id=func_L39_005F0CE0(3,4,obj);
    } else if (func_L39_005F08A0(obj,s->id)) {
        id=s->id;
        if(id!=-1 && ((Entry133 *)(D_L39_001FE1A0+id*0x80))->owner==obj && ((Entry133 *)(D_L39_001FE1A0+id*0x80))->active) func_L39_005F0988(id);
        s->id=-1;
    }
    value=func_L01_004C5828();
    if (!func_L39_00564490(obj,value) || D_001DFD94_sda==40) {
        id=s->id;
        if(id!=-1 && ((Entry133 *)(D_L39_001FE1A0+id*0x80))->owner==obj && ((Entry133 *)(D_L39_001FE1A0+id*0x80))->active) func_L39_005F0988(id);
        s->id=-1;
        D_001DFD94_sda=0;
        func_L01_003116F0();
        func_L39_005F0CE0(2,0,obj);
        func_003BD360(obj);
        return;
    }
    if(value!=s->last) {s->last=value;s->timer=D_001DFDC8_sda;}
    x=(f32)s->timer/(f32)D_001DFDC8_sda;
    if(*(s16 *)(obj+0xAA)==0x1B37) id=func_003894A0(D_001DFD68_sda,D_001DFD6C_sda,x);
    else id=func_003894A0(D_001DFD70_sda,D_001DFD74_sda,x);
    s->colour=id;
    func_003883C8(&s->timer);
    func_003886E8(&scaled,s->entity->model+0xE0,0.75f);
    add_ba133(obj+0x10,&s->entity->position,&scaled);
    func_003BDA38(s->entity->model,10,&anchor);
    for(i=0;i<8;i++) {
        if(!D_L39_0024D790[i]) {
            id=func_L39_005B24C8(D_001DFDB0_sda,D_001DFDB4_sda);
            x=func_L39_005B25C8(); y=func_L39_005B25C8();
            func_0037E4B8(&position,D_001DFD98_sda,x,y);
            add_ab133(&position,&position,&anchor);
            p=func_L01_00469378(&position,id,2,1);
            D_L39_0024D790[i]=p;
            if(p) {
                Particle133 *particle=(Particle133 *)p;
                ParticleVars133 *vars=&particle->vars;
                vars->offset.x=particle->position.x-*(f32 *)(obj+0x10);
                vars->offset.y=particle->position.y-*(f32 *)(obj+0x14);
                vars->offset.z=particle->position.z-*(f32 *)(obj+0x18);
                vars->owner=obj;
                particle->radius=D_001DFDB8_sda*210000.0f;
                particle->colour=D_001DFDBC_sda|s->colour;
                p[2]=(*(u8 **)(D_L39_00296918+0xF8))[1];
                D_L39_0024D7B0[i]=id;
            }
            p=func_L01_00469378(&position,id,2,1);
            if(p) {
                Particle133 *particle=(Particle133 *)p;
                ParticleVars133 *vars=&particle->vars;
                vars->offset.x=particle->position.x-*(f32 *)(obj+0x10);
                vars->offset.y=particle->position.y-*(f32 *)(obj+0x14);
                vars->offset.z=particle->position.z-*(f32 *)(obj+0x18);
                vars->owner=obj;
                particle->colour=0x307F7F7F;
                particle->radius=D_001DFDB8_sda*210000.0f*0.3f;
                p[2]=(*(u8 **)(D_L39_00296918+0xF8))[1];
            }
        } else if(func_00388398(&D_L39_0024D7B0[i])) D_L39_0024D790[i]=0;
    }
    func_00388398(&s->other);
    for(i=0;i<4;i++) if(func_003883C8(&s->timers[i])) s->slots[i]=0;
    if(func_L01_0040BB20(&s->delay)) {
        count=func_003CF790(obj+0x10,1,s->entity->model,0,D_001DFD84_sda*0.3f);
        if(count) {
            hit.dir.w=5627.925f;
            hit.owner=obj;hit.flags=0x10000;hit.a=3;hit.b=2;hit.kind=*(u16 *)(obj+0xAA);hit.zero=0;hit.one=1;
            if(count>0) for(i=0;i<count;i++) {
                p=D_L39_002638C0[i];
                if(!p[0x31] || !p || p[0x20]==0xFE || p[0x20]==0xFD || !*(u8 **)(p+0x24) || (*(u8 **)(p+0x24))[0x46]!=5) continue;
                health=func_0037E0B8(p);
                if(health) {
                    if(*(f32 *)health<=0.0f) continue;
                    func_003886E8(&temp,obj+0xE0,*(f32 *)(health+0x10));
                    add_ab133(&position,p+0x10,&temp);
                } else *(vu0_q *)&position=*(vu0_q *)(p+0x10);
                sub_ab133(&hit.dir,&position,obj+0x10);
                func_00388830(&hit.dir,&hit.dir,1.0f);
                func_L01_00443840(p,&hit);
                func_003886E8(&temp,&hit.dir,D_001DFD84_sda*0.3f);
                add_ba133(&endpoint,obj+0x10,&temp);
                func_L01_00342DB8(&endpoint,s->colour);
                s->delay=0.5f;
            }
        }
    }
    *(vu0_q *)&position=*(vu0_q *)&anchor;
    for(i=0;i<5;i++) {
        if(func_003883C8(&D_L39_0024D7D0[i])) D_L39_0024D7D0[i]=0;
        if(!D_L39_0024D7D0[i]) {
            id=func_L39_005B24C8(3,45);
            D_L39_0024D7F0[i]=id;
            D_L39_0024D7E0[i]=64;
            D_L39_0024D7D0[i]=id;
            func_0037E2F0(&hit.dir,D_001DFDC0_sda,D_001DFDC0_sda);
            *(vu0_q *)&D_L39_003CD580[i][0]=*(vu0_q *)&position;
            D_L39_003CD580[i][0].w=0.04f;
            sign=1.0f;
            for(j=0;j<9;j++) {
                sub_global133(&temp,&D_L39_003CD580[i][j],&D_L39_0024DF00);
                x=func_L39_005B2510(0.08726646f,1.3089969158172607f);
                func_00389158(&hit.dir,&hit.dir,&temp,x*sign);
                sign=-sign;
                add_ab133(&D_L39_003CD580[i][j+1],&D_L39_003CD580[i][j],&hit.dir);
                D_L39_003CD580[i][j+1].w=0.04f;
            }
        }
    }
    func_L01_00402498(func_L39_00563240,obj);
}
/* localdecomp:end func_L39_00562AB0 */
