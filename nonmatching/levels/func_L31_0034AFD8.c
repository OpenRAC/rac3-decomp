/* PAL near miss (Codex wave 7): near miss: 294 words differ with the file's flags.
 * Worker's note: 8 diff e3-12.log with injected divs 0,0,2,0,0,2; only zero-area base v0 vs v1; switch evidence e3-switch.txt; no all-place exact claim
 */
#include "common.h"
/* localdecomp:start func_L31_0034AFD8 */
#include "vu0.h"
typedef struct { u8 pad[16]; } Bytes_0034AFD8;
typedef struct { u8 pad[0x68]; u8 *vars; } Child_0034AFD8;
typedef struct {
    u8 p0[0x30]; f32 progress; s16 duration; u8 p36[0x70-0x36];
    Bytes_0034AFD8 bytes; u8 p80[0xD4-0x80]; s32 timer;
    u8 pD8[0xE8-0xD8]; s32 e8, ec, f0; u8 pF4[8]; s32 handle;
    u8 p100[0x18]; s32 total; u8 p11C[0x154-0x11C]; s32 flag;
    Child_0034AFD8 *child; s32 index; s32 sound;
} Vars_0034AFD8;
typedef struct { u8 p[0xD0]; u8 active; u8 pD1[11]; void *owner; } Slot_0034AFD8;
typedef struct { u8 data[64]; } Row_0034AFD8;
__asm__(".extern D_L31_001DD2A0, 4");
__asm__(".extern D_L31_001DD25C, 4");
__asm__(".extern D_L31_001DD260, 4");
__asm__(".extern D_L31_001DD250, 4");
__asm__(".extern D_L31_001DD254, 4");
__asm__(".extern D_L31_001DD240, 4");
extern s32 D_L31_001DD2A0;
extern f32 D_L31_001DD25C;
extern f32 D_L31_001DD260;
extern f32 D_L31_001E12B4;
extern s32 D_L31_001DD250;
extern s32 D_L31_001DD254;
extern s32 D_L31_001DD240;
extern s32 D_001A71A0[];
extern u8 D_00142732[];
extern u8 D_001426D7[];
extern u8 D_001A6718[];
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern Row_0034AFD8 D_L31_00284110_0034AFD8[];
typedef struct { vu0_q q0; u8 p10[16]; vu0_q q20,q30,q40; u8 p50[32]; vu0_q q70; u8 p80[16]; s32 flag; } Zero_0034AFD8;
extern Zero_0034AFD8 D_001A4CD0;
extern u8 *D_L31_001DF79C_0034AFD8;
void func_L31_0034AFD8(Obj_0034ACA8 *m) {
    extern void func_L31_0034D088(void *);
    extern s32 func_L01_004561B8(void *);
    extern f32 func_003C4088(f32, f32, f32);
    extern void func_L31_0034C5A0(void *, f32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L31_0034CC30(void *);
    extern void func_L01_004AAC98(s32, s32, s32, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void *func_L31_003B3D38(s32, void *, s32, s32, s32, f32, f32);
    extern void func_003A4F28(s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L31_0034BCA8(void *);
    extern void func_L31_0034ACA8(Moby_0034ACA8 *);
    extern void func_L31_0034CB80(void *);
    extern s32 func_00382380(void *, s32, s32);
    extern void func_003C2C98(void *, void *);
    extern void func_L01_0043A430(void *, s32, void *);
    extern void func_L31_0034B580(void *);
    extern void func_L30_004CF4B0(s32, s32);
    extern void func_L31_0034D390(void *, s32);
    extern void func_L01_00456230(void *, s32);
    extern void func_L01_0045F1E8(s32, s32);
    extern void func_L31_0034BF90(void *);
    extern void func_L31_0034CA18(void *);
    Vars_0034AFD8 *v = m->vars;
    Bytes_0034AFD8 bytes;
    s32 params[14];
    s32 i;
    Row_0034AFD8 *row;
    switch(m->state) {
    case 1:
        func_L31_0034D088(m);
        break;
    case 2:
        if(func_L01_004561B8(m)) {
            v->timer = v->total = (s32)(D_L31_001E12B4 / func_003C4088(D_L31_001DD25C, D_L31_001DD260, 1.0f - v->progress / v->duration));
        }
        if(v->timer > v->total) v->timer = v->total;
        func_L31_0034C5A0(m, (f32)(v->total - v->timer) / v->total);
        if(func_0038CAD0(&v->timer)) {
            if(!v->flag) goto finish_action;
            goto cc_action;
        }
        break;
    case 3:
        if(func_L01_004561B8(m)) {
            v->timer = v->total = (s32)(D_L31_001E12B4 / func_003C4088(D_L31_001DD25C, D_L31_001DD260, 1.0f - v->progress / v->duration));
        }
        if(v->timer > v->total) v->timer = v->total;
        func_L31_0034C5A0(m, (f32)(v->total - v->timer) / v->total);
        if(func_0038CAD0(&v->timer)) func_L01_004450F0(m, 1, -1);
        break;
    case 66:
        if(func_L01_004561B8(m)) func_L01_004AAC98(0, 0, D_001A71A0[0], 0x165E);
        if(func_0038CAD0(&v->timer)) {
            u8 *vars=v->child->vars;
            if(vars) vars[0x4B]=1;
            if(!v->flag) D_00142732[0]=1;
cc_action:
            func_L31_0034CC30(m);
        }
        break;
    case 4:
        if(func_L01_004561B8(m)) {
            v->timer=D_L31_001DD250;
            func_L01_004AAC98(3,0,D_001A71A0[0],0x165E);
            if(v->handle==-1 || ((Slot_0034AFD8 *)(D_001A30B0+(v->handle<<7)))->owner!=m || !((Slot_0034AFD8 *)(D_001A30B0+(v->handle<<7)))->active)
                v->handle=func_003A52A0(5,4,m);
            bytes=v->bytes;
            func_L01_0043B9E8(m,bytes.pad[4],bytes.pad[5],bytes.pad[6]);
            { s32 j; for(j=13;j>=0;j--) params[j]=0; }
            params[0]=(s32)m;
            v->child=func_L31_003B3D38(14,params,100,7,5,1.0f,280.0f);
        }
        if(func_0038CAD0(&v->timer)) {
            v->timer=D_L31_001DD254;
            if(v->handle!=-1 && ((Slot_0034AFD8 *)(D_001A30B0+(v->handle<<7)))->owner==m && ((Slot_0034AFD8 *)(D_001A30B0+(v->handle<<7)))->active)
                func_003A4F28(v->handle);
            v->handle=-1;
            func_L01_004450F0(m,66,-1);
        } else {
            func_L31_0034BCA8(m);
            func_L31_0034ACA8((Moby_0034ACA8 *)m);
        }
        break;
    case 0:
        func_L31_0034CB80(m);
        if(D_001426D7[0]&0x10) func_L01_004450F0(m,66,-1);
        else func_L01_004450F0(m,5,-1);
        break;
    case 5:
        if(func_00382380(D_001A4C60,v->f0,0)) {
            for(i=0,row=D_L31_00284110_0034AFD8;i<31;i++,row++) {
                if(row->data[1]) func_003C2C98(m,row);
                func_L01_0043A430(m,i,row);
            }
            if(!v->flag) func_L01_004450F0(m,6,-1);
            else if(((D_001A6718[0] ^ 1) & 1)) {
finish_action:
                func_L31_0034B580(m);
            }
        }
        break;
    case 6:
        if(func_L01_004561B8(m)) {
            func_L30_004CF4B0(0x74,1);
            qzero(&D_001A4CD0.q0);
            qzero(&D_001A4CD0.q20);
            qzero(&D_001A4CD0.q30);
            qzero(&D_001A4CD0.q40);
            qzero(&D_001A4CD0.q70);
            D_001A4CD0.flag=0;
            func_L31_0034D390(m,1);
            func_L01_00456230(D_L31_001DF79C_0034AFD8+(v->e8<<8),1);
            func_L01_00456230(D_L31_001DF79C_0034AFD8+(v->ec<<8),1);
            v->timer=D_L31_001DD240;
            func_L01_0045F1E8(v->sound,-1);
        }
        if(func_0038CAD0(&v->timer)) {
            func_L30_004CF4B0(0x9A,1);
            func_L31_0034B580(m);
        }
        break;
    }
    if(D_L31_001DD2A0) v->timer++;
    if(m->state!=0xFD && m->state!=0xFE && m->state!=0xFF) {
        func_L31_0034BF90(m);
        func_L31_0034CA18(m);
    }
}
/* localdecomp:end func_L31_0034AFD8 */
