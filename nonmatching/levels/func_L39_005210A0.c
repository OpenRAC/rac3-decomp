/* Wave 13 (r24, 2026-11-28) replaces the earlier draft of this function (NTSC-U draft of `func_L39_00520C08` (Codex wave 3)). */
/* func_L39_005210A0 near (wave 13 r24), the first PAL draft: the NTSC-U draft (C of func_L39_00520C08)
   moved to PAL's callees and data (func_L39_0061C4D0, func_0038D000, func_0038CF68, func_0038CC88,
   func_L39_005FFD20, func_L01_003F6F20, func_L39_006472D0, ..., D_L39_004997E0, D_L39_0024A9A0/B0,
   D_L39_0025F760, D_L39_004701E0, D_L39_0049C890), PAL's 1.4000001f where NTSC-U has 1.1666667f, and the
   file's own func_003D3CB0 prototype (4th argument void *). The player layout and the remaining
   constants are the same on both discs. 537 differences: the frame is 0x110 against retail's 0x120
   (retail spills five words at 0xA0-0xB0: p+0x10, p+0x20/0x30 addresses, the matrix row address and
   &hit; here fewer values spill), which shifts every stack offset; not yet compared block by block. */
#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* localdecomp:start func_L39_005210A0 */
typedef struct Player_005210A0 Player_005210A0;
typedef union { vu0_v4 v; u32 w[4]; u8 b[16]; } Buf_005210A0;
typedef struct {
    u8 pad0[0x10];
    struct Moby *(*object)(void *);
    u8 pad14[0x20];
    void (*set)(void *,s32,s32,s32,s32);
} VTable_005210A0;
struct Player_005210A0 {
    u8 pad0[0x14];
    VTable_005210A0 *vtable;
    u8 pad18[0x2F4];
    s32 f30C;
    u8 pad310[0xA0];
    vu0_v4 v3B0;
    u8 pad3C0[0x64];
    s32 f424;
    u8 pad428[0x48];
    s32 f470;
    u8 pad474[0xDB8];
    struct Moby *target;
    u8 pad1230[0x10];
    vu0_v4 v1240;
    f32 f1250;
    u8 pad1254[0x5C];
    vu0_v4 v12B0;
    u8 pad12C0[0x50];
    s32 f1310;
    u8 pad1314[0x24];
    s32 f1338, f133C;
    u8 pad1340[0x6A4];
    u8 key;
    u8 pad19E5[0x22];
    u8 b1A07, b1A08;
    u8 pad1A09[0xB];
    u8 b1A14;
    u8 pad1A15[0x2B];
    u8 a1A40[0x10];
    u8 pad1A50[0xA79];
    u8 b24C9;
    u8 pad24CA[0x66];
    u8 *camera; void *sound;
};
typedef struct {
    vu0_v4 origin[2], direction;
    u8 pad30[0x10];
    vu0_v4 target_pos;
    s16 h50,h52;
    s32 sound;
    Player_005210A0 *player;
    u32 target_id;
    s16 h60,h62,h64,h66;
    s32 f68,counter;
    struct Moby *target;
} P_005210A0;
typedef struct {
    u8 pad0[0x2C];
    u32 target_id;
    f32 point[3], normal[3];
    u8 pad48[8];
} Hit_005210A0;
extern u8 D_L39_004997E0[];
extern u8 D_L39_004701E0[],D_L39_0049C890[];
extern vu0_v4 D_L39_0025F760;
extern f32 D_L39_0024A9A0,D_L39_0024A9B0;
__asm__(".extern D_L39_0024A9A0, 4");
__asm__(".extern D_L39_0024A9B0, 4");

