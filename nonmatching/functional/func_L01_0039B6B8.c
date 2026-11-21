/* functional: high. Codex PAL draft re-checked in context: 25 words (weapon table address maths scheduled differently) differs only in scheduling/register allocation/addressing, same calls in the same order.  */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;
#include "vu0.h"
extern f32 D_L01_001E2064;
extern s32 D_L01_001DE0F0;
__asm__(".extern D_L01_001DE0F0, 4");
extern u8 D_00142637[];
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_0039B6B8;
extern Hero_0039B6B8 D_001A4BE0;
typedef struct { u8 pad[0x77]; u8 weapon; } Game_0039B6B8;
extern Game_0039B6B8 D_001425C0;
typedef struct { vu0_q vec; u8 rest[0x20]; } Damage_0039B6B8;
typedef struct { u8 pad[0x6C]; f32 damage; u8 tail[0x80]; } Weapon_0039B6B8;
extern Weapon_0039B6B8 D_L01_002C5600_0039B6B8;
typedef struct { u8 pad[0x9C]; s32 owner; u8 tail[0x10]; } Effect_0039B6B8;
extern Effect_0039B6B8 D_L01_002A1E70_0039B6B8;
extern u8 D_L01_001EEA80[];
extern u8 D_L01_002A1E70[];
extern vu0_q D_L01_001EAA20;
void func_L01_0039B6B8(u8 *self)
{
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *,void *);
    extern s32 func_0038CAD0(s32 *);
    extern s32 func_003D4D00(void *,s32,void *,s32,f32);
    extern u8 *func_00382348(void *);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CF68(Vec4_0039E0C8 *,Vec4_0039E0C8 *,f32);
    extern void func_L01_0039BEF8(u8 *,void *,s32);
    extern void func_L01_00446760(void *,void *,s32,void *,f32);
    extern void func_L01_00446978(void *,void *);
    extern f32 func_00382538(void);
    extern void func_00382760(void *,f32,f32,f32);
    extern s32 func_003D3CB0(Vec4 *,s32 *,s32,s32,s32);
    extern void func_L01_0039C190(u8 *);
    extern void func_L01_0039B9F0(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *),u8 *);
    extern void func_003C2880(void *);
    struct { vu0_q pos,offset,delta; Damage_0039B6B8 hit; } work;
    u8 *state=*(u8 **)(self+0x68);
    s32 count;
    u8 **objects;
    f32 x,y;
    s32 active;
    s32 n;
    if(func_L01_004CB2D8()) func_L01_004CAB30(self+0x10,self+0x10);
    active=func_0038CAD0((s32 *)state);
    n=D_L01_001DE0F0;
    if (!active) {
        count=func_003D4D00(self+0x10,1,self,0,D_L01_001E2064);
        if(count && (&D_L01_002C5600_0039B6B8)[D_001425C0.weapon].pad[1]>=2) {
            if(count>0) {
            s32 remaining=count;
            objects=(u8 **)D_L01_001EEA80;
            do {
                u8 *other=func_00382348(*objects);
                if(other && (*(u16 *)(*objects+0x34)&0x4000) && *objects!=D_001A4BE0.moby
                   && *objects && *(u8 **)(*objects+0x24) && (*(u8 **)(*objects+0x24))[0x46]==5) {
                    func_L01_004C7D98(self+0x10,&work.offset);
                    func_0038CF68((Vec4_0039E0C8 *)&work.offset,(Vec4_0039E0C8 *)&work.offset,*(f32 *)(other+0x10));
                    vec_add_ba(&work.pos,*objects+0x10,&work.offset);
                    func_L01_0039BEF8(self,&work.pos,4);
                    vec_sub_ba(&work.delta,*objects+0x10,self+0x10);
                    func_0038CF68((Vec4_0039E0C8 *)&work.delta,(Vec4_0039E0C8 *)&work.delta,1.5f);
                    func_0038CF68((Vec4_0039E0C8 *)((u8 *)&work.hit),(Vec4_0039E0C8 *)((u8 *)&work.hit),2.0f);
                    func_L01_00446760(((u8 *)&work.hit),self,0x110000,&work.delta,(&D_L01_002C5600_0039B6B8)[D_001425C0.weapon].damage*0.001f);
                    *(vu0_q *)((u8 *)&work.hit)=work.delta;
                    *(s32 *)(((u8 *)&work.hit)+0x20)=1;
                    *(f32 *)(((u8 *)&work.hit)+0xC)=5627.9248046875f;
                    ((u8 *)&work.hit)[0x18]=5;
                    ((u8 *)&work.hit)[0x19]=3;
                    *(u16 *)(((u8 *)&work.hit)+0x1A)=*(u16 *)(*objects+0xAA);
                    func_L01_00446978(*objects,((u8 *)&work.hit));
                }
            } while(--remaining,objects++,remaining!=0);
            }
        }
        x=func_00382538();
        y=func_00382538();
        func_00382760(&work.pos,D_L01_001E2064,x,y);
        vec_add_ab(&work.pos,&work.pos,self+0x10);
        if(func_003D3CB0((Vec4 *)(self+0x10),(s32 *)&work.pos,0,(s32)self,0)) work.pos=D_L01_001EAA20;
        func_L01_0039BEF8(self,&work.pos,4);
        func_L01_0039C190(self);
        func_L01_00404A10(func_L01_0039B9F0,self);
    } else {
        
        Effect_0039B6B8 *p=&D_L01_002A1E70_0039B6B8;
        if(n>0) do { p->owner=0; n--;p++; } while(n!=0);
        func_003C2880(self);
    }
}
