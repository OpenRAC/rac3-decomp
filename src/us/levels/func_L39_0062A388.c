#include "common.h"

/* localdecomp:start func_L39_0062A388 */
typedef union { u8 b[8]; u32 w[2]; u16 h[4]; } B_A388;
typedef struct {
    u8 pad0[0xE]; s16 animation;
    u8 pad10[0x11]; s8 remap; u8 pad22[0x5E];
} E_A388;
typedef struct { u8 pad0[8]; s32 value; u8 padC[0x1C]; f32 scale; } O_A388;
extern E_A388 D_L39_0049C950[];
extern u8 D_L39_004998A0[];
extern s32 D_L39_00246268[2];
__asm__(".extern D_L39_00246268, 16");
extern s32 func_L39_00646268(u8 *, s32);
extern O_A388 *func_L39_005A8E28(void *, s32, void *, s32);
extern void func_L01_00437108(void *, void *, s32, s32, s32, s32);

void func_L39_0062A388(u8 *g, s32 a1, s32 a2) {
    s32 id, animation, i;
    E_A388 *entry;
    O_A388 **slots;
    O_A388 *o;
    if (!g[0x1A07] || !g[0x1A05] || a1 || !a2) return;
    id=-1;
    if (*(s32 *)(g+0x474)==2) id=*(s32 *)(g+0x478);
    if (id==-1 || id==0) return;
    if (func_L39_00646268(g,id)) entry=&D_L39_0049C950[D_L39_0049C950[id].remap];
    else entry=&D_L39_0049C950[id];
    animation=entry->animation;
    if(animation==-1) return;
    slots=(O_A388 **)(g+0x748);
    for(i=0;i<2;i++) {
        if(slots[i]==0) {
            if(i==1) {
                B_A388 buf;
                u8 *q=g+0x1A17;
                u8 *d;
                s32 n,k,m,j;
                u32 a,b;
                s32 r;
                if(*q==0) r=0;
                else {
                    n=*q;k=((u32)q-n)&7;m=n+1;d=buf.b;
                    for(j=0;j<24;j+=3) *d++=D_L39_004998A0[m+((k+j)&7)*255];
                    a=buf.w[0]^(u32)q;
                    b=buf.w[1]^a;
                    buf.w[0]=a;
                    buf.w[1]=(b>>16)/(((b^(b>>16))<<16)+1);
                    r=buf.b[4];
                }
                if((r^2)!=0) break;
            }
            o=func_L39_005A8E28(*(void **)(g+0x2524),D_L39_00246268[i],g+(i*0x3C0+0x2580),0x3C0);
            slots[i]=o;
            if(o) {
                *(s32 *)(g+0x754)=0;
                o->value=0;
                func_L01_00437108(*(void **)(g+0x2524),o,animation,0,15,1);
                o->scale=1.0f;
            }
        }
    }
}
/* localdecomp:end func_L39_0062A388 */
