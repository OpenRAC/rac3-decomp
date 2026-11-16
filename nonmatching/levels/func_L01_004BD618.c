/* NTSC-U draft (Codex wave 3): C of func_L01_004B9A80, the NTSC-U twin of func_L01_004BD618, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 149 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004B9A80", whose code is not the PAL one).
 * Worker's note: 149 diff (improved 232); corrected inverted funds comparison; isolated buy/action ids, cached item pointers and accept/reject layout; remaining pad phi/gp-lui and old-buttons allocation; three later phi/condition forms 247; alias D_001D52FC_004B9A80 = ...
 */
#include "common.h"
/* localdecomp:start func_L01_004B9A80 */
typedef struct { int id; unsigned char type; unsigned char pad5[13]; unsigned char locked,other; } Entry53;
typedef struct {
    unsigned char pad0[0x28]; int sound; unsigned char pad2C[0x24];
    int mode; unsigned char pad54[8]; int f5C; unsigned char pad60[12];
    int scroll; unsigned char pad70[8]; int handle; int f7C; int selected; int active;
    unsigned char f88; unsigned char pad89[3]; int f8C; unsigned char pad90[0xB0];
    Entry53 entries[76]; unsigned char pad730[16]; int count; unsigned char pad744[16];
    int cost; unsigned char f758; unsigned char pad759[3]; int f75C,f760;
} UI53;
typedef struct { unsigned char pad0[0x1C4]; int buttons; } Pad53;
typedef struct { unsigned char enabled; unsigned char pad1[0x37]; unsigned short f38; unsigned char pad3A[0x4A]; unsigned short cost; unsigned char pad86[4]; unsigned short max; unsigned char pad8C[0x64]; } Item53;
extern UI53 D_L01_00244740;
extern unsigned int D_L01_001E0FE0;
__asm__(".extern D_L01_001E0FE0,16");
extern int D_L01_001E100C,D_L01_001E1008;
__asm__(".extern D_L01_001E100C,16");
__asm__(".extern D_L01_001E1008,16");
extern int D_001E1010_sda;
extern Pad53 *D_001D52FC_sda;
extern Pad53 *D_001D52FC_004B9A80;
__asm__(".extern D_001D52FC_004B9A80,16");
extern int D_001DABE0_sda;
extern int D_001D545C_sda;
extern int D_00142660[];
extern unsigned char D_001425C0[];
extern int D_001427F0[];
extern unsigned char D_00142CA0[];
extern Item53 D_L01_002C5640[];
extern int D_001DAC18_sda;
extern unsigned char D_001DAC1C_sda;
extern void func_0039FE80(int,int,int);
extern void func_0038ED78(int,int);
extern int func_L01_004B6C98(void);
extern void func_L01_004B95D8(void);
extern void func_L01_00477F48(int,int);
extern void func_L01_00477FD0(int,int);
extern void func_L01_00478168(int);
void func_L01_004B9A80(void) {
    int changed,changed2;
    int repeat;
    int id,buyId,actionId;
    Item53 *purchase,*display;
    Pad53 *upPad,*acceptPad,*confirm;
    int oldbuttons;

    if (!D_L01_00244740.active && D_L01_001E0FE0<2) {
        if (!(D_001D52FC_sda->buttons&0x2000)) {
            repeat=D_L01_001E100C;
            if(repeat<16 || repeat%10!=1) goto load_up_pad;
        }
        if(D_L01_00244740.scroll>=57) goto load_up_pad;
        changed=0;
        if(D_L01_00244740.selected<D_L01_00244740.count-1) {D_L01_00244740.selected++;changed=1;}
        if(!changed)goto load_up_pad;
        if(D_L01_00244740.f88) {D_L01_00244740.f8C=1;D_001DABE0_sda=5;}
        D_L01_00244740.scroll+=56;func_0039FE80(1,17,D_L01_00244740.sound);
        if(D_L01_00244740.handle!=-1 && !D_L01_00244740.mode)func_0038ED78(D_L01_00244740.handle,0);
        D_L01_00244740.handle=-1;
        upPad=D_001D52FC_004B9A80;
        goto up_test;
load_up_pad:
        upPad=D_001D52FC_sda;
up_test:
        if (!(upPad->buttons&0x8000)) {
            repeat=D_L01_001E1008;
            if(repeat<16 || repeat%10!=1)goto load_accept_pad;
        }
        if(D_L01_00244740.scroll < -56)goto load_accept_pad;
        changed2=0;
        if(D_L01_00244740.selected>0) {D_L01_00244740.selected--;changed2=1;}
        if(!changed2)goto load_accept_pad;
        if(D_L01_00244740.f88)D_L01_00244740.f8C=1;
        D_L01_00244740.scroll-=56;func_0039FE80(1,17,D_L01_00244740.sound);
        if(D_L01_00244740.handle!=-1 && !D_L01_00244740.mode)func_0038ED78(D_L01_00244740.handle,0);
        D_L01_00244740.handle=-1;
        acceptPad=D_001D52FC_004B9A80;
        goto accept_test;
load_accept_pad:
        acceptPad=D_001D52FC_sda;
accept_test:
        if(acceptPad->buttons&0x40) {
            oldbuttons=D_001E1010_sda;
            confirm=D_001D52FC_sda;
            if(!(oldbuttons&0x40)) {
                if(D_L01_00244740.mode!=3 && D_L01_00244740.mode!=5)goto validate;
                confirm=D_001D52FC_004B9A80;
            }
            if(!(confirm->buttons&0x40) || (oldbuttons&0x40))goto after_accept;
            if(D_L01_00244740.mode!=3 && D_L01_00244740.mode!=5)goto after_accept;
            if(!*(int *)((unsigned char *)&D_L01_00244740+0x144+(D_L01_00244740.selected<<4)))goto after_accept;
validate:
            if(D_L01_00244740.mode!=0)goto accept;
            if(!D_L01_00244740.entries[D_L01_00244740.selected].locked) {
                if(!D_L01_00244740.entries[D_L01_00244740.selected].type && D_00142660[0]>=func_L01_004B6C98())goto accept;
                if(D_L01_00244740.entries[D_L01_00244740.selected].type==1) {
                    buyId=D_L01_00244740.entries[D_L01_00244740.selected].id;
                    purchase=(Item53 *)((unsigned char *)D_L01_002C5640+D_001425C0[buyId]*sizeof(Item53));
                    if(D_001427F0[buyId]<purchase->max && D_00142660[0]>=purchase->cost)goto accept;
                }
            }
            if(D_L01_00244740.entries[D_L01_00244740.selected].locked!=1 || !D_L01_00244740.cost || D_00142660[0]<D_L01_00244740.cost)goto reject;
accept:
            D_L01_00244740.active=1;
            if(D_L01_00244740.mode==3 || D_L01_00244740.mode==5)func_0039FE80(0,17,D_L01_00244740.sound);
            goto after_accept;
reject:
            func_0039FE80(2,17,D_L01_00244740.sound);
        }
after_accept:
        if (D_001D545C_sda==3 && !D_L01_00244740.f5C && !D_L01_00244740.entries[D_L01_00244740.selected].locked && !D_L01_00244740.entries[D_L01_00244740.selected].other) {
            actionId=D_L01_00244740.entries[D_L01_00244740.selected].id;
            if (actionId!=103) {
                if (actionId!=22 && !D_L01_00244740.mode && (D_001D52FC_sda->buttons&0x80)) {
                    D_L01_00244740.f758=1;D_L01_00244740.f760=D_L01_00244740.entries[D_L01_00244740.selected].id;D_L01_00244740.f75C=D_L01_00244740.entries[D_L01_00244740.selected].id;
                    if (D_001DAC18_sda) D_001DAC1C_sda=1;
                    D_001DAC18_sda=0;func_L01_004B95D8();
                }
            }
        }
        if (D_001D52FC_sda->buttons&0x10) func_L01_004B95D8();
    }
    if (D_L01_00244740.entries[D_L01_00244740.selected].type==1) {
        id=D_L01_00244740.entries[D_L01_00244740.selected].id;
        display=(Item53 *)((unsigned char *)D_L01_002C5640+D_001425C0[id]*sizeof(Item53));
        if (display->enabled && D_00142CA0[id]) {
            func_L01_00477F48(display->f38,0);
            func_L01_00477FD0(D_001427F0[id],D_L01_002C5640[D_001425C0[id]].max);
            func_L01_00478168(id);
        }
    }
}
/* localdecomp:end func_L01_004B9A80 */
