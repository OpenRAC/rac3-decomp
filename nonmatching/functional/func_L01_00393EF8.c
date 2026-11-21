/* functional: medium. retail returns the particle pointer (0 if pool full or cap hit); draft was void so return added; f20 0.0008f exact 0x3A51B717; 1 differing float const fixed. Scheduling diffs remain. */
#include "common.h"
/* localdecomp:start func_L01_00393EF8 */
#include "vu0.h"
typedef struct { vu0_q pos; vu0_v4 velocity; f32 f20; f32 f24; f32 f28; f32 f2C; f32 f30; f32 f34; f32 f38; f32 f3C; f32 f40; f32 f44; f32 f48; f32 f4C; s32 w50; s32 w54; s32 w58; s32 w5C; s32 w60; s32 w64; s32 w68; s32 w6C; s32 w70; s32 w74; s32 w78; u8 *owner; } Particle_00393EF8;
extern S_393258 *D_L01_001E201C;
void *func_L01_00393EF8(void *owner, s32 mode, f32 angle, f32 unused, s32 position) {
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    vu0_q temp, extra;
    u8 *o=owner;
    u8 *pool=(u8 *)D_L01_001E201C;
    Particle_00393EF8 *p;
    s32 i, initial;
    f32 f;
    for(i=0;i<300;i++) {
        if(*(void **)(pool+i*128+0x7C)) continue;
        switch(mode) {
        case 0:
            if(++*(s32 *)(o+0x40)==140) { --*(s32 *)(o+0x40); return 0; }
            break;
        case 1:
            if(++*(s32 *)(o+0x44)==140) { --*(s32 *)(o+0x44); return 0; }
            break;
        }
        p=(Particle_00393EF8 *)D_L01_001E201C+i;
        p->owner=o;
        ++*(s32 *)(o+0x38);
        initial=func_00382498(95,127);
        p->w78=mode;
        p->w5C=p->w60=initial;
        if(mode==0) {
            s32 r;
            func_0038D890(&p->velocity,o+0x10,o,func_00382538());
            f=*(f32 *)(o+0x3C)*func_003824E0(0.0f,1.25f);
            p->f40=0.0f;
            p->f3C=p->f38=f;
            r=func_00382498(0,13);
            p->w6C=(r<<16)+(r<<8)+r;
            p->f48=p->f44=func_003824E0(0.25f,0.35f);
            p->f4C=func_003824E0(0.75f,1.0f);
            p->f24=0.0f;
            p->w58=p->w54=func_00382498(83,100);
            p->pos=*(vu0_q *)(p->owner+0x20);
            func_0038CF68(&temp,&p->velocity,func_003824E0(0.15f,0.75f));
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(p->pos) : "m"(temp) : "vf1", "vf2");
            p->w70=2;
            p->f30=0.0f;
        } else if(mode==1) {
            s32 r;
            func_0038D890(&p->velocity,o+0x10,o,func_00382538());
            p->f38=0.0f;
            p->f3C=0.0f;
            p->f40=0.0f;
            r=func_00382498(0,13);
            p->w6C=(r<<16)+(r<<8)+r;
            p->f48=p->f44=func_003824E0(0.25f,0.5f);
            p->f4C=func_003824E0(1.0f,1.5f);
            p->f24=func_003824E0(0.08000000566244125f,0.10000000894069672f);
            p->w58=p->w54=func_00382498(83,100);
            p->pos=*(vu0_q *)position;
            p->w70=2;
            p->f30=0.0f;
        } else if(mode==2) {
            s32 r;
            func_0038D890(&p->velocity,o+0x10,o,angle);
            p->f40=0.0f;
            p->f38=0.0f;
            p->f3C=0.0f;
            r=func_00382498(1,10);
            p->w6C=(r<<16)+(r<<8)+r;
            p->f48=p->f44=func_003824E0(0.15f,0.25f)*0.5f;
            p->f4C=func_003824E0(0.5f,0.8f)*1.15f;
            p->f24=0.07000000774860382f;
            p->w58=p->w54=75;
            func_0038CF68(&temp,p->owner,0.2f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(p->pos) : "m"(temp), "m"(*(vu0_q *)(p->owner+0x20)) : "vf1", "vf2");
            func_0038CF68(&extra,&p->velocity,0.75f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(p->pos) : "m"(extra) : "vf1", "vf2");
            p->f30=func_L01_00443A18(0.06283185631036758f,0.12566371262073517f);
            p->w70=mode;
        }
        p->f20=0.00079999998f;
        p->w68=p->w64=0x103080;
        p->f2C=p->f28=func_L01_00443A18(0.3769911527633667f,0.42760568857192993f);
        p->f34=func_00382538();
        p->w74=0;
        return p;
    }
}
/* localdecomp:end func_L01_00393EF8 */
