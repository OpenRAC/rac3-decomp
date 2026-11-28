#include "common.h"
/* localdecomp:start func_L40_004338B0 */
typedef union { u8 b[8]; u16 h[4]; u32 w[2]; } B_00434418;
typedef struct { s32 a, valid; s16 item; u8 kind, pad; } E_00434418;
typedef struct {
    s32 pad0, stamp, last, player;
    u8 pad10[0x20]; s32 values[8]; u8 flags[8]; E_00434418 entries[8];
} P_00434418;
extern s32 D_001A5E50[];
extern s32 D_001A6C00[];
extern u8 D_L40_00240590, D_L40_00240598, D_L40_002405A0;
__asm__(".extern D_L40_00240590, 16");
__asm__(".extern D_L40_00240598, 16");
__asm__(".extern D_L40_002405A0, 16");
extern u8 D_L40_00241240, D_L40_00241241;
__asm__(".extern D_L40_00241240, 16");
__asm__(".extern D_L40_00241241, 16");
extern u8 D_L40_00241240;
extern u32 D_L40_00248048;
__asm__(".extern D_L40_00248048, 16");
extern u8 D_L40_00247CC8[];
extern void func_L39_00660240(void *, void *, s32);
extern s32 func_L40_00448C78(s32);
extern s32 func_L40_00449588(s32);
extern void *func_0011D534(void *, s32, s32);
extern void func_001962F8(void);
extern void func_L01_00433628(void *, s32, s32);

static __inline__ u32 get_00434418(u8 *q, B_00434418 *bp) {
    s32 n,k,m,i;
    u8 *d;
    u32 a,w0,w1;
    if (*q == 0) {
        return 0;
    }
    n=*q; k=((u32)q-n)&7; m=n+1; d=bp->b;
    for(i=0;i<40;i+=5) { s32 o=((k+i)&7)*4; *d++=(&D_L40_00241240)[m + o]; }
    w0=bp->w[0]; w1=bp->w[1];
    w0^=(u32)q;
    w1^=w0;
    bp->w[0]=w0;
    a=w1>>16;
    w1^=a;
    w1=~(a|w1);
    bp->w[1]=w1;
    return w1;
}

static __inline__ void hide_00434418(u8 *slot, B_00434418 *buf, u32 v, s32 size, s32 step) {
    u8 *q = slot;
    u32 z = v;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*slot == 0) {
        *slot = D_L40_00241240 = D_L40_00241240 + 1;
    } else {
        s32 t = *slot;
        *slot = D_L40_00241241;
        D_L40_00241241 = t;
    }
    key = ((u32 *)&D_L40_00241240)[((u32)slot * D_L40_00248048) % 8];
    k = ((u32)q - *q) & 7;
    if (size == 1) {
        buf->b[4] = z;
        v = buf->w[1];
    } else {
        v = ~v;
    }
    buf->w[0] = (u32)q ^ key;
    buf->w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    m = *q + 1;
    d = buf->b;
    for (i = 0; i < step * 8; i += step) {
        s32 o = ((k + i) & 7) * 4;

        (&D_L40_00241240)[m + o] = *d++;
    }
}

void func_L40_004338B0(u8 *m, s32 *msg) {
    u8 b[16];
    B_00434418 sb;
    s32 item, value;
    P_00434418 *p=*(P_00434418 **)(m+0x68);
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
        else {
            result=func_L40_00449588(item);
        }
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
        hide_00434418(&D_L40_00240590,&sb,get_00434418(&D_L40_00240590,&sb)+1,4,5);
        hide_00434418(&D_L40_00240598,&sb,get_00434418(&D_L40_00240598,&sb)+1,4,5);
        hide_00434418(&D_L40_002405A0,&sb,0,1,3);
        func_001962F8();
        if(D_001A6C00[2]) func_L01_00433628(D_L40_00247CC8,600,0);
        goto end;
end:;
}
/* localdecomp:end func_L40_004338B0 */
