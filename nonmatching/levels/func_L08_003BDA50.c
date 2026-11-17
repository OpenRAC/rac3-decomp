/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_003BB948, the NTSC-U twin of func_L08_003BDA50, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" when tried; not with src/levels/08_aquatos/L08_003BD8A0.c's current line.
 * Worker's note: 63 diff with injected row; best func_L08_003BB948.check03.log; NEEDS divs row 'func_L08_003BB948 2'; 77 diff without row (check02); 3 wordings identical (check03/check05/check07); VU load/store interleaving remains; j-form forbidden-register compile error check04 under allowed flags
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_003BB948 */
typedef vu0_v4 V_3BB948;
typedef struct { char p0[0x10]; V_3BB948 pos; char p20[4]; char *classdata; float p28,scale; } M_3BB948;
extern int func_0037E1D8(int);
extern void func_003BF6A8(void *,float);
extern float func_0037E250(float,float);
extern void *func_L01_00460318(void *,void *,int,int,int,int,int,int);

void func_L08_003BB948(M_3BB948 *m,float spread,float height) {
    V_3BB948 point,velocity,center;
    float scale;
    int i=0,random;
    scale=m->scale/ *(float *)(m->classdata+0x24);
    qzero(&center);
    center.z+=scale*height;
    __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
        : "=m"(center) : "m"(m->pos), "m"(center) : "vf1", "vf2");
    do {
        random=func_0037E1D8(50);
        qzero(&point);
        func_003BF6A8(&point,scale*spread);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
            : "=m"(point) : "m"(center), "m"(point) : "vf1", "vf2");
        qzero(&velocity);
        func_003BF6A8(&velocity,0.0033333336468786f);
        velocity.z+=func_0037E250(0,0.0083333337679505f);
        func_L01_00460318(&point,&velocity,0x70507080,0,func_0037E1D8(150)+150,(int)(scale*(random+100)),(int)(scale*(random+220)),i<21);
        i++;
    } while (i<35);
}
/* localdecomp:end func_L08_003BB948 */
