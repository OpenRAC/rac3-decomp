/* NTSC-U draft (Codex wave 3): C of func_L39_00520C08, the NTSC-U twin of func_L39_005210A0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 537 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00520C08", whose code is not the PAL one).
 * Worker's note: 537 diff; best log func_L39_00520C08.check05.log; NEEDS divs row 'func_L39_00520C08 2 2 2' (in-memory injection); ten checks, last variants 541/542; stack -0x110 vs -0x120, register/argument/VU scheduling; masked return variant retained as .v07.c (541 diff ...
 */
#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* localdecomp:start func_L39_00520C08 */
typedef struct Player_520C08 Player_520C08;
typedef union { vu0_v4 v; u32 w[4]; u8 b[16]; } Buf_520C08;
typedef struct {
    u8 pad0[0x10];
    struct Moby *(*object)(void *);
    u8 pad14[0x20];
    void (*set)(void *,s32,s32,s32,s32);
} VTable_520C08;
struct Player_520C08 {
    u8 pad0[0x14];
    VTable_520C08 *vtable;
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
    Player_520C08 *player;
    u32 target_id;
    s16 h60,h62,h64,h66;
    s32 f68,counter;
    struct Moby *target;
} P_520C08;
typedef struct {
    u8 pad0[0x2C];
    u32 target_id;
    f32 point[3], normal[3];
    u8 pad48[8];
} Hit_520C08;
extern u8 D_L39_004998A0[];
extern u8 D_L39_004702E0[],D_L39_0049C950[];
extern vu0_v4 D_L39_0025F860;
extern f32 D_001DF220_sda,D_001DF230_sda;
__asm__(".extern D_001DF220_sda, 4");
__asm__(".extern D_001DF230_sda, 4");
extern void func_L39_00619D58(void *,void *,s32);
extern void func_L01_00441E00(void *,s32,s32,s32,s32);
extern void func_003888C8(void *,void *,void *);
extern void func_00388830(void *,void *,f32);
extern void func_003886E8(void *,void *,f32);
extern void func_00388550(void *,void *,s32);
extern s32 func_L39_005FD580(void *,void *,s32,f32);
extern void func_L01_003F4D78(s32,void *,u32,void *,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32);
extern f32 func_00388730(void *,void *);
extern struct Moby *func_L39_00644AA0(void *,void *,void *,s32,f32,f32,f32,f32,f32);
extern u8 *func_0037E0B8(void *);
extern s32 func_L39_00637548(void *);
extern u32 func_003894A0(u32,u32,f32);
extern f32 func_003887C8(void *,void *);
extern u32 func_L39_0061B008(void *);
extern s32 func_L39_00670988(void *,s32,s32,void *);
extern u8 func_L39_00670B50(void *,s32);
extern void func_L39_0061F5C0(void *,s32);
extern void func_003BE4F0(void *,s32,s32,s32);
extern s32 func_L01_003F0118(void *,void *);
extern void *func_L39_0061AA60(u32);
extern void func_L39_005F0CE0(s32,s32,void *);
extern s32 func_003CE740(void *,void *,s32,s32,s32);
extern f32 func_00388770(void *);
extern s32 func_L39_00646268(void *,s32);
extern void func_L39_00533110(void *,void *,void *,void *,s32,s32,f32);
extern void func_L39_00521B48(void *);
extern void func_L01_004026A0(void (*)(void *),void *);
extern void func_L39_00521728(void *);
extern void func_L39_0061FAE8(void *);
extern void func_L01_003F0338(s32,void *);
extern s32 func_L01_003F0080(s32,void *);

