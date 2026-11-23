/* functional: high. Retail saves with sq and reads D_001DFC90 via lui/lw not gp; bytes only. Hand-checked vs the asm, not just alignment. */
#include "common.h"
/* localdecomp:start func_L01_004E8BC8 */
#include "vu0.h"
typedef struct { S_4E56A8vec center; u8 *path; s32 kind; u8 pad[8]; } Entry_004E8BC8;
extern Entry_004E8BC8 *D_L01_001DFC90;
extern s32 D_L01_001DFC94;
s32 func_L01_004E8BC8(s128 *input, s32 *out_path, s128 *out_pos, s32 *out_index, f32 *out_value, s32 *out_kind, s32 ignored, s32 required, s32 skip_probe) {
    extern s32 func_L01_00476B98(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern f32 func_0038CF00(S_4E56A8vec *, S_4E56A8vec *);
    extern f32 func_0038CF38(S_4E56A8vec *, S_4E56A8vec *);
    extern u8 D_001A4BE0[];
    S_4E56A8vec position, top, bottom;
    s32 index;
    f32 value;
    s32 i;
    *(s128 *)&position=*input;
    for(i=0;i<D_L01_001DFC94;i++) {
        f32 horizontal;
        f32 vertical;
        s32 visible;
        u8 *path;
        if (ignored && (s32)D_L01_001DFC90[i].path==ignored) continue;
        if (D_001A4BE0[0x25E4]==5) {
            path=D_L01_001DFC90[i].path;
            if(path && fabs_asm(*(f32 *)(path+0x10)-*(f32 *)(path+((*(s32 *)path-1)<<4)+0x10))<0.1f) continue;
        }
        if(required && (s32)D_L01_001DFC90[i].path!=required) continue;
        if(*(s32 *)D_L01_001DFC90[i].path==0) continue;
        if(func_0038CF00(&D_L01_001DFC90[i].center,(S_4E56A8vec *)&position)>D_L01_001DFC90[i].center.w) continue;
        if(!func_L01_00476B98(D_L01_001DFC90[i].path,&position,out_pos,&index,&value,D_L01_001DFC90[i].kind,12.0f,10.0f,0.0f)) continue;
        {
        u8 *hero=D_001A4BE0;
        horizontal=0.9f;
        vertical=1.5f;
        if((u32)*(s32 *)(hero+0x25CC)<2) horizontal=0.3f;
        if(*(s16 *)(hero+0x1F6)!=0) {
            horizontal+=0.5f;
            vertical=10.0f;
        }
        }
        visible=1;
        if(!skip_probe) {
            *(s128 *)&bottom=*out_pos;
            *(s128 *)&top=*out_pos;
            ((f32 *)&top)[2]+=0.25f;
            ((f32 *)&bottom)[2]-=1.0f;
            if(func_003D3CB0(&top,&bottom,2,0,0)==0) visible=0;
        }
        {
            f32 distance=func_0038CF38((S_4E56A8vec *)&position,(S_4E56A8vec *)out_pos);
            f32 dz=fabs_asm(((f32 *)&position)[2]-((f32 *)out_pos)[2]);
            if(distance<horizontal && dz<vertical && visible) {
                *out_path=(s32)D_L01_001DFC90[i].path;
                *out_index=index;
                *out_value=value;
                *out_kind=D_L01_001DFC90[i].kind;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004E8BC8 */
