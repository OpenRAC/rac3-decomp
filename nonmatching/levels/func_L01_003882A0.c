/* PAL near miss (haiku-w1): 6 words differ with the file's flags; the hitpos/obj register choice in the tail: the obj load lands in $a0 (retail $v0), so the tail's beql/move order differs. Callee func_L01_00389B00 is declared returning void *, alias of the later Moby definition (__asm__ label). */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003882A0;
typedef struct { u8 pad[0x46]; u8 kind; } Class_003882A0;
typedef struct { u8 pad[0x24]; Class_003882A0 *cls; } Moby_003882A0;
typedef struct { u8 pad[0x18]; Moby_003882A0 *obj; } Hit_003882A0;
typedef struct { u8 pad[0x6c]; f32 damage; u8 tail[0x80]; } Weapon_003882A0;

extern Hit_003882A0 D_L01_001EAA00;
extern Vec_003882A0 D_L01_001EAA20;
extern Weapon_003882A0 D_L01_002C5600[];
extern u8 D_001425E7[];
extern s32 D_001A71A0[];

Moby_003882A0 *func_L01_003882A0(void *owner, Vec_003882A0 *start, Vec_003882A0 *end, Vec_003882A0 *shot, f32 radius) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void * func_L01_00389B00_003882A0(void *, void *, void *, s32, f32) __asm__("func_L01_00389B00");
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    Vec_003882A0 delta;
    f32 damage, dist;
    Moby_003882A0 *obj, *ret;
    Vec_003882A0 *hitpos;

    vec_sub_ab(shot, end, start);
    func_0038CF68(shot, shot, 1.5f);
    shot->w = 5627.925f;
    if (func_003D3CB0(start, end, 16, D_001A71A0[0], 0)) {
        vec_sub_ab(&delta, end, start);
        func_0038CF68(&delta, &delta, 1.0f);
        hitpos = &D_L01_001EAA20;
        vec_sub_ab(&delta, hitpos, start);
        func_L01_00389B00_003882A0(start, &delta, hitpos, 1, radius);
        if (((s32 *)hitpos)[-2]) {
            damage = ((Weapon_003882A0 *)D_L01_002C5600)[D_001425E7[0]].damage;
            dist = func_0038CF00(hitpos, start);
            if (dist < 10.0f) ((f32 *)shot)[7] = damage;
            else if (dist < 14.0f) ((f32 *)shot)[7] = damage * 0.75f;
            else if (dist < 20.0f) ((f32 *)shot)[7] = damage * 0.5f;
            else ((f32 *)shot)[7] = damage * 0.125f;
            func_L01_00446978(D_L01_001EAA00.obj, shot);
            func_L01_0034C9F0(D_L01_001EAA00.obj, 39, owner);
            obj = D_L01_001EAA00.obj;
            ret = obj;
            if (obj == 0 || obj->cls == 0 || obj->cls->kind != 5) ret = 0;
        } else {
            ret = 0;
        }
    } else {
        vec_sub_ab(&delta, end, start);
        func_L01_00389B00_003882A0(start, &delta, end, 0, -1.0f);
        ret = 0;
    }
    return ret;
}
