/* functional: high. Taken from the PAL near-miss draft; every constant, offset and callee re-read against PAL asm; differs from retail only in instruction scheduling and register use. */
#include "common.h"
#include "vu0.h"
typedef struct { u8 pad[0xC]; vu0_v4 *owner; } Link_003D4330;
typedef struct { u8 pad[0x68]; Link_003D4330 *link; } State_003D4330;
typedef struct { u8 pad[0xB8]; State_003D4330 *state; } Obj_003D4330;
typedef struct { u8 pad[0xC]; u8 flags; u8 padD[0x13]; vu0_v4 pos; } Out_003D4330;
extern vu0_v4 D_L07_001E8C20;
s32 func_L07_003D4330(Obj_003D4330 *obj, Out_003D4330 *out) {
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_L04_00455AF8(void *);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_00382538(void);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    vu0_v4 pos, delta, best, offset;
    vu0_v4 *origin;
    u8 *target;
    s32 i;
    f32 angle, distance, height;
    origin=obj->state->link->owner;
    if (out->flags & 1) {
        *(vu0_q *)&pos=*(vu0_q *)origin;
        if (func_L01_0040E570((u8 *)obj->state+0x10,&pos)>4.0f) {
            pos.z+=0.5f;
            if (func_L04_00455AF8(&pos)>=origin->z+64.0f) {
                pos.z=func_003C3D30(&pos,0,0,0.0f);
                out->pos=pos;
                out->pos.z+=0.1f;
                return 1;
            }
        }
    }
    best.z=-1.0f;
    i=0;
    do {
        target=*(u8 **)((u8 *)origin+0x10);
        if (target) {
            func_0038CF68(&offset,target+0xC0,-4.0f);
            distance=func_003824E0(0.0f,15.0f);
            angle=func_0038DAB8(*(f32 *)(target+0xF8),func_003824E0(-0.7853981853f,0.7853981853f));
            pos.x=func_0038D098(angle)*distance;
            pos.y=func_0038D0B0(angle)*distance;
            pos.z=0.0f;
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(pos) : "m"(pos),"m"(offset) : "vf1","vf2");
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
                : "=m"(pos) : "m"(*origin),"m"(pos) : "vf1","vf2");
        } else {
            angle=func_00382538();
            pos.x=func_0038D098(angle)*5.0f;
            pos.y=func_0038D0B0(angle)*5.0f;
            pos.z=0.0f;
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(pos) : "m"(pos),"m"(*origin) : "vf1","vf2");
        }
        if (func_L01_0040E570((u8 *)obj->state+0x10,&pos)<4.0f) continue;
        if (func_003D3CB0(origin,&pos,2,0,0)) {
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
                : "=m"(delta) : "m"(*origin),"m"(pos) : "vf1","vf2");
            func_0038CF68(&pos,&delta,-0.8f);
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
                : "=m"(pos) : "m"(pos),"m"(D_L07_001E8C20) : "vf1","vf2");
        }
        height=func_003C3D30(&pos,0,0,0.0f);
        pos.z=height;
        if (origin->z-height>2.5f && best.z<height) *(vu0_q *)&best=*(vu0_q *)&pos;
        goto found;
    } while (++i<8);
    if (!(best.z>=0.0f)) return 0;
    *(vu0_q *)&out->pos=*(vu0_q *)&best;
    goto done;
found:
    *(vu0_q *)&out->pos=*(vu0_q *)&pos;
done:
    out->pos.z+=0.1f;
    return 1;
}
