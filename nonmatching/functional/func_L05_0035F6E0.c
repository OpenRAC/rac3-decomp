/* functional: high. Existing PAL reconstruction verified line by line against the PAL asm (switch cases 0-8, trailer, all callee names/arg order, constants, delay-slot orders). One bug fixed: after the case-4 sweep step retail clamps s+0xB0 to +1.0 or -1.0 (reuses the compared constant) while the draft always wrote -1.0. 500 diffs vs bytes (regalloc/scheduling only). */
#include "vu0.h"
typedef struct { u8 pad[0x80]; s32 nodes[4]; } State_35F6E0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[],D_001C5290[],D_001A4C60[];
extern u8 *D_001A4F3C;
extern u8 *D_L05_002208AC;
extern s32 *D_L05_0021ED80[];
extern f32 D_L05_002F4170[];
extern s32 func_L05_00360070(void *,s32);
extern void func_L05_003601F0(void *);
extern u8 *func_L05_003602D0(void *,void *);
extern void func_L05_00360730(void *);
extern void func_L05_00360448(void *);
extern void func_L01_00404A10(void (*)(void *),void *);
extern void func_L01_00456C98(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32);
extern s32 func_L01_004AAC98(s32,s32,void *,s32);
extern s32 func_00382380(void *,s32,s32);
extern f32 func_0038CF00(void *,void *);
extern void func_L03_004657D0(s32,s32,void *,void *,s32,f32);
extern s32 func_L01_004561B8(void *);
extern void func_003CA4A0(void *,s32,s32 *,void *);
extern void func_0038CE20(void *,void *,f32);
extern void func_0038D000(void *,void *,void *);
extern void func_0038CE90(void *,void *,void *);
extern s32 func_00382468(s32);
extern f32 func_0038D160(f32,f32);
extern u8 *func_L01_00470150(void *,void *,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32);
extern s32 func_L01_0041A4F0(void);
extern u8 *func_L05_00362148(u8 *,vu0_v4 *,vu0_v4 *,s32,s32,u8,f32);
extern void func_L01_004AA7E8(void *,s32,s32);
void func_L05_0035F6E0(u8 *obj) {
    vu0_v4 a,mat[4],b,c;
    s32 bone;
    u8 *s=*(u8 **)(obj+0x68),*p,*q;
    s32 i,j,rate,level,variant;
    s32 *nodes=((State_35F6E0 *)s)->nodes;
    f32 x,damage;
    if(D_001BBC40[obj[0xB0]+D_001D545C*16]&0x80) return;
    if(s[0xC9]!=31) {
        for(i=0;i<5;i++) {
            if(!((s[0xC9]>>i)&1) && func_L05_00360070(obj,i))
                s[0xC9]|=1<<i;
        }
    }
    func_L01_00456C98(obj,-1,0,0,0,0,1,0,0,0,100.0f,100.0f,1.0f);
    if(*(s32 *)(s+0xD0)==-1) {
        if(!(obj[0x34]&1)) *(s32 *)(s+0xD0)=func_L01_004AAC98(0,4,obj,0x1666);
    } else if(*(u16 *)(obj+0x34)&1) {
        func_003A4F28(*(s32 *)(s+0xD0));
        *(s32 *)(s+0xD0)=-1;
    }
    for(j=0;j<4;j++)
        if(func_00382380(D_001A4C60,nodes[j],0)) s[0xCB]|=1<<j;
    switch(obj[0x20]) {
    case 0:
        if(*(u16 *)(obj+0x34)&2) break;
        i=*(s32 *)(s+0x54);
        if(i!=-1 && *(s32 *)D_L05_0021ED80[i]>=2) {
            p=(u8 *)D_L05_0021ED80[i];
            x=func_0038CF00(p+0x10,p+0x20);
            *(f32 *)(s+0xA4)=0.0f;
            *(f32 *)(s+0xA8)=*(f32 *)(s+0xA0)*0.020000001f/x;
            func_L03_004657D0(*(s32 *)(s+0x54),0,obj+0x10,obj+0xF0,0,*(f32 *)(s+0xA4));
        } else *(f32 *)(s+0xA8)=*(f32 *)(s+0xA0)*1.2f/60.0f;
        func_L01_004450F0(obj,1,-1);
        *(f32 *)(s+0xB4)=-0.4f;
        *(f32 *)(s+0xB0)=1.0f;
        *(f32 *)(s+0xB8)=-1.0f;
        *(s16 *)(s+0xBC)=60;
        s[0xCB]=0;obj[0xBC]=0;s[0xC9]=0;
        *(f32 *)(obj+0x2C)=*(f32 *)(*(u8 **)(obj+0x24)+0x24)*0.5f;
        *(s16 *)(obj+0x32)=128;s[0xCD]=0;
        *(u16 *)(obj+0x34)&=0xBFFF;
        *(s32 *)(s+0xD0)=-1;
        *(s32 *)(obj+0x98)=0;
        *(u16 *)(obj+0x34)=(*(u16 *)(obj+0x34)|0x41)&0xEFFF;
        func_L01_004AA7E8(obj,1,-1);
        break;
    case 1:
        if(D_001A4F3C && *(s16 *)(D_001A4F3C+0xAA)==0x1626) break;
        if((s[0xC9]>>(s8)s[0xC8])&1) {
            s[0xC8]++;
            *(f32 *)(obj+0xF8)=func_0038D160(*(f32 *)(s+0x30)-*(f32 *)(obj+0x10),*(f32 *)(s+0x34)-*(f32 *)(obj+0x14));
            *(f32 *)(s+0xA4)=0;
            *(s16 *)(s+0xBE)=50;s[0xCE]=2;
            *(s32 *)(s+0xD0)=func_L01_004AAC98(0,4,obj,0x1666);
            func_L01_004450F0(obj,2,-1);
        }
        break;
    case 2:
        if(func_L01_004561B8(obj)) func_L01_004AAC98(2,0,obj,0x1666);
        if(func_0038CB00(s+0xBE)) func_L01_004450F0(obj,3,-1);
        else func_L01_00404A10(func_L05_00360448,obj);
        break;
    case 3:
        func_L05_003601F0(obj);
        if((s[0xC9]>>(s8)s[0xC8])&1) {
            s[0xC8]++;
            *(s16 *)(s+0xBE)=50;
            func_L01_004450F0(obj,4,-1);
        }
        break;
    case 4:
        func_L05_003601F0(obj);
        func_0038CB00(s+0xBE);
        if(*(s16 *)(s+0xBE)>=6) break;
        x=*(f32 *)(obj+0x2C)*0.0009765625f;
        bone=s[0xCD];
        func_003CA4A0(obj,1,&bone,mat);
        func_0038CE20(&a,&mat[3],x);
        *(vu0_q *)&b=*(vu0_q *)&a;
        x=((3-*(s16 *)(s+0xBE)/2)*0.8f+1.5f)*func_003824E0(0.9f,1.1f);
        func_003C4C18((f32 *)&b,0.3f);
        variant=func_00382468(2)?0xD0:0x30;
        p=func_L01_00470150(&b,obj,0x30204080,-1,0,10,0,-1,variant,0,x*210000.0f,0.0f,0.92f);
        if(p) p[2]=D_L05_002208AC[0];
        if(*(s16 *)(s+0xBE)!=0) break;
        func_0038D000(&a,&a,obj+0xC0);
        vec_add_ab(&a,&a,obj+0x10);
        vec_sub_ab(&c,obj+0x10,s+0x30);
        func_0038CE90(&c,&c,obj+0xE0);
        func_0038CF68(&c,&c,*(f32 *)(s+0xB0)*4.0f);
        vec_add_ba(&c,&c,s+0x30);
        func_003C4C18((f32 *)&c,0.5f);
        p=func_L05_003602D0(obj,&c);
        if(p) c.z=*(f32 *)(s+0xB8)=*(f32 *)(p+0x18)+0.2f;
        else if(*(f32 *)(s+0xB8)>0.0f) c.z=*(f32 *)(s+0xB8);
        damage=12.0f;
        if(func_L01_0041A4F0()) damage*=D_L05_002F4170[D_001D545C_sda];
        func_L05_00362148(obj,&a,&c,(s32)p,60,0,damage);
        func_L01_004AAC98(1,0,obj,0x1666);
        *(f32 *)(s+0xB0)+=*(f32 *)(s+0xB4);
        if(*(f32 *)(s+0xB0)>1.0f) {
            /* retail reuses the 1.0 it just compared against */
            *(f32 *)(s+0xB0)=1.0f;
            *(f32 *)(s+0xB4)=-*(f32 *)(s+0xB4);
        } else if(*(f32 *)(s+0xB0)<-1.0f) {
            *(f32 *)(s+0xB0)=-1.0f;
            *(f32 *)(s+0xB4)=-*(f32 *)(s+0xB4);
        }
        if((s[0xCB]>>((s8)s[0xC8]-2))&1) {
            if(nodes[(s8)s[0xC8]-1]>=0) func_L01_004450F0(obj,3,-1);
            else { *(s16 *)(s+0xBE)=50;s[0xCE]=1;func_L01_004450F0(obj,8,-1); }
        }
        s[0xCD]^=1;
        level=*(s32 *)(D_001C5290+D_001D545C*64);
        rate=100;
        if(level>=6) rate=75;
        else if(level>=11) rate=50;
        else if(level>=26) rate=25;
        else if(level>=2) rate=95-(level-2)*10;
        s[0xCC]=1;*(s16 *)(s+0xBE)=((6000/rate)*5+2)/6;
        break;
    case 5: case 6: case 7: break;
    case 8:
        if(func_L01_004561B8(obj)) func_L01_004AAC98(2,0,obj,0x1666);
        if(func_0038CB00(s+0xBE)) {
            if(*(s32 *)(s+0xD0)!=-1) func_003A4F28(*(s32 *)(s+0xD0));
            func_003C2880(obj);return;
        }
        func_L01_00404A10(func_L05_00360448,obj);
        break;
    }
    if(obj[0x20]>=3 && obj[0x20]<=6 && *(s32 *)(s+0x54)!=-1) {
        i=*(s32 *)(s+0x54);
        *(f32 *)(s+0xA4)+=*(f32 *)(s+0xA8);
        x=(f32)(D_L05_0021ED80[i][0]-1);
        if(*(f32 *)(s+0xA4)<x)
            func_L03_004657D0(i,0,obj+0x10,&a,0,*(f32 *)(s+0xA4));
        else {
            *(f32 *)(s+0xA4)=x;
            p=(u8 *)D_L05_0021ED80[i];
            *(vu0_q *)(obj+0x10)=*(vu0_q *)(p+*(s32 *)p*16);
        }
    }
    if(!(obj[0x34]&1)) func_L05_00360730(obj);
}