void func_L39_00520C08(struct Moby *o) {
    Buf_520C08 a;
    vu0_v4 b;
    Buf_520C08 c;
    Hit_520C08 hit;
    vu0_v4 previous,aim;
    P_520C08 *p=o->pvar;
    Player_520C08 *player;
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
        func_L39_00619D58(o,&p->player,o->state=1);
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
            for (i=0;i<40;i+=5) *dst++=D_L39_004998A0[m+((k+i)&7)*255];
            a.w[0]^=(u32)key;
            a.w[1]^=a.w[0];
            decoded=a.w[1];
        }
    }
    direction=&p->direction;
    second=&p->origin[1];
    right=(vu0_v4 *)&o->matrix[1];
    if (((u32)decoded^1)==0) player->vtable->set(player,0x1D,1,0,1);
    if (o->prev_seq==o->cur_seq && (o->anim_flags&2)) func_L01_00441E00(o,1,0,2,0);
    func_003888C8(&a.v,&D_001DF220_sda,o->matrix);
    vec_add_ab(&a.v,&a.v,&o->position);
    p->origin[0]=a.v;
    func_003888C8(&b,&D_001DF230_sda,o->matrix);
    vec_add_ab(&b,&b,&o->position);
    p->origin[1]=b;
    func_00388830(direction,right,-1.0f);
    target=0;
    if (player->f1310) {
        func_00388550(&c.v,(p->h64?second:&p->origin[0]),0x10);
        vec_sub_ab(direction,&player->v12B0,&c.v);
        if (player->f1250>0.8f) {
            flag=func_L39_005FD580(&player->f1338,&player->f133C,1,150.0f);
            if (player->b1A14) func_L01_003F4D78(player->b24C9,o,flag,0,0x56,-1,4,0.7f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            target=player->target;
        } else {
            flag=func_L39_005FD580(&player->f1338,&player->f133C,0,150.0f);
            if (player->b1A14) func_L01_003F4D78(player->b24C9,o,flag,0,0x56,-1,4,0.7f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            if (func_00388730(direction,right)>0.0f) func_00388830(direction,player->camera+0x200,20.0f);
            else func_00388830(direction,direction,20.0f);
        }
    } else {
        *direction=player->v3B0;
        func_00388830(direction,direction,20.0f);
        target=func_L39_00644AA0(player,p,direction,1,0.05235987901687622f,0.05235987901687622f,35.0f,0.7853981852531433f,0.6108652353286743f);
    }
    if (player->b1A08) {
        func_00388830(direction,right,-20.0f);
        target=0;
    }
    if (target) {
        p->target_pos=*(vu0_v4 *)&target->position;
        target_data=func_0037E0B8(target);
        if (target_data) {
            func_003886E8(&c.v,&target->matrix[2],*(f32 *)(target_data+0x10));
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
            for (i=0;i<40;i+=5) *dst++=D_L39_004998A0[m+((k+i)&7)*255];
            c.w[0]^=(u32)key;
            c.w[1]^=c.w[0];
            decoded=c.w[1];
        }
    }
        if (((u32)decoded^0x1D)!=0) {
            ratio=(player->f1250-0.8f)/0.19999998807907104f;
            if (ratio>1.0f) ratio=1.0f;
            else if (ratio<0.0f) ratio=0.0f;
            charged=func_L39_00637548(player);
            if (charged) colour=func_003894A0(0xFF0FFFFF,0xFF0F0FFF,ratio);
            else colour=0xFF0F0FFF;
            f=func_003887C8(player->camera,&p->target_pos)/150.0f;
            f=fabs_asm(0.9f-f*0.65f);
            if (player->b1A14) func_L01_003F4D78(player->b24C9,o,colour,&p->target_pos,0x26,-1,4,f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            if (target_data) {
                d=func_003887C8(p,&p->target_pos);
                func_003886E8(&c.v,&player->v1240,(d/1.1666667461395264f)*0.8f);
                vec_add_ab(&p->target_pos,&p->target_pos,&c.v);
            }
        }
        func_00388550(&c.v,(p->h64?second:&p->origin[0]),0x10);
        vec_sub_ba(direction,&p->target_pos,&c.v);
        func_00388830(direction,direction,20.0f);
        p->target_id=func_L39_0061B008(target);
        p->target=target;
    } else {
        p->target=0;
        p->target_id=0xFFFFFFFF;
    }
    status=func_L39_00670988(player->a1A40,0,1,&hit);
    if ((func_L39_00670B50(player->a1A40,0) && player->f470>=23) || status==8 || status==4) {
        p->h50=20;
        p->h52++;
        p->counter=0;
        if (status==8) {
            func_L39_0061F5C0(player,-1);
            o->anim_speed=3.0f;
            if (o->cur_seq!=2) func_003BE4F0(o,2,0,0);
            o->anim_speed=3.0f;
            p->h66=1;
            p->sound=func_L01_003F0118(D_L39_004702E0,player->sound);
            other=0;
            if (hit.target_id!=0xFFFFFFFF) {
                handle=func_L39_0061AA60(hit.target_id);
                if (handle) other=(*(VTable_520C08 **)((u8 *)handle+0x14))->object(handle);
            }
            func_00388550(&previous,(p->h64?second:&p->origin[0]),0x10);
            p->h64=(p->h64==0);
            if (other) {
                aim.x=hit.point[0];aim.y=hit.point[1];aim.z=hit.point[2];aim.w=0.0f;
                vec_add_ba(&aim,&aim,&other->position);
                vec_sub_ab(&c.v,&aim,&previous);
                func_00388830(&c.v,&c.v,1.1666667461395264f);
            } else {
                c.v.y=hit.normal[1];c.v.x=hit.normal[0];c.v.z=hit.normal[2];c.v.w=0.0f;
                func_003886E8(&aim,right,-1.0f);
                func_00388830(&c.v,&c.v,1.0f);
                if (func_00388730(&c.v,&aim)<0.8659999966621399f) c.v=aim;
                func_003886E8(&c.v,&c.v,1.1666667461395264f);
            }
            func_L39_005F0CE0(3,0,o);
            if (func_003CE740(&o->position,&previous,0,p->player->f424,0)) {
                vec_sub_ba(&aim,&D_L39_0025F860,&o->position);
                f=func_00388770(&aim);
                func_00388830(&aim,&aim,f-0.05f);
                vec_add_ab(&previous,&aim,&o->position);
                func_00388830(&c.v,right,-1.1666667461395264f);
            }
            if (func_L39_00646268(player,1)) flag=*(s8 *)(D_L39_0049C950+0xA1);
            else flag=1;
            func_L39_00533110(o,player,&previous,&c.v,0x10001,1,*(f32 *)(D_L39_0049C950+(flag<<7)+0x30));
            func_L01_004026A0(func_L39_00521B48,o);
            func_L39_00521728(o);
        } else if (status==4 && p->h66==1) {
            func_L39_005F0CE0(4,0,o);
            p->h66=0;
        }
    } else {
        p->counter++;
        if (player->f30C>=16 && p->counter>=9) func_L39_0061FAE8(player);
        if (p->counter>=21) p->h66=1;
        if (p->h50<=0) p->h52=0;
    }
    if (status!=8 || !player->b1A07) {
        if (p->sound>=0) {
            func_L01_003F0338(p->sound,player->sound);
            p->sound=-1;
        }
    }
    if (p->sound>0 && !func_L01_003F0080(p->sound-1,player->sound)) p->sound=-1;
}
/* localdecomp:end func_L39_00520C08 */
