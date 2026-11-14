/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_006A12A0, the NTSC-U twin of func_L39_006A3AB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/39_multiplayer_menu/L39_006A3A80.c's current line.
 * Worker's note: 607 diff; default assembler emits .lit4 loads instead of retail inline float literals (Matching-Patterns assembler section); remaining virtual-call register allocation/control flow differs; no unlisted flags tried; best log func_L39_006A12A0.check02.log
 */
#include "common.h"
/* localdecomp:start func_L39_006A12A0 */
typedef struct Obj Obj;
typedef struct Vtab { char pad[0x20]; int (*f20)(); int (*f24)(); char p28[0x18]; int (*f40)(); char p44[0x34]; int (*f78)(); int (*f7c)(); int (*f80)(); int (*f84)(); int (*f88)(); int (*f8c)(); char p90[12]; int (*f9c)(); int (*fa0)(); int (*fa4)(); int (*fa8)(); int (*fac)(); } Vtab;
struct Obj { char pad[0x60]; Vtab *vt; };
typedef struct Menu { char p0[0x110]; Obj *items[21]; Obj *a164; Obj *a168; Obj *a16c; char p170[0x120]; int state; char p294[0x14]; int a2a8,a2ac,a2b0,a2b4; void *a2b8; int a2bc,a2c0; char p2c4[12]; int a2d0[8]; char p2f0[0x24]; int a314; int a318,a31c,a320,a324,a328,a32c; unsigned char a330; char p331[3]; int a334,a338; unsigned char a33c,a33d,a33e,a33f; } Menu;
extern Menu *D_001DC1E4_sda;
extern Menu *D_L39_00247A74[];
extern int D_001A6130[];
extern char D_001A5E50[];
extern void *D_L39_0024D860;
extern char D_L39_002487E8[],D_L39_002488D8[];
extern void func_L39_006A1D00(Menu *,int);
extern char *func_0037DF98(int);
extern int func_L39_00688350(Menu *,int);
extern void func_L39_006847C8(Menu *,char *,void *,int,int,float);
extern void func_L39_00685798(int,int,int);
extern void func_L39_00688750(Menu *,int,int);
extern void func_L39_005EF018(void);
extern int func_L39_006D7B28(void *,int,int);
extern void func_L39_006C9630(void *),func_L39_006C9A08(void *,void *),func_L39_006C9668(void *,int);
extern int func_L39_006C9860(void *,int);
extern void func_L39_00684930(Menu *,char *,void *,int,int,int,int);
extern int func_L39_006D0D50(void *,int,void *,int,int,int);
extern void func_L39_006B2920(void *,int,int);
extern void func_L39_00684B20(Menu *,int,int,int,int,int,int,void *,int,int,int,int,int);
extern void func_L39_00687358(Menu *,int,int,int,float,float,float,float,float,float);
extern void func_L39_00687728(Menu *,int,int,int,float,float);
extern int func_L39_005C2100(void);
extern void func_L39_006A28E8(Menu *);
int func_L39_006A12A0(Menu *p,int event) {
    char text[16]; char text2[16]; char storage[0x1e0];
    float x,y,w,h; void *manager,*server,*client; int mode,changed,ok;
    func_L39_006A1D00(p,event==6 || (p->state==23 && event==7));
    if (!p->a2b8 || *(int *)((char *)p->a2b8+0x30)==0) {
        if(D_001A6130[0]<10) func_L39_006847C8(D_001DC1E4_sda,func_0037DF98(0x131f),D_L39_002487E8,4,0,0.6f);
        *(int *)((char *)D_L39_00247A74[0]+0x284)=44; return 1;
    }
    if(func_L39_00688350(p,event)==1) return 1;
    if(event==2) {
        func_L39_00685798(3,0,0);
        if(p->state==20) func_L39_00688750(p,22,0);
        else if(p->state==22) func_L39_00688750(p,23,0);
        else if(p->state==23) func_L39_00688750(p,20,0);
        return 1;
    }
    if(event==1) {
        func_L39_00685798(3,0,0);
        if(p->state==20) func_L39_00688750(p,23,0);
        else if(p->state==22) func_L39_00688750(p,20,0);
        else if(p->state==23) func_L39_00688750(p,22,0);
        return 1;
    }
    if((unsigned)(event-3)<2) {
        func_L39_00685798(3,0,0);
        if(p->state==19) func_L39_00688750(p,p->a314,0);
        else { p->a314=p->state; func_L39_00688750(p,19,0); }
        return 1;
    }
    if(event==7) {
        func_L39_00685798(4,0,0); func_L39_005EF018();
        if(p->state==20 && p->a2bc) {
            p->a164->vt->f80(p->a164,1); p->a164->vt->f20(p->a164,3,0);
            func_L39_00688750(p,21,0); p->a164->vt->f84(p->a164,1); p->a164->vt->f88(p->a164,0); return 1;
        }
        if(p->state==23) {
            manager=D_L39_0024D860; server=*(void **)((char *)manager+0x3c); client=*(void **)((char *)manager+0x4c);
            p->a16c->vt->f24(p->a16c,func_0037DF98(0x1184)); p->a16c->vt->f40(p->a16c,1);
            if(p->a2b0==-1 || (*(int *)client==p->a2b0 ? 1 : func_L39_006D7B28(client,p->a2b0,0))) {
                mode=p->a168->vt->fac(p->a168); changed=0; text2[0]=0; text[0]=0;
                if(p->a2b8) {
                    func_L39_006C9630(storage); func_L39_006C9A08(storage,p->a2b8);
                    if(func_L39_006C9860(storage,12)==2) changed=**(int **)((char *)manager+0x38)!=func_L39_006C9860(storage,13);
                    func_L39_006C9668(storage,2);
                }
                if(p->a2ac==1) func_L39_00684930(D_L39_00247A74[0],func_0037DF98(0x1183),text,0,17,1,0);
                D_001A5E50[0xaa]=mode>=2;
                if(func_L39_006D0D50(server,p->a2a8,text,mode,changed,p->a2b4)) { *(int *)((char *)D_001DC1E4_sda+0x284)=33; return 1; }
                if(*(int *)(D_001A5E50+0x634)==1 || p->a2bc==p->a2c0) func_L39_006847C8(D_001DC1E4_sda,func_0037DF98(0x12f5),D_L39_002487E8,4,0,0.6f);
                else if(*(int *)(D_001A5E50+0x634)==3) func_L39_006847C8(D_L39_00247A74[0],func_0037DF98(0x12f6),D_L39_002487E8,4,0,0.6f);
                else if(p->a2ac==1) func_L39_006847C8(D_001DC1E4_sda,func_0037DF98(0x18c3),D_L39_002487E8,4,0,0.6f);
                else func_L39_006847C8(D_001DC1E4_sda,func_0037DF98(0x1fcf),D_L39_002488D8,4,0,0.6f);
            } else func_L39_006847C8(D_001DC1E4_sda,func_0037DF98(0x1326),D_L39_002488D8,4,0,0.6f);
            p->a16c->vt->f24(p->a16c,func_0037DF98(0xf8c)); p->a16c->vt->f40(p->a16c,0); return 1;
        }
        if(p->state==21) {
            int index=p->a164->vt->f8c(p->a164);
            if((unsigned)index<8 && *(void **)((char *)D_001DC1E4_sda+0xd0)) {
                func_L39_006B2920(*(void **)((char *)D_001DC1E4_sda+0xd0),p->a2d0[index],0);
                *(int *)((char *)D_L39_00247A74[0]+0x284)=27;
            } return 1;
        }
        if(p->state==19) { func_L39_00684B20(D_L39_00247A74[0],p->a320,p->a324,p->a328,p->a330,p->a32c,p->a334,&p->a318,p->a33c,p->a33d,p->a33e,p->a33f,p->a338!=0); return 1; }
    }
    if(event==5) {
        if(p->state==21) { p->a164->vt->f80(p->a164,0); p->a164->vt->f20(p->a164,2,0); func_L39_00688750(p,20,0); return 1; }
    } else if(p->state==21) {
        p->a164->vt->f9c(p->a164,&x,&y); p->items[p->state]->vt->fa0(p->items[p->state],&w,&h); ok=3;
        func_L39_00687358(p,0,3,3,x+w*0.5f,y,w*1.228f,h,0.004f,1.225f);
        mode=p->items[p->state]->vt->f8c(p->items[p->state]); changed=p->items[p->state]->vt->f78(p->items[p->state]);
        if(!mode) { ok=2; if(changed==1) ok=0; }
        else if(mode==p->items[p->state]->vt->f78(p->items[p->state])-1) ok=1;
        func_L39_00687728(p,ok,3,3,x+w*0.5f+0.033f,y); goto done;
    }
    if(p->state==20) {x=0.489f; y=0.334f; w=0.37f; h=0.04f;}
    else if(p->state==22) {w=0.37f; h=0.0378f; x=0.49f; y=0.791f;}
    else if(p->state==23) {w=0.37f; h=0.035f; x=0.49f; y=0.837f;}
    else if(p->state==19) {w=0.37f; h=0.0425f; x=0.076f; y=0.831f;}
    func_L39_00687358(p,0,3,3,x,y,w,h,0.1f,0.1f);
    func_L39_00687728(p,0,1,3,x+0.033f,y);
done:
    if(p->a168->vt->fac(p->a168)==2 && func_L39_005C2100()==1) p->a168->vt->fa8(p->a168,1);
    func_L39_006A28E8(p); return 0;
}
/* localdecomp:end func_L39_006A12A0 */
