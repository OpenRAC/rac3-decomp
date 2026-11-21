/* functional: high. stack layout only; D_L01_001E29C0 instead of pointer arithmetic */
#include "common.h"
/* localdecomp:start func_L01_004C7438 */
typedef struct { u8 pad[0x368]; s16 state; u8 gap[0x25C0-0x36A]; u8 *camera; s32 mode; u8 gap2[0x25ED-0x25C8]; u8 disabled; } Hero_004C7438;
extern S_4C4A18 D_001A4BE0;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern u8 *D_001D52FC;
extern Vec4_004C4AD8 D_L01_001E29E0;
extern Vec4_004C4AD8 D_L01_001E29C0;
void func_L01_004C7438(Vec4_004C4AD8 *out, Vec4_004C4AD8 *pos, u8 *moby, u8 *camera,
                     f32 minimum, f32 maximum, f32 speed, f32 acceleration) {
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);
    extern void func_L01_005003D0(s32, s32);
    extern s32 func_003A3BB8(s32, s32);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D810(Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern void func_0038D5F0(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern f32 func_0038CEA8(Vec4_004C4AD8 *);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038D000(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern f32 *func_00382348(u8 *);
    Vec4_004C4AD8 v, temp, direction, target, delta, correction;
    Vec4_004C4AD8 from, to, accel, result;
    Vec4_004C4AD8 basis[4];
    Vec4_004C4AD8 quat, axis, unit, rotated, matrix[4], point;
    f32 distance, denominator, plane, angle, t, inv;
    f32 *data;
    if (camera) {
        *(u128_4C4A18 *)&basis[0] = *(u128_4C4A18 *)(camera+0x10);
        *(u128_4C4A18 *)&basis[1] = *(u128_4C4A18 *)(camera+0xC0);
        *(u128_4C4A18 *)&basis[2] = *(u128_4C4A18 *)(camera+0xD0);
        *(u128_4C4A18 *)&basis[3] = *(u128_4C4A18 *)(camera+0xE0);
    } else {
        *(u128_4C4A18 *)&basis[0] = *(u128_4C4A18 *)(D_001A4BE0.x25C0+0x10);
        *(u128_4C4A18 *)&basis[1] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0+0x6C0);
        *(u128_4C4A18 *)&basis[2] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0+0x6D0);
        *(u128_4C4A18 *)&basis[3] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0+0x6E0);
    }
    out->x=1; out->y=0; out->z=0; out->w=0;
    if (D_001A4BE0.x368 && !D_L01_001D6740)
        func_0038CE20(&direction,(Vec4_004C4AD8 *)(D_001A4BE0.x25C0+0xE0),-1.0f);
    else func_003C5180((u128_4C4A18 *)&basis[0],(E_4C4A18 *)&direction,0);
    distance=maximum;
    if (!moby) {
        if (((Hero_004C7438 *)&D_001A4BE0)->mode==1) func_L01_005003D0(29,1);
        if ((*(s32 *)(D_001D52FC+0x1A0)&func_003A3BB8(4,0)) && !((Hero_004C7438 *)&D_001A4BE0)->disabled) {
            func_0038CF68(&unit,&D_L01_001E29E0,1.0f);
            angle=func_0038CE68(&unit,(T_004C4AD8 *)&direction);
            func_0038CE20(&temp,&direction,angle);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(v) : "m"(unit), "m"(temp) : "vf1", "vf2");
            func_0038CF68(&v,&v,1.0f);
            func_0038CE90(&axis,&unit,(T_004C4AD8 *)&v);
            angle=func_0038CE68(&unit,(T_004C4AD8 *)&v)*0.5f;
            func_0038CE20(&quat,&axis,func_0038D0B0(angle));
            quat.w=func_0038D098(angle);
            func_0038D810(&quat,matrix);
            func_0038D5F0(&rotated,matrix,&D_L01_001E29E0);
            plane=-func_0038CE68(&basis[0],(T_004C4AD8 *)&direction);
            func_0038CF68(&point,&D_L01_001E29E0,1.0f);
            denominator=func_0038CE68(&direction,(T_004C4AD8 *)&point);
            if (denominator>0.0f) {
                func_0038CE20(&point,&point,(func_0038CE68(&direction,(T_004C4AD8 *)&D_L01_001E29C0)+plane)/denominator);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(point) : "m"(D_L01_001E29C0), "m"(point) : "vf1", "vf2");
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(point) : "m"(point), "m"(D_L01_001E29C0) : "vf1", "vf2");
                func_0038CE20(&temp,&direction,func_0038CE68(&point,(T_004C4AD8 *)&direction));
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(v) : "m"(point), "m"(temp) : "vf1", "vf2");
                distance=func_0038CEA8(&v);
                if (maximum<distance) distance=maximum;
                else if (distance<minimum) distance=minimum;
            }
            distance=maximum*func_L01_004451A8(distance/maximum);
            func_0038D000(out,out,&rotated);
        } else func_0038D000(out,out,&basis[1]);
        func_0038CF68(out,out,distance);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(target) : "m"((*out)), "m"(basis[0]) : "vf1", "vf2");
    } else {
        if ((u32)(*(u16 *)(moby+0xAA)-0xA8D)<2 && (data=func_00382348(moby)) && data[0]>0.0f) {
            if (D_L01_001D673C || D_001A4BE0.x368) {
                func_0038CE20(&quat,(Vec4_004C4AD8 *)(moby+0xE0),data[4]);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(target) : "m"((*(Vec4_004C4AD8 *)(moby+0x10))), "m"(quat) : "vf1", "vf2");
            } else {
                *(u128_4C4A18 *)&target=*(u128_4C4A18 *)(moby+0x10);
                target.z+=data[4];
            }
        } else *(u128_4C4A18 *)&target=*(u128_4C4A18 *)(moby+0x10);
    }
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(target), "m"((*pos)) : "vf1", "vf2");
    func_0038CE20(&temp,&direction,func_0038CE68(&delta,(T_004C4AD8 *)&direction));
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(v) : "m"(delta), "m"(temp) : "vf1", "vf2");
    func_0038CF68(out,&v,speed);
    t=func_0038CEA8(&v)/speed;
    inv=1.0f/t;
    func_0038CE20(&from,&direction,func_0038CE68(pos,(T_004C4AD8 *)&direction));
    func_0038CE20(&to,&direction,func_0038CE68(&target,(T_004C4AD8 *)&direction));
    t=t*t;
    t=t*acceleration;
    func_0038CE20(&accel,&direction,t*0.5f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(result) : "m"(from), "m"(to) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(result) : "m"(result), "m"(accel) : "vf1", "vf2");
    func_0038CE20(&result,&result,-1.0f);
    func_0038CE20(&correction,&result,inv);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"((*out)) : "m"((*out)), "m"(correction) : "vf1", "vf2");
}
/* localdecomp:end func_L01_004C7438 */
