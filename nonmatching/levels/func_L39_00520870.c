/* NTSC-U draft (Codex wave 3): C of func_L39_00520408, the NTSC-U twin of func_L39_00520870, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 39 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00520408", whose code is not the PAL one).
 * Worker's note: 39 diff; best func_L39_00520408.check10.log; loop GPR allocation, VU add destination and collision-store/call scheduling; 10 checks; no forbidden flags
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_00520408 */
typedef vu0_v4 V_520408;
typedef struct { char p0[0x10]; V_520408 pos; char p20[4]; char *classdata; float p28,scale; char p30[0x38]; char *data; char p6c[0x3e]; unsigned short cls; char pac[0x10]; unsigned char state; char pbd[0x33]; V_520408 rot; } M_520408;
typedef struct {
    V_520408 vel;
    void *owner;
    int flags;
    unsigned char a,b;
    unsigned short cls;
    float damage;
    int enabled,unused,extra;
} Hit_520408;
typedef union { V_520408 v[6]; Hit_520408 hit; } Scratch_520408;
extern float func_00388A28(float,float),func_003887A0(void *),func_00388770(void *);
extern float func_L18_00454598(float,float,float *,float,float,float);
extern void func_0037E4B8(void *,float,float,float);
extern float func_L39_005B2510(float,float);
extern int func_L39_005B24C8(int,int);
extern void func_00388830(void *,void *,float),func_00388880(void *,void *,float);
extern void *func_L39_005C3D70(void *,void *,int,int,int,int,int,int);
extern float func_00389380(float,float),func_00388978(float),func_00388960(float),func_00388800(void *,void *);
extern void func_00388BF0(void *,void *),func_003888F0(void *,void *,void *);
extern int func_003CE740(void *,void *,int,void *,void *);
extern void func_L01_0040C260(void *,void *,void *);
extern void func_L39_005B69C0(void *,void *,int,int,int,int,int,int,float,float,float,float,float,float,float,int,int,int,int);
extern int func_00388398(int *),func_0019D650(void);
extern void func_003BD360(void *);
typedef struct { char p0[0x18]; char *obj; int count; V_520408 point,unused,normal; } Collision_520408;
extern Collision_520408 D_L39_0025F840;

