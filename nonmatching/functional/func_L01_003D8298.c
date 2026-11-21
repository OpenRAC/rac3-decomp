/* functional: medium. Near miss (49 word diffs, register allocation and stack slots only per the worker's notes). */
#include "common.h"
/* localdecomp:start func_L01_003D8298 */
#include "vu0.h"
extern f32 D_L01_001DF4AC, D_L01_001DF4B0;
__asm__(".extern D_L01_001DF4AC, 4");
__asm__(".extern D_L01_001DF4B0, 4");
extern u8 *D_L01_00221098_003D8298[];
extern u8 D_001425C0[];
typedef struct { u8 pad0[0x6C]; f32 damage; u8 pad70[0x80]; } Weapon_003D8298;
extern Weapon_003D8298 D_L01_002C5600[];
typedef struct { u8 pad0[0xD0]; u8 active; u8 padD1[11]; u8 *owner; } Record_003D8298;
extern u8 D_001A30B0[];
typedef struct { vu0_v4 velocity; s32 pad10, time, pad18, attachment; u8 pad20[12]; s32 sound; } State_003D8298;
void func_L01_003D8298(u8 *obj) {
    extern void func_L01_004C8688(s32, void *, void *);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_L01_00446760(void *, u8 *, s32, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, void *);
    extern s32 func_003A52A0(s32, s32, u8 *);
    extern void func_003A4F28(s32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(u8 *);
    extern void func_L01_00404A10(void *, s32);
    extern void func_L01_003D8780(void);
    f32 previous[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 point[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    u8 hit[0x30];
    State_003D8298 *s=*(State_003D8298 **)(obj+0x68);
    u8 *particle;
    s32 i, k, life, kind, next;
    Record_003D8298 *record;
    f32 size;
    *(u128_t *)previous=*(u128_t *)(obj+0x10);
    func_L01_004C8688(s->attachment,s,0);
    vec_add_ab(obj+0x10,s,obj+0x10);
    if(func_L01_004CB2D8()) func_L01_004CAB30(obj+0x10,obj+0x10);
    if(s->time<25) {
        for(i=0;i<6;i=next) {
            func_003C2F58(obj,i,a);
            next=i+1;
            func_003C2F58(obj,next,b);
            k=0;
            do {
                func_0038CDF8(point,a,b,func_003824E0(0.0f,1.0f));
                func_0038CE20((f32 *)velocity,(f32 *)s,-0.0400000028f);
                func_003C4C18(velocity,D_L01_001DF4B0*0.0200000014f);
                velocity[2]+=D_L01_001DF4AC*0.0200000014f;
                kind=func_00382498(3,6);
                kind=kind*5+2;
                kind/=6;
                life=(s32)func_L01_00443A18(2.0f,3.0f);
                size=func_003824E0(0.8f,0.4f)*210000.0f;
                particle=func_L01_004713C8(point,velocity,kind,0,life,127,127,size,21000.0f,0.0f,6);
                if(particle) {
                    particle[3]=0x44;
                    particle[2]=D_L01_00221098_003D8298[0x35][0];
                }
                kind=func_00382498(3,6);
                kind=kind*5+2;
                kind/=6;
                life=(s32)func_L01_00443A18(2.0f,3.0f);
                size=func_003824E0(0.8f,0.4f)*210000.0f;
                particle=func_L01_004713C8(point,velocity,kind,0x7C0030,life,48,48,size*1.35f,21000.0f,0.0f,0);
                if(particle) {
                    particle[3]=0x44;
                    particle[2]=D_L01_00221098_003D8298[0x35][0];
                }
                k--;
            } while(k>=0);
        }
    }
    *(u128_t *)a=*(u128_t *)s;
    func_0038CE20((f32 *)a,(f32 *)a,1.75f);
    a[3]=5627.9248046875f;
    func_L01_00446760(hit,obj,0x210000,a,(D_001425C0[0x7F]+D_L01_002C5600)->damage);
    hit[0x19]=1;
    *(u16 *)(hit+0x1A)=*(u16 *)(obj+0xAA);
    hit[0x18]=0;
    func_003C2F58(obj,0,b);
    func_003C2F58(obj,6,point);
    func_003D3CB0(b,point,0,obj,hit);
    if(s->sound==-1) {
        s->sound=func_003A52A0(0,4,obj);
    } else {
        record=(Record_003D8298 *)(D_001A30B0+(s->sound<<7));
        if(record->owner!=obj || !record->active) s->sound=func_003A52A0(0,4,obj);
    }
    if(func_0038CAD0(&s->time)) {
        if(s->sound!=-1) {
            record=(Record_003D8298 *)(D_001A30B0+(s->sound<<7));
            if(record->owner==obj && record->active) func_003A4F28(s->sound);
        }
        s->sound=-1;
        func_L01_004C8668(s->attachment);
        func_003C2880(obj);
    } else if(obj && obj[0x20]!=254 && obj[0x20]!=253) {
        if(!(*(u16 *)(obj+0x34)&2)) func_L01_00404A10(func_L01_003D8780,(s32)obj);
    }
}
/* localdecomp:end func_L01_003D8298 */
