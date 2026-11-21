/* functional: high. Draft near miss (165 words, VU sequences). Full read against PAL asm: aim vector/ballistic solve (target or hero-camera path, down vector from camera or func_003C5180, gravity correction); stack slots, constants, $gp global (D_001D6740_sda = gp-0x6170), and branch conditions all verified. Both VU subtracts around the D_001E29E0-2 vector are retail's (they cancel); kept. */
#include "common.h"
/* localdecomp:start func_L01_0036FA50 */
typedef int Q_0036FA50 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0036FA50;
typedef struct { V_0036FA50 row[3]; } M_0036FA50;
typedef struct { u8 p0[0x10]; V_0036FA50 pos; u8 p20[0xC0-0x20]; M_0036FA50 matrix; } Actor_0036FA50;
typedef struct { u8 p0[0x368]; s16 mode; u8 p36A[0x6C0-0x36A]; M_0036FA50 matrix; u8 p6F0[0x25C0-0x6F0]; Actor_0036FA50 *actor; s32 weapon; u8 p25C8[0x25ED-0x25C8]; u8 disabled; } Hero_0036FA50;
typedef struct { u8 pad[0x1A0]; s32 mask; } Pad_0036FA50;
extern Hero_0036FA50 D_001A4BE0;
extern s32 D_001D6740_sda;
extern Pad_0036FA50 *D_001D52FC;
extern V_0036FA50 D_L01_001E29E0[];
void func_L01_0036FA50(V_0036FA50 *out, V_0036FA50 *from, Actor_0036FA50 *target, Actor_0036FA50 *actor, f32 low, f32 high, f32 speed, f32 gravity) {
    extern f32 func_0038CE68(void *a, void *b);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_L01_005003D0(s32, s32);
    extern s32 func_003A3BB8(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D810(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038D000(void *, void *, void *);
    V_0036FA50 tmp, projection, down, end, diff, correction, velpart, endpart, fall, accel;
    V_0036FA50 origin;
    M_0036FA50 basis;
    V_0036FA50 quat, axis, look;
    M_0036FA50 rotated, rotation;
    V_0036FA50 direction;
    f32 distance, half, d, denom, time, invtime;
    if (actor) { origin=actor->pos; basis=actor->matrix; }
    else { origin=D_001A4BE0.actor->pos; basis=D_001A4BE0.matrix; }
    out->x=1.0f; *(s32 *)&out->y=0; *(s32 *)&out->z=0; *(s32 *)&out->w=0;
    if (D_001A4BE0.mode && !D_001D6740_sda) func_0038CE20(&down,&D_001A4BE0.actor->matrix.row[2],-1.0f);
    else func_003C5180(&origin,&down,0);
    distance=high;
    if (!target) {
        if (D_001A4BE0.weapon==1) func_L01_005003D0(29,1);
        if ((D_001D52FC->mask & func_003A3BB8(4,0)) && !D_001A4BE0.disabled) {
            func_0038CF68(&look,D_L01_001E29E0,1.0f);
            func_0038CE20(&projection,&down,func_0038CE68(&look,&down));
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tmp) : "m"(look), "m"(projection) : "vf1", "vf2");
            func_0038CF68(&tmp,&tmp,1.0f);
            func_0038CE90(&axis,&look,&tmp);
            half=func_0038CE68(&look,&tmp)*0.5f;
            func_0038CE20(&quat,&axis,func_0038D0B0(half));
            quat.w=func_0038D098(half);
            func_0038D810(&quat,&rotation);
            func_0038D5F0(&rotated,&rotation,D_L01_001E29E0);
            d=-func_0038CE68(&origin,&down);
            func_0038CF68(&direction,D_L01_001E29E0,1.0f);
            denom=func_0038CE68(&down,&direction);
            if (denom>0.0f) {
                func_0038CE20(&direction,&direction,(func_0038CE68(&down,D_L01_001E29E0-2)+d)/denom);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(direction) : "m"(D_L01_001E29E0[-2]), "m"(direction) : "vf1", "vf2");
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(direction) : "m"(direction), "m"(D_L01_001E29E0[-2]) : "vf1", "vf2");
                func_0038CE20(&projection,&down,func_0038CE68(&direction,&down));
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tmp) : "m"(direction), "m"(projection) : "vf1", "vf2");
                distance=func_0038CEA8(&tmp);
                if (distance>high) distance=high;
                else if (distance<low) distance=low;
            }
            distance=high*func_L01_004451A8(distance/high);
            func_0038D000(out,out,&rotated);
        } else func_0038D000(out,out,&basis);
        func_0038CF68(out,out,distance);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(end) : "m"(*out), "m"(origin) : "vf1", "vf2");
    } else end=target->pos;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(diff) : "m"(end), "m"(*from) : "vf1", "vf2");
    func_0038CE20(&projection,&down,func_0038CE68(&diff,&down));
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tmp) : "m"(diff), "m"(projection) : "vf1", "vf2");
    func_0038CF68(out,&tmp,speed);
    time=func_0038CEA8(&tmp)/speed;
    invtime=1.0f/time;
    func_0038CE20(&velpart,&down,func_0038CE68(from,&down));
    func_0038CE20(&endpart,&down,func_0038CE68(&end,&down));
    time=time*time;
    time=gravity*time;
    func_0038CE20(&fall,&down,time*0.5f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(accel) : "m"(velpart), "m"(endpart) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(accel) : "m"(accel), "m"(fall) : "vf1", "vf2");
    func_0038CE20(&accel,&accel,-1.0f);
    func_0038CE20(&correction,&accel,invtime);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*out) : "m"(*out), "m"(correction) : "vf1", "vf2");
}
/* localdecomp:end func_L01_0036FA50 */
