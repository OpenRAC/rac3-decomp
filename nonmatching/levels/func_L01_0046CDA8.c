/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_004696F8, the NTSC-U twin of func_L01_0046CDA8, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 3 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L01_004696F8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_4696F8;
extern s32 D_L01_001D7F50;
__asm__(".extern D_L01_001D7F50, 4");
extern s32 func_003883C8(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32,s32);
extern f32 func_0037E250(f32,f32);
extern void *func_L01_00462190(void *,void *,s32,s32,s32,s32,s32,s32,s32,f32);
extern void func_003C7CE0(void *);
typedef struct { u8 pad[16]; V_4696F8 pos, vel; } Particle_4696F8;
static __inline__ void add_4696F8(Particle_4696F8 *p) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
        : "=m"(p->pos) : "m"(p->pos),"m"(p->vel) : "vf1","vf2");
}
void func_L01_004696F8(u8 *obj) {
    u8 *rec=obj+0x20;
    u8 *position;
    if(func_003883C8(obj+0xA)) {
        *(f32*)(rec+8)-=*(f32*)(rec+0x14);
    }
    add_4696F8((Particle_4696F8 *)obj);
    position=obj+0x10;
    { f32 height=((V_4696F8*)position)->z;
    obj[8]+=2;
    if(height<*(f32*)(rec+0x10)) {
        if(!func_0037E1D8(D_L01_001D7F50-1)) {
            *(f32*)(obj+0x18)=*(f32*)(rec+0x10);
            *(f32*)(obj+0x20)*=func_0037E250(1.0f,3.5f);
            *(f32*)(rec+4)*=func_0037E250(1.0f,3.5f);
            *(f32*)(rec+8)*=func_0037E250(-1.0f,-1.5f);
            func_L01_00462190(position,rec,*(s32*)(obj+4),*(s32*)(rec+0x18),func_0037E208(60,120),0,obj[2],obj[3],0,*(f32*)(obj+0xC)*0.5f);
        } else {
            *(f32*)(obj+0x18)=*(f32*)(rec+0x10);
            *(f32*)(obj+0x20)+=func_0037E250(-5.0f,5.0f)*(1.0f/60.0f);
            *(f32*)(rec+4)+=func_0037E250(-5.0f,5.0f)*(1.0f/60.0f);
            *(f32*)(rec+8)*=func_0037E250(-0.5f,-1.0f);
            func_L01_00462190(position,rec,*(s32*)(obj+4),*(s32*)(rec+0x18),func_0037E208(30,60),0,obj[2],obj[3],0,*(f32*)(obj+0xC)*0.25f);
        }
        func_003C7CE0(obj);
    }
}
}
/* localdecomp:end func_L01_004696F8 */
