/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0061FCB0, the NTSC-U twin of func_L39_00622450, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L39_00621600.c's current line.
 * Worker's note: 307 diff; 3 checks; complete animation/frame interpolation and event logic reconstructed; permitted default assembler emits lit4 pool loads versus retail inline floats; no unlisted flags; retail div.s has 1 preceding nop, other differences remain; best log func_L39_0061FCB0.check03.log
 */
#include "common.h"

/* localdecomp:start func_L39_0061FCB0 */
typedef struct {
    u8 pad[0x10];
    u8 count, b11, events, b13;
    u8 pad14[8];
    float *frames[1];
} Clip_0061FCB0;
typedef struct { u8 pad[0x48]; Clip_0061FCB0 *clips[1]; } Class_0061FCB0;
typedef struct {
    u8 pad[0x24]; Class_0061FCB0 *cl;
    u8 pad28[0x40-0x28];
    u8 oldFrame, nextFrame, animation, target;
    float time;
    u8 pad48[0x58-0x48];
    float *current, *next;
    u8 pad60[0x6c-0x60];
    u8 desiredEvent, activeEvent, eventCount;
    u8 pad6f[0xaa-0x6f];
    s16 classId;
} Moby_0061FCB0;
typedef struct {
    u8 pad[0x610];
    float scale, rate;
    s32 flags;
    s32 changed, curve, curveFrame;
    float previousTime, deltaTime;
    s32 queuedStart, queuedEnd, restart;
    u8 pad63c[0x2524-0x63c];
    Moby_0061FCB0 *moby;
} Self_0061FCB0;
extern float D_L39_0047A7D8[][25];
extern float D_L39_002461B4[];
extern u8 D_L39_001FE1A0[];
extern void func_L39_00628F40(Self_0061FCB0 *);
extern s32 func_L39_005F0CE0(s32,s32,void *);
extern void func_L39_005F0988(s32);
extern float func_L01_00436500(void *);
void func_L39_0061FCB0(Self_0061FCB0 *p) {
    Moby_0061FCB0 *m;
    float old, delta, now, previous;
    s32 same, oldFrame, start, end, i, event;
    Clip_0061FCB0 *clip;
    s32 *events;
    m=p->moby;
    p->flags &= ~3;
    same=m->animation==m->target;
    oldFrame=m->oldFrame;
    old=m->time;
    if(m->animation==m->target) m->time += p->scale*p->rate;
    else if(p->curve>=0) {
        m->time=D_L39_0047A7D8[p->curve][p->curveFrame++];
    } else m->time += p->rate;
    if(m->time>0.99f && m->time<1.01f) m->time=1.0f;
    if(m->time>-0.01f && m->time<0.01f) m->time=0.0f;
    delta=m->time-old;
    now=m->time;
    if(m->time>=1.0f) {
      float base=D_L39_002461B4[0], zero=0.0f, one=1.0f;
      do {
        if(m->animation!=m->target) {
            m->animation=m->target;
            m->eventCount=m->cl->clips[m->target]->events;
        }
        p->flags |= 1;
        p->curve=-1;
        m->oldFrame=m->nextFrame;
        m->current=m->next;
        m->nextFrame++;
        if(p->restart) {
            p->restart=0;
            p->rate=base;
            m->time=zero;
            m->nextFrame=p->queuedEnd;
            m->next=m->cl->clips[m->target]->frames[m->nextFrame];
            func_L39_00628F40(p);
        } else if(p->queuedStart!=-1 && m->nextFrame>p->queuedEnd) {
            p->rate=0.333333343f;
            m->time=0.0f;
            m->nextFrame=p->queuedStart;
            m->next=m->cl->clips[m->target]->frames[m->nextFrame];
        } else {
            if(m->nextFrame>=m->cl->clips[m->target]->count) {
                m->nextFrame=0;
                p->flags |= 2;
            }
            m->time-=one;
            m->next=m->cl->clips[m->target]->frames[m->nextFrame];
            m->time /= p->rate;
            p->rate=*m->current;
            m->time *= p->rate;
        }
        now=m->time;
      } while(m->time>=one);
    }
    if(same && m->eventCount) {
        clip=m->cl->clips[m->animation];
        start=(oldFrame<<4)+(s32)(old*16.0f);
        end=(m->oldFrame<<4)+(s32)(now*16.0f);
        events=(s32 *)((u8 *)clip+0x1c+clip->count*4);
        for(i=0;i<clip->events;i++) {
            s32 word=events[i];
            s32 frame=word>>16;
            if(start<frame && end>=frame) {
                event=word&0xffff;
                if(m->animation!=m->target || m->animation!=40) {
                    if((u32)(event-37)<3 && m->classId!=0x171c) event=0;
                    func_L39_005F0CE0(event,0,m);
                }
                break;
            }
        }
    }
    if(m->activeEvent!=255) {
        s32 id=m->activeEvent;
        u8 *entry=D_L39_001FE1A0+(id<<7);
        if(*(Moby_0061FCB0 **)(entry+0xdc)!=m) m->activeEvent=255;
        else if(*(s16 *)(entry+0xca)!=m->desiredEvent) {
            func_L39_005F0988(id);
            m->activeEvent=255;
        }
    } else if(m->desiredEvent!=255) m->activeEvent=func_L39_005F0CE0(m->desiredEvent,4,m);
    previous=p->previousTime;
    p->previousTime=func_L01_00436500(m);
    if(p->previousTime>=previous) p->deltaTime=p->previousTime-previous;
    else p->deltaTime=delta;
    p->changed=m->animation!=m->target;
}
/* localdecomp:end func_L39_0061FCB0 */
