/* func_L01_00475128 (level 01, Veldin): allocates and fills a 0x7C particle record.
 * Best C: with the file's flags this compiles to retail's instructions exactly; the
 * only thing check.py still reports is the two `nop`s retail has before its div.s,
 * which the build pads from config/levels/divs_nops.txt. The line that table needs is
 *
 *     func_L01_00475128 2
 *
 * (one div.s, two nops in front of it: 0x004751E4 and 0x004751E8).
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
Part_00475128 *func_L01_00475128(s32 owner, Quad_00475128 *pos, Quad_00475128 *vel,
                                s32 color, s32 life, u8 flag, u8 mode, u8 texture,
                                f32 width, f32 age, f32 speed)
{
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 fe_func_00443948(s32);
    Part_00475128 *p;
    Sub_00475128 *q;
    p = (Part_00475128 *)func_L01_004618E0(0x7C);
    if (p) {
        p->flags=0;
        p->render2=0x44;
        p->render=0x48;
        p->spin=fe_func_00443948(0x100);
        p->age=age;
        p->texture=D_L01_00221288[0][texture];
        p->rgba=color;
        p->life=life;
        p->position=*pos;
        ((f32 *)&p->position)[3]=1.0f/(f32)life;
        q=&p->sub;
        q->owner=owner;
        q->v=*vel;
        /* The store order is a scheduling lever: gcc issues the last store of the
         * run to one base first and the rest in source order, so writing these
         * backwards of retail is what reproduces retail's at 0x00475210. */
        ((f32 *)&q->v)[3]=width;
        q->scale=age;
        q->speed=speed;
        q->alpha=color>>24;
        q->flag=flag;
        q->mode=mode;
    }
    return p;
}
/* localdecomp:end func_L01_00475128 */
