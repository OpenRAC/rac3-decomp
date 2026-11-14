/* NTSC-U draft (2026-11-14, Codex worker): C of func_L02_00307298, the NTSC-U twin of func_L02_00307520, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L02_00307520.c's current line.
 * Worker's note: 309 diff; best func_L02_00307298.check02.log; switch states 0/1/2/3 verified from branches; default assembler .lit4 loads versus inline retail for angle/acceleration constants; real VU0 blocks have scheduling differences; no unlisted flags tried
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L02_00307298 */
typedef struct { float x,y,z,w; } V_307298;
typedef struct {
    char pad0[0x58]; unsigned char a58,a59,a5a; char p5b[0x15];
    int path,instant,index,timer; float rate,base_z,speed; int wait;
    float start_z; int pad94; void *area; int short_wait,long_wait;
} Data_307298;
typedef struct {
    char p0[0x10]; V_307298 pos; unsigned char state; char p21[0xf];
    unsigned char opacity,p31; unsigned short p32,flags; char p36[0xd];
    unsigned char anim; char p44[0x1c]; unsigned char bits; char p61[7]; Data_307298 *data;
    char p6c[0x54]; V_307298 matrix[3]; V_307298 rotation;
} Moby_307298;
typedef struct { int count; char pad4[0xc]; V_307298 points[1]; } Path_307298;
typedef struct {
    char p0[0x80]; V_307298 pos,orientation; char pa0[0x50];
    V_307298 velocity,extra,step,projected,flat; char p140[0xb0]; short locked;
    char p1f2[0x15e]; float ground; char p354[0xc]; int active;
    char p364[0x2260]; int state,p25c8,previous;
    char p25d0[0x15]; unsigned char lock;
} Hero_307298;
extern Hero_307298 D_001A4BE0;
extern Path_307298 *D_L02_0021C780[];
extern float D_001DC534_sda;
extern char D_L02_001E11C0[];
extern unsigned char D_001439F4[];
extern int D_001D545C[];
extern void func_003BD360(void *),func_003BE4F0(void *,int,int,int);
extern int func_0037E1D8(int),func_00388398(int *);
extern float func_00388A28(float,float),func_003887C8(void *,void *),func_00389380(float,float);
extern void func_L01_00445758(void *,float,void *,float,float,float,int);
extern void func_00388830(void *,void *,float),func_00388BD0(void *,void *),func_0039FE80(int,int,void *);
extern int func_0037E0F0(void *,void *,int),func_L01_004432C0(void *,void *,int),func_L01_00452EC8(void *);
extern void func_L02_00307918(void *,void *),func_L01_004F12C0(void *,void *,int,int);
extern void func_L01_003E9588(int,void *,void *,int,int,int),func_L01_004EA040(void);
static __inline__ void add_307298(V_307298 *d,V_307298 *a,V_307298 *b) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void sub_307298(V_307298 *d,V_307298 *a,V_307298 *b) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
void func_L02_00307298(Moby_307298 *m) {
    V_307298 v0,v1,v2;
    Data_307298 *p=m->data;
    switch (m->state) {
    case 0:
        if (p->instant) {
            p->a58=15;
            p->a5a=12;
            m->state=2;
            m->opacity=255;
            m->flags|=1;
            p->wait=30;
            p->base_z=m->pos.z;
        } else {
            if (p->path==-1) { func_003BD360(m); break; }
            p->index=func_0037E1D8(D_L02_0021C780[p->path]->count);
            p->timer=600;
            if (m->anim!=1) func_003BE4F0(m,1,0,10);
            m->pos.z=D_L02_0021C780[p->path]->points[0].z-D_001DC534_sda;
            p->start_z=m->pos.z;
            m->state=1;
        }
        break;
    case 1:
        *(vu0_q *)&v0=*(vu0_q *)&D_L02_0021C780[p->path]->points[p->index];
        func_L01_00445758(&m->rotation.z,func_00388A28(v0.x-m->pos.x,v0.y-m->pos.y),&p->rate,0.0008726646774448454f,0.0008726646774448454f,0.05235988274216652f,0);
        func_00388830(&v1,&m->matrix[0],0.05000000447034836f);
        add_307298(&m->pos,&m->pos,&v1);
        if (func_003887C8(&m->pos,&v0)<3.0f || func_00388398(&p->timer)) {
            int k=func_0037E1D8(D_L02_0021C780[p->path]->count);
            p->timer=600;
            p->index=(p->index+k)%D_L02_0021C780[p->path]->count;
        }
        break;
    case 2:
        func_00388398(&p->wait);
        if (fabs_asm(D_001A4BE0.ground-p->base_z)<0.8f && D_001A4BE0.previous==18 && !func_0037E0F0(&D_001A4BE0.pos,p->area,0)) {
            if (p->wait) break;
            m->rotation.y=-1.5533430576324463f;
            m->rotation.z=func_00389380(*(float *)(D_L02_001E11C0+0x158),1.5707963705062866f);
            func_00388BD0(&m->matrix[0],&m->rotation);
            *(vu0_q *)&m->pos=*(vu0_q *)&D_001A4BE0.pos;
            func_00388830(&v0,&m->matrix[2],D_001DC534_sda);
            sub_307298(&m->pos,&m->pos,&v0);
            p->speed=0.13333334f;
            m->flags&=0xfffe;
            func_0039FE80(1,0,m);
            if (m->anim!=2) func_003BE4F0(m,2,10,5);
            m->state=3;
            *(vu0_q *)&v1=*(vu0_q *)&D_001A4BE0.pos;
            v1.z=D_001A4BE0.ground;
            func_L02_00307918(m,&v1);
            func_L01_004F12C0(&D_001A4BE0.pos,&D_001A4BE0.orientation,49,0);
            D_001A4BE0.lock=1;
            if (!D_001439F4[0]) func_L01_003E9588(0,D_L02_001E11C0+0x140,D_L02_001E11C0+0x150,0,0,0);
        } else if (D_001A4BE0.state!=18 && D_001A4BE0.active) {
            if (p->path!=-1 && func_L01_004432C0(&D_001A4BE0.pos,&D_L02_0021C780[p->path]->points[0],D_L02_0021C780[p->path]->count)) p->wait=p->long_wait;
            else p->wait=p->short_wait;
        }
        break;
    case 3:
        if (func_L01_00452EC8(m)) func_0039FE80(1,0,m);
        qzero(&D_001A4BE0.velocity);
        qzero(&D_001A4BE0.step);
        qzero(&D_001A4BE0.projected);
        qzero(&D_001A4BE0.flat);
        D_001A4BE0.lock=1;
        D_001A4BE0.locked=3;
        m->pos.z+=p->speed;
        if (D_001D545C[0]!=9) p->speed-=0.0027777778450399637f;
        else p->speed-=0.0055555556900799274f;
        if (p->speed<0.033333335f) {
            func_00388830(&v0,&m->matrix[2],D_001DC534_sda);
            func_L01_00445758(&m->rotation.y,1.5533430576324463f,&p->rate,0.0034906587097793818f,0.0034906587097793818f,0.41887906193733215f,0);
            func_00388BD0(&m->matrix[0],&m->rotation);
            func_00388830(&v1,&m->matrix[2],D_001DC534_sda);
            sub_307298(&v2,&v1,&v0);
            sub_307298(&m->pos,&m->pos,&v2);
        }
        if (p->speed<0 && m->pos.z<D_001A4BE0.ground) {
            *(vu0_q *)&v0=*(vu0_q *)&D_001A4BE0.pos;
            v0.z=D_001A4BE0.ground;
            func_L02_00307918(m,&v0);
        }
        if (p->speed<0 && m->pos.z<p->base_z) func_L01_004EA040();
        if ((m->bits&2) && m->anim!=1) func_003BE4F0(m,1,0,10);
        break;
    }
}
/* localdecomp:end func_L02_00307298 */
