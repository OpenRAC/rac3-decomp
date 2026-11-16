/* PAL near miss (Codex wave 6): near miss: 40 words differ with the file's flags.
 * Worker's note: 12 diff w298/func_L01_00475128.retained.log with injected divs 2; address registers and final byte-store scheduling; three later forms stagnate at 16 diff
 */
#include "common.h"
/* localdecomp:start func_L01_00475128 */
typedef int Quad_00475128 __attribute__((mode(TI)));
typedef struct {
    Quad_00475128 v;
    s32 owner;
    f32 scale, speed;
    u8 alpha, mode, flag;
} Sub_00475128;
typedef struct {
    u8 type, flags, texture, render;
    s32 rgba;
    u8 spin, render2;
    s16 life;
    f32 age;
    Quad_00475128 position;
    Sub_00475128 sub;
} Part_00475128;
extern u8 *D_L01_00221288[];
Part_00475128 *func_L01_00475128(s32 owner,Quad_00475128 *pos,Quad_00475128 *vel,s32 color,s32 life,u8 flag,u8 mode,u8 texture,f32 width,f32 age,f32 speed) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    Part_00475128 *p;
    Sub_00475128 *q;
    p = (Part_00475128 *)func_L01_004618E0(0x7C);
    if (p) {
        p->flags=0;
        p->render2=0x44;
        p->render=0x48;
        p->spin=func_00382468(0x100);
        p->age=age;
        p->texture=D_L01_00221288[0][texture];
        p->rgba=color;
        p->life=life;
        p->position=*pos;
        ((f32 *)&p->position)[3]=1.0f/(f32)life;
        q=&p->sub;
        q->owner=owner;
        q->v=*vel;
        q->mode=mode;
        ((f32 *)&q->v)[3]=width;
        q->scale=age;
        q->speed=speed;
        q->alpha=color>>24;
        p->sub.flag=flag;
    }
    return p;
}
/* localdecomp:end func_L01_00475128 */
