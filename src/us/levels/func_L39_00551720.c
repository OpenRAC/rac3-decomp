#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00551720 */
typedef int Q87d __attribute__((mode(TI)));
typedef struct { float pos[4],last[4],now[4]; char pad[32]; short active,timer; float phase1,phase2; int pad2; } S87d;
extern S87d D_L39_003C1120[];
extern int func_003883C8(short *);
extern float func_003887C8(void *,void *);
extern void func_00388830(void *,void *,float);
extern void func_L01_0040C188(void *,void *,float);
int func_L39_00551720(u8 *m) {
    float v[4];
    u8 *t=*(u8 **)(m+0x68);
    S87d *s=&D_L39_003C1120[t[0x3A]];
    float d,old;
    if(!s->active)return 0;
    if(func_003883C8(&s->timer)) {s->active=0;return 0;}
    *(Q87d *)s->now=*(Q87d *)(m+0x10);
    d=func_003887C8(s,s->now);
    old=func_003887C8(s,s->last);
    if(d<old) {
        *(Q87d *)s->last=*(Q87d *)(m+0x10);
        old=0;
    } else old=d-old;
    s->phase1+=0.05f;
    if(s->phase1>=4)s->phase1-=4;
    s->phase2+=0.075f;
    if(s->phase2>=4)s->phase2-=4;
    func_00388830(v,t,0.26666668f);
    func_L01_0040C188(v,v,d);
    vec_add_ba(s,s,v);
    func_L01_0040C188(v,v,old);
    vec_add_ab(s->last,s->last,v);
    return 1;
}
/* localdecomp:end func_L39_00551720 */
