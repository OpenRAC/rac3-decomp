/* PAL near miss (Codex wave 7): near miss: 33 words differ with the file's flags.
 * Worker's note: 33 diff e5-04.log; frame 0x50 vs retail 0x60 and swapped s0/s1 allocation; three pointer/copy wordings emitted same mismatch
 */
#include "common.h"
/* localdecomp:start func_L20_003F21A8 */
typedef int Q_003F21A8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003F21A8;
typedef struct { V_003F21A8 pos,vel; s32 mode; u8 p24[8]; s32 arg; } Vars_003F21A8;
typedef struct { u8 p0[0x10]; V_003F21A8 pos; u8 p20[0x48]; Vars_003F21A8 *vars; u8 p6C[0x88]; f32 pitch,yaw; } Obj_003F21A8;
Obj_003F21A8 *func_L20_003F21A8(u8 *parent, V_003F21A8 *position, V_003F21A8 *velocity, s32 arg) {
    extern void func_L01_0044A7D0(void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern s32 func_00382468(s32);
    V_003F21A8 pos;
    V_003F21A8 vel;
    V_003F21A8 *velp;
    s32 mode;
    Obj_003F21A8 *m;
    Vars_003F21A8 *v;
    pos=*position;
    vel=*velocity;
    velp=&vel;
    m=(Obj_003F21A8 *)func_003C24B0(0x1D85,0x70);
    if(m) {
        func_L01_00456160((u8 *)m,parent);
        *(Q_003F21A8 *)&m->pos=*(Q_003F21A8 *)&pos;
        func_L01_0044A7D0(m);
        v=m->vars;
        v->pos=*velp;
        v->vel=*velp;
        v->pos.z=func_0038DAB8(v->pos.z,func_L01_00443A18(2.0f,25.0f)*0.01745329238474369f);
        m->pitch=-func_0038D160(func_0038CED8(velp),velp->z);
        m->yaw=func_0038D160(vel.x,velp->y);
        v->arg=arg;
        if(func_00382468(30)) {
            func_00382468(2);
            mode=-1;
        } else mode=1;
        v->mode=mode;
    }
    return m;
}
/* localdecomp:end func_L20_003F21A8 */
