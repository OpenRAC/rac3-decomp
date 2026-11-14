#include "common.h"

/* localdecomp:start func_L01_004C9F98 */
typedef struct {
    f32 *position;
    f32 *opacity;
    u8 pad08[0x80];
    u8 text[255];
    u8 terminator;
    u8 pad188[8];
    s32 lines;
    u8 pad194[4];
    s32 limit;
    u8 pad19C[8];
    s32 mode;
    u8 pad1A8[12];
    s32 width;
    u8 *line[30];
} Text_4C9F98;
extern void *func_0011A264(void *, s32, u32);
extern s32 func_L01_00410120(void *, s32);
extern s32 func_L01_004100D8_004C9F98(void *, s32);
void func_L01_004C9F98(Text_4C9F98 *obj, s32 mode, s32 limit, f32 x, f32 y) {
    u8 buffer[256];
    s32 width=1;
    s32 out=0;
    s32 single=1;
    s32 i=0;
    obj->position[0]=x;
    obj->position[1]=y;
    obj->limit=limit;
    obj->mode=mode;
    obj->terminator=0;
    obj->lines=1;
    obj->width=0;
    func_0011A264(buffer,0,256);
    func_0011A264(obj->line,0,120);
    obj->line[obj->lines-1]=obj->text;
    for(; i<255 && obj->text[i]; i++) {
        if(obj->text[i]==1) {
            single=0;
            buffer[out]=0;
            obj->text[i]=0;
            obj->line[obj->lines]=obj->text+i+1;
            obj->lines++;
            switch(obj->mode) {
            case 0: width=func_L01_00410120(buffer,-1);break;
            case 1: width=func_L01_004100D8_004C9F98(buffer,-1);break;
            case 2:break;
            }
            obj->width=(obj->width<width)?width:obj->width;
            out=0;
        } else {
            buffer[out]=obj->text[i];
            out++;
        }
    }
    if(single) {
        switch(obj->mode) {
        case 0:obj->width=func_L01_00410120(buffer,-1);break;
        case 1:obj->width=func_L01_004100D8_004C9F98(buffer,-1);break;
        case 2:break;
        }
    } else {
        switch(obj->mode) {
        case 0:width=func_L01_00410120(buffer,-1);break;
        case 1:width=func_L01_004100D8_004C9F98(buffer,-1);break;
        case 2:break;
        }
        obj->width=(obj->width<width)?width:obj->width;
    }
    *obj->opacity=1.0f;
}
/* localdecomp:end func_L01_004C9F98 */
