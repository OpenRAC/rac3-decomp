/* NTSC-U draft (2026-11-14, Codex worker): C of func_L30_00341478, the NTSC-U twin of func_L30_003420E0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 10 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_00341478 */
typedef struct {
    float time;
    s16 duration;
    u8 pad6[0xE];
    u8 power;
    u8 pad15[0x37];
    s16 anim, frames;
    vu0_v4 saved, velocity;
    float width, height, range, radius;
    int mode;
    int flags;
} State341478;
extern int D_001DCE64_sda;
__asm__(".extern D_001DCE64_sda, 4");
extern s16 D_001DCE70_sda;
extern float D_001DCE78_sda;
__asm__(".extern D_001DCE78_sda, 4");
__asm__(".extern D_001DCE70_sda, 2");
extern float D_001A4C60;
__asm__(".extern D_001A4C60, 16");
extern u8 D_L30_001D66B0;
__asm__(".extern D_L30_001D66B0, 16");
extern int func_L01_00452EC8(void *);
extern void func_0039FE80(int,int,void *),func_003BD360(void *);
extern void func_L01_004A6DF8(void *,int),func_L01_00441FB8(void *,int,int);
extern int func_L30_0034C9F8(void *,float);
extern void func_003BE4F0(void *,int,int,int);
extern void func_L30_00341B30(void *),func_L30_00341D40(void *),func_L30_00341938(void *);
extern int func_L30_00341CB8(void *);
extern float func_003887C8(void *,void *);
extern void func_L30_0034BC88(void *,void *,int,int,int,int,float,float);
extern void func_L01_0032FE90(void *,int,int,int,int,int,int,int,float,float,float,float,
    int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);

void func_L30_00341478(u8 *o) {
    State341478 *p=*(State341478 **)(o+0x68);
    switch(o[0x20]) {
    case 66:
        if(func_L01_00452EC8(o)) {
            *(vu0_v4 *)(o+0x10)=p->saved;
            func_0039FE80(2,0,o);
            p->flags&=~4;
            if((p->flags&2)||(((u8)p->flags^1)&1)) {
                func_003BD360(o);
                return;
            }
            *(u32 *)(o+0x98)=0;
            *(u16 *)(o+0x34)=(*(u16 *)(o+0x34)|0x41)&0xEFFF;
            func_L01_004A6DF8(o,1);
        }
        if(func_L30_0034C9F8(o+0x10,1.5f)) {
            if(p->flags&1) if(p->flags&4) {
                u8 *data=*(u8 **)(o+0x24);
                *(u16 *)(o+0x34)&=0xFFBE;
                *(u16 *)(o+0x34)|=(*(u16 *)(data+0x44)&0x1000);
                *(int *)(o+0x98)=*(int *)(data+0x10);
                func_L01_00441FB8(o,0,-1);
            }
        }else p->flags|=4;
        break;
    case 1:
        if(func_L01_00452EC8(o)&&o[0x43]!=1)func_003BE4F0(o,1,0,D_001DCE64_sda);
        func_L30_00341B30(o);
        if(func_L30_00341CB8(o)) {
            func_L30_00341D40(o);
            func_L01_00441FB8(o,3,-1);
        }
        break;
    case 2:
        if(func_L01_00452EC8(o)&&o[0x43]!=5)func_003BE4F0(o,5,0,D_001DCE64_sda);
        if(fabs_asm(D_001A4C60-*(float *)(o+0x10))<=p->range)func_L01_00441FB8(o,1,-1);
        break;
    case 0:
        if(p->duration<=0)p->duration=D_001DCE70_sda;
        p->anim=4;
        p->frames=15;
        p->time=(float)p->duration;
        p->saved=*(vu0_v4 *)(o+0x10);
        p->width=(*(float *)(o+0x2C)*1.6f)/(*(float *)(*(u8 **)(o+0x24)+0x24));
        p->height=(*(float *)(o+0x2C)*1.6f)/(*(float *)(*(u8 **)(o+0x24)+0x24));
        p->mode=0;
        if(p->flags&2)func_L01_00441FB8(o,5,-1);
        else {
            qzero(&p->velocity);
            func_L01_00441FB8(o,2,-1);
        }
        break;
    case 3:
        if(func_L01_00452EC8(o)&&o[0x43]!=2)func_003BE4F0(o,2,0,D_001DCE64_sda);
        if(o[0x60]&2)func_L01_00441FB8(o,4,-1);
        break;
    case 4:
        if(func_L01_00452EC8(o)&&o[0x43]!=4)func_003BE4F0(o,4,0,D_001DCE64_sda);
        { float x=p->velocity.x,y;
        if(*(float *)(o+0x10)>D_001A4C60)y=x-D_001DCE78_sda;
        else y=x+D_001DCE78_sda;
        func_L30_00341B30((p->velocity.x=y,o)); }
        if(func_003887C8(&D_001A4C60,o+0x10)<p->radius) {
            func_L30_0034BC88(o,&D_L30_001D66B0,1,-1,0,0,(float)p->power,p->radius*1.5f);
            func_L01_0032FE90(o+0x10,0,25,20,20,20,45,1,p->radius/3.0f,1.0f,0.0f,0.0f,
                1,1,0,0,1,1,0,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
            func_L01_00441FB8(o,66,-1);
        }
        break;
    case 5:
        func_L01_00452EC8(o);
        func_L01_00441FB8(o,1,-1);
        break;
    }
    func_L30_00341938(o);
}
/* localdecomp:end func_L30_00341478 */