void func_L39_005210A0(struct Moby *o) {
    extern void func_L39_0061C4D0(void *,void *,s32);
    extern void func_L01_00444F38(void *,s32,s32,s32,s32);
    extern void func_0038D000(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CC88(void *,void *,s32);
    extern s32 func_L39_005FFD20(void *,void *,s32,f32);
    extern void func_L01_003F6F20(s32,void *,u32,void *,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32);
    extern f32 func_0038CE68(void *,void *);
    extern struct Moby *func_L39_006472D0(void *,void *,void *,s32,f32,f32,f32,f32,f32);
    extern u8 *func_00382348(void *);
    extern s32 func_L39_00639D90(void *);
    extern u32 func_0038DBD8(u32,u32,f32);
    extern f32 func_0038CF00(void *,void *);
    extern u32 func_L39_0061D780(void *);
    extern s32 func_L39_006732D0(void *,s32,s32,void *);
    extern u8 func_L39_00673498(void *,s32);
    extern void func_L39_00621D60(void *,s32);
    extern void func_003C3A10(void *,s32,s32,s32);
    extern s32 func_L01_003F2058(void *,void *);
    extern void *func_L39_0061D1D8(u32);
    extern void func_L39_005F33E0(s32,s32,void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern s32 func_L39_00648AE0(void *,s32);
    extern void func_L39_00533790(void *,void *,void *,void *,s32,s32,f32);
    extern void func_L39_00521FE0(void *);
    extern void func_L01_00404A10(void (*)(void *),void *);
    extern void func_L39_00521BC0();
    extern void func_L39_00622288(void *);
    extern void func_L01_003F2278(s32,void *);
    extern s32 func_L01_003F1FC0(s32,void *);
    Buf_005210A0 a;
    vu0_v4 b;
    Buf_005210A0 c;
    Hit_005210A0 hit;
    vu0_v4 previous,aim;
    P_005210A0 *p=o->pvar;
    Player_005210A0 *player;
    struct Moby *target,*other;
    u8 *target_data;
    void *handle;
    vu0_v4 *direction,*second,*right;
    s32 decoded,colour,charged,status,flag;
    f32 ratio,f,d;
    if ((u8)o->state==0) {
        o->pad_30[0]=0xFF;
        p->sound=-1;
        p->h52=0;
        func_L39_0061C4D0(o,&p->player,o->state=1);
        p->h66=1;
    }
    player=p->player;
    {
        u8 *key=&player->key;
        u8 *dst;
        s32 n,k,m,i;
        if (!*key) decoded=0;
        else {
            n=*key; m=n+1; k=((s32)key-n)&7;
            dst=a.b;
            for (i=0;i<40;i+=5) *dst++=D_L39_004997E0[m+((k+i)&7)*255];
            a.w[0]^=(u32)key;
            a.w[1]^=a.w[0];
            decoded=a.w[1];
        }
    }
    direction=&p->direction;
    second=&p->origin[1];
    right=(vu0_v4 *)&o->matrix[1];
    if (((u32)decoded^1)==0) player->vtable->set(player,0x1D,1,0,1);
    if (o->prev_seq==o->cur_seq && (o->anim_flags&2)) func_L01_00444F38(o,1,0,2,0);
    func_0038D000(&a.v,&D_L39_0024A9A0,o->matrix);
    vec_add_ab(&a.v,&a.v,&o->position);
    p->origin[0]=a.v;
    func_0038D000(&b,&D_L39_0024A9B0,o->matrix);
    vec_add_ab(&b,&b,&o->position);
    p->origin[1]=b;
    func_0038CF68(direction,right,-1.0f);
    target=0;
    if (player->f1310) {
        func_0038CC88(&c.v,(p->h64?second:&p->origin[0]),0x10);
        vec_sub_ab(direction,&player->v12B0,&c.v);
        if (player->f1250>0.8f) {
            flag=func_L39_005FFD20(&player->f1338,&player->f133C,1,150.0f);
            if (player->b1A14) func_L01_003F6F20(player->b24C9,o,flag,0,0x56,-1,4,0.7f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            target=player->target;
        } else {
            flag=func_L39_005FFD20(&player->f1338,&player->f133C,0,150.0f);
            if (player->b1A14) func_L01_003F6F20(player->b24C9,o,flag,0,0x56,-1,4,0.7f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            if (func_0038CE68(direction,right)>0.0f) func_0038CF68(direction,player->camera+0x200,20.0f);
            else func_0038CF68(direction,direction,20.0f);
        }
    } else {
        *direction=player->v3B0;
        func_0038CF68(direction,direction,20.0f);
        target=func_L39_006472D0(player,p,direction,1,0.05235987901687622f,0.05235987901687622f,35.0f,0.7853981852531433f,0.6108652353286743f);
    }
    if (player->b1A08) {
        func_0038CF68(direction,right,-20.0f);
        target=0;
    }
    if (target) {
        p->target_pos=*(vu0_v4 *)&target->position;
        target_data=func_00382348(target);
        if (target_data) {
            func_0038CE20(&c.v,&target->matrix[2],*(f32 *)(target_data+0x10));
            vec_add_ab(&p->target_pos,&p->target_pos,&c.v);
        }
        {
        u8 *key=&player->key;
        u8 *dst;
        s32 n,k,m,i;
        if (!*key) decoded=0;
        else {
            n=*key; m=n+1; k=((s32)key-n)&7;
            dst=c.b;
            for (i=0;i<40;i+=5) *dst++=D_L39_004997E0[m+((k+i)&7)*255];
            c.w[0]^=(u32)key;
            c.w[1]^=c.w[0];
            decoded=c.w[1];
        }
    }
        if (((u32)decoded^0x1D)!=0) {
            ratio=(player->f1250-0.8f)/0.19999998807907104f;
            if (ratio>1.0f) ratio=1.0f;
            else if (ratio<0.0f) ratio=0.0f;
            charged=func_L39_00639D90(player);
            if (charged) colour=func_0038DBD8(0xFF0FFFFF,0xFF0F0FFF,ratio);
            else colour=0xFF0F0FFF;
            f=func_0038CF00(player->camera,&p->target_pos)/150.0f;
            f=fabs_asm(0.9f-f*0.65f);
            if (player->b1A14) func_L01_003F6F20(player->b24C9,o,colour,&p->target_pos,0x26,-1,4,f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            if (target_data) {
                d=func_0038CF00(p,&p->target_pos);
                func_0038CE20(&c.v,&player->v1240,(d/1.4000001f)*0.8f);
                vec_add_ab(&p->target_pos,&p->target_pos,&c.v);
            }
        }
        func_0038CC88(&c.v,(p->h64?second:&p->origin[0]),0x10);
        vec_sub_ba(direction,&p->target_pos,&c.v);
        func_0038CF68(direction,direction,20.0f);
        p->target_id=func_L39_0061D780(target);
        p->target=target;
    } else {
        p->target=0;
        p->target_id=0xFFFFFFFF;
    }
    status=func_L39_006732D0(player->a1A40,0,1,&hit);
    if ((func_L39_00673498(player->a1A40,0) && player->f470>=23) || status==8 || status==4) {
        p->h50=20;
        p->h52++;
        p->counter=0;
        if (status==8) {
            func_L39_00621D60(player,-1);
            o->anim_speed=3.0f;
            if (o->cur_seq!=2) func_003C3A10(o,2,0,0);
            o->anim_speed=3.0f;
            p->h66=1;
            p->sound=func_L01_003F2058(D_L39_004701E0,player->sound);
            other=0;
            if (hit.target_id!=0xFFFFFFFF) {
                handle=func_L39_0061D1D8(hit.target_id);
                if (handle) other=(*(VTable_005210A0 **)((u8 *)handle+0x14))->object(handle);
            }
            func_0038CC88(&previous,(p->h64?second:&p->origin[0]),0x10);
            p->h64=(p->h64==0);
            if (other) {
                aim.x=hit.point[0];aim.y=hit.point[1];aim.z=hit.point[2];aim.w=0.0f;
                vec_add_ba(&aim,&aim,&other->position);
                vec_sub_ab(&c.v,&aim,&previous);
                func_0038CF68(&c.v,&c.v,1.4000001f);
            } else {
                c.v.y=hit.normal[1];c.v.x=hit.normal[0];c.v.z=hit.normal[2];c.v.w=0.0f;
                func_0038CE20(&aim,right,-1.0f);
                func_0038CF68(&c.v,&c.v,1.0f);
                if (func_0038CE68(&c.v,&aim)<0.8659999966621399f) c.v=aim;
                func_0038CE20(&c.v,&c.v,1.4000001f);
            }
            func_L39_005F33E0(3,0,o);
            if (func_003D3CB0(&o->position,&previous,0,(void *)p->player->f424,0)) {
                vec_sub_ba(&aim,&D_L39_0025F760,&o->position);
                f=func_0038CEA8(&aim);
                func_0038CF68(&aim,&aim,f-0.05f);
                vec_add_ab(&previous,&aim,&o->position);
                func_0038CF68(&c.v,right,-1.4000001f);
            }
            if (func_L39_00648AE0(player,1)) flag=*(s8 *)(D_L39_0049C890+0xA1);
            else flag=1;
            func_L39_00533790(o,player,&previous,&c.v,0x10001,1,*(f32 *)(D_L39_0049C890+(flag<<7)+0x30));
            func_L01_00404A10(func_L39_00521FE0,o);
            func_L39_00521BC0(o);
        } else if (status==4 && p->h66==1) {
            func_L39_005F33E0(4,0,o);
            p->h66=0;
        }
    } else {
        p->counter++;
        if (player->f30C>=16 && p->counter>=9) func_L39_00622288(player);
        if (p->counter>=21) p->h66=1;
        if (p->h50<=0) p->h52=0;
    }
    if (status!=8 || !player->b1A07) {
        if (p->sound>=0) {
            func_L01_003F2278(p->sound,player->sound);
            p->sound=-1;
        }
    }
    if (p->sound>0 && !func_L01_003F1FC0(p->sound-1,player->sound)) p->sound=-1;
}
/* localdecomp:end func_L39_005210A0 */
