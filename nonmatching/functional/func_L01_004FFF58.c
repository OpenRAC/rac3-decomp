/* functional: high. Same behaviour as retail; 2 words differ (swap of the sw zero and lwc1 constant load in the prologue, independent). */
#include "common.h"
/* localdecomp:start func_L01_004FFF58 */
typedef struct {
    u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[0x10]; u8 active;
    u8 pad32[2]; u16 flags; u8 pad36[0x32]; u8 *pvar;
    u8 pad6C[0x3E]; s16 class_id;
} M_004FFF58;
typedef struct {
    u8 pad0[0xAC0]; M_004FFF58 *target; s32 valid; f32 distance;
    u8 padACC[0x25C0-0xACC]; M_004FFF58 *object;
} H_004FFF58;
typedef union { s128 q; f32 v[4]; } Q_004FFF58;
extern Veldin1A4BE0 D_001A4BE0;
extern M_004FFF58 *D_L01_001F0468[];
extern f32 D_L01_001DC028[];
extern s32 D_001D545C;
extern Dir_004FE668 D_L01_001EAA00;
extern u8 D_L01_001E2A40[];
s32 func_L01_004FFF58(void) {
    extern u8 *func_00382348(void *);
    extern s32 func_0038DC20(void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern f32 func_0038CF00(void *, void *);
    M_004FFF58 *best;
    M_004FFF58 *m;
    s32 i;
    f32 dist;
    f32 radius;
    f32 d;
    u8 *info;
    Q_004FFF58 pos;
    ((H_004FFF58 *)&D_001A4BE0)->valid = 0;
    best=0;
    dist=D_L01_001DC028[0];
    for (i=0; i<32; i++) {
        s32 allow;
        m=D_L01_001F0468[i];
        if (m==0) break;
        if (m->flags & 1) continue;
        if (m->active==0) continue;
        if (m->state==2 || m->state==3) continue;
        pos.q=m->pos;
        pos.v[3]=0.5f;
        radius=32.0f;
        if (m->class_id==0xCB5 || m->class_id==0x952) {
            radius=*(f32 *)(m->pvar+0x78);
        } else {
            info=func_00382348(m);
            if (info) radius=info[0xA]*0.125f;
        }
        if (D_001D545C!=11 && func_0038DC20(&pos,radius)==-1) continue;
        allow=1;
        if (func_003D3CB0(D_L01_001E2A40,&m->pos,6,(s32)m,0)) {
            if (D_L01_001EAA00.object==0 || (s32)((H_004FFF58 *)&D_001A4BE0)->object!=D_L01_001EAA00.object)
                allow=0;
        }
        if (!allow) continue;
        d=func_0038CF00(&m->pos,(u8 *)((H_004FFF58 *)&D_001A4BE0)->object+0x10);
        if (d<dist) { best=m; dist=d; }
    }
    if (best) {
        ((H_004FFF58 *)&D_001A4BE0)->target=best;
        ((H_004FFF58 *)&D_001A4BE0)->distance=dist;
        ((H_004FFF58 *)&D_001A4BE0)->valid=1;
    } else {
        ((H_004FFF58 *)&D_001A4BE0)->target=0;
        ((H_004FFF58 *)&D_001A4BE0)->distance=D_L01_001DC028[0];
        ((H_004FFF58 *)&D_001A4BE0)->valid=0;
    }
    return ((H_004FFF58 *)&D_001A4BE0)->valid;
}
/* localdecomp:end func_L01_004FFF58 */
