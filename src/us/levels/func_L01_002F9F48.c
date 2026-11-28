#include "common.h"
/* localdecomp:start func_L01_002F9F48 */
#include "vu0.h"
typedef struct {
    vu0_v4 vector;
    u8 *owner;
    u32 flags;
    u8 type, enabled;
    u16 kind;
    f32 scale;
    s32 active;
} Hit_002F9F20;
typedef struct {
    u8 pad[0x18];
    u8 *object;
    s32 count;
    vu0_v4 position;
    u8 pad30[0x10];
    vu0_v4 normal;
} Collision_002F9F20;
extern u8 D_L01_001EAA80[];
extern u8 *D_001A71A0[];
extern s32 D_L01_001D9EA0;
void func_L01_002F9F48(u8 *obj) {
    extern void func_003BFC18(void *,void *,s32);
    extern void func_003886E8(f32 *,f32 *,f32);
    extern void func_L01_002FB580(u8 *);
    extern void func_00388880(void *,void *,f32);
    extern s32 func_003CE740(void *,void *,s32,void *,void *);
    extern void func_L01_0040C260(void *,void *,void *);
    extern void func_00388830(void *,void *,f32);
    extern s32 func_00388398(s32 *);
    extern void func_L01_004C4AB8(s32);
    extern void func_L01_002FA220(u8 *,void *,void *);
    extern void func_L01_002FAAC8(u8 *,void *,void *);
    vu0_v4 reflected = {0,0,0,0};
    vu0_v4 normal = {0,0,0,0};
    vu0_v4 previous;
    vu0_v4 ground;
    Hit_002F9F20 hit;
    u8 *vars = *(u8 **)(obj+0x68);
    previous=*(vu0_v4 *)(obj+0x10);
    reflected.z=0.0333333351f;
    normal.z=1.0f;
    vec_add_ab(obj+0x10,obj+0x10,vars);
    func_003BFC18(obj+0x10,&ground,0);
    func_003886E8((f32 *)&ground,(f32 *)&ground,0.000305555586f);
    func_L01_002FB580(obj);
    hit.owner=obj;
    hit.flags=0x1030000;
    if (*(s32 *)(vars+0x18)<290) {
        hit.flags=0x1030001;
    }
    hit.scale=1;
    hit.active=1;
    hit.vector=*(vu0_v4 *)vars;
    func_00388880(&hit.vector,&hit.vector,1.0f);
    hit.type=2;
    hit.vector.w=5627.9248046875f;
    hit.kind=*(u16 *)(obj+0xAA);
    hit.vector.z=1;
    hit.enabled=1;
    (*(s32 *)(vars+0x14))++;
    if (func_003CE740(&previous,obj+0x10,16,obj,&hit)) {
        if(((Collision_002F9F20 *)D_L01_001EAA80)->object) {
            if ((((Collision_002F9F20 *)D_L01_001EAA80)->object==D_001A71A0[0] || *(s16 *)(((Collision_002F9F20 *)D_L01_001EAA80)->object+0xAA)==0xC0) && *(s32 *)(vars+0x18)>=290) goto done;
            if (*(s32 *)(((Collision_002F9F20 *)D_L01_001EAA80)->object+0x64)==D_L01_001D9EA0 && *(s16 *)(((Collision_002F9F20 *)D_L01_001EAA80)->object+0xAA)!=0x336) goto done;
            obj[0xBC]=1;
            *(vu0_v4 *)(obj+0x10)=((Collision_002F9F20 *)D_L01_001EAA80)->position;
            func_L01_0040C260(&reflected,vars,&((Collision_002F9F20 *)D_L01_001EAA80)->normal);
            func_00388830(&reflected,&reflected,0.0333333351f);
            func_00388830(&normal,&((Collision_002F9F20 *)D_L01_001EAA80)->normal,1.0f);
        } else if (((Collision_002F9F20 *)D_L01_001EAA80)->count>0) {
            obj[0xBC]=1;
            *(vu0_v4 *)(obj+0x10)=((Collision_002F9F20 *)D_L01_001EAA80)->position;
            func_L01_0040C260(&reflected,vars,&((Collision_002F9F20 *)D_L01_001EAA80)->normal);
            func_00388830(&reflected,&reflected,0.0333333351f);
            func_00388830(&normal,&((Collision_002F9F20 *)D_L01_001EAA80)->normal,1.0f);
        }
    } else if(func_00388398((s32 *)(vars+0x18))) {
        obj[0xBC]=1;
        vec_add_ab(&reflected,&reflected,vars);
    }
done:
    if (obj[0xBC]) {
        func_L01_004C4AB8(*(s32 *)(vars+0x1C));
        if (*(s32 *)(vars+0x14)<20) {
            func_L01_002FA220(obj,&reflected,&normal);
        }
        else {
            func_L01_002FAAC8(obj,&reflected,&normal);
        }
    }
}
/* localdecomp:end func_L01_002F9F48 */