void func_L39_00520408(M_520408 *m) {
    V_520408 old, impulse, point, dir, delta;
    Scratch_520408 s;
    char *p;
    float angle, f, radius;
    int life;
    unsigned char hit;
    if (!m) return;
    p=m->data;
    if (!p) return;
    *(vu0_q *)&impulse=0;
    impulse.z=0.13333334f;
    m->scale+=(*(float *)(m->classdata+0x24)-m->scale)*0.05f;
    *(float *)(p+0x38)+=(1.0f-*(float *)(p+0x38))*0.1f;
    vec_sub_ab(&delta,p+0x10,&m->pos);
    if (*(int *)(p+0x34)<245) {
        angle=func_00388A28(delta.x,delta.y);
        m->rot.z=func_L18_00454598(m->rot.z,angle,(float *)(p+0x3c),0.02617993950843811f,0,0);
        angle=func_00388A28(func_003887A0(&delta),delta.z);
        m->rot.y=func_L18_00454598(m->rot.y,-angle,(float *)(p+0x40),0.02617993950843811f,0,0);
        vec_sub_ab(&delta,p+0x10,p+0x20);
        angle=func_00388770(&delta);
        if (angle<6.0f) *(float *)(p+0x44)*=angle/6.0f;
        else *(float *)(p+0x44)+=0.1f;
    }
    func_0037E4B8(&dir,*(float *)(p+0x38),m->rot.z,-m->rot.y);
    *(vu0_q *)&s.v[1]=0;
    s.v[1].x=func_L39_005B2510(-1,1);
    s.v[1].y=func_L39_005B2510(-1,1);
    s.v[1].z=func_L39_005B2510(-1,1);
    s.v[0]=s.v[1];
    func_00388830(&s.v[0],&s.v[0],func_L39_005B2510(0.1f,0.2f)*0.0166666675f);
    func_00388830(&point,&dir,-func_L39_005B2510(0.0016666668234393f,0.0166666675f));
    vec_add_ba(&s.v[0],&s.v[0],&point);
    func_00388830(&point,&dir,func_L39_005B2510(0,1)* *(float *)(p+0x38));
    vec_add_ab(&point,&point,&m->pos);
    life=func_L39_005B24C8(28,40);
    func_L39_005C3D70(&point,&s.v[0],0x6f00afff,0x100000ff,life,40,func_L39_005B24C8(40,70),1);
    *(vu0_q *)&old=*(vu0_q *)&m->pos;
    vec_add_ba(p+0x20,p+0x20,&dir);
    *(float *)(p+0x48)=func_00389380(*(float *)(p+0x48),*(float *)(p+0x50));
    *(float *)(p+0x4c)=func_00389380(*(float *)(p+0x4c),*(float *)(p+0x54));
    *(float *)(p+0x48)=func_00389380(*(float *)(p+0x48),func_00388978(*(float *)(p+0x4c))*0.075f);
    if (*(float *)(p+0x44)>0.7f) *(float *)(p+0x44)=0.7f;
    hit=0;
    goto move_first;
move_test:
    if (!(radius>0.1f)) goto move_done;
move_first:
        f=func_00388978(*(float *)(p+0x48));
        s.v[0].y=*(float *)(p+0x44)*f*func_00388960(*(float *)(p+0x4c));
        f=func_00388960(*(float *)(p+0x48));
        s.v[0].z=*(float *)(p+0x44)*f*func_00388960(*(float *)(p+0x4c));
        s.v[0].x=s.v[0].w=0.0f;
        func_00388BF0(&s.v[2],&m->rot);
        func_003888F0(&s.v[0],&s.v[0],&s.v[2]);
        vec_add_ba(&m->pos,&s.v[0],p+0x20);
        if (!func_003CE740(&old,&m->pos,6,*(void **)(p+0x30),0)) goto move_done;
        hit=1;
        radius=*(float *)(p+0x44)*0.7f;
        *(float *)(p+0x44)=radius;
    goto move_test;
move_done:
    if (hit) {
        m->rot.z=func_00388A28(m->pos.x-old.x,m->pos.y-old.y);
        m->rot.y=-func_00388A28(func_00388800(&old,&m->pos),m->pos.z-old.z);
        *(float *)(p+0x3c)=0;
        *(float *)(p+0x40)=0;
    }
    if (m->pos.x<0 || m->pos.y<0 || m->pos.z<0) goto destroy;
    s.hit.owner=*(void **)(p+0x30);
    s.hit.flags=0x01030001;
    s.hit.damage=*(float *)(p+0x5c);
    s.hit.enabled=1;
    s.hit.vel=dir;
    func_00388880(&s.hit.vel,&s.hit.vel,1);
    s.hit.vel.w=5627.925f;
    s.hit.b=3;
    s.hit.cls=m->cls;
    s.hit.vel.z=1;
    s.hit.a=3;
    s.hit.extra=*(int *)(p+0x60);
    if (func_003CE740(&old,&m->pos,0,*(void **)(p+0x30),&s.hit)) {
        if (D_L39_0025F840.obj) {
            if (D_L39_0025F840.obj==*(char **)(p+0x30) || *(short *)(D_L39_0025F840.obj+0xaa)==4242) goto alive;
            m->state=2;
            m->pos=D_L39_0025F840.point;
            func_L01_0040C260(&impulse,&dir,&D_L39_0025F840.normal);
            func_00388830(&impulse,&impulse,0.033333335f);
            func_L39_005B69C0(m,&impulse,0,10,3,9,0,1,0,0,4,2,9,1,15,1,-1,0,0x01010001);
            goto destroy;
        } else if (D_L39_0025F840.count>0) {
            m->state=1;
            m->pos=D_L39_0025F840.point;
            func_L01_0040C260(&impulse,&dir,&D_L39_0025F840.normal);
            func_00388830(&impulse,&impulse,0.033333335f);
            func_L39_005B69C0(m,&impulse,0,10,3,9,0,1,0,*(float *)(p+0x5c),4,2,9,1,15,1,-1,0,0x01010001);
            goto destroy;
        }
    } else if (func_00388398((int *)(p+0x34))) {
destroy:
        func_003BD360(m);
        return;
    }
alive:
    if ((*(int *)(p+0x34)&31)==0) {
        if (func_0019D650()&1) *(float *)(p+0x50)*=func_L39_005B2510(-0.7f,-1.5f);
        if (func_0019D650()&1) *(float *)(p+0x54)*=func_L39_005B2510(-0.6f,-1.6f);
    }
}
/* localdecomp:end func_L39_00520408 */
