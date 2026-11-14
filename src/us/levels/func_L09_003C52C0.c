#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L09_003C52C0 */
extern void func_L09_003C4F88(void *,void *);
extern void func_L01_004F12C0(void *,void *,int,int);
extern void func_L01_00441FB8(void *,int,int);
typedef struct {u8 a[0x19E0];int f19E0;short f19E4;u8 b[0x25C0-0x19E6];u8 *f25C0;int f25C4;u8 c[0x280C-0x25C8];int f280C;} Hero;
extern Hero D_001A4BE0[];
typedef struct {int a,b,c;} Other;
extern Other D_L09_002D1E70[];
void func_L09_003C52C0(u8 *m) {
    vu0_v4 a,b;
    u8 *p=*(u8 **)(m+0x68);
    u8 *v;
    u8 *v2;
    *(vu0_q *)&b=*(vu0_q *)(m+0xF0);
    b.x=0.0f;b.y=0.0f;
    func_L09_003C4F88(m,&a);
    if(D_001A4BE0[0].f25C4==49)func_L01_004F12C0(&a,&b,0,1);
    else func_L01_004F12C0(&a,&b,D_001A4BE0[0].f25C4,1);
    D_001A4BE0[0].f280C=0;
    D_001A4BE0[0].f19E0=0;
    D_001A4BE0[0].f19E4=-1;
    D_L09_002D1E70[0].a=5;
    D_L09_002D1E70[0].c=10;
    v=*(u8 **)(p+0x6D0);
    if(*(float *)(v+0x138)<=0.0666666701f && *(short *)(v+0x128)==0) {
        qzero(v+0xC0);*(int *)(*(u8 **)(p+0x6D0)+0x138)=0;
    }
    v2=D_001A4BE0[0].f25C0;
    *(int *)(v2+0x98)=*(int *)(*(u8 **)(v2+0x24)+0x10);
    func_L01_00441FB8(m,3,-1);
}
/* localdecomp:end func_L09_003C52C0 */
