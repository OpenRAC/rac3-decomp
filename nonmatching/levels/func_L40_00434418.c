/* NTSC-U draft (Codex wave 3): C of func_L40_004338B0, the NTSC-U twin of func_L40_00434418, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 100 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L40_004338B0", whose code is not the PAL one).
 * Worker's note: 100 diff; three formulations emitted identical checked output (baseline, scalar decode and sum order, shared aligned scratch); encrypted read/write pointer CSE, register allocation and load/store scheduling remain; best log func_L40_004338B0.check-01.log
 */
#include "common.h"

/* localdecomp:start func_L40_004338B0 */
typedef union { u8 b[8]; u16 h[4]; u32 w[2]; } B_338B0;
typedef struct { s32 a, valid; s16 item; u8 kind, pad; } E_338B0;
typedef struct {
    s32 pad0, stamp, last, player;
    u8 pad10[0x20]; s32 values[8]; u8 flags[8]; E_338B0 entries[8];
} P_338B0;
extern s32 D_001A5E50[];
extern s32 D_001A6C00[];
extern u8 D_L40_00240590, D_L40_00240598, D_L40_002405A0;
__asm__(".extern D_L40_00240590, 16");
__asm__(".extern D_L40_00240598, 16");
__asm__(".extern D_L40_002405A0, 16");
extern u8 D_L40_00241240, D_L40_00241241;
__asm__(".extern D_L40_00241240, 16");
__asm__(".extern D_L40_00241241, 16");
extern u8 D_001D59B0_sda;
extern u32 D_L40_00248048;
__asm__(".extern D_L40_00248048, 16");
extern u8 D_L40_00247CC8[];
extern void func_L39_00660240(void *, void *, s32);
extern s32 func_L40_00448C78(s32);
extern s32 func_L40_00449588(s32);
extern void *func_0011D534(void *, s32, s32);
extern void func_001962F8(void);
extern void func_L01_00433628(void *, s32, s32);

static __inline__ u32 get_338B0(u8 *q) {
    B_338B0 buf;
    s32 n,k,m,i;
    u8 *d;
    u32 a,b,c;
    if (*q == 0) return 0;
    n=*q; k=((u32)q-n)&7; m=n+1; d=buf.b;
    for(i=0;i<40;i+=5) *d++=(&D_L40_00241240)[((k+i)&7)*4+m];
    buf.w[0]^=(u32)q;
    buf.w[1]^=buf.w[0];
    a=buf.w[1]>>16;
    buf.w[1]^=a;
    buf.w[1]=~(buf.w[1]|a);
    return buf.w[1];
}

static __inline__ void set_338B0(u8 *q, u32 value) {
    B_338B0 buf;
    u32 hk=(u32)q;
    u32 key;
    s32 k,m,i,t;
    u8 *d;
    if (*q==0) {
        *q=D_001D59B0_sda=D_L40_00241240+1;
    } else {
        t=*q; *q=D_L40_00241241; D_L40_00241241=t;
    }
    key=((u32 *)&D_L40_00241240)[(hk*D_L40_00248048)&7];
    k=((u32)q-*q)&7;
    buf.w[0]=(u32)q^key;
    value=~value;
    buf.w[1]=((value&0xFFFF)|(value<<16))^key;
    m=*q+1;d=buf.b;
    for(i=0;i<40;i+=5) (&D_L40_00241240)[((k+i)&7)*4+m]=*d++;
}

static __inline__ void zero_338B0(u8 *q) {
    B_338B0 buf;
    u32 hk=(u32)q;
    u32 key;
    s32 k,m,i,t;
    u8 *d;
    if (*q==0) {
        *q=D_001D59B0_sda=D_L40_00241240+1;
    } else {
        t=*q; *q=D_L40_00241241; D_L40_00241241=t;
    }
    key=((u32 *)&D_L40_00241240)[(hk*D_L40_00248048)&7];
    k=((u32)q-*q)&7;
    buf.b[4]=0;
    buf.w[0]=(u32)q^key;
    buf.w[1]=((buf.w[1]&0xFFFF)|(buf.w[1]<<16))^key;
    m=*q+1;d=buf.b;
    for(i=0;i<24;i+=3) (&D_L40_00241240)[((k+i)&7)*4+m]=*d++;
}

void func_L40_004338B0(u8 *m, s32 *msg) {
    u8 b[16];
    s32 item, value;
    P_338B0 *p=*(P_338B0 **)(m+0x68);
    s32 state=msg[0]&15;
    s32 index, result;
    if(state==1) goto one;
    if(state==0) goto zero;
    if(state==2) goto two;
    return;
zero:
        index=(u32)msg[0]>>10;
        func_L39_00660240(msg,&item,4);
        index &= 7;
        func_L39_00660240(msg,b,1);
        p->stamp=msg[1]+((u32)msg[0]>>13);
        if(index==D_001A5E50[2]) goto end;
        if(!b[0]) result=func_L40_00448C78(item);
        else result=func_L40_00449588(item);
        if(result) {
            func_0011D534(&p->entries[index],0,12);
            p->entries[index].a=0;
            p->entries[index].valid=1;
            p->entries[index].item=result;
            p->entries[index].kind=b[0];
        }
        p->player=index;
        p->last=D_001A5E50[0x128/4];
        goto end;
    one:
        func_L39_00660240(msg,&value,4);
        p->values[((u32)msg[0]>>10)&7]=value;
        p->flags[((u32)msg[0]>>10)&7]=1;
        goto end;
    two:
        set_338B0(&D_L40_00240590,(get_338B0(&D_L40_00240590)+1));
        set_338B0(&D_L40_00240598,(get_338B0(&D_L40_00240598)+1));
        zero_338B0(&D_L40_002405A0);
        func_001962F8();
        if(D_001A6C00[2]) func_L01_00433628(D_L40_00247CC8,600,0);
        goto end;
end:;
}
/* localdecomp:end func_L40_004338B0 */
