#include "common.h"
/* localdecomp:start func_L01_003EA9F0 */
typedef unsigned int Q_A9F0 __attribute__((mode(TI)));
typedef struct M_A9F0 { Q_A9F0 q[4]; u8 pad[0x30]; u8 *p70; u8 pad74[0x20]; int index; } M_A9F0;
typedef struct { u8 pad[0x100]; int state; u8 pad104[0x34]; int id; } Sub_A9F0;
typedef struct { u8 pad[0x54]; M_A9F0 *m; u8 pad58[0xF8]; Sub_A9F0 sub; u8 pad28c[0x98]; int state324; u8 pad328[0x138]; } S_A9F0;
extern S_A9F0 D_L01_001E2AC0[];
extern void func_L01_003EA090(M_A9F0 *);
extern void func_L01_003EA998_003EA9F0(M_A9F0 *);
extern void func_L01_003F3EA0(int, void *, float);
void func_L01_003EA9F0(M_A9F0 *m) {
 S_A9F0 *p = &D_L01_001E2AC0[m->index];
 u8 *d=m->p70+0xB8;
 Sub_A9F0 *sub=&p->sub;
 int state=sub->state;
 if(state==43 || (unsigned)(state-35)<3) {
  if(*(int *)(d+8)!=sub->id) {
   p->m->q[3]=m->q[3];
   p->m->q[0]=m->q[0];
   p->m->q[1]=m->q[1];
   p->m->q[2]=m->q[2];
   func_L01_003EA090(m);
   D_L01_001E2AC0[m->index].state324=45;
  }
 }
 func_L01_003EA998_003EA9F0(m);
 func_L01_003F3EA0(m->index,&m->q[3],0.5f);
 *(int *)(m->p70+0x80)=0;
}
/* localdecomp:end func_L01_003EA9F0 */
