/* NTSC-U draft (Codex wave 3): C of func_L01_0033A5C0, the NTSC-U twin of func_L01_0033AC78, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 480 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0033A5C0", whose code is not the PAL one).
 * Worker's note: 480 diff; best log w143/func_L01_0033A5C0.01.log; inherited best draft verified once with permitted flags; GNU emits .lit4 load for 0.1f versus retail lui/ori/mtc1, documented Matching-Patterns Floats mismatch needs unlisted @ps2as (not tried); also ...
 */
#include "common.h"
/* localdecomp:start func_L01_0033A5C0 */
typedef unsigned long U64;
typedef int Q __attribute__((mode(TI)));
extern int D_001D545C_sda;
extern int D_L01_001DFBC0[];
typedef struct { u8 pad[0x28c]; u8 *p28c; u8 *p290; u8 p294[0x35c - 0x294]; u8 *p35c; u8 p360[0x36e - 0x360]; s16 s36e; u8 p370[0x538 - 0x370]; u8 *p538; u8 p53c[0x25c0 - 0x53c]; u8 *p25c0; u8 p25c4[8]; s32 i25cc; } Hero;
extern Hero D_001A4BE0[];
extern int D_001A5E08[];
extern int D_001A71AC[];
extern u8 D_L01_001EEB00[];
extern void func_003BD360(void *);
extern void func_L01_0033AE40(void *);
extern int func_L01_00448E90(void *);
extern float func_00388730(void *,void *);
extern void func_L01_0033C4D0(void *);
extern u8 *func_L01_00444358(void *,int,int);
extern int func_L01_00452EC8(void *);
extern void func_L01_0033BE30(void *,int,void *);
extern void func_L01_0033B940(void *);
extern float func_0037E250(float,float);
extern void func_00388830(void *,void *,float);
extern int func_003CF790(void *,int,void *,void *,float);
extern void func_L01_004445E0(void *,void *,void *,int,int,int,int,int,int,float,float,float);
extern void func_L01_004A6DF8(void *,int);
extern int func_0037E208(int,int);
extern void func_L01_0033CA98(void *,int);
extern int func_003894E8(void *,float);
extern int func_L01_0040BAF0(void *);
extern void func_L01_00441FB8(void *,int,int);
extern void func_L01_00442B10(void *,int,int,int);
extern void func_L01_00442BF8(void *,void *,int,int);
extern float func_00388800(void *,void *);
extern float func_003BE7F0(void *,int,int,float);
extern void func_0039FE80(int,int,void *);
extern void func_L01_00438908(void *,int,int,int);
void func_L01_0033A5C0(u8 *m) {
    struct { Q v; u8 *m; int flags; int unused; float f; int zero; } hit;
    Q pos;
    u8 *other;
    u8 *p = (*(u8 * *)((u8 *)(m)+0x68));
    u8 *h;

    int special;
    int ok;
    int effect;
    float f;
    if ((*(s16 *)((u8 *)(m)+0xaa))==0x1fa) {func_003BD360(m);return;}
    if (((*(u16 *)((u8 *)(m)+0x34))&0x80) && D_001D545C_sda==4)return;
    if (!m[0x20])func_L01_0033AE40(m);
    if (!func_L01_00448E90(m+0x10))return;
    h=p+0x30;
    if (((*(s32 *)((u8 *)(p)+0xdc))&12) && (*(s32 *)((u8 *)(p)+0xe4))!=D_L01_001DFBC0[0] || func_00388730(p+0xc0,p+0xc0)>0.0f)func_L01_0033C4D0(m);
    if (!(*(u8 * *)((u8 *)(p)+0xd0)))(*(u16 *)(h+0x1e))|=1;
    h=func_L01_00444358(m,0xb030001,0);special=0;
    if(h && (*(s32 *)((u8 *)(h)+0x24))==0x2000000){h=0;special=1;}
    switch(m[0x20]) {
    case 1:
        if(func_L01_00452EC8(m))(*(s32 *)((u8 *)(p)+0x130))=0;
        if((*(s16 *)((u8 *)(m)+0xaa))==0x1f9 && (D_001A4BE0[0].p290==m || D_001A4BE0[0].p28c==m || (D_001A4BE0[0].p35c==m && !D_001A4BE0[0].s36e) || D_001A4BE0[0].p538==m || special)) {
            if(D_001A4BE0[0].i25cc==15){func_L01_0033BE30(m,1,0);func_L01_0033B940(m);return;}
            m[0xbc]=0;m[0x20]=5;return;
        }
        if(!h || !((*(float *)((u8 *)(h)+0x2c))>0.0f))return;
        ok=1;
        if((*(s16 *)((u8 *)(m)+0xaa))==0x1f6 && !((*(s32 *)((u8 *)(h)+0x24))&0x20000) && (*(s16 *)((u8 *)((*(u8 * *)((u8 *)(h)+0x20)))+0xaa))!=0x1f9)ok=0;
        if((*(s16 *)((u8 *)(m)+0xaa))==0x1f9){
            m[0x20]=5;
            if((*(s32 *)((u8 *)(h)+0x24))&0x20000)m[0xbc]=1;
            else m[0xbc]=(int)func_0037E250(5.0f,15.0f);
            (*(U64 *)((u8 *)(p)+0xe8))=(*(U64 *)((u8 *)(m)+0x38));ok=0;
        }
        if(ok){
            if((*(s16 *)((u8 *)(m)+0xaa))==0x1f8){
                if(!(*(u8 * *)((u8 *)(h)+0x20)) || ((*(s16 *)((u8 *)((*(u8 * *)((u8 *)(h)+0x20)))+0xaa))!=71 && (*(s16 *)((u8 *)((*(u8 * *)((u8 *)(h)+0x20)))+0xaa))!=0) || D_001A5E08[0]!=9)break;
                func_L01_0033BE30(m,0,h);func_L01_0033B940(m);
            }else {func_L01_0033BE30(m,(*(s16 *)((u8 *)(m)+0xaa))==0x1f9,h);func_L01_0033B940(m);}
        }
        break;
    case 2:
        if(--m[0xbc]==255){m[0xa8]=255;m[0x20]=1;}return;
    case 3:
        if((*(s16 *)((u8 *)(m)+0xaa))==0x1f9 && p[0xfa]<21){
            hit.v=(*(Q *)((u8 *)(m)+0xc0));hit.f=2.0f;hit.m=m;hit.zero=0;
            func_00388830(&pos,m+0xe0,0.5f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(pos),"m"((*(Q *)((u8 *)(m)+0x10))) : "vf1","vf2");
            hit.flags=0x30001;f=(float)p[0xfa]/20.0f;
            func_003CF790(&pos,16,m,&hit,f+f);
            hit.flags=0x30000;
            effect=func_003CF790(&pos,16,D_001A4BE0[0].p25c0,0,f*3.0f);
            if(effect)func_L01_004445E0(m,&pos,D_L01_001EEB00,effect,(int)D_001A4BE0[0].p25c0,0x10000,0,0x30000,-1,4.0f,1.0f,1.0f);
            ++p[0xfa];break;
        }
        if(p[0xf8]){
            (*(s32 *)((u8 *)(m)+0x98))=0;(*(u16 *)((u8 *)(m)+0x34))=((*(u16 *)((u8 *)(m)+0x34))|0x41)&0xefff;
            func_L01_004A6DF8(m,1);
            if((*(s16 *)((u8 *)(m)+0xb4))>=2)(*(s16 *)((u8 *)(m)+0xb4))=1;
            m[0x20]=6;
            if(p[0xf9]!=255)p[0xf9]=func_0037E208(30,60);
        }else {func_L01_0033CA98(m,1);return;}
        break;
    case 6:
        ++(*(s32 *)((u8 *)(p)+0x130));
        if(p[0xf9]==255)return;
        hit.v=(*(Q *)((u8 *)(m)+0x10));(*(float *)((u8 *)(&hit)+8))+=0.5f;(*(float *)((u8 *)(&hit)+12))=1.0f;
        if(func_003894E8(&hit,(float)(*(s16 *)((u8 *)(m)+0x32)))!=-1 || !func_L01_0040BAF0(p+0xf9))break;
        m[0x7f]=0;
        if(m[0x21]==255){
            func_L01_00441FB8(m,1,-1);
            (*(u16 *)((u8 *)(m)+0x34))&=0xffbe;
            (*(u16 *)((u8 *)(m)+0x34))|=(*(u16 *)((u8 *)((*(u8 * *)((u8 *)(m)+0x24)))+0x44))&0x1000;
            (*(s32 *)((u8 *)(m)+0x98))=(*(s32 *)((u8 *)((*(u8 * *)((u8 *)(m)+0x24)))+0x10));return;
        }
        func_L01_00442B10(&other,m[0x21],0,0);
        while(other){
            if(other!=m && func_00388800(m+0x10,other+0x10)<=0.1f && other[0x20]==1 && !(*(u8 * *)((u8 *)((*(u8 * *)((u8 *)(other)+0x68)))+0xd0))){
                (*(Q *)((u8 *)(m)+0x10))=(*(Q *)((u8 *)(other)+0x10));(*(float *)((u8 *)(m)+0x18))+=1.0f;
                (*(u8 * *)((u8 *)((*(u8 * *)((u8 *)(other)+0x68)))+0xd0))=m;
                (*(u8 * *)((u8 *)(p)+0xd0))=0;(*(u8 * *)((u8 *)(p)+0xd4))=other;
                m[0x31]=1;m[0x20]=1;(*(u16 *)((u8 *)(m)+0x34))&=0xfffe;
                (*(s32 *)((u8 *)(m)+0x98))=(*(s32 *)((u8 *)((*(u8 * *)((u8 *)(m)+0x24)))+0x10));(*(u16 *)((u8 *)(m)+0x34))|=0x1000;
                break;
            }
            func_L01_00442BF8(&other,other,0,0);
        }
        if(m[0x20]!=1){
            (*(float *)((u8 *)(m)+0x18))=func_003BE7F0(m+0x10,0,0,0.5f);
            m[0x20]=1;(*(s32 *)((u8 *)(p)+0xd4))=0;(*(s32 *)((u8 *)(p)+0xd0))=0;m[0x31]=1;
            (*(u16 *)((u8 *)(m)+0x34))&=0xfffe;(*(s32 *)((u8 *)(m)+0x98))=(*(s32 *)((u8 *)((*(u8 * *)((u8 *)(m)+0x24)))+0x10));
        }
        break;
    case 5:
        if(!m[0xbc]){m[0xbc]=179;(*(U64 *)((u8 *)(p)+0xe8))=(*(U64 *)((u8 *)(m)+0x38));}
        else if(m[0xbc]>=16 && h)m[0xbc]=(int)func_0037E250(5.0f,15.0f);
        if(m[0xbc]%60==57 || m[0xbc]==13)func_0039FE80(1,32,m);
        if(m[0xbc]%60>=41 || m[0xbc]<15)func_L01_00438908(m,200,64,64);
        else (*(U64 *)((u8 *)(m)+0x38))=(*(U64 *)((u8 *)(p)+0xe8));
        if(m[0xbc]==1 || D_001A71AC[0]==22){(*(U64 *)((u8 *)(m)+0x38))=(*(U64 *)((u8 *)(p)+0xe8));func_L01_0033BE30(m,1,0);func_L01_0033B940(m);}
        m[0xa8]=255;--m[0xbc];return;
    case 4:
        if(func_L01_0040BAF0(m+0xbc)){m[0x20]=1;(*(u16 *)((u8 *)(m)+0x34))&=0xfffe;}
        break;
    default:return;
    }
    m[0xa8]=255;
}
/* localdecomp:end func_L01_0033A5C0 */
