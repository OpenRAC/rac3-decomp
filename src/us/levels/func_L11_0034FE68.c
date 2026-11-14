#include "common.h"

/* localdecomp:start func_L11_0034FE68 */
typedef int Q_34FE68 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } V_34FE68;
typedef struct { char pad[0x100]; V_34FE68 target; int p110,active,index,other,trigger; } P_34FE68;
typedef struct { char p0[0x10]; V_34FE68 pos; unsigned char state; char p21[0x47]; P_34FE68 *p; char p6c[0x8c]; float angle; } M_34FE68;
typedef struct { char pad[0x30]; V_34FE68 pos; char rest[0x40]; } R128_34FE68;
typedef struct { char pad[0x10]; V_34FE68 pos; char rest[0xe0]; } R256_34FE68;
extern R128_34FE68 *D_001DEF00_sda;
extern R256_34FE68 *D_001DEE1C_sda;
extern char *D_001D52FC;
extern char D_L11_00350058[],D_L11_00350460[];
extern float func_00388960(float),func_00388978(float),func_00388A28(float,float);
extern void func_L01_00441FB8(void *,int,int);
extern void func_L01_00402498(void *,void *);
extern int func_L01_00452F60(void *),func_L01_0045D358(int,int,int,int);
extern void func_L01_00452F40(void *,int);
void func_L11_0034FE68(M_34FE68 *m) {
    P_34FE68 *p=m->p;
    if (m->state==0) {
        if (p->index==-1) {
            if (p->other==-1) {
                p->target.x=func_00388960(m->angle)*100.0f;
                p->target.y=func_00388978(m->angle)*100.0f;
                p->target.z=0;
                __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                    : "=m"(p->target) : "m"(p->target),"m"(m->pos) : "vf1","vf2");
            } else {
                m->angle=func_00388A28(D_001DEE1C_sda[p->other].pos.x-m->pos.x,D_001DEE1C_sda[p->other].pos.y-m->pos.y);
                *(Q_34FE68 *)&p->target=*(Q_34FE68 *)&D_001DEE1C_sda[p->other].pos;
            }
        } else {
            m->angle=func_00388A28(D_001DEF00_sda[p->index].pos.x-m->pos.x,D_001DEF00_sda[p->index].pos.y-m->pos.y);
            *(Q_34FE68 *)&p->target=*(Q_34FE68 *)&D_001DEF00_sda[p->index].pos;
        }
        func_L01_00441FB8(m,1,-1);
    } else if (p->active) {
        func_L01_00402498(D_L11_00350058,m);
        if (*(int *)(D_001D52FC+0x1b0)&0x20) func_L01_00402498(D_L11_00350460,m);
    } else if (func_L01_00452F60(m) || (func_L01_0045D358(1,60,0,0) && func_L01_0045D358(2,60,0,0))) {
        p->active=1;
        if (p->trigger!=-1) func_L01_00452F40(&D_001DEE1C_sda[p->trigger],1);
    }
}
/* localdecomp:end func_L11_0034FE68 */
